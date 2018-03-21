#include "g4sbs_data.h"
#include <TTree.h>
#include <iostream>


namespace TSBSGeant4 {
  bool CalData_t::SetupBranches(TTree *tree, const char* prefix)
  {
    if(!tree)
      return false;

    // Setup the branches now
    tree->SetBranchAddress(TString::Format("%s.nhits",prefix), &nhits);
    tree->SetBranchAddress(TString::Format("%s.row",prefix), &row);
    tree->SetBranchAddress(TString::Format("%s.col",prefix), &col);
    tree->SetBranchAddress(TString::Format("%s.cell",prefix), &cell);
    tree->SetBranchAddress(TString::Format("%s.plane",prefix), &plane);
    tree->SetBranchAddress(TString::Format("%s.xcell",prefix), &xcell);
    tree->SetBranchAddress(TString::Format("%s.ycell",prefix), &ycell);
    tree->SetBranchAddress(TString::Format("%s.zcell",prefix), &zcell);
    tree->SetBranchAddress(TString::Format("%s.xcellg",prefix), &xcellg);
    tree->SetBranchAddress(TString::Format("%s.ycellg",prefix), &ycellg);
    tree->SetBranchAddress(TString::Format("%s.zcellg",prefix), &zcellg);
    tree->SetBranchAddress(TString::Format("%s.xhit",prefix), &xhit);
    tree->SetBranchAddress(TString::Format("%s.yhit",prefix), &yhit);
    tree->SetBranchAddress(TString::Format("%s.zhit",prefix), &zhit);
    tree->SetBranchAddress(TString::Format("%s.sumedep",prefix), &sumedep);
    tree->SetBranchAddress(TString::Format("%s.tavg",prefix), &tavg);
    tree->SetBranchAddress(TString::Format("%s.trms",prefix), &trms);
    tree->SetBranchAddress(TString::Format("%s.tmin",prefix), &tmin);
    tree->SetBranchAddress(TString::Format("%s.tmax",prefix), &tmax);
    return true;
  }
  bool ECalData_t::SetupBranches(TTree *tree, const char* prefix)
  {
    if(!tree)
      return false;

    tree->SetBranchAddress(TString::Format("%s.nhits",prefix), &nhits);
    tree->SetBranchAddress(TString::Format("%s.PMT",prefix), &PMT);
    tree->SetBranchAddress(TString::Format("%s.row",prefix), &row);
    tree->SetBranchAddress(TString::Format("%s.col",prefix), &col);
    tree->SetBranchAddress(TString::Format("%s.plane",prefix), &plane);
    tree->SetBranchAddress(TString::Format("%s.xcell",prefix), &xcell);
    tree->SetBranchAddress(TString::Format("%s.ycell",prefix), &ycell);
    tree->SetBranchAddress(TString::Format("%s.zcell",prefix), &zcell);
    tree->SetBranchAddress(TString::Format("%s.xgcell",prefix), &xgcell);
    tree->SetBranchAddress(TString::Format("%s.ygcell",prefix), &ygcell);
    tree->SetBranchAddress(TString::Format("%s.zgcell",prefix), &zgcell);
    tree->SetBranchAddress(TString::Format("%s.NumPhotoelectrons",prefix),
        &NumPhotoelectrons);
    tree->SetBranchAddress(TString::Format("%s.Time_avg",prefix), &Time_avg);
    tree->SetBranchAddress(TString::Format("%s.Time_rms",prefix), &Time_rms);
    tree->SetBranchAddress(TString::Format("%s.Time_min",prefix), &Time_min);
    tree->SetBranchAddress(TString::Format("%s.Time_max",prefix), &Time_max);
    return true;
  }

  bool ECalPartData_t::SetupBranches(TTree* tree, const char* prefix)
  {
    if(!tree)
      return false;

    tree->SetBranchAddress(TString::Format("%s.E",prefix), &E);
    tree->SetBranchAddress(TString::Format("%s.t",prefix), &t);
    tree->SetBranchAddress(TString::Format("%s.part_PMT",prefix), &part_PMT);
    tree->SetBranchAddress(TString::Format("%s.detected",prefix), &detected);

    return true;
    //return ECalData_t::SetupBranches(tree,prefix);
  }
}

