void ALL_systosc_Nue(){
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetPadBottomMargin(0.02);
  gStyle->SetPadLeftMargin(0.1);
  gStyle->SetPadRightMargin(0.02);
  gStyle->SetPadTopMargin(0.02);
  std::ifstream true_array("output_Nue_osc/Unf_spectrum_7_7.txt");
  std::ifstream bins("../../matrix/likelihood/5YRS/output_Nue_osc/energybins_Nue_7.txt");
  std::ofstream rel_err("outputs_systosc_Nue/systosc_err_Nue_7_7.txt");
  TFile *f_out = new TFile("outputs_systosc_Nue/systosc_Nue_7_7.root", "RECREATE");
  char* input_file = new char[256];
  float var, binvalue, mod_var;
  std::vector <float> vec_unf_arr;
  std::vector <float> vec_unf_bins;
  while (bins >> binvalue) vec_unf_bins.push_back(binvalue);
  while (true_array >> var) vec_unf_arr.push_back(var);
  static const int NBINS = vec_unf_bins.size();
  TVectorF unf_bins;
  TVectorF unf_arr;
  TVectorF bin_ratio;
  TVectorF err_ratio;
  unf_bins.ResizeTo(vec_unf_bins.size());
  unf_arr.ResizeTo(vec_unf_arr.size());
  bin_ratio.ResizeTo(vec_unf_arr.size());
  err_ratio.ResizeTo(vec_unf_arr.size());
  for(int ii=0; ii<(vec_unf_bins.size()); ii++) {
    unf_bins[ii] = (vec_unf_bins)[ii]-3.0;
    //unf_arr[ii] = log10((vec_unf_arr)[ii]);
    unf_arr[ii] = ((vec_unf_arr)[ii]);
  }
  Float_t scale_factor[7] = {0.38,0.175,0.044,0.0113,0.00185,2.45E-4,0.31E-4};
  TCanvas *histos_c[NBINS];
  TH1F *Flux_bin_r_h[NBINS];
  TH1F *Flux_bin_r_copy_h[NBINS];
  TLine *true_flux_l[NBINS];
  for (int qq=0;qq<NBINS;qq++) {
    char *histname= new char[128];
    char *canvname= new char[128];
    sprintf(histname, "Flux_bin_%i_h",qq);
    sprintf(canvname, "c%i",qq);
    //Flux_bin_r_h[qq]=new TH1F(histname,"",500,-3.0,4.0);
    histos_c[qq]=new TCanvas(canvname,"",800,600);
    //Flux_bin_r_h[qq]=new TH1F(histname,"",100,0.0,scale_factor[qq]);
    Flux_bin_r_h[qq]=new TH1F(histname,"",100,0.9*scale_factor[qq],scale_factor[qq]);
    true_flux_l[qq] = new TLine(unf_arr[qq],0.0,unf_arr[qq],100.);
    true_flux_l[qq]->SetLineWidth(3);
    true_flux_l[qq]->SetLineColor(kRed);
  }
  TH2F *Flux_var_h = new TH2F("Flux_var_h","",7,-1.0,1.2,200,1.E-7,1.0);
  TGraph *flux_true = new TGraph(unf_bins,unf_arr);
  flux_true->SetMarkerStyle(20);
  flux_true->SetMarkerSize(2.3);
  flux_true->SetMarkerColor(kRed);
  flux_true->GetXaxis()->SetTitle("log_{10}(E_{#nu} / GeV)");
  flux_true->GetYaxis()->SetTitle("Flux [cm^{-2} s^{-1} sr^{-1} GeV^{-1}]");
  flux_true->GetYaxis()->SetTitleSize(0.07);
  flux_true->GetYaxis()->SetTitleOffset(0.74);
  flux_true->GetYaxis()->SetLabelSize(0.06);
  flux_true->GetYaxis()->CenterTitle(true);
  flux_true->GetXaxis()->SetTitleSize(0.07);
  flux_true->GetXaxis()->SetTitleOffset(1.1);
  flux_true->GetXaxis()->SetLabelSize(0.07);
  flux_true->GetYaxis()->SetRangeUser(0.5E-6,0.7);
  /*
  flux_true->GetYaxis()->SetTitleSize(0.05);
  flux_true->GetYaxis()->SetLabelSize(0.05);
  flux_true->GetXaxis()->SetLabelSize(0.05);
  */
  flux_true->SetTitle("");
  int index;
  for (int k=1; k<=1000; k++) {
    sprintf(input_file,"outputs_systosc_Nue/Unf_spectrum-%i_7_7.txt",k);
    //std::cout << "reading file " << input_file << "..." <<std::endl;
    std::ifstream modspec_in(input_file);
    for(int jj=0; jj<(vec_unf_bins.size()); jj++) {
      modspec_in >> mod_var;
      Flux_bin_r_h[jj]->Fill((mod_var));
      //std::cout<<(unf_bins)[jj]<<"\t"<<mod_var<<std::endl;
      Flux_var_h->Fill((unf_bins)[jj], (mod_var));
      //Flux_bin_r_h[jj]->Fill(log10(mod_var));
      //Flux_var_h->Fill((unf_bins)[jj], log10(mod_var));
    }
  }
  Flux_var_h->Write();
  flux_true->Write("original_flux");

  for(int ii=0; ii<NBINS; ii++) {
    Flux_bin_r_h[ii]->Write();
    char *histname_copy= new char[128];
    sprintf(histname_copy, "Flux_bin_%i_copy_h",ii); 
    Flux_bin_r_copy_h[ii] = (TH1F*)Flux_bin_r_h[ii]->Clone(histname_copy);
    //histos_c[ii]->cd();
    //Flux_bin_r_h[ii]->Draw();
    //true_flux_l[ii]->Draw();
    //histos_c[ii]->Write();
  }

  //FIT
  TVectorF fit_peak;
  TVectorF fit_sigma;
  TVectorF err0;
  fit_peak.ResizeTo(vec_unf_bins.size());
  fit_sigma.ResizeTo(vec_unf_bins.size());
  err0.ResizeTo(vec_unf_bins.size());
  for( int ra=0; ra<NBINS; ra++){
    //TF1 *gausfit_flux = new TF1("gausfit_flux", "gaus", -3.0,4.0);
    TF1 *gausfit_flux = new TF1("gausfit_flux", "gaus", 1.E-7,1.0);
    Flux_bin_r_h[ra]->Fit("gausfit_flux","R");
    fit_peak[ra] = gausfit_flux->GetParameter(1);
    fit_sigma[ra] = (gausfit_flux->GetParameter(2))/2.;
    err0[ra] = 0.;
  }
  TLine *fit_flux_l[NBINS];
  for (int pp=0;pp<NBINS;pp++) {
    fit_flux_l[pp] = new TLine(fit_peak[pp],0.0,fit_peak[pp],100.);
    fit_flux_l[pp]->SetLineWidth(3);
    fit_flux_l[pp]->SetLineColor(kBlue);
  }
  std::cout<<std::endl;
  for(int ii=0; ii<NBINS; ii++) {
    //Flux_bin_r_h[ii]->Write();
    //rel_err << (abs(fit_peak[ii]-unf_arr[ii])/unf_arr[ii]) << "\t";
    rel_err << (fit_sigma[ii]/unf_arr[ii]) << "\t";
    //rel_err << (abs(modoscs[0][ii]-modoscs[999][ii])/(2.73*unf_arr[ii])) << "\t";
    std::cout<<fit_sigma[ii]/unf_arr[ii]<<"\t"<<abs(fit_peak[ii]-unf_arr[ii])/unf_arr[ii]<<std::endl;
    histos_c[ii]->cd();
    Flux_bin_r_copy_h[ii]->Draw();
    true_flux_l[ii]->Draw();
    fit_flux_l[ii]->Draw();
    histos_c[ii]->Write();
    bin_ratio[ii] = ( fit_peak[ii]/unf_arr[ii] );
    err_ratio[ii] = ( fit_sigma[ii]/unf_arr[ii] );
  }
  rel_err << "\n";
  TGraphErrors *fitspread = new TGraphErrors(unf_bins,fit_peak,err0,fit_sigma);
  fitspread->SetMarkerStyle(23);
  fitspread->SetMarkerSize(1.7);
  fitspread->SetLineWidth(2);
  fitspread->GetXaxis()->SetTitle("log_{10}(E_{#nu} / GeV)");
  fitspread->Write("fit_flux");

  TGraphErrors *fitratio = new TGraphErrors(unf_bins,bin_ratio,err0,err_ratio);
  fitratio->SetMarkerStyle(20);
  fitratio->SetMarkerSize(1.7);
  fitratio->SetLineWidth(2);
  fitratio->GetYaxis()->SetTitle("Ratio");
  fitratio->GetYaxis()->SetTitleSize(0.07);
  fitratio->GetYaxis()->SetTitleOffset(0.74);
  fitratio->GetYaxis()->SetLabelSize(0.05);
  fitratio->GetYaxis()->CenterTitle(true);
  fitratio->GetXaxis()->SetTitleSize(0.07);
  fitratio->GetXaxis()->SetTitleOffset(1.1);
  fitratio->GetXaxis()->SetLabelSize(0.07);
  fitratio->GetXaxis()->SetTitle("log_{10}(E_{#nu} / GeV)");
  fitratio->GetYaxis()->SetRangeUser(0.79,1.21);
  fitratio->SetTitle("");
  fitratio->Write("fit_ratio");

  TCanvas *cfin = new TCanvas("cfin","",800,800);
  TLine *zero = new TLine(-1.0,1.0,1.05,1.0);
  zero->SetLineWidth(3);
  zero->SetLineStyle(9);
  zero->SetLineColor(kRed);

  TPad *p1 = new TPad("p1", "p1", 0.05, 0.5, 0.95, 0.95, 0, 0, 0);
  p1->SetTopMargin(0);
  p1->SetBottomMargin(0);
  //p1->SetLeftMargin(0);
  p1->SetRightMargin(0.02);
  //gPad->SetTickx(2);
  //gPad->SetTicky(2);
  p1->Draw();

  TPad *p2 = new TPad("p2", "p2", 0.05, 0.0, 0.95, 0.5, 0, 0, 0);
  p2->SetTopMargin(0);
  //p2->SetLeftMargin(0);
  p2->SetRightMargin(0.02);
  p2->SetBottomMargin(0.25);
  //gPad->SetTickx(2);
  //gPad->SetTicky(2);
  p2->Draw();

  TLegend *legspread = new TLegend(0.7,0.65,0.94,0.94);
  legspread->SetBorderSize(0);
  p1->cd();
  flux_true->GetXaxis()->SetLabelSize(0);
  flux_true->Draw("AP");
  legspread->AddEntry(flux_true,"nominal flux","p");
  fitspread->Draw("PE");
  legspread->AddEntry(fitspread,"fit pseudodata","ep");
  gPad->SetLogy();
  legspread->Draw();
  p2->cd();
  fitratio->Draw("APE");
  zero->Draw();
  fitratio->Draw("PE");
  cfin->Write();

  std::cout << "file outputs_systosc_Nue/systosc_Nue_7_7.root created" << std::endl;
  f_out->Close();
  cfin->SaveAs("plot_err/systosc_nue.pdf");
  
}
