
#include "TObject.h"
#include <vector>
#include <iostream>
#include <TFile.h>
#include <TChain.h>
#define SGD1 "/storage/gpfs_data/juno/junofs/production/public/users/sgiulio/J18v1r1-Pre1/Atmospheric/0-20GeV/detsim/detsim-"
#include "Event/SimPMTHit.h"


void AddDetsimFile2TChain(TChain &tree, int NFiles = 1, int startFile = 1)
{
    for (int i = startFile; i < startFile + NFiles; i++)
    {
        tree.Add(Form("%s%d.root", SGD1, i));
    }
}
int Wphits()
{
    TChain SimEvent("Event/Sim/SimEvent");
    AddDetsimFile2TChain(SimEvent);

    std::vector<SimPMTHit *> m_wp_hits = {0};
    TBranch *brWp = 0;
    SimEvent.SetBranchAddress("SimEvent.m_wp_hits", &m_wp_hits, &brWp);
    SimEvent.SetCacheSize(10000000);
    SimEvent.AddBranchToCache("SimEvent.m_wp_hits");
    brWp->GetEntry(1);
    printf("wpPe:%d\n", m_wp_hits[0]->getNPE());

    return 0;
}
