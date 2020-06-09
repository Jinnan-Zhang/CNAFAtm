void makeplots_tres_mu() {
  gStyle->SetOptStat(0);
  gStyle->SetPadBottomMargin(0.12);
  gStyle->SetTitleH(0.1);
  gStyle->SetTitleW(1.05);
  //gStyle->SetOptTitle(0);

  TTree *mytree;
  TFile *_file1 = TFile::Open("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker_mu/trees/MC_mu.root");
  _file1->GetObject("Data",mytree);

  ///////////////////////////////////////////////////////////////////

  TCanvas *cc = new TCanvas("cc","",900,900);
  cc->cd();
  TH2F *ha = new TH2F("ha","", 45, -180, 180, 44, -89.5, 89.5);
  ha->GetXaxis()->SetTitle("#phi [deg]");
  ha->GetYaxis()->SetTitle("#theta [deg]");  
  mytree->Project("ha","(90-theta_hitSPMT):(phi_hitSPMT-180)","evtID==0","");
  ha->Draw("aitoff");
  ha->SaveAs("Plot/MAP_theta-phi_evt1_SPMT.pdf");
  ha->SaveAs("Plot/MAP_theta-phi_evt1_SPMT.png");

  ////////////////////////////////TRES/////////////////////////////////////////////////  

  TCanvas *c1 = new TCanvas("c1","",1600,350);
  c1->Divide(4,1,0.00000001,0.01);
  TH1F *Tres_RMS_mu_1 = new TH1F("Tres_RMS_mu_1","",200,0.,200.);
  Tres_RMS_mu_1->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_mu_1->GetYaxis()->SetTitle("entries");
  Tres_RMS_mu_1->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_mu_1->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_mu_1->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_mu_1->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_mu_1->GetXaxis()->SetRangeUser(40,150);
  Tres_RMS_mu_1->SetLineWidth(3);
  Tres_RMS_mu_1->SetLineColor(kGray+3);
  Tres_RMS_mu_1->SetTitle("E_{#mu} = 2 GeV");
  mytree->Project("Tres_RMS_mu_1","Tres_RMS","lepEnergy > 2000. && lepEnergy < 2100.","");
  c1->cd(1);
  Tres_RMS_mu_1->Draw();

  ////////////////////////////////////

  TH1F *Tres_RMS_mu_2 = new TH1F("Tres_RMS_mu_2","",200,0.,200.);
  Tres_RMS_mu_2->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_mu_2->GetYaxis()->SetTitle("entries");
  Tres_RMS_mu_2->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_mu_2->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_mu_2->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_mu_2->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_mu_2->GetXaxis()->SetRangeUser(40,150);
  Tres_RMS_mu_2->SetLineWidth(3);
  Tres_RMS_mu_2->SetLineColor(kGray+3);
  Tres_RMS_mu_2->SetTitle("E_{#mu} = 20 GeV");
  mytree->Project("Tres_RMS_mu_2","Tres_RMS","lepEnergy > 20000. && lepEnergy < 21000.","");
  c1->cd(2);
  Tres_RMS_mu_2->Draw();

  ////////////////////////////////////

  TH1F *Tres_RMS_mu_3 = new TH1F("Tres_RMS_mu_3","",200,0.,200.);
  Tres_RMS_mu_3->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_mu_3->GetYaxis()->SetTitle("entries");
  Tres_RMS_mu_3->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_mu_3->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_mu_3->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_mu_3->GetYaxis()->SetLabelSize(0.047);  
  Tres_RMS_mu_3->SetLineWidth(3);
  Tres_RMS_mu_3->SetLineColor(kGray+3);
  Tres_RMS_mu_3->GetXaxis()->SetRangeUser(40,150);
  Tres_RMS_mu_3->SetTitle("E_{#mu} = 209 GeV");
  mytree->Project("Tres_RMS_mu_3","Tres_RMS","lepEnergy > 200000. && lepEnergy < 210000.","");
  c1->cd(3);
  Tres_RMS_mu_3->Draw();

  ////////////////////////////////////

  TH1F *Tres_RMS_mu_4 = new TH1F("Tres_RMS_mu_4","",200,0.,200.);
  Tres_RMS_mu_4->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_mu_4->GetYaxis()->SetTitle("entries");
  Tres_RMS_mu_4->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_mu_4->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_mu_4->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_mu_4->GetYaxis()->SetLabelSize(0.047);  
  Tres_RMS_mu_4->SetLineWidth(3);
  Tres_RMS_mu_4->SetLineColor(kGray+3);
  Tres_RMS_mu_4->GetXaxis()->SetRangeUser(40,150);
  Tres_RMS_mu_4->SetTitle("E_{#mu} = 2 TeV");
  mytree->Project("Tres_RMS_mu_4","Tres_RMS","lepEnergy >= 2000000. && lepEnergy < 2100000.","");
  c1->cd(4);
  Tres_RMS_mu_4->Draw();

  c1->SaveAs("Plot/Tres_RMS_mu_EnBins.pdf");
  c1->SaveAs("Plot/Tres_RMS_mu_EnBins.png");
  c1->SaveAs("Plot/Tres_RMS_mu_EnBins.C");

  ////////////////////////////CUMULATIVE////////////////////////////////////////////////////////////////////
  /*
  TCanvas *c2 = new TCanvas("c2","",1600,350);
  c2->Divide(4,1,0.001,0.01);
  TH1F *Tres_RMS_cumul_numuCC_1 = (TH1F*)Tres_RMS_numuCC_1->GetCumulative(kTRUE);
  Tres_RMS_cumul_numuCC_1->SetLineWidth(3);
  Tres_RMS_cumul_numuCC_1->SetLineColor(kGray+3);
  //Tres_RMS_cumul_numuCC_1->GetYaxis()->SetRangeUser(0,1300);
  TH1F *Tres_RMS_cumul_nueCC_1 = (TH1F*)Tres_RMS_nueCC_1->GetCumulative(kTRUE);
  Tres_RMS_cumul_nueCC_1->SetLineWidth(3);
  Tres_RMS_cumul_nueCC_1->SetLineColor(kRed);
  TH1F *Tres_RMS_cumul_nuNC_1 = (TH1F*)Tres_RMS_mu_1->GetCumulative(kTRUE);
  Tres_RMS_cumul_nuNC_1->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_cumul_nuNC_1->GetYaxis()->SetTitle("entries");
  Tres_RMS_cumul_nuNC_1->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_cumul_nuNC_1->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_cumul_nuNC_1->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_nuNC_1->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_nuNC_1->GetXaxis()->SetRangeUser(40,150);
  Tres_RMS_cumul_nuNC_1->SetLineWidth(3);
  Tres_RMS_cumul_nuNC_1->SetLineColor(kGray+3);
  c2->cd(1);
  Tres_RMS_cumul_nuNC_1->Draw();
  Tres_RMS_cumul_nueCC_1->Draw("same");  
  Tres_RMS_cumul_numuCC_1->Draw("same");
  leg21->AddEntry(Tres_RMS_cumul_numuCC_1, "#nu_{#mu} CC" ,"l");
  leg21->AddEntry(Tres_RMS_cumul_nueCC_1, "#nu_{e} CC" ,"l");
  leg21->AddEntry(Tres_RMS_cumul_nuNC_1, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg21->Draw();

  ////////////////////////////////////

  TLegend * leg22 = new TLegend(0.1,0.9,0.4,0.6);
  TH1F *Tres_RMS_cumul_numuCC_2 = (TH1F*)Tres_RMS_mu_2->GetCumulative(kTRUE);
  Tres_RMS_cumul_numuCC_2->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_cumul_numuCC_2->GetYaxis()->SetTitle("entries");
  Tres_RMS_cumul_numuCC_2->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_cumul_numuCC_2->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_cumul_numuCC_2->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_2->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_2->SetLineWidth(3);
  Tres_RMS_cumul_numuCC_2->SetLineColor(kGray+3);
  Tres_RMS_cumul_numuCC_2->GetXaxis()->SetRangeUser(40,150);
  c2->cd(3);
  Tres_RMS_cumul_numuCC_2->Draw();
  leg22->AddEntry(Tres_RMS_cumul_numuCC_2, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_cumul_nueCC_2 = (TH1F*)Tres_RMS_nueCC_2->GetCumulative(kTRUE);
  Tres_RMS_cumul_nueCC_2->SetLineWidth(3);
  Tres_RMS_cumul_nueCC_2->SetLineColor(kRed);
  Tres_RMS_cumul_nueCC_2->Draw("same");
  leg22->AddEntry(Tres_RMS_cumul_nueCC_2, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_cumul_nuNC_2 = (TH1F*)Tres_RMS_nuNC_2->GetCumulative(kTRUE);
  Tres_RMS_cumul_nuNC_2->SetLineWidth(3);
  Tres_RMS_cumul_nuNC_2->SetLineColor(kGray+3);
  Tres_RMS_cumul_nuNC_2->Draw("same");
  leg22->AddEntry(Tres_RMS_cumul_nuNC_2, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg22->Draw();

  ////////////////////////////////////

  TLegend * leg23 = new TLegend(0.1,0.9,0.4,0.6);
  TH1F *Tres_RMS_cumul_numuCC_3 = (TH1F*)Tres_RMS_mu_3->GetCumulative(kTRUE);
  Tres_RMS_cumul_numuCC_3->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_cumul_numuCC_3->GetYaxis()->SetTitle("entries");
  Tres_RMS_cumul_numuCC_3->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_cumul_numuCC_3->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_cumul_numuCC_3->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_3->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_3->SetLineWidth(3);
  Tres_RMS_cumul_numuCC_3->SetLineColor(kGray+3);
  Tres_RMS_cumul_numuCC_3->GetXaxis()->SetRangeUser(40,150);
  c2->cd(3);
  Tres_RMS_cumul_numuCC_3->Draw();
  leg23->AddEntry(Tres_RMS_cumul_numuCC_3, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_cumul_nueCC_3 = (TH1F*)Tres_RMS_nueCC_3->GetCumulative(kTRUE);
  Tres_RMS_cumul_nueCC_3->SetLineWidth(3);
  Tres_RMS_cumul_nueCC_3->SetLineColor(kRed);
  Tres_RMS_cumul_nueCC_3->Draw("same");
  leg23->AddEntry(Tres_RMS_cumul_nueCC_3, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_cumul_nuNC_3 = (TH1F*)Tres_RMS_nuNC_3->GetCumulative(kTRUE);
  Tres_RMS_cumul_nuNC_3->SetLineWidth(3);
  Tres_RMS_cumul_nuNC_3->SetLineColor(kGray+3);
  Tres_RMS_cumul_nuNC_3->Draw("same");
  leg23->AddEntry(Tres_RMS_cumul_nuNC_3, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg23->Draw();

  ////////////////////////////////////

  TLegend * leg24 = new TLegend(0.1,0.9,0.4,0.6);
  TH1F *Tres_RMS_cumul_numuCC_4 = (TH1F*)Tres_RMS_mu_4->GetCumulative(kTRUE);
  Tres_RMS_cumul_numuCC_4->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_cumul_numuCC_4->GetYaxis()->SetTitle("entries");
  Tres_RMS_cumul_numuCC_4->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_cumul_numuCC_4->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_cumul_numuCC_4->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_4->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_4->SetLineWidth(3);
  Tres_RMS_cumul_numuCC_4->SetLineColor(kGray+3);
  Tres_RMS_cumul_numuCC_4->GetXaxis()->SetRangeUser(40,150);
  c2->cd(4);
  Tres_RMS_cumul_numuCC_4->Draw();
  leg24->AddEntry(Tres_RMS_cumul_numuCC_4, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_cumul_nueCC_4 = (TH1F*)Tres_RMS_nueCC_4->GetCumulative(kTRUE);
  Tres_RMS_cumul_nueCC_4->SetLineWidth(3);
  Tres_RMS_cumul_nueCC_4->SetLineColor(kRed);
  Tres_RMS_cumul_nueCC_4->Draw("same");
  leg24->AddEntry(Tres_RMS_cumul_nueCC_4, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_cumul_nuNC_4 = (TH1F*)Tres_RMS_nuNC_4->GetCumulative(kTRUE);
  Tres_RMS_cumul_nuNC_4->SetLineWidth(3);
  Tres_RMS_cumul_nuNC_4->SetLineColor(kGray+3);
  Tres_RMS_cumul_nuNC_4->Draw("same");
  leg24->AddEntry(Tres_RMS_cumul_nuNC_4, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg24->Draw();

  c2->SaveAs("Plot/Tres_RMS_cumul_mu_EnBins.pdf");
  c2->SaveAs("Plot/Tres_RMS_cumul_mu_EnBins.png");
  c2->SaveAs("Plot/Tres_RMS_cumul_mu_EnBins.C");

  ////////////////////////////////////////////////////////////////////////////////////////////////

  TLegend * leg31 = new TLegend(0.62,0.9,0.9,0.55);
  TCanvas *c3 = new TCanvas("c3","",1600,350);
  c3->Divide(4,1,0.001,0.01);
  TH1F *Tres_RMS_revcumul_numuCC_1 = (TH1F*)Tres_RMS_numuCC_1->GetCumulative(kFALSE);
  Tres_RMS_revcumul_numuCC_1->SetLineWidth(3);
  Tres_RMS_revcumul_numuCC_1->SetLineColor(kGray+3);
  TH1F *Tres_RMS_revcumul_nueCC_1 = (TH1F*)Tres_RMS_nueCC_1->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nueCC_1->SetLineWidth(3);
  Tres_RMS_revcumul_nueCC_1->SetLineColor(kRed);
  TH1F *Tres_RMS_revcumul_nuNC_1 = (TH1F*)Tres_RMS_mu_1->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nuNC_1->SetLineWidth(3);
  Tres_RMS_revcumul_nuNC_1->SetLineColor(kGray+3);
  Tres_RMS_revcumul_nuNC_1->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_revcumul_nuNC_1->GetYaxis()->SetTitle("entries");
  Tres_RMS_revcumul_nuNC_1->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_revcumul_nuNC_1->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_revcumul_nuNC_1->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_nuNC_1->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_nuNC_1->GetXaxis()->SetRangeUser(40,150);
  c3->cd(1);
  Tres_RMS_revcumul_nuNC_1->Draw();
  Tres_RMS_revcumul_nueCC_1->Draw("same");
  Tres_RMS_revcumul_numuCC_1->Draw("same");
  leg31->AddEntry(Tres_RMS_revcumul_numuCC_1, "#nu_{#mu} CC" ,"l");
  leg31->AddEntry(Tres_RMS_revcumul_nueCC_1, "#nu_{e} CC" ,"l");
  leg31->AddEntry(Tres_RMS_revcumul_nuNC_1, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg31->Draw();

  ////////////////////////////////////

  TLegend * leg32 = new TLegend(0.62,0.9,0.9,0.55);
  TH1F *Tres_RMS_revcumul_numuCC_2 = (TH1F*)Tres_RMS_mu_2->GetCumulative(kFALSE);
  Tres_RMS_revcumul_numuCC_2->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_revcumul_numuCC_2->GetYaxis()->SetTitle("entries");
  Tres_RMS_revcumul_numuCC_2->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_revcumul_numuCC_2->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_revcumul_numuCC_2->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_2->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_2->SetLineWidth(3);
  Tres_RMS_revcumul_numuCC_2->SetLineColor(kGray+3);
  Tres_RMS_revcumul_numuCC_2->GetXaxis()->SetRangeUser(40,150);
  c3->cd(3);
  Tres_RMS_revcumul_numuCC_2->Draw();
  leg32->AddEntry(Tres_RMS_revcumul_numuCC_2, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_revcumul_nueCC_2 = (TH1F*)Tres_RMS_nueCC_2->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nueCC_2->SetLineWidth(3);
  Tres_RMS_revcumul_nueCC_2->SetLineColor(kRed);
  Tres_RMS_revcumul_nueCC_2->Draw("same");
  leg32->AddEntry(Tres_RMS_revcumul_nueCC_2, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_revcumul_nuNC_2 = (TH1F*)Tres_RMS_nuNC_2->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nuNC_2->SetLineWidth(3);
  Tres_RMS_revcumul_nuNC_2->SetLineColor(kGray+3);
  Tres_RMS_revcumul_nuNC_2->Draw("same");
  leg32->AddEntry(Tres_RMS_revcumul_nuNC_2, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg32->Draw();

  ////////////////////////////////////

  TLegend * leg33 = new TLegend(0.62,0.9,0.9,0.55);
  TH1F *Tres_RMS_revcumul_numuCC_3 = (TH1F*)Tres_RMS_mu_3->GetCumulative(kFALSE);
  Tres_RMS_revcumul_numuCC_3->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_revcumul_numuCC_3->GetYaxis()->SetTitle("entries");
  Tres_RMS_revcumul_numuCC_3->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_revcumul_numuCC_3->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_revcumul_numuCC_3->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_3->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_3->SetLineWidth(3);
  Tres_RMS_revcumul_numuCC_3->SetLineColor(kGray+3);
  Tres_RMS_revcumul_numuCC_3->GetXaxis()->SetRangeUser(40,150);
  c3->cd(3);
  Tres_RMS_revcumul_numuCC_3->Draw();
  leg33->AddEntry(Tres_RMS_revcumul_numuCC_3, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_revcumul_nueCC_3 = (TH1F*)Tres_RMS_nueCC_3->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nueCC_3->SetLineWidth(3);
  Tres_RMS_revcumul_nueCC_3->SetLineColor(kRed);
  Tres_RMS_revcumul_nueCC_3->Draw("same");
  leg33->AddEntry(Tres_RMS_revcumul_nueCC_3, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_revcumul_nuNC_3 = (TH1F*)Tres_RMS_nuNC_3->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nuNC_3->SetLineWidth(3);
  Tres_RMS_revcumul_nuNC_3->SetLineColor(kGray+3);
  Tres_RMS_revcumul_nuNC_3->Draw("same");
  leg33->AddEntry(Tres_RMS_revcumul_nuNC_3, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg33->Draw();

  ////////////////////////////////////

  TLegend * leg34 = new TLegend(0.62,0.9,0.9,0.55);
  TH1F *Tres_RMS_revcumul_numuCC_4 = (TH1F*)Tres_RMS_mu_4->GetCumulative(kFALSE);
  Tres_RMS_revcumul_numuCC_4->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_revcumul_numuCC_4->GetYaxis()->SetTitle("entries");
  Tres_RMS_revcumul_numuCC_4->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_revcumul_numuCC_4->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_revcumul_numuCC_4->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_4->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_4->SetLineWidth(3);
  Tres_RMS_revcumul_numuCC_4->SetLineColor(kGray+3);
  Tres_RMS_revcumul_numuCC_4->GetXaxis()->SetRangeUser(40,150);
  c3->cd(4);
  Tres_RMS_revcumul_numuCC_4->Draw();
  leg34->AddEntry(Tres_RMS_revcumul_numuCC_4, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_revcumul_nueCC_4 = (TH1F*)Tres_RMS_nueCC_4->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nueCC_4->SetLineWidth(3);
  Tres_RMS_revcumul_nueCC_4->SetLineColor(kRed);
  Tres_RMS_revcumul_nueCC_4->Draw("same");
  leg34->AddEntry(Tres_RMS_revcumul_nueCC_4, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_revcumul_nuNC_4 = (TH1F*)Tres_RMS_nuNC_4->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nuNC_4->SetLineWidth(3);
  Tres_RMS_revcumul_nuNC_4->SetLineColor(kGray+3);
  Tres_RMS_revcumul_nuNC_4->Draw("same");
  leg34->AddEntry(Tres_RMS_revcumul_nuNC_4, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg34->Draw();

  c3->SaveAs("Plot/Tres_RMS_revcumul_mu_EnBins.pdf");
  c3->SaveAs("Plot/Tres_RMS_revcumul_mu_EnBins.png");
  c3->SaveAs("Plot/Tres_RMS_revcumul_mu_EnBins.C");
  */
}

