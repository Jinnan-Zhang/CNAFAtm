void NuSpectrum3() {

  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);

  static const int NBINS_nue = 7;
  static const int NBINS_numu = 7;

  TCanvas *c1 = new TCanvas("c1","",1200,1000);
  TCanvas *c2 = new TCanvas("c2","",1200,1000);
  TGraph *H_Flux_Mu_osc;
  TGraph *H_Flux_Mu_noosc;
  TGraph *H_Flux_E_osc;
  TGraph *H_Flux_E_noosc;
  TGraphErrors *Mu_SK_flux;
  TGraphErrors *E_SK_flux;

  std::ifstream NueSpec("../output_Nue_osc/Unf_spectrum_7_7.txt");
  std::ifstream NueBins("../../../matrix/likelihood/output_Nue_osc/energybins_Nue_7.txt");
  std::ifstream NueErr("../err_forplots/toterr_nue_7_7.txt");
  //std::ifstream NuMuSpec("../output_Numu_osc/Unf_spectrum_8_8.txt");
  std::ifstream NuMuSpec("../output_Numu_osc/Unf_spectrum_7_8.txt");
  std::ifstream NumuBins("../../../matrix/likelihood/output_Numu_osc/energybins_Numu_8.txt");
  std::ifstream NumuErr("../err_forplots/toterr_numu_7_8.txt");

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

  TLegend * leg1 = new TLegend(0.12,0.15,0.55,0.35);
  TLegend * leg2 = new TLegend(0.12,0.15,0.55,0.35);
  H_Flux_Mu_noosc->SetLineColor(kBlue);
  H_Flux_Mu_noosc->SetLineStyle(2);
  H_Flux_Mu_osc->SetLineColor(kBlue);
  Mu_flux->SetMarkerStyle(20);
  Mu_flux->SetMarkerSize(2.0);
  Mu_flux->SetMarkerColor(kBlue);
  Mu_flux->SetLineWidth(3);
  Mu_flux->SetLineColor(kBlue);
  Mu_SK_flux->SetMarkerStyle(28);
  Mu_SK_flux->SetMarkerSize(2);
  //Mu_SK_flux->SetMarkerColor(kOrange-2);
  Mu_SK_flux->SetLineWidth(2);
  //Mu_SK_flux->SetLineColor(kBlue);
  H_Flux_E_noosc->SetLineColor(kRed);
  H_Flux_E_noosc->SetLineStyle(2);
  H_Flux_E_osc->SetLineColor(kRed);
  E_flux->SetMarkerStyle(20);
  E_flux->SetMarkerSize(2.0);
  E_flux->SetMarkerColor(kRed);
  E_flux->SetLineWidth(3);
  E_flux->SetLineColor(kRed);
  E_SK_flux->SetMarkerStyle(28);
  E_SK_flux->SetMarkerSize(2);
  //E_SK_flux->SetMarkerColor(kGreen+2);
  E_SK_flux->SetLineWidth(2);
  //E_SK_flux->SetLineColor(kRed);
  leg1->AddEntry(H_Flux_Mu_noosc, "HKKM14 #nu_{#mu} Flux (w/o osc.)", "l");
  leg1->AddEntry(H_Flux_Mu_osc, "HKKM14 #nu_{#mu} Flux (w/ osc.)", "l");
  leg1->AddEntry(Mu_flux, "This work (5 yrs) #nu_{#mu}", "pe");
  leg1->AddEntry(Mu_SK_flux, "PRD 94, 052001 (#nu_{#mu})", "pe");
  leg1->SetBorderSize(0);
  leg2->AddEntry(H_Flux_E_noosc, "HKKM14 #nu_{e} Flux (w/o osc.)", "l");
  leg2->AddEntry(H_Flux_E_osc, "HKKM14 #nu_{e} Flux (w/ osc.)", "l");
  leg2->AddEntry(E_flux, "This work (5 yrs) #nu_{e}", "pe");
  leg2->AddEntry(E_SK_flux, "PRD 94, 052001 (#nu_{e})", "pe");
  leg2->SetBorderSize(0);
  c1->cd();
  gPad->SetLogy();
  H_Flux_Mu_noosc->Draw("AL");
  H_Flux_Mu_osc->Draw("CL");
  Mu_SK_flux->Draw("PE");
  Mu_flux->Draw("PE");
  leg1->Draw();
  c2->cd();
  gPad->SetLogy();
  H_Flux_E_noosc->Draw("AL");
  H_Flux_E_osc->Draw("CL");
  E_SK_flux->Draw("PE");
  E_flux->Draw("PE");
  leg2->Draw();  
  c1->SaveAs("Plot/Spec_Numu.root");
  c2->SaveAs("Plot/Spec_Nue.root");

}
