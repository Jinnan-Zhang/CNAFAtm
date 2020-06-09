void aitoff() {
  gStyle->SetOptStat(0);
  gStyle->SetPadBottomMargin(0.12);
  gStyle->SetTitleH(0.1);
  gStyle->SetTitleW(1.05);
  //gStyle->SetOptTitle(0);

  TTree *mytree;
  TFile *_file1 = TFile::Open("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker/trees/DATA_10K_1m_TOT.root");
  //TFile *_file1 = TFile::Open("/home/sgiulio/Giulio/University/JUNO/juno-unfolding/treemaker/trees/MC_100K_1m_SHORT.root");
  _file1->GetObject("Data",mytree);

  ///////////////////////////////////////////////////////////////////

  TCanvas *cc = new TCanvas("cc","",900,900);
  cc->cd();
  TH2F *ha = new TH2F("ha","", 45, -180, 180, 44, -89.5, 89.5);
  ha->GetXaxis()->SetTitle("#phi [deg]");
  ha->GetYaxis()->SetTitle("#theta [deg]");  
  mytree->Project("ha","(-theta_hitSPMT+90):(phi_hitSPMT-180)","evtID==4","");
  ha->Draw("aitoff");
  cc->SaveAs("Plot/MAP_theta-phi_nueCC_900MeV_SPMT.pdf");
  cc->SaveAs("Plot/MAP_theta-phi_nueCC_900MeV_SPMT.png");

}
