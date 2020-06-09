makeplots_nu_60mmsmear() {

  //TLegend * leg = new TLegend(0.1,0.9,0.4,0.7);
  TLegend * leg = new TLegend(0.7,0.9,0.9,0.7);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  TFile *_file0 = TFile::Open("Plot/TRUEnue_0-10GeV_red_60mm_CCpure.root");
  TCanvas *c3 = new TCanvas("c3","",1600,1200);
  Time_residual_spread_all_h->SetLineWidth(4);
  Time_residual_spread_all_h->SetLineColor(kRed);
  Time_residual_spread_all_h->GetXaxis()->SetTitle("t_{res} RMS [ns]");
  Time_residual_spread_all_h->GetYaxis()->SetRangeUser(0,1000);
  Time_residual_spread_all_h->Draw();
  leg->AddEntry(Time_residual_spread_all_h, "#nu_{e} CC" ,"l");
  TFile *_file1 = TFile::Open("Plot/TRUEnumu_0-10GeV_red_60mm_CCpure.root");
  Time_residual_spread_all_h->SetLineWidth(4);
  Time_residual_spread_all_h->SetLineColor(kBlue);
  Time_residual_spread_all_h->Draw("same");
  leg->AddEntry(Time_residual_spread_all_h, "#nu_{#mu} CC" ,"l");
  //TFile *_file2 = TFile::Open("Plot/TRUEnue_0-10GeV_red_60mm_NCpure.root");
  TFile *_file2 = TFile::Open("Plot/TRUEnue+numu_0-10GeV_red_60mm_NCpure.root");
  Time_residual_spread_all_h->SetLineWidth(4);
  Time_residual_spread_all_h->SetLineColor(kGreen+3);
  Time_residual_spread_all_h->Draw("same");
  leg->AddEntry(Time_residual_spread_all_h, "#nu_{e}+#nu_{#mu} NC" ,"l");

  leg->Draw();



  //gPad->BuildLegend(0.1,0.9,0.6,0.7); 
  c3->SaveAs("Plot/tres_spread_nueCC+numuCC+nuCC_0-10GeV_16volcut_purecharge_60mmV_ALL.pdf");
  c3->SaveAs("Plot/tres_spread_nueCC+numuCC+nuCC_0-10GeV_16volcut_purecharge_60mmV_ALL.C");
  }
