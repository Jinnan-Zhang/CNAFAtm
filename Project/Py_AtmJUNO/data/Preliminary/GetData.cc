#include <TFile.h>
#include <TTree.h>
#include <TChain.h>

void ShowEvtNUM();

int GetData()
{
    ShowEvtNUM();
    return 0;
}

//show the event number of different type
void ShowEvtNUM()
{
    // TChain evt("evt");
    TChain geninfo("geninfo");
    for (int i = 0; i < 65; i++)
    {
        // evt.Add(Form("/storage/gpfs_data/juno/junofs/production/public/users/sgiulio/J18v1r1-Pre1/Atmospheric/0-20GeV/detsim/user-detsim-%d.root", i + 5001));
        geninfo.Add(Form("/storage/gpfs_data/juno/junofs/production/public/users/sgiulio/J18v1r1-Pre1/Atmospheric/0-20GeV/detsim/user-detsim-%d.root", i + 5001));
    }

    // evt.SetBranchStatus("*", 0);
    geninfo.SetBranchStatus("*", 0);
    geninfo.SetBranchStatus("InitPDGID", 1);
    int InitPDGID[10];
    geninfo.SetBranchAddress("InitPDGID", InitPDGID);
    int NUM_muCC = 0;
    for (int i = 0; i < geninfo.GetEntries(); i++)
    {
        geninfo.GetEntry(i);
        if (InitPDGID[0] == 13 || InitPDGID[0] == -13)
            NUM_muCC++;
    }
    printf("muCC total:%d\n", NUM_muCC);
}