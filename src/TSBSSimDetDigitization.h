
// Class handling digitization of GEMs

#ifndef __TSBSSimDetDigitization__
#define __TSBSSimDetDigitization__

#include "TRandom3.h"
#include "TVector3.h"
#include "TArrayI.h"
#include "TArrayD.h"

#include "THaAnalysisObject.h"

#include <vector>
#include <map>

class TFile;
class TTree;

class TSBSDetData;
class TSBSSpec;
class TSBSSimEvent;
class TSBSGeant4File;


class TSBSSimDetDigitization: public THaAnalysisObject
{
 public:
  //Constructor and destructor
  TSBSSimDetDigitization( const TSBSSpec& spect,
			  const char* name = "ratedig");
  virtual ~TSBSSimDetDigitization();
  
  //full initialization of all parameters with database
  void Initialize(const TSBSSpec& spect);
  //void ReadPMTtimesDataFiles();
  
  //const TSBSDigitizedPlane& GetDigitizedPlane (UInt_t ich, UInt_t ip) const {return *(fDP[ich][ip]);}; 
  // void PrintCharges() const;
  // void PrintSamples() const; 
  
  Double_t GetGateWidth(){ return fGateWidth; }
  Double_t GetTriggerOffset(){ return fTriggerOffset; }
  Double_t GetTriggerJitter(){ return fTriggerJitter; }
  Double_t GetPulseNoiseSigma(){ return fPulseNoiseSigma; }
  
  //bool GetTDCtimes(int detnum, double C, double t0, double& t1, double& t2);
  
  // Tree methods
  // To write a tree with digitization results:
  //   Call InitTree before main loop;
  //   Call SetTreeEvent in main loop (before or after Digitize)
  //   Call FillTree in main loop (after Digitize and SetTreeEvent)
  // Call WriteTree and CloseTree after main loop

  void InitTree (const TSBSSpec& spect, const TString& ofile);
  //dpulication of the SetTreeEvent routine with G4SBS file input instead of EVIO file
  //void CleanClusterList();//remove the "clusters" with 1 hit size...
  void FillTree ();
  void WriteTree () const;
  void CloseTree () const;

  TSBSSimEvent* GetEvent() const { return fEvent; }
  
  
 protected:
  //Everything which goes here MUST be overloaded
  void Print() const;// print info

  Int_t ReadDatabase (const TDatime& date);
  
  //This is in those three functions that the job is done, more specifically in AddititveDigitize
  Int_t Digitize (const TSBSDetData& gdata, const TSBSSpec& spect); // digitize event
  Int_t AdditiveDigitize (const TSBSDetData& gdata, const TSBSSpec& spect); // add more digitized data, e.g. background
  void NoDigitize (const TSBSDetData& gdata, const TSBSSpec& spect); // do not digitize event, just fill tree

  void SetTreeEvent (const TSBSDetData& tsgd,
		     const TSBSGeant4File& f,
		     Int_t evnum = -1);
  Short_t SetTreeHit (const UInt_t ih,
		      const TSBSSpec& spect,
		      //TSolGEMVStrip* const *dh,
		      const TSBSDetData& tsgd,
		      Double_t t0 ); // called from Digitization
  
  TFile* fOFile;          // Output ROOT file
  TTree* fOTree;          // Output tree
  TSBSSimEvent* fEvent;   // Output event structure, written to tree
  
 private:

  Double_t fGateWidth;
  Double_t fTriggerOffset;
  Double_t fTriggerJitter;
  Double_t fPulseNoiseSigma;
  
  /*
  // NINO cross talk parameters
  static Int_t    fDoCrossTalk;  //whether we want to do cross talk simulation
  static Int_t    fNCStripApart; // # of strips the induced signal is away from the mean signal
  static Double_t fCrossFactor;  //reduction factor for the induced signal
  static Double_t fCrossSigma;   //uncertainty of the reduction factor
  
  // Database parameters:
  Double_t fTDCthreshold;
  Double_t fTDCresolution;
  Double_t fPMTGain;
  // Double_t fPMTPulseShapeTau;
  Double_t fPMTTransitTime;
  // Double_t fPMTRiseTime;
  // Double_t fPMTJitter;
  // Double_t fPMTFWHM;
  Double_t fTDCTimeConversion;
  Short_t  fTDCbits;
  Double_t fPulseNoiseConst;
  Bool_t   fDoCrossTalk;
  Double_t fCrossTalkMean;
  Double_t fCrossTalkSigma;
  Double_t fCrossTalkChanApart;
  Double_t fReadOutImpedance;
  
  UInt_t fNDetectors;  // # N detectors
  std::vector<UInt_t> fNPMTs;  // # N PMTs for each detector
  std::vector< std::pair<TArrayI, TArrayI> > fTDCArrays;
  // TDC digital value output arrays (1st array: rise time, 2nd array: fall time)
  std::vector< std::pair<TArrayD, TArrayD> > fTDCtimeArrays;
  // TDC "input" time values (evaluated with the PMT pulse shape)
  TString fPMTtimesDataFileNames;
  
  std::vector<Double_t> fPulseHeight;
  std::vector< std::map< Double_t, std::pair<Double_t, Double_t> > > fPulseTimes;
  */
  
  TRandom3 fTrnd;     // time randomizer

  void MakePrefix() { THaAnalysisObject::MakePrefix(0); }
  void DeleteObjects();

  ClassDef (TSBSSimDetDigitization, 0)
};

#endif

