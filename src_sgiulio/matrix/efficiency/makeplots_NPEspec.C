void makeplots_NPEspec() {
  gStyle->SetOptStat(0);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadLeftMargin(0.1);
  gStyle->SetPadRightMargin(0.05);
  gStyle->SetOptTitle(0);

  TTree *mytree;
  TFile *_file1 = TFile::Open("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker/trees/MC_500K_1m_TOT_NEW.root");
  //TFile *_file1 = TFile::Open("/home/sgiulio/Giulio/University/JUNO/juno-unfolding/treemaker/trees/MC_100K_1m_SHORT.root");
  _file1->GetObject("Data",mytree);

  ///////////////////////////////////////////////////////////////////
  TCanvas *c8a = new TCanvas("c8a","",1200,1000);
  c8a->Divide(2,1);
  TLegend * leg8a = new TLegend(0.7,0.7,0.9,0.5);
  leg8a->SetBorderSize(0);
  TLegend * leg8b = new TLegend(0.7,0.7,0.9,0.5);
  leg8b->SetBorderSize(0);
  TH1F *Npe_Nue_Nuecut = new TH1F("Npe_Nue_Nuecut","",50,0.,3.0E7);
  Npe_Nue_Nuecut->GetXaxis()->SetTitle("NPE");
  Npe_Nue_Nuecut->GetXaxis()->SetTitleSize(0.06);
  Npe_Nue_Nuecut->GetXaxis()->SetLabelSize(0.06);
  Npe_Nue_Nuecut->GetYaxis()->SetTitle("entries");
  Npe_Nue_Nuecut->GetYaxis()->SetLabelSize(0.06);
  Npe_Nue_Nuecut->GetYaxis()->SetTitleOffset(1.2);
  Npe_Nue_Nuecut->SetLineWidth(3);
  Npe_Nue_Nuecut->SetLineColor(46);
  mytree->Project("Npe_Nue_Nuecut","trueNPE_LPMT_CD","abs(init_nuID)==12 && newVradius<16000. && trueNPE_LPMT_WP < 60. && trueNPE_LPMT_CD > 1.E5 && Tres_RMS < 75","");
  leg8a->AddEntry(Npe_Nue_Nuecut,"#nu_{e}","l");
  c8a->cd(1);
  gPad->SetLogy();
  Npe_Nue_Nuecut->Draw();
  TH1F *Npe_Numu_Nuecut = new TH1F("Npe_Numu_Nuecut","",50,0.,3.0E7);
  Npe_Numu_Nuecut->SetLineWidth(3);
  Npe_Numu_Nuecut->SetLineColor(46);
  Npe_Numu_Nuecut->SetLineStyle(2);
  mytree->Project("Npe_Numu_Nuecut","trueNPE_LPMT_CD","abs(init_nuID)==14 && newVradius<16000. && trueNPE_LPMT_WP < 60. && trueNPE_LPMT_CD\
 > 1.E5 && Tres_RMS < 75","");
  leg8a->AddEntry(Npe_Numu_Nuecut,"#nu_{#mu}","l");
  Npe_Numu_Nuecut->Draw("same");
  leg8a->Draw();
  ////////////////////////////////////////
  TH1F *Npe_Numu_Numucut = new TH1F("Npe_Numu_Numucut","",50,0.,3.0E7);
  Npe_Numu_Numucut->GetXaxis()->SetTitle("NPE");
  Npe_Numu_Numucut->GetXaxis()->SetTitleSize(0.06);
  Npe_Numu_Numucut->GetXaxis()->SetLabelSize(0.06);
  Npe_Numu_Numucut->GetYaxis()->SetTitle("entries");
  Npe_Numu_Numucut->GetYaxis()->SetLabelSize(0.06);
  Npe_Numu_Numucut->GetYaxis()->SetTitleOffset(1.2);
  Npe_Numu_Numucut->SetLineWidth(3);
  Npe_Numu_Numucut->SetLineColor(9);
  mytree->Project("Npe_Numu_Numucut","trueNPE_LPMT_CD","abs(init_nuID)==14 && newVradius<16000. && trueNPE_LPMT_WP < 60. && trueNPE_LPMT_CD > 5.E5 && Tres_RMS > 95","");
  leg8b->AddEntry(Npe_Numu_Numucut,"#nu_{#mu}","l");
  c8a->cd(2);
  gPad->SetLogy();
  Npe_Numu_Numucut->Draw();
  TH1F *Npe_Nue_Numucut = new TH1F("Npe_Nue_Numucut","",50,0.,3.0E7);
  Npe_Nue_Numucut->SetLineWidth(3);
  Npe_Nue_Numucut->SetLineColor(9);
  Npe_Nue_Numucut->SetLineStyle(2);
  mytree->Project("Npe_Nue_Numucut","trueNPE_LPMT_CD","abs(init_nuID)==12 && newVradius<16000. && trueNPE_LPMT_WP < 60. && trueNPE_LPMT_CD > 5.E5 && Tres_RMS > 95","");
  leg8b->AddEntry(Npe_Nue_Numucut,"#nu_{e}","l");
  Npe_Nue_Numucut->Draw("same");
  leg8b->Draw();

  c8a->SaveAs("Plot/NPE_LPMT_0-20GeV_samplecuts_1m.png");
  c8a->SaveAs("Plot/NPE_LPMT_0-20GeV_samplecuts_1m.pdf");
  c8a->SaveAs("Plot/NPE_LPMT_0-20GeV_samplecuts_1m.C");

  /////////////////////////LOGPLOTS//////////////////////////////////////////
  TCanvas *c9a = new TCanvas("c9a","",1200,700);
  c9a->Divide(2,1);
  TLegend * leg9a = new TLegend(0.3,0.25,0.5,0.55);
  leg9a->SetBorderSize(0);
  TLegend * leg9b = new TLegend(0.2,0.25,0.4,0.55);
  leg9b->SetBorderSize(0);
  TH1F *LogNpeNue_Nuecut = new TH1F("LogNpeNue_Nuecut","",35,5.,7.5);
  LogNpeNue_Nuecut->GetXaxis()->SetTitle("log_{10} (NPE)");
  LogNpeNue_Nuecut->GetXaxis()->SetTitleSize(0.06);
  LogNpeNue_Nuecut->GetXaxis()->SetLabelSize(0.06);
  LogNpeNue_Nuecut->GetYaxis()->SetTitle("entries");
  LogNpeNue_Nuecut->GetYaxis()->SetTitleSize(0.04);
  LogNpeNue_Nuecut->GetYaxis()->SetLabelSize(0.06);
  LogNpeNue_Nuecut->GetYaxis()->SetTitleOffset(0.8);
  LogNpeNue_Nuecut->SetLineWidth(3);
  LogNpeNue_Nuecut->SetLineColor(46);
  mytree->Project("LogNpeNue_Nuecut","log10(trueNPE_LPMT_CD)","abs(init_nuID)==12 && newVradius<16000. && trueNPE_LPMT_WP < 60. && trueNPE_LPMT_CD > 1.E5 && Tres_RMS < 75","");
  leg9a->AddEntry(LogNpeNue_Nuecut,"#nu_{e}","l");
  c9a->cd(1);
  gPad->SetLogy();
  LogNpeNue_Nuecut->Draw();
  TH1F *LogNpeNumu_Nuecut = new TH1F("LogNpeNumu_Nuecut","",35,5.,7.5);
  LogNpeNumu_Nuecut->SetLineWidth(3);
  LogNpeNumu_Nuecut->SetLineColor(46);
  LogNpeNumu_Nuecut->SetLineStyle(2);
  mytree->Project("LogNpeNumu_Nuecut","log10(trueNPE_LPMT_CD)","abs(init_nuID)==14 && newVradius<16000. && trueNPE_LPMT_WP < 60. && trueNPE_LPMT_CD\
 > 1.E5 && Tres_RMS < 75","");
  leg9a->AddEntry(LogNpeNumu_Nuecut,"#nu_{#mu}","l");
  LogNpeNumu_Nuecut->Draw("same");
  leg9a->Draw();
  ////////////////////////////////////////
  TH1F *LogNpeNumu_Numucut = new TH1F("LogNpeNumu_Numucut","",35,5.7,7.5);
  LogNpeNumu_Numucut->GetXaxis()->SetTitle("log_{10} (NPE)");
  LogNpeNumu_Numucut->GetXaxis()->SetTitleSize(0.06);
  LogNpeNumu_Numucut->GetXaxis()->SetLabelSize(0.06);
  LogNpeNumu_Numucut->GetYaxis()->SetTitle("entries");
  LogNpeNumu_Numucut->GetYaxis()->SetTitleSize(0.04);
  LogNpeNumu_Numucut->GetYaxis()->SetLabelSize(0.06);
  LogNpeNumu_Numucut->GetYaxis()->SetTitleOffset(0.8);
  LogNpeNumu_Numucut->SetLineWidth(3);
  LogNpeNumu_Numucut->SetLineColor(9);
  mytree->Project("LogNpeNumu_Numucut","log10(trueNPE_LPMT_CD)","abs(init_nuID)==14 && newVradius<16000. && trueNPE_LPMT_WP < 60. && trueNPE_LPMT_CD > 5.E5 && Tres_RMS > 95","");
  leg9b->AddEntry(LogNpeNumu_Numucut,"#nu_{#mu}","l");
  c9a->cd(2);
  gPad->SetLogy();
  LogNpeNumu_Numucut->Draw();
  TH1F *LogNpeNue_Numucut = new TH1F("LogNpeNue_Numucut","",35,5.7,7.5);
  LogNpeNue_Numucut->SetLineWidth(3);
  LogNpeNue_Numucut->SetLineColor(9);
  LogNpeNue_Numucut->SetLineStyle(2);
  mytree->Project("LogNpeNue_Numucut","log10(trueNPE_LPMT_CD)","abs(init_nuID)==12 && newVradius<16000. && trueNPE_LPMT_WP < 60. && trueNPE_LPMT_CD > 5.E5 && Tres_RMS > 95","");
  leg9b->AddEntry(LogNpeNue_Numucut,"#nu_{e}","l");
  LogNpeNue_Numucut->Draw("same");
  leg9b->Draw();

  c9a->SaveAs("Plot/LogNPE_LPMT_0-20GeV_samplecuts_1m.png");
  c9a->SaveAs("Plot/LogNPE_LPMT_0-20GeV_samplecuts_1m.pdf");
  c9a->SaveAs("Plot/LogNPE_LPMT_0-20GeV_samplecuts_1m.C");

}

