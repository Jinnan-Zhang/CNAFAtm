void makeeffmatrix_single() {
  gStyle->SetOptStat(0);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetPadRightMargin(0.12);
  gStyle->SetTitleH(0.1);
  gStyle->SetTitleW(1.05);

  TCanvas *cc = new TCanvas("cc","",1600,350);
  cc->Divide(4,1);
  
  TTree *mytree;
  TFile *_file1 = TFile::Open("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/matrix/treemaker/trees/MC_97K_1m.root");
  _file1->GetObject("Data",mytree);
  //////////////////////////ELECTRONS-LPMT///////////////////////////////////////////
  TH2F *Npe_VS_Ev_Elec_LPMT_nueCC_CUT = new TH2F("Npe_VS_Ev_Elec_LPMT_nueCC_CUT","",20,1.7,4.31,20,5.,7.3);
  mytree->Project("Npe_VS_Ev_Elec_LPMT_nueCC_CUT","log10(trueNPE_LPMT):log10(nuEnergy)","Tres_RMS<80 && CCint==1 && abs(init_lepID)==11 && newVradius<16000","");
  TH2F *Npe_VS_Ev_Elec_LPMT_nueCC_FULL = new TH2F("Npe_VS_Ev_Elec_LPMT_nueCC_FULL","",20,1.7,4.31,20,5.,7.3);
  mytree->Project("Npe_VS_Ev_Elec_LPMT_nueCC_FULL","log10(trueNPE_LPMT):log10(nuEnergy)","CCint==1 && abs(init_lepID)==11 && newVradius<16000","");
  TH2F *Npe_VS_Ev_Elec_LPMT_nueCC_EFF = (TH2F*)Npe_VS_Ev_Elec_LPMT_nueCC_CUT->Clone("Npe_VS_Ev_Elec_LPMT_nueCC_EFF");
  Npe_VS_Ev_Elec_LPMT_nueCC_EFF->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_VS_Ev_Elec_LPMT_nueCC_EFF->GetYaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_Elec_LPMT_nueCC_EFF->GetYaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_Elec_LPMT_nueCC_EFF->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_Elec_LPMT_nueCC_EFF->GetXaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_Elec_LPMT_nueCC_EFF->GetXaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_Elec_LPMT_nueCC_EFF->GetZaxis()->SetLabelSize(0.05); 
  Npe_VS_Ev_Elec_LPMT_nueCC_EFF->Divide(Npe_VS_Ev_Elec_LPMT_nueCC_FULL);
  Npe_VS_Ev_Elec_LPMT_nueCC_EFF->SetTitle("#sigma (t_{res}) < 80 ns");

  //gStyle->SetPalette(kLightTemperature);

  cc->cd(1);
  Npe_VS_Ev_Elec_LPMT_nueCC_EFF->Draw("colz");

  //////////////////////////ELECTRONS-SPMT///////////////////////////////////////////
  TH2F *Npe_VS_Ev_Elec_SPMT_nueCC_CUT = new TH2F("Npe_VS_Ev_Elec_SPMT_nueCC_CUT","",20,1.7,4.31,20,3.,6.1);
  mytree->Project("Npe_VS_Ev_Elec_SPMT_nueCC_CUT","log10(trueNPE_SPMT):log10(nuEnergy)","Tres_RMS<80 && CCint==1 && abs(init_lepID)==11 && newVradius<16000","");
  TH2F *Npe_VS_Ev_Elec_SPMT_nueCC_FULL = new TH2F("Npe_VS_Ev_Elec_SPMT_nueCC_FULL","",20,1.7,4.31,20,3.,6.1);
  mytree->Project("Npe_VS_Ev_Elec_SPMT_nueCC_FULL","log10(trueNPE_SPMT):log10(nuEnergy)","CCint==1 && abs(init_lepID)==11 && newVradius<16000","");
  TH2F *Npe_VS_Ev_Elec_SPMT_nueCC_EFF = (TH2F*)Npe_VS_Ev_Elec_SPMT_nueCC_CUT->Clone("Npe_VS_Ev_Elec_SPMT_nueCC_EFF");
  Npe_VS_Ev_Elec_SPMT_nueCC_EFF->GetYaxis()->SetTitle("log_{10}(NPE_{SPMT})");
  Npe_VS_Ev_Elec_SPMT_nueCC_EFF->GetYaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_Elec_SPMT_nueCC_EFF->GetYaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_Elec_SPMT_nueCC_EFF->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_Elec_SPMT_nueCC_EFF->GetXaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_Elec_SPMT_nueCC_EFF->GetXaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_Elec_SPMT_nueCC_EFF->GetZaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_Elec_SPMT_nueCC_EFF->Divide(Npe_VS_Ev_Elec_SPMT_nueCC_FULL);
  Npe_VS_Ev_Elec_SPMT_nueCC_EFF->SetTitle("#sigma (t_{res}) < 80 ns");
  //gStyle->SetPalette(kLightTemperature);
  cc->cd(2);
  Npe_VS_Ev_Elec_SPMT_nueCC_EFF->Draw("colz");

  //////////////////////////MUONS-LPMT///////////////////////////////////////////
  TH2F *Npe_VS_Ev_noElec_LPMT_nueCC_CUT = new TH2F("Npe_VS_Ev_noElec_LPMT_nueCC_CUT","",20,1.7,4.31,20,5.,7.3);
  mytree->Project("Npe_VS_Ev_noElec_LPMT_nueCC_CUT","log10(trueNPE_LPMT):log10(nuEnergy)","Tres_RMS>90 && CCint==1 && abs(init_lepID)==13 && newVradius<16000","");
  TH2F *Npe_VS_Ev_noElec_LPMT_nueCC_FULL = new TH2F("Npe_VS_Ev_noElec_LPMT_nueCC_FULL","",20,1.7,4.31,20,5.,7.3);
  mytree->Project("Npe_VS_Ev_noElec_LPMT_nueCC_FULL","log10(trueNPE_LPMT):log10(nuEnergy)","CCint==1 && abs(init_lepID)==13 && newVradius<16000","");
  TH2F *Npe_VS_Ev_noElec_LPMT_nueCC_EFF = (TH2F*)Npe_VS_Ev_noElec_LPMT_nueCC_CUT->Clone("Npe_VS_Ev_noElec_LPMT_nueCC_EFF");
  Npe_VS_Ev_noElec_LPMT_nueCC_EFF->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_VS_Ev_noElec_LPMT_nueCC_EFF->GetYaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_noElec_LPMT_nueCC_EFF->GetYaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_noElec_LPMT_nueCC_EFF->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_noElec_LPMT_nueCC_EFF->GetXaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_noElec_LPMT_nueCC_EFF->GetXaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_noElec_LPMT_nueCC_EFF->GetZaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_noElec_LPMT_nueCC_EFF->Divide(Npe_VS_Ev_noElec_LPMT_nueCC_FULL);
  Npe_VS_Ev_noElec_LPMT_nueCC_EFF->SetTitle("#sigma (t_{res}) > 90 ns");
  //gStyle->SetPalette(kLightTemperature);
  cc->cd(3);
  Npe_VS_Ev_noElec_LPMT_nueCC_EFF->Draw("colz");

  //////////////////////////MUONS-SPMT///////////////////////////////////////////
  TH2F *Npe_VS_Ev_noElec_SPMT_nueCC_CUT = new TH2F("Npe_VS_Ev_noElec_SPMT_nueCC_CUT","",20,1.7,4.31,20,3.,6.1);
  mytree->Project("Npe_VS_Ev_noElec_SPMT_nueCC_CUT","log10(trueNPE_SPMT):log10(nuEnergy)","Tres_RMS>90 && CCint==1 && abs(init_lepID)==13 && newVradius<16000","");
  TH2F *Npe_VS_Ev_noElec_SPMT_nueCC_FULL = new TH2F("Npe_VS_Ev_noElec_SPMT_nueCC_FULL","",20,1.7,4.31,20,3.,6.1);
  mytree->Project("Npe_VS_Ev_noElec_SPMT_nueCC_FULL","log10(trueNPE_SPMT):log10(nuEnergy)","CCint==1 && abs(init_lepID)==13 && newVradius<16000","");
  TH2F *Npe_VS_Ev_noElec_SPMT_nueCC_EFF = (TH2F*)Npe_VS_Ev_noElec_SPMT_nueCC_CUT->Clone("Npe_VS_Ev_noElec_SPMT_nueCC_EFF");
  Npe_VS_Ev_noElec_SPMT_nueCC_EFF->GetYaxis()->SetTitle("log_{10}(NPE_{SPMT})");
  Npe_VS_Ev_noElec_SPMT_nueCC_EFF->GetYaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_noElec_SPMT_nueCC_EFF->GetYaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_noElec_SPMT_nueCC_EFF->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_noElec_SPMT_nueCC_EFF->GetXaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_noElec_SPMT_nueCC_EFF->GetXaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_noElec_SPMT_nueCC_EFF->GetZaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_noElec_SPMT_nueCC_EFF->Divide(Npe_VS_Ev_noElec_SPMT_nueCC_FULL);
  Npe_VS_Ev_noElec_SPMT_nueCC_EFF->SetTitle("#sigma (t_{res}) > 90 ns");
  //gStyle->SetPalette(kLightTemperature);
  cc->cd(4);
  Npe_VS_Ev_noElec_SPMT_nueCC_EFF->Draw("colz");

  cc->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_16volcut_1m_e-mu_EFF.png");
  cc->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_16volcut_1m_e-mu_EFF.pdf");
  cc->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_16volcut_1m_e-mu_EFF.C");
  
}
