
#include <TObject.h>
#include <vector>
#include <iostream>
#include <TFile.h>
#include <TChain.h>
#include <fstream>
// #include "Event/SimPMTHit.h"
// #include "Event/SimEvent.h"
// #include "Event/SimHeader.h"
#define SGD1 "/storage/gpfs_data/juno/junofs/production/public/users/sgiulio/J18v1r1-Pre1/Atmospheric/0-20GeV/detsim/detsim-"
#define HXD "/junofs/users/huangx/production/J19v1r0-Pre3bk/IBD/uniform/IBD/detsim/user-detsim-"
#define HXD1 "/junofs/users/huangx/production/J19v1r0-Pre3bk/IBD/uniform/IBD/detsim/detsim-"

void AddDetsimFile2TChain(TChain &tree, int NFiles = 1, int startFile = 1)
{
    for (int i = startFile; i < startFile + NFiles; i++)
    {
        tree.Add(Form("%s%d.root", SGD1, i));
        // tree.Add(Form("%s%d.root", HXD1, i));
    }
}
int Wphits()
{
    TChain SimEvent1("Event/Sim/SimEvent");
    AddDetsimFile2TChain(SimEvent1);
    // JM::SimHeader* sh7 = 0;
    JM::SimEvent *se7 = 0;
    SimEvent1.SetBranchAddress("SimEvent", &se7);
    SimEvent1.GetBranch("SimEvent")->SetAutoDelete(true);
    int totalpe = 0;
    for (int entry = 0; entry < SimEvent1.GetEntries(); entry++)
    {
        SimEvent1.GetEntry(entry);
        const std::vector<JM::SimPMTHit *> hits = se7->getWPHitsVec();
        for (std::vector<JM::SimPMTHit *>::const_iterator it = hits.begin();
             it != hits.end(); ++it)
        {
            JM::SimPMTHit *hit = *it;
            totalpe += hit->getNPE();
        }
    }
    printf("totalPE:%d\n", totalpe);
    return 0;
}
