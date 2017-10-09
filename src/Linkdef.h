#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclasses;

#pragma link C++ defined_in "src/g4sbs_tree.h";
#pragma link C++ defined_in "src/TSBSCherData.h";
#pragma link C++ defined_in "src/TSBSDBManager.h";
#pragma link C++ defined_in "src/TSBSGeant4File.h";
#pragma link C++ defined_in "src/TSBSSimDecoder.h";
#pragma link C++ defined_in "src/TSBSSimEvent.h";
#pragma link C++ defined_in "src/TSBSSimCherDigitization.h";
#pragma link C++ defined_in "src/TSBSSpec.h";

// Limited stuff in EVIO file.  We don't want to be
// able to call the evio functions in the interpreter

#endif
