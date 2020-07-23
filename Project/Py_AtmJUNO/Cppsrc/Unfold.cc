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

int Unfold()
{
    BayesUnfold();
    return 0;
}

//apply Bayesian iterration to unfold the spectras
void BayesUnfold()
{

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