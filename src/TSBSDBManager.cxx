#include "TSBSDBManager.h"
#include "TSBSSimDecoder.h"
#include <cassert>
#include <cmath>
#include "TMath.h"
#include "TVector2.h"
#include "TRandom3.h"

TSBSDBManager * TSBSDBManager::fManager = NULL;

TSBSDBManager::TSBSDBManager() 
: fErrID(-999), fErrVal(-999.)
{
}
//______________________________________________________________
TSBSDBManager::~TSBSDBManager()
{
}
//______________________________________________________________
void TSBSDBManager::LoadGeneralInfo(const string& fileName)
{  
  ifstream input(fileName.c_str());
  if (!input.is_open()){
    cout<<"cannot find general information file "<<fileName
	<<". Exiting the program"<<endl;
        exit(0);
  }
  const string prefix = "generalinfo.";
  DBRequest request[] = {
    {"g4sbs_detectortype",  &fg4sbsDetectorType , kInt,    0, 1},
    {"ndetectors",          &fNDetectors        , kInt,    0, 1},
    {"chan_per_slot",       &fChanPerSlot       , kInt,    0, 1},
    {"nsignal",             &fNSigParticle      , kInt,    0, 1},
    { 0 }
  };
  int pid, tid;
  DBRequest signalRequest[] = {
    {"pid",                 &pid,                   kInt, 0, 1},
    {"tid",                 &tid,                   kInt, 0, 1},
    { 0 }
  };
  int err = LoadDB( input, request,  prefix);
  
  if( err ) exit(2); 
  
  for (int i=0; i<fNSigParticle; i++){
    ostringstream signal_prefix(prefix, ios_base::ate);
    signal_prefix<<"signal"<<i+1<<".";
    
    err = LoadDB(input, signalRequest, signal_prefix.str());
    
    fSigPID.push_back(pid);
    fSigTID.push_back(tid);
    
    if( err ) exit(2); 
  }
  
  for (int i=0; i<fNDetectors; i++){
    vector<GeoInfo> thisInfo;
    thisInfo.clear();
    fGeoInfo[i] = thisInfo;
  }
}


//______________________________________________________________
void TSBSDBManager::LoadGeoInfo(const string& prefix)
{
  const string& fileName = "db_"+prefix+".dat";
    
  ifstream input(fileName.c_str());
  if (!input.is_open()){
    cout<<"cannot find geometry file "<<fileName
	<<". Exiting the program"<<endl;
    exit(0);
  }
  
  GeoInfo thisGeo;
  
  DBRequest request[] = {
    {"npmts",        &thisGeo.fNPMTs,        kInt,    0, 1},
    {"npmtrows",     &thisGeo.fNPMTrows,     kInt,    0, 1},
    {"npmtcolsmax",  &thisGeo.fNPMTcolsMax,  kInt,    0, 1},
    {"interpmtdist", &thisGeo.fInterPMTDist, kDouble, 0, 1},
    {"x_tcpmt",      &thisGeo.fX_TCPMT,      kDouble, 0, 1},
    {"x_tcpmt",      &thisGeo.fY_TCPMT,      kDouble, 0, 1},
    { 0 }
  };
    
  thisGeo.fPMTmatrixHext = (thisGeo.fNPMTcolsMax-1)*thisGeo.fInterPMTDist;
  thisGeo.fPMTmatrixVext = (thisGeo.fNPMTrows-1)*thisGeo.fInterPMTDist;
  
  for (int i=0; i<fNDetectors; i++){
    map<int, vector<GeoInfo> >::iterator it = fGeoInfo.find(i);
    if (it == fGeoInfo.end()) { cout<<"unexpected detector id "<<i<<endl; }
    ostringstream detector_prefix(prefix, ios_base::ate);
    detector_prefix<<".cher"<<i<<".";
    
    int err = LoadDB(input, request,detector_prefix.str());
    if( err ) exit(2);
    
    fGeoInfo[i].push_back(thisGeo);
  }
  
  
}

//______________________________________________________________
string TSBSDBManager::FindKey( ifstream& inp, const string& key )
{
  static const string empty("");
  string line;
  string::size_type keylen = key.size();
  inp.seekg(0); // could probably be more efficient, but it's fast enough
  while( getline(inp,line) ) {
    if( line.size() <= keylen )
      continue;
    if( line.compare(0,keylen,key) == 0 ) {
      if( keylen < line.size() ) {
	string::size_type pos = line.find_first_not_of(" \t=", keylen);
	if( pos != string::npos )
	  return line.substr(pos);
      }
      break;
    }
  }
  return empty;
}
//_________________________________________________________________
int TSBSDBManager::LoadDB( ifstream& inp, DBRequest* request, const string& prefix )
{
  DBRequest* item = request;
  while( item->name ) {
    ostringstream sn(prefix, ios_base::ate);
    sn << item->name;
    const string& key = sn.str();
    string val = FindKey(inp,key);
    if( !val.empty() ) {
      istringstream sv(val);
      switch(item->type){
        case kDouble:
          sv >> *((double*)item->var);
          break;
        case kInt:
          sv >> *((Int_t*)item->var);
          break;
        default:
          return 1;
        break;
      }
      if( !sv ) {
	cerr << "Error converting key/value = " << key << "/" << val << endl;
	return 1;
      }
    } else {
      cerr << "key \"" << key << "\" not found" << endl;
      return 2;
    }
    ++item;
  }
  return 0;
}
//_____________________________________________________________________
const int & TSBSDBManager::GetSigPID(unsigned int i)
{
    if ( i >= fSigPID.size() ){ 
        cout<<"only "<<fSigPID.size()<<" signal particle registered"<<endl;
        return fErrID;
    }
    return fSigPID[i];
}
//______________________________________________________________________
const int & TSBSDBManager::GetSigTID(unsigned int i)
{
    if ( i >= fSigPID.size() ){ 
        cout<<"only "<<fSigPID.size()<<" signal particle registered"<<endl;
        return fErrID;
    }
    return fSigTID[i];
}

/*
//__________________________________________________________________________
int TSBSDBManager::GetSectorIDFromPos(int ichamber, double x, double y)
{
  if (!CheckIndex(ichamber)) return fErrVal;
  
  //int sector = -1;
  std::vector<int> sector;//yet something else...
  //printf("chamber %d, x = %1.6f\n", ichamber, x);
  for(int k = 0; k<fGeoInfo.size(); k++){
    //printf("%d: %1.2f, %1.2f \n", k, 
    //fGeoInfo[k].at(ichamber).xoffset-fGeoInfo[k].at(ichamber).dx/2.0,
    //fGeoInfo[k].at(ichamber).xoffset+fGeoInfo[k].at(ichamber).dx/2.0);
    if(fGeoInfo[k].at(ichamber).xoffset-fGeoInfo[k].at(ichamber).dx/2.0<=x && 
       x<=fGeoInfo[k].at(ichamber).xoffset+fGeoInfo[k].at(ichamber).dx/2.0){
      //if(abs(sector)==1)
      //sector = k;// EFuchey, 2017/05/16: if the sector value is -1 then it is not being over ridden
      // if the sector value is 1, then it is being over ridden, 
      // but it should happen only in the case of BB GEMs, plane 5.
      // I want that to happen because I divided plane 5 in 3 "sectors, each 1m long in x, 
      // and centered on -0.5, 0, 0.5, i.e. sector 1 overlaps completely with the 2 others.
      // I didn't figure any simpler way to integrate plane 5(UVA GEM) along with with the other 4 (INFN GEMs).
      sector.push_back(k);
    }
  }

  TRandom3 R(0);
  double P;
  //return sector;
  switch(sector.size()){
  case(0):
    return -1;
    break;
  case(1):
    return sector.at(0);
    break;
  case(2):// should actually happen **only** in the case of BB GEMs, plane 5.
    //return -1;cos(2*TMath::Pi()*x)/2+0.5
    P = R.Uniform(0, 1);
    if(P<= cos(2*TMath::Pi()*x)/2+0.5 ){
      return 1;
    }else{
      for(int i = 0; i<sector.size(); i++){
	if(sector.at(i)!=1)return sector.at(i);
      }
    }
    break;
  default:// >2 (should never happen)
    cout << "Sector size = " << sector.size() << "; something wrong, needs to be fixed !" << endl;
    return -1;
    break;
  }
  
  //if no conditions were ever satisfied, return error value
  return fErrVal;
}

//__________________________________________________________________________
double TSBSDBManager::GetPosFromSectorStrip(int iproj, int ichamber, int isector, int istrip)
{
  if (!CheckIndex(ichamber, isector, iproj)) return fErrVal;
  
  //cout << isector << " " << ichamber << " " << istrip;// << endl;
  // cout << fGeoInfo.size() << " " << fGeoInfo[isector].size() << endl;

  double pos = fErrVal;
  if(iproj==0){
    pos = fGeoInfo[isector].at(ichamber).pitch_u*istrip
      -fGeoInfo[isector].at(ichamber).dx/2.0
      -fGeoInfo[isector].at(ichamber).xoffset;
  }
  
  if(iproj==1){
    pos = fGeoInfo[isector].at(ichamber).pitch_v*istrip
      -fGeoInfo[isector].at(ichamber).dy/2.0;
  }
  
  //cout << " " << pos << endl;
  return( pos );
}
*/
