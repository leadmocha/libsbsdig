#ifndef _G4SBS_DATA_H
#define _G4SBS_DATA_H

#include <Rtypes.h>
class TTree;

namespace TSBSGeant4 {

  // Purely virtual data structure for detector data in a G4SBS ROOT tree.
  struct VDetData_t {
    VDetData_t() {};
    // All sub-classes *must* implement a concrete instance of this
    virtual bool SetupBranches(TTree *t, const char* prefix) = 0;
  };

  struct CalData_t : public VDetData_t {
    Int_t nhits;
    std::vector<Int_t>    *row;
    std::vector<Int_t>    *col;
    std::vector<Int_t>    *cell;
    std::vector<Int_t>    *plane;
    //std::vector<Int_t>    *wire;
    std::vector<Double_t> *xcell;
    std::vector<Double_t> *ycell;
    std::vector<Double_t> *zcell;
    std::vector<Double_t> *xcellg;
    std::vector<Double_t> *ycellg;
    std::vector<Double_t> *zcellg;
    std::vector<Double_t> *xhit;
    std::vector<Double_t> *yhit;
    std::vector<Double_t> *zhit;
    std::vector<Double_t> *sumedep;
    std::vector<Double_t> *tavg;
    std::vector<Double_t> *trms;
    std::vector<Double_t> *tmin;
    std::vector<Double_t> *tmax;
    CalData_t() :
      nhits(0), row(0), col(0), cell(0), plane(0), xcell(0), ycell(0), zcell(0),
      xcellg(0), ycellg(0), zcellg(0), xhit(0), yhit(0), zhit(0), sumedep(0),
      tavg(0), trms(0), tmin(0), tmax(0) {}
    virtual bool SetupBranches(TTree *t, const char* prefix);
  };

  // Standard ECal data (on PMT)
  struct ECalData_t : public VDetData_t {
    Int_t nhits;
    std::vector<Int_t>    *PMT;
    std::vector<Int_t>    *row;
    std::vector<Int_t>    *col;
    std::vector<Int_t>    *plane;
    std::vector<Double_t> *xcell;
    std::vector<Double_t> *ycell;
    std::vector<Double_t> *zcell;
    std::vector<Double_t> *xgcell;
    std::vector<Double_t> *ygcell;
    std::vector<Double_t> *zgcell;
    std::vector<Int_t>    *NumPhotoelectrons;
    std::vector<Double_t> *Time_avg;
    std::vector<Double_t> *Time_rms;
    std::vector<Double_t> *Time_min;
    std::vector<Double_t> *Time_max;
    ECalData_t() :
      nhits(0), PMT(0), row(0), col(0), plane(0), xcell(0),
      ycell(0), zcell(0), xgcell(0), ygcell(0), zgcell(0), NumPhotoelectrons(0),
      Time_avg(0), Time_rms(0), Time_min(0), Time_max(0) {}
    virtual bool SetupBranches(TTree *t, const char* prefix);
  };

  // If individual optical photons are included on the PMT
  //struct ECalPartData_t : public ECalData_t {
  struct ECalPartData_t : public VDetData_t {
    std::vector<Double_t> *E;
    std::vector<Double_t> *t;
    std::vector<Int_t> *part_PMT;
    std::vector<Bool_t> *detected;
    // Quick default constructor sets all pointers to zero for safety
    ECalPartData_t() : E(0), t(0), part_PMT(0), detected(0) {};
    virtual bool SetupBranches(TTree *t, const char *prefix);
  };
}

#endif // _G4SBS_DATA_H
