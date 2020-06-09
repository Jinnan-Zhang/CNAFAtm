void makeplots() {

  static const int NBINS_Nue = 7;
  static const int NBINS_Numu = 8;
  static const float lowNPE_Nue = 5.0;
  static const float upNPE_Nue = 7.2;
  static const float lowNPE_Numu = 5.7;
  static const float upNPE_Numu = 7.2;
  float nue_step = ((upNPE_Nue-lowNPE_Nue)/NBINS_Nue);
  float numu_step = ((upNPE_Numu-lowNPE_Numu)/NBINS_Numu);
  float lowedge, upedge;

  TTree *mytree;
  TFile *_file1 = TFile::Open("Tres_bins.root");
  TH1F* Nuesel_CC_Tres_Nue_h[NBINS_Nue];
  TH1F* Nuesel_CC_Tres_Numu_h[NBINS_Nue];
  TH1F* Nuesel_NC_Tres_h[NBINS_Nue];
  TH1F* Numusel_CC_Tres_Nue_h[NBINS_Numu];
  TH1F* Numusel_CC_Tres_Numu_h[NBINS_Numu];
  TH1F* Numusel_NC_Tres_h[NBINS_Numu];
  THStack *Nuesel_hs[NBINS_Nue];
  THStack *Numusel_hs[NBINS_Numu];
  TCanvas *cE = new TCanvas("cE", "#nu_{e} NPE bins", 1800, 1000);
  cE->Divide(4,2,0.00000001,0.01);
  TCanvas *cMu = new TCanvas("cMu", "#nu_{#mu} NPE bins", 1800, 1000);
  cMu->Divide(4,2,0.00000001,0.01);

  for (int ii=0; ii<NBINS_Nue; ii++) {
    lowedge = (lowNPE_Nue+(ii*nue_step));
    upedge = (lowNPE_Nue+((ii+1)*nue_step));
    char* titlepad_Nue = new char[128];
    sprintf(titlepad_Nue, "%.2f < log_{10} (NPE) < %.2f",lowedge,upedge);
    char* Nuesel_stackname = new char[128];
    sprintf(Nuesel_stackname, "tres_Nuesel_%i_hs", ii);
    Nuesel_hs[ii] = new THStack(Nuesel_stackname,"");
    char *Nuesel_histnameNuMuCC_in = new char[128];
    char *Nuesel_histnameNuMuCC_out = new char[128];
    sprintf(Nuesel_histnameNuMuCC_in, "tres_Nuesel_NumuCC_%i_h", ii);
    sprintf(Nuesel_histnameNuMuCC_out, "Nuesel_NumuCC_%i_h", ii);
    Nuesel_CC_Tres_Numu_h[ii] = new TH1F(Nuesel_histnameNuMuCC_out,"",160,40.,200.);
    _file1->GetObject(Nuesel_histnameNuMuCC_in, Nuesel_CC_Tres_Numu_h[ii]);
    Nuesel_hs[ii]->Add(Nuesel_CC_Tres_Numu_h[ii]);
    char *Nuesel_histnameNuECC_in = new char[128];
    char *Nuesel_histnameNuECC_out = new char[128];
    sprintf(Nuesel_histnameNuECC_in, "tres_Nuesel_NueCC_%i_h", ii);
    sprintf(Nuesel_histnameNuECC_out, "Nuesel_NueCC_%i_h", ii);
    Nuesel_CC_Tres_Nue_h[ii] = new TH1F(Nuesel_histnameNuECC_out,"",160,40.,200.);
    _file1->GetObject(Nuesel_histnameNuECC_in, Nuesel_CC_Tres_Nue_h[ii]);
    Nuesel_hs[ii]->Add(Nuesel_CC_Tres_Nue_h[ii]);
    char *Nuesel_histnameNuNC_in = new char[128];
    char *Nuesel_histnameNuNC_out = new char[128];
    sprintf(Nuesel_histnameNuNC_in, "tres_Nuesel_NuNC_%i_h", ii);
    sprintf(Nuesel_histnameNuNC_out, "Nuesel_NuNC_%i_h", ii);
    Nuesel_NC_Tres_h[ii] = new TH1F(Nuesel_histnameNuNC_out,"",160,40.,200.);
    _file1->GetObject(Nuesel_histnameNuNC_in, Nuesel_NC_Tres_h[ii]);
    Nuesel_hs[ii]->Add(Nuesel_NC_Tres_h[ii]);
    cE->cd(ii+1);
    Nuesel_hs[ii]->Draw();
    Nuesel_hs[ii]->SetTitle(titlepad_Nue);
    Nuesel_hs[ii]->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
    Nuesel_hs[ii]->GetYaxis()->SetTitle("entries");
    Nuesel_hs[ii]->Draw("HISTO NOSTACK");
    /////////////////////////////////////////////////////////////////////////////////////
  }
  for (int jj=0; jj<NBINS_Numu; jj++) {
    lowedge = (lowNPE_Numu+(jj*numu_step));
    upedge = (lowNPE_Numu+((jj+1)*numu_step));
    char* titlepad_Numu = new char[128];
    sprintf(titlepad_Numu, "%.2f < log_{10} (NPE) < %.2f",lowedge,upedge);
    char* Numusel_stackname = new char[128];
    sprintf(Numusel_stackname, "tres_Numusel_%i_hs", jj);
    Numusel_hs[jj] = new THStack(Numusel_stackname,"");
    char *Numusel_histnameNuMuCC_in = new char[128];
    char *Numusel_histnameNuMuCC_out = new char[128];
    sprintf(Numusel_histnameNuMuCC_in, "tres_Numusel_NumuCC_%i_h", jj);
    sprintf(Numusel_histnameNuMuCC_out, "Numusel_NumuCC_%i_h", jj);
    Numusel_CC_Tres_Numu_h[jj] = new TH1F(Numusel_histnameNuMuCC_out,"",160,40.,200.);
    _file1->GetObject(Numusel_histnameNuMuCC_in, Numusel_CC_Tres_Numu_h[jj]);
    Numusel_hs[jj]->Add(Numusel_CC_Tres_Numu_h[jj]);
    char *Numusel_histnameNuECC_in = new char[128];
    char *Numusel_histnameNuECC_out = new char[128];
    sprintf(Numusel_histnameNuECC_in, "tres_Numusel_NueCC_%i_h", jj);
    sprintf(Numusel_histnameNuECC_out, "Numusel_NueCC_%i_h", jj);
    Numusel_CC_Tres_Nue_h[jj] = new TH1F(Numusel_histnameNuECC_out,"",160,40.,200.);
    _file1->GetObject(Numusel_histnameNuECC_in, Numusel_CC_Tres_Nue_h[jj]);
    Numusel_hs[jj]->Add(Numusel_CC_Tres_Nue_h[jj]);
    char *Numusel_histnameNuNC_in = new char[128];
    char *Numusel_histnameNuNC_out = new char[128];
    sprintf(Numusel_histnameNuNC_in, "tres_Numusel_NuNC_%i_h", jj);
    sprintf(Numusel_histnameNuNC_out, "Numusel_NuNC_%i_h", jj);
    Numusel_NC_Tres_h[jj] = new TH1F(Numusel_histnameNuNC_out,"",160,40.,200.);
    _file1->GetObject(Numusel_histnameNuNC_in, Numusel_NC_Tres_h[jj]);
    Numusel_hs[jj]->Add(Numusel_NC_Tres_h[jj]);
    cMu->cd(jj+1);
    Numusel_hs[jj]->Draw();
    Numusel_hs[jj]->SetTitle(titlepad_Numu);
    Numusel_hs[jj]->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
    Numusel_hs[jj]->GetYaxis()->SetTitle("entries");
    Numusel_hs[jj]->Draw("HISTO NOSTACK");
  }

}
