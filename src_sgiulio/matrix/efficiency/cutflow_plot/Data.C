#define Data_cxx
#include "Data.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Data::Loop()
{
   if (fChain == 0) return;

   gStyle->SetOptTitle(0);
   gStyle->SetOptStat(0);
   gStyle->SetPadBottomMargin(0.15);
   gStyle->SetPadLeftMargin(0.1);
   gStyle->SetPadRightMargin(0.05);
   gStyle->SetPadTopMargin(0.05);

   TH1F *LogNpe_Nue = new TH1F("LogNpe_Nue","",75,4.7,7.5);
   LogNpe_Nue->GetXaxis()->SetTitle("log_{10} (NPE)");
   LogNpe_Nue->GetXaxis()->SetTitleSize(0.06);
   LogNpe_Nue->GetXaxis()->SetLabelSize(0.045);
   LogNpe_Nue->GetYaxis()->SetTitle("entries");
   LogNpe_Nue->GetYaxis()->SetTitleSize(0.04);
   LogNpe_Nue->GetYaxis()->SetLabelSize(0.045);
   LogNpe_Nue->GetYaxis()->SetTitleOffset(1.3);
   LogNpe_Nue->SetLineWidth(3);
   LogNpe_Nue->SetLineColor(1);
   //LogNpe_Nue->SetFillColor(kGreen-3);
   //LogNpe_Nue->SetFillStyle(3000);
   TH1F *LogNpe_Nue_fidcut = new TH1F("LogNpe_Nue_fidcut","",75,4.7,7.5);
   LogNpe_Nue_fidcut->SetLineWidth(3);
   LogNpe_Nue_fidcut->SetLineColor(4);
   //LogNpe_Nue_fidcut->SetFillColor(kRed-3);
   //LogNpe_Nue_fidcut->SetFillStyle(3000);
   TH1F *LogNpe_Nue_Nuecut = new TH1F("LogNpe_Nue_Nuecut","",75,4.7,7.5);
   LogNpe_Nue_Nuecut->SetLineWidth(3);
   LogNpe_Nue_Nuecut->SetLineColor(2);
   //LogNpe_Nue_Nuecut->SetFillColor(kBlue-10);
   //LogNpe_Nue_Nuecut->SetFillStyle(3000);
   TH1F *LogNpe_Numu_Nuecut = new TH1F("LogNpe_Numu_Nuecut","",75,4.7,7.5);
   LogNpe_Numu_Nuecut->SetLineWidth(3);
   LogNpe_Numu_Nuecut->SetLineColor(kGreen+3);
   //LogNpe_Numu_Nuecut->SetFillColor(kGreen+3);
   //LogNpe_Numu_Nuecut->SetFillStyle(3000);
   ///////////////////////////////////////////////////////////////////////////////
   TH1F *LogNpe_Numu = new TH1F("LogNpe_Numu","",75,5.5,7.5);
   LogNpe_Numu->GetXaxis()->SetTitle("log_{10} (NPE)");
   LogNpe_Numu->GetXaxis()->SetTitleSize(0.06);
   LogNpe_Numu->GetXaxis()->SetLabelSize(0.045);
   LogNpe_Numu->GetYaxis()->SetTitle("entries");
   LogNpe_Numu->GetYaxis()->SetTitleSize(0.04);
   LogNpe_Numu->GetYaxis()->SetLabelSize(0.045);
   LogNpe_Numu->GetYaxis()->SetTitleOffset(1.3);
   LogNpe_Numu->SetLineWidth(3);
   LogNpe_Numu->SetLineColor(1);
   //LogNpe_Numu->SetFillColor(kGreen-3);
   //LogNpe_Numu->SetFillStyle(3000);
   TH1F *LogNpe_Numu_fidcut = new TH1F("LogNpe_Numu_fidcut","",75,5.5,7.5);
   LogNpe_Numu_fidcut->SetLineWidth(3);
   LogNpe_Numu_fidcut->SetLineColor(4);
   //LogNpe_Numu_fidcut->SetFillColor(kRed-3);
   //LogNpe_Numu_fidcut->SetFillStyle(3000);
   TH1F *LogNpe_Numu_Numucut = new TH1F("LogNpe_Numu_Numucut","",75,5.5,7.5);
   LogNpe_Numu_Numucut->SetLineWidth(3);
   LogNpe_Numu_Numucut->SetLineColor(2);
   //LogNpe_Numu_Numucut->SetFillColor(kBlue-10);
   //LogNpe_Numu_Numucut->SetFillStyle(3000);
   TH1F *LogNpe_Nue_Numucut = new TH1F("LogNpe_Nue_Numucut","",75,5.5,7.5);
   LogNpe_Nue_Numucut->SetLineWidth(3);
   LogNpe_Nue_Numucut->SetLineColor(kGreen+3);
   //LogNpe_Nue_Numucut->SetFillColor(kGreen+3);
   //LogNpe_Nue_Numucut->SetFillStyle(3000);


   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if(jentry%1000==0) cout <<"processing event "<<jentry<<endl;

      if(abs(init_nuID)==12) LogNpe_Nue->Fill(log10(trueNPE_LPMT_CD),P_surv);
      if(abs(init_nuID)==12 && newVradius<16000. && trueNPE_LPMT_WP < 60.) LogNpe_Nue_fidcut->Fill(log10(trueNPE_LPMT_CD),P_surv);
      if(abs(init_nuID)==12 && newVradius<16000. && trueNPE_LPMT_WP < 60. && log10(trueNPE_LPMT_CD) > 5.0 && log10(trueNPE_LPMT_CD) < 7.2 && Tres_RMS < 75) LogNpe_Nue_Nuecut->Fill(log10(trueNPE_LPMT_CD),P_surv);
      if(abs(init_nuID)==14 && newVradius<16000. && trueNPE_LPMT_WP < 60. && log10(trueNPE_LPMT_CD) > 5.0 && log10(trueNPE_LPMT_CD) < 7.2 && Tres_RMS < 75) LogNpe_Numu_Nuecut->Fill(log10(trueNPE_LPMT_CD),P_surv);

      if(abs(init_nuID)==14) LogNpe_Numu->Fill(log10(trueNPE_LPMT_CD),P_surv);
      if(abs(init_nuID)==14 && newVradius<16000. && trueNPE_LPMT_WP < 60.) LogNpe_Numu_fidcut->Fill(log10(trueNPE_LPMT_CD),P_surv);
      if(abs(init_nuID)==14 && newVradius<16000. && trueNPE_LPMT_WP < 60. && log10(trueNPE_LPMT_CD) > 5.7 && log10(trueNPE_LPMT_CD) < 7.2 && Tres_RMS > 95) LogNpe_Numu_Numucut->Fill(log10(trueNPE_LPMT_CD),P_surv);
      if(abs(init_nuID)==12 && newVradius<16000. && trueNPE_LPMT_WP < 60. && log10(trueNPE_LPMT_CD) > 5.7 && log10(trueNPE_LPMT_CD) < 7.2 && Tres_RMS > 95) LogNpe_Nue_Numucut->Fill(log10(trueNPE_LPMT_CD),P_surv);

   }

   TCanvas *c9a = new TCanvas("c9a","",750,800);
   TLegend *leg9a = new TLegend(0.74,0.74,0.945,0.945);
   leg9a->SetBorderSize(0);
   c9a->cd();
   gPad->SetLogy();
   LogNpe_Nue->Draw("HISTO");
   LogNpe_Nue_fidcut->Draw("HISTO SAME");
   LogNpe_Nue_Nuecut->Draw("HISTO SAME");
   LogNpe_Numu_Nuecut->Draw("HISTO SAME");
   leg9a->AddEntry(LogNpe_Nue,"#nu_{e} sim.","l");
   leg9a->AddEntry(LogNpe_Nue_fidcut,"#nu_{e} fid. cuts","l");
   leg9a->AddEntry(LogNpe_Nue_Nuecut,"#nu_{e} all cuts","l");
   leg9a->AddEntry(LogNpe_Numu_Nuecut,"#nu_{#mu} res.","l");
   leg9a->Draw();
   gPad->RedrawAxis();
   c9a->SaveAs("cutflow_Nue.pdf");
   c9a->SaveAs("cutflow_Nue.png");
   c9a->SaveAs("cutflow_Nue.root");

   TCanvas *c9b = new TCanvas("c9b","",750,800);
   TLegend *leg9b = new TLegend(0.74,0.74,0.945,0.945);
   leg9b->SetBorderSize(0);
   c9b->cd();
   gPad->SetLogy();
   LogNpe_Numu->Draw("HISTO");
   LogNpe_Numu_fidcut->Draw("HISTO SAME");
   LogNpe_Numu_Numucut->Draw("HISTO SAME");
   LogNpe_Nue_Numucut->Draw("HISTO SAME");
   leg9b->AddEntry(LogNpe_Numu,"#nu_{#mu} sim.","l");
   leg9b->AddEntry(LogNpe_Numu_fidcut,"#nu_{#mu} fid. cuts","l");
   leg9b->AddEntry(LogNpe_Numu_Numucut,"#nu_{#mu} all cuts","l");
   leg9b->AddEntry(LogNpe_Nue_Numucut,"#nu_{e} res.","l");
   leg9b->Draw();
   gPad->RedrawAxis();
   c9b->SaveAs("cutflow_Numu.pdf");
   c9b->SaveAs("cutflow_Numu.png");
   c9b->SaveAs("cutflow_Numu.root");

}
