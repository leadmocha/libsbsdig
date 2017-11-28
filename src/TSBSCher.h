#ifndef __TSBSCHER_H
#define __TSBSCHER_H

//#include "THaDetector.h"
#include "THaCherenkov.h"

class THaEvData;

// TSBSCher also inherits form THaPidDetector, which grants it all the functions from its class
// (see http://hallaweb.jlab.org/podd/doc/html_v16/ClassIndex.html for more info).

//class TSBSCher : public THaDetector {
class TSBSCher : public THaCherenkov {
 public:
  //Constructors and destructor
  TSBSCher(const char *name, const char *desc);//It is recommended to use this constructor
  TSBSCher() : fNPMTs(0), fNPMTrows(0), fNPMTcolsMax(0) {} // for ROOT RTTI

  virtual ~TSBSCher();
  
  //Read the geometry for the TSBSBox in the data base
  Int_t ReadDatabase (const TDatime& date);
  Int_t ReadGeometry (FILE* file, const TDatime& date, Bool_t required);
  const char* GetDBFileName() const;

  Int_t Decode( const THaEvData & );
  
  // Access to the info of TSBSGEMPlane which is regarded as a subdetector of TSBSCher.
  // (see comments in the code of class TSBSGEMPlane)
  UInt_t GetNPMTs() const {return fNPMTs;};
  UInt_t GetNPMTrows() const {return fNPMTrows;};
  UInt_t GetNPMTcolsMax() const {return fNPMTcolsMax;};
  
  void Print ();
  
 private:
  int    fZCkovIn;       // Z of the entrance window in the spectrometer central ray;
  int    fNradiator;     // radiator index of refraction;
  int    fLradiator;     // radiator length on central ray;
  //int    fNquartz;       // quartz window index of refraction;
  int    fNPMTs;         // number of PMTs
  int    fNPMTrows;      // number of PMT rows
  int    fNPMTcolsMax;   // max number of PMT columns 
  double fPMTmatrixHext; // horizontal extension, in m, of the PMT matrix (from lower PMT center to higher PMT center)
  double fPMTmatrixVext; // vertical extension, in m, of the PMT matrix (from left PMT center to right PMT center)
  double fPMTdistX;      // projected X distance between the center of 2 PMT tubes in consecutive rows, in m
  double fPMTdistY;      // Y distance between the center of 2 PMT tubes in consecutive columns, in m
  double fX_TCPMT;       // X position of the top close PMT center in the PMT matrix (transport coord)
  double fY_TCPMT;       // Y position of the top close PMT center in the PMT matrix (transport coord)

  ClassDef(TSBSCher,0)

};

#endif//__TSBSCHER_H
