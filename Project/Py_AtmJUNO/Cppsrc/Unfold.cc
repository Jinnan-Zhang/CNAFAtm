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
void BayesUnfold();
void Iter_Bayes_Once(TH1 *h_input, TH1 *h_prior, TH2 *h_Likelihd_M, TH1 *h_output, double *epsilon_i);

int Unfold()
{
    BayesUnfold();
    return 0;
}

//apply Bayesian iterration to unfold the spectras
void BayesUnfold()
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
    TH1 *h_ecc_result = (TH1 *)h_Prior_eCC->Clone("eCC_result");
    TH1 *h_mucc_result = (TH1 *)h_Prior_muCC->Clone("muCC_result");
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
    // Iter_Bayes_Once(h_sel_eCC, h_Prior_eCC, h_likeli_eCC, h_ecc_result, epsilon_i_eCC);
    Iter_Bayes_Once(h_sel_muCC, h_Prior_muCC, h_likeli_muCC, h_mucc_result, epsilon_i_muCC);
    // h_Prior_muCC->Draw();
    h_mucc_result->SetLineColor(kRed);
    h_mucc_result->Draw();
    h_MC_true_muCC->Draw("SAME");
    
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
            U_ij[i][j] = nominator_i / denominator_i;
        }
    }
    double E_hat = 0;
    for (int i = 0; i < Enu_BINNUM; i++)
    {
        E_hat = 0;
        for (int j = 0; j < NPE_BINNUM; j++)
        {
            E_hat += (U_ij[i][j] *
                      h_input->GetBinContent(j + 1));
        }
        h_output->SetBinContent(i + 1, E_hat);
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