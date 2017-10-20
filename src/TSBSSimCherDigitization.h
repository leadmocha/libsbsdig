
// Class handling digitization of GEMs

#ifndef __TSBSSimCherDigitization__
#define __TSBSSimCherDigitization__

#include "TRandom3.h"
#include "TVector3.h"
#include "TArrayI.h"

#include "THaAnalysisObject.h"

#include <vector>

class TFile;
class TTree;

class TSBSCherData;
//class TSolGEMVStrip;
class TSBSSpec;
class TSBSSimEvent;
class TSBSGeant4File;

// First an auxiliary class

// The whole strip plane; used to cumulate virtual strips charges
// and generate real strips
/*
class TSBSDigitizedPlane {
private:
  // ADC sampled value of strip array of each axis

  //TODO: make this a struct inside an STL vector or similar
  TArrayI fStripADC;  
  Short_t *fType;  // Type of track (primary, secondary) which left the hit for each strip
  Int_t   *fTotADC;  // number of ADC counts for each strip

  Float_t *fCharge;  // charge for each strip
  Float_t *fTime;   // time for each strip

  UShort_t fNSamples;   // number of ADC samples
  UShort_t fNStrips;   // number of strips in the plane
  Int_t    fThreshold;  // ADC threshold 

  UShort_t  fNOT;   // # strips over threshold
  Short_t*  fOverThr;  // # list of strips over threshold

  std::vector< std::vector<Short_t> > fStripClusters; // Clusters associated with each strip

  //used to simulate cross talk of APV25
  TRandom3 fRan;

public:
  // init and reset physics strips arrays
  TSBSDigitizedPlane (UShort_t nstrip,
		      UShort_t nsample = 10,
		      Int_t    threshold = 0 );
  ~TSBSDigitizedPlane();
  void Clear();

  // cumulate hits (strips signals)
  void Cumulate (const TSolGEMVStrip *vv, Short_t type, Short_t clusterID );
  
  //standard getters
  Short_t  GetType (Int_t n) const {return fType[n];}
  Int_t    GetTotADC (Int_t n) const {return fTotADC[n];}
  Float_t  GetTime (Int_t n) const {return fTime[n];}
  Float_t  GetCharge (Int_t n) const {return fCharge[n];}
  Int_t    GetADC (Int_t n, Int_t ks) const {return fStripADC[n*fNSamples+ks];}
  UShort_t GetNSamples() const {return fNSamples;}
  UShort_t GetNStrips() const {return fNStrips;}

  UShort_t Threshold (Int_t thr);

  UShort_t GetNOverThr() const {return fNOT;}
  Short_t  GetIdxOverThr (Int_t n) const {return fOverThr[n];}

  const std::vector<Short_t>& GetStripClusters(UInt_t n) const { return fStripClusters[n]; }
};
*/


class TSBSSimCherDigitization: public THaAnalysisObject
{
 public:
  //Constructor and destructor
  TSBSSimCherDigitization( const TSBSSpec& spect,
			  const char* name = "ratedig");
  virtual ~TSBSSimCherDigitization();
  
  //full initialization of all parameters with database
  void Initialize(const TSBSSpec& spect);
  Int_t ReadDatabase (const TDatime& date);
  
  //This is in those three functions that the job is done, more specifically in AddititveDigitize
  Int_t Digitize (const TSBSCherData& gdata, const TSBSSpec& spect); // digitize event
  Int_t AdditiveDigitize (const TSBSCherData& gdata, const TSBSSpec& spect); // add more digitized data, e.g. background
  void NoDigitize (const TSBSCherData& gdata, const TSBSSpec& spect); // do not digitize event, just fill tree
  //const TSBSDigitizedPlane& GetDigitizedPlane (UInt_t ich, UInt_t ip) const {return *(fDP[ich][ip]);}; 
  void Print() const;// print info
  /* void PrintCharges() const; */
  /* void PrintSamples() const; */
  
  Double_t GetGateWidth(){ return fGateWidth; }

  // Tree methods
  // To write a tree with digitization results:
  //   Call InitTree before main loop;
  //   Call SetTreeEvent in main loop (before or after Digitize)
  //   Call FillTree in main loop (after Digitize and SetTreeEvent)
  // Call WriteTree and CloseTree after main loop

  void InitTree (const TSBSSpec& spect, const TString& ofile);
  //dpulication of the SetTreeEvent routine with G4SBS file input instead of EVIO file
  void SetTreeEvent (const TSBSCherData& tsgd,
		     const TSBSGeant4File& f,
		     Int_t evnum = -1);
  Short_t SetTreeHit (const UInt_t ih,
		      const TSBSSpec& spect,
		      //TSolGEMVStrip* const *dh,
		      const TSBSCherData& tsgd,
		      Double_t t0 ); // called from Digitization
  void FillTree ();
  void WriteTree () const;
  void CloseTree () const;

  // Access to results
  /* Float_t GetTime (UInt_t ich, UInt_t ip, UInt_t n) const {return fDP[ich][ip]->GetTime (n);} */
  /* Int_t   GetADC (UInt_t ich, UInt_t ip, Int_t n, Int_t ks) const {return fDP[ich][ip]->GetADC (n, ks);} */
  /* Int_t   GetTDC (UInt_t ich, UInt_t ip, Int_t n, Int_t ks) const {return fDP[ich][ip]->GetADC (n, ks);} */
  /* UShort_t Threshold (UInt_t ich, UInt_t ip, Int_t thr) {return fDP[ich][ip]->Threshold (thr);} */
  /* UShort_t GetNPMTOverThr (UInt_t ich, UInt_t ip) const {return fDP[ich][ip]->GetNOverThr();} */
  
  TSBSSimEvent* GetEvent() const { return fEvent; }
  
  /*
  Short_t GetType (UInt_t ich, UInt_t ip, Int_t n) const {return fDP[ich][ip]->GetType (n);}
  Int_t   GetTotADC (UInt_t ich, UInt_t ip, Int_t n) const {return fDP[ich][ip]->GetTotADC (n);}
  Float_t GetCharge (UInt_t ich, UInt_t ip, UInt_t n) const {return fDP[ich][ip]->GetCharge (n);}
  UInt_t   GetNChambers() const {return fNChambers;};
  UInt_t   GetNPlanes (const UInt_t i) const {return fNPlanes[i];}
  UShort_t GetNSamples (UInt_t ich, UInt_t ip) const {return fDP[ich][ip]->GetNSamples();}
  UShort_t GetNStrips (UInt_t ich, UInt_t ip) const {return fDP[ich][ip]->GetNStrips();}
  Short_t  GetIdxOverThr (UInt_t ich, UInt_t ip, Int_t n) const
  { return fDP[ich][ip]->GetIdxOverThr(n); }

  const std::vector<Short_t>& GetStripClusters(UInt_t ich, UInt_t ip, UInt_t n) const
  { return fDP[ich][ip]->GetStripClusters(n); }

  Bool_t IsMapSector() const { return fDoMapSector; }
  void SetMapSector( Bool_t b = true ) { fDoMapSector = b; }

  // APV cross talk parameters
  static Int_t    fDoCrossTalk;  //whether we want to do cross talk simulation
  static Int_t    fNCStripApart; // # of strips the induced signal is away from the mean signal
  static Double_t fCrossFactor;  //reduction factor for the induced signal
  static Double_t fCrossSigma;   //uncertainty of the reduction factor

  //moved in "public" to allow it to compile with Root6/CentOS7
  struct IonPar_t {
    Double_t X;       // position of the point on the projection
    Double_t Y;
    Double_t Charge;  // Charge deposited by this ion
    Double_t SNorm;   // 3 x radius of ion diffusion area at readout
    Double_t R2;      // = SNorm^2 : radius of numerical integration area
    Double_t ggnorm;  // = Charge/R2/pi : charge per unit area
  };
  */
  
  private:

  // Database parameters:
  Double_t fADCgain;
  Double_t fADCoffset;
  Double_t fGateWidth;
  Short_t  fADCbits;
  Double_t fPMTGain;
  Double_t fPulseShapeTau;
  Double_t fTriggerOffset;
  Double_t fTriggerJitter;
  Double_t fPulseNoiseConst;
  Double_t fPulseNoiseSigma;
  Bool_t   fDoCrossTalk;
  Double_t fCrossTalkMean;
  Double_t fCrossTalkSigma;
  Double_t fCrossTalkChanApart;
  
  UInt_t fNDetectors;  // # N detectors
  std::vector<UInt_t> fNPMTs;  // # N PMTs for each detector
  TRandom3 fTrnd;     // time randomizer
  
  // Tree

  TFile* fOFile;          // Output ROOT file
  TTree* fOTree;          // Output tree
  TSBSSimEvent* fEvent;   // Output event structure, written to tree

  //Bool_t fFilledStrips;   // True if no data changed since last SetTreeStrips

  void MakePrefix() { THaAnalysisObject::MakePrefix(0); }
  void DeleteObjects();

  ClassDef (TSBSSimCherDigitization, 0)
};

#endif

