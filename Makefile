#------------------------------------------------------------------------------
include Makefile.arch

#------------------------------------------------------------------------------

NAME    := libsbsdig

SOLINCLUDE := -I$(shell pwd)/src

#------------------------------------------------------------------------------
# Hall A Analyzer

# Analyzer default location,
ANALYZER ?= $(HOME)/ANALYZER
# Possible Analyzer header locations, will be used in the order found
ANAINCDIRS  := $(wildcard $(addprefix $(ANALYZER)/, include src hana_decode hana_scaler))
ifeq ($(strip $(ANAINCDIRS)),)
  $(error No Analyzer header files found. Check $$ANALYZER)
endif


#------------------------------------------------------------------------------
# EVIO

PLATFORM = $(shell uname -s)-$(shell uname -i)
# EVIO default locations as a last resort if $EVIO isn't set in build env
EVIO ?= $(CODA)
EVIO ?= ../libevio
# Possible EVIO header directories, will be used in the order found
EVIOINC := $(wildcard $(addprefix $(EVIO)/, include src/libsrc src/libsrc++))
# Possible EVIO library locations, the first one found will be used
EVIOLIB := $(firstword $(wildcard $(addprefix $(EVIO)/, $(PLATFORM)/lib lib)))
ifeq ($(strip $(EVIOINC)),)
  $(error No EVIO header files found. Check $$EVIO)
endif
ifeq ($(strip $(EVIOLIB)),)
  $(error No EVIO library directory found. Check $$EVIO)
endif
ifeq (debug,$(findstring debug,$(ROOTBUILD)))
  DBGSFX = -dbg
  CXXFLAGS += -O0
else
  CXXFLAGS += -O2 #-DNDEBUG
endif
SOLINCLUDE += $(addprefix -I, $(EVIOINC) )
LDFLAGS  += -L$(EVIOLIB) -levioxx$(DBGSFX) -levio$(DBGSFX) -lz -lexpat

# Some of the analyzer include dirs conflict with headers in
# EVIO
SOLINCLUDE += $(addprefix -I, $(ANAINCDIRS) )

#------------------------------------------------------------------------------

CXXFLAGS += $(SOLINCLUDE)

DICT	= $(NAME)_dict
SRC   = src/g4sbs_tree.cxx \
        src/TSBSCher.cxx \
        src/TSBSCherData.cxx \
        src/TSBSDet.cxx \
        src/TSBSDetData.cxx \
        src/TSBSDBManager.cxx \
        src/TSBSGeant4File.cxx \
        src/TSBSSimCherDigitization.cxx \
        src/TSBSSimDecoder.cxx \
        src/TSBSSimEvent.cxx \
        src/TSBSSimFile.cxx \
        src/TSBSSpec.cxx
#        src/TSBSSimDetDigitization.cxx \


OBJS	= $(SRC:.cxx=.$(ObjSuf)) $(DICT).o
HDR	= $(SRC:.cxx=.h) src/Linkdef.h
ROHDR	= $(SRC:.cxx=.h) src/Linkdef.h

LIBSBSDIG	= libsbsdig.so

PROGRAMS	= $(LIBSBSDIG)

all:	$(PROGRAMS)

$(LIBSBSDIG):	$(OBJS)
	$(LD) $(SOFLAGS) $^ -o $@ $(LDFLAGS) 

clean:
	@rm -f $(OBJS) $(PROGRAMS) *dict.*

$(DICT).cxx: $(ROHDR) 
	$(ROOTCINT) -f $@ -c $(SOLINCLUDE) $^ 

%.$(ObjSuf): %.$(SrcSuf)
	$(CXX)  $(CXXFLAGS) -c -o $@ $<
