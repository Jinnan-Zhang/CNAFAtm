#define Data_cxx
#include "Data.h"
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

void Data::Loop()
{
  gStyle->SetOptStat(0);
  gStyle->SetPadBottomMargin(0.12);
  gStyle->SetTitleH(0.1);
  gStyle->SetTitleW(1.05);
   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;

   float Nevt_nue = 0;
   float Nevt_numu = 0;
   float Nevt_nue_fidcut1 = 0;
   float Nevt_numu_fidcut1 = 0;
   float Nevt_nue_fidcut2 = 0;
   float Nevt_numu_fidcut2 = 0;
   float Nevt_nue_fidcut3 = 0;
   float Nevt_numu_fidcut3 = 0;
   float Nevt_nue_fidcut12 = 0;
   float Nevt_nue_fidcut13 = 0;
   float Nevt_numu_fidcut12 = 0;
   float Nevt_numu_fidcut13 = 0;
   float Nevt_nue_fidcut123 = 0;
   float Nevt_numu_fidcut123 = 0;

   float Nevt_nue_nuecut = 0;
   float Nevt_nue_numucut = 0;
   float Nevt_numu_numucut = 0;
   float Nevt_numu_nuecut = 0;

   //TFile *f_out = new TFile("Tres_plot.root","RECREATE");
   TLegend * leg11 = new TLegend(0.65,0.87,0.87,0.5);
   leg11->SetBorderSize(0);
   TH1F *Tres_RMS_numuCC_1 = new TH1F("Tres_RMS_numuCC_1","",200,0.,200.);
   Tres_RMS_numuCC_1->SetLineWidth(3);
   Tres_RMS_numuCC_1->SetLineColor(kBlue+2);
   //Tres_RMS_numuCC_1->GetYaxis()->SetRangeUser(0,110);
   TH1F *Tres_RMS_nueCC_1 = new TH1F("Tres_RMS_nueCC_1","",200,0.,200.);
   Tres_RMS_nueCC_1->SetLineWidth(3);
   Tres_RMS_nueCC_1->SetLineColor(kRed);
   TH1F *Tres_RMS_nuNC_1 = new TH1F("Tres_RMS_nuNC_1","",200,0.,200.);
   Tres_RMS_nuNC_1->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
   Tres_RMS_nuNC_1->GetYaxis()->SetTitle("entries");
   Tres_RMS_nuNC_1->GetYaxis()->SetTitleOffset(1.5);
   Tres_RMS_nuNC_1->GetXaxis()->SetTitleSize(0.055);
   Tres_RMS_nuNC_1->GetXaxis()->SetLabelSize(0.047);
   Tres_RMS_nuNC_1->GetYaxis()->SetLabelSize(0.047);
   Tres_RMS_nuNC_1->GetXaxis()->SetRangeUser(40,150);
   Tres_RMS_nuNC_1->GetXaxis()->SetLabelSize(0.06);
   Tres_RMS_nuNC_1->SetLineWidth(3);
   Tres_RMS_nuNC_1->SetLineColor(kSpring-1);
   Tres_RMS_nuNC_1->SetTitle("10^{5} < NPE < 4.73 #times 10^{5}");

   ////////////////////////////////////

   TLegend * leg12 = new TLegend(0.65,0.87,0.87,0.5);
   leg12->SetBorderSize(0);
   TH1F *Tres_RMS_numuCC_2 = new TH1F("Tres_RMS_numuCC_2","",200,0.,200.);
   Tres_RMS_numuCC_2->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
   Tres_RMS_numuCC_2->GetYaxis()->SetTitle("entries");
   Tres_RMS_numuCC_2->GetYaxis()->SetTitleOffset(1.5);
   Tres_RMS_numuCC_2->GetXaxis()->SetTitleSize(0.055);
   Tres_RMS_numuCC_2->GetXaxis()->SetLabelSize(0.047);
   Tres_RMS_numuCC_2->GetYaxis()->SetLabelSize(0.047);
   Tres_RMS_numuCC_2->GetXaxis()->SetRangeUser(40,150);
   Tres_RMS_numuCC_2->GetXaxis()->SetLabelSize(0.06);
   Tres_RMS_numuCC_2->SetLineWidth(3);
   Tres_RMS_numuCC_2->SetLineColor(kBlue+2);
   Tres_RMS_numuCC_2->SetTitle("4.73 #times 10^{5} < NPE < 1.01 #times 10^{6}");
   TH1F *Tres_RMS_nueCC_2 = new TH1F("Tres_RMS_nueCC_2","",200,0.,200.);
   Tres_RMS_nueCC_2->SetLineWidth(3);
   Tres_RMS_nueCC_2->SetLineColor(kRed);
   TH1F *Tres_RMS_nuNC_2 = new TH1F("Tres_RMS_nuNC_2","",200,0.,200.);
   Tres_RMS_nuNC_2->SetLineWidth(3);
   Tres_RMS_nuNC_2->SetLineColor(kSpring-1);

   ////////////////////////////////////

   TLegend * leg13 = new TLegend(0.65,0.87,0.87,0.5);
   leg13->SetBorderSize(0);
   TH1F *Tres_RMS_numuCC_3 = new TH1F("Tres_RMS_numuCC_3","",200,0.,200.);
   Tres_RMS_numuCC_3->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
   Tres_RMS_numuCC_3->GetYaxis()->SetTitle("entries");
   Tres_RMS_numuCC_3->GetYaxis()->SetTitleOffset(1.5);
   Tres_RMS_numuCC_3->GetXaxis()->SetTitleSize(0.055);
   Tres_RMS_numuCC_3->GetXaxis()->SetLabelSize(0.047);
   Tres_RMS_numuCC_3->GetYaxis()->SetLabelSize(0.047);  
   Tres_RMS_numuCC_3->SetLineWidth(3);
   Tres_RMS_numuCC_3->SetLineColor(kBlue+2);
   Tres_RMS_numuCC_3->GetXaxis()->SetRangeUser(40,150);
   Tres_RMS_numuCC_3->GetXaxis()->SetLabelSize(0.06);
   Tres_RMS_numuCC_3->SetTitle("1.01 #times 10^{6} < NPE < 2.32 #times 10^{6}");
   TH1F *Tres_RMS_nueCC_3 = new TH1F("Tres_RMS_nueCC_3","",200,0.,200.);
   Tres_RMS_nueCC_3->SetLineWidth(3);
   Tres_RMS_nueCC_3->SetLineColor(kRed);
   TH1F *Tres_RMS_nuNC_3 = new TH1F("Tres_RMS_nuNC_3","",200,0.,200.);
   Tres_RMS_nuNC_3->SetLineWidth(3);
   Tres_RMS_nuNC_3->SetLineColor(kSpring-1);

   ////////////////////////////////////

   TLegend * leg14 = new TLegend(0.65,0.87,0.87,0.5);
   leg14->SetBorderSize(0);
   TH1F *Tres_RMS_numuCC_4 = new TH1F("Tres_RMS_numuCC_4","",200,0.,200.);
   Tres_RMS_numuCC_4->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
   Tres_RMS_numuCC_4->GetYaxis()->SetTitle("entries");
   Tres_RMS_numuCC_4->GetYaxis()->SetTitleOffset(1.5);
   Tres_RMS_numuCC_4->GetXaxis()->SetTitleSize(0.055);
   Tres_RMS_numuCC_4->GetXaxis()->SetLabelSize(0.047);
   Tres_RMS_numuCC_4->GetYaxis()->SetLabelSize(0.047);  
   Tres_RMS_numuCC_4->SetLineWidth(3);
   Tres_RMS_numuCC_4->SetLineColor(kBlue+2);
   Tres_RMS_numuCC_4->GetXaxis()->SetRangeUser(40,150);
   Tres_RMS_numuCC_4->GetXaxis()->SetLabelSize(0.06);
   Tres_RMS_numuCC_4->SetTitle("2.32 #times 10^{6} < NPE < 1.58 #times 10^{7}");
   TH1F *Tres_RMS_nueCC_4 = new TH1F("Tres_RMS_nueCC_4","",200,0.,200.);
   Tres_RMS_nueCC_4->SetLineWidth(3);
   Tres_RMS_nueCC_4->SetLineColor(kRed);
   TH1F *Tres_RMS_nuNC_4 = new TH1F("Tres_RMS_nuNC_4","",200,0.,200.);
   Tres_RMS_nuNC_4->SetLineWidth(3);
   Tres_RMS_nuNC_4->SetLineColor(kSpring-1);
   //////////////////////////////////////////////////////////////////

   std::cout << "Looping over " << fChain->GetEntriesFast() << " entries... " << std::endl;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     //for (Long64_t jentry=0; jentry<10000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if (jentry%1000==0) std::cout <<"processing event "<<jentry<<std::endl;

      if (abs(init_nuID)==12) Nevt_nue += P_surv;
      if (abs(init_nuID)==12 && newVradius<16000.) Nevt_nue_fidcut1 += P_surv;
      if (abs(init_nuID)==12 && trueNPE_LPMT_CD > 1.E5) Nevt_nue_fidcut2 += P_surv;
      if (abs(init_nuID)==12 && trueNPE_LPMT_WP < 60.) Nevt_nue_fidcut3 += P_surv;
      if (abs(init_nuID)==12 && newVradius<16000. && trueNPE_LPMT_CD > 1.E5) Nevt_nue_fidcut12 += P_surv;
      if (abs(init_nuID)==12 && newVradius<16000. && trueNPE_LPMT_WP < 60.) Nevt_nue_fidcut13 += P_surv;
      if (abs(init_nuID)==12 && newVradius<16000. && trueNPE_LPMT_WP < 60. && trueNPE_LPMT_CD > 1.E5) Nevt_nue_fidcut123 += P_surv;
      if (abs(init_nuID)==12 && newVradius<16000. && trueNPE_LPMT_WP < 60. && trueNPE_LPMT_CD > 1.E5 && Tres_RMS < 75.) Nevt_nue_nuecut += P_surv;
      if (abs(init_nuID)==14 && newVradius<16000. && trueNPE_LPMT_WP < 60. && trueNPE_LPMT_CD > 1.E5 && Tres_RMS < 75.) Nevt_numu_nuecut += P_surv;
      //////////////////////////////////////////////////////////////////////////////////////////////
      if (abs(init_nuID)==14) Nevt_numu += P_surv;
      if (abs(init_nuID)==14 && newVradius<16000.) Nevt_numu_fidcut1 += P_surv;
      if (abs(init_nuID)==14 && trueNPE_LPMT_CD > 1.E5) Nevt_numu_fidcut2 += P_surv;
      if (abs(init_nuID)==14 && trueNPE_LPMT_WP < 60.) Nevt_numu_fidcut3 += P_surv;
      if (abs(init_nuID)==14 && newVradius<16000. && trueNPE_LPMT_CD > 1.E5) Nevt_numu_fidcut12 += P_surv;
      if (abs(init_nuID)==14 && newVradius<16000. && trueNPE_LPMT_WP < 60.) Nevt_numu_fidcut13 += P_surv;
      if (abs(init_nuID)==14 && newVradius<16000. && trueNPE_LPMT_WP < 60. && trueNPE_LPMT_CD > 1.E5) Nevt_numu_fidcut123 += P_surv;
      if (abs(init_nuID)==14 && newVradius<16000. && trueNPE_LPMT_WP < 60. && log10(trueNPE_LPMT_CD) > 5.7 && Tres_RMS > 95.) Nevt_numu_numucut += P_surv;
      if (abs(init_nuID)==12 && newVradius<16000. && trueNPE_LPMT_WP < 60. && log10(trueNPE_LPMT_CD) > 5.7 && Tres_RMS > 95.) Nevt_nue_numucut += P_surv;

      if (newVradius>=16000. || trueNPE_LPMT_WP>=60.) continue; // fiducial cuts

      if (trueNPE_LPMT_CD>1.E5 && trueNPE_LPMT_CD<471520.) {
	if (CCint==1 && abs(init_lepID)==13) Tres_RMS_numuCC_1->Fill(Tres_RMS,P_surv);
	if (CCint==1 && abs(init_lepID)==11) Tres_RMS_nueCC_1->Fill(Tres_RMS,P_surv);
	if (NCint==1) Tres_RMS_nuNC_1->Fill(Tres_RMS,P_surv);
      } else if (trueNPE_LPMT_CD>=471520. && trueNPE_LPMT_CD<1.00221E6) {
	if (CCint==1 && abs(init_lepID)==13) Tres_RMS_numuCC_2->Fill(Tres_RMS,P_surv);
	if (CCint==1 && abs(init_lepID)==11) Tres_RMS_nueCC_2->Fill(Tres_RMS,P_surv);
	if (NCint==1) Tres_RMS_nuNC_2->Fill(Tres_RMS,P_surv);
      } else if (trueNPE_LPMT_CD>=1.00221E6 && trueNPE_LPMT_CD<2.21877E6) {
	if (CCint==1 && abs(init_lepID)==13) Tres_RMS_numuCC_3->Fill(Tres_RMS,P_surv);
	if (CCint==1 && abs(init_lepID)==11) Tres_RMS_nueCC_3->Fill(Tres_RMS,P_surv);
	if (NCint==1) Tres_RMS_nuNC_3->Fill(Tres_RMS,P_surv);
      } else if (trueNPE_LPMT_CD>=2.21877E6) {
	if (CCint==1 && abs(init_lepID)==13) Tres_RMS_numuCC_4->Fill(Tres_RMS,P_surv);
	if (CCint==1 && abs(init_lepID)==11) Tres_RMS_nueCC_4->Fill(Tres_RMS,P_surv);
	if (NCint==1) Tres_RMS_nuNC_4->Fill(Tres_RMS,P_surv);
      }

   } //end of loop on events

   std::cout << "Number of Nue is: " << Nevt_nue << std::endl;
   std::cout << "Number of Nue after fidcut1 is: " << Nevt_nue_fidcut1 << std::endl;
   std::cout << "Number of Nue after fidcut2 is: " << Nevt_nue_fidcut2 << std::endl;
   std::cout << "Number of Nue after fidcut3 is: " << Nevt_nue_fidcut3 << std::endl;
   std::cout << "Number of Nue after fidcut12 is: " << Nevt_nue_fidcut12 << std::endl;
   std::cout << "Number of Nue after fidcut13 is: " << Nevt_nue_fidcut13 << std::endl;
   std::cout << "Number of Nue after fidcut123 is: " << Nevt_nue_fidcut123 << std::endl;
   std::cout << "Number of Nue after nuecuts: " << Nevt_nue_nuecut << std::endl;
   std::cout << "Number of Numu after nuecuts: " << Nevt_numu_nuecut << std::endl;
   ////////////////////////////////////////////////////////////////////////////////////////
   std::cout << "Number of Numu is: " << Nevt_numu << std::endl;
   std::cout << "Number of Numu after fidcut1 is: " << Nevt_numu_fidcut1 << std::endl;
   std::cout << "Number of Numu after fidcut2 is: " << Nevt_numu_fidcut2 << std::endl;
   std::cout << "Number of Numu after fidcut3 is: " << Nevt_numu_fidcut3 << std::endl;
   std::cout << "Number of Numu after fidcut12 is: " << Nevt_numu_fidcut12 << std::endl;
   std::cout << "Number of Numu after fidcut13 is: " << Nevt_numu_fidcut13 << std::endl;
   std::cout << "Number of Numu after fidcut123 is: " << Nevt_numu_fidcut123 << std::endl;
   std::cout << "Number of Numu after numucuts: " << Nevt_numu_numucut << std::endl;
   std::cout << "Number of Nue after numucuts: " << Nevt_nue_numucut << std::endl;

   TCanvas *c1 = new TCanvas("c1","",1200,1000);
   c1->Divide(2,2,0.00000001,0.01);

   c1->cd(1);
   Tres_RMS_nuNC_1->Draw("HISTO");
   Tres_RMS_numuCC_1->Draw("HISTO same");
   Tres_RMS_nueCC_1->Draw("HISTO same");
   leg11->AddEntry(Tres_RMS_numuCC_1, "#nu_{#mu} CC" ,"l");
   leg11->AddEntry(Tres_RMS_nueCC_1, "#nu_{e} CC" ,"l");
   leg11->AddEntry(Tres_RMS_nuNC_1, "#nu_{x} NC" ,"l");
   leg11->Draw();

   c1->cd(2);
   Tres_RMS_numuCC_2->Draw("HISTO");
   leg12->AddEntry(Tres_RMS_numuCC_2, "#nu_{#mu} CC" ,"l");
   Tres_RMS_nueCC_2->Draw("HISTO same");
   leg12->AddEntry(Tres_RMS_nueCC_2, "#nu_{e} CC" ,"l");
   Tres_RMS_nuNC_2->Draw("HISTO same");
   leg12->AddEntry(Tres_RMS_nuNC_2, "#nu_{x} NC" ,"l");
   leg12->Draw();

   c1->cd(3);
   Tres_RMS_numuCC_3->Draw("HISTO");
   leg13->AddEntry(Tres_RMS_numuCC_3, "#nu_{#mu} CC" ,"l");
   Tres_RMS_nueCC_3->Draw("HISTO same");
   leg13->AddEntry(Tres_RMS_nueCC_3, "#nu_{e} CC" ,"l");
   Tres_RMS_nuNC_3->Draw("HISTO same");
   leg13->AddEntry(Tres_RMS_nuNC_3, "#nu_{x} NC" ,"l");
   leg13->Draw();

   c1->cd(4);
   Tres_RMS_numuCC_4->Draw("HISTO");
   leg14->AddEntry(Tres_RMS_numuCC_4, "#nu_{#mu} CC" ,"l");
   Tres_RMS_nueCC_4->Draw("HISTO same");
   leg14->AddEntry(Tres_RMS_nueCC_4, "#nu_{e} CC" ,"l");
   Tres_RMS_nuNC_4->Draw("HISTO same");
   leg14->AddEntry(Tres_RMS_nuNC_4, "#nu_{x} NC" ,"l");
   leg14->Draw();

   c1->SaveAs("Tres_RMS_0-20GeV_1m_EnBins_WOSC.pdf");

   std::cout << "file Tres_plot.root created" << std::endl;
   //f_out->Close();

}
