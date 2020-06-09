makeplots_nu_mix() {
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);

  TCanvas *c15 = new TCanvas("c15","",1600,1200);
  TLegend * leg4 = new TLegend(0.7,0.9,0.9,0.7);
  TFile *_file1 = TFile::Open("Plot/TRUEnumu_0-10GeV_red_0_NCpure.root");
  TH1F *Npe_numuNC = new TH1F("Npe_numuNC","",200,0.,1.4E7);
  Npe_numuNC->GetXaxis()->SetTitle("N_{PE}"); 
  gPad->SetLogy();
  Npe_numuNC->SetLineWidth(5);
  Npe_numuNC->SetLineColor(kRed);
  Data->Project("Npe_numuNC","trueNPE","trueVradius<16000","");
  Npe_numuNC->Draw();
  leg4->AddEntry(Npe_numuNC, "NC" ,"l");
  TFile *_file0 = TFile::Open("Plot/TRUEnumu_0-10GeV_red_0_CCpure.root");
  TH1F *Npe_numuCC = new TH1F("Npe_numuCC","",200,0., 1.4E7);
  Npe_numuCC->GetXaxis()->SetTitle("N_{PE}");
  Npe_numuCC->SetLineWidth(5);
  Npe_numuCC->SetLineColor(kBlue);
  Data->Project("Npe_numuCC","trueNPE","trueVradius<16000","");
  c15->cd();
  Npe_numuCC->Draw("same");
  leg4->AddEntry(Npe_numuCC, "CC" ,"l");
  leg4->Draw();
  c15->SaveAs("Plot/NPE_numu_CC+NC_0-10GeV_16volcut_purecharge_0_ALL.png");
  c15->SaveAs("Plot/NPE_numu_CC+NC_0-10GeV_16volcut_purecharge_0_ALL.pdf");
  c15->SaveAs("Plot/NPE_numu_CC+NC_0-10GeV_16volcut_purecharge_0_ALL.C");


  /*
  TFile *_file6 = TFile::Open("Plot/TRUEnumu_0-10GeV_red_0_CCpure.root");
  TCanvas *c11 = new TCanvas("c11","",1600,1200);
  TH2F *Npe_VS_Ev_numuCC = new TH2F("Npe_VS_Ev_numuCC","",150,0.,1.E4,150,0.,1.6E7);
  gPad->SetLogz();
  Npe_VS_Ev_numuCC->GetYaxis()->SetTitle("N_{PE}");
  Npe_VS_Ev_numuCC->GetXaxis()->SetTitle("Neutrino energy [MeV]");
  Data->Project("Npe_VS_Ev_numuCC","trueNPE:nuEnergy","trueVradius<16000","");
  c11->cd();
  Npe_VS_Ev_numuCC->Draw("colz");
  c11->SaveAs("Plot/NPE_VS_Ev_numuCC_0-10GeV_16volcut_purecharge_0_ALL.pdf");
  c11->SaveAs("Plot/NPE_VS_Ev_numuCC_0-10GeV_16volcut_purecharge_0_ALL.png");
  c11->SaveAs("Plot/NPE_VS_Ev_numuCC_0-10GeV_16volcut_purecharge_0_ALL.C");
  TFile *_file7 = TFile::Open("Plot/TRUEnue_0-10GeV_red_0_CCpure.root");
  TCanvas *c12 = new TCanvas("c12","",1600,1200);
  TH2F *Npe_VS_Ev_nueCC = new TH2F("Npe_VS_Ev_nueCC","",150,0.,1.E4,150,0.,1.6E7);
  gPad->SetLogz();
  Npe_VS_Ev_nueCC->GetYaxis()->SetTitle("N_{PE}");
  Npe_VS_Ev_nueCC->GetXaxis()->SetTitle("Neutrino energy [MeV]");
  Data->Project("Npe_VS_Ev_nueCC","trueNPE:nuEnergy","trueVradius<16000","");
  c12->cd();
  Npe_VS_Ev_nueCC->Draw("colz");
  c12->SaveAs("Plot/NPE_VS_Ev_nueCC_0-10GeV_16volcut_purecharge_0_ALL.pdf");
  c12->SaveAs("Plot/NPE_VS_Ev_nueCC_0-10GeV_16volcut_purecharge_0_ALL.png");
  c12->SaveAs("Plot/NPE_VS_Ev_nueCC_0-10GeV_16volcut_purecharge_0_ALL.C");
  TFile *_file8 = TFile::Open("Plot/TRUEnue+numu_0-10GeV_red_0_NCpure.root");
  TCanvas *c13 = new TCanvas("c13","",1600,1200);
  TH2F *Npe_VS_Ev_nuNC = new TH2F("Npe_VS_Ev_nuNC","",150,0.,1.E4,150,0.,0.99E7);
  gPad->SetLogz();
  Npe_VS_Ev_nuNC->GetYaxis()->SetTitle("N_{PE}");
  Npe_VS_Ev_nuNC->GetXaxis()->SetTitle("Neutrino energy [MeV]");
  Data->Project("Npe_VS_Ev_nuNC","trueNPE:nuEnergy","trueVradius<16000","");
  c13->cd();
  Npe_VS_Ev_nuNC->Draw("colz");
  c13->SaveAs("Plot/NPE_VS_Ev_nuNC_0-10GeV_16volcut_purecharge_0_ALL.pdf");
  c13->SaveAs("Plot/NPE_VS_Ev_nuNC_0-10GeV_16volcut_purecharge_0_ALL.png");
  c13->SaveAs("Plot/NPE_VS_Ev_nuNC_0-10GeV_16volcut_purecharge_0_ALL.C");
  */

  /*
  TLegend * leg1 = new TLegend(0.7,0.9,0.9,0.7);
  TFile *_file0 = TFile::Open("Plot/TRUEnumu_0-10GeV_red_0_CCpure.root");
  TCanvas *c3 = new TCanvas("c3","",1600,1200);
  TH1F *Tres_RMS_numuCC = new TH1F("Tres_RMS_numuCC","",250,0., 200.);
  Tres_RMS_numuCC->GetXaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_numuCC->SetLineWidth(5);
  Tres_RMS_numuCC->SetLineColor(kBlue);
  Tres_RMS_numuCC->SetFillStyle(3345);
  Tres_RMS_numuCC->GetXaxis()->SetRangeUser(40,150);
  Data->Project("Tres_RMS_numuCC","Tres_RMS","trueNPE>1.E5 && trueVradius<16000","");
  c3->cd();
  Tres_RMS_numuCC->Draw();
  leg1->AddEntry(Tres_RMS_numuCC, "#nu_{#mu} CC" ,"l");
  TFile *_file1 = TFile::Open("Plot/TRUEnue_0-10GeV_red_0_CCpure.root");
  TH1F *Tres_RMS_nueCC = new TH1F("Tres_RMS_nueCC","",250,0., 200.);
  Tres_RMS_nueCC->SetLineWidth(5);
  Tres_RMS_nueCC->SetLineColor(kRed);
  Data->Project("Tres_RMS_nueCC","Tres_RMS","trueNPE>1.E5 && trueVradius<16000","");
  Tres_RMS_nueCC->Draw("same");
  leg1->AddEntry(Tres_RMS_nueCC, "#nu_{e} CC" ,"l");
  TFile *_file2 = TFile::Open("Plot/TRUEnue+numu_0-10GeV_red_0_NCpure.root");
  TH1F *Tres_RMS_nuNC = new TH1F("Tres_RMS_nuNC","",250,0., 200.);
  Tres_RMS_nuNC->SetLineWidth(5);
  Tres_RMS_nuNC->SetLineColor(kGreen+3);
  Data->Project("Tres_RMS_nuNC","Tres_RMS","trueNPE>1.E5 && trueVradius<16000","");
  Tres_RMS_nuNC->Draw("same");
  leg1->AddEntry(Tres_RMS_nuNC, "#nu_{e}+#nu_{#mu} NC" ,"l");
  leg1->Draw();

  //gPad->BuildLegend(0.1,0.9,0.6,0.7); 
  c3->SaveAs("Plot/Tres_RMS_nueCC+numuCC+nuCC_0-10GeV_16volcut_purecharge_0_ALL.pdf");
  c3->SaveAs("Plot/Tres_RMS_nueCC+numuCC+nuCC_0-10GeV_16volcut_purecharge_0_ALL.png");
  c3->SaveAs("Plot/Tres_RMS_nueCC+numuCC+nuCC_0-10GeV_16volcut_purecharge_0_ALL.C");

  ////////////////////////////////////////////////////////////////////////////////////////////////

  TLegend * leg2 = new TLegend(0.7,0.9,0.9,0.7);
  TFile *_file6 = TFile::Open("Plot/TRUEnumu_0-10GeV_red_0_CCpure.root");
  TCanvas *c10 = new TCanvas("c10","",1600,1200);
  TH2F *Tres_RMS_VS_Npe_numuCC = new TH2F("Tres_RMS_VS_Npe_numuCC","",100,0.,1.3E7, 100,1., 200.);
  gPad->SetLogx();
  Tres_RMS_VS_Npe_numuCC->GetXaxis()->SetTitle("N_{PE}");
  Tres_RMS_VS_Npe_numuCC->GetYaxis()->SetTitle("#sigma(t_{res}) [ns]");
  Tres_RMS_VS_Npe_numuCC->SetMarkerStyle(6);
  Tres_RMS_VS_Npe_numuCC->SetMarkerColor(kBlue);
  Tres_RMS_VS_Npe_numuCC->SetFillColorAlpha(kBlue, 1.0);
  Data->Project("Tres_RMS_VS_Npe_numuCC","Tres_RMS:trueNPE","trueVradius<16000","");
  c10->cd();
  Tres_RMS_VS_Npe_numuCC->Draw();
  leg2->AddEntry(Tres_RMS_VS_Npe_numuCC, "#nu_{#mu} CC" ,"f");
  TFile *_file1 = TFile::Open("Plot/TRUEnue_0-10GeV_red_0_CCpure.root");
  TH2F *Tres_RMS_VS_Npe_nueCC = new TH2F("Tres_RMS_VS_Npe_nueCC","",100,0.,1.3E7, 100,1., 200.);
  Tres_RMS_VS_Npe_nueCC->SetMarkerStyle(6);
  Tres_RMS_VS_Npe_nueCC->SetMarkerColor(kRed);
  Tres_RMS_VS_Npe_nueCC->SetFillColorAlpha(kRed, 1.0);
  Data->Project("Tres_RMS_VS_Npe_nueCC","Tres_RMS:trueNPE","trueVradius<16000","");
  Tres_RMS_VS_Npe_nueCC->Draw("same");
  leg2->AddEntry(Tres_RMS_VS_Npe_nueCC, "#nu_{e} CC" ,"f");
  TFile *_file2 = TFile::Open("Plot/TRUEnue+numu_0-10GeV_red_0_NCpure.root");
  TH2F *Tres_RMS_VS_Npe_nuNC = new TH2F("Tres_RMS_VS_Npe_nuNC","",100,0.,1.3E7, 100,1., 200.);
  Tres_RMS_VS_Npe_nuNC->SetMarkerStyle(6);
  Tres_RMS_VS_Npe_nuNC->SetMarkerColor(kGreen+3);
  Tres_RMS_VS_Npe_nuNC->SetFillColorAlpha(kGreen+3, 0.3);
  Data->Project("Tres_RMS_VS_Npe_nuNC","Tres_RMS:trueNPE","trueVradius<16000","");
  Tres_RMS_VS_Npe_nuNC->Draw("same");
  leg2->AddEntry(Tres_RMS_VS_Npe_nuNC, "#nu_{e}+#nu_{#mu} NC" ,"f");
  leg2->Draw();

  //gPad->BuildLegend(0.1,0.9,0.6,0.7);                                                                                                                                                                     
  c10->SaveAs("Plot/tres_RMS_VS_Npe_nueCC+numuCC+nuCC_0-10GeV_16volcut_purecharge_0_ALL.pdf");
  c10->SaveAs("Plot/tres_RMS_VS_Npe_nueCC+numuCC+nuCC_0-10GeV_16volcut_purecharge_0_ALL.png");
  c10->SaveAs("Plot/tres_RMS_VS_Npe_nueCC+numuCC+nuCC_0-10GeV_16volcut_purecharge_0_ALL.C");
  */
  /*
  TFile *_file3 = TFile::Open("Plot/TRUEnue_0-10GeV_red_5m_CCpure.root");
  TCanvas *c4 = new TCanvas("c4","",1600,1200);
  TCanvas *c5 = new TCanvas("c5","",1600,1200);
  TH2F *Tres_RMS_shift_VS_vertex_shift_nueCC_h = new TH2F("Tres_RMS_shift_VS_vertex_shift_nueCC_h","",150,0.,22.,150,-7.,20.);
  Tres_RMS_shift_VS_vertex_shift_nueCC_h->GetXaxis()->SetTitle("vertex shift [m]");
  Tres_RMS_shift_VS_vertex_shift_nueCC_h->GetYaxis()->SetTitle("#sigma(t_{res}^{smearV}) - #sigma(t_{res}^{trueV}) [ns]");
  TH2F *Tres_Mean_shift_VS_vertex_shift_nueCC_h = new TH2F("Tres_Mean_shift_VS_vertex_shift_nueCC_h","",150,0.,22.,150,-80.,15.);
  Tres_Mean_shift_VS_vertex_shift_nueCC_h->GetXaxis()->SetTitle("vertex shift [m]");
  Tres_Mean_shift_VS_vertex_shift_nueCC_h->GetYaxis()->SetTitle("< t_{res}^{smearV} > - < t_{res}^{trueV} > [ns]");
  Data->Project("Tres_RMS_shift_VS_vertex_shift_nueCC_h","(Tres_RMS-Tres_RMS_trueV):vertex_shift/1000.","trueNPE>1.E5","");
  Data->Project("Tres_Mean_shift_VS_vertex_shift_nueCC_h","(Tres_Mean-Tres_Mean_trueV):vertex_shift/1000.","trueNPE>1.E5","");
  c4->cd();
  Tres_RMS_shift_VS_vertex_shift_nueCC_h->Draw("colz");
  c4->SaveAs("Plot/Tres_RMS_shift_VS_vertex_shift_nueCC_0-10GeV_16volcut_purecharge_5mV_ALL.pdf");
  c4->SaveAs("Plot/Tres_RMS_shift_VS_vertex_shift_nueCC_0-10GeV_16volcut_purecharge_5mV_ALL.png");
  c4->SaveAs("Plot/Tres_RMS_shift_VS_vertex_shift_nueCC_0-10GeV_16volcut_purecharge_5mV_ALL.C");
  c5->cd();
  Tres_Mean_shift_VS_vertex_shift_nueCC_h->Draw("colz");
  c5->SaveAs("Plot/Tres_Mean_shift_VS_vertex_shift_nueCC_0-10GeV_16volcut_purecharge_5mV_ALL.pdf");
  c5->SaveAs("Plot/Tres_Mean_shift_VS_vertex_shift_nueCC_0-10GeV_16volcut_purecharge_5mV_ALL.png");
  c5->SaveAs("Plot/Tres_Mean_shift_VS_vertex_shift_nueCC_0-10GeV_16volcut_purecharge_5mV_ALL.C");

  //////////////////////////////////////////////////////////////////////////////////////////////////////


  TFile *_file4 = TFile::Open("Plot/TRUEnumu_0-10GeV_red_5m_CCpure.root");
  TCanvas *c6 = new TCanvas("c6","",1600,1200);
  TCanvas *c7 = new TCanvas("c7","",1600,1200);
  TH2F *Tres_RMS_shift_VS_vertex_shift_numuCC_h = new TH2F("Tres_RMS_shift_VS_vertex_shift_numuCC_h","",150,0.,22.,150,-7.,20.);
  Tres_RMS_shift_VS_vertex_shift_numuCC_h->GetXaxis()->SetTitle("vertex shift [m]");
  Tres_RMS_shift_VS_vertex_shift_numuCC_h->GetYaxis()->SetTitle("#sigma(t_{res}^{smearV}) - #sigma(t_{res}^{trueV}) [ns]");
  TH2F *Tres_Mean_shift_VS_vertex_shift_numuCC_h = new TH2F("Tres_Mean_shift_VS_vertex_shift_numuCC_h","",150,0.,22.,150,-80.,15.);
  Tres_Mean_shift_VS_vertex_shift_numuCC_h->GetXaxis()->SetTitle("vertex shift [m]");
  Tres_Mean_shift_VS_vertex_shift_numuCC_h->GetYaxis()->SetTitle("< t_{res}^{smearV} > - < t_{res}^{trueV} > [ns]");
  Data->Project("Tres_RMS_shift_VS_vertex_shift_numuCC_h","(Tres_RMS-Tres_RMS_trueV):vertex_shift/1000.","trueNPE>1.E5","");
  Data->Project("Tres_Mean_shift_VS_vertex_shift_numuCC_h","(Tres_Mean-Tres_Mean_trueV):vertex_shift/1000.","trueNPE>1.E5","");
  c6->cd();
  Tres_RMS_shift_VS_vertex_shift_numuCC_h->Draw("colz");
  c6->SaveAs("Plot/Tres_RMS_shift_VS_vertex_shift_numuCC_0-10GeV_16volcut_purecharge_5mV_ALL.pdf");
  c6->SaveAs("Plot/Tres_RMS_shift_VS_vertex_shift_numuCC_0-10GeV_16volcut_purecharge_5mV_ALL.png");
  c6->SaveAs("Plot/Tres_RMS_shift_VS_vertex_shift_numuCC_0-10GeV_16volcut_purecharge_5mV_ALL.C");
  c7->cd();
  Tres_Mean_shift_VS_vertex_shift_numuCC_h->Draw("colz");
  c7->SaveAs("Plot/Tres_Mean_shift_VS_vertex_shift_numuCC_0-10GeV_16volcut_purecharge_5mV_ALL.pdf");
  c7->SaveAs("Plot/Tres_Mean_shift_VS_vertex_shift_numuCC_0-10GeV_16volcut_purecharge_5mV_ALL.png");
  c7->SaveAs("Plot/Tres_Mean_shift_VS_vertex_shift_numuCC_0-10GeV_16volcut_purecharge_5mV_ALL.C");

  /////////////////////////////////////////////////////////////////////////////////////////////////////////


  TFile *_file5 = TFile::Open("Plot/TRUEnue_0-10GeV_red_5m_NCpure.root");
  TCanvas *c8 = new TCanvas("c8","",1600,1200);
  TCanvas *c9 = new TCanvas("c9","",1600,1200);
  TH2F *Tres_RMS_shift_VS_vertex_shift_nuNC_h = new TH2F("Tres_RMS_shift_VS_vertex_shift_nuNC_h","",150,0.,22.,150,-7.,20.);
  Tres_RMS_shift_VS_vertex_shift_nuNC_h->GetXaxis()->SetTitle("vertex shift [m]");
  Tres_RMS_shift_VS_vertex_shift_nuNC_h->GetYaxis()->SetTitle("#sigma(t_{res}^{smearV}) - #sigma(t_{res}^{trueV}) [ns]");
  TH2F *Tres_Mean_shift_VS_vertex_shift_nuNC_h = new TH2F("Tres_Mean_shift_VS_vertex_shift_nuNC_h","",150,0.,22.,150,-80.,15.);
  Tres_Mean_shift_VS_vertex_shift_nuNC_h->GetXaxis()->SetTitle("vertex shift [m]");
  Tres_Mean_shift_VS_vertex_shift_nuNC_h->GetYaxis()->SetTitle("< t_{res}^{smearV} > - < t_{res}^{trueV} > [ns]");
  Data->Project("Tres_RMS_shift_VS_vertex_shift_nuNC_h","(Tres_RMS-Tres_RMS_trueV):vertex_shift/1000.","trueNPE>1.E5","");
  Data->Project("Tres_Mean_shift_VS_vertex_shift_nuNC_h","(Tres_Mean-Tres_Mean_trueV):vertex_shift/1000.","trueNPE>1.E5","");
  c8->cd();
  Tres_RMS_shift_VS_vertex_shift_nuNC_h->Draw("colz");
  c8->SaveAs("Plot/Tres_RMS_shift_VS_vertex_shift_nuNC_0-10GeV_16volcut_purecharge_5mV_ALL.pdf");
  c8->SaveAs("Plot/Tres_RMS_shift_VS_vertex_shift_nuNC_0-10GeV_16volcut_purecharge_5mV_ALL.png");
  c8->SaveAs("Plot/Tres_RMS_shift_VS_vertex_shift_nuNC_0-10GeV_16volcut_purecharge_5mV_ALL.C");
  c9->cd();
  Tres_Mean_shift_VS_vertex_shift_nuNC_h->Draw("colz");
  c9->SaveAs("Plot/Tres_Mean_shift_VS_vertex_shift_nuNC_0-10GeV_16volcut_purecharge_5mV_ALL.pdf");
  c9->SaveAs("Plot/Tres_Mean_shift_VS_vertex_shift_nuNC_0-10GeV_16volcut_purecharge_5mV_ALL.png");
  c9->SaveAs("Plot/Tres_Mean_shift_VS_vertex_shift_nuNC_0-10GeV_16volcut_purecharge_5mV_ALL.C");
  */
  }
