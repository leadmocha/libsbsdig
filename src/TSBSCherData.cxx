#include <iostream>

#include "TSBSCherData.h"

using namespace std;

TSBSCherData::TSBSCherData (UInt_t h)
{
  fHitData.reserve(h);
}

TSBSCherData::~TSBSCherData()
{
}

void
TSBSCherData::ClearEvent() 
{
  fHitData.clear();
};

void
TSBSCherData::InitEvent (UInt_t h)
{
  if (h <= 0)
    return;

  fHitData.resize(h);
}

void 
TSBSCherData::Print() const
{
  cout << "Run " << GetRun() << " Event " << GetEvent() << " " << GetNHit() << " hits" << endl;
}

void 
TSBSCherData::PrintHit (UInt_t k) const
{
  cout << "  Event " << GetEvent() << ":" << endl;
  cout << "    Hit time: " << GetHitTime(k) << " ns, RMS " 
       <<  GetHitTimeRMS(k) << " ns " << endl;
  cout << "    Hit PE yield: " << GetHitPEyield(k) << endl;
  cout << "    Hit PMT: " << GetHitPMTID(k) << endl;
  cout << "    PMT X_transport: " << GetHitXPMT(k) << endl;
  cout << "    PMT Y_transport: " << GetHitYPMT(k) << endl;
  cout << "    Particle type: " << GetParticleType(k) << endl;
  cout << "    Photon detection position: " << GetPositionDet(k).X()
       << " " << GetPositionDet(k).Y() 
       << " " << GetPositionDet(k).Z() 
       << " (mag. " << GetPositionDet(k).Mag() << ")"
       << " eV" << endl;
  if(GetOriginVolFlag(k)==2){
    cout << "    MCtrack PID: " << GetMCtrackPID(k) << endl;
    cout << "    MC track momentum: " << GetMCtrackMomentum(k).X()
	 << " " << GetMCtrackMomentum(k).Y() 
	 << " " << GetMCtrackMomentum(k).Z() 
	 << " (mag. " << GetMCtrackMomentum(k).Mag() << ")"
	 << " MeV" << endl;
    cout << "    MC track vertex: " << GetMCtrackVertex(k).X()
	 << " " << GetMCtrackVertex(k).Y() 
	 << " " << GetMCtrackVertex(k).Z() 
	 << " m" << endl;
  }
   cout << "    Photon volume origin flag (1: aerogel, 2: gas, 3: vessel, 4: PMT window):  " << GetOriginVolFlag(k) << endl;
}


/*
// Add to the current set of GEM data another GEM data set 
// Necessary ??? probably redundant with TSol(SBS)SimGEMDigitization::AdditiveDigitize()
void TSBSCherData::AddGEMData(TSBSCherData* gd)
{
  if( !gd ) return;
  
  unsigned int i, ngdata;
  ngdata = GetNHit();
  for(i=0; i<gd->GetNHit(); i++){
    SetMomentum(ngdata, gd->GetMomentum(i));
    SetVertex(ngdata, gd->GetVertex(i));
    
    SetHitEntrance(ngdata, gd->GetHitEntrance(i));
    SetHitExit(ngdata, gd->GetHitExit(i));
    SetHitReadout(ngdata, gd->GetHitReadout(i));

    SetHitTime(ngdata, gd->GetHitTime(i));
    SetHitEnergy(ngdata, gd->GetHitEnergy(i));
    
    SetTrackID(ngdata, gd->GetTrackID(i));
    SetParticleType(ngdata, gd->GetParticleType(i));
    
    SetHitChamber(ngdata, gd->GetHitChamber(i));
    
    ngdata++;
    
    SetNHit(ngdata);
  }
}
*/
