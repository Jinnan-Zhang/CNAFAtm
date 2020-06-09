void makeeffmatrix() {
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  
  TTree *mytree;
  TFile *_file1 = TFile::Open("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/matrix/treemaker/trees/MC_97K_1m.root");
  _file1->GetObject("Data",mytree);
  //////////////////////////ELECTRONS-LPMT///////////////////////////////////////////
  TCanvas *c15 = new TCanvas("c15","",1000,1200);
  TH2F *Npe_VS_Ev_Elec_LPMT_nueCC_CUT = new TH2F("Npe_VS_Ev_Elec_LPMT_nueCC_CUT","",20,1.7,4.31,20,5.,7.3);
  mytree->Project("Npe_VS_Ev_Elec_LPMT_nueCC_CUT","log10(trueNPE_LPMT):log10(nuEnergy)","Tres_RMS<80 && CCint==1 && abs(init_lepID)==11 && newVradius<16000","");
  TH2F *Npe_VS_Ev_Elec_LPMT_nueCC_FULL = new TH2F("Npe_VS_Ev_Elec_LPMT_nueCC_FULL","",20,1.7,4.31,20,5.,7.3);
  mytree->Project("Npe_VS_Ev_Elec_LPMT_nueCC_FULL","log10(trueNPE_LPMT):log10(nuEnergy)","CCint==1 && abs(init_lepID)==11 && newVradius<16000","");
  TH2F *Npe_VS_Ev_Elec_LPMT_nueCC_EFF = (TH2F*)Npe_VS_Ev_Elec_LPMT_nueCC_CUT->Clone("Npe_VS_Ev_Elec_LPMT_nueCC_EFF");
  Npe_VS_Ev_Elec_LPMT_nueCC_EFF->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");  
  Npe_VS_Ev_Elec_LPMT_nueCC_EFF->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_Elec_LPMT_nueCC_EFF->Divide(Npe_VS_Ev_Elec_LPMT_nueCC_FULL);
  //gStyle->SetPalette(kLightTemperature);
  Npe_VS_Ev_Elec_LPMT_nueCC_EFF->Draw("colz");

  c15->SaveAs("Plot/logNPE_VS_logEv_LPMT_nuall_0-20GeV_16volcut_1m_less80nscut_ElecEFF.png");
  c15->SaveAs("Plot/logNPE_VS_logEv_LPMT_nuall_0-20GeV_16volcut_1m_less80nscut_ElecEFF.pdf");
  c15->SaveAs("Plot/logNPE_VS_logEv_LPMT_nuall_0-20GeV_16volcut_1m_less80nscut_ElecEFF.C");

  //////////////////////////ELECTRONS-SPMT///////////////////////////////////////////
  TCanvas *c16 = new TCanvas("c16","",1000,1200);
  TH2F *Npe_VS_Ev_Elec_SPMT_nueCC_CUT = new TH2F("Npe_VS_Ev_Elec_SPMT_nueCC_CUT","",20,1.7,4.31,20,3.,6.1);
  mytree->Project("Npe_VS_Ev_Elec_SPMT_nueCC_CUT","log10(trueNPE_SPMT):log10(nuEnergy)","Tres_RMS<80 && CCint==1 && abs(init_lepID)==11 && newVradius<16000","");
  TH2F *Npe_VS_Ev_Elec_SPMT_nueCC_FULL = new TH2F("Npe_VS_Ev_Elec_SPMT_nueCC_FULL","",20,1.7,4.31,20,3.,6.1);
  mytree->Project("Npe_VS_Ev_Elec_SPMT_nueCC_FULL","log10(trueNPE_SPMT):log10(nuEnergy)","CCint==1 && abs(init_lepID)==11 && newVradius<16000","");
  TH2F *Npe_VS_Ev_Elec_SPMT_nueCC_EFF = (TH2F*)Npe_VS_Ev_Elec_SPMT_nueCC_CUT->Clone("Npe_VS_Ev_Elec_SPMT_nueCC_EFF");
  Npe_VS_Ev_Elec_SPMT_nueCC_EFF->GetYaxis()->SetTitle("log_{10}(NPE_{SPMT})");
  Npe_VS_Ev_Elec_SPMT_nueCC_EFF->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_Elec_SPMT_nueCC_EFF->Divide(Npe_VS_Ev_Elec_SPMT_nueCC_FULL);
  //gStyle->SetPalette(kLightTemperature);
  Npe_VS_Ev_Elec_SPMT_nueCC_EFF->Draw("colz");

  c16->SaveAs("Plot/logNPE_VS_logEv_SPMT_nuall_0-20GeV_16volcut_1m_less80nscut_ElecEFF.png");
  c16->SaveAs("Plot/logNPE_VS_logEv_SPMT_nuall_0-20GeV_16volcut_1m_less80nscut_ElecEFF.pdf");
  c16->SaveAs("Plot/logNPE_VS_logEv_SPMT_nuall_0-20GeV_16volcut_1m_less80nscut_ElecEFF.C");

  //////////////////////////MUONS-LPMT///////////////////////////////////////////
  TCanvas *c25 = new TCanvas("c25","",1000,1200);
  TH2F *Npe_VS_Ev_noElec_LPMT_nueCC_CUT = new TH2F("Npe_VS_Ev_noElec_LPMT_nueCC_CUT","",20,1.7,4.31,20,5.,7.3);
  mytree->Project("Npe_VS_Ev_noElec_LPMT_nueCC_CUT","log10(trueNPE_LPMT):log10(nuEnergy)","Tres_RMS>90 && CCint==1 && abs(init_lepID)==13 && newVradius<16000","");
  TH2F *Npe_VS_Ev_noElec_LPMT_nueCC_FULL = new TH2F("Npe_VS_Ev_noElec_LPMT_nueCC_FULL","",20,1.7,4.31,20,5.,7.3);
  mytree->Project("Npe_VS_Ev_noElec_LPMT_nueCC_FULL","log10(trueNPE_LPMT):log10(nuEnergy)","CCint==1 && abs(init_lepID)==13 && newVradius<16000","");
  TH2F *Npe_VS_Ev_noElec_LPMT_nueCC_EFF = (TH2F*)Npe_VS_Ev_noElec_LPMT_nueCC_CUT->Clone("Npe_VS_Ev_noElec_LPMT_nueCC_EFF");
  Npe_VS_Ev_noElec_LPMT_nueCC_EFF->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");  
  Npe_VS_Ev_noElec_LPMT_nueCC_EFF->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_noElec_LPMT_nueCC_EFF->Divide(Npe_VS_Ev_noElec_LPMT_nueCC_FULL);
  //gStyle->SetPalette(kLightTemperature);
  Npe_VS_Ev_noElec_LPMT_nueCC_EFF->Draw("colz");

  c25->SaveAs("Plot/logNPE_VS_logEv_LPMT_nuall_0-20GeV_16volcut_1m_over90nscut_MuEFF.png");
  c25->SaveAs("Plot/logNPE_VS_logEv_LPMT_nuall_0-20GeV_16volcut_1m_over90nscut_MuEFF.pdf");
  c25->SaveAs("Plot/logNPE_VS_logEv_LPMT_nuall_0-20GeV_16volcut_1m_over90nscut_MuEFF.C");

  //////////////////////////MUONS-SPMT///////////////////////////////////////////
  TCanvas *c26 = new TCanvas("c26","",1000,1200);
  TH2F *Npe_VS_Ev_noElec_SPMT_nueCC_CUT = new TH2F("Npe_VS_Ev_noElec_SPMT_nueCC_CUT","",20,1.7,4.31,20,3.,6.1);
  mytree->Project("Npe_VS_Ev_noElec_SPMT_nueCC_CUT","log10(trueNPE_SPMT):log10(nuEnergy)","Tres_RMS>90 && CCint==1 && abs(init_lepID)==13 && newVradius<16000","");
  TH2F *Npe_VS_Ev_noElec_SPMT_nueCC_FULL = new TH2F("Npe_VS_Ev_noElec_SPMT_nueCC_FULL","",20,1.7,4.31,20,3.,6.1);
  mytree->Project("Npe_VS_Ev_noElec_SPMT_nueCC_FULL","log10(trueNPE_SPMT):log10(nuEnergy)","CCint==1 && abs(init_lepID)==13 && newVradius<16000","");
  TH2F *Npe_VS_Ev_noElec_SPMT_nueCC_EFF = (TH2F*)Npe_VS_Ev_noElec_SPMT_nueCC_CUT->Clone("Npe_VS_Ev_noElec_SPMT_nueCC_EFF");
  Npe_VS_Ev_noElec_SPMT_nueCC_EFF->GetYaxis()->SetTitle("log_{10}(NPE_{SPMT})");
  Npe_VS_Ev_noElec_SPMT_nueCC_EFF->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_noElec_SPMT_nueCC_EFF->Divide(Npe_VS_Ev_noElec_SPMT_nueCC_FULL);
  //gStyle->SetPalette(kLightTemperature);
  Npe_VS_Ev_noElec_SPMT_nueCC_EFF->Draw("colz");

  c26->SaveAs("Plot/logNPE_VS_logEv_SPMT_nuall_0-20GeV_16volcut_1m_over90nscut_MuEFF.png");
  c26->SaveAs("Plot/logNPE_VS_logEv_SPMT_nuall_0-20GeV_16volcut_1m_over90nscut_MuEFF.pdf");
  c26->SaveAs("Plot/logNPE_VS_logEv_SPMT_nuall_0-20GeV_16volcut_1m_over90nscut_MuEFF.C");
  
}
