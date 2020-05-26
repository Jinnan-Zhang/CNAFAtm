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
#include <TROOT.h>
using namespace std;

void ViewFlavor();
void ViewEffandCONT();

int ShowResult()
{
    // ViewFlavor();
    return 0;
}

//get exact cuts
void ViewEffandCONT()
{
    TString PreFileName = "result10.root";
    TFile *ff_flavor = TFile::Open(PreFileName, "READ");
    TH1 *h_muCC[4], *h_eCC[4], *h_NC[4];
    Color_t mueN[] = {
        kBlue,
        kRed,
        kGreen};
    for (int i = 0; i < 4; i++)
    {
        h_muCC[i] = (TH1 *)ff_flavor->Get(Form("muCC%d", i));
        h_eCC[i] = (TH1 *)ff_flavor->Get(Form("eCC%d", i));
        h_NC[i] = (TH1 *)ff_flavor->Get(Form("NC%d", i));
        h_muCC[i]->SetXTitle("#sigma(t_{res}) [ns]");
        h_muCC[i]->SetYTitle("entries");
        h_muCC[i]->SetLineColor(mueN[0]);
        h_eCC[i]->SetXTitle("#sigma(t_{res}) [ns]");
        h_eCC[i]->SetYTitle("entries");
        h_eCC[i]->SetLineColor(mueN[1]);
        h_NC[i]->SetXTitle("#sigma(t_{res}) [ns]");
        h_NC[i]->SetYTitle("entries");
        h_NC[i]->SetLineColor(mueN[2]);
    }
    TString CutConditions[] = {
        "10^{5}<NPE_{LPMT}<4.73#times10^{5}",
        "4.73#times10^{5}<NPE_{LPMT}<1.01#times10^{6}",
        "1.01#times10^{6}<NPE_{LPMT}<2.32#times10^{6}",
        "NPE_{LPMT}>2.32#times10^{6}"};
    
    
}
void ViewFlavor()
{
    TString PreFileName = "result10.root";
    TH1::AddDirectory(false);
    TFile *ff_flavor = TFile::Open(PreFileName, "READ");
    TH1 *h_muCC[4], *h_eCC[4], *h_NC[4];
    Color_t mueN[] = {
        kBlue,
        kRed,
        kGreen};
    for (int i = 0; i < 4; i++)
    {
        h_muCC[i] = (TH1 *)ff_flavor->Get(Form("muCC%d", i));
        h_eCC[i] = (TH1 *)ff_flavor->Get(Form("eCC%d", i));
        h_NC[i] = (TH1 *)ff_flavor->Get(Form("NC%d", i));
        h_muCC[i]->SetXTitle("#sigma(t_{res}) [ns]");
        h_muCC[i]->SetYTitle("entries");
        h_muCC[i]->SetLineColor(mueN[0]);
        h_eCC[i]->SetXTitle("#sigma(t_{res}) [ns]");
        h_eCC[i]->SetYTitle("entries");
        h_eCC[i]->SetLineColor(mueN[1]);
        h_NC[i]->SetXTitle("#sigma(t_{res}) [ns]");
        h_NC[i]->SetYTitle("entries");
        h_NC[i]->SetLineColor(mueN[2]);
    }
    // h_muCC[0]->Draw();
    TString CutConditions[] = {
        "10^{5}<NPE_{LPMT}<4.73#times10^{5}",
        "4.73#times10^{5}<NPE_{LPMT}<1.01#times10^{6}",
        "1.01#times10^{6}<NPE_{LPMT}<2.32#times10^{6}",
        "NPE_{LPMT}>2.32#times10^{6}"};
    TCanvas *cs[5];
    TLegend leg[5];
    for (int i = 0; i < 4; i++)
    {
        cs[i] = new TCanvas(CutConditions[i]);
        cs[i]->cd();
        leg[i].AddEntry(h_muCC[i], "#nu_{#mu} CC");
        leg[i].AddEntry(h_eCC[i], "#nu_{e} CC");
        leg[i].AddEntry(h_NC[i], "NC");
        h_muCC[i]->SetTitle(CutConditions[i]);
        h_muCC[i]->SetAxisRange(40, 200, "X");
        h_muCC[i]->SetLineWidth(4);
        h_eCC[i]->SetLineWidth(4);
        h_NC[i]->SetLineWidth(4);
        h_muCC[i]->Draw();
        h_eCC[i]->Draw("SAME");
        h_NC[i]->Draw("SAME");
        leg[i].DrawClone("SAME");
    }
}