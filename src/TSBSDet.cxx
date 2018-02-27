#include <iostream>

#include "TSBSDet.h"
#include "THaEvData.h"
#include "THaApparatus.h"
#include "TMath.h"
#include "ha_compiledata.h"

using namespace std;

//Recommanded constructor
TSBSDet::TSBSDet( const char *name, const char *desc )
  : THaDetector (name, desc)
    //: THaCherenkov (name, desc)
{
  fNChannels = 0;
  fZPos = 0;
  
  return;
}

TSBSDet::~TSBSDet()
{
}


const char* TSBSDet::GetDBFileName() const {
    THaApparatus *app = GetApparatus();
    if( app )
      return Form ("%s.", app->GetName());
    else
      return fPrefix;
}
  
Int_t
TSBSDet::ReadDatabase (const TDatime& date)
{
  //Read the geometry for the TSBSBox
  //Calls read geometry which, as it name indicates, actually reads the parameters
 
  FILE* file = OpenFile (date);
  if (!file) return kFileError;

  Int_t err = ReadGeometry (file, date, false);

  fclose(file);
  if (err)
    return err;

  return kOK;
}

/*
Int_t
TSBSDet::ReadGeometry (FILE* file, const TDatime& date,
			      Bool_t required)
{
  
  Int_t err = THaDetector::ReadGeometry (file, date, required);
  if (err)
    return err;
  
  const DBRequest request[] =
    {
      {"zckov_in",     &fZCkovIn,      kDouble, 0, 1},
      {"n_radiator",   &fNradiator,    kDouble, 0, 1},
      {"l_radiator",   &fLradiator,    kDouble, 0, 1},
      {"npmts",        &fNPMTs,        kInt,    0, 1},
      {"npmtrows",     &fNPMTrows,     kInt,    0, 1},
      {"npmtcolsmax",  &fNPMTcolsMax,  kInt,    0, 1},
      {"pmtdistx",     &fPMTdistX,     kDouble, 0, 1},
      {"pmtdisty",     &fPMTdistY,     kDouble, 0, 1},
      {"x_tcpmt",      &fX_TCPMT,      kDouble, 0, 1},
      {"y_tcpmt",      &fY_TCPMT,      kDouble, 0, 1},
      {0}
    };
  err = LoadDB (file, date, request, fPrefix);

  if (err)
    return err;
  
  fPMTmatrixHext = (fNPMTcolsMax-1)*fPMTdistY;
  fPMTmatrixVext = (fNPMTrows-1)*fPMTdistX;
  
  return kOK;
}


//
Int_t
TSBSDet::Decode (const THaEvData& ed )
{
  return 0;
}


void
TSBSDet::Print ()
{
  //Print TSBSDet info
  cout << "I'm a Generic Detector named " << GetName() << endl;
  cout << " Total number of channels = " << fNChannels << endl;
       << fNPMTcolsMax << " or " << fNPMTcolsMax-1 << " PMTs each." << endl;
  cout << " Distance between 2 PMTs rows : " << fPMTdistX << " m" << endl
       << " Distance between 2 PMTs columns : " << fPMTdistY << " m" << endl
       << " horizontal/vertical extension of PMT matrix (m) : " 
       << fPMTmatrixHext << "/" << fPMTmatrixVext << endl;
  cout << "Position of top close PMT in PMT matrix (in transport coord): " << endl
       << "X = " << fX_TCPMT << endl
       << "Y = " << fY_TCPMT << endl;
  
}
*/
