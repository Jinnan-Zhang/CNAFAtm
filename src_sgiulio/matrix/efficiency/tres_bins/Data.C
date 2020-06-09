#define Data_cxx
#include "Data.h"
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

void Data::Loop()
{
   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;

   static const float lowNPE_Nue = 5.0;
   static const float upNPE_Nue = 7.2;
   static const float lowNPE_Numu = 5.7;
   static const float upNPE_Numu = 7.2;
   static const int NPEBINS_Nue = 7;
   static const int NPEBINS_Numu = 8;
   TFile *f_out = new TFile("Tres_bins_DATA.root","RECREATE");
   TH1F* Nuesel_CC_Tres_Nue_h[NPEBINS_Nue];
   TH1F* Nuesel_CC_Tres_Numu_h[NPEBINS_Nue];
   TH1F* Nuesel_NC_Tres_h[NPEBINS_Nue];
   TH1F* Numusel_CC_Tres_Nue_h[NPEBINS_Numu];
   TH1F* Numusel_CC_Tres_Numu_h[NPEBINS_Numu];
   TH1F* Numusel_NC_Tres_h[NPEBINS_Numu];
   for (int hh=0; hh<NPEBINS_Nue; hh++) {
     char *Nuesel_histnameNuECC= new char[128];
     sprintf(Nuesel_histnameNuECC, "tres_Nuesel_NueCC_%i_h", hh);
     Nuesel_CC_Tres_Nue_h[hh] = new TH1F(Nuesel_histnameNuECC, "",110,40.,150.);
     Nuesel_CC_Tres_Nue_h[hh]->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
     Nuesel_CC_Tres_Nue_h[hh]->GetYaxis()->SetTitle("entries");
     Nuesel_CC_Tres_Nue_h[hh]->SetLineWidth(3);
     Nuesel_CC_Tres_Nue_h[hh]->SetLineColor(kRed);
     char *Nuesel_histnameNumuCC= new char[128];
     sprintf(Nuesel_histnameNumuCC, "tres_Nuesel_NumuCC_%i_h", hh);
     Nuesel_CC_Tres_Numu_h[hh] = new TH1F(Nuesel_histnameNumuCC, "",110,40.,150.);
     Nuesel_CC_Tres_Numu_h[hh]->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
     Nuesel_CC_Tres_Numu_h[hh]->GetYaxis()->SetTitle("entries");
     Nuesel_CC_Tres_Numu_h[hh]->SetLineWidth(3);
     Nuesel_CC_Tres_Numu_h[hh]->SetLineColor(kBlue+2);
     char *Nuesel_histnameNuNC= new char[128];
     sprintf(Nuesel_histnameNuNC, "tres_Nuesel_NuNC_%i_h", hh);
     Nuesel_NC_Tres_h[hh] = new TH1F(Nuesel_histnameNuNC, "",110,40.,150.);
     Nuesel_NC_Tres_h[hh]->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
     Nuesel_NC_Tres_h[hh]->GetYaxis()->SetTitle("entries");
     Nuesel_NC_Tres_h[hh]->SetLineWidth(3);
     Nuesel_NC_Tres_h[hh]->SetLineColor(kSpring-1);
   }
   for (int qq=0; qq<NPEBINS_Numu; qq++) {
     char *Numusel_histnameNuECC= new char[128];
     sprintf(Numusel_histnameNuECC, "tres_Numusel_NueCC_%i_h", qq);
     Numusel_CC_Tres_Nue_h[qq] = new TH1F(Numusel_histnameNuECC, "",110,40.,150.);
     Numusel_CC_Tres_Nue_h[qq]->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
     Numusel_CC_Tres_Nue_h[qq]->GetYaxis()->SetTitle("entries");
     Numusel_CC_Tres_Nue_h[qq]->SetLineWidth(3);
     Numusel_CC_Tres_Nue_h[qq]->SetLineColor(kRed);
     char *Numusel_histnameNumuCC= new char[128];
     sprintf(Numusel_histnameNumuCC, "tres_Numusel_NumuCC_%i_h", qq);
     Numusel_CC_Tres_Numu_h[qq] = new TH1F(Numusel_histnameNumuCC, "",110,40.,150.);
     Numusel_CC_Tres_Numu_h[qq]->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
     Numusel_CC_Tres_Numu_h[qq]->GetYaxis()->SetTitle("entries");
     Numusel_CC_Tres_Numu_h[qq]->SetLineWidth(3);
     Numusel_CC_Tres_Numu_h[qq]->SetLineColor(kBlue+2);
     char *Numusel_histnameNuNC= new char[128];
     sprintf(Numusel_histnameNuNC, "tres_Numusel_NuNC_%i_h", qq);
     Numusel_NC_Tres_h[qq] = new TH1F(Numusel_histnameNuNC, "",110,40.,150.);
     Numusel_NC_Tres_h[qq]->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
     Numusel_NC_Tres_h[qq]->GetYaxis()->SetTitle("entries");
     Numusel_NC_Tres_h[qq]->SetLineWidth(3);
     Numusel_NC_Tres_h[qq]->SetLineColor(kSpring-1);
   }
   float nue_step = ((upNPE_Nue-lowNPE_Nue)/NPEBINS_Nue);
   float numu_step = ((upNPE_Numu-lowNPE_Numu)/NPEBINS_Numu);

   std::cout << "Looping over " << fChain->GetEntriesFast() << " entries... " << std::endl;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     //for (Long64_t jentry=0; jentry<10000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if (jentry%1000==0) std::cout <<"processing event "<<jentry<<std::endl;

      if (newVradius>=16000. || trueNPE_LPMT_WP>=60.) continue; // fiducial cuts

      /////////////////////NuE SELECTION//////////////////
      for (int ii=0; ii<NPEBINS_Nue; ii++) {
	if( log10(trueNPE_LPMT_CD) > (lowNPE_Nue + (ii*nue_step)) && log10(trueNPE_LPMT_CD) <= (lowNPE_Nue + ((ii+1)*nue_step)) ) {
	  if(CCint==1 && abs(init_nuID) == 12) Nuesel_CC_Tres_Nue_h[ii]->Fill(Tres_RMS, P_surv);
	  if(CCint==1 && abs(init_nuID) == 14) Nuesel_CC_Tres_Numu_h[ii]->Fill(Tres_RMS, P_surv);
	  if(NCint==1) Nuesel_NC_Tres_h[ii]->Fill(Tres_RMS, P_surv);
	  break;
	}
      }

      /////////////////////NuMu SELECTION//////////////////
      for (int ii=0; ii<NPEBINS_Numu; ii++) {
        if( log10(trueNPE_LPMT_CD) > (lowNPE_Numu + (ii*numu_step)) && log10(trueNPE_LPMT_CD) <= (lowNPE_Numu + ((ii+1)*numu_step)) ) {
          if(CCint==1 && abs(init_nuID) == 12) Numusel_CC_Tres_Nue_h[ii]->Fill(Tres_RMS, P_surv);
          if(CCint==1 && abs(init_nuID) == 14) Numusel_CC_Tres_Numu_h[ii]->Fill(Tres_RMS, P_surv);
          if(NCint==1) Numusel_NC_Tres_h[ii]->Fill(Tres_RMS, P_surv);
          break;
        }
      }

   } //end of loop on events

   for (int jj=0; jj<NPEBINS_Nue; jj++) {
     Nuesel_CC_Tres_Nue_h[jj]->Write();
     Nuesel_CC_Tres_Numu_h[jj]->Write();
     Nuesel_NC_Tres_h[jj]->Write();
   }
   for (int jj=0; jj<NPEBINS_Numu; jj++) {
     Numusel_CC_Tres_Nue_h[jj]->Write();
     Numusel_CC_Tres_Numu_h[jj]->Write();
     Numusel_NC_Tres_h[jj]->Write();
   }
   std::cout << "file Tres_bins.root created" << std::endl;
   f_out->Close();

}
