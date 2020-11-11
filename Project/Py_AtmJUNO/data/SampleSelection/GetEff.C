#include <TChain.h>
#include <TFile.h>
#include <fstream>

#define SGD1 "/storage/gpfs_data/juno/junofs/production/public/users/sgiulio/J18v1r1-Pre1/Atmospheric/0-20GeV/detsim/"

void AddUserFile2TChain(TChain &tree, int NFiles = 1, int startFile = 1)
{
    for (int i = startFile; i < startFile + NFiles; i++)
    {
        tree.Add(Form("%suser-detsim-%d.root", SGD1, i));
        // tree.Add(Form("%s%d.root", HXD1, i));
    }
}

void OutEvtNUM(int NFiles = 1, int StartFile = 1);

//get total number of muCC, eCC and NC events.
int GetEff(int NFiles = 1, int StartFile = 1)
{
    OutEvtNUM(NFiles, StartFile);
    return 0;
}
void OutEvtNUM(int NFiles, int StartFile)
{
    TChain geninfo("geninfo");
    AddUserFile2TChain(geninfo, NFiles, StartFile);
    geninfo.SetBranchStatus("*", 0);
    geninfo.SetBranchStatus("InitPDGID", 1);
    int muCC_total = geninfo.GetEntries("InitPDGID[0]==13||InitPDGID[0]==-13");
    int eCC_total = geninfo.GetEntries("InitPDGID[0]==11||InitPDGID[0]==-11");
    // int NC_total = geninfo.GetEntries("InitPDGID[0]==||InitPDGID[0]==");
    std::ofstream outfile("TotalEvtNUM.txt", std::ios::app);
    outfile << StartFile << "_" << StartFile + NFiles << ":\t" << eCC_total << "\t" << muCC_total << std::endl;
}
