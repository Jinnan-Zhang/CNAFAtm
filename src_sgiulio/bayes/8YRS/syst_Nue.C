void syst_Nue(){
  std::ifstream true_array("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/bayes/outputs_systcut_Nue/Unf_spectrum-75_10_8.txt");
  std::ifstream bins("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/bayes/outputs_modDATA_Nue/energybins_Nue_10.txt");
  std::ofstream rel_err("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/bayes/outputs_systcut_Nue/systcut_err_Nue_10_8.txt");
  TFile *f_out = new TFile("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/bayes/outputs_systcut_Nue/systcut_Nue.root", "RECREATE");
  char* input_file = new char[256];
  float var, binvalue, mod_var;
  std::vector <float> vec_unf_arr;
  std::vector <float> vec_unf_bins;
  while (bins >> binvalue) vec_unf_bins.push_back(binvalue);
  while (true_array >> var) vec_unf_arr.push_back(var);
  TVectorF unf_bins;
  TVectorF unf_arr;
  unf_bins.ResizeTo(vec_unf_bins.size());
  unf_arr.ResizeTo(vec_unf_arr.size());
  for(int ii=0; ii<(vec_unf_bins.size()); ii++) {
    unf_bins[ii] = (vec_unf_bins)[ii]-3.0;
    //unf_arr[ii] = log10((vec_unf_arr)[ii]);
    unf_arr[ii] = ((vec_unf_arr)[ii]);
  }
  static const int NBINS = vec_unf_bins.size();
  Float_t scale_factor[10] = {0.7,0.4,0.15,0.07,0.02,0.005,1.5E-3,1.5E-4,1.E-4,1.E-6};
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
    Flux_bin_r_h[qq]=new TH1F(histname,"",100,0.1*scale_factor[qq],scale_factor[qq]);
    true_flux_l[qq] = new TLine(unf_arr[qq],0.0,unf_arr[qq],100.);
    true_flux_l[qq]->SetLineWidth(3);
    true_flux_l[qq]->SetLineColor(kRed);
  }
  TH2F *Flux_var_h = new TH2F("Flux_var_h","",10,-1.0,1.2,200,1.E-7,1.0);
  TGraph *flux_true = new TGraph(unf_bins,unf_arr);
  flux_true->SetMarkerStyle(20);
  flux_true->SetMarkerSize(1.5);
  flux_true->SetMarkerColor(kRed);
  int index;
  for (int k=1; k<=10; k++) {
    index = 65+(2*k);
    sprintf(input_file,"/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/bayes/outputs_systcut_Nue/Unf_spectrum-%i_10_8.txt",index);
    //std::cout << "reading file " << input_file << "..." <<std::endl;
    std::ifstream modspec_in(input_file);
    for(int jj=0; jj<(vec_unf_bins.size()); jj++) {
      modspec_in >> mod_var;
      Flux_bin_r_h[jj]->Fill((mod_var));
      std::cout<<(unf_bins)[jj]<<"\t"<<mod_var<<std::endl;
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
  TVectorF fit_sigma;;
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

  for(int ii=0; ii<NBINS; ii++) {
    //Flux_bin_r_h[ii]->Write();
    rel_err << (fit_sigma[ii]/unf_arr[ii]) << "\t";
    histos_c[ii]->cd();
    Flux_bin_r_copy_h[ii]->Draw();
    true_flux_l[ii]->Draw();
    fit_flux_l[ii]->Draw();
    histos_c[ii]->Write();
  }
  rel_err << "\n";
  TGraphErrors *fitspread = new TGraphErrors(unf_bins,fit_peak,err0,fit_sigma);
  fitspread->SetMarkerStyle(47);
  fitspread->SetMarkerSize(1);
  fitspread->SetLineWidth(3);
  fitspread->Write("fit_flux");
  std::cout << "file outputs_systcut_Nue/systcut_Nue.root created" << std::endl;
  f_out->Close();
}
