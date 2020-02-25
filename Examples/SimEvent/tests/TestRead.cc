#include <TFile.h>
#include <TTree.h>
#include <TROOT.h>

#include <iostream>
#include <vector>

#include <Event/SimHeader.h>

int TestRead()
{
    TFile *f=TFile::Open("/storage/gpfs_data/juno/junofs/production/public/users/sgiulio/J18v1r1-Pre1/Atmospheric/0-20GeV/detsim/user-detsim-1000.root","READ");
    TTree* tree_hdr = (TTree*)f->Get("Event/Sim/SimHeader");
    TTree* tree_evt = (TTree*)f->Get("Event/Sim/SimEvent");
    JM::SimHeader* sh7 = 0;
    JM::SimEvent* se7 = 0;
    tree_hdr->SetBranchAddress("SimHeader", &sh7);
    tree_evt->SetBranchAddress("SimEvent", &se7);
    tree_hdr->GetBranch("SimHeader")->SetAutoDelete(true);
    tree_evt->GetBranch("SimEvent")->SetAutoDelete(true);
    tree_hdr->Print();
    tree_evt->Print();

    return 0;
    // tree_evt->GetEntry(1);


}