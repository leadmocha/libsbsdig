libsbscer library:

The purpose of this library is to digitize the Cherenkov detectors output from G4SBS.
This can be done with no significant modifications of G4SBS, 
provided that the hit time dispersion is small (<1 ns).

The list of classes and their functions are the following: 

g4sbs_tree: 
Unfolds the G4SBS file data tree; used by class TSBSGeant4File.

TSBSGeant4File: 
Reads the G4SBS output to extract the useful data for the digitization of the selected Cherenkov detector.
This data will be stored by an instance of class TSBSCherData, 
and will be used by class TSBSSimCherDigitization.cxx.

TSBSCherData: 
Constitutes the internal data container for the library;
The structure of the data stored is the following:

    UInt_t    fDetID;          // Hit Detector (if many)
    UInt_t    fPMTID;          // Hit PMT
    Double_t  fXPMT;           // X coordinate of the PMT in transport coordinates
    Double_t  fYPMT;           // Y coordinate of the PMT in transport coordinates
    Double_t  fNpe;            // Number of photoelectrons
    Double_t  fTime;           // hit time
    Double_t  fTimeRMS;        // hit time RMS: should be small (<0.1 ns)
    UInt_t    fType;           // particle type: 1 = primary, >1 secondaries
    TVector3  fPos_det;        // position of the optical photon at detection
    Int_t     fPID_MCtrack;    // Particle ID of the MC particle which produced the hit (*)
    TVector3  fMom_MCtrack;    // momentum of the MC particle which produced the hit (*)
    TVector3  fVtx_MCtrack;    // vertex of the MC particle which produced the hit (*)
    UInt_t    fOriginVolFlag;  // origin volume of the photon
    //  (*) valid if MC track is identified (OriginVolFlag !=4)

Note the first 5 parameters are essential for the digitization itself,
the other are just useful complementary MC information.

TSBSSimCherDigitization:
This is the core class of the library: it performs the digitization of the Cherenkov data. 
It produces the following output:

    std::vector< std::pair<TArrayI, TArrayI> > fTDCArrays;     
    // TDC digital value output arrays (1st array: rise time, 2nd array: fall time)
    std::vector< std::pair<TArrayD, TArrayD> > fTDCtimeArrays; 
    // TDC "input" time values (evaluated with the PMT pulse shape)

These values are then fed to an instance of class TSBSSimEvent, 
which holds the data structure to fill the output file.

TSBSSimEvent:
Holds the data structure to fill the output file. 
The data structure is the following: 

    Int_t     fRunID;               // Run number
    Int_t     fEvtID;               // Event number
    Double_t  fWeight;              // Event weight
    Int_t     fNSignal;             // Number of clusters from signal
    TClonesArray*   fMCTracks;      //-> Physics tracks
    std::vector< std::pair< Int_t, std::vector<Short_t> > > fMCClusterHitID;
    // collections of hit IDs coming from the same MC track ID
    // save only clusters with size >= 2
    struct PMTHit {
    // MC hit data
      Short_t  fID;          // Hit number
      Int_t    fSource;      // MC data set source (0 = signal, >0 background)
      Int_t    fType;        // GEANT particle type (1 = primary)
      Int_t    fMCtrackPID;  // GEANT particle ID (if any)
      Short_t  fOrigVolFlag; // 
      Float_t  fXPMT;        // X coordinate of the PMT in transport coordinates
      Float_t  fYPMT;        // Y coordinate of the PMT in transport coordinates
      Float_t  fNpe;         // Number of photoelectrons
      Double_t fTime;        // Arrival time at electronics
      Double_t fTDCtime[2];  // TDC rising and falling times values wrt trigger time
      // Digitization results for this hit
      Short_t  fDetID;       // Detector ID
      Short_t  fChannel;     // Channel number
        Short_t  fPMTrow;      // Row number: cross reference to Channel number
      Short_t  fPMTcol;      // Column number: cross reference to Channel number
      uint32_t fTDC[2];      // TDC VETROC words
    };
    std::vector<PMTHit> fPMTHits;

Auxilliary classes:

TSBSDBManager:
Useful class to unfold the databases and manage the parameters stored in them:
General parameters for DB:

    //variable for data base information
    int fNPMTs;        // number of PMTs
    int fNPMTrows;     // number of PMT rows
    int fNPMTcolsmax;  // max number of PMT columns 
    // (PMTs staggered with fNPMTcolsmax rows and fNPMTcolsmax-1 rows)
    //  o o o o 
    // o o o o o -> would be fNPMTcolsmax
    //  o o o o
    int fChanPerSlot;  // number of PMTs per slot
  
    // Parameters for TSBSGeant4File
    int fg4sbsDetectorType;// flag to determine which type of GEM should be read.
    //Choices are: 1 - GRINCH
    //Choices are: 2 - RICH
  
    // Parameters for signal particles
    int fNSigParticle; // number of signal particles
    vector<int>    fSigPID;
    vector<int>    fSigTID;
  
    //container for geometry parameters
    vector<GeoInfo> fGeoInfo;


TSBSSimDecoder:
Interprets event buffer from input as TSBSSimEvent objects
(containing digitized simulation data) and unpacks them into
crateslot arrays for low-level decoding by detectors.

TSBSCher:
Detector class; contains the detector geometry (in this case the PMT matrix gemoetry):

    int    fNPMTs;         // number of PMTs
    int    fNPMTrows;      // number of PMT rows
    int    fNPMTcolsMax;   // max number of PMT columns 
    double fPMTmatrixHext; // horizontal extension, in m, of the PMT matrix (from lower PMT center to higher PMT center)
    double fPMTmatrixVext; // vertical extension, in m, of the PMT matrix (from left PMT center to right PMT center)
    double fPMTdistX;      // projected X distance between the center of 2 PMT tubes in consecutive rows, in m
    double fPMTdistY;      // Y distance between the center of 2 PMT tubes in consecutive columns, in m
    double fX_TCPMT;       // X position of the top close PMT center in the PMT matrix (transport coord)
    double fY_TCPMT;       // Y position of the top close PMT center in the PMT matrix (transport coord)

it uses its own database.

TSBSSpec:
Spectrometer class to "carry" the detector. 
Likely, it will be pretty similar to the class with the same name in liblibsolgem/libsbsgem.


