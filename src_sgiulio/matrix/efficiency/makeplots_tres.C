void makeplots_tres() {
  gStyle->SetOptStat(0);
  gStyle->SetPadBottomMargin(0.12);
  gStyle->SetTitleH(0.1);
  gStyle->SetTitleW(1.05);
  //gStyle->SetOptTitle(0);

  TTree *mytree;
  TFile *_file1 = TFile::Open("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker/trees/MC_500K_1m_TOT.root");
  //TFile *_file1 = TFile::Open("/home/sgiulio/Giulio/University/JUNO/juno-unfolding/treemaker/trees/MC_100K_1m_SHORT.root");
  _file1->GetObject("Data",mytree);

  ///////////////////////////////////////////////////////////////////
  /*
  TCanvas *cc = new TCanvas("cc","",900,900);
  cc->cd();
  TH2F *ha = new TH2F("ha","", 45, -180, 180, 44, -89.5, 89.5);
  ha->GetXaxis()->SetTitle("#phi [deg]");
  ha->GetYaxis()->SetTitle("#theta [deg]");  
  mytree->Project("ha","(theta_hitSPMT-90):(phi_hitSPMT-180)","","",1);
  ha->Draw("aitoff");
  ha->SaveAs("Plot/MAP_theta-phi_evt1_SPMT.pdf");
  ha->SaveAs("Plot/MAP_theta-phi_evt1_SPMT.png");
  */
  TCanvas *c80 = new TCanvas("c80","",1200,600);
  TLegend * leg80 = new TLegend(0.65,0.9,0.9,0.6);
  TH1F *Npe_nuNC = new TH1F("Npe_nuNC","",75,0.,3.0E7);
  Npe_nuNC->GetXaxis()->SetTitle("NPE");
  Npe_nuNC->GetXaxis()->SetTitleSize(0.05);
  Npe_nuNC->GetXaxis()->SetLabelSize(0.05);
  Npe_nuNC->GetYaxis()->SetTitle("entries");
  Npe_nuNC->GetYaxis()->SetLabelSize(0.05);
  Npe_nuNC->GetYaxis()->SetTitleOffset(1.2);
  gPad->SetLogy();
  Npe_nuNC->SetLineWidth(5);
  Npe_nuNC->SetLineColor(kSpring-1);
  mytree->Project("Npe_nuNC","trueNPE_LPMT_CD","NCint==1 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  c80->cd();
  Npe_nuNC->Draw();
  TH1F *Npe_nueCC = new TH1F("Npe_nueCC","",75,0.,3.0E7);
  Npe_nueCC->GetXaxis()->SetTitle("NPE");
  gPad->SetLogy();
  Npe_nueCC->SetLineWidth(5);
  Npe_nueCC->SetLineColor(kRed);
  mytree->Project("Npe_nueCC","trueNPE_LPMT_CD","CCint==1 && abs(init_lepID)==11 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  Npe_nueCC->Draw("same");
  TH1F *Npe_numuCC = new TH1F("Npe_numuCC","",75,0., 3.0E7);
  Npe_numuCC->GetXaxis()->SetTitle("NPE");
  Npe_numuCC->SetLineWidth(5);
  Npe_numuCC->SetLineColor(kBlue+2);
  mytree->Project("Npe_numuCC","trueNPE_LPMT_CD","CCint==1 && abs(init_lepID)==13 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  Npe_numuCC->Draw("same");
  leg80->AddEntry(Npe_numuCC, "#nu_{#mu} CC" ,"l");
  leg80->AddEntry(Npe_nueCC, "#nu_{e} CC" ,"l");
  leg80->AddEntry(Npe_nuNC, "#nu_{x} NC" ,"l");
  leg80->Draw();
  c80->SaveAs("Plot/NPE_LPMT_nuall_0-20GeV_16volcut_1m.png");
  c80->SaveAs("Plot/NPE_LPMT_nuall_0-20GeV_16volcut_1m.pdf");
  c80->SaveAs("Plot/NPE_LPMT_nuall_0-20GeV_16volcut_1m.C");

  TCanvas *c81 = new TCanvas("c81","",1200,600);
  TLegend * leg81 = new TLegend(0.65,0.9,0.9,0.6);
  TH1F *Npe_lowE_nuNC = new TH1F("Npe_lowE_nuNC","",75,0.,1.5E6);
  Npe_lowE_nuNC->GetXaxis()->SetTitle("NPE");
  Npe_lowE_nuNC->GetXaxis()->SetTitleSize(0.05);
  Npe_lowE_nuNC->GetXaxis()->SetLabelSize(0.05);
  Npe_lowE_nuNC->GetYaxis()->SetTitle("entries");
  Npe_lowE_nuNC->GetYaxis()->SetLabelSize(0.05);
  Npe_lowE_nuNC->GetYaxis()->SetTitleOffset(1.2);
  gPad->SetLogy();
  Npe_lowE_nuNC->SetLineWidth(5);
  Npe_lowE_nuNC->SetLineColor(kSpring-1);
  mytree->Project("Npe_lowE_nuNC","trueNPE_LPMT_CD","NCint==1 && trueNPE_LPMT_CD<1500.E3 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  c81->cd();
  Npe_lowE_nuNC->Draw();
  TH1F *Npe_lowE_nueCC = new TH1F("Npe_lowE_nueCC","",75,0.,1.5E6);
  Npe_lowE_nueCC->GetXaxis()->SetTitle("NPE");
  gPad->SetLogy();
  Npe_lowE_nueCC->SetLineWidth(5);
  Npe_lowE_nueCC->SetLineColor(kRed);
  mytree->Project("Npe_lowE_nueCC","trueNPE_LPMT_CD","CCint==1 && abs(init_lepID)==11 && trueNPE_LPMT_CD<1500.E3 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  Npe_lowE_nueCC->Draw("same");
  TH1F *Npe_lowE_numuCC = new TH1F("Npe_lowE_numuCC","",75,0.,1.5E6);
  Npe_lowE_numuCC->GetXaxis()->SetTitle("NPE");
  Npe_lowE_numuCC->SetLineWidth(5);
  Npe_lowE_numuCC->SetLineColor(kBlue+2);
  mytree->Project("Npe_lowE_numuCC","trueNPE_LPMT_CD","CCint==1 && abs(init_lepID)==13 && trueNPE_LPMT_CD<1500.E3 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  Npe_lowE_numuCC->Draw("same");
  leg81->AddEntry(Npe_lowE_numuCC, "#nu_{#mu} CC" ,"l");
  leg81->AddEntry(Npe_lowE_nueCC, "#nu_{e} CC" ,"l");
  leg81->AddEntry(Npe_lowE_nuNC, "#nu_{x} NC" ,"l");
  leg81->Draw();
  c81->SaveAs("Plot/NPE_LPMT_nuall_0-20GeV_16volcut_1m_lowE.png");
  c81->SaveAs("Plot/NPE_LPMT_nuall_0-20GeV_16volcut_1m_lowE.pdf");
  c81->SaveAs("Plot/NPE_LPMT_nuall_0-20GeV_16volcut_1m_lowE.C");

  ////////////////////////////////TRES/////////////////////////////////////////////////  

  TLegend * leg11 = new TLegend(0.65,0.87,0.87,0.5);
  leg11->SetBorderSize(0);
  TCanvas *c1 = new TCanvas("c1","",1200,1000);
  c1->Divide(2,2,0.00000001,0.01);
  TH1F *Tres_RMS_numuCC_1 = new TH1F("Tres_RMS_numuCC_1","",200,0.,200.);
  Tres_RMS_numuCC_1->SetLineWidth(3);
  Tres_RMS_numuCC_1->SetLineColor(kBlue+2);
  //Tres_RMS_numuCC_1->GetYaxis()->SetRangeUser(0,110);
  mytree->Project("Tres_RMS_numuCC_1","Tres_RMS","CCint==1 && abs(init_lepID)==13 && trueNPE_LPMT_CD>1.E5 && trueNPE_LPMT_CD<471520. && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  TH1F *Tres_RMS_nueCC_1 = new TH1F("Tres_RMS_nueCC_1","",200,0.,200.);
  Tres_RMS_nueCC_1->SetLineWidth(3);
  Tres_RMS_nueCC_1->SetLineColor(kRed);
  mytree->Project("Tres_RMS_nueCC_1","Tres_RMS","CCint==1 && abs(init_lepID)==11 && trueNPE_LPMT_CD>1.E5 && trueNPE_LPMT_CD<471520. && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  TH1F *Tres_RMS_nuNC_1 = new TH1F("Tres_RMS_nuNC_1","",200,0.,200.);
  Tres_RMS_nuNC_1->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_nuNC_1->GetYaxis()->SetTitle("entries");
  Tres_RMS_nuNC_1->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_nuNC_1->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_nuNC_1->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_nuNC_1->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_nuNC_1->GetXaxis()->SetRangeUser(40,150);
  Tres_RMS_nuNC_1->GetXaxis()->SetLabelSize(0.06);
  Tres_RMS_nuNC_1->SetLineWidth(3);
  Tres_RMS_nuNC_1->SetLineColor(kSpring-1);
  Tres_RMS_nuNC_1->SetTitle("10^{5} < NPE < 4.73 #times 10^{5}");
  mytree->Project("Tres_RMS_nuNC_1","Tres_RMS","NCint==1 && trueNPE_LPMT_CD>1.E5 && trueNPE_LPMT_CD<471520. && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  c1->cd(1);
  Tres_RMS_nuNC_1->Draw();
  Tres_RMS_numuCC_1->Draw("same");
  Tres_RMS_nueCC_1->Draw("same");
  leg11->AddEntry(Tres_RMS_numuCC_1, "#nu_{#mu} CC" ,"l");
  leg11->AddEntry(Tres_RMS_nueCC_1, "#nu_{e} CC" ,"l");
  leg11->AddEntry(Tres_RMS_nuNC_1, "#nu_{x} NC" ,"l");
  leg11->Draw();

  ////////////////////////////////////

  TLegend * leg12 = new TLegend(0.65,0.87,0.87,0.5);
  leg12->SetBorderSize(0);
  TH1F *Tres_RMS_numuCC_2 = new TH1F("Tres_RMS_numuCC_2","",200,0.,200.);
  Tres_RMS_numuCC_2->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_numuCC_2->GetYaxis()->SetTitle("entries");
  Tres_RMS_numuCC_2->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_numuCC_2->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_numuCC_2->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_numuCC_2->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_numuCC_2->GetXaxis()->SetRangeUser(40,150);
  Tres_RMS_numuCC_2->GetXaxis()->SetLabelSize(0.06);
  Tres_RMS_numuCC_2->SetLineWidth(3);
  Tres_RMS_numuCC_2->SetLineColor(kBlue+2);
  Tres_RMS_numuCC_2->SetTitle("4.73 #times 10^{5} < NPE < 1.01 #times 10^{6}");
  mytree->Project("Tres_RMS_numuCC_2","Tres_RMS","CCint==1 && abs(init_lepID)==13 && trueNPE_LPMT_CD>=471520. && trueNPE_LPMT_CD<1.00221E6 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  c1->cd(2);
  Tres_RMS_numuCC_2->Draw();
  leg12->AddEntry(Tres_RMS_numuCC_2, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_nueCC_2 = new TH1F("Tres_RMS_nueCC_2","",200,0.,200.);
  Tres_RMS_nueCC_2->SetLineWidth(3);
  Tres_RMS_nueCC_2->SetLineColor(kRed);
  mytree->Project("Tres_RMS_nueCC_2","Tres_RMS","CCint==1 && abs(init_lepID)==11 && trueNPE_LPMT_CD>=471520. && trueNPE_LPMT_CD<1.00221E6 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  Tres_RMS_nueCC_2->Draw("same");
  leg12->AddEntry(Tres_RMS_nueCC_2, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_nuNC_2 = new TH1F("Tres_RMS_nuNC_2","",200,0.,200.);
  Tres_RMS_nuNC_2->SetLineWidth(3);
  Tres_RMS_nuNC_2->SetLineColor(kSpring-1);
  mytree->Project("Tres_RMS_nuNC_2","Tres_RMS","NCint==1 && trueNPE_LPMT_CD>=471520. && trueNPE_LPMT_CD<1.00221E6 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  Tres_RMS_nuNC_2->Draw("same");
  leg12->AddEntry(Tres_RMS_nuNC_2, "#nu_{x} NC" ,"l");
  leg12->Draw();

  ////////////////////////////////////

  TLegend * leg13 = new TLegend(0.65,0.87,0.87,0.5);
  leg13->SetBorderSize(0);
  TH1F *Tres_RMS_numuCC_3 = new TH1F("Tres_RMS_numuCC_3","",200,0.,200.);
  Tres_RMS_numuCC_3->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_numuCC_3->GetYaxis()->SetTitle("entries");
  Tres_RMS_numuCC_3->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_numuCC_3->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_numuCC_3->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_numuCC_3->GetYaxis()->SetLabelSize(0.047);  
  Tres_RMS_numuCC_3->SetLineWidth(3);
  Tres_RMS_numuCC_3->SetLineColor(kBlue+2);
  Tres_RMS_numuCC_3->GetXaxis()->SetRangeUser(40,150);
  Tres_RMS_numuCC_3->GetXaxis()->SetLabelSize(0.06);
  Tres_RMS_numuCC_3->SetTitle("1.01 #times 10^{6} < NPE < 2.32 #times 10^{6}");
  mytree->Project("Tres_RMS_numuCC_3","Tres_RMS","CCint==1 && abs(init_lepID)==13 && trueNPE_LPMT_CD>=1.00221E6 && trueNPE_LPMT_CD<2.21877E6 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  c1->cd(3);
  Tres_RMS_numuCC_3->Draw();
  leg13->AddEntry(Tres_RMS_numuCC_3, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_nueCC_3 = new TH1F("Tres_RMS_nueCC_3","",200,0.,200.);
  Tres_RMS_nueCC_3->SetLineWidth(3);
  Tres_RMS_nueCC_3->SetLineColor(kRed);
  mytree->Project("Tres_RMS_nueCC_3","Tres_RMS","CCint==1 && abs(init_lepID)==11 && trueNPE_LPMT_CD>=1.00221E6 && trueNPE_LPMT_CD<2.21877E6 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  Tres_RMS_nueCC_3->Draw("same");
  leg13->AddEntry(Tres_RMS_nueCC_3, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_nuNC_3 = new TH1F("Tres_RMS_nuNC_3","",200,0.,200.);
  Tres_RMS_nuNC_3->SetLineWidth(3);
  Tres_RMS_nuNC_3->SetLineColor(kSpring-1);
  mytree->Project("Tres_RMS_nuNC_3","Tres_RMS","NCint==1 && trueNPE_LPMT_CD>=1.00221E6 && trueNPE_LPMT_CD<2.21877E6 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  Tres_RMS_nuNC_3->Draw("same");
  leg13->AddEntry(Tres_RMS_nuNC_3, "#nu_{x} NC" ,"l");
  leg13->Draw();

  ////////////////////////////////////

  TLegend * leg14 = new TLegend(0.65,0.87,0.87,0.5);
  leg14->SetBorderSize(0);
  TH1F *Tres_RMS_numuCC_4 = new TH1F("Tres_RMS_numuCC_4","",200,0.,200.);
  Tres_RMS_numuCC_4->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_numuCC_4->GetYaxis()->SetTitle("entries");
  Tres_RMS_numuCC_4->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_numuCC_4->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_numuCC_4->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_numuCC_4->GetYaxis()->SetLabelSize(0.047);  
  Tres_RMS_numuCC_4->SetLineWidth(3);
  Tres_RMS_numuCC_4->SetLineColor(kBlue+2);
  Tres_RMS_numuCC_4->GetXaxis()->SetRangeUser(40,150);
  Tres_RMS_numuCC_4->GetXaxis()->SetLabelSize(0.06);
  Tres_RMS_numuCC_4->SetTitle("NPE > 2.32 #times 10^{6}");
  mytree->Project("Tres_RMS_numuCC_4","Tres_RMS","CCint==1 && abs(init_lepID)==13 && trueNPE_LPMT_CD>=2.21877E6 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  c1->cd(4);
  Tres_RMS_numuCC_4->Draw();
  leg14->AddEntry(Tres_RMS_numuCC_4, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_nueCC_4 = new TH1F("Tres_RMS_nueCC_4","",200,0.,200.);
  Tres_RMS_nueCC_4->SetLineWidth(3);
  Tres_RMS_nueCC_4->SetLineColor(kRed);
  mytree->Project("Tres_RMS_nueCC_4","Tres_RMS","CCint==1 && abs(init_lepID)==11 && trueNPE_LPMT_CD>=2.21877E6 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  Tres_RMS_nueCC_4->Draw("same");
  leg14->AddEntry(Tres_RMS_nueCC_4, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_nuNC_4 = new TH1F("Tres_RMS_nuNC_4","",200,0.,200.);
  Tres_RMS_nuNC_4->SetLineWidth(3);
  Tres_RMS_nuNC_4->SetLineColor(kSpring-1);
  mytree->Project("Tres_RMS_nuNC_4","Tres_RMS","NCint==1 && trueNPE_LPMT_CD>=2.21877E6 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  Tres_RMS_nuNC_4->Draw("same");
  leg14->AddEntry(Tres_RMS_nuNC_4, "#nu_{x} NC" ,"l");
  leg14->Draw();

  c1->SaveAs("Plot/Tres_RMS_nuall_0-20GeV_16volcut_1m_EnBins.pdf");
  c1->SaveAs("Plot/Tres_RMS_nuall_0-20GeV_16volcut_1m_EnBins.png");
  c1->SaveAs("Plot/Tres_RMS_nuall_0-20GeV_16volcut_1m_EnBins.C");
  c1->SaveAs("Plot/Tres_RMS_nuall_0-20GeV_16volcut_1m_EnBins.root");

  ////////////////////////////CUMULATIVE////////////////////////////////////////////////////////////////////

  TLegend * leg21 = new TLegend(0.1,0.9,0.4,0.6);
  TCanvas *c2 = new TCanvas("c2","",1600,350);
  c2->Divide(4,1,0.001,0.01);
  TH1F *Tres_RMS_cumul_numuCC_1 = (TH1F*)Tres_RMS_numuCC_1->GetCumulative(kTRUE);
  Tres_RMS_cumul_numuCC_1->SetLineWidth(3);
  Tres_RMS_cumul_numuCC_1->SetLineColor(kBlue+2);
  //Tres_RMS_cumul_numuCC_1->GetYaxis()->SetRangeUser(0,1300);
  TH1F *Tres_RMS_cumul_nueCC_1 = (TH1F*)Tres_RMS_nueCC_1->GetCumulative(kTRUE);
  Tres_RMS_cumul_nueCC_1->SetLineWidth(3);
  Tres_RMS_cumul_nueCC_1->SetLineColor(kRed);
  TH1F *Tres_RMS_cumul_nuNC_1 = (TH1F*)Tres_RMS_nuNC_1->GetCumulative(kTRUE);
  Tres_RMS_cumul_nuNC_1->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_cumul_nuNC_1->GetYaxis()->SetTitle("entries");
  Tres_RMS_cumul_nuNC_1->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_cumul_nuNC_1->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_cumul_nuNC_1->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_nuNC_1->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_nuNC_1->GetXaxis()->SetRangeUser(40,150);
  Tres_RMS_cumul_nuNC_1->SetLineWidth(3);
  Tres_RMS_cumul_nuNC_1->SetLineColor(kSpring-1);
  c2->cd(1);
  Tres_RMS_cumul_nuNC_1->Draw();
  Tres_RMS_cumul_nueCC_1->Draw("same");  
  Tres_RMS_cumul_numuCC_1->Draw("same");
  leg21->AddEntry(Tres_RMS_cumul_numuCC_1, "#nu_{#mu} CC" ,"l");
  leg21->AddEntry(Tres_RMS_cumul_nueCC_1, "#nu_{e} CC" ,"l");
  leg21->AddEntry(Tres_RMS_cumul_nuNC_1, "#nu_{x} NC" ,"l");
  leg21->Draw();

  ////////////////////////////////////

  TLegend * leg22 = new TLegend(0.1,0.9,0.4,0.6);
  TH1F *Tres_RMS_cumul_numuCC_2 = (TH1F*)Tres_RMS_numuCC_2->GetCumulative(kTRUE);
  Tres_RMS_cumul_numuCC_2->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_cumul_numuCC_2->GetYaxis()->SetTitle("entries");
  Tres_RMS_cumul_numuCC_2->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_cumul_numuCC_2->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_cumul_numuCC_2->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_2->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_2->SetLineWidth(3);
  Tres_RMS_cumul_numuCC_2->SetLineColor(kBlue+2);
  Tres_RMS_cumul_numuCC_2->GetXaxis()->SetRangeUser(40,150);
  c2->cd(2);
  Tres_RMS_cumul_numuCC_2->Draw();
  leg22->AddEntry(Tres_RMS_cumul_numuCC_2, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_cumul_nueCC_2 = (TH1F*)Tres_RMS_nueCC_2->GetCumulative(kTRUE);
  Tres_RMS_cumul_nueCC_2->SetLineWidth(3);
  Tres_RMS_cumul_nueCC_2->SetLineColor(kRed);
  Tres_RMS_cumul_nueCC_2->Draw("same");
  leg22->AddEntry(Tres_RMS_cumul_nueCC_2, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_cumul_nuNC_2 = (TH1F*)Tres_RMS_nuNC_2->GetCumulative(kTRUE);
  Tres_RMS_cumul_nuNC_2->SetLineWidth(3);
  Tres_RMS_cumul_nuNC_2->SetLineColor(kSpring-1);
  Tres_RMS_cumul_nuNC_2->Draw("same");
  leg22->AddEntry(Tres_RMS_cumul_nuNC_2, "#nu_{x} NC" ,"l");
  leg22->Draw();

  ////////////////////////////////////

  TLegend * leg23 = new TLegend(0.1,0.9,0.4,0.6);
  TH1F *Tres_RMS_cumul_numuCC_3 = (TH1F*)Tres_RMS_numuCC_3->GetCumulative(kTRUE);
  Tres_RMS_cumul_numuCC_3->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_cumul_numuCC_3->GetYaxis()->SetTitle("entries");
  Tres_RMS_cumul_numuCC_3->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_cumul_numuCC_3->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_cumul_numuCC_3->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_3->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_3->SetLineWidth(3);
  Tres_RMS_cumul_numuCC_3->SetLineColor(kBlue+2);
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
  Tres_RMS_cumul_nuNC_3->SetLineColor(kSpring-1);
  Tres_RMS_cumul_nuNC_3->Draw("same");
  leg23->AddEntry(Tres_RMS_cumul_nuNC_3, "#nu_{x} NC" ,"l");
  leg23->Draw();

  ////////////////////////////////////

  TLegend * leg24 = new TLegend(0.1,0.9,0.4,0.6);
  TH1F *Tres_RMS_cumul_numuCC_4 = (TH1F*)Tres_RMS_numuCC_4->GetCumulative(kTRUE);
  Tres_RMS_cumul_numuCC_4->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_cumul_numuCC_4->GetYaxis()->SetTitle("entries");
  Tres_RMS_cumul_numuCC_4->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_cumul_numuCC_4->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_cumul_numuCC_4->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_4->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_4->SetLineWidth(3);
  Tres_RMS_cumul_numuCC_4->SetLineColor(kBlue+2);
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
  Tres_RMS_cumul_nuNC_4->SetLineColor(kSpring-1);
  Tres_RMS_cumul_nuNC_4->Draw("same");
  leg24->AddEntry(Tres_RMS_cumul_nuNC_4, "#nu_{x} NC" ,"l");
  leg24->Draw();

  c2->SaveAs("Plot/Tres_RMS_cumul_nuall_0-20GeV_16volcut_1m_EnBins.pdf");
  c2->SaveAs("Plot/Tres_RMS_cumul_nuall_0-20GeV_16volcut_1m_EnBins.png");
  c2->SaveAs("Plot/Tres_RMS_cumul_nuall_0-20GeV_16volcut_1m_EnBins.C");
  c2->SaveAs("Plot/Tres_RMS_cumul_nuall_0-20GeV_16volcut_1m_EnBins.root");

  ////////////////////////////////////////////////////////////////////////////////////////////////

  TLegend * leg31 = new TLegend(0.65,0.87,0.87,0.5);
  TCanvas *c3 = new TCanvas("c3","",1600,350);
  c3->Divide(4,1,0.001,0.01);
  TH1F *Tres_RMS_revcumul_numuCC_1 = (TH1F*)Tres_RMS_numuCC_1->GetCumulative(kFALSE);
  Tres_RMS_revcumul_numuCC_1->SetLineWidth(3);
  Tres_RMS_revcumul_numuCC_1->SetLineColor(kBlue+2);
  TH1F *Tres_RMS_revcumul_nueCC_1 = (TH1F*)Tres_RMS_nueCC_1->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nueCC_1->SetLineWidth(3);
  Tres_RMS_revcumul_nueCC_1->SetLineColor(kRed);
  TH1F *Tres_RMS_revcumul_nuNC_1 = (TH1F*)Tres_RMS_nuNC_1->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nuNC_1->SetLineWidth(3);
  Tres_RMS_revcumul_nuNC_1->SetLineColor(kSpring-1);
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
  leg31->AddEntry(Tres_RMS_revcumul_nuNC_1, "#nu_{x} NC" ,"l");
  leg31->Draw();

  ////////////////////////////////////

  TLegend * leg32 = new TLegend(0.65,0.87,0.87,0.5);
  TH1F *Tres_RMS_revcumul_numuCC_2 = (TH1F*)Tres_RMS_numuCC_2->GetCumulative(kFALSE);
  Tres_RMS_revcumul_numuCC_2->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_revcumul_numuCC_2->GetYaxis()->SetTitle("entries");
  Tres_RMS_revcumul_numuCC_2->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_revcumul_numuCC_2->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_revcumul_numuCC_2->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_2->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_2->SetLineWidth(3);
  Tres_RMS_revcumul_numuCC_2->SetLineColor(kBlue+2);
  Tres_RMS_revcumul_numuCC_2->GetXaxis()->SetRangeUser(40,150);
  c3->cd(2);
  Tres_RMS_revcumul_numuCC_2->Draw();
  leg32->AddEntry(Tres_RMS_revcumul_numuCC_2, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_revcumul_nueCC_2 = (TH1F*)Tres_RMS_nueCC_2->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nueCC_2->SetLineWidth(3);
  Tres_RMS_revcumul_nueCC_2->SetLineColor(kRed);
  Tres_RMS_revcumul_nueCC_2->Draw("same");
  leg32->AddEntry(Tres_RMS_revcumul_nueCC_2, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_revcumul_nuNC_2 = (TH1F*)Tres_RMS_nuNC_2->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nuNC_2->SetLineWidth(3);
  Tres_RMS_revcumul_nuNC_2->SetLineColor(kSpring-1);
  Tres_RMS_revcumul_nuNC_2->Draw("same");
  leg32->AddEntry(Tres_RMS_revcumul_nuNC_2, "#nu_{x} NC" ,"l");
  leg32->Draw();

  ////////////////////////////////////

  TLegend * leg33 = new TLegend(0.65,0.87,0.87,0.5);
  TH1F *Tres_RMS_revcumul_numuCC_3 = (TH1F*)Tres_RMS_numuCC_3->GetCumulative(kFALSE);
  Tres_RMS_revcumul_numuCC_3->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_revcumul_numuCC_3->GetYaxis()->SetTitle("entries");
  Tres_RMS_revcumul_numuCC_3->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_revcumul_numuCC_3->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_revcumul_numuCC_3->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_3->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_3->SetLineWidth(3);
  Tres_RMS_revcumul_numuCC_3->SetLineColor(kBlue+2);
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
  Tres_RMS_revcumul_nuNC_3->SetLineColor(kSpring-1);
  Tres_RMS_revcumul_nuNC_3->Draw("same");
  leg33->AddEntry(Tres_RMS_revcumul_nuNC_3, "#nu_{x} NC" ,"l");
  leg33->Draw();

  ////////////////////////////////////

  TLegend * leg34 = new TLegend(0.65,0.87,0.87,0.5);
  TH1F *Tres_RMS_revcumul_numuCC_4 = (TH1F*)Tres_RMS_numuCC_4->GetCumulative(kFALSE);
  Tres_RMS_revcumul_numuCC_4->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_revcumul_numuCC_4->GetYaxis()->SetTitle("entries");
  Tres_RMS_revcumul_numuCC_4->GetYaxis()->SetTitleOffset(1.5);
  Tres_RMS_revcumul_numuCC_4->GetXaxis()->SetTitleSize(0.055);
  Tres_RMS_revcumul_numuCC_4->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_4->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_4->SetLineWidth(3);
  Tres_RMS_revcumul_numuCC_4->SetLineColor(kBlue+2);
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
  Tres_RMS_revcumul_nuNC_4->SetLineColor(kSpring-1);
  Tres_RMS_revcumul_nuNC_4->Draw("same");
  leg34->AddEntry(Tres_RMS_revcumul_nuNC_4, "#nu_{x} NC" ,"l");
  leg34->Draw();

  c3->SaveAs("Plot/Tres_RMS_revcumul_nuall_0-20GeV_16volcut_1m_EnBins.pdf");
  c3->SaveAs("Plot/Tres_RMS_revcumul_nuall_0-20GeV_16volcut_1m_EnBins.png");
  c3->SaveAs("Plot/Tres_RMS_revcumul_nuall_0-20GeV_16volcut_1m_EnBins.C");
  c3->SaveAs("Plot/Tres_RMS_revcumul_nuall_0-20GeV_16volcut_1m_EnBins.root");

}

