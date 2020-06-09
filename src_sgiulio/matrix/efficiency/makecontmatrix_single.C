void makecontmatrix_single() {
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
  TH2F *Npe_VS_Ev_Elec_LPMT_nueCC_CUT_BKG = new TH2F("Npe_VS_Ev_Elec_LPMT_nueCC_CUT_BKG","",20,1.7,4.31,20,5.,7.3);
  mytree->Project("Npe_VS_Ev_Elec_LPMT_nueCC_CUT_BKG","log10(trueNPE_LPMT):log10(nuEnergy)","Tres_RMS<80 && abs(init_lepID)!=11 && newVradius<16000","");
  TH2F *Npe_VS_Ev_Elec_LPMT_nueCC_CUT_ALL = new TH2F("Npe_VS_Ev_Elec_LPMT_nueCC_CUT_ALL","",20,1.7,4.31,20,5.,7.3);
  mytree->Project("Npe_VS_Ev_Elec_LPMT_nueCC_CUT_ALL","log10(trueNPE_LPMT):log10(nuEnergy)","Tres_RMS<80 && newVradius<16000","");
  TH2F *Npe_VS_Ev_Elec_LPMT_nueCC_CONT = (TH2F*)Npe_VS_Ev_Elec_LPMT_nueCC_CUT_BKG->Clone("Npe_VS_Ev_Elec_LPMT_nueCC_CONT");
  Npe_VS_Ev_Elec_LPMT_nueCC_CONT->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_VS_Ev_Elec_LPMT_nueCC_CONT->GetYaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_Elec_LPMT_nueCC_CONT->GetYaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_Elec_LPMT_nueCC_CONT->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_Elec_LPMT_nueCC_CONT->GetXaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_Elec_LPMT_nueCC_CONT->GetXaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_Elec_LPMT_nueCC_CONT->GetZaxis()->SetLabelSize(0.05); 
  Npe_VS_Ev_Elec_LPMT_nueCC_CONT->Divide(Npe_VS_Ev_Elec_LPMT_nueCC_CUT_ALL);
  Npe_VS_Ev_Elec_LPMT_nueCC_CONT->SetTitle("#sigma (t_{res}) < 80 ns");
  //gStyle->SetPalette(kLightTemperature);
  cc->cd(1);
  Npe_VS_Ev_Elec_LPMT_nueCC_CONT->Draw("colz");

  //////////////////////////ELECTRONS-SPMT///////////////////////////////////////////
  TH2F *Npe_VS_Ev_Elec_SPMT_nueCC_CUT_BKG = new TH2F("Npe_VS_Ev_Elec_SPMT_nueCC_CUT_BKG","",20,1.7,4.31,20,3.,6.1);
  mytree->Project("Npe_VS_Ev_Elec_SPMT_nueCC_CUT_BKG","log10(trueNPE_SPMT):log10(nuEnergy)","Tres_RMS<80 && abs(init_lepID)!=11 && newVradius<16000","");
  TH2F *Npe_VS_Ev_Elec_SPMT_nueCC_CUT_ALL = new TH2F("Npe_VS_Ev_Elec_SPMT_nueCC_CUT_ALL","",20,1.7,4.31,20,3.,6.1);
  mytree->Project("Npe_VS_Ev_Elec_SPMT_nueCC_CUT_ALL","log10(trueNPE_SPMT):log10(nuEnergy)","Tres_RMS<80 && newVradius<16000","");
  TH2F *Npe_VS_Ev_Elec_SPMT_nueCC_CONT = (TH2F*)Npe_VS_Ev_Elec_SPMT_nueCC_CUT_BKG->Clone("Npe_VS_Ev_Elec_SPMT_nueCC_CONT");
  Npe_VS_Ev_Elec_SPMT_nueCC_CONT->GetYaxis()->SetTitle("log_{10}(NPE_{SPMT})");
  Npe_VS_Ev_Elec_SPMT_nueCC_CONT->GetYaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_Elec_SPMT_nueCC_CONT->GetYaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_Elec_SPMT_nueCC_CONT->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_Elec_SPMT_nueCC_CONT->GetXaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_Elec_SPMT_nueCC_CONT->GetXaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_Elec_SPMT_nueCC_CONT->GetZaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_Elec_SPMT_nueCC_CONT->Divide(Npe_VS_Ev_Elec_SPMT_nueCC_CUT_ALL);
  Npe_VS_Ev_Elec_SPMT_nueCC_CONT->SetTitle("#sigma (t_{res}) < 80 ns");
  //gStyle->SetPalette(kLightTemperature);
  cc->cd(2);
  Npe_VS_Ev_Elec_SPMT_nueCC_CONT->Draw("colz");

  //////////////////////////MUONS-LPMT///////////////////////////////////////////
  TH2F *Npe_VS_Ev_noElec_LPMT_nueCC_CUT_BKG = new TH2F("Npe_VS_Ev_noElec_LPMT_nueCC_CUT_BKG","",20,1.7,4.31,20,5.,7.3);
  mytree->Project("Npe_VS_Ev_noElec_LPMT_nueCC_CUT_BKG","log10(trueNPE_LPMT):log10(nuEnergy)","Tres_RMS>90 && abs(init_lepID)!=13 && newVradius<16000","");
  TH2F *Npe_VS_Ev_noElec_LPMT_nueCC_CUT_ALL = new TH2F("Npe_VS_Ev_noElec_LPMT_nueCC_CUT_ALL","",20,1.7,4.31,20,5.,7.3);
  mytree->Project("Npe_VS_Ev_noElec_LPMT_nueCC_CUT_ALL","log10(trueNPE_LPMT):log10(nuEnergy)","Tres_RMS>90 && newVradius<16000","");
  TH2F *Npe_VS_Ev_noElec_LPMT_nueCC_CONT = (TH2F*)Npe_VS_Ev_noElec_LPMT_nueCC_CUT_BKG->Clone("Npe_VS_Ev_noElec_LPMT_nueCC_CONT");
  Npe_VS_Ev_noElec_LPMT_nueCC_CONT->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_VS_Ev_noElec_LPMT_nueCC_CONT->GetYaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_noElec_LPMT_nueCC_CONT->GetYaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_noElec_LPMT_nueCC_CONT->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_noElec_LPMT_nueCC_CONT->GetXaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_noElec_LPMT_nueCC_CONT->GetXaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_noElec_LPMT_nueCC_CONT->GetZaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_noElec_LPMT_nueCC_CONT->Divide(Npe_VS_Ev_noElec_LPMT_nueCC_CUT_ALL);
  Npe_VS_Ev_noElec_LPMT_nueCC_CONT->SetTitle("#sigma (t_{res}) > 90 ns");
  //gStyle->SetPalette(kLightTemperature);
  cc->cd(3);
  Npe_VS_Ev_noElec_LPMT_nueCC_CONT->Draw("colz");

  //////////////////////////MUONS-SPMT///////////////////////////////////////////
  TH2F *Npe_VS_Ev_noElec_SPMT_nueCC_CUT_BKG = new TH2F("Npe_VS_Ev_noElec_SPMT_nueCC_CUT_BKG","",20,1.7,4.31,20,3.,6.1);
  mytree->Project("Npe_VS_Ev_noElec_SPMT_nueCC_CUT_BKG","log10(trueNPE_SPMT):log10(nuEnergy)","Tres_RMS>90 && abs(init_lepID)!=13 && newVradius<16000","");
  TH2F *Npe_VS_Ev_noElec_SPMT_nueCC_CUT_ALL = new TH2F("Npe_VS_Ev_noElec_SPMT_nueCC_CUT_ALL","",20,1.7,4.31,20,3.,6.1);
  mytree->Project("Npe_VS_Ev_noElec_SPMT_nueCC_CUT_ALL","log10(trueNPE_SPMT):log10(nuEnergy)","Tres_RMS>90 && newVradius<16000","");
  TH2F *Npe_VS_Ev_noElec_SPMT_nueCC_CONT = (TH2F*)Npe_VS_Ev_noElec_SPMT_nueCC_CUT_BKG->Clone("Npe_VS_Ev_noElec_SPMT_nueCC_CONT");
  Npe_VS_Ev_noElec_SPMT_nueCC_CONT->GetYaxis()->SetTitle("log_{10}(NPE_{SPMT})");
  Npe_VS_Ev_noElec_SPMT_nueCC_CONT->GetYaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_noElec_SPMT_nueCC_CONT->GetYaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_noElec_SPMT_nueCC_CONT->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_noElec_SPMT_nueCC_CONT->GetXaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_noElec_SPMT_nueCC_CONT->GetXaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_noElec_SPMT_nueCC_CONT->GetZaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_noElec_SPMT_nueCC_CONT->Divide(Npe_VS_Ev_noElec_SPMT_nueCC_CUT_ALL);
  Npe_VS_Ev_noElec_SPMT_nueCC_CONT->SetTitle("#sigma (t_{res}) > 90 ns");
  //gStyle->SetPalette(kLightTemperature);
  cc->cd(4);
  Npe_VS_Ev_noElec_SPMT_nueCC_CONT->Draw("colz");

  cc->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_16volcut_1m_e-mu_CONT.png");
  cc->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_16volcut_1m_e-mu_CONT.pdf");
  cc->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_16volcut_1m_e-mu_CONT.C");
  
}
