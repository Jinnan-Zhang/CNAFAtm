#define Data_cxx
#include "Data.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Data::Loop()
{
  static const int NBINS = 1000; 
  static const float TRES_MIN = 50.;
  static const float TRES_MAX = 300.;
  static const float TRES_MAX2 = 280.;

  TH1F *Tres_nue_Nuecut = new TH1F("Tres_nue_Nuecut","",NBINS,TRES_MIN,TRES_MAX);
  TH1F *Tres_nue_Numucut = new TH1F("Tres_nue_Numucut","",NBINS,TRES_MIN,TRES_MAX);
  TH1F *Tres_nue = new TH1F("Tres_nue","",NBINS,TRES_MIN,TRES_MAX);
  TH1F *Tres_numu_Numucut = new TH1F("Tres_numu_Numucut","",NBINS,TRES_MIN,TRES_MAX);
  TH1F *Tres_numu_Nuecut = new TH1F("Tres_numu_Nuecut","",NBINS,TRES_MIN,TRES_MAX);
  TH1F *Tres_numu = new TH1F("Tres_numu","",NBINS,TRES_MIN,TRES_MAX);
  char *ext_filename = new char[128];
  sprintf(ext_filename, "effcontplots.root");
  TFile *f_out = new TFile(ext_filename, "RECREATE");
  Float_t norm_all_Nue = 0;
  Float_t norm_all_Numu = 0;

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   std::cout << "Looping over " << fChain->GetEntriesFast() << " entries... " << std::endl;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     if (jentry%1000==0) std::cout <<"processing event "<<jentry<<std::endl;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      //if (abs(init_nuID)==12 && log10(trueNPE_LPMT_CD)>5.0 && newVradius<16000. && trueNPE_LPMT_WP<60.) Tres_nue_fidcuts->Fill(Tres_RMS);
      //if (abs(init_nuID)==14 && log10(trueNPE_LPMT_CD)>5.85 && newVradius<16000. && trueNPE_LPMT_WP<60.) Tres_nue_fidcuts->Fill(Tres_RMS);
      if (abs(init_nuID)==12) {
	norm_all_Nue += P_surv;
	if (log10(trueNPE_LPMT_CD)>5.0 && newVradius<16000. && trueNPE_LPMT_WP<60.) Tres_nue_Nuecut->Fill(Tres_RMS, P_surv);
	if (log10(trueNPE_LPMT_CD)>5.85 && newVradius<16000. && trueNPE_LPMT_WP<60.) Tres_nue_Numucut->Fill(Tres_RMS, P_surv);
	//if (log10(trueNPE_LPMT_CD)>5.0 && newVradius<16000. && trueNPE_LPMT_WP<60.) Tres_nue_Nuecut->Fill(Tres_RMS, P_surv);
	//if (log10(trueNPE_LPMT_CD)>5.85 && newVradius<16000. && trueNPE_LPMT_WP<60.) 
      }
      if (abs(init_nuID)==14) {
	norm_all_Numu += P_surv;
	if (log10(trueNPE_LPMT_CD)>5.0 && newVradius<16000. && trueNPE_LPMT_WP<60.) Tres_numu_Nuecut->Fill(Tres_RMS, P_surv);
	if (log10(trueNPE_LPMT_CD)>5.85 && newVradius<16000. && trueNPE_LPMT_WP<60.) Tres_numu_Numucut->Fill(Tres_RMS, P_surv);
      }
   }

   TH1F *Tres_nue_Nuecut_cumul = (TH1F*)Tres_nue_Nuecut->GetCumulative(kTRUE);
   TH1F *Tres_nue_Numucut_cumul = (TH1F*)Tres_nue_Numucut->GetCumulative(kFALSE);
   TH1F *Tres_numu_Numucut_cumul = (TH1F*)Tres_numu_Numucut->GetCumulative(kFALSE);
   TH1F *Tres_numu_Nuecut_cumul = (TH1F*)Tres_numu_Nuecut->GetCumulative(kTRUE);
   Float_t efficiency_nue[NBINS] = {0.};
   Float_t contamination_nue[NBINS] = {0.};
   Float_t revcontamination_nue[NBINS] = {0.};
   Float_t tres_value[NBINS] = {0.};
   Float_t efficiency_numu[NBINS] = {0.};
   Float_t contamination_numu[NBINS] = {0.};
   Float_t revcontamination_numu[NBINS] = {0.};
   Float_t tres_value_numu[NBINS] = {0.};

   for(int i=0; i<NBINS; i++) {
     tres_value[i] = (TRES_MIN+(((TRES_MAX-TRES_MIN)/NBINS)*(i)));
     if((Tres_nue_Nuecut_cumul->GetBinContent(i+1))==0) {
       contamination_nue[i-1] = 1.;      
       revcontamination_nue[i-1] = 0.;
     } else {
     efficiency_nue[i] = ((Tres_nue_Nuecut_cumul->GetBinContent(i+1))/float(norm_all_Nue));
     contamination_nue[i] = ((Tres_numu_Nuecut_cumul->GetBinContent(i+1))/((Tres_nue_Nuecut_cumul->GetBinContent(i+1))+(Tres_numu_Nuecut_cumul->GetBinContent(i+1))));
     }
     revcontamination_nue[i] = (1. - contamination_nue[i]);
     ////////////////////////////////////////////////////
     if((Tres_numu_Numucut_cumul->GetBinContent(i+1))==0) {
       contamination_numu[i-1] = 1.;      
       revcontamination_numu[i-1] = 0.;
     } else {
     efficiency_numu[i] = ((Tres_numu_Numucut_cumul->GetBinContent(i+1))/float(norm_all_Numu));
     contamination_numu[i] = ((Tres_nue_Numucut_cumul->GetBinContent(i+1))/((Tres_nue_Numucut_cumul->GetBinContent(i+1))+(Tres_numu_Numucut_cumul->GetBinContent(i+1))));
     }
     revcontamination_numu[i] = (1. - contamination_numu[i]);
   }

   TGraph *ROC_NUE = new TGraph(NBINS,revcontamination_nue,efficiency_nue);
   ROC_NUE->SetMarkerStyle(20);
   ROC_NUE->SetMarkerSize(0.65);
   ROC_NUE->SetMarkerColor(kRed);
   ROC_NUE->GetXaxis()->SetTitle("1 - contamination");
   ROC_NUE->GetYaxis()->SetTitle("efficiency");
   TCanvas *cRoc_Nue = new TCanvas("cRoc_Nue","ROC_NUE Curve",0,0,800,700);
   cRoc_Nue->cd();
   ROC_NUE->Draw("AP");
   cRoc_Nue->SaveAs("Plot/ROC_nue.pdf");
   cRoc_Nue->SaveAs("Plot/ROC_nue.png");
   TLegend * leg1 = new TLegend(0.6,0.2,0.9,0.4);
   TGraph *Eff_NUE = new TGraph(NBINS,tres_value,efficiency_nue);
   Eff_NUE->SetMarkerStyle(20);
   Eff_NUE->SetMarkerSize(0.65);
   Eff_NUE->SetLineWidth(5);
   Eff_NUE->SetLineColor(kMagenta);
   //Eff_NUE->GetYaxis()->SetTitle("efficiency");
   Eff_NUE->GetXaxis()->SetTitle("#sigma(t_{RES})");
   TGraph *Cont_NUE = new TGraph(NBINS,tres_value,contamination_nue);
   Cont_NUE->SetMarkerStyle(20);
   Cont_NUE->SetMarkerSize(0.65);
   Cont_NUE->SetLineWidth(5);
   Cont_NUE->SetLineColor(kGreen+3);
   //Cont_NUE->GetYaxis()->SetTitle("contamination");
   Cont_NUE->GetXaxis()->SetTitle("#sigma(t_{RES})");
   TCanvas *cEff_Cont_Nue = new TCanvas("cEff_Cont_Nue","Efficiency - Contamination curves for NuE",0,0,1000,800);
   cEff_Cont_Nue->cd();
   Eff_NUE->Draw("AL");
   leg1->AddEntry(Eff_NUE, "efficiency" ,"l");
   Cont_NUE->Draw("same");
   leg1->AddEntry(Cont_NUE, "contamination" ,"l");
   leg1->Draw();
   cEff_Cont_Nue->SaveAs("Plot/Eff-Cont_VS_tres_nue.pdf");
   cEff_Cont_Nue->SaveAs("Plot/Eff-Cont_VS_tres_nue.png");
   ///////////////////////////////////////////////////////////////////////////////
   TGraph *ROC_NUMU = new TGraph(NBINS,revcontamination_numu,efficiency_numu);
   ROC_NUMU->SetMarkerStyle(20);
   ROC_NUMU->SetMarkerSize(0.65);
   ROC_NUMU->SetMarkerColor(kRed);
   ROC_NUMU->GetXaxis()->SetTitle("1 - contamination");
   ROC_NUMU->GetYaxis()->SetTitle("efficiency");
   TCanvas *cRoc_Numu = new TCanvas("cRoc_Numu","ROC_NUMU Curve",0,0,800,700);
   cRoc_Numu->cd();
   ROC_NUMU->Draw("AP");
   cRoc_Numu->SaveAs("Plot/ROC_numu.pdf");
   cRoc_Numu->SaveAs("Plot/ROC_numu.png");
   TLegend * leg2 = new TLegend(0.6,0.2,0.9,0.4);
   TGraph *Eff_NUMU = new TGraph(NBINS,tres_value,efficiency_numu);
   Eff_NUMU->SetMarkerStyle(20);
   Eff_NUMU->SetMarkerSize(0.65);
   Eff_NUMU->SetLineWidth(5);
   Eff_NUMU->SetLineColor(kMagenta);
   //Eff_NUMU->GetYaxis()->SetTitle("efficiency");
   Eff_NUMU->GetXaxis()->SetTitle("#sigma(t_{RES})");
   TGraph *Cont_NUMU = new TGraph(NBINS,tres_value,contamination_numu);
   Cont_NUMU->SetMarkerStyle(20);
   Cont_NUMU->SetMarkerSize(0.65);
   Cont_NUMU->SetLineWidth(5);
   Cont_NUMU->SetLineColor(kGreen+3);
   //Cont_NUMU->GetYaxis()->SetTitle("contamination");
   Cont_NUMU->GetXaxis()->SetTitle("#sigma(t_{RES})");
   TCanvas *cEff_Cont_Numu = new TCanvas("cEff_Cont_Numu","Efficiency - Contamination curves for NuMu",0,0,1000,800);
   cEff_Cont_Numu->cd();
   Eff_NUMU->Draw("AL");
   leg2->AddEntry(Eff_NUMU, "efficiency" ,"l");
   Cont_NUMU->Draw("same");
   leg2->AddEntry(Cont_NUMU, "contamination" ,"l");
   leg2->Draw();
   cEff_Cont_Numu->SaveAs("Plot/Eff-Cont_VS_tres_numu.pdf");
   cEff_Cont_Numu->SaveAs("Plot/Eff-Cont_VS_tres_numu.png");
   ///////////////////////////////////////////////////////////////////////////////

   std::cout << ext_filename << " created" << std::endl;
   f_out->Close();
}
