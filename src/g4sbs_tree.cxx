//#define g4sbs_tree_cxx
#include "g4sbs_tree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

// g4sbs_tree constructor: the tree will be the 
// the boolean is a flag to consider(true) or ignore(false) the ECal_box and HCal_box data
g4sbs_tree::g4sbs_tree(TTree *tree, int det_opt, bool pythia, bool ecalbox, bool have_hcalbox) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("gep_spin_transport_Sx.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("gep_spin_transport_Sx.root");
      }
      f->GetObject("T",tree);
   }
   fExpOption = det_opt;
   fPythia = pythia;
   fEcalBox = ecalbox;
   fHcalBox = have_hcalbox;
   Init(tree);
}

//default destructor
g4sbs_tree::~g4sbs_tree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

//overload of the TTree::GetEntries() function
Int_t g4sbs_tree::GetEntries()
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntries();
}
//overload of the TTree::GetEntry(Long64_t) function
Int_t g4sbs_tree::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}
Long64_t g4sbs_tree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void g4sbs_tree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   
   // Set object pointer
   Earm_BBGEM_hit_plane = 0;
   Earm_BBGEM_hit_strip = 0;
   Earm_BBGEM_hit_x = 0;
   Earm_BBGEM_hit_y = 0;
   Earm_BBGEM_hit_z = 0;
   Earm_BBGEM_hit_polx = 0;
   Earm_BBGEM_hit_poly = 0;
   Earm_BBGEM_hit_polz = 0;
   Earm_BBGEM_hit_trms = 0;
   Earm_BBGEM_hit_tmin = 0;
   Earm_BBGEM_hit_tmax = 0;
   Earm_BBGEM_hit_tx = 0;
   Earm_BBGEM_hit_ty = 0;
   Earm_BBGEM_hit_txp = 0;
   Earm_BBGEM_hit_typ = 0;
   Earm_BBGEM_hit_xg = 0;
   Earm_BBGEM_hit_yg = 0;
   Earm_BBGEM_hit_zg = 0;
   Earm_BBGEM_hit_trid = 0;
   Earm_BBGEM_hit_mid = 0;
   Earm_BBGEM_hit_pid = 0;
   Earm_BBGEM_hit_vx = 0;
   Earm_BBGEM_hit_vy = 0;
   Earm_BBGEM_hit_vz = 0;
   Earm_BBGEM_hit_p = 0;
   Earm_BBGEM_hit_edep = 0;
   Earm_BBGEM_hit_beta = 0;
   
   Earm_BBGEM_Track_TID = 0;
   Earm_BBGEM_Track_PID = 0;
   Earm_BBGEM_Track_MID = 0;
   Earm_BBGEM_Track_NumHits = 0;
   Earm_BBGEM_Track_NumPlanes = 0;
   Earm_BBGEM_Track_NDF = 0;
   Earm_BBGEM_Track_Chi2fit = 0;
   Earm_BBGEM_Track_Chi2true = 0;
   Earm_BBGEM_Track_X = 0;
   Earm_BBGEM_Track_Y = 0;
   Earm_BBGEM_Track_Xp = 0;
   Earm_BBGEM_Track_Yp = 0;
   Earm_BBGEM_Track_Sx = 0;
   Earm_BBGEM_Track_Sy = 0;
   Earm_BBGEM_Track_Sz = 0;
   Earm_BBGEM_Track_Xfit = 0;
   Earm_BBGEM_Track_Yfit = 0;
   Earm_BBGEM_Track_Xpfit = 0;
   Earm_BBGEM_Track_Ypfit = 0;
 
   Earm_BBHodoScint_hit_row = 0;
   Earm_BBHodoScint_hit_col = 0;
   Earm_BBHodoScint_hit_cell = 0;
   Earm_BBHodoScint_hit_plane = 0;
   Earm_BBHodoScint_hit_xcell = 0;
   Earm_BBHodoScint_hit_ycell = 0;
   Earm_BBHodoScint_hit_zcell = 0;
   Earm_BBHodoScint_hit_xcellg = 0;
   Earm_BBHodoScint_hit_ycellg = 0;
   Earm_BBHodoScint_hit_zcellg = 0;
   Earm_BBHodoScint_hit_xhit = 0;
   Earm_BBHodoScint_hit_yhit = 0;
   Earm_BBHodoScint_hit_zhit = 0;
   Earm_BBHodoScint_hit_sumedep = 0;
   Earm_BBHodoScint_hit_tavg = 0;
   Earm_BBHodoScint_hit_trms = 0;
   Earm_BBHodoScint_hit_tmin = 0;
   Earm_BBHodoScint_hit_tmax = 0;
   
   Earm_GRINCH_hit_PMT = 0;
   Earm_GRINCH_hit_row = 0;
   Earm_GRINCH_hit_col = 0;
   Earm_GRINCH_hit_xpmt = 0;
   Earm_GRINCH_hit_ypmt = 0;
   Earm_GRINCH_hit_zpmt = 0;
   Earm_GRINCH_hit_xgpmt = 0;
   Earm_GRINCH_hit_ygpmt = 0;
   Earm_GRINCH_hit_zgpmt = 0;
   Earm_GRINCH_hit_NumPhotoelectrons = 0;
   Earm_GRINCH_hit_Time_avg = 0;
   Earm_GRINCH_hit_Time_rms = 0;
   Earm_GRINCH_hit_Time_min = 0;
   Earm_GRINCH_hit_Time_max = 0;
   Earm_GRINCH_hit_mTrackNo = 0;
   Earm_GRINCH_hit_xhit = 0;
   Earm_GRINCH_hit_yhit = 0;
   Earm_GRINCH_hit_zhit = 0;
   Earm_GRINCH_hit_pxhit = 0;
   Earm_GRINCH_hit_pyhit = 0;
   Earm_GRINCH_hit_pzhit = 0;
   Earm_GRINCH_hit_pvx = 0;
   Earm_GRINCH_hit_pvy = 0;
   Earm_GRINCH_hit_pvz = 0;
   Earm_GRINCH_hit_ppx = 0;
   Earm_GRINCH_hit_ppy = 0;
   Earm_GRINCH_hit_ppz = 0;
   Earm_GRINCH_hit_volume_flag = 0;
   
   Earm_BBPS_hit_PMT = 0;
   Earm_BBPS_hit_row = 0;
   Earm_BBPS_hit_col = 0;
   Earm_BBPS_hit_plane = 0;
   Earm_BBPS_hit_xcell = 0;
   Earm_BBPS_hit_ycell = 0;
   Earm_BBPS_hit_zcell = 0;
   Earm_BBPS_hit_xgcell = 0;
   Earm_BBPS_hit_ygcell = 0;
   Earm_BBPS_hit_zgcell = 0;
   Earm_BBPS_hit_NumPhotoelectrons = 0;
   Earm_BBPS_hit_Time_avg = 0;
   Earm_BBPS_hit_Time_rms = 0;
   Earm_BBPS_hit_Time_min = 0;
   Earm_BBPS_hit_Time_max = 0;
   
   Earm_BBPSTF1_hit_row = 0;
   Earm_BBPSTF1_hit_col = 0;
   Earm_BBPSTF1_hit_cell = 0;
   Earm_BBPSTF1_hit_plane = 0;
   Earm_BBPSTF1_hit_xcell = 0;
   Earm_BBPSTF1_hit_ycell = 0;
   Earm_BBPSTF1_hit_zcell = 0;
   Earm_BBPSTF1_hit_xcellg = 0;
   Earm_BBPSTF1_hit_ycellg = 0;
   Earm_BBPSTF1_hit_zcellg = 0;
   Earm_BBPSTF1_hit_xhit = 0;
   Earm_BBPSTF1_hit_yhit = 0;
   Earm_BBPSTF1_hit_zhit = 0;
   Earm_BBPSTF1_hit_sumedep = 0;
   Earm_BBPSTF1_hit_tavg = 0;
   Earm_BBPSTF1_hit_trms = 0;
   Earm_BBPSTF1_hit_tmin = 0;
   Earm_BBPSTF1_hit_tmax = 0;
   
   Earm_BBSH_hit_PMT = 0;
   Earm_BBSH_hit_row = 0;
   Earm_BBSH_hit_col = 0;
   Earm_BBSH_hit_plane = 0;
   Earm_BBSH_hit_xcell = 0;
   Earm_BBSH_hit_ycell = 0;
   Earm_BBSH_hit_zcell = 0;
   Earm_BBSH_hit_xgcell = 0;
   Earm_BBSH_hit_ygcell = 0;
   Earm_BBSH_hit_zgcell = 0;
   Earm_BBSH_hit_NumPhotoelectrons = 0;
   Earm_BBSH_hit_Time_avg = 0;
   Earm_BBSH_hit_Time_rms = 0;
   Earm_BBSH_hit_Time_min = 0;
   Earm_BBSH_hit_Time_max = 0;
   
   Earm_BBSHTF1_hit_row = 0;
   Earm_BBSHTF1_hit_col = 0;
   Earm_BBSHTF1_hit_cell = 0;
   Earm_BBSHTF1_hit_plane = 0;
   Earm_BBSHTF1_hit_xcell = 0;
   Earm_BBSHTF1_hit_ycell = 0;
   Earm_BBSHTF1_hit_zcell = 0;
   Earm_BBSHTF1_hit_xcellg = 0;
   Earm_BBSHTF1_hit_ycellg = 0;
   Earm_BBSHTF1_hit_zcellg = 0;
   Earm_BBSHTF1_hit_xhit = 0;
   Earm_BBSHTF1_hit_yhit = 0;
   Earm_BBSHTF1_hit_zhit = 0;
   Earm_BBSHTF1_hit_sumedep = 0;
   Earm_BBSHTF1_hit_tavg = 0;
   Earm_BBSHTF1_hit_trms = 0;
   Earm_BBSHTF1_hit_tmin = 0;
   Earm_BBSHTF1_hit_tmax = 0;

   Earm_CDET_hit_PMT = 0;
   Earm_CDET_hit_row = 0;
   Earm_CDET_hit_col = 0;
   Earm_CDET_hit_plane = 0;
   Earm_CDET_hit_xcell = 0;
   Earm_CDET_hit_ycell = 0;
   Earm_CDET_hit_zcell = 0;
   Earm_CDET_hit_xgcell = 0;
   Earm_CDET_hit_ygcell = 0;
   Earm_CDET_hit_zgcell = 0;
   Earm_CDET_hit_NumPhotoelectrons = 0;
   Earm_CDET_hit_Time_avg = 0;
   Earm_CDET_hit_Time_rms = 0;
   Earm_CDET_hit_Time_min = 0;
   Earm_CDET_hit_Time_max = 0;
   
   Earm_CDET_Scint_hit_row = 0;
   Earm_CDET_Scint_hit_col = 0;
   Earm_CDET_Scint_hit_cell = 0;
   Earm_CDET_Scint_hit_plane = 0;
   Earm_CDET_Scint_hit_xcell = 0;
   Earm_CDET_Scint_hit_ycell = 0;
   Earm_CDET_Scint_hit_zcell = 0;
   Earm_CDET_Scint_hit_xcellg = 0;
   Earm_CDET_Scint_hit_ycellg = 0;
   Earm_CDET_Scint_hit_zcellg = 0;
   Earm_CDET_Scint_hit_xhit = 0;
   Earm_CDET_Scint_hit_yhit = 0;
   Earm_CDET_Scint_hit_zhit = 0;
   Earm_CDET_Scint_hit_sumedep = 0;
   Earm_CDET_Scint_hit_tavg = 0;
   Earm_CDET_Scint_hit_trms = 0;
   Earm_CDET_Scint_hit_tmin = 0;
   Earm_CDET_Scint_hit_tmax = 0;
   
   Harm_CDET_hit_PMT = 0;
   Harm_CDET_hit_row = 0;
   Harm_CDET_hit_col = 0;
   Harm_CDET_hit_plane = 0;
   Harm_CDET_hit_xcell = 0;
   Harm_CDET_hit_ycell = 0;
   Harm_CDET_hit_zcell = 0;
   Harm_CDET_hit_xgcell = 0;
   Harm_CDET_hit_ygcell = 0;
   Harm_CDET_hit_zgcell = 0;
   Harm_CDET_hit_NumPhotoelectrons = 0;
   Harm_CDET_hit_Time_avg = 0;
   Harm_CDET_hit_Time_rms = 0;
   Harm_CDET_hit_Time_min = 0;
   Harm_CDET_hit_Time_max = 0;
   
   Harm_CDET_Scint_hit_row = 0;
   Harm_CDET_Scint_hit_col = 0;
   Harm_CDET_Scint_hit_cell = 0;
   Harm_CDET_Scint_hit_plane = 0;
   Harm_CDET_Scint_hit_xcell = 0;
   Harm_CDET_Scint_hit_ycell = 0;
   Harm_CDET_Scint_hit_zcell = 0;
   Harm_CDET_Scint_hit_xcellg = 0;
   Harm_CDET_Scint_hit_ycellg = 0;
   Harm_CDET_Scint_hit_zcellg = 0;
   Harm_CDET_Scint_hit_xhit = 0;
   Harm_CDET_Scint_hit_yhit = 0;
   Harm_CDET_Scint_hit_zhit = 0;
   Harm_CDET_Scint_hit_sumedep = 0;
   Harm_CDET_Scint_hit_tavg = 0;
   Harm_CDET_Scint_hit_trms = 0;
   Harm_CDET_Scint_hit_tmin = 0;
   Harm_CDET_Scint_hit_tmax = 0;
   
   Earm_ECAL_box_hit_row = 0;
   Earm_ECAL_box_hit_col = 0;
   Earm_ECAL_box_hit_cell = 0;
   Earm_ECAL_box_hit_plane = 0;
   Earm_ECAL_box_hit_xcell = 0;
   Earm_ECAL_box_hit_ycell = 0;
   Earm_ECAL_box_hit_zcell = 0;
   Earm_ECAL_box_hit_xcellg = 0;
   Earm_ECAL_box_hit_ycellg = 0;
   Earm_ECAL_box_hit_zcellg = 0;
   Earm_ECAL_box_hit_xhit = 0;
   Earm_ECAL_box_hit_yhit = 0;
   Earm_ECAL_box_hit_zhit = 0;
   Earm_ECAL_box_hit_sumedep = 0;
   Earm_ECAL_box_hit_tavg = 0;
   Earm_ECAL_box_hit_trms = 0;
   Earm_ECAL_box_hit_tmin = 0;
   Earm_ECAL_box_hit_tmax = 0;
   
   Earm_ECAL_hit_PMT = 0;
   Earm_ECAL_hit_row = 0;
   Earm_ECAL_hit_col = 0;
   Earm_ECAL_hit_plane = 0;
   Earm_ECAL_hit_xcell = 0;
   Earm_ECAL_hit_ycell = 0;
   Earm_ECAL_hit_zcell = 0;
   Earm_ECAL_hit_xgcell = 0;
   Earm_ECAL_hit_ygcell = 0;
   Earm_ECAL_hit_zgcell = 0;
   Earm_ECAL_hit_NumPhotoelectrons = 0;
   Earm_ECAL_hit_Time_avg = 0;
   Earm_ECAL_hit_Time_rms = 0;
   Earm_ECAL_hit_Time_min = 0;
   Earm_ECAL_hit_Time_max = 0;
   
   Earm_ECalTF1_hit_row = 0;
   Earm_ECalTF1_hit_col = 0;
   Earm_ECalTF1_hit_cell = 0;
   Earm_ECalTF1_hit_plane = 0;
   Earm_ECalTF1_hit_xcell = 0;
   Earm_ECalTF1_hit_ycell = 0;
   Earm_ECalTF1_hit_zcell = 0;
   Earm_ECalTF1_hit_xcellg = 0;
   Earm_ECalTF1_hit_ycellg = 0;
   Earm_ECalTF1_hit_zcellg = 0;
   Earm_ECalTF1_hit_xhit = 0;
   Earm_ECalTF1_hit_yhit = 0;
   Earm_ECalTF1_hit_zhit = 0;
   Earm_ECalTF1_hit_sumedep = 0;
   Earm_ECalTF1_hit_tavg = 0;
   Earm_ECalTF1_hit_trms = 0;
   Earm_ECalTF1_hit_tmin = 0;
   Earm_ECalTF1_hit_tmax = 0;
   
   Harm_FPP1_hit_plane = 0;
   Harm_FPP1_hit_strip = 0;
   Harm_FPP1_hit_x = 0;
   Harm_FPP1_hit_y = 0;
   Harm_FPP1_hit_z = 0;
   Harm_FPP1_hit_polx = 0;
   Harm_FPP1_hit_poly = 0;
   Harm_FPP1_hit_polz = 0;
   Harm_FPP1_hit_t = 0;
   Harm_FPP1_hit_trms = 0;
   Harm_FPP1_hit_tmin = 0;
   Harm_FPP1_hit_tmax = 0;
   Harm_FPP1_hit_tx = 0;
   Harm_FPP1_hit_ty = 0;
   Harm_FPP1_hit_txp = 0;
   Harm_FPP1_hit_typ = 0;
   Harm_FPP1_hit_xg = 0;
   Harm_FPP1_hit_yg = 0;
   Harm_FPP1_hit_zg = 0;
   Harm_FPP1_hit_trid = 0;
   Harm_FPP1_hit_mid = 0;
   Harm_FPP1_hit_pid = 0;
   Harm_FPP1_hit_vx = 0;
   Harm_FPP1_hit_vy = 0;
   Harm_FPP1_hit_vz = 0;
   Harm_FPP1_hit_p = 0;
   Harm_FPP1_hit_edep = 0;
   Harm_FPP1_hit_beta = 0;
   
   Harm_FPP1_Track_TID = 0;
   Harm_FPP1_Track_PID = 0;
   Harm_FPP1_Track_MID = 0;
   Harm_FPP1_Track_NumHits = 0;
   Harm_FPP1_Track_NumPlanes = 0;
   Harm_FPP1_Track_NDF = 0;
   Harm_FPP1_Track_Chi2fit = 0;
   Harm_FPP1_Track_Chi2true = 0;
   Harm_FPP1_Track_X = 0;
   Harm_FPP1_Track_Y = 0;
   Harm_FPP1_Track_Xp = 0;
   Harm_FPP1_Track_Yp = 0;
   Harm_FPP1_Track_T = 0;
   Harm_FPP1_Track_P = 0;
   Harm_FPP1_Track_Sx = 0;
   Harm_FPP1_Track_Sy = 0;
   Harm_FPP1_Track_Sz = 0;
   Harm_FPP1_Track_Xfit = 0;
   Harm_FPP1_Track_Yfit = 0;
   Harm_FPP1_Track_Xpfit = 0;
   Harm_FPP1_Track_Ypfit = 0;
   
   Harm_FPP2_hit_plane = 0;
   Harm_FPP2_hit_strip = 0;
   Harm_FPP2_hit_x = 0;
   Harm_FPP2_hit_y = 0;
   Harm_FPP2_hit_z = 0;
   Harm_FPP2_hit_polx = 0;
   Harm_FPP2_hit_poly = 0;
   Harm_FPP2_hit_polz = 0;
   Harm_FPP2_hit_t = 0;
   Harm_FPP2_hit_trms = 0;
   Harm_FPP2_hit_tmin = 0;
   Harm_FPP2_hit_tmax = 0;
   Harm_FPP2_hit_tx = 0;
   Harm_FPP2_hit_ty = 0;
   Harm_FPP2_hit_txp = 0;
   Harm_FPP2_hit_typ = 0;
   Harm_FPP2_hit_xg = 0;
   Harm_FPP2_hit_yg = 0;
   Harm_FPP2_hit_zg = 0;
   Harm_FPP2_hit_trid = 0;
   Harm_FPP2_hit_mid = 0;
   Harm_FPP2_hit_pid = 0;
   Harm_FPP2_hit_vx = 0;
   Harm_FPP2_hit_vy = 0;
   Harm_FPP2_hit_vz = 0;
   Harm_FPP2_hit_p = 0;
   Harm_FPP2_hit_edep = 0;
   Harm_FPP2_hit_beta = 0;
   
   Harm_FPP2_Track_TID = 0;
   Harm_FPP2_Track_PID = 0;
   Harm_FPP2_Track_MID = 0;
   Harm_FPP2_Track_NumHits = 0;
   Harm_FPP2_Track_NumPlanes = 0;
   Harm_FPP2_Track_NDF = 0;
   Harm_FPP2_Track_Chi2fit = 0;
   Harm_FPP2_Track_Chi2true = 0;
   Harm_FPP2_Track_X = 0;
   Harm_FPP2_Track_Y = 0;
   Harm_FPP2_Track_Xp = 0;
   Harm_FPP2_Track_Yp = 0;
   Harm_FPP2_Track_T = 0;
   Harm_FPP2_Track_P = 0;
   Harm_FPP2_Track_Sx = 0;
   Harm_FPP2_Track_Sy = 0;
   Harm_FPP2_Track_Sz = 0;
   Harm_FPP2_Track_Xfit = 0;
   Harm_FPP2_Track_Yfit = 0;
   Harm_FPP2_Track_Xpfit = 0;
   Harm_FPP2_Track_Ypfit = 0;
   
   Harm_FT_hit_plane = 0;
   Harm_FT_hit_strip = 0;
   Harm_FT_hit_x = 0;
   Harm_FT_hit_y = 0;
   Harm_FT_hit_z = 0;
   Harm_FT_hit_polx = 0;
   Harm_FT_hit_poly = 0;
   Harm_FT_hit_polz = 0;
   Harm_FT_hit_t = 0;
   Harm_FT_hit_trms = 0;
   Harm_FT_hit_tmin = 0;
   Harm_FT_hit_tmax = 0;
   Harm_FT_hit_tx = 0;
   Harm_FT_hit_ty = 0;
   Harm_FT_hit_txp = 0;
   Harm_FT_hit_typ = 0;
   Harm_FT_hit_xg = 0;
   Harm_FT_hit_yg = 0;
   Harm_FT_hit_zg = 0;
   Harm_FT_hit_trid = 0;
   Harm_FT_hit_mid = 0;
   Harm_FT_hit_pid = 0;
   Harm_FT_hit_vx = 0;
   Harm_FT_hit_vy = 0;
   Harm_FT_hit_vz = 0;
   Harm_FT_hit_p = 0;
   Harm_FT_hit_edep = 0;
   Harm_FT_hit_beta = 0;
   
   Harm_FT_Track_TID = 0;
   Harm_FT_Track_PID = 0;
   Harm_FT_Track_MID = 0;
   Harm_FT_Track_NumHits = 0;
   Harm_FT_Track_NumPlanes = 0;
   Harm_FT_Track_NDF = 0;
   Harm_FT_Track_Chi2fit = 0;
   Harm_FT_Track_Chi2true = 0;
   Harm_FT_Track_X = 0;
   Harm_FT_Track_Y = 0;
   Harm_FT_Track_Xp = 0;
   Harm_FT_Track_Yp = 0;
   Harm_FT_Track_T = 0;
   Harm_FT_Track_P = 0;
   Harm_FT_Track_Sx = 0;
   Harm_FT_Track_Sy = 0;
   Harm_FT_Track_Sz = 0;
   Harm_FT_Track_Xfit = 0;
   Harm_FT_Track_Yfit = 0;
   Harm_FT_Track_Xpfit = 0;
   Harm_FT_Track_Ypfit = 0;

   Harm_SBSGEM_hit_plane = 0;
   Harm_SBSGEM_hit_strip = 0;
   Harm_SBSGEM_hit_x = 0;
   Harm_SBSGEM_hit_y = 0;
   Harm_SBSGEM_hit_z = 0;
   Harm_SBSGEM_hit_polx = 0;
   Harm_SBSGEM_hit_poly = 0;
   Harm_SBSGEM_hit_polz = 0;
   Harm_SBSGEM_hit_trms = 0;
   Harm_SBSGEM_hit_tmin = 0;
   Harm_SBSGEM_hit_tmax = 0;
   Harm_SBSGEM_hit_tx = 0;
   Harm_SBSGEM_hit_ty = 0;
   Harm_SBSGEM_hit_txp = 0;
   Harm_SBSGEM_hit_typ = 0;
   Harm_SBSGEM_hit_xg = 0;
   Harm_SBSGEM_hit_yg = 0;
   Harm_SBSGEM_hit_zg = 0;
   Harm_SBSGEM_hit_trid = 0;
   Harm_SBSGEM_hit_mid = 0;
   Harm_SBSGEM_hit_pid = 0;
   Harm_SBSGEM_hit_vx = 0;
   Harm_SBSGEM_hit_vy = 0;
   Harm_SBSGEM_hit_vz = 0;
   Harm_SBSGEM_hit_p = 0;
   Harm_SBSGEM_hit_edep = 0;
   Harm_SBSGEM_hit_beta = 0;
   
   Harm_SBSGEM_Track_TID = 0;
   Harm_SBSGEM_Track_PID = 0;
   Harm_SBSGEM_Track_MID = 0;
   Harm_SBSGEM_Track_NumHits = 0;
   Harm_SBSGEM_Track_NumPlanes = 0;
   Harm_SBSGEM_Track_NDF = 0;
   Harm_SBSGEM_Track_Chi2fit = 0;
   Harm_SBSGEM_Track_Chi2true = 0;
   Harm_SBSGEM_Track_X = 0;
   Harm_SBSGEM_Track_Y = 0;
   Harm_SBSGEM_Track_Xp = 0;
   Harm_SBSGEM_Track_Yp = 0;
   Harm_SBSGEM_Track_Sx = 0;
   Harm_SBSGEM_Track_Sy = 0;
   Harm_SBSGEM_Track_Sz = 0;
   Harm_SBSGEM_Track_Xfit = 0;
   Harm_SBSGEM_Track_Yfit = 0;
   Harm_SBSGEM_Track_Xpfit = 0;
   Harm_SBSGEM_Track_Ypfit = 0;
   
   Harm_RICH_hit_PMT = 0;
   Harm_RICH_hit_row = 0;
   Harm_RICH_hit_col = 0;
   Harm_RICH_hit_xpmt = 0;
   Harm_RICH_hit_ypmt = 0;
   Harm_RICH_hit_zpmt = 0;
   Harm_RICH_hit_xgpmt = 0;
   Harm_RICH_hit_ygpmt = 0;
   Harm_RICH_hit_zgpmt = 0;
   Harm_RICH_hit_NumPhotoelectrons = 0;
   Harm_RICH_hit_Time_avg = 0;
   Harm_RICH_hit_Time_rms = 0;
   Harm_RICH_hit_Time_min = 0;
   Harm_RICH_hit_Time_max = 0;
   Harm_RICH_hit_mTrackNo = 0;
   Harm_RICH_hit_xhit = 0;
   Harm_RICH_hit_yhit = 0;
   Harm_RICH_hit_zhit = 0;
   Harm_RICH_hit_pxhit = 0;
   Harm_RICH_hit_pyhit = 0;
   Harm_RICH_hit_pzhit = 0;
   Harm_RICH_hit_pvx = 0;
   Harm_RICH_hit_pvy = 0;
   Harm_RICH_hit_pvz = 0;
   Harm_RICH_hit_ppx = 0;
   Harm_RICH_hit_ppy = 0;
   Harm_RICH_hit_ppz = 0;
   Harm_RICH_hit_volume_flag = 0;

   Primaries_PID = 0;
   Primaries_genflag = 0;
   Primaries_Px = 0;
   Primaries_Py = 0;
   Primaries_Pz = 0;
   Primaries_vx = 0;
   Primaries_vy = 0;
   Primaries_vz = 0;
   Primaries_M = 0;
   Primaries_E = 0;
   Primaries_P = 0;
   Primaries_t = 0;
   Primaries_theta = 0;
   Primaries_phi = 0;
    
   
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("ev", &ev_count, &b_ev);
   fChain->SetBranchAddress("gen", &gen_thbb, &b_gen);
   
   //BigBite detector package: all expts except GEp
   if(fExpOption!=3){
     fChain->SetBranchAddress("Earm.BBGEM.hit.nhits", &Earm_BBGEM_hit_nhits, &b_Earm_BBGEM_hit_nhits);
     fChain->SetBranchAddress("Earm.BBGEM.hit.plane", &Earm_BBGEM_hit_plane, &b_Earm_BBGEM_hit_plane);
     fChain->SetBranchAddress("Earm.BBGEM.hit.strip", &Earm_BBGEM_hit_strip, &b_Earm_BBGEM_hit_strip);
     fChain->SetBranchAddress("Earm.BBGEM.hit.x", &Earm_BBGEM_hit_x, &b_Earm_BBGEM_hit_x);
     fChain->SetBranchAddress("Earm.BBGEM.hit.y", &Earm_BBGEM_hit_y, &b_Earm_BBGEM_hit_y);
     fChain->SetBranchAddress("Earm.BBGEM.hit.z", &Earm_BBGEM_hit_z, &b_Earm_BBGEM_hit_z);
     fChain->SetBranchAddress("Earm.BBGEM.hit.polx", &Earm_BBGEM_hit_polx, &b_Earm_BBGEM_hit_polx);
     fChain->SetBranchAddress("Earm.BBGEM.hit.poly", &Earm_BBGEM_hit_poly, &b_Earm_BBGEM_hit_poly);
     fChain->SetBranchAddress("Earm.BBGEM.hit.polz", &Earm_BBGEM_hit_polz, &b_Earm_BBGEM_hit_polz);
     fChain->SetBranchAddress("Earm.BBGEM.hit.trms", &Earm_BBGEM_hit_trms, &b_Earm_BBGEM_hit_trms);
     fChain->SetBranchAddress("Earm.BBGEM.hit.tmin", &Earm_BBGEM_hit_tmin, &b_Earm_BBGEM_hit_tmin);
     fChain->SetBranchAddress("Earm.BBGEM.hit.tmax", &Earm_BBGEM_hit_tmax, &b_Earm_BBGEM_hit_tmax);
     fChain->SetBranchAddress("Earm.BBGEM.hit.tx", &Earm_BBGEM_hit_tx, &b_Earm_BBGEM_hit_tx);
     fChain->SetBranchAddress("Earm.BBGEM.hit.ty", &Earm_BBGEM_hit_ty, &b_Earm_BBGEM_hit_ty);
     fChain->SetBranchAddress("Earm.BBGEM.hit.txp", &Earm_BBGEM_hit_txp, &b_Earm_BBGEM_hit_txp);
     fChain->SetBranchAddress("Earm.BBGEM.hit.typ", &Earm_BBGEM_hit_typ, &b_Earm_BBGEM_hit_typ);
     fChain->SetBranchAddress("Earm.BBGEM.hit.xg", &Earm_BBGEM_hit_xg, &b_Earm_BBGEM_hit_xg);
     fChain->SetBranchAddress("Earm.BBGEM.hit.yg", &Earm_BBGEM_hit_yg, &b_Earm_BBGEM_hit_yg);
     fChain->SetBranchAddress("Earm.BBGEM.hit.zg", &Earm_BBGEM_hit_zg, &b_Earm_BBGEM_hit_zg);
     fChain->SetBranchAddress("Earm.BBGEM.hit.trid", &Earm_BBGEM_hit_trid, &b_Earm_BBGEM_hit_trid);
     fChain->SetBranchAddress("Earm.BBGEM.hit.mid", &Earm_BBGEM_hit_mid, &b_Earm_BBGEM_hit_mid);
     fChain->SetBranchAddress("Earm.BBGEM.hit.pid", &Earm_BBGEM_hit_pid, &b_Earm_BBGEM_hit_pid);
     fChain->SetBranchAddress("Earm.BBGEM.hit.vx", &Earm_BBGEM_hit_vx, &b_Earm_BBGEM_hit_vx);
     fChain->SetBranchAddress("Earm.BBGEM.hit.vy", &Earm_BBGEM_hit_vy, &b_Earm_BBGEM_hit_vy);
     fChain->SetBranchAddress("Earm.BBGEM.hit.vz", &Earm_BBGEM_hit_vz, &b_Earm_BBGEM_hit_vz);
     fChain->SetBranchAddress("Earm.BBGEM.hit.p", &Earm_BBGEM_hit_p, &b_Earm_BBGEM_hit_p);
     fChain->SetBranchAddress("Earm.BBGEM.hit.edep", &Earm_BBGEM_hit_edep, &b_Earm_BBGEM_hit_edep);
     fChain->SetBranchAddress("Earm.BBGEM.hit.beta", &Earm_BBGEM_hit_beta, &b_Earm_BBGEM_hit_beta);
   
     fChain->SetBranchAddress("Earm.BBGEM.Track.ntracks", &Earm_BBGEM_Track_ntracks, &b_Earm_BBGEM_Track_ntracks);
     fChain->SetBranchAddress("Earm.BBGEM.Track.TID", &Earm_BBGEM_Track_TID, &b_Earm_BBGEM_Track_TID);
     fChain->SetBranchAddress("Earm.BBGEM.Track.PID", &Earm_BBGEM_Track_PID, &b_Earm_BBGEM_Track_PID);
     fChain->SetBranchAddress("Earm.BBGEM.Track.MID", &Earm_BBGEM_Track_MID, &b_Earm_BBGEM_Track_MID);
     fChain->SetBranchAddress("Earm.BBGEM.Track.NumHits", &Earm_BBGEM_Track_NumHits, &b_Earm_BBGEM_Track_NumHits);
     fChain->SetBranchAddress("Earm.BBGEM.Track.NumPlanes", &Earm_BBGEM_Track_NumPlanes, &b_Earm_BBGEM_Track_NumPlanes);
     fChain->SetBranchAddress("Earm.BBGEM.Track.NDF", &Earm_BBGEM_Track_NDF, &b_Earm_BBGEM_Track_NDF);
     fChain->SetBranchAddress("Earm.BBGEM.Track.Chi2fit", &Earm_BBGEM_Track_Chi2fit, &b_Earm_BBGEM_Track_Chi2fit);
     fChain->SetBranchAddress("Earm.BBGEM.Track.Chi2true", &Earm_BBGEM_Track_Chi2true, &b_Earm_BBGEM_Track_Chi2true);
     fChain->SetBranchAddress("Earm.BBGEM.Track.X", &Earm_BBGEM_Track_X, &b_Earm_BBGEM_Track_X);
     fChain->SetBranchAddress("Earm.BBGEM.Track.Y", &Earm_BBGEM_Track_Y, &b_Earm_BBGEM_Track_Y);
     fChain->SetBranchAddress("Earm.BBGEM.Track.Xp", &Earm_BBGEM_Track_Xp, &b_Earm_BBGEM_Track_Xp);
     fChain->SetBranchAddress("Earm.BBGEM.Track.Yp", &Earm_BBGEM_Track_Yp, &b_Earm_BBGEM_Track_Yp);
     fChain->SetBranchAddress("Earm.BBGEM.Track.Sx", &Earm_BBGEM_Track_Sx, &b_Earm_BBGEM_Track_Sx);
     fChain->SetBranchAddress("Earm.BBGEM.Track.Sy", &Earm_BBGEM_Track_Sy, &b_Earm_BBGEM_Track_Sy);
     fChain->SetBranchAddress("Earm.BBGEM.Track.Sz", &Earm_BBGEM_Track_Sz, &b_Earm_BBGEM_Track_Sz);
     fChain->SetBranchAddress("Earm.BBGEM.Track.Xfit", &Earm_BBGEM_Track_Xfit, &b_Earm_BBGEM_Track_Xfit);
     fChain->SetBranchAddress("Earm.BBGEM.Track.Yfit", &Earm_BBGEM_Track_Yfit, &b_Earm_BBGEM_Track_Yfit);
     fChain->SetBranchAddress("Earm.BBGEM.Track.Xpfit", &Earm_BBGEM_Track_Xpfit, &b_Earm_BBGEM_Track_Xpfit);
     fChain->SetBranchAddress("Earm.BBGEM.Track.Ypfit", &Earm_BBGEM_Track_Ypfit, &b_Earm_BBGEM_Track_Ypfit);
   
   
     fChain->SetBranchAddress("Earm.GRINCH.hit.nhits", &Earm_GRINCH_hit_nhits, &b_Earm_GRINCH_hit_nhits);
     fChain->SetBranchAddress("Earm.GRINCH.hit.PMT", &Earm_GRINCH_hit_PMT, &b_Earm_GRINCH_hit_PMT);
     fChain->SetBranchAddress("Earm.GRINCH.hit.row", &Earm_GRINCH_hit_row, &b_Earm_GRINCH_hit_row);
     fChain->SetBranchAddress("Earm.GRINCH.hit.col", &Earm_GRINCH_hit_col, &b_Earm_GRINCH_hit_col);
     fChain->SetBranchAddress("Earm.GRINCH.hit.xpmt", &Earm_GRINCH_hit_xpmt, &b_Earm_GRINCH_hit_xpmt);
     fChain->SetBranchAddress("Earm.GRINCH.hit.ypmt", &Earm_GRINCH_hit_ypmt, &b_Earm_GRINCH_hit_ypmt);
     fChain->SetBranchAddress("Earm.GRINCH.hit.zpmt", &Earm_GRINCH_hit_zpmt, &b_Earm_GRINCH_hit_zpmt);
     fChain->SetBranchAddress("Earm.GRINCH.hit.xgpmt", &Earm_GRINCH_hit_xgpmt, &b_Earm_GRINCH_hit_xgpmt);
     fChain->SetBranchAddress("Earm.GRINCH.hit.ygpmt", &Earm_GRINCH_hit_ygpmt, &b_Earm_GRINCH_hit_ygpmt);
     fChain->SetBranchAddress("Earm.GRINCH.hit.zgpmt", &Earm_GRINCH_hit_zgpmt, &b_Earm_GRINCH_hit_zgpmt);
     fChain->SetBranchAddress("Earm.GRINCH.hit.NumPhotoelectrons", &Earm_GRINCH_hit_NumPhotoelectrons, &b_Earm_GRINCH_hit_NumPhotoelectrons);
     fChain->SetBranchAddress("Earm.GRINCH.hit.Time_avg", &Earm_GRINCH_hit_Time_avg, &b_Earm_GRINCH_hit_Time_avg);
     fChain->SetBranchAddress("Earm.GRINCH.hit.Time_rms", &Earm_GRINCH_hit_Time_rms, &b_Earm_GRINCH_hit_Time_rms);
     fChain->SetBranchAddress("Earm.GRINCH.hit.Time_min", &Earm_GRINCH_hit_Time_min, &b_Earm_GRINCH_hit_Time_min);
     fChain->SetBranchAddress("Earm.GRINCH.hit.Time_max", &Earm_GRINCH_hit_Time_max, &b_Earm_GRINCH_hit_Time_max);
     fChain->SetBranchAddress("Earm.GRINCH.hit.mTrackNo", &Earm_GRINCH_hit_mTrackNo, &b_Earm_GRINCH_hit_mTrackNo);
     fChain->SetBranchAddress("Earm.GRINCH.hit.xhit", &Earm_GRINCH_hit_xhit, &b_Earm_GRINCH_hit_xhit);
     fChain->SetBranchAddress("Earm.GRINCH.hit.yhit", &Earm_GRINCH_hit_yhit, &b_Earm_GRINCH_hit_yhit);
     fChain->SetBranchAddress("Earm.GRINCH.hit.zhit", &Earm_GRINCH_hit_zhit, &b_Earm_GRINCH_hit_zhit);
     fChain->SetBranchAddress("Earm.GRINCH.hit.pxhit", &Earm_GRINCH_hit_pxhit, &b_Earm_GRINCH_hit_pxhit);
     fChain->SetBranchAddress("Earm.GRINCH.hit.pyhit", &Earm_GRINCH_hit_pyhit, &b_Earm_GRINCH_hit_pyhit);
     fChain->SetBranchAddress("Earm.GRINCH.hit.pzhit", &Earm_GRINCH_hit_pzhit, &b_Earm_GRINCH_hit_pzhit);
     fChain->SetBranchAddress("Earm.GRINCH.hit.pvx", &Earm_GRINCH_hit_pvx, &b_Earm_GRINCH_hit_pvx);
     fChain->SetBranchAddress("Earm.GRINCH.hit.pvy", &Earm_GRINCH_hit_pvy, &b_Earm_GRINCH_hit_pvy);
     fChain->SetBranchAddress("Earm.GRINCH.hit.pvz", &Earm_GRINCH_hit_pvz, &b_Earm_GRINCH_hit_pvz);
     fChain->SetBranchAddress("Earm.GRINCH.hit.ppx", &Earm_GRINCH_hit_ppx, &b_Earm_GRINCH_hit_ppx);
     fChain->SetBranchAddress("Earm.GRINCH.hit.ppy", &Earm_GRINCH_hit_ppy, &b_Earm_GRINCH_hit_ppy);
     fChain->SetBranchAddress("Earm.GRINCH.hit.ppz", &Earm_GRINCH_hit_ppz, &b_Earm_GRINCH_hit_ppz);
     fChain->SetBranchAddress("Earm.GRINCH.hit.volume_flag", &Earm_GRINCH_hit_volume_flag, &b_Earm_GRINCH_hit_volume_flag);
    
     if(fEcalBox){
       fChain->SetBranchAddress("Earm.BBCal.hit.nhits", &Earm_ECAL_box_hit_nhits, &b_Earm_ECAL_box_hit_nhits);
       fChain->SetBranchAddress("Earm.BBCal.hit.row", &Earm_ECAL_box_hit_row, &b_Earm_ECAL_box_hit_row);
       fChain->SetBranchAddress("Earm.BBCal.hit.col", &Earm_ECAL_box_hit_col, &b_Earm_ECAL_box_hit_col);
       fChain->SetBranchAddress("Earm.BBCal.hit.cell", &Earm_ECAL_box_hit_cell, &b_Earm_ECAL_box_hit_cell);
       fChain->SetBranchAddress("Earm.BBCal.hit.plane", &Earm_ECAL_box_hit_plane, &b_Earm_ECAL_box_hit_plane);
       fChain->SetBranchAddress("Earm.BBCal.hit.xcell", &Earm_ECAL_box_hit_xcell, &b_Earm_ECAL_box_hit_xcell);
       fChain->SetBranchAddress("Earm.BBCal.hit.ycell", &Earm_ECAL_box_hit_ycell, &b_Earm_ECAL_box_hit_ycell);
       fChain->SetBranchAddress("Earm.BBCal.hit.zcell", &Earm_ECAL_box_hit_zcell, &b_Earm_ECAL_box_hit_zcell);
       fChain->SetBranchAddress("Earm.BBCal.hit.xcellg", &Earm_ECAL_box_hit_xcellg, &b_Earm_ECAL_box_hit_xcellg);
       fChain->SetBranchAddress("Earm.BBCal.hit.ycellg", &Earm_ECAL_box_hit_ycellg, &b_Earm_ECAL_box_hit_ycellg);
       fChain->SetBranchAddress("Earm.BBCal.hit.zcellg", &Earm_ECAL_box_hit_zcellg, &b_Earm_ECAL_box_hit_zcellg);
       fChain->SetBranchAddress("Earm.BBCal.hit.xhit", &Earm_ECAL_box_hit_xhit, &b_Earm_ECAL_box_hit_xhit);
       fChain->SetBranchAddress("Earm.BBCal.hit.yhit", &Earm_ECAL_box_hit_yhit, &b_Earm_ECAL_box_hit_yhit);
       fChain->SetBranchAddress("Earm.BBCal.hit.zhit", &Earm_ECAL_box_hit_zhit, &b_Earm_ECAL_box_hit_zhit);
       fChain->SetBranchAddress("Earm.BBCal.hit.sumedep", &Earm_ECAL_box_hit_sumedep, &b_Earm_ECAL_box_hit_sumedep);
       fChain->SetBranchAddress("Earm.BBCal.hit.tavg", &Earm_ECAL_box_hit_tavg, &b_Earm_ECAL_box_hit_tavg);
       fChain->SetBranchAddress("Earm.BBCal.hit.trms", &Earm_ECAL_box_hit_trms, &b_Earm_ECAL_box_hit_trms);
       fChain->SetBranchAddress("Earm.BBCal.hit.tmin", &Earm_ECAL_box_hit_tmin, &b_Earm_ECAL_box_hit_tmin);
       fChain->SetBranchAddress("Earm.BBCal.hit.tmax", &Earm_ECAL_box_hit_tmax, &b_Earm_ECAL_box_hit_tmax);
       
       /*
	 fChain->SetBranchAddress("Earm.BBCal.part.npart", &Earm_ECAL_box_part_npart, &b_Earm_ECAL_box_part_npart);
	 fChain->SetBranchAddress("Earm.BBCal.part.PID", &Earm_ECAL_box_part_PID, &b_Earm_ECAL_box_part_PID);
	 fChain->SetBranchAddress("Earm.BBCal.part.MID", &Earm_ECAL_box_part_MID, &b_Earm_ECAL_box_part_MID);
	 fChain->SetBranchAddress("Earm.BBCal.part.TID", &Earm_ECAL_box_part_TID, &b_Earm_ECAL_box_part_TID);
	 fChain->SetBranchAddress("Earm.BBCal.part.nbounce", &Earm_ECAL_box_part_nbounce, &b_Earm_ECAL_box_part_nbounce);
	 fChain->SetBranchAddress("Earm.BBCal.part.hitindex", &Earm_ECAL_box_part_hitindex, &b_Earm_ECAL_box_part_hitindex);
	 fChain->SetBranchAddress("Earm.BBCal.part.vx", &Earm_ECAL_box_part_vx, &b_Earm_ECAL_box_part_vx);
	 fChain->SetBranchAddress("Earm.BBCal.part.vy", &Earm_ECAL_box_part_vy, &b_Earm_ECAL_box_part_vy);
	 fChain->SetBranchAddress("Earm.BBCal.part.vz", &Earm_ECAL_box_part_vz, &b_Earm_ECAL_box_part_vz);
	 fChain->SetBranchAddress("Earm.BBCal.part.px", &Earm_ECAL_box_part_px, &b_Earm_ECAL_box_part_px);
	 fChain->SetBranchAddress("Earm.BBCal.part.py", &Earm_ECAL_box_part_py, &b_Earm_ECAL_box_part_py);
	 fChain->SetBranchAddress("Earm.BBCal.part.pz", &Earm_ECAL_box_part_pz, &b_Earm_ECAL_box_part_pz);
       */
     }else{
       fChain->SetBranchAddress("Earm.BBPS.hit.nhits", &Earm_BBPS_hit_nhits, &b_Earm_BBPS_hit_nhits);
       fChain->SetBranchAddress("Earm.BBPS.hit.PMT", &Earm_BBPS_hit_PMT, &b_Earm_BBPS_hit_PMT);
       fChain->SetBranchAddress("Earm.BBPS.hit.row", &Earm_BBPS_hit_row, &b_Earm_BBPS_hit_row);
       fChain->SetBranchAddress("Earm.BBPS.hit.col", &Earm_BBPS_hit_col, &b_Earm_BBPS_hit_col);
       fChain->SetBranchAddress("Earm.BBPS.hit.plane", &Earm_BBPS_hit_plane, &b_Earm_BBPS_hit_plane);
       fChain->SetBranchAddress("Earm.BBPS.hit.xcell", &Earm_BBPS_hit_xcell, &b_Earm_BBPS_hit_xcell);
       fChain->SetBranchAddress("Earm.BBPS.hit.ycell", &Earm_BBPS_hit_ycell, &b_Earm_BBPS_hit_ycell);
       fChain->SetBranchAddress("Earm.BBPS.hit.zcell", &Earm_BBPS_hit_zcell, &b_Earm_BBPS_hit_zcell);
       fChain->SetBranchAddress("Earm.BBPS.hit.xgcell", &Earm_BBPS_hit_xgcell, &b_Earm_BBPS_hit_xgcell);
       fChain->SetBranchAddress("Earm.BBPS.hit.ygcell", &Earm_BBPS_hit_ygcell, &b_Earm_BBPS_hit_ygcell);
       fChain->SetBranchAddress("Earm.BBPS.hit.zgcell", &Earm_BBPS_hit_zgcell, &b_Earm_BBPS_hit_zgcell);
       fChain->SetBranchAddress("Earm.BBPS.hit.NumPhotoelectrons", &Earm_BBPS_hit_NumPhotoelectrons, &b_Earm_BBPS_hit_NumPhotoelectrons);
       fChain->SetBranchAddress("Earm.BBPS.hit.Time_avg", &Earm_BBPS_hit_Time_avg, &b_Earm_BBPS_hit_Time_avg);
       fChain->SetBranchAddress("Earm.BBPS.hit.Time_rms", &Earm_BBPS_hit_Time_rms, &b_Earm_BBPS_hit_Time_rms);
       fChain->SetBranchAddress("Earm.BBPS.hit.Time_min", &Earm_BBPS_hit_Time_min, &b_Earm_BBPS_hit_Time_min);
       fChain->SetBranchAddress("Earm.BBPS.hit.Time_max", &Earm_BBPS_hit_Time_max, &b_Earm_BBPS_hit_Time_max);
   
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.nhits", &Earm_BBPSTF1_hit_nhits, &b_Earm_BBPSTF1_hit_nhits);
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.row", &Earm_BBPSTF1_hit_row, &b_Earm_BBPSTF1_hit_row);
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.col", &Earm_BBPSTF1_hit_col, &b_Earm_BBPSTF1_hit_col);
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.cell", &Earm_BBPSTF1_hit_cell, &b_Earm_BBPSTF1_hit_cell);
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.plane", &Earm_BBPSTF1_hit_plane, &b_Earm_BBPSTF1_hit_plane);
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.xcell", &Earm_BBPSTF1_hit_xcell, &b_Earm_BBPSTF1_hit_xcell);
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.ycell", &Earm_BBPSTF1_hit_ycell, &b_Earm_BBPSTF1_hit_ycell);
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.zcell", &Earm_BBPSTF1_hit_zcell, &b_Earm_BBPSTF1_hit_zcell);
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.xcellg", &Earm_BBPSTF1_hit_xcellg, &b_Earm_BBPSTF1_hit_xcellg);
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.ycellg", &Earm_BBPSTF1_hit_ycellg, &b_Earm_BBPSTF1_hit_ycellg);
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.zcellg", &Earm_BBPSTF1_hit_zcellg, &b_Earm_BBPSTF1_hit_zcellg);
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.xhit", &Earm_BBPSTF1_hit_xhit, &b_Earm_BBPSTF1_hit_xhit);
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.yhit", &Earm_BBPSTF1_hit_yhit, &b_Earm_BBPSTF1_hit_yhit);
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.zhit", &Earm_BBPSTF1_hit_zhit, &b_Earm_BBPSTF1_hit_zhit);
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.sumedep", &Earm_BBPSTF1_hit_sumedep, &b_Earm_BBPSTF1_hit_sumedep);
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.tavg", &Earm_BBPSTF1_hit_tavg, &b_Earm_BBPSTF1_hit_tavg);
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.trms", &Earm_BBPSTF1_hit_trms, &b_Earm_BBPSTF1_hit_trms);
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.tmin", &Earm_BBPSTF1_hit_tmin, &b_Earm_BBPSTF1_hit_tmin);
       fChain->SetBranchAddress("Earm.BBPSTF1.hit.tmax", &Earm_BBPSTF1_hit_tmax, &b_Earm_BBPSTF1_hit_tmax);
       
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.nhits", &Earm_BBHodoScint_hit_nhits, &b_Earm_BBHodoScint_hit_nhits);
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.row", &Earm_BBHodoScint_hit_row, &b_Earm_BBHodoScint_hit_row);
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.col", &Earm_BBHodoScint_hit_col, &b_Earm_BBHodoScint_hit_col);
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.cell", &Earm_BBHodoScint_hit_cell, &b_Earm_BBHodoScint_hit_cell);
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.plane", &Earm_BBHodoScint_hit_plane, &b_Earm_BBHodoScint_hit_plane);
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.xcell", &Earm_BBHodoScint_hit_xcell, &b_Earm_BBHodoScint_hit_xcell);
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.ycell", &Earm_BBHodoScint_hit_ycell, &b_Earm_BBHodoScint_hit_ycell);
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.zcell", &Earm_BBHodoScint_hit_zcell, &b_Earm_BBHodoScint_hit_zcell);
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.xcellg", &Earm_BBHodoScint_hit_xcellg, &b_Earm_BBHodoScint_hit_xcellg);
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.ycellg", &Earm_BBHodoScint_hit_ycellg, &b_Earm_BBHodoScint_hit_ycellg);
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.zcellg", &Earm_BBHodoScint_hit_zcellg, &b_Earm_BBHodoScint_hit_zcellg);
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.xhit", &Earm_BBHodoScint_hit_xhit, &b_Earm_BBHodoScint_hit_xhit);
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.yhit", &Earm_BBHodoScint_hit_yhit, &b_Earm_BBHodoScint_hit_yhit);
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.zhit", &Earm_BBHodoScint_hit_zhit, &b_Earm_BBHodoScint_hit_zhit);
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.sumedep", &Earm_BBHodoScint_hit_sumedep, &b_Earm_BBHodoScint_hit_sumedep);
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.tavg", &Earm_BBHodoScint_hit_tavg, &b_Earm_BBHodoScint_hit_tavg);
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.trms", &Earm_BBHodoScint_hit_trms, &b_Earm_BBHodoScint_hit_trms);
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.tmin", &Earm_BBHodoScint_hit_tmin, &b_Earm_BBHodoScint_hit_tmin);
       fChain->SetBranchAddress("Earm.BBHodoScint.hit.tmax", &Earm_BBHodoScint_hit_tmax, &b_Earm_BBHodoScint_hit_tmax);
       
       fChain->SetBranchAddress("Earm.BBSH.hit.nhits", &Earm_BBSH_hit_nhits, &b_Earm_BBSH_hit_nhits);
       fChain->SetBranchAddress("Earm.BBSH.hit.PMT", &Earm_BBSH_hit_PMT, &b_Earm_BBSH_hit_PMT);
       fChain->SetBranchAddress("Earm.BBSH.hit.row", &Earm_BBSH_hit_row, &b_Earm_BBSH_hit_row);
       fChain->SetBranchAddress("Earm.BBSH.hit.col", &Earm_BBSH_hit_col, &b_Earm_BBSH_hit_col);
       fChain->SetBranchAddress("Earm.BBSH.hit.plane", &Earm_BBSH_hit_plane, &b_Earm_BBSH_hit_plane);
       fChain->SetBranchAddress("Earm.BBSH.hit.xcell", &Earm_BBSH_hit_xcell, &b_Earm_BBSH_hit_xcell);
       fChain->SetBranchAddress("Earm.BBSH.hit.ycell", &Earm_BBSH_hit_ycell, &b_Earm_BBSH_hit_ycell);
       fChain->SetBranchAddress("Earm.BBSH.hit.zcell", &Earm_BBSH_hit_zcell, &b_Earm_BBSH_hit_zcell);
       fChain->SetBranchAddress("Earm.BBSH.hit.xgcell", &Earm_BBSH_hit_xgcell, &b_Earm_BBSH_hit_xgcell);
       fChain->SetBranchAddress("Earm.BBSH.hit.ygcell", &Earm_BBSH_hit_ygcell, &b_Earm_BBSH_hit_ygcell);
       fChain->SetBranchAddress("Earm.BBSH.hit.zgcell", &Earm_BBSH_hit_zgcell, &b_Earm_BBSH_hit_zgcell);
       fChain->SetBranchAddress("Earm.BBSH.hit.NumPhotoelectrons", &Earm_BBSH_hit_NumPhotoelectrons, &b_Earm_BBSH_hit_NumPhotoelectrons);
       fChain->SetBranchAddress("Earm.BBSH.hit.Time_avg", &Earm_BBSH_hit_Time_avg, &b_Earm_BBSH_hit_Time_avg);
       fChain->SetBranchAddress("Earm.BBSH.hit.Time_rms", &Earm_BBSH_hit_Time_rms, &b_Earm_BBSH_hit_Time_rms);
       fChain->SetBranchAddress("Earm.BBSH.hit.Time_min", &Earm_BBSH_hit_Time_min, &b_Earm_BBSH_hit_Time_min);
       fChain->SetBranchAddress("Earm.BBSH.hit.Time_max", &Earm_BBSH_hit_Time_max, &b_Earm_BBSH_hit_Time_max);
   
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.nhits", &Earm_BBSHTF1_hit_nhits, &b_Earm_BBSHTF1_hit_nhits);
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.row", &Earm_BBSHTF1_hit_row, &b_Earm_BBSHTF1_hit_row);
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.col", &Earm_BBSHTF1_hit_col, &b_Earm_BBSHTF1_hit_col);
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.cell", &Earm_BBSHTF1_hit_cell, &b_Earm_BBSHTF1_hit_cell);
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.plane", &Earm_BBSHTF1_hit_plane, &b_Earm_BBSHTF1_hit_plane);
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.xcell", &Earm_BBSHTF1_hit_xcell, &b_Earm_BBSHTF1_hit_xcell);
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.ycell", &Earm_BBSHTF1_hit_ycell, &b_Earm_BBSHTF1_hit_ycell);
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.zcell", &Earm_BBSHTF1_hit_zcell, &b_Earm_BBSHTF1_hit_zcell);
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.xcellg", &Earm_BBSHTF1_hit_xcellg, &b_Earm_BBSHTF1_hit_xcellg);
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.ycellg", &Earm_BBSHTF1_hit_ycellg, &b_Earm_BBSHTF1_hit_ycellg);
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.zcellg", &Earm_BBSHTF1_hit_zcellg, &b_Earm_BBSHTF1_hit_zcellg);
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.xhit", &Earm_BBSHTF1_hit_xhit, &b_Earm_BBSHTF1_hit_xhit);
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.yhit", &Earm_BBSHTF1_hit_yhit, &b_Earm_BBSHTF1_hit_yhit);
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.zhit", &Earm_BBSHTF1_hit_zhit, &b_Earm_BBSHTF1_hit_zhit);
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.sumedep", &Earm_BBSHTF1_hit_sumedep, &b_Earm_BBSHTF1_hit_sumedep);
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.tavg", &Earm_BBSHTF1_hit_tavg, &b_Earm_BBSHTF1_hit_tavg);
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.trms", &Earm_BBSHTF1_hit_trms, &b_Earm_BBSHTF1_hit_trms);
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.tmin", &Earm_BBSHTF1_hit_tmin, &b_Earm_BBSHTF1_hit_tmin);
       fChain->SetBranchAddress("Earm.BBSHTF1.hit.tmax", &Earm_BBSHTF1_hit_tmax, &b_Earm_BBSHTF1_hit_tmax);
     }
   }else{
     //if(fExpOption==3){
     fChain->SetBranchAddress("Earm.CDET.hit.nhits", &Earm_CDET_hit_nhits, &b_Earm_CDET_hit_nhits);
     fChain->SetBranchAddress("Earm.CDET.hit.PMT", &Earm_CDET_hit_PMT, &b_Earm_CDET_hit_PMT);
     fChain->SetBranchAddress("Earm.CDET.hit.row", &Earm_CDET_hit_row, &b_Earm_CDET_hit_row);
     fChain->SetBranchAddress("Earm.CDET.hit.col", &Earm_CDET_hit_col, &b_Earm_CDET_hit_col);
     fChain->SetBranchAddress("Earm.CDET.hit.plane", &Earm_CDET_hit_plane, &b_Earm_CDET_hit_plane);
     fChain->SetBranchAddress("Earm.CDET.hit.xcell", &Earm_CDET_hit_xcell, &b_Earm_CDET_hit_xcell);
     fChain->SetBranchAddress("Earm.CDET.hit.ycell", &Earm_CDET_hit_ycell, &b_Earm_CDET_hit_ycell);
     fChain->SetBranchAddress("Earm.CDET.hit.zcell", &Earm_CDET_hit_zcell, &b_Earm_CDET_hit_zcell);
     fChain->SetBranchAddress("Earm.CDET.hit.xgcell", &Earm_CDET_hit_xgcell, &b_Earm_CDET_hit_xgcell);
     fChain->SetBranchAddress("Earm.CDET.hit.ygcell", &Earm_CDET_hit_ygcell, &b_Earm_CDET_hit_ygcell);
     fChain->SetBranchAddress("Earm.CDET.hit.zgcell", &Earm_CDET_hit_zgcell, &b_Earm_CDET_hit_zgcell);
     fChain->SetBranchAddress("Earm.CDET.hit.NumPhotoelectrons", &Earm_CDET_hit_NumPhotoelectrons, &b_Earm_CDET_hit_NumPhotoelectrons);
     fChain->SetBranchAddress("Earm.CDET.hit.Time_avg", &Earm_CDET_hit_Time_avg, &b_Earm_CDET_hit_Time_avg);
     fChain->SetBranchAddress("Earm.CDET.hit.Time_rms", &Earm_CDET_hit_Time_rms, &b_Earm_CDET_hit_Time_rms);
     fChain->SetBranchAddress("Earm.CDET.hit.Time_min", &Earm_CDET_hit_Time_min, &b_Earm_CDET_hit_Time_min);
     fChain->SetBranchAddress("Earm.CDET.hit.Time_max", &Earm_CDET_hit_Time_max, &b_Earm_CDET_hit_Time_max);
   
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.nhits", &Earm_CDET_Scint_hit_nhits, &b_Earm_CDET_Scint_hit_nhits);
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.row", &Earm_CDET_Scint_hit_row, &b_Earm_CDET_Scint_hit_row);
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.col", &Earm_CDET_Scint_hit_col, &b_Earm_CDET_Scint_hit_col);
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.cell", &Earm_CDET_Scint_hit_cell, &b_Earm_CDET_Scint_hit_cell);
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.plane", &Earm_CDET_Scint_hit_plane, &b_Earm_CDET_Scint_hit_plane);
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.xcell", &Earm_CDET_Scint_hit_xcell, &b_Earm_CDET_Scint_hit_xcell);
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.ycell", &Earm_CDET_Scint_hit_ycell, &b_Earm_CDET_Scint_hit_ycell);
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.zcell", &Earm_CDET_Scint_hit_zcell, &b_Earm_CDET_Scint_hit_zcell);
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.xcellg", &Earm_CDET_Scint_hit_xcellg, &b_Earm_CDET_Scint_hit_xcellg);
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.ycellg", &Earm_CDET_Scint_hit_ycellg, &b_Earm_CDET_Scint_hit_ycellg);
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.zcellg", &Earm_CDET_Scint_hit_zcellg, &b_Earm_CDET_Scint_hit_zcellg);
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.xhit", &Earm_CDET_Scint_hit_xhit, &b_Earm_CDET_Scint_hit_xhit);
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.yhit", &Earm_CDET_Scint_hit_yhit, &b_Earm_CDET_Scint_hit_yhit);
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.zhit", &Earm_CDET_Scint_hit_zhit, &b_Earm_CDET_Scint_hit_zhit);
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.sumedep", &Earm_CDET_Scint_hit_sumedep, &b_Earm_CDET_Scint_hit_sumedep);
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.tavg", &Earm_CDET_Scint_hit_tavg, &b_Earm_CDET_Scint_hit_tavg);
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.trms", &Earm_CDET_Scint_hit_trms, &b_Earm_CDET_Scint_hit_trms);
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.tmin", &Earm_CDET_Scint_hit_tmin, &b_Earm_CDET_Scint_hit_tmin);
     fChain->SetBranchAddress("Earm.CDET_Scint.hit.tmax", &Earm_CDET_Scint_hit_tmax, &b_Earm_CDET_Scint_hit_tmax);
     
     if(fEcalBox){
       fChain->SetBranchAddress("Earm.ECAL_box.hit.nhits", &Earm_ECAL_box_hit_nhits, &b_Earm_ECAL_box_hit_nhits);
       fChain->SetBranchAddress("Earm.ECAL_box.hit.row", &Earm_ECAL_box_hit_row, &b_Earm_ECAL_box_hit_row);
       fChain->SetBranchAddress("Earm.ECAL_box.hit.col", &Earm_ECAL_box_hit_col, &b_Earm_ECAL_box_hit_col);
       fChain->SetBranchAddress("Earm.ECAL_box.hit.cell", &Earm_ECAL_box_hit_cell, &b_Earm_ECAL_box_hit_cell);
       fChain->SetBranchAddress("Earm.ECAL_box.hit.plane", &Earm_ECAL_box_hit_plane, &b_Earm_ECAL_box_hit_plane);
       fChain->SetBranchAddress("Earm.ECAL_box.hit.xcell", &Earm_ECAL_box_hit_xcell, &b_Earm_ECAL_box_hit_xcell);
       fChain->SetBranchAddress("Earm.ECAL_box.hit.ycell", &Earm_ECAL_box_hit_ycell, &b_Earm_ECAL_box_hit_ycell);
       fChain->SetBranchAddress("Earm.ECAL_box.hit.zcell", &Earm_ECAL_box_hit_zcell, &b_Earm_ECAL_box_hit_zcell);
       fChain->SetBranchAddress("Earm.ECAL_box.hit.xcellg", &Earm_ECAL_box_hit_xcellg, &b_Earm_ECAL_box_hit_xcellg);
       fChain->SetBranchAddress("Earm.ECAL_box.hit.ycellg", &Earm_ECAL_box_hit_ycellg, &b_Earm_ECAL_box_hit_ycellg);
       fChain->SetBranchAddress("Earm.ECAL_box.hit.zcellg", &Earm_ECAL_box_hit_zcellg, &b_Earm_ECAL_box_hit_zcellg);
       fChain->SetBranchAddress("Earm.ECAL_box.hit.xhit", &Earm_ECAL_box_hit_xhit, &b_Earm_ECAL_box_hit_xhit);
       fChain->SetBranchAddress("Earm.ECAL_box.hit.yhit", &Earm_ECAL_box_hit_yhit, &b_Earm_ECAL_box_hit_yhit);
       fChain->SetBranchAddress("Earm.ECAL_box.hit.zhit", &Earm_ECAL_box_hit_zhit, &b_Earm_ECAL_box_hit_zhit);
       fChain->SetBranchAddress("Earm.ECAL_box.hit.sumedep", &Earm_ECAL_box_hit_sumedep, &b_Earm_ECAL_box_hit_sumedep);
       fChain->SetBranchAddress("Earm.ECAL_box.hit.tavg", &Earm_ECAL_box_hit_tavg, &b_Earm_ECAL_box_hit_tavg);
       fChain->SetBranchAddress("Earm.ECAL_box.hit.trms", &Earm_ECAL_box_hit_trms, &b_Earm_ECAL_box_hit_trms);
       fChain->SetBranchAddress("Earm.ECAL_box.hit.tmin", &Earm_ECAL_box_hit_tmin, &b_Earm_ECAL_box_hit_tmin);
       fChain->SetBranchAddress("Earm.ECAL_box.hit.tmax", &Earm_ECAL_box_hit_tmax, &b_Earm_ECAL_box_hit_tmax);
     }else{
       fChain->SetBranchAddress("Earm.ECAL.hit.nhits", &Earm_ECAL_hit_nhits, &b_Earm_ECAL_hit_nhits);
       fChain->SetBranchAddress("Earm.ECAL.hit.PMT", &Earm_ECAL_hit_PMT, &b_Earm_ECAL_hit_PMT);
       fChain->SetBranchAddress("Earm.ECAL.hit.row", &Earm_ECAL_hit_row, &b_Earm_ECAL_hit_row);
       fChain->SetBranchAddress("Earm.ECAL.hit.col", &Earm_ECAL_hit_col, &b_Earm_ECAL_hit_col);
       fChain->SetBranchAddress("Earm.ECAL.hit.plane", &Earm_ECAL_hit_plane, &b_Earm_ECAL_hit_plane);
       fChain->SetBranchAddress("Earm.ECAL.hit.xcell", &Earm_ECAL_hit_xcell, &b_Earm_ECAL_hit_xcell);
       fChain->SetBranchAddress("Earm.ECAL.hit.ycell", &Earm_ECAL_hit_ycell, &b_Earm_ECAL_hit_ycell);
       fChain->SetBranchAddress("Earm.ECAL.hit.zcell", &Earm_ECAL_hit_zcell, &b_Earm_ECAL_hit_zcell);
       fChain->SetBranchAddress("Earm.ECAL.hit.xgcell", &Earm_ECAL_hit_xgcell, &b_Earm_ECAL_hit_xgcell);
       fChain->SetBranchAddress("Earm.ECAL.hit.ygcell", &Earm_ECAL_hit_ygcell, &b_Earm_ECAL_hit_ygcell);
       fChain->SetBranchAddress("Earm.ECAL.hit.zgcell", &Earm_ECAL_hit_zgcell, &b_Earm_ECAL_hit_zgcell);
       fChain->SetBranchAddress("Earm.ECAL.hit.NumPhotoelectrons", &Earm_ECAL_hit_NumPhotoelectrons, &b_Earm_ECAL_hit_NumPhotoelectrons);
       fChain->SetBranchAddress("Earm.ECAL.hit.Time_avg", &Earm_ECAL_hit_Time_avg, &b_Earm_ECAL_hit_Time_avg);
       fChain->SetBranchAddress("Earm.ECAL.hit.Time_rms", &Earm_ECAL_hit_Time_rms, &b_Earm_ECAL_hit_Time_rms);
       fChain->SetBranchAddress("Earm.ECAL.hit.Time_min", &Earm_ECAL_hit_Time_min, &b_Earm_ECAL_hit_Time_min);
       fChain->SetBranchAddress("Earm.ECAL.hit.Time_max", &Earm_ECAL_hit_Time_max, &b_Earm_ECAL_hit_Time_max);
     }
     
     fChain->SetBranchAddress("Earm.ECalTF1.hit.nhits", &Earm_ECalTF1_hit_nhits, &b_Earm_ECalTF1_hit_nhits);
     fChain->SetBranchAddress("Earm.ECalTF1.hit.row", &Earm_ECalTF1_hit_row, &b_Earm_ECalTF1_hit_row);
     fChain->SetBranchAddress("Earm.ECalTF1.hit.col", &Earm_ECalTF1_hit_col, &b_Earm_ECalTF1_hit_col);
     fChain->SetBranchAddress("Earm.ECalTF1.hit.cell", &Earm_ECalTF1_hit_cell, &b_Earm_ECalTF1_hit_cell);
     fChain->SetBranchAddress("Earm.ECalTF1.hit.plane", &Earm_ECalTF1_hit_plane, &b_Earm_ECalTF1_hit_plane);
     fChain->SetBranchAddress("Earm.ECalTF1.hit.xcell", &Earm_ECalTF1_hit_xcell, &b_Earm_ECalTF1_hit_xcell);
     fChain->SetBranchAddress("Earm.ECalTF1.hit.ycell", &Earm_ECalTF1_hit_ycell, &b_Earm_ECalTF1_hit_ycell);
     fChain->SetBranchAddress("Earm.ECalTF1.hit.zcell", &Earm_ECalTF1_hit_zcell, &b_Earm_ECalTF1_hit_zcell);
     fChain->SetBranchAddress("Earm.ECalTF1.hit.xcellg", &Earm_ECalTF1_hit_xcellg, &b_Earm_ECalTF1_hit_xcellg);
     fChain->SetBranchAddress("Earm.ECalTF1.hit.ycellg", &Earm_ECalTF1_hit_ycellg, &b_Earm_ECalTF1_hit_ycellg);
     fChain->SetBranchAddress("Earm.ECalTF1.hit.zcellg", &Earm_ECalTF1_hit_zcellg, &b_Earm_ECalTF1_hit_zcellg);
     fChain->SetBranchAddress("Earm.ECalTF1.hit.xhit", &Earm_ECalTF1_hit_xhit, &b_Earm_ECalTF1_hit_xhit);
     fChain->SetBranchAddress("Earm.ECalTF1.hit.yhit", &Earm_ECalTF1_hit_yhit, &b_Earm_ECalTF1_hit_yhit);
     fChain->SetBranchAddress("Earm.ECalTF1.hit.zhit", &Earm_ECalTF1_hit_zhit, &b_Earm_ECalTF1_hit_zhit);
     fChain->SetBranchAddress("Earm.ECalTF1.hit.sumedep", &Earm_ECalTF1_hit_sumedep, &b_Earm_ECalTF1_hit_sumedep);
     fChain->SetBranchAddress("Earm.ECalTF1.hit.tavg", &Earm_ECalTF1_hit_tavg, &b_Earm_ECalTF1_hit_tavg);
     fChain->SetBranchAddress("Earm.ECalTF1.hit.trms", &Earm_ECalTF1_hit_trms, &b_Earm_ECalTF1_hit_trms);
     fChain->SetBranchAddress("Earm.ECalTF1.hit.tmin", &Earm_ECalTF1_hit_tmin, &b_Earm_ECalTF1_hit_tmin);
     fChain->SetBranchAddress("Earm.ECalTF1.hit.tmax", &Earm_ECalTF1_hit_tmax, &b_Earm_ECalTF1_hit_tmax);
   
     fChain->SetBranchAddress("Harm.FPP1.hit.nhits", &Harm_FPP1_hit_nhits, &b_Harm_FPP1_hit_nhits);
     fChain->SetBranchAddress("Harm.FPP1.hit.plane", &Harm_FPP1_hit_plane, &b_Harm_FPP1_hit_plane);
     fChain->SetBranchAddress("Harm.FPP1.hit.strip", &Harm_FPP1_hit_strip, &b_Harm_FPP1_hit_strip);
     fChain->SetBranchAddress("Harm.FPP1.hit.x", &Harm_FPP1_hit_x, &b_Harm_FPP1_hit_x);
     fChain->SetBranchAddress("Harm.FPP1.hit.y", &Harm_FPP1_hit_y, &b_Harm_FPP1_hit_y);
     fChain->SetBranchAddress("Harm.FPP1.hit.z", &Harm_FPP1_hit_z, &b_Harm_FPP1_hit_z);
     fChain->SetBranchAddress("Harm.FPP1.hit.polx", &Harm_FPP1_hit_polx, &b_Harm_FPP1_hit_polx);
     fChain->SetBranchAddress("Harm.FPP1.hit.poly", &Harm_FPP1_hit_poly, &b_Harm_FPP1_hit_poly);
     fChain->SetBranchAddress("Harm.FPP1.hit.polz", &Harm_FPP1_hit_polz, &b_Harm_FPP1_hit_polz);
     fChain->SetBranchAddress("Harm.FPP1.hit.t", &Harm_FPP1_hit_t, &b_Harm_FPP1_hit_t);
     fChain->SetBranchAddress("Harm.FPP1.hit.trms", &Harm_FPP1_hit_trms, &b_Harm_FPP1_hit_trms);
     fChain->SetBranchAddress("Harm.FPP1.hit.tmin", &Harm_FPP1_hit_tmin, &b_Harm_FPP1_hit_tmin);
     fChain->SetBranchAddress("Harm.FPP1.hit.tmax", &Harm_FPP1_hit_tmax, &b_Harm_FPP1_hit_tmax);
     fChain->SetBranchAddress("Harm.FPP1.hit.tmax", &Harm_FPP1_hit_tmax, &b_Harm_FPP1_hit_tmax);
     fChain->SetBranchAddress("Harm.FPP1.hit.tx", &Harm_FPP1_hit_tx, &b_Harm_FPP1_hit_tx);
     fChain->SetBranchAddress("Harm.FPP1.hit.ty", &Harm_FPP1_hit_ty, &b_Harm_FPP1_hit_ty);
     fChain->SetBranchAddress("Harm.FPP1.hit.txp", &Harm_FPP1_hit_txp, &b_Harm_FPP1_hit_txp);
     fChain->SetBranchAddress("Harm.FPP1.hit.typ", &Harm_FPP1_hit_typ, &b_Harm_FPP1_hit_typ);
     fChain->SetBranchAddress("Harm.FPP1.hit.xg", &Harm_FPP1_hit_xg, &b_Harm_FPP1_hit_xg);
     fChain->SetBranchAddress("Harm.FPP1.hit.yg", &Harm_FPP1_hit_yg, &b_Harm_FPP1_hit_yg);
     fChain->SetBranchAddress("Harm.FPP1.hit.zg", &Harm_FPP1_hit_zg, &b_Harm_FPP1_hit_zg);
     fChain->SetBranchAddress("Harm.FPP1.hit.trid", &Harm_FPP1_hit_trid, &b_Harm_FPP1_hit_trid);
     fChain->SetBranchAddress("Harm.FPP1.hit.mid", &Harm_FPP1_hit_mid, &b_Harm_FPP1_hit_mid);
     fChain->SetBranchAddress("Harm.FPP1.hit.pid", &Harm_FPP1_hit_pid, &b_Harm_FPP1_hit_pid);
     fChain->SetBranchAddress("Harm.FPP1.hit.vx", &Harm_FPP1_hit_vx, &b_Harm_FPP1_hit_vx);
     fChain->SetBranchAddress("Harm.FPP1.hit.vy", &Harm_FPP1_hit_vy, &b_Harm_FPP1_hit_vy);
     fChain->SetBranchAddress("Harm.FPP1.hit.vz", &Harm_FPP1_hit_vz, &b_Harm_FPP1_hit_vz);
     fChain->SetBranchAddress("Harm.FPP1.hit.p", &Harm_FPP1_hit_p, &b_Harm_FPP1_hit_p);
     fChain->SetBranchAddress("Harm.FPP1.hit.edep", &Harm_FPP1_hit_edep, &b_Harm_FPP1_hit_edep);
     fChain->SetBranchAddress("Harm.FPP1.hit.beta", &Harm_FPP1_hit_beta, &b_Harm_FPP1_hit_beta);
   
     fChain->SetBranchAddress("Harm.FPP1.Track.ntracks", &Harm_FPP1_Track_ntracks, &b_Harm_FPP1_Track_ntracks);
     fChain->SetBranchAddress("Harm.FPP1.Track.TID", &Harm_FPP1_Track_TID, &b_Harm_FPP1_Track_TID);
     fChain->SetBranchAddress("Harm.FPP1.Track.PID", &Harm_FPP1_Track_PID, &b_Harm_FPP1_Track_PID);
     fChain->SetBranchAddress("Harm.FPP1.Track.MID", &Harm_FPP1_Track_MID, &b_Harm_FPP1_Track_MID);
     fChain->SetBranchAddress("Harm.FPP1.Track.NumHits", &Harm_FPP1_Track_NumHits, &b_Harm_FPP1_Track_NumHits);
     fChain->SetBranchAddress("Harm.FPP1.Track.NumPlanes", &Harm_FPP1_Track_NumPlanes, &b_Harm_FPP1_Track_NumPlanes);
     fChain->SetBranchAddress("Harm.FPP1.Track.NDF", &Harm_FPP1_Track_NDF, &b_Harm_FPP1_Track_NDF);
     fChain->SetBranchAddress("Harm.FPP1.Track.Chi2fit", &Harm_FPP1_Track_Chi2fit, &b_Harm_FPP1_Track_Chi2fit);
     fChain->SetBranchAddress("Harm.FPP1.Track.Chi2true", &Harm_FPP1_Track_Chi2true, &b_Harm_FPP1_Track_Chi2true);
     fChain->SetBranchAddress("Harm.FPP1.Track.X", &Harm_FPP1_Track_X, &b_Harm_FPP1_Track_X);
     fChain->SetBranchAddress("Harm.FPP1.Track.Y", &Harm_FPP1_Track_Y, &b_Harm_FPP1_Track_Y);
     fChain->SetBranchAddress("Harm.FPP1.Track.Xp", &Harm_FPP1_Track_Xp, &b_Harm_FPP1_Track_Xp);
     fChain->SetBranchAddress("Harm.FPP1.Track.Yp", &Harm_FPP1_Track_Yp, &b_Harm_FPP1_Track_Yp);
     fChain->SetBranchAddress("Harm.FPP1.Track.T", &Harm_FPP1_Track_T, &b_Harm_FPP1_Track_T);
     fChain->SetBranchAddress("Harm.FPP1.Track.P", &Harm_FPP1_Track_P, &b_Harm_FPP1_Track_P);
     fChain->SetBranchAddress("Harm.FPP1.Track.Sx", &Harm_FPP1_Track_Sx, &b_Harm_FPP1_Track_Sx);
     fChain->SetBranchAddress("Harm.FPP1.Track.Sy", &Harm_FPP1_Track_Sy, &b_Harm_FPP1_Track_Sy);
     fChain->SetBranchAddress("Harm.FPP1.Track.Sz", &Harm_FPP1_Track_Sz, &b_Harm_FPP1_Track_Sz);
     fChain->SetBranchAddress("Harm.FPP1.Track.Xfit", &Harm_FPP1_Track_Xfit, &b_Harm_FPP1_Track_Xfit);
     fChain->SetBranchAddress("Harm.FPP1.Track.Yfit", &Harm_FPP1_Track_Yfit, &b_Harm_FPP1_Track_Yfit);
     fChain->SetBranchAddress("Harm.FPP1.Track.Xpfit", &Harm_FPP1_Track_Xpfit, &b_Harm_FPP1_Track_Xpfit);
     fChain->SetBranchAddress("Harm.FPP1.Track.Ypfit", &Harm_FPP1_Track_Ypfit, &b_Harm_FPP1_Track_Ypfit);
   
     fChain->SetBranchAddress("Harm.FPP2.hit.nhits", &Harm_FPP2_hit_nhits, &b_Harm_FPP2_hit_nhits);
     fChain->SetBranchAddress("Harm.FPP2.hit.plane", &Harm_FPP2_hit_plane, &b_Harm_FPP2_hit_plane);
     fChain->SetBranchAddress("Harm.FPP2.hit.strip", &Harm_FPP2_hit_strip, &b_Harm_FPP2_hit_strip);
     fChain->SetBranchAddress("Harm.FPP2.hit.x", &Harm_FPP2_hit_x, &b_Harm_FPP2_hit_x);
     fChain->SetBranchAddress("Harm.FPP2.hit.y", &Harm_FPP2_hit_y, &b_Harm_FPP2_hit_y);
     fChain->SetBranchAddress("Harm.FPP2.hit.z", &Harm_FPP2_hit_z, &b_Harm_FPP2_hit_z);
     fChain->SetBranchAddress("Harm.FPP2.hit.polx", &Harm_FPP2_hit_polx, &b_Harm_FPP2_hit_polx);
     fChain->SetBranchAddress("Harm.FPP2.hit.poly", &Harm_FPP2_hit_poly, &b_Harm_FPP2_hit_poly);
     fChain->SetBranchAddress("Harm.FPP2.hit.polz", &Harm_FPP2_hit_polz, &b_Harm_FPP2_hit_polz);
     fChain->SetBranchAddress("Harm.FPP2.hit.t", &Harm_FPP2_hit_t, &b_Harm_FPP2_hit_t);
     fChain->SetBranchAddress("Harm.FPP2.hit.trms", &Harm_FPP2_hit_trms, &b_Harm_FPP2_hit_trms);
     fChain->SetBranchAddress("Harm.FPP2.hit.tmin", &Harm_FPP2_hit_tmin, &b_Harm_FPP2_hit_tmin);
     fChain->SetBranchAddress("Harm.FPP2.hit.tmax", &Harm_FPP2_hit_tmax, &b_Harm_FPP2_hit_tmax);
     fChain->SetBranchAddress("Harm.FPP2.hit.tx", &Harm_FPP2_hit_tx, &b_Harm_FPP2_hit_tx);
     fChain->SetBranchAddress("Harm.FPP2.hit.ty", &Harm_FPP2_hit_ty, &b_Harm_FPP2_hit_ty);
     fChain->SetBranchAddress("Harm.FPP2.hit.txp", &Harm_FPP2_hit_txp, &b_Harm_FPP2_hit_txp);
     fChain->SetBranchAddress("Harm.FPP2.hit.typ", &Harm_FPP2_hit_typ, &b_Harm_FPP2_hit_typ);
     fChain->SetBranchAddress("Harm.FPP2.hit.trid", &Harm_FPP2_hit_trid, &b_Harm_FPP2_hit_trid);
     fChain->SetBranchAddress("Harm.FPP2.hit.xg", &Harm_FPP2_hit_xg, &b_Harm_FPP2_hit_xg);
     fChain->SetBranchAddress("Harm.FPP2.hit.yg", &Harm_FPP2_hit_yg, &b_Harm_FPP2_hit_yg);
     fChain->SetBranchAddress("Harm.FPP2.hit.zg", &Harm_FPP2_hit_zg, &b_Harm_FPP2_hit_zg);
     fChain->SetBranchAddress("Harm.FPP2.hit.mid", &Harm_FPP2_hit_mid, &b_Harm_FPP2_hit_mid);
     fChain->SetBranchAddress("Harm.FPP2.hit.pid", &Harm_FPP2_hit_pid, &b_Harm_FPP2_hit_pid);
     fChain->SetBranchAddress("Harm.FPP2.hit.vx", &Harm_FPP2_hit_vx, &b_Harm_FPP2_hit_vx);
     fChain->SetBranchAddress("Harm.FPP2.hit.vy", &Harm_FPP2_hit_vy, &b_Harm_FPP2_hit_vy);
     fChain->SetBranchAddress("Harm.FPP2.hit.vz", &Harm_FPP2_hit_vz, &b_Harm_FPP2_hit_vz);
     fChain->SetBranchAddress("Harm.FPP2.hit.p", &Harm_FPP2_hit_p, &b_Harm_FPP2_hit_p);
     fChain->SetBranchAddress("Harm.FPP2.hit.edep", &Harm_FPP2_hit_edep, &b_Harm_FPP2_hit_edep);
     fChain->SetBranchAddress("Harm.FPP2.hit.beta", &Harm_FPP2_hit_beta, &b_Harm_FPP2_hit_beta);
   
     fChain->SetBranchAddress("Harm.FPP2.Track.ntracks", &Harm_FPP2_Track_ntracks, &b_Harm_FPP2_Track_ntracks);
     fChain->SetBranchAddress("Harm.FPP2.Track.TID", &Harm_FPP2_Track_TID, &b_Harm_FPP2_Track_TID);
     fChain->SetBranchAddress("Harm.FPP2.Track.PID", &Harm_FPP2_Track_PID, &b_Harm_FPP2_Track_PID);
     fChain->SetBranchAddress("Harm.FPP2.Track.MID", &Harm_FPP2_Track_MID, &b_Harm_FPP2_Track_MID);
     fChain->SetBranchAddress("Harm.FPP2.Track.NumHits", &Harm_FPP2_Track_NumHits, &b_Harm_FPP2_Track_NumHits);
     fChain->SetBranchAddress("Harm.FPP2.Track.NumPlanes", &Harm_FPP2_Track_NumPlanes, &b_Harm_FPP2_Track_NumPlanes);
     fChain->SetBranchAddress("Harm.FPP2.Track.NDF", &Harm_FPP2_Track_NDF, &b_Harm_FPP2_Track_NDF);
     fChain->SetBranchAddress("Harm.FPP2.Track.Chi2fit", &Harm_FPP2_Track_Chi2fit, &b_Harm_FPP2_Track_Chi2fit);
     fChain->SetBranchAddress("Harm.FPP2.Track.Chi2true", &Harm_FPP2_Track_Chi2true, &b_Harm_FPP2_Track_Chi2true);
     fChain->SetBranchAddress("Harm.FPP2.Track.X", &Harm_FPP2_Track_X, &b_Harm_FPP2_Track_X);
     fChain->SetBranchAddress("Harm.FPP2.Track.Y", &Harm_FPP2_Track_Y, &b_Harm_FPP2_Track_Y);
     fChain->SetBranchAddress("Harm.FPP2.Track.Xp", &Harm_FPP2_Track_Xp, &b_Harm_FPP2_Track_Xp);
     fChain->SetBranchAddress("Harm.FPP2.Track.Yp", &Harm_FPP2_Track_Yp, &b_Harm_FPP2_Track_Yp);
     fChain->SetBranchAddress("Harm.FPP2.Track.T", &Harm_FPP2_Track_T, &b_Harm_FPP2_Track_T);
     fChain->SetBranchAddress("Harm.FPP2.Track.P", &Harm_FPP2_Track_P, &b_Harm_FPP2_Track_P);
     fChain->SetBranchAddress("Harm.FPP2.Track.Sx", &Harm_FPP2_Track_Sx, &b_Harm_FPP2_Track_Sx);
     fChain->SetBranchAddress("Harm.FPP2.Track.Sy", &Harm_FPP2_Track_Sy, &b_Harm_FPP2_Track_Sy);
     fChain->SetBranchAddress("Harm.FPP2.Track.Sz", &Harm_FPP2_Track_Sz, &b_Harm_FPP2_Track_Sz);
     fChain->SetBranchAddress("Harm.FPP2.Track.Xfit", &Harm_FPP2_Track_Xfit, &b_Harm_FPP2_Track_Xfit);
     fChain->SetBranchAddress("Harm.FPP2.Track.Yfit", &Harm_FPP2_Track_Yfit, &b_Harm_FPP2_Track_Yfit);
     fChain->SetBranchAddress("Harm.FPP2.Track.Xpfit", &Harm_FPP2_Track_Xpfit, &b_Harm_FPP2_Track_Xpfit);
     fChain->SetBranchAddress("Harm.FPP2.Track.Ypfit", &Harm_FPP2_Track_Ypfit, &b_Harm_FPP2_Track_Ypfit);
     
     fChain->SetBranchAddress("Harm.FT.hit.nhits", &Harm_FT_hit_nhits, &b_Harm_FT_hit_nhits);
     fChain->SetBranchAddress("Harm.FT.hit.plane", &Harm_FT_hit_plane, &b_Harm_FT_hit_plane);
     fChain->SetBranchAddress("Harm.FT.hit.strip", &Harm_FT_hit_strip, &b_Harm_FT_hit_strip);
     fChain->SetBranchAddress("Harm.FT.hit.x", &Harm_FT_hit_x, &b_Harm_FT_hit_x);
     fChain->SetBranchAddress("Harm.FT.hit.y", &Harm_FT_hit_y, &b_Harm_FT_hit_y);
     fChain->SetBranchAddress("Harm.FT.hit.z", &Harm_FT_hit_z, &b_Harm_FT_hit_z);
     fChain->SetBranchAddress("Harm.FT.hit.polx", &Harm_FT_hit_polx, &b_Harm_FT_hit_polx);
     fChain->SetBranchAddress("Harm.FT.hit.poly", &Harm_FT_hit_poly, &b_Harm_FT_hit_poly);
     fChain->SetBranchAddress("Harm.FT.hit.polz", &Harm_FT_hit_polz, &b_Harm_FT_hit_polz);
     fChain->SetBranchAddress("Harm.FT.hit.t", &Harm_FT_hit_t, &b_Harm_FT_hit_t);
     fChain->SetBranchAddress("Harm.FT.hit.trms", &Harm_FT_hit_trms, &b_Harm_FT_hit_trms);
     fChain->SetBranchAddress("Harm.FT.hit.tmin", &Harm_FT_hit_tmin, &b_Harm_FT_hit_tmin);
     fChain->SetBranchAddress("Harm.FT.hit.tmax", &Harm_FT_hit_tmax, &b_Harm_FT_hit_tmax);
     fChain->SetBranchAddress("Harm.FT.hit.tx", &Harm_FT_hit_tx, &b_Harm_FT_hit_tx);
     fChain->SetBranchAddress("Harm.FT.hit.ty", &Harm_FT_hit_ty, &b_Harm_FT_hit_ty);
     fChain->SetBranchAddress("Harm.FT.hit.txp", &Harm_FT_hit_txp, &b_Harm_FT_hit_txp);
     fChain->SetBranchAddress("Harm.FT.hit.typ", &Harm_FT_hit_typ, &b_Harm_FT_hit_typ);
     fChain->SetBranchAddress("Harm.FT.hit.xg", &Harm_FT_hit_xg, &b_Harm_FT_hit_xg);
     fChain->SetBranchAddress("Harm.FT.hit.yg", &Harm_FT_hit_yg, &b_Harm_FT_hit_yg);
     fChain->SetBranchAddress("Harm.FT.hit.zg", &Harm_FT_hit_zg, &b_Harm_FT_hit_zg);
     fChain->SetBranchAddress("Harm.FT.hit.trid", &Harm_FT_hit_trid, &b_Harm_FT_hit_trid);
     fChain->SetBranchAddress("Harm.FT.hit.mid", &Harm_FT_hit_mid, &b_Harm_FT_hit_mid);
     fChain->SetBranchAddress("Harm.FT.hit.pid", &Harm_FT_hit_pid, &b_Harm_FT_hit_pid);
     fChain->SetBranchAddress("Harm.FT.hit.vx", &Harm_FT_hit_vx, &b_Harm_FT_hit_vx);
     fChain->SetBranchAddress("Harm.FT.hit.vy", &Harm_FT_hit_vy, &b_Harm_FT_hit_vy);
     fChain->SetBranchAddress("Harm.FT.hit.vz", &Harm_FT_hit_vz, &b_Harm_FT_hit_vz);
     fChain->SetBranchAddress("Harm.FT.hit.p", &Harm_FT_hit_p, &b_Harm_FT_hit_p);
     fChain->SetBranchAddress("Harm.FT.hit.edep", &Harm_FT_hit_edep, &b_Harm_FT_hit_edep);
     fChain->SetBranchAddress("Harm.FT.hit.beta", &Harm_FT_hit_beta, &b_Harm_FT_hit_beta);
   
     fChain->SetBranchAddress("Harm.FT.Track.ntracks", &Harm_FT_Track_ntracks, &b_Harm_FT_Track_ntracks);
     fChain->SetBranchAddress("Harm.FT.Track.TID", &Harm_FT_Track_TID, &b_Harm_FT_Track_TID);
     fChain->SetBranchAddress("Harm.FT.Track.PID", &Harm_FT_Track_PID, &b_Harm_FT_Track_PID);
     fChain->SetBranchAddress("Harm.FT.Track.MID", &Harm_FT_Track_MID, &b_Harm_FT_Track_MID);
     fChain->SetBranchAddress("Harm.FT.Track.NumHits", &Harm_FT_Track_NumHits, &b_Harm_FT_Track_NumHits);
     fChain->SetBranchAddress("Harm.FT.Track.NumPlanes", &Harm_FT_Track_NumPlanes, &b_Harm_FT_Track_NumPlanes);
     fChain->SetBranchAddress("Harm.FT.Track.NDF", &Harm_FT_Track_NDF, &b_Harm_FT_Track_NDF);
     fChain->SetBranchAddress("Harm.FT.Track.Chi2fit", &Harm_FT_Track_Chi2fit, &b_Harm_FT_Track_Chi2fit);
     fChain->SetBranchAddress("Harm.FT.Track.Chi2true", &Harm_FT_Track_Chi2true, &b_Harm_FT_Track_Chi2true);
     fChain->SetBranchAddress("Harm.FT.Track.X", &Harm_FT_Track_X, &b_Harm_FT_Track_X);
     fChain->SetBranchAddress("Harm.FT.Track.Y", &Harm_FT_Track_Y, &b_Harm_FT_Track_Y);
     fChain->SetBranchAddress("Harm.FT.Track.Xp", &Harm_FT_Track_Xp, &b_Harm_FT_Track_Xp);
     fChain->SetBranchAddress("Harm.FT.Track.Yp", &Harm_FT_Track_Yp, &b_Harm_FT_Track_Yp);
     fChain->SetBranchAddress("Harm.FT.Track.T", &Harm_FT_Track_T, &b_Harm_FT_Track_T);
     fChain->SetBranchAddress("Harm.FT.Track.P", &Harm_FT_Track_P, &b_Harm_FT_Track_P);
     fChain->SetBranchAddress("Harm.FT.Track.Sx", &Harm_FT_Track_Sx, &b_Harm_FT_Track_Sx);
     fChain->SetBranchAddress("Harm.FT.Track.Sy", &Harm_FT_Track_Sy, &b_Harm_FT_Track_Sy);
     fChain->SetBranchAddress("Harm.FT.Track.Sz", &Harm_FT_Track_Sz, &b_Harm_FT_Track_Sz);
     fChain->SetBranchAddress("Harm.FT.Track.Xfit", &Harm_FT_Track_Xfit, &b_Harm_FT_Track_Xfit);
     fChain->SetBranchAddress("Harm.FT.Track.Yfit", &Harm_FT_Track_Yfit, &b_Harm_FT_Track_Yfit);
     fChain->SetBranchAddress("Harm.FT.Track.Xpfit", &Harm_FT_Track_Xpfit, &b_Harm_FT_Track_Xpfit);
     fChain->SetBranchAddress("Harm.FT.Track.Ypfit", &Harm_FT_Track_Ypfit, &b_Harm_FT_Track_Ypfit);
   }
   
   if(fExpOption==1){
     fChain->SetBranchAddress("Harm.CDET.hit.nhits", &Harm_CDET_hit_nhits, &b_Harm_CDET_hit_nhits);
     fChain->SetBranchAddress("Harm.CDET.hit.PMT", &Harm_CDET_hit_PMT, &b_Harm_CDET_hit_PMT);
     fChain->SetBranchAddress("Harm.CDET.hit.row", &Harm_CDET_hit_row, &b_Harm_CDET_hit_row);
     fChain->SetBranchAddress("Harm.CDET.hit.col", &Harm_CDET_hit_col, &b_Harm_CDET_hit_col);
     fChain->SetBranchAddress("Harm.CDET.hit.plane", &Harm_CDET_hit_plane, &b_Harm_CDET_hit_plane);
     fChain->SetBranchAddress("Harm.CDET.hit.xcell", &Harm_CDET_hit_xcell, &b_Harm_CDET_hit_xcell);
     fChain->SetBranchAddress("Harm.CDET.hit.ycell", &Harm_CDET_hit_ycell, &b_Harm_CDET_hit_ycell);
     fChain->SetBranchAddress("Harm.CDET.hit.zcell", &Harm_CDET_hit_zcell, &b_Harm_CDET_hit_zcell);
     fChain->SetBranchAddress("Harm.CDET.hit.xgcell", &Harm_CDET_hit_xgcell, &b_Harm_CDET_hit_xgcell);
     fChain->SetBranchAddress("Harm.CDET.hit.ygcell", &Harm_CDET_hit_ygcell, &b_Harm_CDET_hit_ygcell);
     fChain->SetBranchAddress("Harm.CDET.hit.zgcell", &Harm_CDET_hit_zgcell, &b_Harm_CDET_hit_zgcell);
     fChain->SetBranchAddress("Harm.CDET.hit.NumPhotoelectrons", &Harm_CDET_hit_NumPhotoelectrons, &b_Harm_CDET_hit_NumPhotoelectrons);
     fChain->SetBranchAddress("Harm.CDET.hit.Time_avg", &Harm_CDET_hit_Time_avg, &b_Harm_CDET_hit_Time_avg);
     fChain->SetBranchAddress("Harm.CDET.hit.Time_rms", &Harm_CDET_hit_Time_rms, &b_Harm_CDET_hit_Time_rms);
     fChain->SetBranchAddress("Harm.CDET.hit.Time_min", &Harm_CDET_hit_Time_min, &b_Harm_CDET_hit_Time_min);
     fChain->SetBranchAddress("Harm.CDET.hit.Time_max", &Harm_CDET_hit_Time_max, &b_Harm_CDET_hit_Time_max);
     
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.nhits", &Harm_CDET_Scint_hit_nhits, &b_Harm_CDET_Scint_hit_nhits);
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.row", &Harm_CDET_Scint_hit_row, &b_Harm_CDET_Scint_hit_row);
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.col", &Harm_CDET_Scint_hit_col, &b_Harm_CDET_Scint_hit_col);
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.cell", &Harm_CDET_Scint_hit_cell, &b_Harm_CDET_Scint_hit_cell);
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.plane", &Harm_CDET_Scint_hit_plane, &b_Harm_CDET_Scint_hit_plane);
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.xcell", &Harm_CDET_Scint_hit_xcell, &b_Harm_CDET_Scint_hit_xcell);
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.ycell", &Harm_CDET_Scint_hit_ycell, &b_Harm_CDET_Scint_hit_ycell);
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.zcell", &Harm_CDET_Scint_hit_zcell, &b_Harm_CDET_Scint_hit_zcell);
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.xcellg", &Harm_CDET_Scint_hit_xcellg, &b_Harm_CDET_Scint_hit_xcellg);
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.ycellg", &Harm_CDET_Scint_hit_ycellg, &b_Harm_CDET_Scint_hit_ycellg);
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.zcellg", &Harm_CDET_Scint_hit_zcellg, &b_Harm_CDET_Scint_hit_zcellg);
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.xhit", &Harm_CDET_Scint_hit_xhit, &b_Harm_CDET_Scint_hit_xhit);
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.yhit", &Harm_CDET_Scint_hit_yhit, &b_Harm_CDET_Scint_hit_yhit);
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.zhit", &Harm_CDET_Scint_hit_zhit, &b_Harm_CDET_Scint_hit_zhit);
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.sumedep", &Harm_CDET_Scint_hit_sumedep, &b_Harm_CDET_Scint_hit_sumedep);
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.tavg", &Harm_CDET_Scint_hit_tavg, &b_Harm_CDET_Scint_hit_tavg);
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.trms", &Harm_CDET_Scint_hit_trms, &b_Harm_CDET_Scint_hit_trms);
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.tmin", &Harm_CDET_Scint_hit_tmin, &b_Harm_CDET_Scint_hit_tmin);
     fChain->SetBranchAddress("Harm.CDET_Scint.hit.tmax", &Harm_CDET_Scint_hit_tmax, &b_Harm_CDET_Scint_hit_tmax);
   }
     
   if(fExpOption<5){
     // Example of simplified HCAL branch setup
     if(fHcalBox){
       SetupDetBranch(hcalbox,"Harm.HCAL_box.hit");
     }else{
       SetupDetBranch(hcal,"Harm.HCal.hit");
       SetupDetBranch(hcalscint,"Harm.HCalScint.hit");
       SetupDetBranch(hcalpart,"Harm.HCal");
     }
   }
   
   if(fExpOption==4 /* >=4 ??? */){
     fChain->SetBranchAddress("Harm.SBSGEM.hit.nhits", &Harm_SBSGEM_hit_nhits, &b_Harm_SBSGEM_hit_nhits);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.plane", &Harm_SBSGEM_hit_plane, &b_Harm_SBSGEM_hit_plane);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.strip", &Harm_SBSGEM_hit_strip, &b_Harm_SBSGEM_hit_strip);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.x", &Harm_SBSGEM_hit_x, &b_Harm_SBSGEM_hit_x);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.y", &Harm_SBSGEM_hit_y, &b_Harm_SBSGEM_hit_y);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.z", &Harm_SBSGEM_hit_z, &b_Harm_SBSGEM_hit_z);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.polx", &Harm_SBSGEM_hit_polx, &b_Harm_SBSGEM_hit_polx);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.poly", &Harm_SBSGEM_hit_poly, &b_Harm_SBSGEM_hit_poly);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.polz", &Harm_SBSGEM_hit_polz, &b_Harm_SBSGEM_hit_polz);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.trms", &Harm_SBSGEM_hit_trms, &b_Harm_SBSGEM_hit_trms);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.tmin", &Harm_SBSGEM_hit_tmin, &b_Harm_SBSGEM_hit_tmin);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.tmax", &Harm_SBSGEM_hit_tmax, &b_Harm_SBSGEM_hit_tmax);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.tx", &Harm_SBSGEM_hit_tx, &b_Harm_SBSGEM_hit_tx);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.ty", &Harm_SBSGEM_hit_ty, &b_Harm_SBSGEM_hit_ty);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.txp", &Harm_SBSGEM_hit_txp, &b_Harm_SBSGEM_hit_txp);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.typ", &Harm_SBSGEM_hit_typ, &b_Harm_SBSGEM_hit_typ);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.trid", &Harm_SBSGEM_hit_trid, &b_Harm_SBSGEM_hit_trid);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.xg", &Harm_SBSGEM_hit_xg, &b_Harm_SBSGEM_hit_xg);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.yg", &Harm_SBSGEM_hit_yg, &b_Harm_SBSGEM_hit_yg);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.zg", &Harm_SBSGEM_hit_zg, &b_Harm_SBSGEM_hit_zg);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.mid", &Harm_SBSGEM_hit_mid, &b_Harm_SBSGEM_hit_mid);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.pid", &Harm_SBSGEM_hit_pid, &b_Harm_SBSGEM_hit_pid);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.vx", &Harm_SBSGEM_hit_vx, &b_Harm_SBSGEM_hit_vx);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.vy", &Harm_SBSGEM_hit_vy, &b_Harm_SBSGEM_hit_vy);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.vz", &Harm_SBSGEM_hit_vz, &b_Harm_SBSGEM_hit_vz);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.p", &Harm_SBSGEM_hit_p, &b_Harm_SBSGEM_hit_p);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.edep", &Harm_SBSGEM_hit_edep, &b_Harm_SBSGEM_hit_edep);
     fChain->SetBranchAddress("Harm.SBSGEM.hit.beta", &Harm_SBSGEM_hit_beta, &b_Harm_SBSGEM_hit_beta);
   
     fChain->SetBranchAddress("Harm.SBSGEM.Track.ntracks", &Harm_SBSGEM_Track_ntracks, &b_Harm_SBSGEM_Track_ntracks);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.TID", &Harm_SBSGEM_Track_TID, &b_Harm_SBSGEM_Track_TID);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.PID", &Harm_SBSGEM_Track_PID, &b_Harm_SBSGEM_Track_PID);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.MID", &Harm_SBSGEM_Track_MID, &b_Harm_SBSGEM_Track_MID);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.NumHits", &Harm_SBSGEM_Track_NumHits, &b_Harm_SBSGEM_Track_NumHits);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.NumPlanes", &Harm_SBSGEM_Track_NumPlanes, &b_Harm_SBSGEM_Track_NumPlanes);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.NDF", &Harm_SBSGEM_Track_NDF, &b_Harm_SBSGEM_Track_NDF);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.Chi2fit", &Harm_SBSGEM_Track_Chi2fit, &b_Harm_SBSGEM_Track_Chi2fit);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.Chi2true", &Harm_SBSGEM_Track_Chi2true, &b_Harm_SBSGEM_Track_Chi2true);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.X", &Harm_SBSGEM_Track_X, &b_Harm_SBSGEM_Track_X);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.Y", &Harm_SBSGEM_Track_Y, &b_Harm_SBSGEM_Track_Y);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.Xp", &Harm_SBSGEM_Track_Xp, &b_Harm_SBSGEM_Track_Xp);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.Yp", &Harm_SBSGEM_Track_Yp, &b_Harm_SBSGEM_Track_Yp);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.Sx", &Harm_SBSGEM_Track_Sx, &b_Harm_SBSGEM_Track_Sx);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.Sy", &Harm_SBSGEM_Track_Sy, &b_Harm_SBSGEM_Track_Sy);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.Sz", &Harm_SBSGEM_Track_Sz, &b_Harm_SBSGEM_Track_Sz);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.Xfit", &Harm_SBSGEM_Track_Xfit, &b_Harm_SBSGEM_Track_Xfit);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.Yfit", &Harm_SBSGEM_Track_Yfit, &b_Harm_SBSGEM_Track_Yfit);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.Xpfit", &Harm_SBSGEM_Track_Xpfit, &b_Harm_SBSGEM_Track_Xpfit);
     fChain->SetBranchAddress("Harm.SBSGEM.Track.Ypfit", &Harm_SBSGEM_Track_Ypfit, &b_Harm_SBSGEM_Track_Ypfit);
     
     fChain->SetBranchAddress("Harm.RICH.hit.nhits", &Harm_RICH_hit_nhits, &b_Harm_RICH_hit_nhits);
     fChain->SetBranchAddress("Harm.RICH.hit.PMT", &Harm_RICH_hit_PMT, &b_Harm_RICH_hit_PMT);
     fChain->SetBranchAddress("Harm.RICH.hit.row", &Harm_RICH_hit_row, &b_Harm_RICH_hit_row);
     fChain->SetBranchAddress("Harm.RICH.hit.col", &Harm_RICH_hit_col, &b_Harm_RICH_hit_col);
     fChain->SetBranchAddress("Harm.RICH.hit.xpmt", &Harm_RICH_hit_xpmt, &b_Harm_RICH_hit_xpmt);
     fChain->SetBranchAddress("Harm.RICH.hit.ypmt", &Harm_RICH_hit_ypmt, &b_Harm_RICH_hit_ypmt);
     fChain->SetBranchAddress("Harm.RICH.hit.zpmt", &Harm_RICH_hit_zpmt, &b_Harm_RICH_hit_zpmt);
     fChain->SetBranchAddress("Harm.RICH.hit.xgpmt", &Harm_RICH_hit_xgpmt, &b_Harm_RICH_hit_xgpmt);
     fChain->SetBranchAddress("Harm.RICH.hit.ygpmt", &Harm_RICH_hit_ygpmt, &b_Harm_RICH_hit_ygpmt);
     fChain->SetBranchAddress("Harm.RICH.hit.zgpmt", &Harm_RICH_hit_zgpmt, &b_Harm_RICH_hit_zgpmt);
     fChain->SetBranchAddress("Harm.RICH.hit.NumPhotoelectrons", &Harm_RICH_hit_NumPhotoelectrons, &b_Harm_RICH_hit_NumPhotoelectrons);
     fChain->SetBranchAddress("Harm.RICH.hit.Time_avg", &Harm_RICH_hit_Time_avg, &b_Harm_RICH_hit_Time_avg);
     fChain->SetBranchAddress("Harm.RICH.hit.Time_rms", &Harm_RICH_hit_Time_rms, &b_Harm_RICH_hit_Time_rms);
     fChain->SetBranchAddress("Harm.RICH.hit.Time_min", &Harm_RICH_hit_Time_min, &b_Harm_RICH_hit_Time_min);
     fChain->SetBranchAddress("Harm.RICH.hit.Time_max", &Harm_RICH_hit_Time_max, &b_Harm_RICH_hit_Time_max);
     fChain->SetBranchAddress("Harm.RICH.hit.mTrackNo", &Harm_RICH_hit_mTrackNo, &b_Harm_RICH_hit_mTrackNo);
     fChain->SetBranchAddress("Harm.RICH.hit.xhit", &Harm_RICH_hit_xhit, &b_Harm_RICH_hit_xhit);
     fChain->SetBranchAddress("Harm.RICH.hit.yhit", &Harm_RICH_hit_yhit, &b_Harm_RICH_hit_yhit);
     fChain->SetBranchAddress("Harm.RICH.hit.zhit", &Harm_RICH_hit_zhit, &b_Harm_RICH_hit_zhit);
     fChain->SetBranchAddress("Harm.RICH.hit.pxhit", &Harm_RICH_hit_pxhit, &b_Harm_RICH_hit_pxhit);
     fChain->SetBranchAddress("Harm.RICH.hit.pyhit", &Harm_RICH_hit_pyhit, &b_Harm_RICH_hit_pyhit);
     fChain->SetBranchAddress("Harm.RICH.hit.pzhit", &Harm_RICH_hit_pzhit, &b_Harm_RICH_hit_pzhit);
     fChain->SetBranchAddress("Harm.RICH.hit.pvx", &Harm_RICH_hit_pvx, &b_Harm_RICH_hit_pvx);
     fChain->SetBranchAddress("Harm.RICH.hit.pvy", &Harm_RICH_hit_pvy, &b_Harm_RICH_hit_pvy);
     fChain->SetBranchAddress("Harm.RICH.hit.pvz", &Harm_RICH_hit_pvz, &b_Harm_RICH_hit_pvz);
     fChain->SetBranchAddress("Harm.RICH.hit.ppx", &Harm_RICH_hit_ppx, &b_Harm_RICH_hit_ppx);
     fChain->SetBranchAddress("Harm.RICH.hit.ppy", &Harm_RICH_hit_ppy, &b_Harm_RICH_hit_ppy);
     fChain->SetBranchAddress("Harm.RICH.hit.ppz", &Harm_RICH_hit_ppz, &b_Harm_RICH_hit_ppz);
     fChain->SetBranchAddress("Harm.RICH.hit.volume_flag", &Harm_RICH_hit_volume_flag, &b_Harm_RICH_hit_volume_flag);
   }
   
   if(fPythia){
     fChain->SetBranchAddress("primaries.Sigma", &primaries_Sigma, &b_primaries_Sigma);
     fChain->SetBranchAddress("primaries.Ebeam", &primaries_Ebeam, &b_primaries_Ebeam);
     fChain->SetBranchAddress("primaries.Eprime", &primaries_Eprime, &b_primaries_Eprime);
     fChain->SetBranchAddress("primaries.theta_e", &primaries_theta_e, &b_primaries_theta_e);
     fChain->SetBranchAddress("primaries.phi_e", &primaries_phi_e, &b_primaries_phi_e);
     fChain->SetBranchAddress("primaries.px_e", &primaries_px_e, &b_primaries_px_e);
     fChain->SetBranchAddress("primaries.py_e", &primaries_py_e, &b_primaries_py_e);
     fChain->SetBranchAddress("primaries.pz_e", &primaries_pz_e, &b_primaries_pz_e);
     fChain->SetBranchAddress("primaries.vx_e", &primaries_vx_e, &b_primaries_vx_e);
     fChain->SetBranchAddress("primaries.vy_e", &primaries_vy_e, &b_primaries_vy_e);
     fChain->SetBranchAddress("primaries.vz_e", &primaries_vz_e, &b_primaries_vz_e);
     fChain->SetBranchAddress("primaries.Egamma", &primaries_Egamma, &b_primaries_Egamma);
     fChain->SetBranchAddress("primaries.theta_gamma", &primaries_theta_gamma, &b_primaries_theta_gamma);
     fChain->SetBranchAddress("primaries.phi_gamma", &primaries_phi_gamma, &b_primaries_phi_gamma);
     fChain->SetBranchAddress("primaries.px_gamma", &primaries_px_gamma, &b_primaries_px_gamma);
     fChain->SetBranchAddress("primaries.py_gamma", &primaries_py_gamma, &b_primaries_py_gamma);
     fChain->SetBranchAddress("primaries.pz_gamma", &primaries_pz_gamma, &b_primaries_pz_gamma);
     fChain->SetBranchAddress("primaries.vx_gamma", &primaries_vx_gamma, &b_primaries_vx_gamma);
     fChain->SetBranchAddress("primaries.vy_gamma", &primaries_vy_gamma, &b_primaries_vy_gamma);
     fChain->SetBranchAddress("primaries.vz_gamma", &primaries_vz_gamma, &b_primaries_vz_gamma);
     
     fChain->SetBranchAddress("Primaries.Nprimaries", &Primaries_Nprimaries, &b_Primaries_Nprimaries);
     fChain->SetBranchAddress("Primaries.PID", &Primaries_PID, &b_Primaries_PID);
     fChain->SetBranchAddress("Primaries.genflag", &Primaries_genflag, &b_Primaries_genflag);
     fChain->SetBranchAddress("Primaries.Px", &Primaries_Px, &b_Primaries_Px);
     fChain->SetBranchAddress("Primaries.Py", &Primaries_Py, &b_Primaries_Py);
     fChain->SetBranchAddress("Primaries.Pz", &Primaries_Pz, &b_Primaries_Pz);
     fChain->SetBranchAddress("Primaries.vx", &Primaries_vx, &b_Primaries_vx);
     fChain->SetBranchAddress("Primaries.vy", &Primaries_vy, &b_Primaries_vy);
     fChain->SetBranchAddress("Primaries.vz", &Primaries_vz, &b_Primaries_vz);
     fChain->SetBranchAddress("Primaries.M", &Primaries_M, &b_Primaries_M);
     fChain->SetBranchAddress("Primaries.E", &Primaries_E, &b_Primaries_E);
     fChain->SetBranchAddress("Primaries.P", &Primaries_P, &b_Primaries_P);
     fChain->SetBranchAddress("Primaries.t", &Primaries_t, &b_Primaries_t);
     fChain->SetBranchAddress("Primaries.theta", &Primaries_theta, &b_Primaries_theta);
     fChain->SetBranchAddress("Primaries.phi", &Primaries_phi, &b_Primaries_phi);
   }
   
   Notify();
}


Bool_t g4sbs_tree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void g4sbs_tree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}

Int_t g4sbs_tree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

void g4sbs_tree::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L gep_tree_with_spin.C
//      Root > gep_tree_with_spin t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}


void g4sbs_tree::SetupDetBranch(TSBSGeant4::VDetData_t &det, const char *prefix)
{
  det.SetupBranches(fChain,prefix);
}
