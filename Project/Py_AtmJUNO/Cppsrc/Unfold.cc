/*
Purpose: to inplement the bayes unfolding procedure.
Author: Jinnan Zhang: jinnan.zhang@ihep.ac.cn
2020.07.21
*/

#include <TChain.h>
#include <TROOT.h>
#include <TTree.h>
#include <TFile.h>
#include <TSelector.h>
#include <TH1.h>
#include <TH2.h>
#include <TEntryList.h>
#include <TF1.h>
#include "TStyle.h"
#include "TCanvas.h"
#include "TPaveStats.h"
#include "TLine.h"
#include "TMath.h"
#include <vector>
#include <string>
#include <fstream>

void LoadFile(std::string filename, std::vector<std::vector<double>> &v, int Length = 2, int SkipLines = 0);
void BayesUnfold(int Iter_NUM = 1);
void Iter_Bayes_Once(TH1 *h_input, TH1 *h_prior, TH2 *h_Likelihd_M, TH1 *h_output, double *epsilon_i);
const int Expected_evt_NUM_eCC[] = {40, 100, 125, 135, 80, 45, 20};
const int Expected_evt_NUM_muCC[] = {55, 237, 231, 171, 100, 48,17};

int Unfold()
{
    BayesUnfold(1000);
    return 0;
}

//apply Bayesian iterration to unfold the spectras
void BayesUnfold(int Iter_NUM)
{
    TFile *ff_unfold_data = TFile::Open("../data/UnfoldData.root", "READ");
    TH2 *h_likeli_eCC = (TH2 *)ff_unfold_data->Get("eCC_Likely_hood");
    TH2 *h_likeli_muCC = (TH2 *)ff_unfold_data->Get("muCC_Likely_hood");
    TH1 *h_sel_eCC = (TH1 *)ff_unfold_data->Get("NPEeCCSel.");
    TH1 *h_sel_muCC = (TH1 *)ff_unfold_data->Get("NPEmuCCSel.");
    TH1 *h_Prior_eCC = (TH1 *)ff_unfold_data->Get("Honda_flux_e");
    TH1 *h_Prior_muCC = (TH1 *)ff_unfold_data->Get("Honda_flux_mu");
    TH1 *h_MC_true_eCC = (TH1 *)ff_unfold_data->Get("Enu_eCCTrue");
    TH1 *h_MC_true_muCC = (TH1 *)ff_unfold_data->Get("Enu_muCCTrue");
    TH1 *h_eCC_result = (TH1 *)h_Prior_eCC->Clone("eCC_result");
    TH1 *h_muCC_result = (TH1 *)h_Prior_muCC->Clone("muCC_result");
    const int Enu_BINNUM_eCC = h_Prior_eCC->GetNbinsX();
    const int Enu_BINNUM_muCC = h_Prior_muCC->GetNbinsX();
    double epsilon_i_eCC[Enu_BINNUM_eCC];
    double epsilon_i_muCC[Enu_BINNUM_muCC];
    for (int i = 0; i < Enu_BINNUM_eCC; i++)
    {
        epsilon_i_eCC[i] = 0;
    }
    for (int i = 0; i < Enu_BINNUM_muCC; i++)
    {
        epsilon_i_muCC[i] = 0;
    }
    // h_Prior_eCC = (TH1 *)h_MC_true_eCC->Clone("eCC_Prior");
    // h_Prior_muCC = (TH1 *)h_MC_true_muCC->Clone("muCC_Prior");
    // h_Prior_eCC->Scale(1 / h_Prior_eCC->Integral());
    // h_Prior_muCC->Scale(1 / h_Prior_muCC->Integral());
    Iter_Bayes_Once(h_sel_eCC, h_Prior_eCC, h_likeli_eCC, h_eCC_result, epsilon_i_eCC);
    Iter_Bayes_Once(h_sel_muCC, h_Prior_muCC, h_likeli_muCC, h_muCC_result, epsilon_i_muCC);
    if (Iter_NUM > 1)
        for (int i = 1; i < Iter_NUM; i++)
        {
            h_Prior_eCC = (TH1 *)h_eCC_result->Clone("eCC_Prior");
            h_Prior_muCC = (TH1 *)h_muCC_result->Clone("muCC_Prior");
            h_Prior_eCC->Scale(1 / h_Prior_eCC->Integral());
            h_Prior_muCC->Scale(1 / h_Prior_muCC->Integral());
            Iter_Bayes_Once(h_sel_eCC, h_Prior_eCC, h_likeli_eCC, h_eCC_result, epsilon_i_eCC);
            Iter_Bayes_Once(h_sel_muCC, h_Prior_muCC, h_likeli_muCC, h_muCC_result, epsilon_i_muCC);
        }
    TCanvas *c_CC_Spec = new TCanvas("muCC_Spec");
    h_muCC_result->SetLineColor(kRed);
    h_muCC_result->Draw();
    h_MC_true_muCC->Draw("SAME");

    TCanvas *c_muCC = new TCanvas("muCC_");
    TH1 *h_ref_muCC = (TH1 *)h_MC_true_muCC->Clone("refLine_muCC");
    TH1 *h_ratio_muCC = (TH1 *)h_MC_true_muCC->Clone("Ratio_muCC");
    h_ref_muCC->Divide(h_MC_true_muCC);
    h_ratio_muCC->Divide(h_muCC_result, h_MC_true_muCC);
    h_ratio_muCC->SetLineColor(kRed);
    h_ratio_muCC->SetMarkerColor(kRed);
    h_ratio_muCC->SetMarkerSize(1.5);
    h_ratio_muCC->SetMarkerStyle(kFullCircle);
    h_ratio_muCC->Draw("E1");
    h_ref_muCC->Draw("SAME");

    TCanvas *c_eCC_Spec = new TCanvas("eCC_Spec");
    h_eCC_result->SetLineColor(kRed);
    h_eCC_result->Draw();
    h_MC_true_eCC->Draw("SAME");
    // h_MC_true_eCC->Draw();

    TCanvas *c_eCC = new TCanvas("eCC_");
    TH1 *h_ref_eCC = (TH1 *)h_MC_true_eCC->Clone("refLine_eCC");
    TH1 *h_ratio_eCC = (TH1 *)h_MC_true_eCC->Clone("Ratio_eCC");
    h_ref_eCC->Divide(h_MC_true_eCC);
    h_ratio_eCC->Divide(h_eCC_result, h_MC_true_eCC);
    h_ratio_eCC->SetLineColor(kRed);
    h_ratio_eCC->SetMarkerColor(kRed);
    h_ratio_eCC->SetMarkerSize(1.5);
    h_ratio_eCC->SetMarkerStyle(kFullCircle);
    h_ratio_eCC->Draw("E1");
    h_ref_eCC->Draw("SAME");
}

//input NPE spectra and prios disribution,
//output neutrino spectra
void Iter_Bayes_Once(TH1 *h_input,
                     TH1 *h_prior,
                     TH2 *h_Likelihd_M,
                     TH1 *h_output,
                     double *epsilon_i)
{
    const int NPE_BINNUM = h_input->GetNbinsX();
    const int Enu_BINNUM = h_prior->GetNbinsX();
    double A_ji[NPE_BINNUM][Enu_BINNUM];
    double Response_SUM[Enu_BINNUM];
    for (int i = 0; i < Enu_BINNUM; i++)
    {
        Response_SUM[i] = h_Likelihd_M->Integral(i + 1, i + 1, 1, NPE_BINNUM);
        for (int j = 0; j < NPE_BINNUM; j++)
        {
            //normalize the the likelihood sum of a row to 1-epsilon
            A_ji[j][i] = h_Likelihd_M->GetBinContent(i + 1, j + 1) *
                         (1 - epsilon_i[i]) / Response_SUM[i];
        }
    }
    {
        // for (int i = 0; i < Enu_BINNUM; i++)
        // {
        //     for (int j = 0; j < NPE_BINNUM; j++)
        //     {
        //         printf("A_%d%d: %f\n", j+1, i+1, A_ji[j][i]);
        //     }
        // }
    }

    double U_ij[Enu_BINNUM][NPE_BINNUM];
    double P_0Ei = 0;
    double nominator_i, denominator_i;
    for (int i = 0; i < Enu_BINNUM; i++)
    {
        P_0Ei = h_prior->GetBinContent(i + 1);
        for (int j = 0; j < NPE_BINNUM; j++)
        {
            nominator_i = A_ji[j][i] * P_0Ei;
            denominator_i = 0;
            for (int k = 0; k < Enu_BINNUM; k++)
            {
                denominator_i += (A_ji[j][k] *
                                  h_prior->GetBinContent(k + 1));
            }
            if (denominator_i == 0)
                denominator_i = 1;
            U_ij[i][j] = nominator_i / denominator_i;
        }
    }
    double E_hat = 0;
    double BinCenter = 0;
    h_output->Reset();
    for (int i = 0; i < Enu_BINNUM; i++)
    {
        E_hat = 0;
        for (int j = 0; j < NPE_BINNUM; j++)
        {
            E_hat += (U_ij[i][j] *
                      h_input->GetBinContent(j + 1));
        }
        // printf("E_hat: %f\n", E_hat);
        BinCenter = h_output->GetBinCenter(i + 1);
        // h_output->SetBinContent(i + 1, E_hat);
        // const int stat_NUM = 100;
        if (NPE_BINNUM == 7)
            for (int k = 0; k < Expected_evt_NUM_eCC[i]; k++)
                h_output->Fill(BinCenter, E_hat / Expected_evt_NUM_eCC[i]);
        else
            for (int k = 0; k < Expected_evt_NUM_muCC[i]; k++)
                h_output->Fill(BinCenter, E_hat / Expected_evt_NUM_muCC[i]);
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