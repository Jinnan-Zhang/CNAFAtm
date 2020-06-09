void makecontmatrix() {
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);

  TTree *mytree;
  TFile *_file1 = TFile::Open("/home/settanta/Documents/JUNO/Work/Atmo/analysis/unfolding/matrix/treemaker/trees/MC_44K_1m.root");
  _file1->GetObject("Data",mytree);
  //////////////////////////ELECTRONS-LPMT///////////////////////////////////////////
  TCanvas *c15 = new TCanvas("c15","",1000,1200);
  TH2F *Npe_VS_Ev_Elec_LPMT_nueCC_CUT_BKG = new TH2F("Npe_VS_Ev_Elec_LPMT_nueCC_CUT_BKG","",20,1.7,4.31,20,5.,7.3);
  mytree->Project("Npe_VS_Ev_Elec_LPMT_nueCC_CUT_BKG","log10(trueNPE_LPMT):log10(nuEnergy)","Tres_RMS<80 && abs(init_lepID)!=11 && newVradius<16000","");
  TH2F *Npe_VS_Ev_Elec_LPMT_nueCC_CUT_ALL = new TH2F("Npe_VS_Ev_Elec_LPMT_nueCC_CUT_ALL","",20,1.7,4.31,20,5.,7.3);
  mytree->Project("Npe_VS_Ev_Elec_LPMT_nueCC_CUT_ALL","log10(trueNPE_LPMT):log10(nuEnergy)","Tres_RMS<80 && newVradius<16000","");
  TH2F *Npe_VS_Ev_Elec_LPMT_nueCC_CONT = (TH2F*)Npe_VS_Ev_Elec_LPMT_nueCC_CUT_BKG->Clone("Npe_VS_Ev_Elec_LPMT_nueCC_CONT");
  Npe_VS_Ev_Elec_LPMT_nueCC_CONT->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");  
  Npe_VS_Ev_Elec_LPMT_nueCC_CONT->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_Elec_LPMT_nueCC_CONT->Divide(Npe_VS_Ev_Elec_LPMT_nueCC_CUT_ALL);
  gStyle->SetPalette(kLightTemperature);
  Npe_VS_Ev_Elec_LPMT_nueCC_CONT->Draw("colz");

  c15->SaveAs("Plot/logNPE_VS_logEv_LPMT_nuall_0-20GeV_16volcut_1m_less80nscut_ElecCONT.png");
  c15->SaveAs("Plot/logNPE_VS_logEv_LPMT_nuall_0-20GeV_16volcut_1m_less80nscut_ElecCONT.pdf");
  c15->SaveAs("Plot/logNPE_VS_logEv_LPMT_nuall_0-20GeV_16volcut_1m_less80nscut_ElecCONT.C");

  //////////////////////////ELECTRONS-SPMT///////////////////////////////////////////
  TCanvas *c16 = new TCanvas("c16","",1000,1200);
  TH2F *Npe_VS_Ev_Elec_SPMT_nueCC_CUT_BKG = new TH2F("Npe_VS_Ev_Elec_SPMT_nueCC_CUT_BKG","",20,1.7,4.31,20,3.,6.1);
  mytree->Project("Npe_VS_Ev_Elec_SPMT_nueCC_CUT_BKG","log10(trueNPE_SPMT):log10(nuEnergy)","Tres_RMS<80 && abs(init_lepID)!=11 && newVradius<16000","");
  TH2F *Npe_VS_Ev_Elec_SPMT_nueCC_CUT_ALL = new TH2F("Npe_VS_Ev_Elec_SPMT_nueCC_CUT_ALL","",20,1.7,4.31,20,3.,6.1);
  mytree->Project("Npe_VS_Ev_Elec_SPMT_nueCC_CUT_ALL","log10(trueNPE_SPMT):log10(nuEnergy)","Tres_RMS<80 && newVradius<16000","");
  TH2F *Npe_VS_Ev_Elec_SPMT_nueCC_CONT = (TH2F*)Npe_VS_Ev_Elec_SPMT_nueCC_CUT_BKG->Clone("Npe_VS_Ev_Elec_SPMT_nueCC_CONT");
  Npe_VS_Ev_Elec_SPMT_nueCC_CONT->GetYaxis()->SetTitle("log_{10}(NPE_{SPMT})");
  Npe_VS_Ev_Elec_SPMT_nueCC_CONT->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_Elec_SPMT_nueCC_CONT->Divide(Npe_VS_Ev_Elec_SPMT_nueCC_CUT_ALL);
  gStyle->SetPalette(kLightTemperature);
  Npe_VS_Ev_Elec_SPMT_nueCC_CONT->Draw("colz");

  c16->SaveAs("Plot/logNPE_VS_logEv_SPMT_nuall_0-20GeV_16volcut_1m_less80nscut_ElecCONT.png");
  c16->SaveAs("Plot/logNPE_VS_logEv_SPMT_nuall_0-20GeV_16volcut_1m_less80nscut_ElecCONT.pdf");
  c16->SaveAs("Plot/logNPE_VS_logEv_SPMT_nuall_0-20GeV_16volcut_1m_less80nscut_ElecCONT.C");

  //////////////////////////MUONS-LPMT///////////////////////////////////////////
  TCanvas *c25 = new TCanvas("c25","",1000,1200);
  TH2F *Npe_VS_Ev_noElec_LPMT_nueCC_CUT_BKG = new TH2F("Npe_VS_Ev_noElec_LPMT_nueCC_CUT_BKG","",20,1.7,4.31,20,5.,7.3);
  mytree->Project("Npe_VS_Ev_noElec_LPMT_nueCC_CUT_BKG","log10(trueNPE_LPMT):log10(nuEnergy)","Tres_RMS>90 && abs(init_lepID)!=13 && newVradius<16000","");
  TH2F *Npe_VS_Ev_noElec_LPMT_nueCC_CUT_ALL = new TH2F("Npe_VS_Ev_noElec_LPMT_nueCC_CUT_ALL","",20,1.7,4.31,20,5.,7.3);
  mytree->Project("Npe_VS_Ev_noElec_LPMT_nueCC_CUT_ALL","log10(trueNPE_LPMT):log10(nuEnergy)","Tres_RMS>90 && newVradius<16000","");
  TH2F *Npe_VS_Ev_noElec_LPMT_nueCC_CONT = (TH2F*)Npe_VS_Ev_noElec_LPMT_nueCC_CUT_BKG->Clone("Npe_VS_Ev_noElec_LPMT_nueCC_CONT");
  Npe_VS_Ev_noElec_LPMT_nueCC_CONT->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");  
  Npe_VS_Ev_noElec_LPMT_nueCC_CONT->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_noElec_LPMT_nueCC_CONT->Divide(Npe_VS_Ev_noElec_LPMT_nueCC_CUT_ALL);
  gStyle->SetPalette(kLightTemperature);
  Npe_VS_Ev_noElec_LPMT_nueCC_CONT->Draw("colz");

  c25->SaveAs("Plot/logNPE_VS_logEv_LPMT_nuall_0-20GeV_16volcut_1m_over90nscut_MuCONT.png");
  c25->SaveAs("Plot/logNPE_VS_logEv_LPMT_nuall_0-20GeV_16volcut_1m_over90nscut_MuCONT.pdf");
  c25->SaveAs("Plot/logNPE_VS_logEv_LPMT_nuall_0-20GeV_16volcut_1m_over90nscut_MuCONT.C");

  //////////////////////////MUONS-SPMT///////////////////////////////////////////
  TCanvas *c26 = new TCanvas("c26","",1000,1200);
  TH2F *Npe_VS_Ev_noElec_SPMT_nueCC_CUT_BKG = new TH2F("Npe_VS_Ev_noElec_SPMT_nueCC_CUT_BKG","",20,1.7,4.31,20,3.,6.1);
  mytree->Project("Npe_VS_Ev_noElec_SPMT_nueCC_CUT_BKG","log10(trueNPE_SPMT):log10(nuEnergy)","Tres_RMS>90 && abs(init_lepID)!=13 && newVradius<16000","");
  TH2F *Npe_VS_Ev_noElec_SPMT_nueCC_CUT_ALL = new TH2F("Npe_VS_Ev_noElec_SPMT_nueCC_CUT_ALL","",20,1.7,4.31,20,3.,6.1);
  mytree->Project("Npe_VS_Ev_noElec_SPMT_nueCC_CUT_ALL","log10(trueNPE_SPMT):log10(nuEnergy)","Tres_RMS>90 && newVradius<16000","");
  TH2F *Npe_VS_Ev_noElec_SPMT_nueCC_CONT = (TH2F*)Npe_VS_Ev_noElec_SPMT_nueCC_CUT_BKG->Clone("Npe_VS_Ev_noElec_SPMT_nueCC_CONT");
  Npe_VS_Ev_noElec_SPMT_nueCC_CONT->GetYaxis()->SetTitle("log_{10}(NPE_{SPMT})");
  Npe_VS_Ev_noElec_SPMT_nueCC_CONT->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_noElec_SPMT_nueCC_CONT->Divide(Npe_VS_Ev_noElec_SPMT_nueCC_CUT_ALL);
  gStyle->SetPalette(kLightTemperature);
  Npe_VS_Ev_noElec_SPMT_nueCC_CONT->Draw("colz");

  c26->SaveAs("Plot/logNPE_VS_logEv_SPMT_nuall_0-20GeV_16volcut_1m_over90nscut_MuCONT.png");
  c26->SaveAs("Plot/logNPE_VS_logEv_SPMT_nuall_0-20GeV_16volcut_1m_over90nscut_MuCONT.pdf");
  c26->SaveAs("Plot/logNPE_VS_logEv_SPMT_nuall_0-20GeV_16volcut_1m_over90nscut_MuCONT.C");
  
}
