//*-- Author :    Ole Hansen (ole@jlab.org)    9-Dec-2011

/////////////////////////////////////////////////////////////////////
//
//   TSBSSimEvent
//
//   Common class definitions for SoLID simulation decoder
//
/////////////////////////////////////////////////////////////////////

#include "TSBSSimEvent.h"
#include "TClonesArray.h"
#include "TString.h"
#include "TMath.h"

#include <iostream>

using namespace std;

//-----------------------------------------------------------------------------
TSBSSimEvent::TSBSSimEvent()
  : fRunID(0), fEvtID(0), fNSignal(0)
{
}

//-----------------------------------------------------------------------------
TSBSSimEvent::TSBSSimEvent( UInt_t ntracks )
  : fRunID(0), fEvtID(0), fNSignal(0)
{
  if( ntracks == 0 ) ntracks = 1;
  fMCTracks = new TClonesArray( "TSBSSimTrack", ntracks );
}

//-----------------------------------------------------------------------------
TSBSSimEvent::~TSBSSimEvent()
{
  delete fMCTracks;
}

//-----------------------------------------------------------------------------
void TSBSSimEvent::Clear( const Option_t* opt )
{
  // Clear the event in preparation for reading next tree entry

  TString sopt(opt);

  fNSignal = 0;
  fPMTHits.clear();
}

//-----------------------------------------------------------------------------
void TSBSSimEvent::Print( const Option_t* opt ) const
{
  // Print current event info

  cout << ">>>>> =====================================" << endl;
  cout << "Run number:               " << fRunID << endl;
  cout << "Event number:               " << fEvtID << endl;
  cout << "Event weight:               " << fWeight << endl;
  cout << "Number of hits:             " << fPMTHits.size()   << endl;
  
  TString sopt(opt);
  bool do_all    = sopt.Contains("all",   TString::kIgnoreCase);
  bool do_hit    = sopt.Contains("hit",   TString::kIgnoreCase) || do_all;
  
  if( do_hit ) {
    for( vector<PMTHit>::const_iterator ih = fPMTHits.begin();
	 ih != fPMTHits.end(); ++ih ) {
      const PMTHit& h = *ih;
      cout << "hit = " << h.fID
	   << ", type = "    << h.fType
	   << ", src = "    << h.fSource
	   << endl;
      cout << "PMT row = "   << h.fPMTrow
	   << ", PMT col = "   << h.fPMTcol 
	   << ", number of photoelectrons = " << h.fNpe
	   << ", time = " << h.fTime << " ns " 
	   << endl;
      cout << " Channel = " << h.fChannel
	   << ", ADC value  " << h.fADC 
	   << ", TDC value  " << h.fTDC 
	   << endl;
    }
  }
}

//-----------------------------------------------------------------------------
ClassImp(TSBSSimEvent)
