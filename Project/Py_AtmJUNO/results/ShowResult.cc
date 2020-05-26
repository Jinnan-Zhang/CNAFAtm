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
    ViewEffandCONT();
    return 0;
}

//get exact cuts
void ViewEffandCONT()
{
    TH1::AddDirectory(false);
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
    TH1 *h_Eff_eCC[4];
    TH1 *h_CONT_eCC[4];
    TH1 *h_Eff_muCC[4];
    TH1 *h_CONT_muCC[4];
    //all events number for eCC in each LPMT NPE
    double eCC_all[4];
    //all events number for muCC in each LPMT NPE
    double muCC_all[4];
    //all events
    TH1 *h_all[4];
    for (int i = 0; i < 4; i++)
    {

        eCC_all[i] = h_eCC[i]->Integral();
        muCC_all[i] = h_muCC[i]->Integral();
        h_CONT_eCC[i] = (TH1 *)h_muCC[0]->Clone("Contamination");
        h_Eff_eCC[i] = (TH1 *)h_muCC[0]->Clone("Efficiency");
        h_CONT_muCC[i] = (TH1 *)h_muCC[0]->Clone("Contamination");
        h_Eff_muCC[i] = (TH1 *)h_muCC[0]->Clone("Efficiency");
        h_all[i] = (TH1 *)h_muCC[0]->Clone("AllEvents");
        h_all[i]->Add(h_eCC[i], h_muCC[i]);
        h_all[i]->Add(h_NC[i]);
        h_CONT_eCC[i]->SetYTitle("");
        h_Eff_eCC[i]->SetYTitle("");
        h_CONT_muCC[i]->SetYTitle("");
        h_Eff_muCC[i]->SetYTitle("");
        h_CONT_eCC[i]->SetLineColor(kRed);
        h_CONT_eCC[i]->SetLineWidth(4);
        h_Eff_eCC[i]->SetLineColor(kBlue);
        h_Eff_eCC[i]->SetLineWidth(4);
        h_CONT_muCC[i]->SetLineColor(kRed);
        h_CONT_muCC[i]->SetLineWidth(4);
        h_Eff_muCC[i]->SetLineColor(kBlue);
        h_Eff_muCC[i]->SetLineWidth(4);
    }
    //obseved event number in current cut range
    //1st 4 for e, cut under. 2nd 4 for mu ,cut above
    double Ob_range[8];
    double muCC_in[4], eCC_in[4];
    double Eff_mu = 0, CONT_mu = 0;
    double Eff_e = 0, CONT_e = 0;

    for (int j = 0; j < h_Eff_eCC[0]->GetNbinsX(); j++)
    {
        for (int i = 0; i < 4; i++)
        {
            Ob_range[i] = 0;
            eCC_in[i] = h_eCC[i]->Integral(1, j + 1);
            muCC_in[i] = h_muCC[i]->Integral(j + 1, 500);
            // Ob_range[i] += eCC_in[i];
            // Ob_range[i] += muCC_in[i];
            // Ob_range[i] += h_NC[i]->Integral(1, j + 1);
            Ob_range[i] = h_all[i]->Integral(1, j + 1);
            Ob_range[i + 4] = h_all[i]->Integral(j + 1, 500);
            if (Ob_range[i] == 0)
                Ob_range[i] = 1;
            if (Ob_range[i + 4] == 0)
                Ob_range[i + 4] = 1;
            Eff_e = eCC_in[i] / eCC_all[i];
            CONT_e = 1 - eCC_in[i] / Ob_range[i];
            Eff_mu = muCC_in[i] / muCC_all[i];
            CONT_mu = 1 - muCC_in[i] / Ob_range[i + 4];
            h_Eff_eCC[i]->SetBinContent(j + 1, Eff_e);
            h_CONT_eCC[i]->SetBinContent(j + 1, CONT_e);
            h_Eff_muCC[i]->SetBinContent(j + 1, Eff_mu);
            h_CONT_muCC[i]->SetBinContent(j + 1, CONT_mu);
        }
    }
    // TCanvas *cs[8];
    // TLegend leg[8];
    // for (int i = 0; i < 4; i++)
    // {
    //     cs[i] = new TCanvas(Form("c%d", i));
    //     leg[i].AddEntry(h_Eff_muCC[i], "Efficiency");
    //     leg[i].AddEntry(h_CONT_muCC[i], "Contamination");
    //     cs[i]->cd();
    //     h_Eff_muCC[i]->SetTitle(CutConditions[i] + ": #nu_{#mu}");
    //     h_Eff_muCC[i]->Draw();
    //     h_CONT_muCC[i]->Draw("SAME");
    //     leg[i].DrawClone("SAME");

    //     // cs[i+4]=new TCanvas(Form("c%d",i+4));
    //     // cs[i+4]->cd();
    //     // leg[i+4].AddEntry(h_Eff_eCC[i],"Efficiency");
    //     // leg[i+4].AddEntry(h_CONT_eCC[i],"Contamination");
    //     // h_Eff_eCC[i]->SetTitle(CutConditions[i]+": #nu_{e}");
    //     // h_Eff_eCC[i]->Draw();
    //     // h_CONT_eCC[i]->Draw("SAME");
    //     // leg[i+4].DrawClone("SAME");
    // }
    double e_CC_cut=76;
    double mu_CC_cut=115;
    printf("%.1f ns eCC:EFF: %f\tCONT: %f\n",e_CC_cut,h_Eff_eCC[0]->Interpolate(e_CC_cut),h_CONT_eCC[0]->Interpolate(e_CC_cut));
    printf("%.1f ns muCC:EFF: %f\tCONT: %f\n",mu_CC_cut,h_Eff_muCC[2]->Interpolate(mu_CC_cut),h_CONT_muCC[2]->Interpolate(mu_CC_cut));
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