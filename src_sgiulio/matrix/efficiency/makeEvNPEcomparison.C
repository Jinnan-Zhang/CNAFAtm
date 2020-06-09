void makeEvNPEcomparison() {
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  gStyle->SetPadBottomMargin(0.1);
  gStyle->SetPadLeftMargin(0.1);
  gStyle->SetPadRightMargin(0.1);

  TCanvas *cc = new TCanvas("cc","",1600,1200);
  cc->Divide(2,2);
  
  TTree *mytree;
  TFile *_file1 = TFile::Open("/home/sgiulio/Giulio/University/JUNO/juno-unfolding/treemaker/trees/MC_100K_1m_FULL.root");
  _file1->GetObject("Data",mytree);

  TLegend * leg1 = new TLegend(0.72,0.7,0.9,0.9);
  TH1F *Ev_nue_FC = new TH1F("Ev_nue_FC","",100,1.5,4.5);
  Ev_nue_FC->GetXaxis()->SetTitle("log_{10} (E_{#nu} [MeV])");
  Ev_nue_FC->GetYaxis()->SetTitle("entries");
  Ev_nue_FC->SetLineColor(kRed);
  Ev_nue_FC->SetLineWidth(5);
  mytree->Project("Ev_nue_FC","log10(nuEnergy)","FC==1 && CCint==1 && abs(init_lepID)==11","");
  TH1F *Ev_numu_FC = new TH1F("Ev_numu_FC","",100,1.5,4.5);
  Ev_numu_FC->GetXaxis()->SetTitle("log_{10} (E_{#nu} [MeV])");
  Ev_numu_FC->GetYaxis()->SetTitle("entries");
  Ev_numu_FC->SetLineColor(kBlue);
  Ev_numu_FC->SetLineWidth(5);
  mytree->Project("Ev_numu_FC","log10(nuEnergy)","FC==1 && CCint==1 && abs(init_lepID)==13","");
  TH1F *Ev_numu_PC = new TH1F("Ev_numu_PC","",100,1.5,4.5);
  Ev_numu_PC->GetXaxis()->SetTitle("log_{10} (E_{#nu} [MeV])");
  Ev_numu_PC->GetYaxis()->SetTitle("entries");
  Ev_numu_PC->SetLineColor(kGreen+2);
  Ev_numu_PC->SetLineWidth(5);
  mytree->Project("Ev_numu_PC","log10(nuEnergy)","PC==1 && CCint==1 && abs(init_lepID)==13","");
  cc->cd();
  leg1->AddEntry(Ev_nue_FC, "#nu_{e}^{CC} FC" ,"l");
  leg1->AddEntry(Ev_numu_FC, "#nu_{#mu}^{CC} FC" ,"l");
  leg1->AddEntry(Ev_numu_PC, "#nu_{#mu}^{CC} PC" ,"l");  
  Ev_numu_FC->Draw();
  Ev_nue_FC->Draw("same");
  Ev_numu_PC->Draw("same");
  leg1->Draw();
  cc->SaveAs("Plot/logEv_0-20GeV_containment.png");
  cc->SaveAs("Plot/logEv_0-20GeV_containment.pdf");
  cc->SaveAs("Plot/logEv_0-20GeV_containment.C");

  ////////////////////////////////2D///////////////////////////////

  TCanvas *cs = new TCanvas("cs","",1600,1000);
  TH2F *NPE_LPMT_VS_Ev_nue_FC = new TH2F("NPE_LPMT_VS_Ev_nue_FC","",100,1.5,4.5,100,3.5,7.35);
  NPE_LPMT_VS_Ev_nue_FC->GetXaxis()->SetTitle("log_{10} (E_{#nu} [MeV])");
  NPE_LPMT_VS_Ev_nue_FC->GetYaxis()->SetTitle("log_{10} (NPE_{LPMT})");
  mytree->Project("NPE_LPMT_VS_Ev_nue_FC","log10(trueNPE_LPMT):log10(nuEnergy)","FC==1 && CCint==1 && abs(init_lepID)==11 && newVradius<16000.","");
  cs->cd();
  NPE_LPMT_VS_Ev_nue_FC->Draw("colz");
  cs->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_nueCC_FC.png");
  cs->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_nueCC_FC.pdf");
  cs->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_nueCC_FC.C");
  TCanvas *c3 = new TCanvas("c3","",1600,1000);
  TH2F *NPE_LPMT_VS_Ev_numu_FC = new TH2F("NPE_LPMT_VS_Ev_numu_FC","",100,1.5,4.5,100,3.5,7.35);
  NPE_LPMT_VS_Ev_numu_FC->GetXaxis()->SetTitle("log_{10} (E_{#nu} [MeV])");
  NPE_LPMT_VS_Ev_numu_FC->GetYaxis()->SetTitle("log_{10} (NPE_{LPMT})");
  mytree->Project("NPE_LPMT_VS_Ev_numu_FC","log10(trueNPE_LPMT):log10(nuEnergy)","FC==1 && CCint==1 && abs(init_lepID)==13","");
  c3->cd();
  NPE_LPMT_VS_Ev_numu_FC->Draw("colz");
  c3->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_numuCC_FC.png");
  c3->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_numuCC_FC.pdf");
  c3->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_numuCC_FC.C");
  TCanvas *c4 = new TCanvas("c4","",1600,1000);
  TH2F *NPE_LPMT_VS_Ev_numu_PC = new TH2F("NPE_LPMT_VS_Ev_numu_PC","",100,1.5,4.5,100,3.5,7.35);
  NPE_LPMT_VS_Ev_numu_PC->GetXaxis()->SetTitle("log_{10} (E_{#nu} [MeV])");
  NPE_LPMT_VS_Ev_numu_PC->GetYaxis()->SetTitle("log_{10} (NPE_{LPMT})");
  mytree->Project("NPE_LPMT_VS_Ev_numu_PC","log10(trueNPE_LPMT):log10(nuEnergy)","PC==1 && CCint==1 && abs(init_lepID)==13","");
  c4->cd();
  NPE_LPMT_VS_Ev_numu_PC->Draw("colz");
  c4->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_numuCC_PC.png");
  c4->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_numuCC_PC.pdf");
  c4->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_numuCC_PC.C");

}
