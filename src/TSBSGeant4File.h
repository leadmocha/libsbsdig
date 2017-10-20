#ifndef __TSBSGEANT4FILE_H
#define __TSBSGEANT4FILE_H

// Put prototypes here first so that it doens't freak out
#ifndef __CINT__
#include "evioUtil.hxx"
#endif//__CINT__

#include "TROOT.h"
#include "TFile.h"
#include "TChain.h"
#include "g4sbs_tree.h"
#include "TSBSCherData.h"
#include "TSBSDBManager.h"

#define __DEFAULT_DATA_SIZE 32

////////////////////////////////////////////////////////////////////////////
// Auxilliary class for storing hit data
//
// Stores an arbitrary double data in dynamically allocated
// arrays.  Allows us to add in data as we get it and then check
// to make sure all entries in the array are filled
// // ___________________________________________________________ //
// // hit_data: {PMT row, PMT column, 
// //            N_pe, t,
// //            pdetx, pdety, pdetz, 
// //            Xdetx, Xdety, Xdetz, 
// //            type, 
// //            pprodx, pprody, pprodz, 
// //            Xprodx, Xprody, Xprodz,
// //            OrigVolFlag};
// // the strucutre of the data array is identical to the structure 
// // of the hitdata array defined in TSolEVIOFile class

class g4sbshitdata {
    public:
        //Default constructor. 
  	g4sbshitdata( int detid, unsigned int size = __DEFAULT_DATA_SIZE );
	virtual ~g4sbshitdata();
	
	//Get detector ID
	int     GetDetID() const { return fDetID;}

	// Get/set one specific element of the data for this hit
	void    SetData( unsigned int, double );
	double  GetData( unsigned int ) const ;
	double *GetData(){ return fData; }//Get all data array 
	
	bool    IsFilled() const ;
	
    protected:
	int     fDetID;//detector ID
	unsigned int     fSize;//data array size;
	long long int fFillbits;
	double *fData;//data array: See in .cxx the sequence of this data array for g4sbs GRINCH/RICH
};

////////////////////////////////////////////////////////////////////////////
// Auxilliary class for storing generated track data
// // ___________________________________________________________ //
// // gendata: {type, 
// //           pprodx, pprody, pprodz, 
// //           Xprodx, Xprody, Xprodz,
// //           OrigVolFlag, weight};
// // the strucutre of this data array is identical to the structure 
// // of the gendata array defined in TSolEVIOFile class

class g4sbsgendata : public g4sbshitdata {
    public:
	g4sbsgendata();
	~g4sbsgendata(){;}
	
	int	GetTRID() const { return IsFilled()? (int) fData[0] : -1e9; }//G4 particle ID
	int	GetPID() const { return IsFilled()? (int) fData[1] : -1e9; }//G4 particle ID
	double  GetWeight() const { return fData[8]; }//cross section
	TVector3 GetP() const { return IsFilled()? TVector3(fData[2], fData[3], fData[4]) : TVector3(-1e9, -1e9, -1e9 ); }//Track momentum 3-vector
	TVector3 GetV() const { return IsFilled()? TVector3(fData[5], fData[6], fData[7]) : TVector3(-1e9, -1e9, -1e9 ); }//Track vtx 3-vector
};


///////////////////////////////////////////////////////////////////////////////


class TSBSGeant4File {

 public:
  //constructor may be inputed a data file to input some of the paramaters used by this class
  //NB: if the second file path does not select a valid file, default parameters will be used.
  TSBSGeant4File();// Default constructor
  TSBSGeant4File( const char *name);// Constructor with input file name: recommanded
  virtual ~TSBSGeant4File();// Default destructor

  //void ReadGasData(const char* filename); // NB: See comment lines 128-129 
  
  // Standard getters and setters
  void  SetFilename( const char *name );
  void  SetSource( Int_t i ) { fSource = i; }
  void  Clear();
  Int_t Open();
  Int_t Close();
  
  const Long64_t GetEntries(){
    return fTree->GetEntries();
  };
  
  const char* GetFileName() const { return fFilename; }
  Int_t GetSource() const { return fSource; }
  
  // This is actually where the data is read: 
  Int_t ReadNextEvent(int d_flag = 0);
  
  //return the size of the hit arrays
  UInt_t GetNData() const { return fg4sbsHitData.size(); }
  UInt_t GetNGen() const { return fg4sbsGenData.size(); }
  
  UInt_t GetEvNum() const { return fEvNum; }
  
  //get one hit from the hit data arrays
  g4sbshitdata *GetHitData(Int_t i) const { return fg4sbsHitData[i]; }
  g4sbsgendata *GetGenData(Int_t i) const { return fg4sbsGenData[i]; }
  
  //get GEM data
  TSBSCherData *GetCherData();
  void GetCherData(TSBSCherData* gd);
  
 private:
  // Members
  char  fFilename[255];
  TFile *fFile;
  g4sbs_tree *fTree;// needed to easily unfold root file data
  Int_t fSource;   // User-defined source ID (e.g. MC run number)  
  
  //hit data arrays
  vector<g4sbshitdata *> fg4sbsHitData;
  vector<g4sbsgendata *> fg4sbsGenData;
  
  unsigned int fEvNum;// global event incrementer

  TSBSDBManager *fManager;
};



#endif//__TSOLSIMG4SBSFILE_H
