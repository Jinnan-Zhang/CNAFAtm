void makeROC() {
  gStyle->SetOptStat(0);
  gStyle->SetPadBottomMargin(0.08);
  gStyle->SetPadTopMargin(0.08);
  gStyle->SetPadLeftMargin(0.1);
  gStyle->SetPadRightMargin(0.08);
  //gStyle->SetTitleH(0.1);
  //gStyle->SetTitleW(1.05);
  gStyle->SetOptTitle(0);                                                                                                                                                            

  static const int NBINS = 1000; 
  static const float TRES_MIN = 60.;
  static const float TRES_MAX = 300.;
  static const float TRES_MAX2 = 280.;

  TTree *mytree;
  TFile *_file1 = TFile::Open("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker/trees/MC_500K_1m_TOT.root");
  _file1->GetObject("Data",mytree);

  /////////////////////////////NUECC//////////////////////////////////////////////////////////////

  TH1F *Tres_nueCC_all = new TH1F("Tres_nueCC_all","",NBINS,0.,400.);
  TH1F *Tres_nueCC_fid = new TH1F("Tres_nueCC_fid","",NBINS,0.,400.);
  TH1F *Tres_nueCC = new TH1F("Tres_nueCC","",NBINS,TRES_MIN,TRES_MAX);
  TH1F *Tres_bkg = new TH1F("Tres_bkg","",NBINS,TRES_MIN,TRES_MAX);

  mytree->Project("Tres_nueCC","Tres_RMS","CCint==1 && abs(init_lepID)==11 && trueNPE_LPMT_CD>1.E5 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  mytree->Project("Tres_bkg","Tres_RMS","abs(init_lepID)!=11 && trueNPE_LPMT_CD>1.E5 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  Int_t norm_all = mytree->Project("Tres_nueCC_all","Tres_RMS","CCint==1 && abs(init_lepID)==11","");
  Int_t norm_fid = mytree->Project("Tres_nueCC_fid","Tres_RMS","CCint==1 && abs(init_lepID)==11 && trueNPE_LPMT_CD>1.E5 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  std::cout<<"fiducial cut efficiency is "<<100.*(float(norm_fid)/float(norm_all))<<"%"<<std::endl;

  TH1F *Tres_nueCC_cumul = (TH1F*)Tres_nueCC->GetCumulative(kTRUE);
  TH1F *Tres_bkg_cumul = (TH1F*)Tres_bkg->GetCumulative(kTRUE);
  Float_t efficiency_nueCC[NBINS] = {0.};
  Float_t contamination_nueCC[NBINS] = {0.};
  Float_t revcontamination_nueCC[NBINS] = {0.};
  Float_t tres_value_nueCC[NBINS] = {0.};

  for(int i=1; i<NBINS+1; i++) {
    tres_value_nueCC[i-1] = (TRES_MIN+(((TRES_MAX-TRES_MIN)/NBINS)*(i-1)));
    efficiency_nueCC[i-1] = ((Tres_nueCC_cumul->GetBinContent(i))/float(norm_fid));
    if((Tres_nueCC_cumul->GetBinContent(i))==0) {
      contamination_nueCC[i-1] = 1.;      
      revcontamination_nueCC[i-1] = 0.;
    } else {
      contamination_nueCC[i-1] = ((Tres_bkg_cumul->GetBinContent(i))/((Tres_bkg_cumul->GetBinContent(i))+(Tres_nueCC_cumul->GetBinContent(i))));
      revcontamination_nueCC[i-1] = (1.-((Tres_bkg_cumul->GetBinContent(i))/((Tres_bkg_cumul->GetBinContent(i))+(Tres_nueCC_cumul->GetBinContent(i)))));
    }
    //std::cout<<"cut: "<<tres_value_nueCC[i-1]<<"\t"<<"E: "<<efficiency_nueCC[i-1]<<"\t"<<"C: "<<revcontamination_nueCC[i-1]<<std::endl;
  }

  TGraph *ROC_NUECC = new TGraph(NBINS,revcontamination_nueCC,efficiency_nueCC);
  ROC_NUECC->SetMarkerStyle(20);
  ROC_NUECC->SetMarkerSize(0.65);
  ROC_NUECC->SetMarkerColor(kRed);
  ROC_NUECC->GetXaxis()->SetTitle("1 - contamination");
  ROC_NUECC->GetYaxis()->SetTitle("efficiency");
  TCanvas *cRoc_NueCC = new TCanvas("cRoc_NueCC","ROC_NUECC Curve",0,0,800,700);
  cRoc_NueCC->cd();
  ROC_NUECC->Draw("AP");
  cRoc_NueCC->SaveAs("Plot/ROC_nueCC.pdf");
  cRoc_NueCC->SaveAs("Plot/ROC_nueCC.png");
  TLegend * leg1 = new TLegend(0.6,0.2,0.9,0.4);
  TGraph *Eff_NUECC = new TGraph(NBINS,tres_value_nueCC,efficiency_nueCC);
  Eff_NUECC->SetMarkerStyle(20);
  Eff_NUECC->SetMarkerSize(0.65);
  Eff_NUECC->SetLineWidth(5);
  Eff_NUECC->SetLineColor(kMagenta);
  //Eff_NUECC->GetYaxis()->SetTitle("efficiency");
  Eff_NUECC->GetXaxis()->SetTitle("#sigma(t_{RES})");
  TGraph *Cont_NUECC = new TGraph(NBINS,tres_value_nueCC,contamination_nueCC);
  Cont_NUECC->SetMarkerStyle(20);
  Cont_NUECC->SetMarkerSize(0.65);
  Cont_NUECC->SetLineWidth(5);
  Cont_NUECC->SetLineColor(kGreen+3);
  //Cont_NUECC->GetYaxis()->SetTitle("contamination");
  Cont_NUECC->GetXaxis()->SetTitle("#sigma(t_{RES})");
  TCanvas *cEff_Cont_NueCC = new TCanvas("cEff_Cont_NueCC","Efficiency - Contamination curves",0,0,1000,800);
  cEff_Cont_NueCC->cd();
  Eff_NUECC->Draw("AL");
  leg1->AddEntry(Eff_NUECC, "efficiency" ,"l");
  Cont_NUECC->Draw("same");
  leg1->AddEntry(Cont_NUECC, "contamination" ,"l");
  leg1->Draw();
  cEff_Cont_NueCC->SaveAs("Plot/Eff-Cont_VS_tres_nueCC.pdf");
  cEff_Cont_NueCC->SaveAs("Plot/Eff-Cont_VS_tres_nueCC.png");



  /////////////////////////////NUMUCC//////////////////////////////////////////////////////////////                                                                                      

  TH1F *Tres_numuCC_all = new TH1F("Tres_numuCC_all","",NBINS,0.,400.);
  TH1F *Tres_numuCC_fid = new TH1F("Tres_numuCC_fid","",NBINS,0.,400.);
  TH1F *Tres_numuCC = new TH1F("Tres_numuCC","",NBINS,TRES_MIN,TRES_MAX2);
  TH1F *Tres_bkg2 = new TH1F("Tres_bkg2","",NBINS,TRES_MIN,TRES_MAX2);

  mytree->Project("Tres_numuCC","Tres_RMS","CCint==1 && abs(init_lepID)==13 && trueNPE_LPMT_CD>5.E5 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  mytree->Project("Tres_bkg2","Tres_RMS","abs(init_lepID)!=13 && trueNPE_LPMT_CD>5.E5 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  norm_all = mytree->Project("Tres_numuCC_all","Tres_RMS","CCint==1 && abs(init_lepID)==13","");
  norm_fid = mytree->Project("Tres_numuCC_fid","Tres_RMS","CCint==1 && abs(init_lepID)==13 && trueNPE_LPMT_CD>5.E5 && newVradius<16000. && trueNPE_LPMT_WP<60.","");
  std::cout<<std::endl<<"fiducial cut efficiency is "<<100.*(float(norm_fid)/float(norm_all))<<"%"<<std::endl;

  TH1F *Tres_numuCC_cumul = (TH1F*)Tres_numuCC->GetCumulative(kFALSE);
  TH1F *Tres_bkg2_cumul = (TH1F*)Tres_bkg2->GetCumulative(kFALSE);
  Float_t efficiency_numuCC[NBINS] = {0.};
  Float_t contamination_numuCC[NBINS] = {0.};
  Float_t revcontamination_numuCC[NBINS] = {0.};
  Float_t tres_value_numuCC[NBINS] = {0.};

  for(int i=1; i<NBINS+1; i++) {
    tres_value_numuCC[i-1] = (TRES_MIN+(((TRES_MAX2-TRES_MIN)/NBINS)*(i-1)));
    efficiency_numuCC[i-1] = ((Tres_numuCC_cumul->GetBinContent(i))/float(norm_fid));
    if((Tres_numuCC_cumul->GetBinContent(i))==0) {
      contamination_numuCC[i-1] = 1.;
      revcontamination_numuCC[i-1] = 0.;
    } else {
      contamination_numuCC[i-1] = ((Tres_bkg2_cumul->GetBinContent(i))/((Tres_bkg2_cumul->GetBinContent(i))+(Tres_numuCC_cumul->GetBinContent(i))));
      revcontamination_numuCC[i-1] = (1.-((Tres_bkg2_cumul->GetBinContent(i))/((Tres_bkg2_cumul->GetBinContent(i))+(Tres_numuCC_cumul->GetBinContent(i)))));
    }
    //std::cout<<"cut: "<<tres_value_numuCC[i-1]<<"\t"<<"E: "<<efficiency_numuCC[i-1]<<"\t"<<"C: "<<revcontamination_numuCC[i-1]<<std::endl;                                                                                                                  
  }

  TGraph *ROC_NUMUCC = new TGraph(NBINS,revcontamination_numuCC,efficiency_numuCC);
  ROC_NUMUCC->SetMarkerStyle(20);
  ROC_NUMUCC->SetMarkerSize(0.65);
  ROC_NUMUCC->SetMarkerColor(kBlue+2);
  ROC_NUMUCC->GetXaxis()->SetTitle("1 - contamination");
  ROC_NUMUCC->GetYaxis()->SetTitle("efficiency");
  TCanvas *cRoc_NumuCC = new TCanvas("cRoc_NumuCC","ROC_NUMUCC Curve",0,0,800,700);
  cRoc_NumuCC->cd();
  ROC_NUMUCC->Draw("AP");
  cRoc_NumuCC->SaveAs("Plot/ROC_numuCC.pdf");
  cRoc_NumuCC->SaveAs("Plot/ROC_numuCC.png");
  TLegend * leg2 = new TLegend(0.6,0.25,0.9,0.45);
  TGraph *Eff_NUMUCC = new TGraph(NBINS,tres_value_numuCC,efficiency_numuCC);
  Eff_NUMUCC->SetMarkerStyle(20);
  Eff_NUMUCC->SetMarkerSize(0.65);
  Eff_NUMUCC->SetLineWidth(5);
  Eff_NUMUCC->SetLineColor(kMagenta);
  //Eff_NUMUCC->GetYaxis()->SetTitle("efficiency");
  Eff_NUMUCC->GetXaxis()->SetTitle("#sigma(t_{RES})");
  TGraph *Cont_NUMUCC = new TGraph(NBINS,tres_value_numuCC,contamination_numuCC);
  Cont_NUMUCC->SetMarkerStyle(20);
  Cont_NUMUCC->SetMarkerSize(0.65);
  Cont_NUMUCC->SetLineWidth(5);
  Cont_NUMUCC->SetLineColor(kGreen+3);
  //Cont_NUMUCC->GetYaxis()->SetTitle("contamination");
  Cont_NUMUCC->GetXaxis()->SetTitle("#sigma(t_{RES})");
  TCanvas *cEff_Cont_NumuCC = new TCanvas("cEff_Cont_NumuCC","Efficiency - Contamination curves",0,0,1000,800);
  cEff_Cont_NumuCC->cd();
  Eff_NUMUCC->Draw("AL");
  leg2->AddEntry(Eff_NUMUCC, "efficiency" ,"l");
  Cont_NUMUCC->Draw("same");
  leg2->AddEntry(Cont_NUMUCC, "contamination" ,"l");
  leg2->Draw();
  cEff_Cont_NumuCC->SaveAs("Plot/Eff-Cont_VS_tres_numuCC.pdf");
  cEff_Cont_NumuCC->SaveAs("Plot/Eff-Cont_VS_tres_numuCC.png");


}
