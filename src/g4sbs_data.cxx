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
    var = 0;
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


  bool RICHData_t::SetupBranches(TTree* tree, const char* prefix)
  {
    int ret = 0;
    ret += SetupBranch(tree,prefix,"nhits",nhits);
    ret += SetupBranch(tree,prefix,"PMT",PMT);
    ret += SetupBranch(tree,prefix,"row",row);
    ret += SetupBranch(tree,prefix,"col",col);
    ret += SetupBranch(tree,prefix,"xpmt",xpmt);
    ret += SetupBranch(tree,prefix,"ypmt",ypmt);
    ret += SetupBranch(tree,prefix,"zpmt",zpmt);
    ret += SetupBranch(tree,prefix,"xgpmt",xgpmt);
    ret += SetupBranch(tree,prefix,"ygpmt",ygpmt);
    ret += SetupBranch(tree,prefix,"zgpmt",zgpmt);
    ret += SetupBranch(tree,prefix,"NumPhotoelectrons",NumPhotoelectrons);
    ret += SetupBranch(tree,prefix,"Time_avg",Time_avg);
    ret += SetupBranch(tree,prefix,"Time_rms",Time_rms);
    ret += SetupBranch(tree,prefix,"Time_min",Time_min);
    ret += SetupBranch(tree,prefix,"Time_max",Time_max);
    ret += SetupBranch(tree,prefix,"mTrackNo",mTrackNo);
    ret += SetupBranch(tree,prefix,"xhit",xhit);
    ret += SetupBranch(tree,prefix,"yhit",yhit);
    ret += SetupBranch(tree,prefix,"zhit",zhit);
    ret += SetupBranch(tree,prefix,"pxhit",pxhit);
    ret += SetupBranch(tree,prefix,"pyhit",pyhit);
    ret += SetupBranch(tree,prefix,"pzhit",pzhit);
    ret += SetupBranch(tree,prefix,"pvx",pvx);
    ret += SetupBranch(tree,prefix,"pvy",pvy);
    ret += SetupBranch(tree,prefix,"pvz",pvz);
    ret += SetupBranch(tree,prefix,"ppx",ppx);
    ret += SetupBranch(tree,prefix,"ppy",ppy);
    ret += SetupBranch(tree,prefix,"ppz",ppz);
    ret += SetupBranch(tree,prefix,"volume_flag",volume_flag);
    return (ret==0);
  }

  bool GEMData_t::SetupBranches(TTree* tree, const char *prefix)
  {
    int ret = 0;
    ret += SetupBranch(tree,prefix,"nhits",nhits);
    ret += SetupBranch(tree,prefix,"plane",plane);
    ret += SetupBranch(tree,prefix,"strip",strip);
    ret += SetupBranch(tree,prefix,"x",x);
    ret += SetupBranch(tree,prefix,"y",y);
    ret += SetupBranch(tree,prefix,"z",z);
    ret += SetupBranch(tree,prefix,"polx",polx);
    ret += SetupBranch(tree,prefix,"poly",poly);
    ret += SetupBranch(tree,prefix,"polz",polz);
    ret += SetupBranch(tree,prefix,"t",t);
    ret += SetupBranch(tree,prefix,"trms",trms);
    ret += SetupBranch(tree,prefix,"tmin",tmin);
    ret += SetupBranch(tree,prefix,"tmax",tmax);
    ret += SetupBranch(tree,prefix,"tx",tx);
    ret += SetupBranch(tree,prefix,"ty",ty);
    ret += SetupBranch(tree,prefix,"txp",txp);
    ret += SetupBranch(tree,prefix,"typ",typ);
    ret += SetupBranch(tree,prefix,"xg",xg);
    ret += SetupBranch(tree,prefix,"yg",yg);
    ret += SetupBranch(tree,prefix,"zg",zg);
    ret += SetupBranch(tree,prefix,"trid",trid);
    ret += SetupBranch(tree,prefix,"mid",mid);
    ret += SetupBranch(tree,prefix,"pid",pid);
    ret += SetupBranch(tree,prefix,"vx",vx);
    ret += SetupBranch(tree,prefix,"vy",vy);
    ret += SetupBranch(tree,prefix,"vz",vz);
    ret += SetupBranch(tree,prefix,"p",p);
    ret += SetupBranch(tree,prefix,"edep",edep);
    ret += SetupBranch(tree,prefix,"beta",beta);
    return (ret==0);
  }

  bool TrackerData_t::SetupBranches(TTree* tree, const char *prefix)
  {
    int ret = 0;
    ret += SetupBranch(tree,prefix,"ntracks",ntracks);
    ret += SetupBranch(tree,prefix,"TID",TID);
    ret += SetupBranch(tree,prefix,"PID",PID);
    ret += SetupBranch(tree,prefix,"MID",MID);
    ret += SetupBranch(tree,prefix,"NumHits",NumHits);
    ret += SetupBranch(tree,prefix,"NumPlanes",NumPlanes);
    ret += SetupBranch(tree,prefix,"NDF",NDF);
    ret += SetupBranch(tree,prefix,"Chi2fit",Chi2fit);
    ret += SetupBranch(tree,prefix,"Chi2true",Chi2true);
    ret += SetupBranch(tree,prefix,"X",X);
    ret += SetupBranch(tree,prefix,"Y",Y);
    ret += SetupBranch(tree,prefix,"Xp",Xp);
    ret += SetupBranch(tree,prefix,"Yp",Yp);
    ret += SetupBranch(tree,prefix,"T",T);
    ret += SetupBranch(tree,prefix,"P",P);
    ret += SetupBranch(tree,prefix,"Sx",Sx);
    ret += SetupBranch(tree,prefix,"Sy",Sy);
    ret += SetupBranch(tree,prefix,"Sz",Sz);
    ret += SetupBranch(tree,prefix,"Xfit",Xfit);
    ret += SetupBranch(tree,prefix,"Yfit",Yfit);
    ret += SetupBranch(tree,prefix,"Xpfit",Xpfit);
    ret += SetupBranch(tree,prefix,"Ypfit",Ypfit);
    return (ret==0);
  }
}

