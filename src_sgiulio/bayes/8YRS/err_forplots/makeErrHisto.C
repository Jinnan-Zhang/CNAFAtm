void makeErrHisto() {
  gStyle->SetOptStat(0);

  static const int NBINS_nue = 7;
  static const float lowE_Nue = -1.0;
  static const float upE_Nue = 1.05;
  //std::ifstream bins("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/matrix/likelihood/output_Nue_osc/energybins_Nue_7.txt");
  std::ifstream nue_stat("staterror_Nue_7_7.txt");
  std::ifstream nue_systcut("systcut_err_Nue_7_7.txt");
  std::ifstream nue_systosc("systosc_err_Nue_7_7.txt");
  std::ifstream nue_systflux("systflux_err_Nue_7_7.txt");
  std::ifstream nue_systxsec("xsecerror_Nue_7_7.txt");
  std::ofstream nue_toterr("toterr_nue_7_7.txt");
  ///////////////////////////////////////////////////////////////////
  static const int NBINS_numu = 7;
  static const float lowE_Numu = -0.3;
  static const float upE_Numu = 1.05;
  //std::ifstream bins("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/matrix/likelihood/output_Numu_osc/energybins_Numu_7.txt");
  std::ifstream numu_stat("staterror_Numu_7_8.txt");
  std::ifstream numu_systcut("systcut_err_Numu_7_8.txt");
  std::ifstream numu_systosc("systosc_err_Numu_7_8.txt");
  std::ifstream numu_systflux("systflux_err_Numu_7_8.txt");
  std::ifstream numu_systxsec("xsecerror_Numu_7_8.txt");
  std::ofstream numu_toterr("toterr_numu_7_8.txt");

  float stat_nue[NBINS_nue]= {.0};
  float systcut_nue[NBINS_nue]= {.0};
  float systosc_nue[NBINS_nue]= {.0};
  float systflux_nue[NBINS_nue]= {.0};
  float systxsec_nue[NBINS_nue]= {.0};
  float toterr_nue[NBINS_nue]= {.0};  
  float stat_numu[NBINS_numu]= {.0};
  float systcut_numu[NBINS_numu]= {.0};
  float systosc_numu[NBINS_numu]= {.0};
  float systflux_numu[NBINS_numu]= {.0};
  float systxsec_numu[NBINS_numu]= {.0};
  float toterr_numu[NBINS_numu]= {.0};

  TH1F *stat_nue_h = new TH1F("stat_nue_h","",NBINS_nue,lowE_Nue,upE_Nue);
  TH1F *systcut_nue_h = new TH1F("systcut_nue_h","",NBINS_nue,lowE_Nue,upE_Nue);
  TH1F *systosc_nue_h = new TH1F("systosc_nue_h","",NBINS_nue,lowE_Nue,upE_Nue);
  TH1F *systflux_nue_h = new TH1F("systflux_nue_h","",NBINS_nue,lowE_Nue,upE_Nue);
  TH1F *systxsec_nue_h = new TH1F("systxsec_nue_h","",NBINS_nue,lowE_Nue,upE_Nue);
  TH1F *tot_err_nue_h = new TH1F("tot_err_nue_h","",NBINS_nue,lowE_Nue,upE_Nue);
  TLegend *lege = new TLegend(0.65,0.7,0.9,0.9);
  TH1F *stat_numu_h = new TH1F("stat_numu_h","",NBINS_numu,lowE_Numu,upE_Numu);
  TH1F *systcut_numu_h = new TH1F("systcut_numu_h","",NBINS_numu,lowE_Numu,upE_Numu);
  TH1F *systosc_numu_h = new TH1F("systosc_numu_h","",NBINS_numu,lowE_Numu,upE_Numu);
  TH1F *systflux_numu_h = new TH1F("systflux_numu_h","",NBINS_numu,lowE_Numu,upE_Numu);
  TH1F *systxsec_numu_h = new TH1F("systxsec_numu_h","",NBINS_numu,lowE_Numu,upE_Numu);
  TH1F *tot_err_numu_h = new TH1F("tot_err_numu_h","",NBINS_numu,lowE_Numu,upE_Numu);
  TLegend *legmu = new TLegend(0.65,0.7,0.9,0.9);
  stat_nue_h->GetYaxis()->SetRangeUser(0.,35.);
  stat_nue_h->GetYaxis()->SetTitle("#Delta#Phi/#Phi [%]");
  stat_nue_h->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
  stat_nue_h->SetLineColor(2);
  stat_nue_h->SetLineStyle(9);
  stat_nue_h->SetLineWidth(3);
  systcut_nue_h->SetLineColor(8);
  systcut_nue_h->SetLineStyle(8);
  systcut_nue_h->SetLineWidth(3);
  systosc_nue_h->SetLineColor(4);
  systosc_nue_h->SetLineStyle(7);
  systosc_nue_h->SetLineWidth(3);
  systflux_nue_h->SetLineColor(6);
  systflux_nue_h->SetLineStyle(2);
  systflux_nue_h->SetLineWidth(3);
  systxsec_nue_h->SetLineColor(9);
  systxsec_nue_h->SetLineStyle(10);
  systxsec_nue_h->SetLineWidth(3);
  tot_err_nue_h->SetLineColor(1);
  tot_err_nue_h->SetLineWidth(4);
  stat_numu_h->GetYaxis()->SetRangeUser(0.,35.);
  stat_numu_h->GetYaxis()->SetTitle("#Delta#Phi/#Phi [%]");
  stat_numu_h->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
  stat_numu_h->SetLineColor(2);
  stat_numu_h->SetLineStyle(9);
  stat_numu_h->SetLineWidth(3);
  systcut_numu_h->SetLineColor(8);
  systcut_numu_h->SetLineStyle(8);
  systcut_numu_h->SetLineWidth(3);
  systosc_numu_h->SetLineColor(4);
  systosc_numu_h->SetLineStyle(7);
  systosc_numu_h->SetLineWidth(3);
  systflux_numu_h->SetLineColor(6);
  systflux_numu_h->SetLineStyle(2);
  systflux_numu_h->SetLineWidth(3);
  systxsec_numu_h->SetLineColor(9);
  systxsec_numu_h->SetLineStyle(10);
  systxsec_numu_h->SetLineWidth(3);
  tot_err_numu_h->SetLineColor(1);
  tot_err_numu_h->SetLineWidth(4);

  for (int ii=0; ii<=NBINS_nue; ii++) {
    nue_stat >> stat_nue[ii];
    toterr_nue[ii] += stat_nue[ii]*stat_nue[ii];
    nue_systcut >> systcut_nue[ii];
    toterr_nue[ii] += systcut_nue[ii]*systcut_nue[ii];
    nue_systosc >> systosc_nue[ii];
    toterr_nue[ii] += systosc_nue[ii]*systosc_nue[ii];
    nue_systflux >> systflux_nue[ii];
    toterr_nue[ii] += systflux_nue[ii]*systflux_nue[ii];
    nue_systxsec >> systxsec_nue[ii];
    toterr_nue[ii] += systxsec_nue[ii]*systxsec_nue[ii];
    stat_nue_h->SetBinContent(ii+1, stat_nue[ii]*100.);
    systcut_nue_h->SetBinContent(ii+1, systcut_nue[ii]*100.);
    systosc_nue_h->SetBinContent(ii+1, systosc_nue[ii]*100.);
    systflux_nue_h->SetBinContent(ii+1, systflux_nue[ii]*100.);
    systxsec_nue_h->SetBinContent(ii+1, systxsec_nue[ii]*100.);
    toterr_nue[ii] = sqrt(toterr_nue[ii]);
    tot_err_nue_h->SetBinContent(ii+1, toterr_nue[ii]*100.);
    nue_toterr << toterr_nue[ii] << "\t";
  }


  TCanvas *ce = new TCanvas("ce","ce",1500,1000);
  ce->cd();

  stat_nue_h->Draw();
  systcut_nue_h->Draw("same");
  systosc_nue_h->Draw("same");
  systflux_nue_h->Draw("same");
  systxsec_nue_h->Draw("same");
  tot_err_nue_h->Draw("same");
  lege->AddEntry(stat_nue_h,"statistical","l");
  lege->AddEntry(systcut_nue_h,"sample selection","l");
  lege->AddEntry(systosc_nue_h,"oscillation","l");
  lege->AddEntry(systflux_nue_h,"probabilities","l");
  lege->AddEntry(systxsec_nue_h,"cross section","l");
  lege->AddEntry(tot_err_nue_h,"total","l");
  lege->Draw();

  ce->SaveAs("Plot/Errors_Nue.root");

  for (int jj=0; jj<=NBINS_numu; jj++) {
    numu_stat >> stat_numu[jj];
    toterr_numu[jj] += stat_numu[jj]*stat_numu[jj];
    numu_systcut >> systcut_numu[jj];
    toterr_numu[jj] += systcut_numu[jj]*systcut_numu[jj];
    numu_systosc >> systosc_numu[jj];
    toterr_numu[jj] += systosc_numu[jj]*systosc_numu[jj];
    numu_systflux >> systflux_numu[jj];
    toterr_numu[jj] += systflux_numu[jj]*systflux_numu[jj];
    numu_systxsec >> systxsec_numu[jj];
    toterr_numu[jj] += systxsec_numu[jj]*systxsec_numu[jj];
    stat_numu_h->SetBinContent(jj+1, stat_numu[jj]*100.);
    systcut_numu_h->SetBinContent(jj+1, systcut_numu[jj]*100.);
    systosc_numu_h->SetBinContent(jj+1, systosc_numu[jj]*100.);
    systflux_numu_h->SetBinContent(jj+1, systflux_numu[jj]*100.);
    systxsec_numu_h->SetBinContent(jj+1, systxsec_numu[jj]*100.);
    toterr_numu[jj] = sqrt(toterr_numu[jj]);
    tot_err_numu_h->SetBinContent(jj+1, toterr_numu[jj]*100.);
    numu_toterr << toterr_numu[jj] << "\t";
  }

  TCanvas *cmu = new TCanvas("cmu","cmu",1500,1000);
  cmu->cd();  

  stat_numu_h->Draw();
  systcut_numu_h->Draw("same");
  systosc_numu_h->Draw("same");
  systflux_numu_h->Draw("same");
  systxsec_numu_h->Draw("same");
  tot_err_numu_h->Draw("same");
  legmu->AddEntry(stat_numu_h,"statistical","l");
  legmu->AddEntry(systcut_numu_h,"sample selection","l");
  legmu->AddEntry(systosc_numu_h,"oscillation","l");
  legmu->AddEntry(systflux_numu_h,"probabilities","l");
  legmu->AddEntry(systxsec_numu_h,"cross section","l");
  legmu->AddEntry(tot_err_numu_h,"total","l");
  legmu->Draw();

  cmu->SaveAs("Plot/Errors_Numu.root");

}
