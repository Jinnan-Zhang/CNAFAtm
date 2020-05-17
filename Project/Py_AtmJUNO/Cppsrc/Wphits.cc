
#include "TObject.h"
#include <vector>
#include <iostream>
#include <TFile.h>
#include <TChain.h>
#define SGD1 "/storage/gpfs_data/juno/junofs/production/public/users/sgiulio/J18v1r1-Pre1/Atmospheric/0-20GeV/detsim/detsim-"
#include "Event/SimPMTHit.h"
#include "Event/SimEvent.h"
#include "Event/SimHeader.h"


void AddDetsimFile2TChain(TChain &tree, int NFiles = 1, int startFile = 1)
{
    for (int i = startFile; i < startFile + NFiles; i++)
    {
        tree.Add(Form("%s%d.root", SGD1, i));
    }
}
int Wphits()
{
    TChain SimEvent1("Event/Sim/SimEvent");
    AddDetsimFile2TChain(SimEvent1);
    JM::SimHeader* sh7 = 0;
    JM::SimEvent* se7 = 0;
    SimEvent1.SetBranchAddress("SimEvent",&se7);
    SimEvent1.GetBranch("SimEvent")->SetAutoDelete(true);
    
    SimEvent1.GetEntry(0);
    int totalpe=0;
    const std::vector<JM::SimPMTHit*> hits = se7->getWPHitsVec();
    for (std::vector<JM::SimPMTHit*>::const_iterator it = hits.begin();
                it != hits.end(); ++it) {

            JM::SimPMTHit* hit = *it;
            totalpe += hit->getNPE();
        }

    return 0;
}
