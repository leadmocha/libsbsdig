#include "g4sbs_data.h"
#include <TTree.h>
#include <iostream>


namespace TSBSGeant4 {
  template<typename T>
  int VDetData_t::SetupBranch(TTree *tree, const char* prefix,
      const char* varname, T &var)
  {
    TString branchname = TString::Format("%s.%s",prefix,varname);
    if(!tree)
      return 1;
    int ret = tree->SetBranchAddress(branchname.Data(),&var);
    if( ret != 0 ) {
      std::cerr << "Unable to set branch '" << branchname
        << "' failed with error code: " << ret << std::endl;
      return 1;
    }

    return 0;
  }

  bool CalData_t::SetupBranches(TTree *tree, const char* prefix)
  {
    int ret = 0;
    ret += SetupBranch(tree,prefix,"nhits", nhits);
    ret += SetupBranch(tree,prefix,"row", row);
    ret += SetupBranch(tree,prefix,"col", col);
    ret += SetupBranch(tree,prefix,"cell", cell);
    ret += SetupBranch(tree,prefix,"plane", plane);
    ret += SetupBranch(tree,prefix,"xcell", xcell);
    ret += SetupBranch(tree,prefix,"ycell", ycell);
    ret += SetupBranch(tree,prefix,"zcell", zcell);
    ret += SetupBranch(tree,prefix,"xcellg", xcellg);
    ret += SetupBranch(tree,prefix,"ycellg", ycellg);
    ret += SetupBranch(tree,prefix,"zcellg", zcellg);
    ret += SetupBranch(tree,prefix,"xhit", xhit);
    ret += SetupBranch(tree,prefix,"yhit", yhit);
    ret += SetupBranch(tree,prefix,"zhit", zhit);
    ret += SetupBranch(tree,prefix,"sumedep", sumedep);
    ret += SetupBranch(tree,prefix,"tavg", tavg);
    ret += SetupBranch(tree,prefix,"trms", trms);
    ret += SetupBranch(tree,prefix,"tmin", tmin);
    ret += SetupBranch(tree,prefix,"tmax", tmax);
    return (ret ==0);
  }
  bool ECalData_t::SetupBranches(TTree *tree, const char* prefix)
  {
    int ret = 0;
    ret += SetupBranch(tree,prefix,"nhits", nhits);
    ret += SetupBranch(tree,prefix,"PMT", PMT);
    ret += SetupBranch(tree,prefix,"row", row);
    ret += SetupBranch(tree,prefix,"col", col);
    ret += SetupBranch(tree,prefix,"plane", plane);
    ret += SetupBranch(tree,prefix,"xcell", xcell);
    ret += SetupBranch(tree,prefix,"ycell", ycell);
    ret += SetupBranch(tree,prefix,"zcell", zcell);
    ret += SetupBranch(tree,prefix,"xgcell", xgcell);
    ret += SetupBranch(tree,prefix,"ygcell", ygcell);
    ret += SetupBranch(tree,prefix,"zgcell", zgcell);
    ret += SetupBranch(tree,prefix,"NumPhotoelectrons", NumPhotoelectrons);
    ret += SetupBranch(tree,prefix,"Time_avg", Time_avg);
    ret += SetupBranch(tree,prefix,"Time_rms", Time_rms);
    ret += SetupBranch(tree,prefix,"Time_min", Time_min);
    ret += SetupBranch(tree,prefix,"Time_max", Time_max);
    return (ret==0);
  }

  bool ECalPartData_t::SetupBranches(TTree* tree, const char* prefix)
  {
    int ret = 0;
    ret += SetupBranch(tree,prefix,"npart_ECAL", npart_ECAL);
    ret += SetupBranch(tree,prefix,"E", E);
    ret += SetupBranch(tree,prefix,"t", t);
    ret += SetupBranch(tree,prefix,"part_PMT", part_PMT);
    ret += SetupBranch(tree,prefix,"detected", detected);
    return (ret==0);
    //return ECalData_t::SetupBranches(tree,prefix);
  }
}

