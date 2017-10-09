#ifndef __TSBSSimDecoder_h
#define __TSBSSimDecoder_h

/////////////////////////////////////////////////////////////////////
//
//   TSBSSimDecoder
//
/////////////////////////////////////////////////////////////////////

#include "SimDecoder.h"
#include "TSBSSimEvent.h"
#include "ha_compiledata.h"
#include <cassert>
#include <map>
#include "TSBSDBManager.h"

class THaCrateMap;

//-----------------------------------------------------------------------------
// Helper classes for making decoded event data available via global variables

class TSBSSimPMTHit : public TObject {
public:
  TSBSSimPMTHit() {}
  TSBSSimPMTHit( const TSBSSimEvent::PMTHit& hit );

  virtual void Print( const Option_t* opt="" ) const;

  Short_t   fID;        // Hit number
  // MC hit data
  Int_t     fSource;    // MC data set source (0 = signal, >0 background)
  Int_t     fType;      // GEANT particle type (1 = primary)
  Short_t   fPMTrow;    // Sector number
  Short_t   fPMTcol;    // Plane number
  Float_t   fNpe;       // Number of photoelectrons
  Float_t   fTime;      // Arrival time at electronics
  // Digitization results for this hit
  Int_t     fChannel;   // Channel number
  Int_t     fADC;       // ADC value
  Int_t     fTDC;       // TDC value
  
  ClassDef(TSBSSimPMTHit,1) // A Monte Carlo hit at a GEM tracking chamber
};


//-----------------------------------------------------------------------------
// SoLID simulation decoder class
class TSBSSimDecoder : public Podd::SimDecoder {
 public:
  //constructor may be inputed a data file to input some of the paramaters used by SimDecoder
  //NB: if the second file path does not select a valid file, default parameters will be used.
  TSBSSimDecoder();
  virtual ~TSBSSimDecoder();
  
#if ANALYZER_VERSION_CODE >= 67072 // ANALYZER_VERSION(1,6,0)
  virtual Int_t LoadEvent( const UInt_t* evbuffer );
#else
  virtual Int_t LoadEvent( const Int_t* evbuffer );
#endif
  virtual void  Clear( Option_t* opt="" );
  virtual Int_t DefineVariables( THaAnalysisObject::EMode mode =
				 THaAnalysisObject::kDefine );
  virtual Podd::MCHitInfo GetMCHitInfo( Int_t crate, Int_t slot, Int_t chan ) const;

  TSBSSimPMTHit* GetPMTHit( Int_t i ) const {
    TObject* obj = fMCHits->UncheckedAt(i);
    assert( dynamic_cast<TSBSSimPMTHit*>(obj) );
    return static_cast<TSBSSimPMTHit*>(obj);
  }

  // Workaround for fubar THaEvData
#if ANALYZER_VERSION_CODE >= 67072  // ANALYZER_VERSION(1,6,0)
  static Int_t GetMAXSLOT() { return Decoder::MAXSLOT; }
#else
  static Int_t GetMAXSLOT() { return MAXSLOT; }
#endif

protected:
  typedef std::map<Int_t,Int_t> PMTMap_t;

  // Event-by-event data
  PMTMap_t      fPMTMap;   //! Map ROCKey -> index of corresponding strip

  // Event-by-event data
#if ANALYZER_VERSION_CODE >= 67072  // ANALYZER_VERSION(1,6,0)
  Int_t DoLoadEvent( const UInt_t* evbuffer );
#else
  Int_t DoLoadEvent( const Int_t* evbuffer );
#endif

  // void  PMTtoROC( Int_t s_plane, Int_t s_sector, Int_t s_proj, Int_t s_chan,
  //		    Int_t& crate, Int_t& slot, Int_t& chan ) const;
  Int_t PMTfromROC( Int_t crate, Int_t slot, Int_t chan ) const;
  // Int_t MakeROCKey( Int_t crate, Int_t slot, Int_t chan ) const;
  
  ClassDef(TSBSSimDecoder,0) // Decoder for simulated SoLID spectrometer data
};


#endif
