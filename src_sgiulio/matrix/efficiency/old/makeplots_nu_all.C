makeplots_nu_all() {
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);

  TFile *_file1 = TFile::Open("Plot/TRUEnuall_0-10GeV_red_1m.root");/*
  TCanvas *c15 = new TCanvas("c15","",1600,1200);
  TLegend * leg4 = new TLegend(0.7,0.9,0.9,0.7);
  TH1F *Npe_nuNC = new TH1F("Npe_nuNC","",200,0.,1.4E7);
  Npe_nuNC->GetXaxis()->SetTitle("N_{PE}");
  gPad->SetLogy();
  Npe_nuNC->SetLineWidth(2);
  Npe_nuNC->SetLineColor(kSpring-1);
  Data->Project("Npe_nuNC","trueNPE_LPMT","NCint==1 && newVradius<16000","");
  c15->cd();
  Npe_nuNC->Draw();
  leg4->AddEntry(Npe_nuNC, "#nu_{e}+#nu_{#mu} NC" ,"l");
  TH1F *Npe_nueCC = new TH1F("Npe_nueCC","",200,0.,1.4E7);
  Npe_nueCC->GetXaxis()->SetTitle("N_{PE}"); 
  gPad->SetLogy();
  Npe_nueCC->SetLineWidth(2);
  Npe_nueCC->SetLineColor(kRed);
  Data->Project("Npe_nueCC","trueNPE_LPMT","CCint==1 && abs(init_lepID)==11 && newVradius<16000","");
  Npe_nueCC->Draw("same");
  leg4->AddEntry(Npe_nueCC, "#nu_{e} CC" ,"l");
  TH1F *Npe_numuCC = new TH1F("Npe_numuCC","",200,0., 1.4E7);
  Npe_numuCC->GetXaxis()->SetTitle("N_{PE}");
  Npe_numuCC->SetLineWidth(2);
  Npe_numuCC->SetLineColor(kBlue);
  Data->Project("Npe_numuCC","trueNPE_LPMT","CCint==1 && abs(init_lepID)==13 && newVradius<16000","");
  Npe_numuCC->Draw("same");
  leg4->AddEntry(Npe_numuCC, "#nu_{#mu} CC" ,"l");
  leg4->Draw();
  c15->SaveAs("Plot/NPE_LPMT_nuall_CC+NC_0-10GeV_16volcut_purecharge_1m_ALL.png");
  c15->SaveAs("Plot/NPE_LPMT_nuall_CC+NC_0-10GeV_16volcut_purecharge_1m_ALL.pdf");
  c15->SaveAs("Plot/NPE_LPMT_nuall_CC+NC_0-10GeV_16volcut_purecharge_1m_ALL.C");

  TCanvas *c25 = new TCanvas("c25","",1600,1200);
  TLegend * leg17 = new TLegend(0.7,0.9,0.9,0.7);
  TH1F *Npe_2_nuNC = new TH1F("Npe_2_nuNC","",100,0.,1.5E6);
  Npe_2_nuNC->GetXaxis()->SetTitle("N_{PE}");
  gPad->SetLogy();
  Npe_2_nuNC->SetLineWidth(4);
  Npe_2_nuNC->SetLineColor(kSpring-1);
  Data->Project("Npe_2_nuNC","trueNPE_LPMT","NCint==1 && newVradius<16000","");
  c25->cd();
  Npe_2_nuNC->Draw();
  leg17->AddEntry(Npe_2_nuNC, "#nu_{e}+#nu_{#mu} NC" ,"l");
  TH1F *Npe_2_nueCC = new TH1F("Npe_2_nueCC","",100,0.,1.5E6);
  Npe_2_nueCC->GetXaxis()->SetTitle("N_{PE}");
  gPad->SetLogy();
  Npe_2_nueCC->SetLineWidth(4);
  Npe_2_nueCC->SetLineColor(kRed);
  Data->Project("Npe_2_nueCC","trueNPE_LPMT","CCint==1 && abs(init_lepID)==11 && newVradius<16000","");
  Npe_2_nueCC->Draw("same");
  leg17->AddEntry(Npe_2_nueCC, "#nu_{e} CC" ,"l");
  TH1F *Npe_2_numuCC = new TH1F("Npe_2_numuCC","",100,0., 1.5E6);
  Npe_2_numuCC->GetXaxis()->SetTitle("N_{PE}");
  Npe_2_numuCC->SetLineWidth(4);
  Npe_2_numuCC->SetLineColor(kBlue);
  Data->Project("Npe_2_numuCC","trueNPE_LPMT","CCint==1 && abs(init_lepID)==13 && newVradius<16000","");
  Npe_2_numuCC->Draw("same");
  leg17->AddEntry(Npe_2_numuCC, "#nu_{#mu} CC" ,"l");
  leg17->Draw();
  c25->SaveAs("Plot/NPE_LPMT_nuall_CC+NC_0-10GeV_16volcut_purecharge_1m_ALL_lowE.png");
  c25->SaveAs("Plot/NPE_LPMT_nuall_CC+NC_0-10GeV_16volcut_purecharge_1m_ALL_lowE.pdf");
  c25->SaveAs("Plot/NPE_LPMT_nuall_CC+NC_0-10GeV_16volcut_purecharge_1m_ALL_lowE.C");
*/
  /*
  TCanvas *c11 = new TCanvas("c11","",1600,1200);
  TH2F *Npe_VS_Ev_numuCC = new TH2F("Npe_VS_Ev_numuCC","",150,0.,1.E4,150,0.,1.6E7);
  gPad->SetLogz();
  Npe_VS_Ev_numuCC->GetYaxis()->SetTitle("N_{PE}");
  Npe_VS_Ev_numuCC->GetXaxis()->SetTitle("Neutrino energy [MeV]");
  Data->Project("Npe_VS_Ev_numuCC","trueNPE_LPMT:nuEnergy","trueVradius<16000","");
  c11->cd();
  Npe_VS_Ev_numuCC->Draw("colz");
  c11->SaveAs("Plot/NPE_LPMT_VS_Ev_numuCC_0-10GeV_16volcut_purecharge_1m_ALL.pdf");
  c11->SaveAs("Plot/NPE_LPMT_VS_Ev_numuCC_0-10GeV_16volcut_purecharge_1m_ALL.png");
  c11->SaveAs("Plot/NPE_LPMT_VS_Ev_numuCC_0-10GeV_16volcut_purecharge_1m_ALL.C");
  TFile *_file7 = TFile::Open("Plot/TRUEnue_0-10GeV_red_1m_CCpure.root");
  TCanvas *c12 = new TCanvas("c12","",1600,1200);
  TH2F *Npe_VS_Ev_nueCC = new TH2F("Npe_VS_Ev_nueCC","",150,0.,1.E4,150,0.,1.6E7);
  gPad->SetLogz();
  Npe_VS_Ev_nueCC->GetYaxis()->SetTitle("N_{PE}");
  Npe_VS_Ev_nueCC->GetXaxis()->SetTitle("Neutrino energy [MeV]");
  Data->Project("Npe_VS_Ev_nueCC","trueNPE_LPMT:nuEnergy","trueVradius<16000","");
  c12->cd();
  Npe_VS_Ev_nueCC->Draw("colz");
  c12->SaveAs("Plot/NPE_LPMT_VS_Ev_nueCC_0-10GeV_16volcut_purecharge_1m_ALL.pdf");
  c12->SaveAs("Plot/NPE_LPMT_VS_Ev_nueCC_0-10GeV_16volcut_purecharge_1m_ALL.png");
  c12->SaveAs("Plot/NPE_LPMT_VS_Ev_nueCC_0-10GeV_16volcut_purecharge_1m_ALL.C");
  TFile *_file8 = TFile::Open("Plot/TRUEnue+numu_0-10GeV_red_1m_NCpure.root");
  TCanvas *c13 = new TCanvas("c13","",1600,1200);
  TH2F *Npe_VS_Ev_nuNC = new TH2F("Npe_VS_Ev_nuNC","",150,0.,1.E4,150,0.,0.99E7);
  gPad->SetLogz();
  Npe_VS_Ev_nuNC->GetYaxis()->SetTitle("N_{PE}");
  Npe_VS_Ev_nuNC->GetXaxis()->SetTitle("Neutrino energy [MeV]");
  Data->Project("Npe_VS_Ev_nuNC","trueNPE_LPMT:nuEnergy","trueVradius<16000","");
  c13->cd();
  Npe_VS_Ev_nuNC->Draw("colz");
  c13->SaveAs("Plot/NPE_LPMT_VS_Ev_nuNC_0-10GeV_16volcut_purecharge_1m_ALL.pdf");
  c13->SaveAs("Plot/NPE_LPMT_VS_Ev_nuNC_0-10GeV_16volcut_purecharge_1m_ALL.png");
  c13->SaveAs("Plot/NPE_LPMT_VS_Ev_nuNC_0-10GeV_16volcut_purecharge_1m_ALL.C");

  TFile *_file1 = TFile::Open("Plot/TRUEnumu_0-10GeV_red_1m_CCpure.root");  */
  TLegend * leg1 = new TLegend(0.7,0.9,0.9,0.7);
  TCanvas *c3 = new TCanvas("c3","",1600,1200);
  TH1F *Tres_RMS_numuCC = new TH1F("Tres_RMS_numuCC","",250,0., 200.);
  Tres_RMS_numuCC->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_numuCC->SetLineWidth(5);
  Tres_RMS_numuCC->SetLineColor(kBlue);
  Tres_RMS_numuCC->GetXaxis()->SetRangeUser(40,150);
  Data->Project("Tres_RMS_numuCC","Tres_RMS","CCint==1 && abs(init_lepID)==13 && trueNPE>1.E5 && newVradius<16000","");
  c3->cd();
  Tres_RMS_numuCC->Draw();
  leg1->AddEntry(Tres_RMS_numuCC, "#nu_{#mu} CC" ,"l");
  TH1F *Tres_RMS_nueCC = new TH1F("Tres_RMS_nueCC","",250,0., 200.);
  Tres_RMS_nueCC->SetLineWidth(5);
  Tres_RMS_nueCC->SetLineColor(kRed);
  Data->Project("Tres_RMS_nueCC","Tres_RMS","CCint==1 && abs(init_lepID)==11 && trueNPE>1.E5 && newVradius<16000","");
  Tres_RMS_nueCC->Draw("same");
  leg1->AddEntry(Tres_RMS_nueCC, "#nu_{e} CC" ,"l");
  TH1F *Tres_RMS_nuNC = new TH1F("Tres_RMS_nuNC","",250,0., 200.);
  Tres_RMS_nuNC->SetLineWidth(5);
  Tres_RMS_nuNC->SetLineColor(kSpring-1);
  Data->Project("Tres_RMS_nuNC","Tres_RMS","NCint==1 && trueNPE>1.E5 && newVradius<16000","");
  Tres_RMS_nuNC->Draw("same");
  leg1->AddEntry(Tres_RMS_nuNC, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg1->Draw();

  //gPad->BuildLegend(0.1,0.9,0.6,0.7); 
  c3->SaveAs("Plot/Tres_RMS_nuall_CC+NC_0-10GeV_16volcut_purecharge_1m_ALL.pdf");
  c3->SaveAs("Plot/Tres_RMS_nuall_CC+NC_0-10GeV_16volcut_purecharge_1m_ALL.png");
  c3->SaveAs("Plot/Tres_RMS_nuall_CC+NC_0-10GeV_16volcut_purecharge_1m_ALL.C");

  ////////////////////////////////////////////////////////////////////////////////////////////////
  /*
  TLegend * leg2 = new TLegend(0.7,0.9,0.9,0.7);
  TCanvas *c10 = new TCanvas("c10","",1600,1200);
  TH2F *Tres_RMS_VS_Npe_2_numuCC = new TH2F("Tres_RMS_VS_Npe_2_numuCC","",100,0.,1.3E7, 100,1., 200.);
  gPad->SetLogx();
  Tres_RMS_VS_Npe_2_numuCC->GetXaxis()->SetTitle("N_{PE}");
  Tres_RMS_VS_Npe_2_numuCC->GetYaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_VS_Npe_2_numuCC->SetMarkerStyle(6);
  Tres_RMS_VS_Npe_2_numuCC->SetMarkerColor(kBlue);
  Tres_RMS_VS_Npe_2_numuCC->SetFillColorAlpha(kBlue, 1.0);
  Data->Project("Tres_RMS_VS_Npe_2_numuCC","Tres_RMS:trueNPE_LPMT","CCint==1 && abs(init_lepID)==13 && newVradius<16000","");
  c10->cd();
  Tres_RMS_VS_Npe_2_numuCC->Draw();
  leg2->AddEntry(Tres_RMS_VS_Npe_2_numuCC, "#nu_{#mu} CC" ,"f");
  TH2F *Tres_RMS_VS_Npe_2_nueCC = new TH2F("Tres_RMS_VS_Npe_2_nueCC","",100,0.,1.3E7, 100,1., 200.);
  Tres_RMS_VS_Npe_2_nueCC->SetMarkerStyle(6);
  Tres_RMS_VS_Npe_2_nueCC->SetMarkerColor(kRed);
  Tres_RMS_VS_Npe_2_nueCC->SetFillColorAlpha(kRed, 1.0);
  Data->Project("Tres_RMS_VS_Npe_2_nueCC","Tres_RMS:trueNPE_LPMT","CCint==1 && abs(init_lepID)==11 && newVradius<16000","");
  Tres_RMS_VS_Npe_2_nueCC->Draw("same");
  leg2->AddEntry(Tres_RMS_VS_Npe_2_nueCC, "#nu_{e} CC" ,"f");
  TH2F *Tres_RMS_VS_Npe_2_nuNC = new TH2F("Tres_RMS_VS_Npe_2_nuNC","",100,0.,1.3E7, 100,1., 200.);
  Tres_RMS_VS_Npe_2_nuNC->SetMarkerStyle(6);
  Tres_RMS_VS_Npe_2_nuNC->SetMarkerColor(kSpring-1);
  Tres_RMS_VS_Npe_2_nuNC->SetFillColorAlpha(kSpring-1, 0.3);
  Data->Project("Tres_RMS_VS_Npe_2_nuNC","Tres_RMS:trueNPE_LPMT","NCint==1 && newVradius<16000","");
  Tres_RMS_VS_Npe_2_nuNC->Draw("same");
  leg2->AddEntry(Tres_RMS_VS_Npe_2_nuNC, "#nu_{e}+#nu_{#mu} NC" ,"f");
  leg2->Draw();

  //gPad->BuildLegend(0.1,0.9,0.6,0.7);                                                                                                                                                                     
  c10->SaveAs("Plot/tres_RMS_VS_Npe_LPMT_nuall_CC+NC_0-10GeV_16volcut_purecharge_1m_ALL_logX.pdf");
  c10->SaveAs("Plot/tres_RMS_VS_Npe_LPMT_nuall_CC+NC_0-10GeV_16volcut_purecharge_1m_ALL_logX.png");
  c10->SaveAs("Plot/tres_RMS_VS_Npe_LPMT_nuall_CC+NC_0-10GeV_16volcut_purecharge_1m_ALL_logX.C");

  /////////////////////////////////////////////////////////////////////////////////////////
  
  TLegend * leg22 = new TLegend(0.7,0.9,0.9,0.7);
  TCanvas *c110 = new TCanvas("c110","",1600,1200);
  TH2F *Tres_RMS_VS_Npe_numuCC = new TH2F("Tres_RMS_VS_Npe_numuCC","",100,0.,1.3E7, 100,1., 200.);
  Tres_RMS_VS_Npe_numuCC->GetXaxis()->SetTitle("N_{PE}");
  Tres_RMS_VS_Npe_numuCC->GetYaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_VS_Npe_numuCC->SetMarkerStyle(6);
  Tres_RMS_VS_Npe_numuCC->SetMarkerColor(kBlue);
  Tres_RMS_VS_Npe_numuCC->SetFillColorAlpha(kBlue, 1.0);
  Data->Project("Tres_RMS_VS_Npe_numuCC","Tres_RMS:trueNPE_LPMT","CCint==1 && abs(init_lepID)==13 && newVradius<16000","");
  c110->cd();
  Tres_RMS_VS_Npe_numuCC->Draw();
  leg22->AddEntry(Tres_RMS_VS_Npe_numuCC, "#nu_{#mu} CC" ,"f");
  TH2F *Tres_RMS_VS_Npe_nueCC = new TH2F("Tres_RMS_VS_Npe_nueCC","",100,0.,1.3E7, 100,1., 200.);
  Tres_RMS_VS_Npe_nueCC->SetMarkerStyle(6);
  Tres_RMS_VS_Npe_nueCC->SetMarkerColor(kRed);
  Tres_RMS_VS_Npe_nueCC->SetFillColorAlpha(kRed, 1.0);
  Data->Project("Tres_RMS_VS_Npe_nueCC","Tres_RMS:trueNPE_LPMT","CCint==1 && abs(init_lepID)==11 && newVradius<16000","");
  Tres_RMS_VS_Npe_nueCC->Draw("same");
  leg22->AddEntry(Tres_RMS_VS_Npe_nueCC, "#nu_{e} CC" ,"f");
  TH2F *Tres_RMS_VS_Npe_nuNC = new TH2F("Tres_RMS_VS_Npe_nuNC","",100,0.,1.3E7, 100,1., 200.);
  Tres_RMS_VS_Npe_nuNC->SetMarkerStyle(6);
  Tres_RMS_VS_Npe_nuNC->SetMarkerColor(kSpring-1);
  Tres_RMS_VS_Npe_nuNC->SetFillColorAlpha(kSpring-1, 0.3);
  Data->Project("Tres_RMS_VS_Npe_nuNC","Tres_RMS:trueNPE_LPMT","NCint==1 && newVradius<16000","");
  Tres_RMS_VS_Npe_nuNC->Draw("same");
  leg22->AddEntry(Tres_RMS_VS_Npe_nuNC, "#nu_{e}+#nu_{#mu} NC" ,"f");
  leg22->Draw();

  c110->SaveAs("Plot/tres_RMS_VS_Npe_LPMT_nuall_CC+NC_0-10GeV_16volcut_purecharge_1m_ALL.pdf");
  c110->SaveAs("Plot/tres_RMS_VS_Npe_LPMT_nuall_CC+NC_0-10GeV_16volcut_purecharge_1m_ALL.png");
  c110->SaveAs("Plot/tres_RMS_VS_Npe_LPMT_nuall_CC+NC_0-10GeV_16volcut_purecharge_1m_ALL.C");
  */  
  /*
  TFile *_file1 = TFile::Open("Plot/TRUEnue_0-10GeV_red_1m_CCpure.root");  
  TCanvas *c4 = new TCanvas("c4","",1600,1200);
  TCanvas *c5 = new TCanvas("c5","",1600,1200);
  TH2F *Tres_RMS_shift_VS_vertex_shift_nueCC_h = new TH2F("Tres_RMS_shift_VS_vertex_shift_nueCC_h","",150,0.,6.,150,-5.,5.);
  Tres_RMS_shift_VS_vertex_shift_nueCC_h->GetXaxis()->SetTitle("vertex shift [m]");
  Tres_RMS_shift_VS_vertex_shift_nueCC_h->GetYaxis()->SetTitle("#sigma(t_{res}^{smearV}) - #sigma(t_{res}^{trueV}) [ns]");
  TH2F *Tres_Mean_shift_VS_vertex_shift_nueCC_h = new TH2F("Tres_Mean_shift_VS_vertex_shift_nueCC_h","",150,0.,6.,150,-10.,10.);
  Tres_Mean_shift_VS_vertex_shift_nueCC_h->GetXaxis()->SetTitle("vertex shift [m]");
  Tres_Mean_shift_VS_vertex_shift_nueCC_h->GetYaxis()->SetTitle("< t_{res}^{smearV} > - < t_{res}^{trueV} > [ns]");
  Data->Project("Tres_RMS_shift_VS_vertex_shift_nueCC_h","(Tres_RMS-Tres_RMS_trueV):vertex_shift/1000.","trueNPE>1.E5","");
  Data->Project("Tres_Mean_shift_VS_vertex_shift_nueCC_h","(Tres_Mean-Tres_Mean_trueV):vertex_shift/1000.","trueNPE>1.E5","");
  c4->cd();
  Tres_RMS_shift_VS_vertex_shift_nueCC_h->Draw("colz");
  c4->SaveAs("Plot/Tres_RMS_shift_VS_vertex_shift_nueCC_0-10GeV_16volcut_purecharge_1mV_ALL.pdf");
  c4->SaveAs("Plot/Tres_RMS_shift_VS_vertex_shift_nueCC_0-10GeV_16volcut_purecharge_1mV_ALL.png");
  c4->SaveAs("Plot/Tres_RMS_shift_VS_vertex_shift_nueCC_0-10GeV_16volcut_purecharge_1mV_ALL.C");
  c5->cd();
  Tres_Mean_shift_VS_vertex_shift_nueCC_h->Draw("colz");
  c5->SaveAs("Plot/Tres_Mean_shift_VS_vertex_shift_nueCC_0-10GeV_16volcut_purecharge_1mV_ALL.pdf");
  c5->SaveAs("Plot/Tres_Mean_shift_VS_vertex_shift_nueCC_0-10GeV_16volcut_purecharge_1mV_ALL.png");
  c5->SaveAs("Plot/Tres_Mean_shift_VS_vertex_shift_nueCC_0-10GeV_16volcut_purecharge_1mV_ALL.C");

  //////////////////////////////////////////////////////////////////////////////////////////////////////

  TFile *_file1 = TFile::Open("Plot/TRUEnumu_0-10GeV_red_1m_CCpure.root");
  TCanvas *c6 = new TCanvas("c6","",1600,1200);
  TCanvas *c7 = new TCanvas("c7","",1600,1200);
  TH2F *Tres_RMS_shift_VS_vertex_shift_numuCC_h = new TH2F("Tres_RMS_shift_VS_vertex_shift_numuCC_h","",150,0.,6.,150,-5.,5.);
  Tres_RMS_shift_VS_vertex_shift_numuCC_h->GetXaxis()->SetTitle("vertex shift [m]");
  Tres_RMS_shift_VS_vertex_shift_numuCC_h->GetYaxis()->SetTitle("#sigma(t_{res}^{smearV}) - #sigma(t_{res}^{trueV}) [ns]");
  TH2F *Tres_Mean_shift_VS_vertex_shift_numuCC_h = new TH2F("Tres_Mean_shift_VS_vertex_shift_numuCC_h","",150,0.,6.,150,-10.,10.);
  Tres_Mean_shift_VS_vertex_shift_numuCC_h->GetXaxis()->SetTitle("vertex shift [m]");
  Tres_Mean_shift_VS_vertex_shift_numuCC_h->GetYaxis()->SetTitle("< t_{res}^{smearV} > - < t_{res}^{trueV} > [ns]");
  Data->Project("Tres_RMS_shift_VS_vertex_shift_numuCC_h","(Tres_RMS-Tres_RMS_trueV):vertex_shift/1000.","trueNPE>1.E5","");
  Data->Project("Tres_Mean_shift_VS_vertex_shift_numuCC_h","(Tres_Mean-Tres_Mean_trueV):vertex_shift/1000.","trueNPE>1.E5","");
  c6->cd();
  Tres_RMS_shift_VS_vertex_shift_numuCC_h->Draw("colz");
  c6->SaveAs("Plot/Tres_RMS_shift_VS_vertex_shift_numuCC_0-10GeV_16volcut_purecharge_1mV_ALL.pdf");
  c6->SaveAs("Plot/Tres_RMS_shift_VS_vertex_shift_numuCC_0-10GeV_16volcut_purecharge_1mV_ALL.png");
  c6->SaveAs("Plot/Tres_RMS_shift_VS_vertex_shift_numuCC_0-10GeV_16volcut_purecharge_1mV_ALL.C");
  c7->cd();
  Tres_Mean_shift_VS_vertex_shift_numuCC_h->Draw("colz");
  c7->SaveAs("Plot/Tres_Mean_shift_VS_vertex_shift_numuCC_0-10GeV_16volcut_purecharge_1mV_ALL.pdf");
  c7->SaveAs("Plot/Tres_Mean_shift_VS_vertex_shift_numuCC_0-10GeV_16volcut_purecharge_1mV_ALL.png");
  c7->SaveAs("Plot/Tres_Mean_shift_VS_vertex_shift_numuCC_0-10GeV_16volcut_purecharge_1mV_ALL.C");

  /////////////////////////////////////////////////////////////////////////////////////////////////////////

  TFile *_file1 = TFile::Open("Plot/TRUEnue+numu_0-10GeV_red_1m_NCpure.root");
  TCanvas *c8 = new TCanvas("c8","",1600,1200);
  TCanvas *c9 = new TCanvas("c9","",1600,1200);
  TH2F *Tres_RMS_shift_VS_vertex_shift_nuNC_h = new TH2F("Tres_RMS_shift_VS_vertex_shift_nuNC_h","",150,0.,6.,150,-5.,5.);
  Tres_RMS_shift_VS_vertex_shift_nuNC_h->GetXaxis()->SetTitle("vertex shift [m]");
  Tres_RMS_shift_VS_vertex_shift_nuNC_h->GetYaxis()->SetTitle("#sigma(t_{res}^{smearV}) - #sigma(t_{res}^{trueV}) [ns]");
  TH2F *Tres_Mean_shift_VS_vertex_shift_nuNC_h = new TH2F("Tres_Mean_shift_VS_vertex_shift_nuNC_h","",150,0.,6.,150,-10.,10.);
  Tres_Mean_shift_VS_vertex_shift_nuNC_h->GetXaxis()->SetTitle("vertex shift [m]");
  Tres_Mean_shift_VS_vertex_shift_nuNC_h->GetYaxis()->SetTitle("< t_{res}^{smearV} > - < t_{res}^{trueV} > [ns]");
  Data->Project("Tres_RMS_shift_VS_vertex_shift_nuNC_h","(Tres_RMS-Tres_RMS_trueV):vertex_shift/1000.","trueNPE>1.E5","");
  Data->Project("Tres_Mean_shift_VS_vertex_shift_nuNC_h","(Tres_Mean-Tres_Mean_trueV):vertex_shift/1000.","trueNPE>1.E5","");
  c8->cd();
  Tres_RMS_shift_VS_vertex_shift_nuNC_h->Draw("colz");
  c8->SaveAs("Plot/Tres_RMS_shift_VS_vertex_shift_nuNC_0-10GeV_16volcut_purecharge_1mV_ALL.pdf");
  c8->SaveAs("Plot/Tres_RMS_shift_VS_vertex_shift_nuNC_0-10GeV_16volcut_purecharge_1mV_ALL.png");
  c8->SaveAs("Plot/Tres_RMS_shift_VS_vertex_shift_nuNC_0-10GeV_16volcut_purecharge_1mV_ALL.C");
  c9->cd();
  Tres_Mean_shift_VS_vertex_shift_nuNC_h->Draw("colz");
  c9->SaveAs("Plot/Tres_Mean_shift_VS_vertex_shift_nuNC_0-10GeV_16volcut_purecharge_1mV_ALL.pdf");
  c9->SaveAs("Plot/Tres_Mean_shift_VS_vertex_shift_nuNC_0-10GeV_16volcut_purecharge_1mV_ALL.png");
  c9->SaveAs("Plot/Tres_Mean_shift_VS_vertex_shift_nuNC_0-10GeV_16volcut_purecharge_1mV_ALL.C");
*/
  }
