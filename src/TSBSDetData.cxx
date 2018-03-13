#include <iostream>

#include "TSBSDetData.h"

using namespace std;

TSBSDetData::TSBSDetData (UInt_t h)
{
  fHitData->Expand(h);
}

TSBSDetData::~TSBSDetData()
{
}

void
TSBSDetData::ClearEvent() 
{
  fHitData->Clear();
};

void
TSBSDetData::InitEvent (UInt_t h)
{
  if (h <= 0)
    return;

  fHitData->Expand(h);
}

void 
TSBSDetData::Print() const
{
  cout << "Run " << GetRun() << " Event " << GetEvent() << " " << GetNHit() << " hits" << endl;
}

void 
TSBSDetData::PrintHit (UInt_t k) const
{
}
