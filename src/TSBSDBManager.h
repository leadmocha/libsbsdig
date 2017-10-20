#ifndef __TSBSDBMANAGER_H
#define __TSBSDBMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include "Rtypes.h"
#include "VarDef.h"
#include "TMath.h"
#include "types.h"

using namespace std;

class TSBSDBManager {
public:
  ~TSBSDBManager();
  static TSBSDBManager* GetInstance() {
    if (fManager == NULL) fManager = new TSBSDBManager();
    return fManager;
  }
  
  void LoadGeneralInfo(const string& fileName);
  void LoadGeoInfo(const string& prefix);
  
  const int    &   GetNDetectors()        { return fNDetectors;        }
  const int    &   Getg4sbsDetectorType() { return fg4sbsDetectorType; }
  const int    &   GetChanPerSlot()       { return fChanPerSlot;       }
  
  const int    &   GetSigPID(unsigned int i);
  const int    &   GetSigTID(unsigned int i);
  
 protected:
  TSBSDBManager();
  int    LoadDB(ifstream& inp, DBRequest* request, const string& prefix);
  string FindKey( ifstream& inp, const string& key );
  bool   CheckIndex(int i, int j=0, int k=0);
  
  static TSBSDBManager* fManager;
  
  //variable for data base information
  int fNDetectors;  // number of Cherenkov detectors in arm (usually 1...)
  int fChanPerSlot;  // number of PMTs per slot
  
  // Parameters for TSBSGeant4File
  int fg4sbsDetectorType;// flag to determine which type of GEM should be read.
  //Choices are: 1 - GRINCH
  //Choices are: 2 - RICH
  
  // Parameters for signal particles
  int fNSigParticle; // number of signal particles
  vector<int>    fSigPID;
  vector<int>    fSigTID;
  
  map< int, vector<GeoInfo> > fGeoInfo;
  
  int    fErrID;
  double fErrVal;
};

#endif
