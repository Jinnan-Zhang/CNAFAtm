void makeplots_nu_all_cumulative() {
  gStyle->SetOptStat(0);
  //gStyle->SetOptTitle(0);

  TTree *mytree;
  TFile *_file1 = TFile::Open("Plot/TRUEnuall_0-10GeV_red_1m.root");
  _file1->GetObject("Data",mytree);

  ///////////////////////////////////////////////////////////////////

  TCanvas *cc = new TCanvas("cc","",900,900);
  cc->cd();
  TH2F *ha = new TH2F("ha","", 45, -180, 180, 44, -89.5, 89.5);
  ha->GetXaxis()->SetTitle("#phi [deg]");
  ha->GetYaxis()->SetTitle("#theta [deg]");  
  mytree->Project("ha","(theta_hitSPMT-90):(phi_hitSPMT-180)","","",1);
  ha->Draw("aitoff");
  ha->SaveAs("Plot/MAP_theta-phi_evt1_SPMT.pdf");
  ha->SaveAs("Plot/MAP_theta-phi_evt1_SPMT.png");

  TCanvas *c80 = new TCanvas("c80","",1600,1200);
  TLegend * leg80 = new TLegend(0.2,0.9,0.45,0.65);
  TH1F *Npe_nuNC = new TH1F("Npe_nuNC","",200,0.,1.4E7);
  Npe_nuNC->GetXaxis()->SetTitle("N_{PE}");
  Npe_nuNC->GetXaxis()->SetTitleSize(0.045);
  Npe_nuNC->GetYaxis()->SetTitle("entries");
  gPad->SetLogy();
  Npe_nuNC->SetLineWidth(5);
  Npe_nuNC->SetLineColor(kSpring-1);
  mytree->Project("Npe_nuNC","trueNPE","NCint==1 && newVradius<16000","");
  c80->cd();
  Npe_nuNC->Draw();
  leg80->AddEntry(Npe_nuNC, "#nu_{e}+#nu_{#mu} NC" ,"l");
  TH1F *Npe_nueCC = new TH1F("Npe_nueCC","",200,0.,1.4E7);
  Npe_nueCC->GetXaxis()->SetTitle("N_{PE}");
  gPad->SetLogy();
  Npe_nueCC->SetLineWidth(5);
  Npe_nueCC->SetLineColor(kRed);
  mytree->Project("Npe_nueCC","trueNPE","CCint==1 && abs(init_lepID)==11 && newVradius<16000","");
  Npe_nueCC->Draw("same");
  leg80->AddEntry(Npe_nueCC, "#nu_{e} CC" ,"l");
  TH1F *Npe_numuCC = new TH1F("Npe_numuCC","",200,0., 1.4E7);
  Npe_numuCC->GetXaxis()->SetTitle("N_{PE}");
  Npe_numuCC->SetLineWidth(5);
  Npe_numuCC->SetLineColor(kBlue+2);
  mytree->Project("Npe_numuCC","trueNPE","CCint==1 && abs(init_lepID)==13 && newVradius<16000","");
  Npe_numuCC->Draw("same");
  leg80->AddEntry(Npe_numuCC, "#nu_{#mu} CC" ,"l");
  leg80->Draw();
  c80->SaveAs("Plot/NPE_LPMT_nuall_CC+NC_0-10GeV_16volcut_1m_ALL.png");
  c80->SaveAs("Plot/NPE_LPMT_nuall_CC+NC_0-10GeV_16volcut_1m_ALL.pdf");
  c80->SaveAs("Plot/NPE_LPMT_nuall_CC+NC_0-10GeV_16volcut_1m_ALL.C");

  TCanvas *c81 = new TCanvas("c81","",1600,1200);
  TH1F *Npe_lowE_nuNC = new TH1F("Npe_lowE_nuNC","",200,0.,1.5E6);
  Npe_lowE_nuNC->GetXaxis()->SetTitle("N_{PE}");
  Npe_lowE_nuNC->GetXaxis()->SetTitleSize(0.045);
  Npe_lowE_nuNC->GetYaxis()->SetTitle("entries");
  gPad->SetLogy();
  Npe_lowE_nuNC->SetLineWidth(5);
  Npe_lowE_nuNC->SetLineColor(kSpring-1);
  mytree->Project("Npe_lowE_nuNC","trueNPE","NCint==1 && trueNPE<1500.E3 && newVradius<16000","");
  c81->cd();
  Npe_lowE_nuNC->Draw();
  TH1F *Npe_lowE_nueCC = new TH1F("Npe_lowE_nueCC","",200,0.,1.5E6);
  Npe_lowE_nueCC->GetXaxis()->SetTitle("N_{PE}");
  gPad->SetLogy();
  Npe_lowE_nueCC->SetLineWidth(5);
  Npe_lowE_nueCC->SetLineColor(kRed);
  mytree->Project("Npe_lowE_nueCC","trueNPE","CCint==1 && abs(init_lepID)==11 && trueNPE<1500.E3 && newVradius<16000","");
  Npe_lowE_nueCC->Draw("same");
  TH1F *Npe_lowE_numuCC = new TH1F("Npe_lowE_numuCC","",200,0.,1.5E6);
  Npe_lowE_numuCC->GetXaxis()->SetTitle("N_{PE}");
  Npe_lowE_numuCC->SetLineWidth(5);
  Npe_lowE_numuCC->SetLineColor(kBlue+2);
  mytree->Project("Npe_lowE_numuCC","trueNPE","CCint==1 && abs(init_lepID)==13 && trueNPE<1500.E3 && newVradius<16000","");
  Npe_lowE_numuCC->Draw("same");
  c81->SaveAs("Plot/NPE_LPMT_nuall_CC+NC_0-10GeV_16volcut_1m_All_lowE.png");
  c81->SaveAs("Plot/NPE_LPMT_nuall_CC+NC_0-10GeV_16volcut_1m_All_lowE.pdf");
  c81->SaveAs("Plot/NPE_LPMT_nuall_CC+NC_0-10GeV_16volcut_1m_All_lowE.C");
  
  TLegend * leg11 = new TLegend(0.62,0.9,0.9,0.55);
  TCanvas *c1 = new TCanvas("c1","",1600,900);
  c1->Divide(2,2);
  TH1F *Tres_RMS_numuCC_1 = new TH1F("Tres_RMS_numuCC_1","",250,0., 200.);
  Tres_RMS_numuCC_1->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_numuCC_1->GetYaxis()->SetTitle("entries");
  Tres_RMS_numuCC_1->GetYaxis()->SetTitleOffset(1.3);
  Tres_RMS_numuCC_1->GetXaxis()->SetTitleSize(0.047);
  Tres_RMS_numuCC_1->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_numuCC_1->GetYaxis()->SetLabelSize(0.047);  
  Tres_RMS_numuCC_1->SetLineWidth(4);
  Tres_RMS_numuCC_1->SetLineColor(kBlue+2);
  Tres_RMS_numuCC_1->GetXaxis()->SetRangeUser(40,150);
  Tres_RMS_numuCC_1->GetYaxis()->SetRangeUser(0,110);
  Tres_RMS_numuCC_1->SetTitle("10^{5} < N_{PE} < 4.72 #times 10^{5}");
  mytree->Project("Tres_RMS_numuCC_1","Tres_RMS","CCint==1 && abs(init_lepID)==13 && trueNPE>1.E5 && trueNPE<471520. && newVradius<16000","");
  c1->cd(1);
  Tres_RMS_numuCC_1->Draw();
  leg11->AddEntry(Tres_RMS_numuCC_1, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_nueCC_1 = new TH1F("Tres_RMS_nueCC_1","",250,0., 200.);
  Tres_RMS_nueCC_1->SetLineWidth(4);
  Tres_RMS_nueCC_1->SetLineColor(kRed);
  mytree->Project("Tres_RMS_nueCC_1","Tres_RMS","CCint==1 && abs(init_lepID)==11 && trueNPE>1.E5 && trueNPE<471520. && newVradius<16000","");
  Tres_RMS_nueCC_1->Draw("same");
  leg11->AddEntry(Tres_RMS_nueCC_1, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_nuNC_1 = new TH1F("Tres_RMS_nuNC_1","",250,0., 200.);
  Tres_RMS_nuNC_1->SetLineWidth(4);
  Tres_RMS_nuNC_1->SetLineColor(kSpring-1);
  mytree->Project("Tres_RMS_nuNC_1","Tres_RMS","NCint==1 && trueNPE>1.E5 && trueNPE<471520. && newVradius<16000","");
  Tres_RMS_nuNC_1->Draw("same");
  leg11->AddEntry(Tres_RMS_nuNC_1, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg11->Draw();

  ////////////////////////////////////

  TLegend * leg12 = new TLegend(0.62,0.9,0.9,0.55);
  TH1F *Tres_RMS_numuCC_2 = new TH1F("Tres_RMS_numuCC_2","",250,0., 200.);
  Tres_RMS_numuCC_2->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_numuCC_2->GetYaxis()->SetTitle("entries");
  Tres_RMS_numuCC_2->GetYaxis()->SetTitleOffset(1.3);
  Tres_RMS_numuCC_2->GetXaxis()->SetTitleSize(0.047);
  Tres_RMS_numuCC_2->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_numuCC_2->GetYaxis()->SetLabelSize(0.047);  
  Tres_RMS_numuCC_2->SetLineWidth(4);
  Tres_RMS_numuCC_2->SetLineColor(kBlue+2);
  Tres_RMS_numuCC_2->GetXaxis()->SetRangeUser(40,150);
  Tres_RMS_numuCC_2->SetTitle("4.72 #times 10^{5} < N_{PE} < 1.01 #times 10^{6}");
  mytree->Project("Tres_RMS_numuCC_2","Tres_RMS","CCint==1 && abs(init_lepID)==13 && trueNPE>=471520. && trueNPE<1.00221E6 && newVradius<16000","");
  c1->cd(2);
  Tres_RMS_numuCC_2->Draw();
  leg12->AddEntry(Tres_RMS_numuCC_2, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_nueCC_2 = new TH1F("Tres_RMS_nueCC_2","",250,0., 200.);
  Tres_RMS_nueCC_2->SetLineWidth(4);
  Tres_RMS_nueCC_2->SetLineColor(kRed);
  mytree->Project("Tres_RMS_nueCC_2","Tres_RMS","CCint==1 && abs(init_lepID)==11 && trueNPE>=471520. && trueNPE<1.00221E6 && newVradius<16000","");
  Tres_RMS_nueCC_2->Draw("same");
  leg12->AddEntry(Tres_RMS_nueCC_2, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_nuNC_2 = new TH1F("Tres_RMS_nuNC_2","",250,0., 200.);
  Tres_RMS_nuNC_2->SetLineWidth(4);
  Tres_RMS_nuNC_2->SetLineColor(kSpring-1);
  mytree->Project("Tres_RMS_nuNC_2","Tres_RMS","NCint==1 && trueNPE>=471520. && trueNPE<1.00221E6 && newVradius<16000","");
  Tres_RMS_nuNC_2->Draw("same");
  leg12->AddEntry(Tres_RMS_nuNC_2, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg12->Draw();

  ////////////////////////////////////

  TLegend * leg13 = new TLegend(0.62,0.9,0.9,0.55);
  TH1F *Tres_RMS_numuCC_3 = new TH1F("Tres_RMS_numuCC_3","",250,0., 200.);
  Tres_RMS_numuCC_3->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_numuCC_3->GetYaxis()->SetTitle("entries");
  Tres_RMS_numuCC_3->GetYaxis()->SetTitleOffset(1.3);
  Tres_RMS_numuCC_3->GetXaxis()->SetTitleSize(0.047);
  Tres_RMS_numuCC_3->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_numuCC_3->GetYaxis()->SetLabelSize(0.047);  
  Tres_RMS_numuCC_3->SetLineWidth(4);
  Tres_RMS_numuCC_3->SetLineColor(kBlue+2);
  Tres_RMS_numuCC_3->GetXaxis()->SetRangeUser(40,150);
  Tres_RMS_numuCC_3->SetTitle("1.01 #times 10^{6} < N_{PE} < 2.22 #times 10^{6}");
  mytree->Project("Tres_RMS_numuCC_3","Tres_RMS","CCint==1 && abs(init_lepID)==13 && trueNPE>=1.00221E6 && trueNPE<2.21877E6 && newVradius<16000","");
  c1->cd(3);
  Tres_RMS_numuCC_3->Draw();
  leg13->AddEntry(Tres_RMS_numuCC_3, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_nueCC_3 = new TH1F("Tres_RMS_nueCC_3","",250,0., 200.);
  Tres_RMS_nueCC_3->SetLineWidth(4);
  Tres_RMS_nueCC_3->SetLineColor(kRed);
  mytree->Project("Tres_RMS_nueCC_3","Tres_RMS","CCint==1 && abs(init_lepID)==11 && trueNPE>=1.00221E6 && trueNPE<2.21877E6 && newVradius<16000","");
  Tres_RMS_nueCC_3->Draw("same");
  leg13->AddEntry(Tres_RMS_nueCC_3, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_nuNC_3 = new TH1F("Tres_RMS_nuNC_3","",250,0., 200.);
  Tres_RMS_nuNC_3->SetLineWidth(4);
  Tres_RMS_nuNC_3->SetLineColor(kSpring-1);
  mytree->Project("Tres_RMS_nuNC_3","Tres_RMS","NCint==1 && trueNPE>=1.00221E6 && trueNPE<2.21877E6 && newVradius<16000","");
  Tres_RMS_nuNC_3->Draw("same");
  leg13->AddEntry(Tres_RMS_nuNC_3, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg13->Draw();

  ////////////////////////////////////

  TLegend * leg14 = new TLegend(0.62,0.9,0.9,0.55);
  TH1F *Tres_RMS_numuCC_4 = new TH1F("Tres_RMS_numuCC_4","",250,0., 200.);
  Tres_RMS_numuCC_4->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_numuCC_4->GetYaxis()->SetTitle("entries");
  Tres_RMS_numuCC_4->GetYaxis()->SetTitleOffset(1.3);
  Tres_RMS_numuCC_4->GetXaxis()->SetTitleSize(0.047);
  Tres_RMS_numuCC_4->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_numuCC_4->GetYaxis()->SetLabelSize(0.047);  
  Tres_RMS_numuCC_4->SetLineWidth(4);
  Tres_RMS_numuCC_4->SetLineColor(kBlue+2);
  Tres_RMS_numuCC_4->GetXaxis()->SetRangeUser(40,150);
  Tres_RMS_numuCC_4->SetTitle("N_{PE} > 2.22 #times 10^{6}");
  mytree->Project("Tres_RMS_numuCC_4","Tres_RMS","CCint==1 && abs(init_lepID)==13 && trueNPE>=2.21877E6 && newVradius<16000","");
  c1->cd(4);
  Tres_RMS_numuCC_4->Draw();
  leg14->AddEntry(Tres_RMS_numuCC_4, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_nueCC_4 = new TH1F("Tres_RMS_nueCC_4","",250,0., 200.);
  Tres_RMS_nueCC_4->SetLineWidth(4);
  Tres_RMS_nueCC_4->SetLineColor(kRed);
  mytree->Project("Tres_RMS_nueCC_4","Tres_RMS","CCint==1 && abs(init_lepID)==11 && trueNPE>=2.21877E6 && newVradius<16000","");
  Tres_RMS_nueCC_4->Draw("same");
  leg14->AddEntry(Tres_RMS_nueCC_4, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_nuNC_4 = new TH1F("Tres_RMS_nuNC_4","",250,0., 200.);
  Tres_RMS_nuNC_4->SetLineWidth(4);
  Tres_RMS_nuNC_4->SetLineColor(kSpring-1);
  mytree->Project("Tres_RMS_nuNC_4","Tres_RMS","NCint==1 && trueNPE>=2.21877E6 && newVradius<16000","");
  Tres_RMS_nuNC_4->Draw("same");
  leg14->AddEntry(Tres_RMS_nuNC_4, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg14->Draw();

  c1->SaveAs("Plot/Tres_RMS_nuall_CC+NC_0-10GeV_16volcut_1m_EnBins_ALL.pdf");
  c1->SaveAs("Plot/Tres_RMS_nuall_CC+NC_0-10GeV_16volcut_1m_EnBins_ALL.png");
  c1->SaveAs("Plot/Tres_RMS_nuall_CC+NC_0-10GeV_16volcut_1m_EnBins_ALL.C");

  ////////////////////////////////////////////////////////////////////////////////////////////////

  TLegend * leg21 = new TLegend(0.1,0.9,0.4,0.6);
  TCanvas *c2 = new TCanvas("c2","",1600,900);
  c2->Divide(2,2);
  TH1F *Tres_RMS_cumul_numuCC_1 = (TH1F*)Tres_RMS_numuCC_1->GetCumulative(kTRUE);
  Tres_RMS_cumul_numuCC_1->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_cumul_numuCC_1->GetYaxis()->SetTitle("entries");
  Tres_RMS_cumul_numuCC_1->GetYaxis()->SetTitleOffset(1.3);
  Tres_RMS_cumul_numuCC_1->GetXaxis()->SetTitleSize(0.047);
  Tres_RMS_cumul_numuCC_1->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_1->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_1->SetLineWidth(5);
  Tres_RMS_cumul_numuCC_1->SetLineColor(kBlue+2);
  Tres_RMS_cumul_numuCC_1->GetXaxis()->SetRangeUser(40,150);
  Tres_RMS_cumul_numuCC_1->GetYaxis()->SetRangeUser(0,1300);
  c2->cd(1);
  Tres_RMS_cumul_numuCC_1->Draw();
  leg21->AddEntry(Tres_RMS_cumul_numuCC_1, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_cumul_nueCC_1 = (TH1F*)Tres_RMS_nueCC_1->GetCumulative(kTRUE);
  Tres_RMS_cumul_nueCC_1->SetLineWidth(5);
  Tres_RMS_cumul_nueCC_1->SetLineColor(kRed);
  Tres_RMS_cumul_nueCC_1->Draw("same");
  leg21->AddEntry(Tres_RMS_cumul_nueCC_1, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_cumul_nuNC_1 = (TH1F*)Tres_RMS_nuNC_1->GetCumulative(kTRUE);
  Tres_RMS_cumul_nuNC_1->SetLineWidth(5);
  Tres_RMS_cumul_nuNC_1->SetLineColor(kSpring-1);
  Tres_RMS_cumul_nuNC_1->Draw("same");
  leg21->AddEntry(Tres_RMS_cumul_nuNC_1, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg21->Draw();

  ////////////////////////////////////

  TLegend * leg22 = new TLegend(0.1,0.9,0.4,0.6);
  TH1F *Tres_RMS_cumul_numuCC_2 = (TH1F*)Tres_RMS_numuCC_2->GetCumulative(kTRUE);
  Tres_RMS_cumul_numuCC_2->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_cumul_numuCC_2->GetYaxis()->SetTitle("entries");
  Tres_RMS_cumul_numuCC_2->GetYaxis()->SetTitleOffset(1.3);
  Tres_RMS_cumul_numuCC_2->GetXaxis()->SetTitleSize(0.047);
  Tres_RMS_cumul_numuCC_2->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_2->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_2->SetLineWidth(5);
  Tres_RMS_cumul_numuCC_2->SetLineColor(kBlue+2);
  Tres_RMS_cumul_numuCC_2->GetXaxis()->SetRangeUser(40,150);
  c2->cd(2);
  Tres_RMS_cumul_numuCC_2->Draw();
  leg22->AddEntry(Tres_RMS_cumul_numuCC_2, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_cumul_nueCC_2 = (TH1F*)Tres_RMS_nueCC_2->GetCumulative(kTRUE);
  Tres_RMS_cumul_nueCC_2->SetLineWidth(5);
  Tres_RMS_cumul_nueCC_2->SetLineColor(kRed);
  Tres_RMS_cumul_nueCC_2->Draw("same");
  leg22->AddEntry(Tres_RMS_cumul_nueCC_2, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_cumul_nuNC_2 = (TH1F*)Tres_RMS_nuNC_2->GetCumulative(kTRUE);
  Tres_RMS_cumul_nuNC_2->SetLineWidth(5);
  Tres_RMS_cumul_nuNC_2->SetLineColor(kSpring-1);
  Tres_RMS_cumul_nuNC_2->Draw("same");
  leg22->AddEntry(Tres_RMS_cumul_nuNC_2, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg22->Draw();

  ////////////////////////////////////

  TLegend * leg23 = new TLegend(0.1,0.9,0.4,0.6);
  TH1F *Tres_RMS_cumul_numuCC_3 = (TH1F*)Tres_RMS_numuCC_3->GetCumulative(kTRUE);
  Tres_RMS_cumul_numuCC_3->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_cumul_numuCC_3->GetYaxis()->SetTitle("entries");
  Tres_RMS_cumul_numuCC_3->GetYaxis()->SetTitleOffset(1.3);
  Tres_RMS_cumul_numuCC_3->GetXaxis()->SetTitleSize(0.047);
  Tres_RMS_cumul_numuCC_3->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_3->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_3->SetLineWidth(5);
  Tres_RMS_cumul_numuCC_3->SetLineColor(kBlue+2);
  Tres_RMS_cumul_numuCC_3->GetXaxis()->SetRangeUser(40,150);
  c2->cd(3);
  Tres_RMS_cumul_numuCC_3->Draw();
  leg23->AddEntry(Tres_RMS_cumul_numuCC_3, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_cumul_nueCC_3 = (TH1F*)Tres_RMS_nueCC_3->GetCumulative(kTRUE);
  Tres_RMS_cumul_nueCC_3->SetLineWidth(5);
  Tres_RMS_cumul_nueCC_3->SetLineColor(kRed);
  Tres_RMS_cumul_nueCC_3->Draw("same");
  leg23->AddEntry(Tres_RMS_cumul_nueCC_3, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_cumul_nuNC_3 = (TH1F*)Tres_RMS_nuNC_3->GetCumulative(kTRUE);
  Tres_RMS_cumul_nuNC_3->SetLineWidth(5);
  Tres_RMS_cumul_nuNC_3->SetLineColor(kSpring-1);
  Tres_RMS_cumul_nuNC_3->Draw("same");
  leg23->AddEntry(Tres_RMS_cumul_nuNC_3, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg23->Draw();

  ////////////////////////////////////

  TLegend * leg24 = new TLegend(0.1,0.9,0.4,0.6);
  TH1F *Tres_RMS_cumul_numuCC_4 = (TH1F*)Tres_RMS_numuCC_4->GetCumulative(kTRUE);
  Tres_RMS_cumul_numuCC_4->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_cumul_numuCC_4->GetYaxis()->SetTitle("entries");
  Tres_RMS_cumul_numuCC_4->GetYaxis()->SetTitleOffset(1.3);
  Tres_RMS_cumul_numuCC_4->GetXaxis()->SetTitleSize(0.047);
  Tres_RMS_cumul_numuCC_4->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_4->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_cumul_numuCC_4->SetLineWidth(5);
  Tres_RMS_cumul_numuCC_4->SetLineColor(kBlue+2);
  Tres_RMS_cumul_numuCC_4->GetXaxis()->SetRangeUser(40,150);
  c2->cd(4);
  Tres_RMS_cumul_numuCC_4->Draw();
  leg24->AddEntry(Tres_RMS_cumul_numuCC_4, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_cumul_nueCC_4 = (TH1F*)Tres_RMS_nueCC_4->GetCumulative(kTRUE);
  Tres_RMS_cumul_nueCC_4->SetLineWidth(5);
  Tres_RMS_cumul_nueCC_4->SetLineColor(kRed);
  Tres_RMS_cumul_nueCC_4->Draw("same");
  leg24->AddEntry(Tres_RMS_cumul_nueCC_4, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_cumul_nuNC_4 = (TH1F*)Tres_RMS_nuNC_4->GetCumulative(kTRUE);
  Tres_RMS_cumul_nuNC_4->SetLineWidth(5);
  Tres_RMS_cumul_nuNC_4->SetLineColor(kSpring-1);
  Tres_RMS_cumul_nuNC_4->Draw("same");
  leg24->AddEntry(Tres_RMS_cumul_nuNC_4, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg24->Draw();

  c2->SaveAs("Plot/Tres_RMS_cumul_nuall_CC+NC_0-10GeV_16volcut_1m_EnBins_ALL.pdf");
  c2->SaveAs("Plot/Tres_RMS_cumul_nuall_CC+NC_0-10GeV_16volcut_1m_EnBins_ALL.png");
  c2->SaveAs("Plot/Tres_RMS_cumul_nuall_CC+NC_0-10GeV_16volcut_1m_EnBins_ALL.C");

  ////////////////////////////////////////////////////////////////////////////////////////////////

  TLegend * leg31 = new TLegend(0.62,0.9,0.9,0.55);
  TCanvas *c3 = new TCanvas("c3","",1600,900);
  c3->Divide(2,2);
  TH1F *Tres_RMS_revcumul_numuCC_1 = (TH1F*)Tres_RMS_numuCC_1->GetCumulative(kFALSE);
  Tres_RMS_revcumul_numuCC_1->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_revcumul_numuCC_1->GetYaxis()->SetTitle("entries");
  Tres_RMS_revcumul_numuCC_1->GetYaxis()->SetTitleOffset(1.3);
  Tres_RMS_revcumul_numuCC_1->GetXaxis()->SetTitleSize(0.047);
  Tres_RMS_revcumul_numuCC_1->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_1->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_1->SetLineWidth(5);
  Tres_RMS_revcumul_numuCC_1->SetLineColor(kBlue+2);
  Tres_RMS_revcumul_numuCC_1->GetXaxis()->SetRangeUser(40,150);
  Tres_RMS_revcumul_numuCC_1->GetYaxis()->SetRangeUser(0,1300);
  c3->cd(1);
  Tres_RMS_revcumul_numuCC_1->Draw();
  leg31->AddEntry(Tres_RMS_revcumul_numuCC_1, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_revcumul_nueCC_1 = (TH1F*)Tres_RMS_nueCC_1->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nueCC_1->SetLineWidth(5);
  Tres_RMS_revcumul_nueCC_1->SetLineColor(kRed);
  Tres_RMS_revcumul_nueCC_1->Draw("same");
  leg31->AddEntry(Tres_RMS_revcumul_nueCC_1, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_revcumul_nuNC_1 = (TH1F*)Tres_RMS_nuNC_1->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nuNC_1->SetLineWidth(5);
  Tres_RMS_revcumul_nuNC_1->SetLineColor(kSpring-1);
  Tres_RMS_revcumul_nuNC_1->Draw("same");
  leg31->AddEntry(Tres_RMS_revcumul_nuNC_1, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg31->Draw();

  ////////////////////////////////////

  TLegend * leg32 = new TLegend(0.62,0.9,0.9,0.55);
  TH1F *Tres_RMS_revcumul_numuCC_2 = (TH1F*)Tres_RMS_numuCC_2->GetCumulative(kFALSE);
  Tres_RMS_revcumul_numuCC_2->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_revcumul_numuCC_2->GetYaxis()->SetTitle("entries");
  Tres_RMS_revcumul_numuCC_2->GetYaxis()->SetTitleOffset(1.3);
  Tres_RMS_revcumul_numuCC_2->GetXaxis()->SetTitleSize(0.047);
  Tres_RMS_revcumul_numuCC_2->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_2->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_2->SetLineWidth(5);
  Tres_RMS_revcumul_numuCC_2->SetLineColor(kBlue+2);
  Tres_RMS_revcumul_numuCC_2->GetXaxis()->SetRangeUser(40,150);
  c3->cd(2);
  Tres_RMS_revcumul_numuCC_2->Draw();
  leg32->AddEntry(Tres_RMS_revcumul_numuCC_2, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_revcumul_nueCC_2 = (TH1F*)Tres_RMS_nueCC_2->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nueCC_2->SetLineWidth(5);
  Tres_RMS_revcumul_nueCC_2->SetLineColor(kRed);
  Tres_RMS_revcumul_nueCC_2->Draw("same");
  leg32->AddEntry(Tres_RMS_revcumul_nueCC_2, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_revcumul_nuNC_2 = (TH1F*)Tres_RMS_nuNC_2->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nuNC_2->SetLineWidth(5);
  Tres_RMS_revcumul_nuNC_2->SetLineColor(kSpring-1);
  Tres_RMS_revcumul_nuNC_2->Draw("same");
  leg32->AddEntry(Tres_RMS_revcumul_nuNC_2, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg32->Draw();

  ////////////////////////////////////

  TLegend * leg33 = new TLegend(0.62,0.9,0.9,0.55);
  TH1F *Tres_RMS_revcumul_numuCC_3 = (TH1F*)Tres_RMS_numuCC_3->GetCumulative(kFALSE);
  Tres_RMS_revcumul_numuCC_3->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_revcumul_numuCC_3->GetYaxis()->SetTitle("entries");
  Tres_RMS_revcumul_numuCC_3->GetYaxis()->SetTitleOffset(1.3);
  Tres_RMS_revcumul_numuCC_3->GetXaxis()->SetTitleSize(0.047);
  Tres_RMS_revcumul_numuCC_3->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_3->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_3->SetLineWidth(5);
  Tres_RMS_revcumul_numuCC_3->SetLineColor(kBlue+2);
  Tres_RMS_revcumul_numuCC_3->GetXaxis()->SetRangeUser(40,150);
  c3->cd(3);
  Tres_RMS_revcumul_numuCC_3->Draw();
  leg33->AddEntry(Tres_RMS_revcumul_numuCC_3, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_revcumul_nueCC_3 = (TH1F*)Tres_RMS_nueCC_3->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nueCC_3->SetLineWidth(5);
  Tres_RMS_revcumul_nueCC_3->SetLineColor(kRed);
  Tres_RMS_revcumul_nueCC_3->Draw("same");
  leg33->AddEntry(Tres_RMS_revcumul_nueCC_3, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_revcumul_nuNC_3 = (TH1F*)Tres_RMS_nuNC_3->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nuNC_3->SetLineWidth(5);
  Tres_RMS_revcumul_nuNC_3->SetLineColor(kSpring-1);
  Tres_RMS_revcumul_nuNC_3->Draw("same");
  leg33->AddEntry(Tres_RMS_revcumul_nuNC_3, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg33->Draw();

  ////////////////////////////////////

  TLegend * leg34 = new TLegend(0.62,0.9,0.9,0.55);
  TH1F *Tres_RMS_revcumul_numuCC_4 = (TH1F*)Tres_RMS_numuCC_4->GetCumulative(kFALSE);
  Tres_RMS_revcumul_numuCC_4->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_revcumul_numuCC_4->GetYaxis()->SetTitle("entries");
  Tres_RMS_revcumul_numuCC_4->GetYaxis()->SetTitleOffset(1.3);
  Tres_RMS_revcumul_numuCC_4->GetXaxis()->SetTitleSize(0.047);
  Tres_RMS_revcumul_numuCC_4->GetXaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_4->GetYaxis()->SetLabelSize(0.047);
  Tres_RMS_revcumul_numuCC_4->SetLineWidth(5);
  Tres_RMS_revcumul_numuCC_4->SetLineColor(kBlue+2);
  Tres_RMS_revcumul_numuCC_4->GetXaxis()->SetRangeUser(40,150);
  c3->cd(4);
  Tres_RMS_revcumul_numuCC_4->Draw();
  leg34->AddEntry(Tres_RMS_revcumul_numuCC_4, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_revcumul_nueCC_4 = (TH1F*)Tres_RMS_nueCC_4->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nueCC_4->SetLineWidth(5);
  Tres_RMS_revcumul_nueCC_4->SetLineColor(kRed);
  Tres_RMS_revcumul_nueCC_4->Draw("same");
  leg34->AddEntry(Tres_RMS_revcumul_nueCC_4, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_revcumul_nuNC_4 = (TH1F*)Tres_RMS_nuNC_4->GetCumulative(kFALSE);
  Tres_RMS_revcumul_nuNC_4->SetLineWidth(5);
  Tres_RMS_revcumul_nuNC_4->SetLineColor(kSpring-1);
  Tres_RMS_revcumul_nuNC_4->Draw("same");
  leg34->AddEntry(Tres_RMS_revcumul_nuNC_4, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg34->Draw();

  c3->SaveAs("Plot/Tres_RMS_revcumul_nuall_CC+NC_0-10GeV_16volcut_1m_EnBins_ALL.pdf");
  c3->SaveAs("Plot/Tres_RMS_revcumul_nuall_CC+NC_0-10GeV_16volcut_1m_EnBins_ALL.png");
  c3->SaveAs("Plot/Tres_RMS_revcumul_nuall_CC+NC_0-10GeV_16volcut_1m_EnBins_ALL.C");

}
//  LocalWords:  numuCC
