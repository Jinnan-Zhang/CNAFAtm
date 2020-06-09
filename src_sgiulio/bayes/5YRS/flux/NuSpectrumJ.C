void NuSpectrumJ() {

  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  gStyle->SetPadBottomMargin(0.02);
  gStyle->SetPadLeftMargin(0.1);
  gStyle->SetPadRightMargin(0.02);
  gStyle->SetPadTopMargin(0.02);
  
  static const int NBINS_nue = 7;
  static const int NBINS_numu = 7;

  TCanvas *c1 = new TCanvas("c1","",900,1000);
  TCanvas *c2 = new TCanvas("c2","",900,1000);
  TGraph *H_Flux_Mu_osc;
  TGraph *H_Flux_Mu_noosc;
  TGraph *H_Flux_E_osc;
  TGraph *H_Flux_E_noosc;
  TGraphErrors *Mu_SK_flux;
  TGraphErrors *E_SK_flux;
  
  std::ifstream NueSpec("../output_Nue_osc/Unf_spectrum_7_7.txt");
  std::ifstream NueBins("../../../matrix/likelihood/5YRS/output_Nue_osc/energybins_Nue_7.txt");
  std::ifstream NueErr("../err_forplots/toterr_nue_7_7.txt");
  std::ifstream NueRatio("../output_Nue_osc/Reco_MC_spectrum_ratio_1_iter_7_7.txt");
  //std::ifstream NuMuSpec("../output_Numu_osc/Unf_spectrum_8_8.txt");
  std::ifstream NumuSpec("../output_Numu_osc/Unf_spectrum_7_8.txt");
  std::ifstream NumuBins("../../../matrix/likelihood/5YRS/output_Numu_osc/energybins_Numu_7.txt");
  std::ifstream NumuErr("../err_forplots/toterr_numu_7_8.txt");
  std::ifstream NumuRatio("../output_Numu_osc/Reco_MC_spectrum_ratio_1_iter_7_8.txt");

  TFile *_file0 = TFile::Open("../output_Numu_osc/plot_7_8.root");
  _file0->GetObject("Honda_Flux_noosc",H_Flux_Mu_noosc);
  _file0->GetObject("Honda_Flux_osc",H_Flux_Mu_osc);
  TFile *_file1 = TFile::Open("../output_Nue_osc/plot_7_7.root");
  _file1->GetObject("Honda_Flux_noosc",H_Flux_E_noosc);
  _file1->GetObject("Honda_Flux_osc",H_Flux_E_osc);

  TVectorF Spec_nue, bins_nue, Err_nue, errx0_nue, Spec_numu, bins_numu, Err_numu, errx0_numu, Ratio_nue, Ratio_numu, errRatio_nue, errRatio_numu;
  Spec_nue.ResizeTo(NBINS_nue);
  bins_nue.ResizeTo(NBINS_nue);
  Err_nue.ResizeTo(NBINS_nue);
  errx0_nue.ResizeTo(NBINS_nue);
  Ratio_nue.ResizeTo(NBINS_nue);
  errRatio_nue.ResizeTo(NBINS_nue);
  Spec_numu.ResizeTo(NBINS_numu);
  bins_numu.ResizeTo(NBINS_numu);
  Err_numu.ResizeTo(NBINS_numu);
  errx0_numu.ResizeTo(NBINS_numu);
  Ratio_numu.ResizeTo(NBINS_numu);
  errRatio_numu.ResizeTo(NBINS_numu);

  for (int ii=0; ii<NBINS_nue; ii++) {
    NueSpec >> Spec_nue[ii];
    NueBins >> bins_nue[ii];
    bins_nue[ii] = bins_nue[ii]-3.0;
    NueErr >> Err_nue[ii];
    Err_nue[ii] = Spec_nue[ii]*(Err_nue[ii]*pow(10.,2.0*bins_nue[ii]));
    Spec_nue[ii] = Spec_nue[ii]*pow(10.,2.0*bins_nue[ii]);
    errx0_nue[ii] = .0;
    NueRatio >> Ratio_nue[ii];
    errRatio_nue[ii] = ((Err_nue[ii]/Spec_nue[ii])*Ratio_nue[ii]);
  }

  for (int jj=0; jj<NBINS_nue; jj++) { 
    NumuSpec >> Spec_numu[jj];
    NumuBins >> bins_numu[jj];
    bins_numu[jj] = bins_numu[jj]-3.0;
    NumuErr >> Err_numu[jj];
    Err_numu[jj] = Spec_numu[jj]*(Err_numu[jj]*pow(10.,2.0*bins_numu[jj]));
    Spec_numu[jj] = Spec_numu[jj]*pow(10.,2.0*bins_numu[jj]);
    errx0_numu[jj] = .0;
    NumuRatio >> Ratio_numu[jj];
    errRatio_numu[jj] = ((Err_numu[jj]/Spec_numu[jj])*Ratio_numu[jj]);
  }

  TGraphErrors *Mu_flux = new TGraphErrors(bins_numu,Spec_numu,errx0_numu,Err_numu);
  TGraphErrors *E_flux = new TGraphErrors(bins_nue,Spec_nue,errx0_nue,Err_nue);
  TGraphErrors *Mu_ratio_flux = new TGraphErrors(bins_numu,Ratio_numu,errx0_numu,errRatio_numu);
  TGraphErrors *E_ratio_flux = new TGraphErrors(bins_nue,Ratio_nue,errx0_nue,errRatio_nue);
  
  TLine *zero_Numu = new TLine(-1.0,1.0,2.0,1.0);
  zero_Numu->SetLineWidth(2);
  zero_Numu->SetLineStyle(9);
  
  TLegend * leg1 = new TLegend(0.12,0.15,0.55,0.35);
  TLegend * leg2 = new TLegend(0.12,0.15,0.55,0.35);
  H_Flux_Mu_noosc->SetLineColor(kBlue);
  H_Flux_Mu_noosc->SetLineStyle(2);
  H_Flux_Mu_noosc->GetYaxis()->SetRangeUser(2.E-5,0.8E-1);
  H_Flux_Mu_noosc->GetYaxis()->SetTitleSize(0.055);
  H_Flux_Mu_noosc->GetYaxis()->SetTitleOffset(0.88);
  H_Flux_Mu_noosc->GetYaxis()->SetLabelSize(0.04);
  H_Flux_Mu_noosc->GetXaxis()->SetTitle("log_{10} (E_{#nu} / GeV)");
  H_Flux_Mu_noosc->GetXaxis()->SetTitleSize(0.055);
  H_Flux_Mu_noosc->GetXaxis()->SetTitleOffset(0.88);
  H_Flux_Mu_osc->SetLineColor(kBlue);
  Mu_flux->SetMarkerStyle(20);
  Mu_flux->SetMarkerSize(2.0);
  Mu_flux->SetMarkerColor(kBlue);
  Mu_flux->SetLineWidth(3);
  Mu_flux->SetLineColor(kBlue);
  H_Flux_E_noosc->SetLineColor(kRed);
  H_Flux_E_noosc->SetLineStyle(2);
  H_Flux_E_noosc->GetYaxis()->SetRangeUser(2.E-5,0.8E-1);
  H_Flux_E_noosc->GetYaxis()->SetTitleSize(0.055);
  H_Flux_E_noosc->GetYaxis()->SetTitleOffset(0.88);
  H_Flux_E_noosc->GetYaxis()->SetLabelSize(0.04);
  H_Flux_E_noosc->GetXaxis()->SetTitle("log_{10} (E_{#nu} / GeV)");
  H_Flux_E_osc->SetLineColor(kRed);
  E_flux->SetMarkerStyle(20);
  E_flux->SetMarkerSize(2.0);
  E_flux->SetMarkerColor(kRed);
  E_flux->SetLineWidth(3);
  E_flux->SetLineColor(kRed);
  leg1->AddEntry(H_Flux_Mu_noosc, "HKKM14 #nu_{#mu} Flux (w/o osc.)", "l");
  leg1->AddEntry(H_Flux_Mu_osc, "HKKM14 #nu_{#mu} Flux (w/ osc.)", "l");
  leg1->AddEntry(Mu_flux, "This work (5 yrs) #nu_{#mu}", "pe");
  leg1->SetBorderSize(0);
  leg2->AddEntry(H_Flux_E_noosc, "HKKM14 #nu_{e} Flux (w/o osc.)", "l");
  leg2->AddEntry(H_Flux_E_osc, "HKKM14 #nu_{e} Flux (w/ osc.)", "l");
  leg2->AddEntry(E_flux, "This work (5 yrs) #nu_{e}", "pe");
  leg2->SetBorderSize(0);
  Mu_ratio_flux->SetMarkerStyle(20);
  Mu_ratio_flux->SetMarkerSize(2.0);
  Mu_ratio_flux->SetMarkerColor(kBlue);
  Mu_ratio_flux->SetLineWidth(3);
  Mu_ratio_flux->SetLineColor(kBlue);
  Mu_ratio_flux->GetYaxis()->SetRangeUser(-0.01,1.99);
  Mu_ratio_flux->GetYaxis()->SetTitleSize(0.11);
  Mu_ratio_flux->GetYaxis()->SetTitleOffset(0.45);
  Mu_ratio_flux->GetYaxis()->SetLabelSize(0.08);
  Mu_ratio_flux->GetYaxis()->SetTitle("Reco/MC");
  Mu_ratio_flux->GetXaxis()->SetLimits(-1.0,2.0);
  Mu_ratio_flux->GetXaxis()->SetTitle("log_{10} (E_{#nu} / GeV)");
  Mu_ratio_flux->GetXaxis()->SetTitleSize(0.12);
  Mu_ratio_flux->GetXaxis()->SetTitleOffset(0.88);
  Mu_ratio_flux->GetXaxis()->SetLabelSize(0.1);
  E_ratio_flux->SetMarkerStyle(20);
  E_ratio_flux->SetMarkerSize(2.0);
  E_ratio_flux->SetMarkerColor(kRed);
  E_ratio_flux->SetLineWidth(3);
  E_ratio_flux->SetLineColor(kRed);
  E_ratio_flux->GetYaxis()->SetRangeUser(-0.01,1.99);
  E_ratio_flux->GetYaxis()->SetTitleSize(0.11);
  E_ratio_flux->GetYaxis()->SetTitleOffset(0.45);
  E_ratio_flux->GetYaxis()->SetLabelSize(0.08);
  E_ratio_flux->GetYaxis()->SetTitle("Reco/MC");
  E_ratio_flux->GetXaxis()->SetLimits(-1.0,2.0);
  E_ratio_flux->GetXaxis()->SetTitle("log_{10} (E_{#nu} / GeV)");
  E_ratio_flux->GetXaxis()->SetTitleSize(0.12);
  E_ratio_flux->GetXaxis()->SetTitleOffset(0.88);
  E_ratio_flux->GetXaxis()->SetLabelSize(0.1);
  TPaveText *ptmu = new TPaveText(1.0,0.008,1.5,0.02,"nb");
  TText *tmu = ptmu->AddText("#nu_{#mu}");
  tmu->SetTextColor(kBlue);
  ptmu->SetFillColor(0);
  TPaveText *pte = new TPaveText(1.0,0.003,1.5,0.008,"nb");
  TText *te = pte->AddText("#nu_{#font[12]{e}}");
  te->SetTextColor(kRed);
  pte->SetFillColor(0);
  
  c1->cd();

  TPad *p1 = new TPad("p1", "p1", 0.01, 0.3, 0.95, 0.95, 0, 0, 0);
  p1->SetTopMargin(0);
  p1->SetBottomMargin(0);
  p1->SetRightMargin(0.02);
  p1->Draw();
  
  TPad *p2 = new TPad("p2", "p2", 0.01, 0.0, 0.95, 0.3, 0, 0, 0);
  p2->SetTopMargin(0);
  //p2->SetLeftMargin(0);
  p2->SetRightMargin(0.02);
  p2->SetBottomMargin(0.25);
  //gPad->SetTickx(2);
  //gPad->SetTicky(2);
  p2->Draw();

  p1->cd();
  gPad->SetLogy();
  H_Flux_Mu_noosc->Draw("AL");
  H_Flux_Mu_osc->Draw("CL");
  Mu_flux->Draw("PE");
  ptmu->Draw();
  //leg1->Draw();
  
  p2->cd();
  Mu_ratio_flux->Draw("APE");
  zero_Numu->Draw();
  Mu_ratio_flux->Draw("PE");

  c2->cd();
  
  TPad *p3 = new TPad("p3", "p3", 0.01, 0.3, 0.95, 0.95, 0, 0, 0);
  p3->SetTopMargin(0);
  p3->SetBottomMargin(0);
  //p3->SetLeftMargin(0);
  p3->SetRightMargin(0.02);
  //gPad->SetTickx(2);
  //gPad->SetTicky(2);
  p3->Draw();

  TPad *p4 = new TPad("p4", "p4", 0.01, 0.0, 0.95, 0.3, 0, 0, 0);
  p4->SetTopMargin(0);
  //p4->SetLeftMargin(0);
  p4->SetRightMargin(0.02);
  p4->SetBottomMargin(0.25);
  //gPad->SetTickx(2);
  //gPad->SetTicky(2);
  p4->Draw();

  p3->cd();
  gPad->SetLogy();
  H_Flux_E_noosc->Draw("AL");
  H_Flux_E_osc->Draw("CL");
  E_flux->Draw("PE");
  //leg2->Draw();
  pte->Draw();
  
  p4->cd();
  E_ratio_flux->Draw("APE");
  zero_Numu->Draw();
  E_ratio_flux->Draw("PE");

  c1->SaveAs("Plot/Spec_Numu_JUNO.pdf");
  c2->SaveAs("Plot/Spec_Nue_JUNO.pdf");

}
