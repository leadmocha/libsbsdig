/////////////////////////////////////////////////////////////////////
//
//   TSBSSimEvent
//
//   Common class definitions (event, MC track, etc.) for SoLID
//   simulation decoder
//
//   Ole Hansen (ole@jlab.org)  December 2011
//
/////////////////////////////////////////////////////////////////////

#ifndef __TSBSSim_h
#define __TSBSSim_h

#include "SimDecoder.h"
#include "TVector3.h"
#include "TArrayS.h"
#include <vector>

//-----------------------------------------------------------------------------
// Kludgy hardcoded parameters necessary because I can't get ROOT to allocate
// arrays dynamically via TTree::GetEntry

#define treeName "digtree"
#define eventBranchName "event"

class TSBSSimEvent : public TObject {
public:
  TSBSSimEvent();                 // Default constructor, for ROOT I/O
  virtual ~TSBSSimEvent();
  TSBSSimEvent( UInt_t ntracks ); // Construct and initialize fMCTracks
  
  virtual void Clear( const Option_t* opt="" );
  virtual void Print( const Option_t* opt="" ) const;
  
  Int_t GetNPMTHits()  const { return fPMTHits.size(); }

  // Event identification
  Int_t     fRunID;               // Run number
  Int_t     fEvtID;               // Event number

  Double_t  fWeight;              // Event weight
  Int_t     fNSignal;             // Number of clusters from trigger track (signal)
  
  // MC tracks
  TClonesArray*   fMCTracks;      //-> Physics tracks
  
  struct PMTHit {
    // MC hit data
    Short_t   fID;        // Hit number
    Int_t     fSource;    // MC data set source (0 = signal, >0 background)
    Int_t     fType;      // GEANT particle type (1 = primary)
    Int_t     fMCtrackPID; // GEANT particle ID (if any)
    Short_t   fOrigVolFlag; // 
    Float_t   fNpe;       // Number of photoelectrons
    Float_t   fTime;      // Arrival time at electronics
    // Digitization results for this hit
    Short_t   fChannel;   // Channel number
    Short_t   fPMTrow;    // Row number: cross reference to Channel number
    Short_t   fPMTcol;    // Column number: cross reference to Channel number
    Int_t     fADC;       // ADC value
    Int_t     fTDC;       // TDC value
  };
  std::vector<PMTHit> fPMTHits;  // All MC-generated clusters in the GEMs

  ClassDef(TSBSSimEvent, 5) // Simulated data for one event
};

#endif
