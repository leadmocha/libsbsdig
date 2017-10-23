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
    fGeoInfo = thisInfo;
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
  
  for (int i=0; i<fNDetectors; i++){
    //map<int, vector<GeoInfo> >::iterator it = fGeoInfo.find(i);
    //if (it == fGeoInfo.end()) { cout<<"unexpected detector id "<<i<<endl; }
    ostringstream detector_prefix(prefix, ios_base::ate);
    detector_prefix<<".cher"<<i<<".";
    
    int err = LoadDB(input, request,detector_prefix.str());
    if( err ) exit(2);
    
    thisGeo.fPMTmatrixHext = (thisGeo.fNPMTcolsMax-1)*thisGeo.fInterPMTDist;
    thisGeo.fPMTmatrixVext = (thisGeo.fNPMTrows-1)*thisGeo.fInterPMTDist;
    
    fGeoInfo.push_back(thisGeo);
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

//_________________________________________________________________________
bool TSBSDBManager::CheckIndex(int i)
{
    if (i >= fNDetectors || i < 0){
        cout<<"invalid Detector ID requested: "<<i<<endl;
        return false;
    }

    return true;
}

//_________________________________________________________________________
const int & TSBSDBManager::GetNPMTs(int i)
{
  if (!CheckIndex(i)) return fErrID;
  return fGeoInfo.at(i).fNPMTs;
}

//_________________________________________________________________________
const int & TSBSDBManager::GetNPMTrows(int i)
{
  if (!CheckIndex(i)) return fErrID;
  return fGeoInfo.at(i).fNPMTrows;
}

//_________________________________________________________________________
const int & TSBSDBManager::GetNPMTcolsMax(int i)
{
  if (!CheckIndex(i)) return fErrID;
  return fGeoInfo.at(i).fNPMTcolsMax;
}

//_________________________________________________________________________
const double & TSBSDBManager::GetPMTmatrixHext(int i)
{
  if (!CheckIndex(i)) return fErrVal;
  return fGeoInfo.at(i).fPMTmatrixHext;
}

//_________________________________________________________________________
const double & TSBSDBManager::GetPMTmatrixVext(int i)
{
  if (!CheckIndex(i)) return fErrVal;
  return fGeoInfo.at(i).fPMTmatrixVext;
}

//_________________________________________________________________________
const double & TSBSDBManager::GetInterPMTDist(int i)
{
  if (!CheckIndex(i)) return fErrVal;
  return fGeoInfo.at(i).fInterPMTDist;
}

//_________________________________________________________________________
const double & TSBSDBManager::GetX_TCPMTs(int i)
{
  if (!CheckIndex(i)) return fErrVal;
  return fGeoInfo.at(i).fX_TCPMT;
}

//_________________________________________________________________________
const double & TSBSDBManager::GetY_TCPMTs(int i)
{
  if (!CheckIndex(i)) return fErrVal;
  return fGeoInfo.at(i).fY_TCPMT;
}
