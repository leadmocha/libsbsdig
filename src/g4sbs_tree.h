//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jan  7 11:54:23 2016 by ROOT version 5.34/32
// from TTree T/Geant4 SBS Simulation
// found on file: gep_spin_transport_Sx.root
//////////////////////////////////////////////////////////

#ifndef __G4SBS_TREE_H
#define __G4SBS_TREE_H

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// ----------------------------
// This class is useful to activate *all* variables from the tree 
// stored in g4sbs output root files. 
// In libsolgem (libsbsgem) it is used by the class TSBSGeant4File.
// Note it can perfectly be used in standalone.
// 
// It is more particularly dedicated to unfold files obtained with GEp setup.
// It includes information of CDET, GEp ECal, FT, FPP1&2, HCal.
// For more info check the following link: 
// https://hallaweb.jlab.org/wiki/index.php/Documentation_of_g4sbs#ROOT_Tree_Structure 
// 

// Header file for the classes stored in the TTree if any.
#include <vector>
#include "g4sbs_data.h"
// Fixed size dimensions of array or collections stored in the TTree if any.

class g4sbs_tree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
   int             fExpOption;// Choose experiment option: 1: GMn, 2: GEn, 3: GEp, 4: SIDIS, 5: A1n
   bool            fPythia;// needed to turn on/off the reading of the pythia variables
   bool            fEcalBox;// needed to turn on/off the reading of the ECAL_box data
   bool            fHcalBox;// needed to turn on/off the reading of the HCAL_box data

   // Declaration of leaf types
   
   // Event variables
   Double_t        ev_count;
   Double_t        ev_rate;
   Double_t        ev_solang;
   Double_t        ev_sigma;
   Double_t        ev_W2;
   Double_t        ev_xbj;
   Double_t        ev_Q2;
   Double_t        ev_th;
   Double_t        ev_ph;
   Double_t        ev_Aperp;
   Double_t        ev_Apar;
   Double_t        ev_Pt;
   Double_t        ev_Pl;
   Double_t        ev_vx;
   Double_t        ev_vy;
   Double_t        ev_vz;
   Double_t        ev_ep;
   Double_t        ev_np;
   Double_t        ev_epx;
   Double_t        ev_epy;
   Double_t        ev_epz;
   Double_t        ev_npx;
   Double_t        ev_npy;
   Double_t        ev_npz;
   Double_t        ev_nth;
   Double_t        ev_nph;
   Double_t        ev_pmperp;
   Double_t        ev_pmpar;
   Double_t        ev_pmparsm;
   Double_t        ev_z;
   Double_t        ev_phperp;
   Double_t        ev_phih;
   Double_t        ev_MX2;
   Double_t        ev_Sx;
   Double_t        ev_Sy;
   Double_t        ev_Sz;
   Int_t           ev_nucl;
   Int_t           ev_fnucl;
   Int_t           ev_hadr;
   Int_t           ev_earmaccept;
   Int_t           ev_harmaccept;
   Double_t        gen_thbb;
   Double_t        gen_thsbs;
   Double_t        gen_dbb;
   Double_t        gen_dsbs;
   Double_t        gen_dhcal;
   Double_t        gen_drich;
   Double_t        gen_dsbstrkr;
   Double_t        gen_Ebeam;
   
   //BB GEMs variables
   Int_t                 Earm_BBGEM_hit_nhits;
   std::vector<int>     *Earm_BBGEM_hit_plane;
   std::vector<int>     *Earm_BBGEM_hit_strip;
   std::vector<double>  *Earm_BBGEM_hit_x;
   std::vector<double>  *Earm_BBGEM_hit_y;
   std::vector<double>  *Earm_BBGEM_hit_z;
   std::vector<double>  *Earm_BBGEM_hit_polx;
   std::vector<double>  *Earm_BBGEM_hit_poly;
   std::vector<double>  *Earm_BBGEM_hit_polz;
   std::vector<double>  *Earm_BBGEM_hit_trms;
   std::vector<double>  *Earm_BBGEM_hit_tmin;
   std::vector<double>  *Earm_BBGEM_hit_tmax;
   std::vector<double>  *Earm_BBGEM_hit_tx;
   std::vector<double>  *Earm_BBGEM_hit_ty;
   std::vector<double>  *Earm_BBGEM_hit_txp;
   std::vector<double>  *Earm_BBGEM_hit_typ;
   std::vector<double>  *Earm_BBGEM_hit_xg;
   std::vector<double>  *Earm_BBGEM_hit_yg;
   std::vector<double>  *Earm_BBGEM_hit_zg;
   std::vector<int>     *Earm_BBGEM_hit_trid;
   std::vector<int>     *Earm_BBGEM_hit_mid;
   std::vector<int>     *Earm_BBGEM_hit_pid;
   std::vector<double>  *Earm_BBGEM_hit_vx;
   std::vector<double>  *Earm_BBGEM_hit_vy;
   std::vector<double>  *Earm_BBGEM_hit_vz;
   std::vector<double>  *Earm_BBGEM_hit_p;
   std::vector<double>  *Earm_BBGEM_hit_edep;
   std::vector<double>  *Earm_BBGEM_hit_beta;
   
   Int_t                 Earm_BBGEM_Track_ntracks;
   std::vector<int>     *Earm_BBGEM_Track_TID;
   std::vector<int>     *Earm_BBGEM_Track_PID;
   std::vector<int>     *Earm_BBGEM_Track_MID;
   std::vector<int>     *Earm_BBGEM_Track_NumHits;
   std::vector<int>     *Earm_BBGEM_Track_NumPlanes;
   std::vector<int>     *Earm_BBGEM_Track_NDF;
   std::vector<double>  *Earm_BBGEM_Track_Chi2fit;
   std::vector<double>  *Earm_BBGEM_Track_Chi2true;
   std::vector<double>  *Earm_BBGEM_Track_X;
   std::vector<double>  *Earm_BBGEM_Track_Y;
   std::vector<double>  *Earm_BBGEM_Track_Xp;
   std::vector<double>  *Earm_BBGEM_Track_Yp;
   std::vector<double>  *Earm_BBGEM_Track_Sx;
   std::vector<double>  *Earm_BBGEM_Track_Sy;
   std::vector<double>  *Earm_BBGEM_Track_Sz;
   std::vector<double>  *Earm_BBGEM_Track_Xfit;
   std::vector<double>  *Earm_BBGEM_Track_Yfit;
   std::vector<double>  *Earm_BBGEM_Track_Xpfit;
   std::vector<double>  *Earm_BBGEM_Track_Ypfit;
 
   // BB timing hodoscope
   TSBSGeant4::CalData_t  Earm_BBHodoScint;

   // GRINCH variables
   Int_t                 Earm_GRINCH_hit_nhits;
   std::vector<int>     *Earm_GRINCH_hit_PMT;
   std::vector<int>     *Earm_GRINCH_hit_row;
   std::vector<int>     *Earm_GRINCH_hit_col;
   std::vector<double>  *Earm_GRINCH_hit_xpmt;
   std::vector<double>  *Earm_GRINCH_hit_ypmt;
   std::vector<double>  *Earm_GRINCH_hit_zpmt;
   std::vector<double>  *Earm_GRINCH_hit_xgpmt;
   std::vector<double>  *Earm_GRINCH_hit_ygpmt;
   std::vector<double>  *Earm_GRINCH_hit_zgpmt;
   std::vector<int>     *Earm_GRINCH_hit_NumPhotoelectrons;
   std::vector<double>  *Earm_GRINCH_hit_Time_avg;
   std::vector<double>  *Earm_GRINCH_hit_Time_rms;
   std::vector<double>  *Earm_GRINCH_hit_Time_min;
   std::vector<double>  *Earm_GRINCH_hit_Time_max;
   std::vector<int>     *Earm_GRINCH_hit_mTrackNo;
   std::vector<double>  *Earm_GRINCH_hit_xhit;
   std::vector<double>  *Earm_GRINCH_hit_yhit;
   std::vector<double>  *Earm_GRINCH_hit_zhit;
   std::vector<double>  *Earm_GRINCH_hit_pxhit;
   std::vector<double>  *Earm_GRINCH_hit_pyhit;
   std::vector<double>  *Earm_GRINCH_hit_pzhit;
   std::vector<double>  *Earm_GRINCH_hit_pvx;
   std::vector<double>  *Earm_GRINCH_hit_pvy;
   std::vector<double>  *Earm_GRINCH_hit_pvz;
   std::vector<double>  *Earm_GRINCH_hit_ppx;
   std::vector<double>  *Earm_GRINCH_hit_ppy;
   std::vector<double>  *Earm_GRINCH_hit_ppz;
   std::vector<int>     *Earm_GRINCH_hit_volume_flag;
   
   //BB ECal variables
   TSBSGeant4::ECalData_t Earm_BBPS;
   TSBSGeant4::CalData_t  Earm_BBPSTF1;
   TSBSGeant4::ECalData_t Earm_BBSH;
   TSBSGeant4::CalData_t  Earm_BBSHTF1;

   // Coordinate detector hits
   TSBSGeant4::ECalData_t Earm_CDET;
   TSBSGeant4::CalData_t  Earm_CDET_Scint;
   TSBSGeant4::ECalData_t Harm_CDET;
   TSBSGeant4::CalData_t  Harm_CDET_Scint;

   // GEp Electromagnetic calorimeter hits
   TSBSGeant4::CalData_t  Earm_ECAL_box;
   TSBSGeant4::ECalData_t Earm_ECAL;
   TSBSGeant4::CalData_t  Earm_ECalTF1;

   // Focal Plane Polarimeter 1 hits
   Int_t                 Harm_FPP1_hit_nhits;
   std::vector<int>     *Harm_FPP1_hit_plane;
   std::vector<int>     *Harm_FPP1_hit_strip;
   std::vector<double>  *Harm_FPP1_hit_x;
   std::vector<double>  *Harm_FPP1_hit_y;
   std::vector<double>  *Harm_FPP1_hit_z;
   std::vector<double>  *Harm_FPP1_hit_polx;
   std::vector<double>  *Harm_FPP1_hit_poly;
   std::vector<double>  *Harm_FPP1_hit_polz;
   std::vector<double>  *Harm_FPP1_hit_t;
   std::vector<double>  *Harm_FPP1_hit_trms;
   std::vector<double>  *Harm_FPP1_hit_tmin;
   std::vector<double>  *Harm_FPP1_hit_tmax;
   std::vector<double>  *Harm_FPP1_hit_tx;
   std::vector<double>  *Harm_FPP1_hit_ty;
   std::vector<double>  *Harm_FPP1_hit_txp;
   std::vector<double>  *Harm_FPP1_hit_typ;
   std::vector<double>  *Harm_FPP1_hit_xg;
   std::vector<double>  *Harm_FPP1_hit_yg;
   std::vector<double>  *Harm_FPP1_hit_zg;
   std::vector<int>     *Harm_FPP1_hit_trid;
   std::vector<int>     *Harm_FPP1_hit_mid;
   std::vector<int>     *Harm_FPP1_hit_pid;
   std::vector<double>  *Harm_FPP1_hit_vx;
   std::vector<double>  *Harm_FPP1_hit_vy;
   std::vector<double>  *Harm_FPP1_hit_vz;
   std::vector<double>  *Harm_FPP1_hit_p;
   std::vector<double>  *Harm_FPP1_hit_edep;
   std::vector<double>  *Harm_FPP1_hit_beta;
   
   Int_t                 Harm_FPP1_Track_ntracks;
   std::vector<int>     *Harm_FPP1_Track_TID;
   std::vector<int>     *Harm_FPP1_Track_PID;
   std::vector<int>     *Harm_FPP1_Track_MID;
   std::vector<int>     *Harm_FPP1_Track_NumHits;
   std::vector<int>     *Harm_FPP1_Track_NumPlanes;
   std::vector<int>     *Harm_FPP1_Track_NDF;
   std::vector<double>  *Harm_FPP1_Track_Chi2fit;
   std::vector<double>  *Harm_FPP1_Track_Chi2true;
   std::vector<double>  *Harm_FPP1_Track_X;
   std::vector<double>  *Harm_FPP1_Track_Y;
   std::vector<double>  *Harm_FPP1_Track_Xp;
   std::vector<double>  *Harm_FPP1_Track_Yp;
   std::vector<double>  *Harm_FPP1_Track_T;
   std::vector<double>  *Harm_FPP1_Track_P;
   std::vector<double>  *Harm_FPP1_Track_Sx;
   std::vector<double>  *Harm_FPP1_Track_Sy;
   std::vector<double>  *Harm_FPP1_Track_Sz;
   std::vector<double>  *Harm_FPP1_Track_Xfit;
   std::vector<double>  *Harm_FPP1_Track_Yfit;
   std::vector<double>  *Harm_FPP1_Track_Xpfit;
   std::vector<double>  *Harm_FPP1_Track_Ypfit;
   
   // Focal Plane Polarimeter 2 hits
   Int_t           Harm_FPP2_hit_nhits;
   std::vector<int>     *Harm_FPP2_hit_plane;
   std::vector<int>     *Harm_FPP2_hit_strip;
   std::vector<double>  *Harm_FPP2_hit_x;
   std::vector<double>  *Harm_FPP2_hit_y;
   std::vector<double>  *Harm_FPP2_hit_z;
   std::vector<double>  *Harm_FPP2_hit_polx;
   std::vector<double>  *Harm_FPP2_hit_poly;
   std::vector<double>  *Harm_FPP2_hit_polz;
   std::vector<double>  *Harm_FPP2_hit_t;
   std::vector<double>  *Harm_FPP2_hit_trms;
   std::vector<double>  *Harm_FPP2_hit_tmin;
   std::vector<double>  *Harm_FPP2_hit_tmax;
   std::vector<double>  *Harm_FPP2_hit_tx;
   std::vector<double>  *Harm_FPP2_hit_ty;
   std::vector<double>  *Harm_FPP2_hit_txp;
   std::vector<double>  *Harm_FPP2_hit_typ;
   std::vector<double>  *Harm_FPP2_hit_xg;
   std::vector<double>  *Harm_FPP2_hit_yg;
   std::vector<double>  *Harm_FPP2_hit_zg;
   std::vector<int>     *Harm_FPP2_hit_trid;
   std::vector<int>     *Harm_FPP2_hit_mid;
   std::vector<int>     *Harm_FPP2_hit_pid;
   std::vector<double>  *Harm_FPP2_hit_vx;
   std::vector<double>  *Harm_FPP2_hit_vy;
   std::vector<double>  *Harm_FPP2_hit_vz;
   std::vector<double>  *Harm_FPP2_hit_p;
   std::vector<double>  *Harm_FPP2_hit_edep;
   std::vector<double>  *Harm_FPP2_hit_beta;
   
   Int_t                 Harm_FPP2_Track_ntracks;
   std::vector<int>     *Harm_FPP2_Track_TID;
   std::vector<int>     *Harm_FPP2_Track_PID;
   std::vector<int>     *Harm_FPP2_Track_MID;
   std::vector<int>     *Harm_FPP2_Track_NumHits;
   std::vector<int>     *Harm_FPP2_Track_NumPlanes;
   std::vector<int>     *Harm_FPP2_Track_NDF;
   std::vector<double>  *Harm_FPP2_Track_Chi2fit;
   std::vector<double>  *Harm_FPP2_Track_Chi2true;
   std::vector<double>  *Harm_FPP2_Track_X;
   std::vector<double>  *Harm_FPP2_Track_Y;
   std::vector<double>  *Harm_FPP2_Track_Xp;
   std::vector<double>  *Harm_FPP2_Track_Yp;
   std::vector<double>  *Harm_FPP2_Track_T;
   std::vector<double>  *Harm_FPP2_Track_P;
   std::vector<double>  *Harm_FPP2_Track_Sx;
   std::vector<double>  *Harm_FPP2_Track_Sy;
   std::vector<double>  *Harm_FPP2_Track_Sz;
   std::vector<double>  *Harm_FPP2_Track_Xfit;
   std::vector<double>  *Harm_FPP2_Track_Yfit;
   std::vector<double>  *Harm_FPP2_Track_Xpfit;
   std::vector<double>  *Harm_FPP2_Track_Ypfit;
   
   // Forward Tracker hits
   Int_t                 Harm_FT_hit_nhits;
   std::vector<int>     *Harm_FT_hit_plane;
   std::vector<int>     *Harm_FT_hit_strip;
   std::vector<double>  *Harm_FT_hit_x;
   std::vector<double>  *Harm_FT_hit_y;
   std::vector<double>  *Harm_FT_hit_z;
   std::vector<double>  *Harm_FT_hit_polx;
   std::vector<double>  *Harm_FT_hit_poly;
   std::vector<double>  *Harm_FT_hit_polz;
   std::vector<double>  *Harm_FT_hit_t;
   std::vector<double>  *Harm_FT_hit_trms;
   std::vector<double>  *Harm_FT_hit_tmin;
   std::vector<double>  *Harm_FT_hit_tmax;
   std::vector<double>  *Harm_FT_hit_tx;
   std::vector<double>  *Harm_FT_hit_ty;
   std::vector<double>  *Harm_FT_hit_txp;
   std::vector<double>  *Harm_FT_hit_typ;
   std::vector<double>  *Harm_FT_hit_xg;
   std::vector<double>  *Harm_FT_hit_yg;
   std::vector<double>  *Harm_FT_hit_zg;
   std::vector<int>     *Harm_FT_hit_trid;
   std::vector<int>     *Harm_FT_hit_mid;
   std::vector<int>     *Harm_FT_hit_pid;
   std::vector<double>  *Harm_FT_hit_vx;
   std::vector<double>  *Harm_FT_hit_vy;
   std::vector<double>  *Harm_FT_hit_vz;
   std::vector<double>  *Harm_FT_hit_p;
   std::vector<double>  *Harm_FT_hit_edep;
   std::vector<double>  *Harm_FT_hit_beta;
   
   Int_t                 Harm_FT_Track_ntracks;
   std::vector<int>     *Harm_FT_Track_TID;
   std::vector<int>     *Harm_FT_Track_PID;
   std::vector<int>     *Harm_FT_Track_MID;
   std::vector<int>     *Harm_FT_Track_NumHits;
   std::vector<int>     *Harm_FT_Track_NumPlanes;
   std::vector<int>     *Harm_FT_Track_NDF;
   std::vector<double>  *Harm_FT_Track_Chi2fit;
   std::vector<double>  *Harm_FT_Track_Chi2true;
   std::vector<double>  *Harm_FT_Track_X;
   std::vector<double>  *Harm_FT_Track_Y;
   std::vector<double>  *Harm_FT_Track_Xp;
   std::vector<double>  *Harm_FT_Track_Yp;
   std::vector<double>  *Harm_FT_Track_T;
   std::vector<double>  *Harm_FT_Track_P;
   std::vector<double>  *Harm_FT_Track_Sx;
   std::vector<double>  *Harm_FT_Track_Sy;
   std::vector<double>  *Harm_FT_Track_Sz;
   std::vector<double>  *Harm_FT_Track_Xfit;
   std::vector<double>  *Harm_FT_Track_Yfit;
   std::vector<double>  *Harm_FT_Track_Xpfit;
   std::vector<double>  *Harm_FT_Track_Ypfit;
   
   // Hadronic calorimeter hits
   // An example for how to simplify tree objects
   // TODO: Don't hard code detectors here, but rather read them in
   // through a database if possible
   TSBSGeant4::CalData_t      hcalbox;
   TSBSGeant4::CalData_t      hcalscint;
   TSBSGeant4::ECalData_t     hcal;
   TSBSGeant4::ECalPartData_t hcalpart;

   //SBS GEMs variables
   Int_t                 Harm_SBSGEM_hit_nhits;
   std::vector<int>     *Harm_SBSGEM_hit_plane;
   std::vector<int>     *Harm_SBSGEM_hit_strip;
   std::vector<double>  *Harm_SBSGEM_hit_x;
   std::vector<double>  *Harm_SBSGEM_hit_y;
   std::vector<double>  *Harm_SBSGEM_hit_z;
   std::vector<double>  *Harm_SBSGEM_hit_polx;
   std::vector<double>  *Harm_SBSGEM_hit_poly;
   std::vector<double>  *Harm_SBSGEM_hit_polz;
   std::vector<double>  *Harm_SBSGEM_hit_trms;
   std::vector<double>  *Harm_SBSGEM_hit_tmin;
   std::vector<double>  *Harm_SBSGEM_hit_tmax;
   std::vector<double>  *Harm_SBSGEM_hit_tx;
   std::vector<double>  *Harm_SBSGEM_hit_ty;
   std::vector<double>  *Harm_SBSGEM_hit_txp;
   std::vector<double>  *Harm_SBSGEM_hit_typ;
   std::vector<double>  *Harm_SBSGEM_hit_xg;
   std::vector<double>  *Harm_SBSGEM_hit_yg;
   std::vector<double>  *Harm_SBSGEM_hit_zg;
   std::vector<int>     *Harm_SBSGEM_hit_trid;
   std::vector<int>     *Harm_SBSGEM_hit_mid;
   std::vector<int>     *Harm_SBSGEM_hit_pid;
   std::vector<double>  *Harm_SBSGEM_hit_vx;
   std::vector<double>  *Harm_SBSGEM_hit_vy;
   std::vector<double>  *Harm_SBSGEM_hit_vz;
   std::vector<double>  *Harm_SBSGEM_hit_p;
   std::vector<double>  *Harm_SBSGEM_hit_edep;
   std::vector<double>  *Harm_SBSGEM_hit_beta;
   
   Int_t                 Harm_SBSGEM_Track_ntracks;
   std::vector<int>     *Harm_SBSGEM_Track_TID;
   std::vector<int>     *Harm_SBSGEM_Track_PID;
   std::vector<int>     *Harm_SBSGEM_Track_MID;
   std::vector<int>     *Harm_SBSGEM_Track_NumHits;
   std::vector<int>     *Harm_SBSGEM_Track_NumPlanes;
   std::vector<int>     *Harm_SBSGEM_Track_NDF;
   std::vector<double>  *Harm_SBSGEM_Track_Chi2fit;
   std::vector<double>  *Harm_SBSGEM_Track_Chi2true;
   std::vector<double>  *Harm_SBSGEM_Track_X;
   std::vector<double>  *Harm_SBSGEM_Track_Y;
   std::vector<double>  *Harm_SBSGEM_Track_Xp;
   std::vector<double>  *Harm_SBSGEM_Track_Yp;
   std::vector<double>  *Harm_SBSGEM_Track_Sx;
   std::vector<double>  *Harm_SBSGEM_Track_Sy;
   std::vector<double>  *Harm_SBSGEM_Track_Sz;
   std::vector<double>  *Harm_SBSGEM_Track_Xfit;
   std::vector<double>  *Harm_SBSGEM_Track_Yfit;
   std::vector<double>  *Harm_SBSGEM_Track_Xpfit;
   std::vector<double>  *Harm_SBSGEM_Track_Ypfit;
   
   // RICH variables
   Int_t                 Harm_RICH_hit_nhits;
   std::vector<int>     *Harm_RICH_hit_PMT;
   std::vector<int>     *Harm_RICH_hit_row;
   std::vector<int>     *Harm_RICH_hit_col;
   std::vector<double>  *Harm_RICH_hit_xpmt;
   std::vector<double>  *Harm_RICH_hit_ypmt;
   std::vector<double>  *Harm_RICH_hit_zpmt;
   std::vector<double>  *Harm_RICH_hit_xgpmt;
   std::vector<double>  *Harm_RICH_hit_ygpmt;
   std::vector<double>  *Harm_RICH_hit_zgpmt;
   std::vector<int>     *Harm_RICH_hit_NumPhotoelectrons;
   std::vector<double>  *Harm_RICH_hit_Time_avg;
   std::vector<double>  *Harm_RICH_hit_Time_rms;
   std::vector<double>  *Harm_RICH_hit_Time_min;
   std::vector<double>  *Harm_RICH_hit_Time_max;
   std::vector<int>     *Harm_RICH_hit_mTrackNo;
   std::vector<double>  *Harm_RICH_hit_xhit;
   std::vector<double>  *Harm_RICH_hit_yhit;
   std::vector<double>  *Harm_RICH_hit_zhit;
   std::vector<double>  *Harm_RICH_hit_pxhit;
   std::vector<double>  *Harm_RICH_hit_pyhit;
   std::vector<double>  *Harm_RICH_hit_pzhit;
   std::vector<double>  *Harm_RICH_hit_pvx;
   std::vector<double>  *Harm_RICH_hit_pvy;
   std::vector<double>  *Harm_RICH_hit_pvz;
   std::vector<double>  *Harm_RICH_hit_ppx;
   std::vector<double>  *Harm_RICH_hit_ppy;
   std::vector<double>  *Harm_RICH_hit_ppz;
   std::vector<int>     *Harm_RICH_hit_volume_flag;

   //Pythia variables
   Double_t              primaries_Sigma;
   Double_t              primaries_Ebeam;
   Double_t              primaries_Eprime;
   Double_t              primaries_theta_e;
   Double_t              primaries_phi_e;
   Double_t              primaries_px_e;
   Double_t              primaries_py_e;
   Double_t              primaries_pz_e;
   Double_t              primaries_vx_e;
   Double_t              primaries_vy_e;
   Double_t              primaries_vz_e;
   Double_t              primaries_Egamma;
   Double_t              primaries_theta_gamma;
   Double_t              primaries_phi_gamma;
   Double_t              primaries_px_gamma;
   Double_t              primaries_py_gamma;
   Double_t              primaries_pz_gamma;
   Double_t              primaries_vx_gamma;
   Double_t              primaries_vy_gamma;
   Double_t              primaries_vz_gamma;
   
   Int_t                 Primaries_Nprimaries;
   std::vector<int>     *Primaries_PID;
   std::vector<int>     *Primaries_genflag;
   std::vector<double>  *Primaries_Px;
   std::vector<double>  *Primaries_Py;
   std::vector<double>  *Primaries_Pz;
   std::vector<double>  *Primaries_vx;
   std::vector<double>  *Primaries_vy;
   std::vector<double>  *Primaries_vz;
   std::vector<double>  *Primaries_M;
   std::vector<double>  *Primaries_E;
   std::vector<double>  *Primaries_P;
   std::vector<double>  *Primaries_t;
   std::vector<double>  *Primaries_theta;
   std::vector<double>  *Primaries_phi;
   
   // List of branches
   TBranch        *b_ev;   //!
   TBranch        *b_gen;   //!
   
   TBranch        *b_Earm_BBGEM_hit_nhits;   //!
   TBranch        *b_Earm_BBGEM_hit_plane;   //!
   TBranch        *b_Earm_BBGEM_hit_strip;   //!
   TBranch        *b_Earm_BBGEM_hit_x;   //!
   TBranch        *b_Earm_BBGEM_hit_y;   //!
   TBranch        *b_Earm_BBGEM_hit_z;   //!
   TBranch        *b_Earm_BBGEM_hit_polx;   //!
   TBranch        *b_Earm_BBGEM_hit_poly;   //!
   TBranch        *b_Earm_BBGEM_hit_polz;   //!
   TBranch        *b_Earm_BBGEM_hit_trms;   //!
   TBranch        *b_Earm_BBGEM_hit_tmin;   //!
   TBranch        *b_Earm_BBGEM_hit_tmax;   //!
   TBranch        *b_Earm_BBGEM_hit_tx;   //!
   TBranch        *b_Earm_BBGEM_hit_ty;   //!
   TBranch        *b_Earm_BBGEM_hit_txp;   //!
   TBranch        *b_Earm_BBGEM_hit_typ;   //!
   TBranch        *b_Earm_BBGEM_hit_xg;   //!
   TBranch        *b_Earm_BBGEM_hit_yg;   //!
   TBranch        *b_Earm_BBGEM_hit_zg;   //!
   TBranch        *b_Earm_BBGEM_hit_trid;   //!
   TBranch        *b_Earm_BBGEM_hit_mid;   //!
   TBranch        *b_Earm_BBGEM_hit_pid;   //!
   TBranch        *b_Earm_BBGEM_hit_vx;   //!
   TBranch        *b_Earm_BBGEM_hit_vy;   //!
   TBranch        *b_Earm_BBGEM_hit_vz;   //!
   TBranch        *b_Earm_BBGEM_hit_p;   //!
   TBranch        *b_Earm_BBGEM_hit_edep;   //!
   TBranch        *b_Earm_BBGEM_hit_beta;   //!
   
   TBranch        *b_Earm_BBGEM_Track_ntracks;   //!
   TBranch        *b_Earm_BBGEM_Track_TID;   //!
   TBranch        *b_Earm_BBGEM_Track_PID;   //!
   TBranch        *b_Earm_BBGEM_Track_MID;   //!
   TBranch        *b_Earm_BBGEM_Track_NumHits;   //!
   TBranch        *b_Earm_BBGEM_Track_NumPlanes;   //!
   TBranch        *b_Earm_BBGEM_Track_NDF;   //!
   TBranch        *b_Earm_BBGEM_Track_Chi2fit;   //!
   TBranch        *b_Earm_BBGEM_Track_Chi2true;   //!
   TBranch        *b_Earm_BBGEM_Track_X;   //!
   TBranch        *b_Earm_BBGEM_Track_Y;   //!
   TBranch        *b_Earm_BBGEM_Track_Xp;   //!
   TBranch        *b_Earm_BBGEM_Track_Yp;   //!
   TBranch        *b_Earm_BBGEM_Track_Sx;   //!
   TBranch        *b_Earm_BBGEM_Track_Sy;   //!
   TBranch        *b_Earm_BBGEM_Track_Sz;   //!
   TBranch        *b_Earm_BBGEM_Track_Xfit;   //!
   TBranch        *b_Earm_BBGEM_Track_Yfit;   //!
   TBranch        *b_Earm_BBGEM_Track_Xpfit;   //!
   TBranch        *b_Earm_BBGEM_Track_Ypfit;   //!

   TBranch        *b_Earm_GRINCH_hit_nhits;   //!
   TBranch        *b_Earm_GRINCH_hit_PMT;   //!
   TBranch        *b_Earm_GRINCH_hit_row;   //!
   TBranch        *b_Earm_GRINCH_hit_col;   //!
   TBranch        *b_Earm_GRINCH_hit_xpmt;   //!
   TBranch        *b_Earm_GRINCH_hit_ypmt;   //!
   TBranch        *b_Earm_GRINCH_hit_zpmt;   //!
   TBranch        *b_Earm_GRINCH_hit_xgpmt;   //!
   TBranch        *b_Earm_GRINCH_hit_ygpmt;   //!
   TBranch        *b_Earm_GRINCH_hit_zgpmt;   //!
   TBranch        *b_Earm_GRINCH_hit_NumPhotoelectrons;   //!
   TBranch        *b_Earm_GRINCH_hit_Time_avg;   //!
   TBranch        *b_Earm_GRINCH_hit_Time_rms;   //!
   TBranch        *b_Earm_GRINCH_hit_Time_min;   //!
   TBranch        *b_Earm_GRINCH_hit_Time_max;   //!
   TBranch        *b_Earm_GRINCH_hit_mTrackNo;   //!
   TBranch        *b_Earm_GRINCH_hit_xhit;   //!
   TBranch        *b_Earm_GRINCH_hit_yhit;   //!
   TBranch        *b_Earm_GRINCH_hit_zhit;   //!
   TBranch        *b_Earm_GRINCH_hit_pxhit;   //!
   TBranch        *b_Earm_GRINCH_hit_pyhit;   //!
   TBranch        *b_Earm_GRINCH_hit_pzhit;   //!
   TBranch        *b_Earm_GRINCH_hit_pvx;   //!
   TBranch        *b_Earm_GRINCH_hit_pvy;   //!
   TBranch        *b_Earm_GRINCH_hit_pvz;   //!
   TBranch        *b_Earm_GRINCH_hit_ppx;   //!
   TBranch        *b_Earm_GRINCH_hit_ppy;   //!
   TBranch        *b_Earm_GRINCH_hit_ppz;   //!
   TBranch        *b_Earm_GRINCH_hit_volume_flag;   //!

   TBranch        *b_Harm_FPP1_hit_nhits;   //!
   TBranch        *b_Harm_FPP1_hit_plane;   //!
   TBranch        *b_Harm_FPP1_hit_strip;   //!
   TBranch        *b_Harm_FPP1_hit_x;   //!
   TBranch        *b_Harm_FPP1_hit_y;   //!
   TBranch        *b_Harm_FPP1_hit_z;   //!
   TBranch        *b_Harm_FPP1_hit_polx;   //!
   TBranch        *b_Harm_FPP1_hit_poly;   //!
   TBranch        *b_Harm_FPP1_hit_polz;   //!
   TBranch        *b_Harm_FPP1_hit_t;   //!
   TBranch        *b_Harm_FPP1_hit_trms;   //!
   TBranch        *b_Harm_FPP1_hit_tmin;   //!
   TBranch        *b_Harm_FPP1_hit_tmax;   //!
   TBranch        *b_Harm_FPP1_hit_tx;   //!
   TBranch        *b_Harm_FPP1_hit_ty;   //!
   TBranch        *b_Harm_FPP1_hit_txp;   //!
   TBranch        *b_Harm_FPP1_hit_typ;   //!
   TBranch        *b_Harm_FPP1_hit_xg;   //!
   TBranch        *b_Harm_FPP1_hit_yg;   //!
   TBranch        *b_Harm_FPP1_hit_zg;   //!
   TBranch        *b_Harm_FPP1_hit_trid;   //!
   TBranch        *b_Harm_FPP1_hit_mid;   //!
   TBranch        *b_Harm_FPP1_hit_pid;   //!
   TBranch        *b_Harm_FPP1_hit_vx;   //!
   TBranch        *b_Harm_FPP1_hit_vy;   //!
   TBranch        *b_Harm_FPP1_hit_vz;   //!
   TBranch        *b_Harm_FPP1_hit_p;   //!
   TBranch        *b_Harm_FPP1_hit_edep;   //!
   TBranch        *b_Harm_FPP1_hit_beta;   //!
   
   TBranch        *b_Harm_FPP1_Track_ntracks;   //!
   TBranch        *b_Harm_FPP1_Track_TID;   //!
   TBranch        *b_Harm_FPP1_Track_PID;   //!
   TBranch        *b_Harm_FPP1_Track_MID;   //!
   TBranch        *b_Harm_FPP1_Track_NumHits;   //!
   TBranch        *b_Harm_FPP1_Track_NumPlanes;   //!
   TBranch        *b_Harm_FPP1_Track_NDF;   //!
   TBranch        *b_Harm_FPP1_Track_Chi2fit;   //!
   TBranch        *b_Harm_FPP1_Track_Chi2true;   //!
   TBranch        *b_Harm_FPP1_Track_X;   //!
   TBranch        *b_Harm_FPP1_Track_Y;   //!
   TBranch        *b_Harm_FPP1_Track_Xp;   //!
   TBranch        *b_Harm_FPP1_Track_Yp;   //!
   TBranch        *b_Harm_FPP1_Track_T;   //!
   TBranch        *b_Harm_FPP1_Track_P;   //!
   TBranch        *b_Harm_FPP1_Track_Sx;   //!
   TBranch        *b_Harm_FPP1_Track_Sy;   //!
   TBranch        *b_Harm_FPP1_Track_Sz;   //!
   TBranch        *b_Harm_FPP1_Track_Xfit;   //!
   TBranch        *b_Harm_FPP1_Track_Yfit;   //!
   TBranch        *b_Harm_FPP1_Track_Xpfit;   //!
   TBranch        *b_Harm_FPP1_Track_Ypfit;   //!
   
   TBranch        *b_Harm_FPP2_hit_nhits;   //!
   TBranch        *b_Harm_FPP2_hit_plane;   //!
   TBranch        *b_Harm_FPP2_hit_strip;   //!
   TBranch        *b_Harm_FPP2_hit_x;   //!
   TBranch        *b_Harm_FPP2_hit_y;   //!
   TBranch        *b_Harm_FPP2_hit_z;   //!
   TBranch        *b_Harm_FPP2_hit_polx;   //!
   TBranch        *b_Harm_FPP2_hit_poly;   //!
   TBranch        *b_Harm_FPP2_hit_polz;   //!
   TBranch        *b_Harm_FPP2_hit_t;   //!
   TBranch        *b_Harm_FPP2_hit_trms;   //!
   TBranch        *b_Harm_FPP2_hit_tmin;   //!
   TBranch        *b_Harm_FPP2_hit_tmax;   //!
   TBranch        *b_Harm_FPP2_hit_tx;   //!
   TBranch        *b_Harm_FPP2_hit_ty;   //!
   TBranch        *b_Harm_FPP2_hit_txp;   //!
   TBranch        *b_Harm_FPP2_hit_typ;   //!
   TBranch        *b_Harm_FPP2_hit_xg;   //!
   TBranch        *b_Harm_FPP2_hit_yg;   //!
   TBranch        *b_Harm_FPP2_hit_zg;   //!
   TBranch        *b_Harm_FPP2_hit_trid;   //!
   TBranch        *b_Harm_FPP2_hit_mid;   //!
   TBranch        *b_Harm_FPP2_hit_pid;   //!
   TBranch        *b_Harm_FPP2_hit_vx;   //!
   TBranch        *b_Harm_FPP2_hit_vy;   //!
   TBranch        *b_Harm_FPP2_hit_vz;   //!
   TBranch        *b_Harm_FPP2_hit_p;   //!
   TBranch        *b_Harm_FPP2_hit_edep;   //!
   TBranch        *b_Harm_FPP2_hit_beta;   //!
   
   TBranch        *b_Harm_FPP2_Track_ntracks;   //!
   TBranch        *b_Harm_FPP2_Track_TID;   //!
   TBranch        *b_Harm_FPP2_Track_PID;   //!
   TBranch        *b_Harm_FPP2_Track_MID;   //!
   TBranch        *b_Harm_FPP2_Track_NumHits;   //!
   TBranch        *b_Harm_FPP2_Track_NumPlanes;   //!
   TBranch        *b_Harm_FPP2_Track_NDF;   //!
   TBranch        *b_Harm_FPP2_Track_Chi2fit;   //!
   TBranch        *b_Harm_FPP2_Track_Chi2true;   //!
   TBranch        *b_Harm_FPP2_Track_X;   //!
   TBranch        *b_Harm_FPP2_Track_Y;   //!
   TBranch        *b_Harm_FPP2_Track_Xp;   //!
   TBranch        *b_Harm_FPP2_Track_Yp;   //!
   TBranch        *b_Harm_FPP2_Track_T;   //!
   TBranch        *b_Harm_FPP2_Track_P;   //!
   TBranch        *b_Harm_FPP2_Track_Sx;   //!
   TBranch        *b_Harm_FPP2_Track_Sy;   //!
   TBranch        *b_Harm_FPP2_Track_Sz;   //!
   TBranch        *b_Harm_FPP2_Track_Xfit;   //!
   TBranch        *b_Harm_FPP2_Track_Yfit;   //!
   TBranch        *b_Harm_FPP2_Track_Xpfit;   //!
   TBranch        *b_Harm_FPP2_Track_Ypfit;   //!
   
   TBranch        *b_Harm_FT_hit_nhits;   //!
   TBranch        *b_Harm_FT_hit_plane;   //!
   TBranch        *b_Harm_FT_hit_strip;   //!
   TBranch        *b_Harm_FT_hit_x;   //!
   TBranch        *b_Harm_FT_hit_y;   //!
   TBranch        *b_Harm_FT_hit_z;   //!
   TBranch        *b_Harm_FT_hit_polx;   //!
   TBranch        *b_Harm_FT_hit_poly;   //!
   TBranch        *b_Harm_FT_hit_polz;   //!
   TBranch        *b_Harm_FT_hit_t;   //!
   TBranch        *b_Harm_FT_hit_trms;   //!
   TBranch        *b_Harm_FT_hit_tmin;   //!
   TBranch        *b_Harm_FT_hit_tmax;   //!
   TBranch        *b_Harm_FT_hit_tx;   //!
   TBranch        *b_Harm_FT_hit_ty;   //!
   TBranch        *b_Harm_FT_hit_txp;   //!
   TBranch        *b_Harm_FT_hit_typ;   //!
   TBranch        *b_Harm_FT_hit_xg;   //!
   TBranch        *b_Harm_FT_hit_yg;   //!
   TBranch        *b_Harm_FT_hit_zg;   //!
   TBranch        *b_Harm_FT_hit_trid;   //!
   TBranch        *b_Harm_FT_hit_mid;   //!
   TBranch        *b_Harm_FT_hit_pid;   //!
   TBranch        *b_Harm_FT_hit_vx;   //!
   TBranch        *b_Harm_FT_hit_vy;   //!
   TBranch        *b_Harm_FT_hit_vz;   //!
   TBranch        *b_Harm_FT_hit_p;   //!
   TBranch        *b_Harm_FT_hit_edep;   //!
   TBranch        *b_Harm_FT_hit_beta;   //!
   
   TBranch        *b_Harm_FT_Track_ntracks;   //!
   TBranch        *b_Harm_FT_Track_TID;   //!
   TBranch        *b_Harm_FT_Track_PID;   //!
   TBranch        *b_Harm_FT_Track_MID;   //!
   TBranch        *b_Harm_FT_Track_NumHits;   //!
   TBranch        *b_Harm_FT_Track_NumPlanes;   //!
   TBranch        *b_Harm_FT_Track_NDF;   //!
   TBranch        *b_Harm_FT_Track_Chi2fit;   //!
   TBranch        *b_Harm_FT_Track_Chi2true;   //!
   TBranch        *b_Harm_FT_Track_X;   //!
   TBranch        *b_Harm_FT_Track_Y;   //!
   TBranch        *b_Harm_FT_Track_Xp;   //!
   TBranch        *b_Harm_FT_Track_Yp;   //!
   TBranch        *b_Harm_FT_Track_T;   //!
   TBranch        *b_Harm_FT_Track_P;   //!
   TBranch        *b_Harm_FT_Track_Sx;   //!
   TBranch        *b_Harm_FT_Track_Sy;   //!
   TBranch        *b_Harm_FT_Track_Sz;   //!
   TBranch        *b_Harm_FT_Track_Xfit;   //!
   TBranch        *b_Harm_FT_Track_Yfit;   //!
   TBranch        *b_Harm_FT_Track_Xpfit;   //!
   TBranch        *b_Harm_FT_Track_Ypfit;   //!

   TBranch        *b_Harm_SBSGEM_hit_nhits;   //!
   TBranch        *b_Harm_SBSGEM_hit_plane;   //!
   TBranch        *b_Harm_SBSGEM_hit_strip;   //!
   TBranch        *b_Harm_SBSGEM_hit_x;   //!
   TBranch        *b_Harm_SBSGEM_hit_y;   //!
   TBranch        *b_Harm_SBSGEM_hit_z;   //!
   TBranch        *b_Harm_SBSGEM_hit_polx;   //!
   TBranch        *b_Harm_SBSGEM_hit_poly;   //!
   TBranch        *b_Harm_SBSGEM_hit_polz;   //!
   TBranch        *b_Harm_SBSGEM_hit_trms;   //!
   TBranch        *b_Harm_SBSGEM_hit_tmin;   //!
   TBranch        *b_Harm_SBSGEM_hit_tmax;   //!
   TBranch        *b_Harm_SBSGEM_hit_tx;   //!
   TBranch        *b_Harm_SBSGEM_hit_ty;   //!
   TBranch        *b_Harm_SBSGEM_hit_txp;   //!
   TBranch        *b_Harm_SBSGEM_hit_typ;   //!
   TBranch        *b_Harm_SBSGEM_hit_xg;   //!
   TBranch        *b_Harm_SBSGEM_hit_yg;   //!
   TBranch        *b_Harm_SBSGEM_hit_zg;   //!
   TBranch        *b_Harm_SBSGEM_hit_trid;   //!
   TBranch        *b_Harm_SBSGEM_hit_mid;   //!
   TBranch        *b_Harm_SBSGEM_hit_pid;   //!
   TBranch        *b_Harm_SBSGEM_hit_vx;   //!
   TBranch        *b_Harm_SBSGEM_hit_vy;   //!
   TBranch        *b_Harm_SBSGEM_hit_vz;   //!
   TBranch        *b_Harm_SBSGEM_hit_p;   //!
   TBranch        *b_Harm_SBSGEM_hit_edep;   //!
   TBranch        *b_Harm_SBSGEM_hit_beta;   //!
   
   TBranch        *b_Harm_SBSGEM_Track_ntracks;   //!
   TBranch        *b_Harm_SBSGEM_Track_TID;   //!
   TBranch        *b_Harm_SBSGEM_Track_PID;   //!
   TBranch        *b_Harm_SBSGEM_Track_MID;   //!
   TBranch        *b_Harm_SBSGEM_Track_NumHits;   //!
   TBranch        *b_Harm_SBSGEM_Track_NumPlanes;   //!
   TBranch        *b_Harm_SBSGEM_Track_NDF;   //!
   TBranch        *b_Harm_SBSGEM_Track_Chi2fit;   //!
   TBranch        *b_Harm_SBSGEM_Track_Chi2true;   //!
   TBranch        *b_Harm_SBSGEM_Track_X;   //!
   TBranch        *b_Harm_SBSGEM_Track_Y;   //!
   TBranch        *b_Harm_SBSGEM_Track_Xp;   //!
   TBranch        *b_Harm_SBSGEM_Track_Yp;   //!
   TBranch        *b_Harm_SBSGEM_Track_Sx;   //!
   TBranch        *b_Harm_SBSGEM_Track_Sy;   //!
   TBranch        *b_Harm_SBSGEM_Track_Sz;   //!
   TBranch        *b_Harm_SBSGEM_Track_Xfit;   //!
   TBranch        *b_Harm_SBSGEM_Track_Yfit;   //!
   TBranch        *b_Harm_SBSGEM_Track_Xpfit;   //!
   TBranch        *b_Harm_SBSGEM_Track_Ypfit;   //!

   TBranch        *b_Harm_RICH_hit_nhits;   //!
   TBranch        *b_Harm_RICH_hit_PMT;   //!
   TBranch        *b_Harm_RICH_hit_row;   //!
   TBranch        *b_Harm_RICH_hit_col;   //!
   TBranch        *b_Harm_RICH_hit_xpmt;   //!
   TBranch        *b_Harm_RICH_hit_ypmt;   //!
   TBranch        *b_Harm_RICH_hit_zpmt;   //!
   TBranch        *b_Harm_RICH_hit_xgpmt;   //!
   TBranch        *b_Harm_RICH_hit_ygpmt;   //!
   TBranch        *b_Harm_RICH_hit_zgpmt;   //!
   TBranch        *b_Harm_RICH_hit_NumPhotoelectrons;   //!
   TBranch        *b_Harm_RICH_hit_Time_avg;   //!
   TBranch        *b_Harm_RICH_hit_Time_rms;   //!
   TBranch        *b_Harm_RICH_hit_Time_min;   //!
   TBranch        *b_Harm_RICH_hit_Time_max;   //!
   TBranch        *b_Harm_RICH_hit_mTrackNo;   //!
   TBranch        *b_Harm_RICH_hit_xhit;   //!
   TBranch        *b_Harm_RICH_hit_yhit;   //!
   TBranch        *b_Harm_RICH_hit_zhit;   //!
   TBranch        *b_Harm_RICH_hit_pxhit;   //!
   TBranch        *b_Harm_RICH_hit_pyhit;   //!
   TBranch        *b_Harm_RICH_hit_pzhit;   //!
   TBranch        *b_Harm_RICH_hit_pvx;   //!
   TBranch        *b_Harm_RICH_hit_pvy;   //!
   TBranch        *b_Harm_RICH_hit_pvz;   //!
   TBranch        *b_Harm_RICH_hit_ppx;   //!
   TBranch        *b_Harm_RICH_hit_ppy;   //!
   TBranch        *b_Harm_RICH_hit_ppz;   //!
   TBranch        *b_Harm_RICH_hit_volume_flag;   //!
   
   TBranch        *b_primaries_Sigma;   //!
   TBranch        *b_primaries_Ebeam;   //!
   TBranch        *b_primaries_Eprime;   //!
   TBranch        *b_primaries_theta_e;   //!
   TBranch        *b_primaries_phi_e;   //!
   TBranch        *b_primaries_px_e;   //!
   TBranch        *b_primaries_py_e;   //!
   TBranch        *b_primaries_pz_e;   //!
   TBranch        *b_primaries_vx_e;   //!
   TBranch        *b_primaries_vy_e;   //!
   TBranch        *b_primaries_vz_e;   //!
   TBranch        *b_primaries_Egamma;   //!
   TBranch        *b_primaries_theta_gamma;   //!
   TBranch        *b_primaries_phi_gamma;   //!
   TBranch        *b_primaries_px_gamma;   //!
   TBranch        *b_primaries_py_gamma;   //!
   TBranch        *b_primaries_pz_gamma;   //!
   TBranch        *b_primaries_vx_gamma;   //!
   TBranch        *b_primaries_vy_gamma;   //!
   TBranch        *b_primaries_vz_gamma;   //!
   
   TBranch        *b_Primaries_Nprimaries;   //!
   TBranch        *b_Primaries_PID;   //!
   TBranch        *b_Primaries_genflag;   //!
   TBranch        *b_Primaries_Px;   //!
   TBranch        *b_Primaries_Py;   //!
   TBranch        *b_Primaries_Pz;   //!
   TBranch        *b_Primaries_vx;   //!
   TBranch        *b_Primaries_vy;   //!
   TBranch        *b_Primaries_vz;   //!
   TBranch        *b_Primaries_M;   //!
   TBranch        *b_Primaries_E;   //!
   TBranch        *b_Primaries_P;   //!
   TBranch        *b_Primaries_t;   //!
   TBranch        *b_Primaries_theta;   //!
   TBranch        *b_Primaries_phi;   //!


   g4sbs_tree(TTree *tree=0, int det_opt = 0, bool pythia = false, bool ecalbox = false, bool hcalbox = false);
   virtual ~g4sbs_tree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntries();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

private:
   void SetupDetBranch(TSBSGeant4::VDetData_t &det, const char* prefix);
};

#endif



