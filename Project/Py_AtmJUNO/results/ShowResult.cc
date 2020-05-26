/*
Show the preliminary results
author: Jinnan Zhang:Jinnan.Zhang@ihep.ac.cn
*/
#include <vector>
#include <TH1.h>
#include <TF1.h>
#include <TGraph.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <iostream>
#include <TString.h>
using namespace std;

void ViewFlavor();

int ShowResult()
{
    return 0;
}
void ViewFlavor()
{
    TString PreFileName = "result10.root";
    TH1::AddDirectory(false);
    TFile *ff_flavor = TFile::Open(PreFileName, "READ");
    TH1 *h_muCC[4], *h_eCC[4], *h_NC[4];
    for(int i=0;i<4;i++)
    {
        h_muCC[i]=(TH1*)ff_flavor->Get(Form("muCC%d",i));
        h_eCC[i]=(TH1*)ff_flavor->Get(Form("eCC%d",i));
        h_NC[i]=(TH1*)ff_flavor->Get(Form("NC%d",i));
        h_muCC[i]->SetXTitle("#sigma(t_{res}) [ns]");
        h_muCC[i]->SetYTitle("entries");
        h_eCC[i]->SetXTitle("#sigma(t_{res}) [ns]");
        h_eCC[i]->SetYTitle("entries");
        h_NC[i]->SetXTitle("#sigma(t_{res}) [ns]");
        h_NC[i]->SetYTitle("entries");
    }
    

}