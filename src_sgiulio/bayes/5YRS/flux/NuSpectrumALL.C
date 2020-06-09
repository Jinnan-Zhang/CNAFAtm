void NuSpectrumALL() {

  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  gStyle->SetPadRightMargin(0.02);
  
  static const int NBINS_nue = 7;
  static const int NBINS_numu = 7;

  TCanvas *cALL = new TCanvas("cALL","",1200,800);
  TGraph *H_Flux_Mu_osc;
  TGraph *H_Flux_Mu_noosc;
  TGraph *H_Flux_E_osc;
  TGraph *H_Flux_E_noosc;
  TGraphErrors *Mu_SK_flux;
  TGraphErrors *E_SK_flux;

  std::ifstream NueSpec("../output_Nue_osc/Unf_spectrum_7_7.txt");
  std::ifstream NueBins("../../../matrix/likelihood/5YRS/output_Nue_osc/energybins_Nue_7.txt");
  std::ifstream NueErr("../err_forplots/toterr_nue_7_7.txt");
  //std::ifstream NuMuSpec("../output_Numu_osc/Unf_spectrum_8_8.txt");
  std::ifstream NuMuSpec("../output_Numu_osc/Unf_spectrum_7_8.txt");
  std::ifstream NumuBins("../../../matrix/likelihood/5YRS/output_Numu_osc/energybins_Numu_7.txt");
  std::ifstream NumuErr("../err_forplots/toterr_numu_7_8.txt");

  //////////Frèjus///////////////////////
  std::ifstream Fr_NueFluxfile("../../ext_fluxes/Fr_flux_Nue.txt");
  std::ifstream Fr_NumuFluxfile("../../ext_fluxes/Fr_flux_Numu.txt");
  TVectorF Fr_Nuebins, Fr_Numubins, Fr_Nueflux, Fr_Numuflux, Fr_NueErr, Fr_NumuErr, Fr_NueXErr0, Fr_NumuXErr0;
  Float_t dummy, FrBE, FrBMu, FrFE, FrFMu, FrErrE, FrErrMu;
  Fr_Nuebins.ResizeTo(7);
  Fr_Nueflux.ResizeTo(7);
  Fr_NueErr.ResizeTo(7);
  Fr_NueXErr0.ResizeTo(7);
  Fr_Numubins.ResizeTo(11);
  Fr_Numuflux.ResizeTo(11);
  Fr_NumuErr.ResizeTo(11);
  Fr_NumuXErr0.ResizeTo(11);
  int index = 0;
  while (Fr_NueFluxfile >> dummy >> FrBE >> FrFE >> FrErrE) {
    std::cout<<dummy<<"\t"<<FrBE<<"\t"<<FrFE<<"\t"<<FrErrE<<std::endl;
    Fr_Nuebins[index] = log10(FrBE);
    Fr_Nueflux[index] = FrFE*FrBE*FrBE;
    Fr_NueErr[index] = FrErrE*FrBE*FrBE;
    Fr_NueXErr0[index] = 0.;
    index++;
  }
  index = 0;
  while (Fr_NumuFluxfile >> dummy >> FrBMu >> FrFMu >> FrErrMu) {
    std::cout<<dummy<<"\t"<<FrBMu<<"\t"<<FrFMu<<"\t"<<FrErrMu<<std::endl;
    Fr_Numubins[index] = log10(FrBMu);
    Fr_Numuflux[index] = FrFMu*FrBMu*FrBMu;
    Fr_NumuErr[index] = FrErrMu*FrBMu*FrBMu;
    Fr_NumuXErr0[index] = 0.;
    index++;
  }
  ///////////////////////////////////////
  
  TFile *_file0 = TFile::Open("../output_Numu_osc/plot_7_8.root");
  _file0->GetObject("Honda_Flux_noosc",H_Flux_Mu_noosc);
  _file0->GetObject("Honda_Flux_osc",H_Flux_Mu_osc);
  _file0->GetObject("SK_Flux",Mu_SK_flux);
  TFile *_file1 = TFile::Open("../output_Nue_osc/plot_7_7.root");
  _file1->GetObject("Honda_Flux_noosc",H_Flux_E_noosc);
  _file1->GetObject("Honda_Flux_osc",H_Flux_E_osc);
  _file1->GetObject("SK_Flux",E_SK_flux);

  TVectorF Spec_nue, bins_nue, Err_nue, errx0_nue, Spec_numu, bins_numu, Err_numu, errx0_numu;
  Spec_nue.ResizeTo(NBINS_nue);
  bins_nue.ResizeTo(NBINS_nue);
  Err_nue.ResizeTo(NBINS_nue);
  errx0_nue.ResizeTo(NBINS_nue);
  Spec_numu.ResizeTo(NBINS_numu);
  bins_numu.ResizeTo(NBINS_numu);
  Err_numu.ResizeTo(NBINS_numu);
  errx0_numu.ResizeTo(NBINS_numu);

  for (int ii=0; ii<NBINS_nue; ii++) {
    NueSpec >> Spec_nue[ii];
    NueBins >> bins_nue[ii];
    bins_nue[ii] = bins_nue[ii]-3.0;
    NueErr >> Err_nue[ii];
    Err_nue[ii] = Spec_nue[ii]*(Err_nue[ii]*pow(10.,2.0*bins_nue[ii]));
    Spec_nue[ii] = Spec_nue[ii]*pow(10.,2.0*bins_nue[ii]);
    errx0_nue[ii] = .0;
  }

  for (int jj=0; jj<NBINS_nue; jj++) { 
    NuMuSpec >> Spec_numu[jj];
    NumuBins >> bins_numu[jj];
    bins_numu[jj] = bins_numu[jj]-3.0;
    NumuErr >> Err_numu[jj];
    Err_numu[jj] = Spec_numu[jj]*(Err_numu[jj]*pow(10.,2.0*bins_numu[jj]));
    Spec_numu[jj] = Spec_numu[jj]*pow(10.,2.0*bins_numu[jj]);
    errx0_numu[jj] = .0;
  }

  TGraphErrors *Mu_flux = new TGraphErrors(bins_numu,Spec_numu,errx0_numu,Err_numu);
  TGraphErrors *E_flux = new TGraphErrors(bins_nue,Spec_nue,errx0_nue,Err_nue);
  TGraphErrors *Mu_Fr_flux = new TGraphErrors(Fr_Numubins,Fr_Numuflux,Fr_NumuXErr0,Fr_NumuErr);
  TGraphErrors *E_Fr_flux = new TGraphErrors(Fr_Nuebins,Fr_Nueflux,Fr_NueXErr0,Fr_NueErr);

  TLegend *legALL1 = new TLegend(0.12,0.42,0.45,0.62);
  TLegend *legALL2 = new TLegend(0.12,0.15,0.45,0.35);
  legALL1->SetBorderSize(0);
  legALL2->SetBorderSize(0);
  H_Flux_Mu_noosc->SetLineColor(9);
  H_Flux_Mu_noosc->SetLineStyle(2);
  H_Flux_Mu_noosc->SetLineWidth(2);
  H_Flux_Mu_noosc->GetYaxis()->SetTitleSize(0.045);
  H_Flux_Mu_noosc->GetYaxis()->SetTitleOffset(1.1);
  H_Flux_Mu_noosc->GetYaxis()->SetLabelSize(0.04);
  H_Flux_Mu_noosc->GetYaxis()->SetRangeUser(0.5E-5,0.12);
  H_Flux_Mu_noosc->GetXaxis()->SetTitle("log_{10} (E_{#nu} / GeV)");
  H_Flux_Mu_noosc->GetXaxis()->SetTitleSize(0.045);
  H_Flux_Mu_noosc->GetXaxis()->SetLabelSize(0.04);
  H_Flux_Mu_osc->SetLineColor(9);
  H_Flux_Mu_osc->SetLineWidth(2);
  Mu_flux->SetMarkerStyle(20);
  Mu_flux->SetMarkerSize(2.0);
  Mu_flux->SetMarkerColor(kBlue);
  Mu_flux->SetLineWidth(3);
  Mu_flux->SetLineColor(kBlue);
  Mu_SK_flux->SetMarkerStyle(34);
  Mu_SK_flux->SetMarkerSize(2.2);
  Mu_SK_flux->SetMarkerColor(38);
  Mu_SK_flux->SetLineColor(38);
  Mu_SK_flux->SetLineWidth(2);
  Mu_Fr_flux->SetMarkerStyle(33);
  Mu_Fr_flux->SetMarkerSize(2.5);
  Mu_Fr_flux->SetLineWidth(2);
  Mu_Fr_flux->SetMarkerColor(30);
  Mu_Fr_flux->SetLineColor(30);
  H_Flux_E_noosc->SetLineColor(46);
  H_Flux_E_noosc->SetLineStyle(2);
  H_Flux_E_noosc->SetLineWidth(2);
  H_Flux_E_noosc->GetYaxis()->SetRangeUser(0.5E-5,0.12);
  H_Flux_E_osc->SetLineColor(46);
  H_Flux_E_osc->SetLineWidth(2);
  E_flux->SetMarkerStyle(20);
  E_flux->SetMarkerSize(2.0);
  E_flux->SetMarkerColor(kRed);
  E_flux->SetLineWidth(3);
  E_flux->SetLineColor(kRed);
  E_SK_flux->SetMarkerStyle(34);
  E_SK_flux->SetMarkerSize(2.2);
  E_SK_flux->SetMarkerColor(49);
  E_SK_flux->SetLineColor(49);
  E_SK_flux->SetLineWidth(2);
  E_Fr_flux->SetMarkerStyle(33);
  E_Fr_flux->SetMarkerSize(2.5);
  E_Fr_flux->SetLineWidth(2);
  E_Fr_flux->SetMarkerColor(44);
  E_Fr_flux->SetLineColor(44);
  legALL1->AddEntry(Mu_flux, "#bf{JUNO - This work (5 yrs) #nu_{#mu}}", "pe");
  legALL1->AddEntry(Mu_SK_flux, "Super-Kamiokande 2016 #nu_{#mu}", "pe");
  legALL1->AddEntry(Mu_Fr_flux, "Fr#acute{e}jus 1995 #nu_{#mu}", "pe");
  legALL1->AddEntry(H_Flux_Mu_noosc, "HKKM14 #nu_{#mu} Flux (w/o osc.)", "l");
  legALL1->AddEntry(H_Flux_Mu_osc, "HKKM14 #nu_{#mu} Flux (w/ osc.)", "l");
  legALL2->AddEntry(E_flux, "#bf{JUNO - This work (5 yrs) #nu_{e}}", "pe");
  legALL2->AddEntry(E_SK_flux, "Super-Kamiokande 2016 #nu_{e}", "pe");
  legALL2->AddEntry(E_Fr_flux, "Fr#acute{e}jus 1995 #nu_{e}", "pe");
  legALL2->AddEntry(H_Flux_E_noosc, "HKKM14 #nu_{e} Flux (w/o osc.)", "l");
  legALL2->AddEntry(H_Flux_E_osc, "HKKM14 #nu_{e} Flux (w/ osc.)", "l");
  cALL->cd();
  gPad->SetLogy();
  H_Flux_Mu_noosc->Draw("AL");
  H_Flux_Mu_osc->Draw("CL");
  H_Flux_E_noosc->Draw("CL");
  H_Flux_E_osc->Draw("CL");
  Mu_Fr_flux->Draw("PE");
  Mu_SK_flux->Draw("PE");
  Mu_flux->Draw("PE");
  E_Fr_flux->Draw("PE");
  E_SK_flux->Draw("PE");
  E_flux->Draw("PE");
  legALL1->Draw();
  legALL2->Draw();
  cALL->SaveAs("Plot/Spec_ALL.pdf");

}
