/*
Show the preliminary results
author: Jinnan Zhang:Jinnan.Zhang@ihep.ac.cn
*/
#include <vector>
#include <TObject.h>
#include <TH1.h>
#include <TH2.h>
#include <TF1.h>
#include <TGraph.h>
#include <TFile.h>
#include <TChain.h>
#include <TTree.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <TString.h>
#include <TROOT.h>
#include <TLine.h>
#include <TString.h>
using namespace std;

//in ns, muCC eCC
const double Cut_sigma_tres_Sg_muCC = 112;
const double Cut_sigma_tres_Sg_eCC = 86;
// muCC then eCC
const double Cut_NPE_low_Sg[2] = {5e5, 1e5};
const double Cut_NPE_up_Sg[2] = {1.585e7, 1.585e7};
const int NPE_BINNUM_eCC = 7;
const int NPE_BINNUM_muCC = 8;
const int Etrue_BINNUM_eCC = 7;
const int Etrue_BINNUM_muCC = 7;
double logNPE_range_eCC[2] = {5, 7.2};
double logNPE_range_muCC[2] = {5.7, 7.2};
double logEtrue_range_eCC[2] = {-1, 1.05};
double logEtrue_range_muCC[2] = {-0.3, 1.05};

void ViewFlavor();
void ViewEffandCONT();
void ForAllPEs();
void GetObjFromFile(TFile *File, TH1 *h[], TString ObjNames[], int NUMObj);
void LoadFile(std::string filename, std::vector<std::vector<double>> &v, int Length = 2, int SkipLines = 0);
void ShowNPE_nd_Cuts();
void ShowContEff(TTree *muCC_NPETresE, TTree *eCC_NPETresE, TTree *NC_NPETresE);
void ShowNPE_Sg_Cuts(bool WithCut = true);
void GetFakeData(TString FileName = "../results/FakeData.root");
const int Expected_evt_NUM_eCC[] = {40, 100, 125, 135, 80, 45, 20};
const int Expected_evt_NUM_muCC[] = {165, 170, 155, 145, 100, 60, 35, 20};

using namespace std;
int ShowResult()
{
    // ViewFlavor();
    // ViewEffandCONT();
    // ForAllPEs();
    ShowNPE_nd_Cuts();
    // ShowNPE_Sg_Cuts();
    return 0;
}

//show the NPE profile
//* @param WithCut: Wherther apply cuts
void ShowNPE_Sg_Cuts(bool WithCut)
{
    TChain muCC_NPETresE("muCC_NPETresE");
    TChain eCC_NPETresE("eCC_NPETresE");
    TChain NC_NPETresE("NC_NPETresE");
    muCC_NPETresE.Add("../results/result_NPETE*.root");
    eCC_NPETresE.Add("../results/result_NPETE*.root");
    NC_NPETresE.Add("../results/result_NPETE*.root");
    //mu,e,NC
    float sigma_tres[3] = {0}, NPE_LPMT[3] = {0}, E_nu_true[3] = {0};
    muCC_NPETresE.SetBranchAddress("sigma_tres", &sigma_tres[0]);
    muCC_NPETresE.SetBranchAddress("NPE_LPMT", &NPE_LPMT[0]);
    muCC_NPETresE.SetBranchAddress("E_nu_true", &E_nu_true[0]);
    eCC_NPETresE.SetBranchAddress("sigma_tres", &sigma_tres[1]);
    eCC_NPETresE.SetBranchAddress("NPE_LPMT", &NPE_LPMT[1]);
    eCC_NPETresE.SetBranchAddress("E_nu_true", &E_nu_true[1]);
    NC_NPETresE.SetBranchAddress("sigma_tres", &sigma_tres[2]);
    NC_NPETresE.SetBranchAddress("NPE_LPMT", &NPE_LPMT[2]);
    NC_NPETresE.SetBranchAddress("E_nu_true", &E_nu_true[2]);

    //mu,e,NC
    Color_t hist_cor[3] = {kBlue, kRed, kGreen};
    TString hist_name[3] = {"#nu_{#mu} CC", "#nu_{e} CC", "#nu_{x} NC"};

    //mu,e,NC
    TH1 *h_NPE_all[3];
    TH1 *h_tres_all[3];
    if (WithCut)
    {
    }
    else
    {
        muCC_NPETresE.Draw("NPE_LPMT>>+h_NPE_mu", "", "goff");
        eCC_NPETresE.Draw("NPE_LPMT>>+h_NPE_e", "", "goff");
        NC_NPETresE.Draw("NPE_LPMT>>+h_NPE_NC", "", "goff");
        h_NPE_all[0] = dynamic_cast<TH1 *>(gDirectory->Get("h_NPE_mu"));
        h_NPE_all[1] = dynamic_cast<TH1 *>(gDirectory->Get("h_NPE_e"));
        h_NPE_all[2] = dynamic_cast<TH1 *>(gDirectory->Get("h_NPE_NC"));

        muCC_NPETresE.Draw("sigma_tres>>+h_tres_mu(1000,0,1000)", "", "goff");
        eCC_NPETresE.Draw("sigma_tres>>+h_tres_e(1000,0,1000)", "", "goff");
        NC_NPETresE.Draw("sigma_tres>>+h_tres_NC(1000,0,1000)", "", "goff");

        h_tres_all[0] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_mu"));
        h_tres_all[1] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_e"));
        h_tres_all[2] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_NC"));

        TCanvas *c_NPE = new TCanvas("cNPE", "", 800, 600);
        TCanvas *c_res = new TCanvas("ctres", "", 800, 600);
        TLegend *leg_NPE = new TLegend();
        TLegend *leg_tres = new TLegend();
        c_NPE->cd();
        h_NPE_all[2]->SetXTitle("NPE_{LPMT}");
        h_NPE_all[2]->SetYTitle("entries");
        h_NPE_all[2]->Draw();
        for (int i = 0; i < 3; i++)
        {
            h_NPE_all[i]->SetLineColor(hist_cor[i]);
            h_tres_all[i]->SetLineColor(hist_cor[i]);
            leg_NPE->AddEntry(h_NPE_all[i], hist_name[i]);
            leg_tres->AddEntry(h_tres_all[i], hist_name[i]);
            h_NPE_all[i]->SetXTitle("NPE_{LPME}");
            h_NPE_all[i]->SetYTitle("entries");
            h_tres_all[i]->SetXTitle("#sigma(t_{res}) [ns]");
            h_tres_all[i]->SetYTitle("entries");
        }
    }
}

//show NPE profile with/without cuts
void ShowNPE_nd_Cuts()
{
    TChain muCC_NPETresE("muCC_NPETresE");
    TChain eCC_NPETresE("eCC_NPETresE");
    TChain NC_NPETresE("NC_NPETresE");
    // muCC_NPETresE.Add("../results/result_NPETE*_100.root");
    // eCC_NPETresE.Add("../results/result_NPETE*_100.root");
    // NC_NPETresE.Add("../results/result_NPETE*_100.root");
    muCC_NPETresE.Add("../results/FakeData.root");
    eCC_NPETresE.Add("../results/FakeData.root");
    NC_NPETresE.Add("../results/FakeData.root");
    //mu,e,NC
    float sigma_tres[3] = {0}, NPE_LPMT[3] = {0}, E_nu_true[3] = {0};
    muCC_NPETresE.SetBranchAddress("sigma_tres", &sigma_tres[0]);
    muCC_NPETresE.SetBranchAddress("NPE_LPMT", &NPE_LPMT[0]);
    muCC_NPETresE.SetBranchAddress("E_nu_true", &E_nu_true[0]);
    eCC_NPETresE.SetBranchAddress("sigma_tres", &sigma_tres[1]);
    eCC_NPETresE.SetBranchAddress("NPE_LPMT", &NPE_LPMT[1]);
    eCC_NPETresE.SetBranchAddress("E_nu_true", &E_nu_true[1]);
    NC_NPETresE.SetBranchAddress("sigma_tres", &sigma_tres[2]);
    NC_NPETresE.SetBranchAddress("NPE_LPMT", &NPE_LPMT[2]);
    NC_NPETresE.SetBranchAddress("E_nu_true", &E_nu_true[2]);
    double Total_mu_eventsNUM = 152073.00;
    double Total_e_eventsNUM = 86731.000;
    double Sigma_cut_muCC = Cut_sigma_tres_Sg_muCC; //ns
    double Sigma_cut_eCC = Cut_sigma_tres_Sg_eCC;   //ns
    double NPE_cut_muCC[2] = {Cut_NPE_low_Sg[0], Cut_NPE_up_Sg[0]};
    double NPE_cut_eCC[2] = {Cut_NPE_low_Sg[1], Cut_NPE_up_Sg[1]};

    TCanvas *c_2dd_eCC = new TCanvas("c_2dd_eCC");
    eCC_NPETresE.Draw("log10(NPE_LPMT):log10(E_nu_true)>>+h_eCC2D(7,-1,1.05,7,5,7.2)", "", "colz");
    // eCC_NPETresE.Draw("log10(NPE_LPMT):log10(E_nu_true)>>+h_eCC2D", "", "colz");
    TCanvas *c_2dd_muCC = new TCanvas("c_2dd_muCC");
    muCC_NPETresE.Draw("log10(NPE_LPMT):log10(E_nu_true)>>+h_muCC2D(7,-0.3,1.05,8,5,7.2)", "", "colz");
    // muCC_NPETresE.Draw("log10(NPE_LPMT):log10(E_nu_true)>>+h_muCC2D", "", "colz");

    //mu,e,NC
    Color_t hist_cor[3] = {kBlue, kRed, kGreen};
    TString hist_name[3] = {"#nu_{#mu} CC", "#nu_{e} CC", "#nu_{x} NC"};
    {
        // TFile *ff_before_cut = TFile::Open("../data/Preliminary/OnlyWPPrompt.root", "RECREATE");

        TH1 *h_NPE_initial[3];
        TH1 *h_NPE_FidCut[3];
        TH1 *h_NPE_allCut[3];
        muCC_NPETresE.Draw("NPE_LPMT>>+h_NPE_initial_mu", "", "goff");
        eCC_NPETresE.Draw("NPE_LPMT>>+h_NPE_initial_e", "", "goff");
        NC_NPETresE.Draw("NPE_LPMT>>+h_NPE_initial_NC", "", "goff");
        h_NPE_initial[0] = dynamic_cast<TH1 *>(gDirectory->Get("h_NPE_initial_mu"));
        h_NPE_initial[1] = dynamic_cast<TH1 *>(gDirectory->Get("h_NPE_initial_e"));
        h_NPE_initial[2] = dynamic_cast<TH1 *>(gDirectory->Get("h_NPE_initial_NC"));

        TLegend leg_NPE;
        h_NPE_initial[2]->SetXTitle("NPE_{LPMT}");
        h_NPE_initial[2]->SetYTitle("entries");
        TCanvas *c_NPE = new TCanvas("NPE");
        c_NPE->cd();
        h_NPE_initial[2]->Draw("hist");
        for (int i = 0; i < 3; i++)
        {
            h_NPE_initial[i]->SetLineColor(hist_cor[i]);
            leg_NPE.AddEntry(h_NPE_initial[i], hist_name[i]);
            h_NPE_initial[i]->Draw("SAME");
            // h_NPE_initial[i]->Write();
        }
        leg_NPE.DrawClone("SAME");
        // c_NPE->DrawClone();
        // gPad->SetLogx();
        gPad->SetLogy();

        TH1 *h_tres_initial[3];
        TH1 *h_tres_FidCut[3];
        TH1 *h_tres_muCut[3];
        TH1 *h_tres_eCut[3];
        muCC_NPETresE.Draw("sigma_tres>>+h_tres_initial_mu(1000,0,1000)", "", "goff");
        eCC_NPETresE.Draw("sigma_tres>>+h_tres_initial_e(1000,0,1000)", "", "goff");
        NC_NPETresE.Draw("sigma_tres>>+h_tres_initial_NC(1000,0,1000)", "", "goff");
        h_tres_initial[0] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_initial_mu"));
        h_tres_initial[1] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_initial_e"));
        h_tres_initial[2] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_initial_NC"));

        TLegend leg_tres;
        h_tres_initial[0]->SetXTitle("#sigma(t_{res})");
        h_tres_initial[0]->SetYTitle("entries");
        TCanvas *c_tres = new TCanvas("tres");
        c_tres->cd();
        h_tres_initial[0]->Draw("hist");
        for (int i = 0; i < 3; i++)
        {
            h_tres_initial[i]->SetLineColor(hist_cor[i]);
            leg_tres.AddEntry(h_tres_initial[i], hist_name[i]);
            c_tres->cd();
            h_tres_initial[i]->Draw("SAME");
            // h_tres_initial[i]->Write();
        }
        c_tres->cd();
        leg_tres.DrawClone("SAME");
        // c_tres->DrawClone();
        // gPad->SetLogx();
        // gPad->SetLogy();

        //different spectra under different cuts
        muCC_NPETresE.Draw("sigma_tres>>+h_tres_muCut_mu(1000,0,1000)", "(NPE_LPMT>5.0e5) && (NPE_LPMT<1.59e7)", "goff");
        eCC_NPETresE.Draw("sigma_tres>>+h_tres_muCut_e(1000,0,1000)", "(NPE_LPMT>5.0e5) && (NPE_LPMT<1.59e7)", "goff");
        NC_NPETresE.Draw("sigma_tres>>+h_tres_muCut_NC(1000,0,1000)", "(NPE_LPMT>5.0e5) && (NPE_LPMT<1.59e7)", "goff");
        h_tres_muCut[0] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_muCut_mu"));
        h_tres_muCut[1] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_muCut_e"));
        h_tres_muCut[2] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_muCut_NC"));
        muCC_NPETresE.Draw("sigma_tres>>+h_tres_eCut_mu(1000,0,1000)", "(NPE_LPMT>1e5) && (NPE_LPMT<1.59e7)", "goff");
        eCC_NPETresE.Draw("sigma_tres>>+h_tres_eCut_e(1000,0,1000)", "(NPE_LPMT>1e5) && (NPE_LPMT<1.59e7)", "goff");
        NC_NPETresE.Draw("sigma_tres>>+h_tres_eCut_NC(1000,0,1000)", "(NPE_LPMT>1e5) && (NPE_LPMT<1.59e7)", "goff");
        h_tres_eCut[0] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_eCut_mu"));
        h_tres_eCut[1] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_eCut_e"));
        h_tres_eCut[2] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_eCut_NC"));
        TH1 *h_Eff_eCC = dynamic_cast<TH1 *>(h_tres_initial[0]->Clone("Eff_eCC"));
        TH1 *h_CONT_eCC = dynamic_cast<TH1 *>(h_tres_initial[0]->Clone("Cont_eCC"));
        TH1 *h_Eff_muCC = dynamic_cast<TH1 *>(h_tres_initial[0]->Clone("Eff_muCC"));
        TH1 *h_CONT_muCC = dynamic_cast<TH1 *>(h_tres_initial[0]->Clone("Cont_muCC"));
        TCanvas *c_EffCONT[2];
        TLegend leg_EffCONT[2];
        //all events number for eCC in each LPMT NPE with current cut(bin)
        double eCC_all = h_NPE_initial[1]->GetEntries();
        //all events number for muCC in each LPMT NPE with current cut(bin)
        double muCC_all = h_tres_initial[0]->GetEntries();
        //obseved event number in current cut range, mu,e case
        double Ob_range[2];
        double muCC_in[2], eCC_in[2], NC_in[2];
        double Eff_mu = 0, CONT_mu = 0;
        double Eff_e = 0, CONT_e = 0;
        const int BINNUM_tres = h_Eff_eCC->GetNbinsX();
        for (int i = 0; i < BINNUM_tres; i++)
        {
            muCC_in[0] = h_tres_muCut[0]->Integral(i + 1, BINNUM_tres);
            eCC_in[0] = h_tres_muCut[1]->Integral(i + 1, BINNUM_tres);
            NC_in[0] = h_tres_muCut[2]->Integral(i + 1, BINNUM_tres);
            muCC_in[1] = h_tres_eCut[0]->Integral(1, i + 1);
            eCC_in[1] = h_tres_eCut[1]->Integral(1, i + 1);
            NC_in[1] = h_tres_eCut[2]->Integral(1, i + 1);
            Ob_range[0] = muCC_in[0] + eCC_in[0] + NC_in[0];
            Ob_range[1] = muCC_in[1] + eCC_in[1] + NC_in[1];
            if (Ob_range[0] == 0)
                Ob_range[0] = 1;
            if (Ob_range[1] == 0)
                Ob_range[1] = 1;
            Eff_mu = muCC_in[0] / muCC_all;
            CONT_mu = 1 - muCC_in[0] / Ob_range[0];
            if (muCC_in[0] == 0)
                CONT_mu = 0;
            Eff_e = eCC_in[1] / eCC_all;
            CONT_e = 1 - eCC_in[1] / Ob_range[1];
            if (eCC_in[1] == 0)
                CONT_e = 0;
            h_Eff_eCC->SetBinContent(i + 1, Eff_e);
            h_CONT_eCC->SetBinContent(i + 1, CONT_e);
            h_Eff_muCC->SetBinContent(i + 1, Eff_mu);
            h_CONT_muCC->SetBinContent(i + 1, CONT_mu);
        }
        // TFile *ff_EffCONT = TFile::Open("../data/Preliminary/EffCont.root", "RECREATE");
        c_EffCONT[0] = new TCanvas("mu_CC");
        h_CONT_muCC->SetLineColor(kRed);
        h_Eff_muCC->SetLineColor(kBlue);
        leg_EffCONT[0].AddEntry(h_CONT_muCC, "Contamination");
        leg_EffCONT[0].AddEntry(h_Eff_muCC, "Efficiency");
        h_CONT_muCC->SetXTitle("#sigma(t_{res}) [ns]");
        h_CONT_muCC->SetTitle("#nu_{#mu} CC");
        h_Eff_muCC->SetTitle("#nu_{#mu} CC");
        c_EffCONT[0]->cd();
        h_Eff_muCC->Draw();
        h_CONT_muCC->Draw("SAME");
        TLine *l_muCC = new TLine(Cut_sigma_tres_Sg_muCC, 0, Cut_sigma_tres_Sg_muCC, 0.75);
        l_muCC->SetLineWidth(3);
        l_muCC->Draw("SAME");
        // h_Eff_muCC->Draw("SAME");
        // h_CONT_muCC->Write();
        // h_Eff_muCC->Write();
        leg_EffCONT[0].DrawClone("SAME");

        c_EffCONT[1] = new TCanvas("e_CC");
        h_CONT_eCC->SetLineColor(kRed);
        h_Eff_eCC->SetLineColor(kBlue);
        leg_EffCONT[1].AddEntry(h_CONT_eCC, "Contamination");
        leg_EffCONT[1].AddEntry(h_Eff_eCC, "Efficiency");
        h_CONT_eCC->SetXTitle("#sigma(t_{res}) [ns]");
        h_CONT_eCC->SetTitle("#nu_{e} CC");
        h_Eff_eCC->SetTitle("#nu_{e} CC");
        c_EffCONT[1]->cd();
        h_Eff_eCC->Draw();
        h_CONT_eCC->Draw("SAME");
        TLine *l_eCC = new TLine(Cut_sigma_tres_Sg_eCC, 0, Cut_sigma_tres_Sg_eCC, 1);
        l_eCC->SetLineWidth(3);
        l_eCC->Draw("SAME");
        // h_Eff_eCC->Draw("SAME");
        // h_CONT_eCC->Write();
        // h_Eff_eCC->Write();
        leg_EffCONT[1].DrawClone("SAME");
        // ff_EffCONT->Close();

        printf("mu CC:%f\t Eff:%f\tCONT:%f\n", Sigma_cut_muCC,
               h_Eff_muCC->Interpolate(Sigma_cut_muCC),
               h_CONT_muCC->Interpolate(Sigma_cut_muCC));
        printf("e CC:%f\t Eff:%f\tCONT:%f\n", Sigma_cut_eCC,
               h_Eff_eCC->Interpolate(Sigma_cut_eCC),
               h_CONT_eCC->Interpolate(Sigma_cut_eCC));
        // TFile *ff_unfold=TFile::Open("../data/UnfoldData.root","update");
        // ff_unfold->cd();
        // h_CONT_eCC->Write();
        // h_Eff_eCC->Write();
        // h_CONT_muCC->Write();
        // h_Eff_muCC->Write();

        // TH1 *h_Etrue_initial[3];
        // TH1 *h_Etrue_FidCut[3];
        // TH1 *h_Etrue_allCut[3];
        // muCC_NPETresE.Draw("E_nu_true>>+h_Etrue_initial_mu(100,0,20)", "", "goff");
        // eCC_NPETresE.Draw("E_nu_true>>+h_Etrue_initial_e(100,0,20)", "", "goff");
        // NC_NPETresE.Draw("E_nu_true>>+h_Etrue_initial_NC(100,0,20)", "", "goff");
        // h_Etrue_initial[0] = dynamic_cast<TH1 *>(gDirectory->Get("h_Etrue_initial_mu"));
        // h_Etrue_initial[1] = dynamic_cast<TH1 *>(gDirectory->Get("h_Etrue_initial_e"));
        // h_Etrue_initial[2] = dynamic_cast<TH1 *>(gDirectory->Get("h_Etrue_initial_NC"));

        // TLegend leg_Etrue;
        // h_Etrue_initial[0]->SetXTitle("True Energy [GeV]");
        // h_Etrue_initial[0]->SetYTitle("entries");
        // TCanvas *c_Etrue = new TCanvas("ETrue");
        // c_Etrue->cd();
        // h_Etrue_initial[0]->Draw("hist");
        // for (int i = 0; i < 3; i++)
        // {
        //     h_Etrue_initial[i]->SetLineColor(hist_cor[i]);
        //     leg_Etrue.AddEntry(h_Etrue_initial[i], hist_name[i]);
        //     c_Etrue->cd();
        //     h_Etrue_initial[i]->Draw("SAME");
        //     // h_Etrue_initial[i]->Write();
        // }
        // c_Etrue->cd();
        // leg_Etrue.DrawClone("SAME");
        // // gPad->SetLogx();
        // gPad->SetLogy();
        // // ff_before_cut->Close();
    }

    //0:all selected, 1:true needed, 2:wrong
    TString NPE_Spec_Name[] = {
        "Sel",
        "True",
        "Wrong"};
    Color_t NPE_Spec_Color[] = {
        kBlack,
        kBlue - 10,
        kGreen - 2};

    //0:all selected, 1:true needed, 2:wrong
    TH1 *h_eCC_NPE_Spec[3];
    TH1 *h_muCC_NPE_Spec[3];
    TH1 *h_eCC_Enu_Spec[3];
    TH1 *h_muCC_Enu_Spec[3];
    TH2D *h_eCC_Etrue_NPE = new TH2D("eCC_Likely_hood",
                                     "#nu_{e} Likelihood Matrix",
                                     Etrue_BINNUM_eCC, logEtrue_range_eCC[0], logEtrue_range_eCC[1],
                                     NPE_BINNUM_eCC, logNPE_range_eCC[0], logNPE_range_eCC[1]);
    TH2D *h_muCC_Etrue_NPE = new TH2D("muCC_Likely_hood",
                                      "#nu_{#mu} Likelihood Matrix",
                                      Etrue_BINNUM_muCC, logEtrue_range_muCC[0], logEtrue_range_muCC[1],
                                      NPE_BINNUM_muCC, logNPE_range_muCC[0], logNPE_range_muCC[1]);
    h_muCC_Etrue_NPE->SetXTitle("log_{10}(E_{#nu}/GeV)");
    h_muCC_Etrue_NPE->SetYTitle("log_{10}(NPE_{LPMT})");
    h_eCC_Etrue_NPE->SetXTitle("log_{10}(E_{#nu}/GeV)");
    h_eCC_Etrue_NPE->SetYTitle("log_{10}(NPE_{LPMT})");

    for (int i = 0; i < 3; i++)
    {
        h_eCC_NPE_Spec[i] = new TH1D("NPEeCC" + NPE_Spec_Name[i],
                                     "#nu_{e} CC NPE Spectra",
                                     NPE_BINNUM_eCC,
                                     logNPE_range_eCC[0], logNPE_range_eCC[1]);
        h_muCC_NPE_Spec[i] = new TH1D("NPEmuCC" + NPE_Spec_Name[i],
                                      "#nu_{#mu} CC NPE Spectra",
                                      NPE_BINNUM_muCC,
                                      logNPE_range_muCC[0], logNPE_range_muCC[1]);
        h_eCC_NPE_Spec[i]->SetXTitle("log_{10}(NPE_{LPMT})");
        h_muCC_NPE_Spec[i]->SetXTitle("log_{10}(NPE_{LPMT})");
        h_eCC_NPE_Spec[i]->SetYTitle("entries");
        h_muCC_NPE_Spec[i]->SetYTitle("entries");
        h_eCC_NPE_Spec[i]->SetLineColor(NPE_Spec_Color[i]);
        h_muCC_NPE_Spec[i]->SetLineColor(NPE_Spec_Color[i]);
        h_eCC_Enu_Spec[i] = new TH1D("Enu_eCC" + NPE_Spec_Name[i],
                                     "#nu_{e} CC Neutrino Enegry Spectra",
                                     Etrue_BINNUM_eCC,
                                     logEtrue_range_eCC[0], logEtrue_range_eCC[1]);
        h_muCC_Enu_Spec[i] = new TH1D("Enu_muCC" + NPE_Spec_Name[i],
                                      "#nu_{#mu} CC Neutrino Enegry Spectra",
                                      Etrue_BINNUM_muCC,
                                      logEtrue_range_muCC[0], logEtrue_range_muCC[1]);
        h_eCC_Enu_Spec[i]->SetXTitle("log_{10}(E_{#nu}/GeV)");
        h_muCC_Enu_Spec[i]->SetXTitle("log_{10}(E_{#nu}/GeV)");
        h_eCC_Enu_Spec[i]->SetYTitle("entries");
        h_muCC_Enu_Spec[i]->SetYTitle("entries");
        h_eCC_Enu_Spec[i]->SetLineColor(NPE_Spec_Color[i]);
        h_muCC_Enu_Spec[i]->SetLineColor(NPE_Spec_Color[i]);
    }

    for (int i = 0; i < muCC_NPETresE.GetEntries(); i++)
    {
        muCC_NPETresE.GetEntry(i);
        if (NPE_LPMT[0] >= NPE_cut_muCC[0] &&
            NPE_LPMT[0] <= NPE_cut_muCC[1] &&
            sigma_tres[0] >= Sigma_cut_muCC)
        {
            h_muCC_NPE_Spec[0]->Fill(log10(NPE_LPMT[0]));                    //all for muCC
            h_muCC_NPE_Spec[1]->Fill(log10(NPE_LPMT[0]));                    //true for eCC
            h_muCC_Enu_Spec[0]->Fill(log10(E_nu_true[0]));                   //all for muCC
            h_muCC_Enu_Spec[1]->Fill(log10(E_nu_true[0]));                   //true for eCC
            h_muCC_Etrue_NPE->Fill(log10(E_nu_true[0]), log10(NPE_LPMT[0])); //all
        }
        if (NPE_LPMT[0] >= NPE_cut_eCC[0] &&
            NPE_LPMT[0] <= NPE_cut_eCC[1] &&
            sigma_tres[0] <= Sigma_cut_eCC)
        {
            h_eCC_NPE_Spec[0]->Fill(log10(NPE_LPMT[0]));                    //all for eCC
            h_eCC_NPE_Spec[2]->Fill(log10(NPE_LPMT[0]));                    //wrong for eCC
            h_eCC_Enu_Spec[0]->Fill(log10(E_nu_true[0]));                   //all for eCC
            h_eCC_Enu_Spec[2]->Fill(log10(E_nu_true[0]));                   //wrong for eCC
            h_eCC_Etrue_NPE->Fill(log10(E_nu_true[0]), log10(NPE_LPMT[0])); //all
        }
        if (i < eCC_NPETresE.GetEntries())
        {
            eCC_NPETresE.GetEntry(i);
            if (NPE_LPMT[1] >= NPE_cut_muCC[0] &&
                NPE_LPMT[1] <= NPE_cut_muCC[1] &&
                sigma_tres[1] >= Sigma_cut_muCC)
            {
                h_muCC_NPE_Spec[0]->Fill(log10(NPE_LPMT[1]));                    //all for muCC
                h_muCC_NPE_Spec[2]->Fill(log10(NPE_LPMT[1]));                    //wrong for eCC
                h_muCC_Enu_Spec[0]->Fill(log10(E_nu_true[1]));                   //all for muCC
                h_muCC_Enu_Spec[2]->Fill(log10(E_nu_true[1]));                   //wrong for eCC
                h_muCC_Etrue_NPE->Fill(log10(E_nu_true[1]), log10(NPE_LPMT[1])); //all
            }
            if (NPE_LPMT[1] >= NPE_cut_eCC[0] &&
                NPE_LPMT[1] <= NPE_cut_eCC[1] &&
                sigma_tres[1] <= Sigma_cut_eCC)
            {
                h_eCC_NPE_Spec[0]->Fill(log10(NPE_LPMT[1]));                    //all for eCC
                h_eCC_NPE_Spec[1]->Fill(log10(NPE_LPMT[1]));                    //true for eCC
                h_eCC_Enu_Spec[0]->Fill(log10(E_nu_true[1]));                   //all for eCC
                h_eCC_Enu_Spec[1]->Fill(log10(E_nu_true[1]));                   //true for eCC
                h_eCC_Etrue_NPE->Fill(log10(E_nu_true[1]), log10(NPE_LPMT[1])); //all
            }
        }
        if (i < NC_NPETresE.GetEntries())
        {
            NC_NPETresE.GetEntry(i);
            if (NPE_LPMT[2] >= NPE_cut_muCC[0] &&
                NPE_LPMT[2] <= NPE_cut_muCC[1] &&
                sigma_tres[2] >= Sigma_cut_muCC)
            {
                h_muCC_NPE_Spec[0]->Fill(log10(NPE_LPMT[2]));                    //all for muCC
                h_muCC_NPE_Spec[2]->Fill(log10(NPE_LPMT[2]));                    //wrong for eCC
                h_muCC_Enu_Spec[0]->Fill(log10(E_nu_true[2]));                   //all for muCC
                h_muCC_Enu_Spec[2]->Fill(log10(E_nu_true[2]));                   //wrong for eCC
                h_muCC_Etrue_NPE->Fill(log10(E_nu_true[2]), log10(NPE_LPMT[2])); //all
            }
            if (NPE_LPMT[2] >= NPE_cut_eCC[0] &&
                NPE_LPMT[2] <= NPE_cut_eCC[1] &&
                sigma_tres[2] <= Sigma_cut_eCC)
            {
                h_eCC_NPE_Spec[0]->Fill(log10(NPE_LPMT[2]));                    //all for eCC
                h_eCC_NPE_Spec[2]->Fill(log10(NPE_LPMT[2]));                    //wrong for eCC
                h_eCC_Enu_Spec[0]->Fill(log10(E_nu_true[2]));                   //all for eCC
                h_eCC_Enu_Spec[2]->Fill(log10(E_nu_true[2]));                   //wrong for eCC
                h_eCC_Etrue_NPE->Fill(log10(E_nu_true[2]), log10(NPE_LPMT[2])); //all
            }
        }
    }

    // TFile *ff_unfold = TFile::Open("../data/UnfoldData.root", "update");
    // ff_unfold->cd();
    // h_muCC_Etrue_NPE->Write(h_muCC_Etrue_NPE->GetName(), TObject::kOverwrite);
    // h_eCC_Etrue_NPE->Write(h_eCC_Etrue_NPE->GetName(), TObject::kOverwrite);

    {
        TLegend *leg_sel[2];
        leg_sel[0] = new TLegend();
        leg_sel[1] = new TLegend();
        TCanvas *c_Sel_eCC = new TCanvas("Sel_eCC");
        c_Sel_eCC->cd();
        // double t_evt[NPE_BINNUM_muCC];
        // double Bin_center;
        // for (int i = 0; i < h_eCC_NPE_Spec[0]->GetNbinsX(); i++)
        //     t_evt[i] = h_eCC_NPE_Spec[0]->GetBinContent(i + 1);
        // h_eCC_NPE_Spec[0]->Reset();
        // for (int i = 0; i < NPE_BINNUM_eCC; i++)
        // {
        //     Bin_center = h_eCC_NPE_Spec[0]->GetBinCenter(i + 1);
        //     for (int j = 0; j < Expected_evt_NUM_eCC[i]; j++)
        //         h_eCC_NPE_Spec[0]->Fill(Bin_center, t_evt[i] / Expected_evt_NUM_eCC[i]);
        // }
        h_eCC_NPE_Spec[0]->SetMarkerColor(kBlack);
        h_eCC_NPE_Spec[0]->SetMarkerSize(1.5);
        h_eCC_NPE_Spec[0]->Draw("E1");
        for (int i = 0; i < 3; i++)
        {
            if (i > 0)
                h_eCC_NPE_Spec[i]->SetFillColor(NPE_Spec_Color[i]);
            leg_sel[0]->AddEntry(h_eCC_NPE_Spec[i], "#nu_{e}: " + NPE_Spec_Name[i] + " part");
            h_eCC_NPE_Spec[i]->Draw("SAME");
        }
        h_eCC_NPE_Spec[0]->Draw("SAME E1");
        leg_sel[0]->DrawClone("SAME");

        TCanvas *c_Sel_mu = new TCanvas("Sel_muCC");
        c_Sel_mu->cd();
        // for (int i = 0; i < h_muCC_NPE_Spec[0]->GetNbinsX(); i++)
        //     t_evt[i] = h_muCC_NPE_Spec[0]->GetBinContent(i + 1);
        // h_muCC_NPE_Spec[0]->Reset();
        // for (int i = 0; i < NPE_BINNUM_muCC; i++)
        // {
        //     Bin_center = h_muCC_NPE_Spec[0]->GetBinCenter(i + 1);
        //     for (int j = 0; j < Expected_evt_NUM_muCC[i]; j++)
        //         h_muCC_NPE_Spec[0]->Fill(Bin_center, t_evt[i] / Expected_evt_NUM_muCC[i]);
        // }
        h_muCC_NPE_Spec[0]->SetMarkerColor(kBlack);
        h_muCC_NPE_Spec[0]->SetMarkerSize(1.5);
        h_muCC_NPE_Spec[0]->Draw("E1");
        for (int i = 0; i < 3; i++)
        {
            if (i > 0)
                h_muCC_NPE_Spec[i]->SetFillColor(NPE_Spec_Color[i]);
            leg_sel[1]->AddEntry(h_muCC_NPE_Spec[i], "#nu_{#mu}: " + NPE_Spec_Name[i] + " part");

            if (i > 0)
                h_muCC_NPE_Spec[i]->Draw("SAME");
        }
        h_muCC_NPE_Spec[0]->Draw("SAME E1");
        leg_sel[1]->DrawClone("SAME");
        // TFile *ff_FakeData = TFile::Open("../data/UnfoldData.root", "recreate");
        TFile *ff_FakeData = TFile::Open("../data/UnfoldData.root", "update");
        ff_FakeData->cd();
        for (int i = 0; i < 3; i++)
        {
            h_muCC_NPE_Spec[i]->Write(h_muCC_NPE_Spec[i]->GetName(), TObject::kOverwrite);
            h_eCC_NPE_Spec[i]->Write(h_eCC_NPE_Spec[i]->GetName(), TObject::kOverwrite);
            h_eCC_Enu_Spec[i]->Write(h_eCC_Enu_Spec[i]->GetName(), TObject::kOverwrite);
            h_muCC_Enu_Spec[i]->Write(h_muCC_Enu_Spec[i]->GetName(), TObject::kOverwrite);
        }
        ff_FakeData->Close();

        // h_muCC_Etrue_NPE->Draw("colz");
        // h_eCC_Etrue_NPE->Draw("colz");
        // gPad->SetLogz();
        // muCC_NPETresE.Draw("NPE_LPMT:E_nu_true>>+h_2DmuCC", "", "colz");
        // muCC_NPETresE.Draw("E_nu_true>>+h_2DmuCC","","");
        // eCC_NPETresE.Draw("NPE_LPMT:E_nu_true>>+h_2DeCC","sigma_tres<77","colz");
        // eCC_NPETresE.Draw("NPE_LPMT:sigma_tres>>+h_2DeCC", "", "colz");
        // NC_NPETresE.Draw("NPE_LPMT:E_nu_true>>+h_2DNC","","colz");
    }
    // TH1D *h_Honda_flux_e = new TH1D("Honda_flux_e", "HKKM14 Flux for #nu_{e}",
    //                                 Etrue_BINNUM_eCC,
    //                                 logEtrue_range_eCC[0], logEtrue_range_eCC[1]);
    // TH1D *h_Honda_flux_mu = new TH1D("Honda_flux_mu", "HKKM14 Flux for #nu_{#mu}",
    //                                  Etrue_BINNUM_muCC,
    //                                  logEtrue_range_muCC[0], logEtrue_range_muCC[1]);
    // vector<vector<double>> Data_vec;
    // LoadFile("../data/Flux/JUNOFlux_Honda_HKKM2014.txt", Data_vec, 5, 2);
    // for (int i = 0; i < Data_vec.size(); i++)
    // {
    //     h_Honda_flux_e->Fill(log10(Data_vec[i][0]), Data_vec[i][3] + Data_vec[i][4]);
    //     h_Honda_flux_mu->Fill(log10(Data_vec[i][0]), Data_vec[i][1] + Data_vec[i][2]);
    // }
    // h_Honda_flux_e->Scale(1 / h_Honda_flux_e->Integral());
    // h_Honda_flux_mu->Scale(1 / h_Honda_flux_mu->Integral());
    // h_Honda_flux_e->SetXTitle("log_{10}(E_{#nu}/GeV)");
    // h_Honda_flux_mu->SetXTitle("log_{10}(E_{#nu}/GeV)");
    // h_Honda_flux_e->SetYTitle("P_{0}(E_{i})");
    // h_Honda_flux_mu->SetYTitle("P_{0}(E_{i})");

    // // h_Honda_flux_mu->Draw("E");
    // TFile *ff_unfold = TFile::Open("../data/UnfoldData.root", "RECREATE");
    // for (int i = 0; i < 3; i++)
    // {
    //     h_eCC_NPE_Spec[i]->Write();
    //     h_muCC_NPE_Spec[i]->Write();
    //     h_eCC_Enu_Spec[i]->Write();
    //     h_muCC_Enu_Spec[i]->Write();
    // }
    // h_muCC_Etrue_NPE->Write();
    // h_eCC_Etrue_NPE->Write();
    // h_Honda_flux_e->Write();
    // h_Honda_flux_mu->Write();
    // ff_unfold->Close();

    {
        double A_ji_ecc[NPE_BINNUM_eCC][Etrue_BINNUM_eCC];
        //
        double epsilon_eCC[Etrue_BINNUM_eCC];
        double epsilon_muCC[Etrue_BINNUM_eCC];
        TH2 *h_eCC2D = dynamic_cast<TH2 *>(gDirectory->Get("h_eCC2D"));
        TH2 *h_muCC2D = dynamic_cast<TH2 *>(gDirectory->Get("h_muCC2D"));
        for (int i = 0; i < Etrue_BINNUM_eCC; i++)
            epsilon_eCC[i] = h_eCC2D->GetBinContent(i + 1, 0) / h_eCC2D->Integral(i + 1, i + 1, 0, NPE_BINNUM_eCC + 1);
        for (int i = 0; i < Etrue_BINNUM_muCC; i++)
            epsilon_muCC[i] = h_muCC2D->GetBinContent(i + 1, 0) / h_muCC2D->Integral(i + 1, i + 1, 0, NPE_BINNUM_muCC + 1);

        double Response_SUM[Etrue_BINNUM_eCC];
        for (int i = 0; i < Etrue_BINNUM_eCC; i++)
        {
            Response_SUM[i] = h_eCC_Etrue_NPE->Integral(i + 1, i + 1, 1, NPE_BINNUM_eCC);
            for (int j = 0; j < NPE_BINNUM_eCC; j++)
            {
                //normalize the the likelihood sum of a row to 1-epsilon
                A_ji_ecc[j][i] = h_eCC_Etrue_NPE->GetBinContent(i + 1, j + 1) *
                                 (1 - epsilon_eCC[i]) / Response_SUM[i];
                h_eCC_Etrue_NPE->SetBinContent(i + 1, j + 1, A_ji_ecc[j][i]);
            }
            printf("epsilon_eCC:%f\n", epsilon_eCC[i]);
        }
        TCanvas *c_redu_Ml_eCC = new TCanvas("c_redu_Ml_eCC");
        h_eCC_Etrue_NPE->Draw("colz");
        gPad->SetLogz();
        double A_ji_mucc[NPE_BINNUM_muCC][Etrue_BINNUM_muCC];
        // double Response_SUM[Etrue_BINNUM_muCC];
        for (int i = 0; i < Etrue_BINNUM_muCC; i++)
        {
            Response_SUM[i] = h_muCC_Etrue_NPE->Integral(i + 1, i + 1, 1, NPE_BINNUM_muCC);
            for (int j = 0; j < NPE_BINNUM_muCC; j++)
            {
                //normalize the the likelihood sum of a row to 1-epsilon
                A_ji_mucc[j][i] = h_muCC_Etrue_NPE->GetBinContent(i + 1, j + 1) *
                                  (1 - epsilon_muCC[i]) / Response_SUM[i];
                h_muCC_Etrue_NPE->SetBinContent(i + 1, j + 1, A_ji_mucc[j][i]);
            }
            printf("epsilon_muCC:%f\n", epsilon_muCC[i]);
        }
        TCanvas *c_redu_Ml_muCC = new TCanvas("c_redu_Ml_muCC");
        c_redu_Ml_muCC->cd();
        h_muCC_Etrue_NPE->Draw("colz");
        gPad->SetLogz();
        // TFile *ff_unfold = TFile::Open("../data/UnfoldData.root", "update");
        // ff_unfold->cd();
        // h_muCC_Etrue_NPE->Write(h_muCC_Etrue_NPE->GetName(), TObject::kOverwrite);
        // h_eCC_Etrue_NPE->Write(h_eCC_Etrue_NPE->GetName(), TObject::kOverwrite);
    }
}

//get result for all PEs
void ForAllPEs()
{
    TFile *ff_newr = TFile::Open("../results/resultnHitCUT.root", "READ");
    TH1 *h_muCC[4], *h_eCC[4], *h_NC[5];
    TString mucc_name[4] = {
        "muCC0",
        "muCC1",
        "muCC2",
        "muCC3",
    };
    TString eCC_name[4] = {
        "eCC0",
        "eCC1",
        "eCC2",
        "eCC3",
    };
    TString NC_name[4] = {
        "NC0",
        "NC1",
        "NC2",
        "NC3",
    };
    GetObjFromFile(ff_newr, h_muCC, mucc_name, 4);
    GetObjFromFile(ff_newr, h_eCC, eCC_name, 4);
    GetObjFromFile(ff_newr, h_NC, NC_name, 4);
    TH1 *h_muCC_all = dynamic_cast<TH1 *>(h_muCC[0]->Clone());
    TH1 *h_eCC_all = dynamic_cast<TH1 *>(h_eCC[0]->Clone());
    TH1 *h_NC_all_e = dynamic_cast<TH1 *>(h_NC[0]->Clone());
    TH1 *h_NC_all_mu = dynamic_cast<TH1 *>(h_NC[0]->Clone());
    for (int i = 1; i < 4; i++)
    {
        h_eCC_all->Add(h_eCC[i]);
        h_NC_all_e->Add(h_NC[i]);
    }
    h_muCC_all->Add(h_muCC[1], h_muCC[2]);
    h_muCC_all->Add(h_muCC[3]);
    h_NC_all_mu->Add(h_NC[1], h_NC[2]);
    h_NC_all_mu->Add(h_NC[3]);

    //all events number for eCC in each LPMT NPE
    double eCC_all = h_eCC_all->Integral();
    //all events number for muCC in each LPMT NPE
    double muCC_all = h_muCC_all->Integral();
    //all events
    TH1 *h_all_e, *h_all_mu;
    h_all_e = dynamic_cast<TH1 *>(h_eCC_all->Clone());
    h_all_e->Add(h_muCC_all);
    h_all_e->Add(h_muCC[0]);
    h_all_e->Add(h_NC_all_e);

    h_all_mu = dynamic_cast<TH1 *>(h_muCC_all->Clone());
    for (int i = 1; i < 4; i++)
        h_all_mu->Add(h_eCC[i]);
    h_all_mu->Add(h_NC_all_mu);

    TH1 *h_Eff_eCC = dynamic_cast<TH1 *>(h_eCC_all->Clone("e-CC Effeciency"));
    TH1 *h_CONT_eCC = dynamic_cast<TH1 *>(h_eCC_all->Clone("e-CC Contamination"));
    TH1 *h_Eff_muCC = dynamic_cast<TH1 *>(h_muCC_all->Clone("Efficiency"));
    TH1 *h_CONT_muCC = dynamic_cast<TH1 *>(h_muCC_all->Clone("Contamination"));
    h_CONT_eCC->SetYTitle("");
    h_Eff_eCC->SetYTitle("");
    h_CONT_muCC->SetYTitle("");
    h_Eff_muCC->SetYTitle("");
    h_CONT_eCC->SetLineColor(kRed);
    h_CONT_eCC->SetLineWidth(4);
    h_Eff_eCC->SetLineColor(kBlue);
    h_Eff_eCC->SetLineWidth(4);
    h_CONT_muCC->SetLineColor(kRed);
    h_CONT_muCC->SetLineWidth(4);
    h_Eff_muCC->SetLineColor(kBlue);
    h_Eff_muCC->SetLineWidth(4);
    //obseved event number in current cut range
    //1st 4 for e, cut under. 2nd 4 for mu ,cut above
    double Ob_range[2];
    double muCC_in, eCC_in;
    double Eff_mu = 0, CONT_mu = 0;
    double Eff_e = 0, CONT_e = 0;
    for (int i = 0; i < h_muCC_all->GetNbinsX(); i++)
    {
        eCC_in = h_eCC_all->Integral(1, i + 1);
        muCC_in = h_muCC_all->Integral(i + 1, 500);
        Ob_range[0] = h_all_e->Integral(1, i + 1);
        Ob_range[1] = h_all_mu->Integral(i + 1, 500);
        if (Ob_range[0] == 0)
            Ob_range[0] = 1;
        if (Ob_range[1] == 0)
            Ob_range[1] = 1;
        Eff_e = eCC_in / eCC_all;
        CONT_e = 1 - eCC_in / Ob_range[0];
        Eff_mu = muCC_in / muCC_all;
        CONT_mu = 1 - muCC_in / Ob_range[1];
        h_Eff_eCC->SetBinContent(i + 1, Eff_e);
        h_CONT_eCC->SetBinContent(i + 1, CONT_e);
        h_Eff_muCC->SetBinContent(i + 1, Eff_mu);
        h_CONT_muCC->SetBinContent(i + 1, CONT_mu);
    }
    TCanvas *cs[2];
    TLegend leg[2];
    for (int i = 0; i < 1; i++)
    {
        cs[i] = new TCanvas(Form("c%d", i));
        leg[i].AddEntry(h_Eff_muCC, "Efficiency");
        leg[i].AddEntry(h_CONT_muCC, "Contamination");
        cs[i]->cd();
        h_Eff_muCC->SetTitle("#nu_{#mu}CC: 5.7<log(NPE_{LPMT})<7.2");
        h_Eff_muCC->Draw();
        h_CONT_muCC->Draw("SAME");
        leg[i].DrawClone("SAME");

        cs[i + 1] = new TCanvas(Form("c%d", i + 4));
        cs[i + 1]->cd();
        leg[i + 1].AddEntry(h_Eff_eCC, "Efficiency");
        leg[i + 1].AddEntry(h_CONT_eCC, "Contamination");
        h_Eff_eCC->SetTitle("#nu_{e}CC: 5<log(NPE_{LPMT})<7.2");
        h_Eff_eCC->Draw();
        // h_CONT_eCC->Draw();
        h_CONT_eCC->Draw("SAME");
        leg[i + 1].DrawClone("SAME");
    }
    double e_CC_cut = 90;
    double mu_CC_cut = 117;
    printf("%.1f ns eCC:EFF: %f\tCONT: %f\n", e_CC_cut, h_Eff_eCC->Interpolate(e_CC_cut), h_CONT_eCC->Interpolate(e_CC_cut));
    printf("%.1f ns muCC:EFF: %f\tCONT: %f\n", mu_CC_cut, h_Eff_muCC->Interpolate(mu_CC_cut), h_CONT_muCC->Interpolate(mu_CC_cut));
}

//get exact cuts
void ViewEffandCONT()
{
    TH1::AddDirectory(false);
    TString PreFileName = "../results/result10.root";
    // TString PreFileName = "../results/resultnHitCUT.root";
    TFile *ff_flavor = TFile::Open(PreFileName, "READ");
    TH1 *h_muCC[4], *h_eCC[4], *h_NC[4];
    Color_t mueN[] = {
        kBlue,
        kRed,
        kGreen};
    for (int i = 0; i < 4; i++)
    {
        h_muCC[i] = dynamic_cast<TH1 *>(ff_flavor->Get(Form("muCC%d", i)));
        h_eCC[i] = dynamic_cast<TH1 *>(ff_flavor->Get(Form("eCC%d", i)));
        h_NC[i] = dynamic_cast<TH1 *>(ff_flavor->Get(Form("NC%d", i)));
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
        h_CONT_eCC[i] = dynamic_cast<TH1 *>(h_muCC[0]->Clone("Contamination"));
        h_Eff_eCC[i] = dynamic_cast<TH1 *>(h_muCC[0]->Clone("Efficiency"));
        h_CONT_muCC[i] = dynamic_cast<TH1 *>(h_muCC[0]->Clone("Contamination"));
        h_Eff_muCC[i] = dynamic_cast<TH1 *>(h_muCC[0]->Clone("Efficiency"));
        h_all[i] = dynamic_cast<TH1 *>(h_muCC[0]->Clone("AllEvents"));
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
    TCanvas *cs[8];
    TLegend leg[8];
    for (int i = 0; i < 4; i++)
    {
        cs[i] = new TCanvas(Form("c%d", i));
        leg[i].AddEntry(h_Eff_muCC[i], "Efficiency");
        leg[i].AddEntry(h_CONT_muCC[i], "Contamination");
        cs[i]->cd();
        h_Eff_muCC[i]->SetTitle(CutConditions[i] + ": #nu_{#mu}");
        h_Eff_muCC[i]->Draw();
        h_CONT_muCC[i]->Draw("SAME");
        leg[i].DrawClone("SAME");

        cs[i + 4] = new TCanvas(Form("c%d", i + 4));
        cs[i + 4]->cd();
        leg[i + 4].AddEntry(h_Eff_eCC[i], "Efficiency");
        leg[i + 4].AddEntry(h_CONT_eCC[i], "Contamination");
        h_Eff_eCC[i]->SetTitle(CutConditions[i] + ": #nu_{e}");
        h_Eff_eCC[i]->Draw();
        h_CONT_eCC[i]->Draw("SAME");
        leg[i + 4].DrawClone("SAME");
    }
    double e_CC_cut = 76;
    double mu_CC_cut = 115;
    printf("%.1f ns eCC:EFF: %f\tCONT: %f\n", e_CC_cut, h_Eff_eCC[0]->Interpolate(e_CC_cut), h_CONT_eCC[0]->Interpolate(e_CC_cut));
    printf("%.1f ns muCC:EFF: %f\tCONT: %f\n", mu_CC_cut, h_Eff_muCC[2]->Interpolate(mu_CC_cut), h_CONT_muCC[2]->Interpolate(mu_CC_cut));
}
void ViewFlavor()
{
    // TString PreFileName = "../results/result10.root";
    TString PreFileName = "../results/resultnHitCUT.root";

    TH1::AddDirectory(false);
    TFile *ff_flavor = TFile::Open(PreFileName, "READ");
    TH1 *h_muCC[4], *h_eCC[4], *h_NC[4];
    Color_t mueN[] = {
        kBlue,
        kRed,
        kGreen};
    for (int i = 0; i < 4; i++)
    {
        h_muCC[i] = dynamic_cast<TH1 *>(ff_flavor->Get(Form("muCC%d", i)));
        h_eCC[i] = dynamic_cast<TH1 *>(ff_flavor->Get(Form("eCC%d", i)));
        h_NC[i] = dynamic_cast<TH1 *>(ff_flavor->Get(Form("NC%d", i)));
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
void GetObjFromFile(TFile *File, TH1 *h[], TString ObjNames[], int NUMObj)
{
    for (int i = 0; i < NUMObj; i++)
    {
        h[i] = dynamic_cast<TH1 *>(File->Get(ObjNames[i]));
    }
}

//may load data inte vector from txt file
void LoadFile(std::string filename,
              std::vector<std::vector<double>> &v,
              int Length,
              int SkipLines)
{
    std::ifstream infile;
    infile.open(filename, std::ios::in);
    if (!infile)
    {
        printf("Fail to open file:%s.", filename.c_str());
    }
    double t1;
    int CountSkip = 0;
    while (!infile.eof())
    {
        if (CountSkip < SkipLines)
        {
            if (infile.get() == '\n')
                CountSkip++;
        }
        else
        {
            std::vector<double> t(Length);
            for (int i = 0; i < Length; i++)
            {
                infile >> t1;
                t[i] = t1;
            }
            v.push_back(t);
        }
    }
    infile.close();
}

void ShowContEff(TTree &muCC_NPETresE,
                 TTree &eCC_NPETresE,
                 TTree &NC_NPETresE)
{
    double Sigma_cut_muCC = Cut_sigma_tres_Sg_muCC; //ns
    double Sigma_cut_eCC = Cut_sigma_tres_Sg_eCC;   //ns
    double NPE_cut_muCC[2] = {Cut_NPE_low_Sg[0], Cut_NPE_up_Sg[0]};
    double NPE_cut_eCC[2] = {Cut_NPE_low_Sg[1], Cut_NPE_up_Sg[1]};
    TH1 *h_NPE_initial[3];
    TH1 *h_NPE_FidCut[3];
    TH1 *h_NPE_allCut[3];
    TH1 *h_tres_initial[3];
    TH1 *h_tres_FidCut[3];
    TH1 *h_tres_muCut[3];
    TH1 *h_tres_eCut[3];
    muCC_NPETresE.Draw("sigma_tres>>+h_tres_initial_mu(1000,0,1000)", "", "goff");
    eCC_NPETresE.Draw("sigma_tres>>+h_tres_initial_e(1000,0,1000)", "", "goff");
    NC_NPETresE.Draw("sigma_tres>>+h_tres_initial_NC(1000,0,1000)", "", "goff");
    h_tres_initial[0] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_initial_mu"));
    h_tres_initial[1] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_initial_e"));
    h_tres_initial[2] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_initial_NC"));
    // // muCC_NPETresE.Draw("NPE_LPMT>>+h_NPE_allCut_mu", "", "goff");
    // // eCC_NPETresE.Draw("NPE_LPMT>>+h_NPE_allCut_e", "", "goff");
    // // NC_NPETresE.Draw("NPE_LPMT>>+h_NPE_allCut_NC", "", "goff");
    // // h_NPE_allCut[0] = dynamic_cast<TH1 *>(gDirectory->Get("h_NPE_allCut_mu"));
    // // h_NPE_allCut[1] = dynamic_cast<TH1 *>(gDirectory->Get("h_NPE_allCut_e"));
    // // h_NPE_allCut[2] = dynamic_cast<TH1 *>(gDirectory->Get("h_NPE_allCut_NC"));

    //different spectra under different cuts
    muCC_NPETresE.Draw("sigma_tres>>+h_tres_muCut_mu(1000,0,1000)", "(NPE_LPMT>5.012e5) && (NPE_LPMT<1.59e7)", "goff");
    eCC_NPETresE.Draw("sigma_tres>>+h_tres_muCut_e(1000,0,1000)", "(NPE_LPMT>5e5) && (NPE_LPMT<1.59e7)", "goff");
    NC_NPETresE.Draw("sigma_tres>>+h_tres_muCut_NC(1000,0,1000)", "(NPE_LPMT>5e5) && (NPE_LPMT<1.59e7)", "goff");
    h_tres_muCut[0] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_muCut_mu"));
    h_tres_muCut[1] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_muCut_e"));
    h_tres_muCut[2] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_muCut_NC"));
    muCC_NPETresE.Draw("sigma_tres>>+h_tres_eCut_mu(1000,0,1000)", "(NPE_LPMT>1e5) && (NPE_LPMT<1.59e7)", "goff");
    eCC_NPETresE.Draw("sigma_tres>>+h_tres_eCut_e(1000,0,1000)", "(NPE_LPMT>1e5) && (NPE_LPMT<1.59e7)", "goff");
    NC_NPETresE.Draw("sigma_tres>>+h_tres_eCut_NC(1000,0,1000)", "(NPE_LPMT>1e5) && (NPE_LPMT<1.59e7)", "goff");
    h_tres_eCut[0] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_eCut_mu"));
    h_tres_eCut[1] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_eCut_e"));
    h_tres_eCut[2] = dynamic_cast<TH1 *>(gDirectory->Get("h_tres_eCut_NC"));
    TH1 *h_Eff_eCC = dynamic_cast<TH1 *>(h_tres_initial[0]->Clone("Eff_eCC"));
    TH1 *h_CONT_eCC = dynamic_cast<TH1 *>(h_tres_initial[0]->Clone("Cont_eCC"));
    TH1 *h_Eff_muCC = dynamic_cast<TH1 *>(h_tres_initial[0]->Clone("Eff_muCC"));
    TH1 *h_CONT_muCC = dynamic_cast<TH1 *>(h_tres_initial[0]->Clone("Cont_muCC"));
    TCanvas *c_EffCONT[2];
    TLegend leg_EffCONT[2];
    //all events number for eCC in each LPMT NPE with current cut(bin)
    double eCC_all = h_NPE_initial[1]->GetEntries();
    //all events number for muCC in each LPMT NPE with current cut(bin)
    double muCC_all = h_tres_initial[0]->GetEntries();
    //obseved event number in current cut range, mu,e case
    double Ob_range[2];
    double muCC_in[2], eCC_in[2], NC_in[2];
    double Eff_mu = 0, CONT_mu = 0;
    double Eff_e = 0, CONT_e = 0;
    const int BINNUM_tres = h_Eff_eCC->GetNbinsX();
    for (int i = 0; i < BINNUM_tres; i++)
    {
        muCC_in[0] = h_tres_muCut[0]->Integral(i + 1, BINNUM_tres);
        eCC_in[0] = h_tres_muCut[1]->Integral(i + 1, BINNUM_tres);
        NC_in[0] = h_tres_muCut[2]->Integral(i + 1, BINNUM_tres);
        muCC_in[1] = h_tres_eCut[0]->Integral(1, i + 1);
        eCC_in[1] = h_tres_eCut[1]->Integral(1, i + 1);
        NC_in[1] = h_tres_eCut[2]->Integral(1, i + 1);
        Ob_range[0] = muCC_in[0] + eCC_in[0] + NC_in[0];
        Ob_range[1] = muCC_in[1] + eCC_in[1] + NC_in[1];
        if (Ob_range[0] == 0)
            Ob_range[0] = 1;
        if (Ob_range[1] == 0)
            Ob_range[1] = 1;
        Eff_mu = muCC_in[0] / muCC_all;
        CONT_mu = 1 - muCC_in[0] / Ob_range[0];
        Eff_e = eCC_in[1] / eCC_all;
        CONT_e = 1 - eCC_in[1] / Ob_range[1];
        h_Eff_eCC->SetBinContent(i + 1, Eff_e);
        h_CONT_eCC->SetBinContent(i + 1, CONT_e);
        h_Eff_muCC->SetBinContent(i + 1, Eff_mu);
        h_CONT_muCC->SetBinContent(i + 1, CONT_mu);
    }
    // TFile *ff_EffCONT = TFile::Open("../data/Preliminary/EffCont.root", "RECREATE");
    c_EffCONT[0] = new TCanvas("mu_CC");
    h_CONT_muCC->SetLineColor(kRed);
    h_Eff_muCC->SetLineColor(kBlue);
    leg_EffCONT[0].AddEntry(h_CONT_muCC, "Contamination");
    leg_EffCONT[0].AddEntry(h_Eff_muCC, "Efficiency");
    h_CONT_muCC->SetXTitle("#sigma(t_{res}) [ns]");
    h_CONT_muCC->SetTitle("#nu_{#mu} CC");
    c_EffCONT[0]->cd();
    h_CONT_muCC->Draw();
    h_Eff_muCC->Draw("SAME");
    // h_CONT_muCC->Write();
    // h_Eff_muCC->Write();
    leg_EffCONT[0].DrawClone("SAME");

    c_EffCONT[1] = new TCanvas("e_CC");
    h_CONT_eCC->SetLineColor(kRed);
    h_Eff_eCC->SetLineColor(kBlue);
    leg_EffCONT[1].AddEntry(h_CONT_eCC, "Contamination");
    leg_EffCONT[1].AddEntry(h_Eff_eCC, "Efficiency");
    h_CONT_eCC->SetXTitle("#sigma(t_{res}) [ns]");
    h_CONT_eCC->SetTitle("#nu_{e} CC");
    c_EffCONT[1]->cd();
    h_CONT_eCC->Draw();
    h_Eff_eCC->Draw("SAME");
    // h_CONT_eCC->Write();
    // h_Eff_eCC->Write();
    leg_EffCONT[1].DrawClone("SAME");
    // ff_EffCONT->Close();

    printf("mu CC: Eff:%f\tCONT:%f\n",
           h_Eff_muCC->Interpolate(Sigma_cut_muCC),
           h_CONT_muCC->Interpolate(Sigma_cut_muCC));
    printf("e CC: Eff:%f\tCONT:%f\n",
           h_Eff_eCC->Interpolate(Sigma_cut_eCC),
           h_CONT_eCC->Interpolate(Sigma_cut_eCC));
}

//show Fake data
void GetFakeData(TString FileName = "../results/FakeData.root")
{
    // TChain muCC_NPETresE("muCC_NPETresE");
    // TChain eCC_NPETresE("eCC_NPETresE");
    // TChain NC_NPETresE("NC_NPETresE");
    // muCC_NPETresE.Add(FileName);
    // eCC_NPETresE.Add(FileName);
    // NC_NPETresE.Add(FileName);

    // //0:all selected, 1:true needed, 2:wrong
    // TString NPE_Spec_Name[] = {
    //     "Sel.",
    //     "True",
    //     "Wrong"};
    // Color_t NPE_Spec_Color[] = {
    //     kBlack,
    //     kBlue - 10,
    //     kGreen - 2};

    // //0:all selected, 1:true needed, 2:wrong
    // TH1 *h_eCC_NPE_Spec[3];
    // TH1 *h_muCC_NPE_Spec[3];
    // TH1 *h_eCC_Enu_Spec[3];
    // TH1 *h_muCC_Enu_Spec[3];
    // for (int i = 0; i < 3; i++)
    // {
    //     h_eCC_NPE_Spec[i] = new TH1D("NPEeCC" + NPE_Spec_Name[i],
    //                                  "#nu_{e} CC NPE Spectra",
    //                                  NPE_BINNUM_eCC,
    //                                  logNPE_range_eCC[0], logNPE_range_eCC[1]);
    //     h_muCC_NPE_Spec[i] = new TH1D("NPEmuCC" + NPE_Spec_Name[i],
    //                                   "#nu_{#mu} CC NPE Spectra",
    //                                   NPE_BINNUM_muCC,
    //                                   logNPE_range_muCC[0], logNPE_range_muCC[1]);
    //     h_eCC_NPE_Spec[i]->SetXTitle("log_{10}(NPE_{LPMT})");
    //     h_muCC_NPE_Spec[i]->SetXTitle("log_{10}(NPE_{LPMT})");
    //     h_eCC_NPE_Spec[i]->SetYTitle("entries");
    //     h_muCC_NPE_Spec[i]->SetYTitle("entries");
    //     h_eCC_NPE_Spec[i]->SetLineColor(NPE_Spec_Color[i]);
    //     h_muCC_NPE_Spec[i]->SetLineColor(NPE_Spec_Color[i]);
    //     h_eCC_Enu_Spec[i] = new TH1D("Enu_eCC" + NPE_Spec_Name[i],
    //                                  "#nu_{e} CC Neutrino Enegry Spectra",
    //                                  Etrue_BINNUM_eCC,
    //                                  logEtrue_range_eCC[0], logEtrue_range_eCC[1]);
    //     h_muCC_Enu_Spec[i] = new TH1D("Enu_muCC" + NPE_Spec_Name[i],
    //                                   "#nu_{#mu} CC Neutrino Enegry Spectra",
    //                                   Etrue_BINNUM_muCC,
    //                                   logEtrue_range_muCC[0], logEtrue_range_muCC[1]);
    //     h_eCC_Enu_Spec[i]->SetXTitle("log_{10}(E_{#nu}/GeV)");
    //     h_muCC_Enu_Spec[i]->SetXTitle("log_{10}(E_{#nu}/GeV)");
    //     h_eCC_Enu_Spec[i]->SetYTitle("entries");
    //     h_muCC_Enu_Spec[i]->SetYTitle("entries");
    //     h_eCC_Enu_Spec[i]->SetLineColor(NPE_Spec_Color[i]);
    //     h_muCC_Enu_Spec[i]->SetLineColor(NPE_Spec_Color[i]);
    // }

    // TLegend leg_sel[2]->
    // TCanvas *c_Sel_eCC = new TCanvas("Sel_eCC");
    // c_Sel_eCC->cd();
    // double t_evt[NPE_BINNUM_muCC];
    // double Bin_center;
    // for (int i = 0; i < h_eCC_NPE_Spec[0]->GetNbinsX(); i++)
    //     t_evt[i] = h_eCC_NPE_Spec[0]->GetBinContent(i + 1);
    // h_eCC_NPE_Spec[0]->Reset();
    // for (int i = 0; i < NPE_BINNUM_eCC; i++)
    // {
    //     Bin_center = h_eCC_NPE_Spec[0]->GetBinCenter(i + 1);
    //     for (int j = 0; j < Expected_evt_NUM_eCC[i]; j++)
    //         h_eCC_NPE_Spec[0]->Fill(Bin_center, t_evt[i] / Expected_evt_NUM_eCC[i]);
    // }
    // h_eCC_NPE_Spec[0]->SetMarkerColor(kBlack);
    // h_eCC_NPE_Spec[0]->SetMarkerSize(1.5);
    // h_eCC_NPE_Spec[0]->Draw("E1");
    // for (int i = 0; i < 3; i++)
    // {
    //     if (i > 0)
    //         h_eCC_NPE_Spec[i]->SetFillColor(NPE_Spec_Color[i]);
    //     leg_sel[0]->AddEntry(h_eCC_NPE_Spec[i], "#nu_{e}: " + NPE_Spec_Name[i] + " part");
    //     h_eCC_NPE_Spec[i]->Draw("SAME");
    // }
    // h_eCC_NPE_Spec[0]->Draw("SAME E1");
    // leg_sel[0]->DrawClone("SAME");

    // TCanvas *c_Sel_mu = new TCanvas("Sel_muCC");
    // c_Sel_mu->cd();
    // for (int i = 0; i < h_muCC_NPE_Spec[0]->GetNbinsX(); i++)
    //     t_evt[i] = h_muCC_NPE_Spec[0]->GetBinContent(i + 1);
    // h_muCC_NPE_Spec[0]->Reset();
    // for (int i = 0; i < NPE_BINNUM_muCC; i++)
    // {
    //     Bin_center = h_muCC_NPE_Spec[0]->GetBinCenter(i + 1);
    //     for (int j = 0; j < Expected_evt_NUM_muCC[i]; j++)
    //         h_muCC_NPE_Spec[0]->Fill(Bin_center, t_evt[i] / Expected_evt_NUM_muCC[i]);
    // }
    // h_muCC_NPE_Spec[0]->SetMarkerColor(kBlack);
    // h_muCC_NPE_Spec[0]->SetMarkerSize(1.5);
    // h_muCC_NPE_Spec[0]->Draw("E1");
    // for (int i = 0; i < 3; i++)
    // {
    //     if (i > 0)
    //         h_muCC_NPE_Spec[i]->SetFillColor(NPE_Spec_Color[i]);
    //     leg_sel[1]->AddEntry(h_muCC_NPE_Spec[i], "#nu_{#mu}: " + NPE_Spec_Name[i] + " part");
    //     h_muCC_NPE_Spec[i]->Draw("SAME");
    // }
    // h_muCC_NPE_Spec[0]->Draw("SAME E1");
    // leg_sel[1]->DrawClone("SAME");

    // h_muCC_NPE_Spec[0]->Draw("E");
    // h_muCC_Etrue_NPE->Draw("colz");
    // h_eCC_Etrue_NPE->Draw("colz");
}