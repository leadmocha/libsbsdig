// manage the input data (output of the GEANT4 simulation)
// for the gem part

#ifndef __TSBSCherData__
#define __TSBSCherData__

#include <TRandom.h>
#include <TVector3.h>
#include <vector>

class TSBSCherData 
{
 public:

  TSBSCherData (UInt_t h = 0);
  virtual ~TSBSCherData();

  void ClearEvent();
  void InitEvent (UInt_t h);
  
  void SetNHit (UInt_t h)   { fHitData.resize(h); }
  void SetEvent (UInt_t id) { fEvtID = id; }
  void SetRun (UInt_t r)    { fRunID = r; }
  void SetSource (Int_t s)  { fSource = s; }

  // Positions are in mm
  // Time is in ns
  // Momenta are in MeV
  void SetHitPMTID (UInt_t k, UInt_t pmtid)             { fHitData[k].fPMTID  = pmtid; }
  void SetHitXPMT (UInt_t k, Double_t xpmt)             { fHitData[k].fXPMT  = xpmt; }
  void SetHitYPMT (UInt_t k, Double_t ypmt)             { fHitData[k].fYPMT  = ypmt; }
  void SetHitPEyield (UInt_t k, Double_t npe)           { fHitData[k].fNpe = npe; }
  void SetHitTime(UInt_t k, Double_t t)                 { fHitData[k].fTime = t; }
  void SetHitTimeRMS(UInt_t k, Double_t trms)           { fHitData[k].fTimeRMS = trms; }
  void SetParticleType (UInt_t k, UInt_t type)          { fHitData[k].fType = type; }
  void SetPositionDet (UInt_t k, const TVector3& X)     { fHitData[k].fPos_det = X; }
  void SetMCtrackPID (UInt_t k, Int_t pid)              { fHitData[k].fPID_MCtrack = pid; }
  void SetMCtrackMomentum (UInt_t k, const TVector3& p) { fHitData[k].fMom_MCtrack = p; }
  void SetMCtrackVertex (UInt_t k, const TVector3& X)   { fHitData[k].fVtx_MCtrack = X; }
  void SetOriginVolFlag (UInt_t k, UInt_t volflag)      { fHitData[k].fOriginVolFlag = volflag; }
  
  UInt_t GetNHit()   const { return fHitData.size(); }
  UInt_t GetEvent()  const { return fEvtID; }
  UInt_t GetRun()    const { return fRunID; }
  Int_t  GetSource() const { return fSource; }

  UInt_t          GetHitPMTID (UInt_t k)        const { return fHitData[k].fPMTID; }
  Double_t        GetHitXPMT (UInt_t k)         const { return fHitData[k].fXPMT; }
  Double_t        GetHitYPMT (UInt_t k)         const { return fHitData[k].fYPMT; }
  Double_t        GetHitPEyield (UInt_t k)      const { return fHitData[k].fNpe; }
  Double_t        GetHitTime (UInt_t k)         const { return fHitData[k].fTime; }
  Double_t        GetHitTimeRMS (UInt_t k)      const { return fHitData[k].fTimeRMS; }
  UInt_t          GetParticleType (UInt_t k)    const { return fHitData[k].fType; }
  const TVector3& GetPositionDet (UInt_t k)     const { return fHitData[k].fPos_det; }
  UInt_t          GetMCtrackPID (Int_t k)       const { return fHitData[k].fPID_MCtrack; }
  const TVector3& GetMCtrackMomentum (UInt_t k) const { return fHitData[k].fMom_MCtrack; }
  const TVector3& GetMCtrackVertex (UInt_t k)   const { return fHitData[k].fVtx_MCtrack; }
  UInt_t          GetOriginVolFlag (UInt_t k)   const { return fHitData[k].fOriginVolFlag; }

  
  void Print() const;
  void PrintHit (UInt_t k) const;

  // Hit data
  // moved in "public" to allow it to compile with Root6/CentOS7
  struct CherHitData_t {
    UInt_t    fPMTID;          // Hit PMT
    Double_t  fXPMT;           // X coordinate of the PMT in transport coordinates
    Double_t  fYPMT;           // Y coordinate of the PMT in transport coordinates
    Double_t  fNpe;            // Number of photoelectrons
    Double_t  fTime;           // hit time
    Double_t  fTimeRMS;        // hit time RMS: should be small (<0.1 ns)
    UInt_t    fType;           // particle type: 1 = primary, >1 secondaries
    TVector3  fPos_det;        // position of the optical photon at detection
    Int_t     fPID_MCtrack;    // Particle ID of the MC particle which produced the hit (*)
    TVector3  fMom_MCtrack;    // momentum of the MC particle which produced the hit (*)
    TVector3  fVtx_MCtrack;    // vertex of the MC particle which produced the hit (*)
    UInt_t    fOriginVolFlag;  // origin volume of the photon
  };//  (*) valid if identified
  
 private:

  UInt_t fRunID, fEvtID;
  Int_t  fSource; // MC source file ID (0 = signal, >0 background)
  std::vector<CherHitData_t> fHitData;

};
#endif
