void makeplots_trueenergy() {
  gStyle->SetOptStat(0);
  gStyle->SetPadBottomMargin(0.12);
  gStyle->SetTitleH(0.1);
  gStyle->SetTitleW(1.05);
  //gStyle->SetOptTitle(0);

  static const int NBINS = 20;
  
  TTree *mytree;
  //TFile *_file1 = TFile::Open("/home/sgiulio/Giulio/University/JUNO/Work/Atmo/atmo_nuall_LS_0-20GeV_1M.1.gst.root");
  TFile *_file1 = TFile::Open("/storage/DATA-02/juno/Prod/GENIE-2_12_10/atmo_nuall_LS_0-20GeV_1M.1.gst.root");
  _file1->GetObject("gst",mytree);

  /////////////////////////LOGPLOTS//////////////////////////////////////////

  TCanvas *c81 = new TCanvas("c81","",1000,600);
  TLegend * leg81 = new TLegend(0.5,0.3,0.6,0.15);
  c81->cd();
  TH1F *LogTrueE_nue = new TH1F("LogTrueE_nue","",NBINS,2.0,4.25);
  gPad->SetLogy();
  LogTrueE_nue->GetXaxis()->SetTitle("log_{10} (True Energy [MeV])");
  LogTrueE_nue->GetYaxis()->SetTitle("entries");
  LogTrueE_nue->GetXaxis()->SetTitleSize(0.05);
  LogTrueE_nue->GetXaxis()->SetLabelSize(0.05);
  LogTrueE_nue->GetYaxis()->SetLabelSize(0.05);
  LogTrueE_nue->GetYaxis()->SetTitleOffset(1.2);
  LogTrueE_nue->SetLineWidth(5);
  LogTrueE_nue->SetLineColor(kRed);
  mytree->Project("LogTrueE_nue","log10(Ev*1000.)","abs(neu)==12","");
  TH1F *LogTrueE_numu = new TH1F("LogTrueE_numu","",NBINS,2.0,4.25);
  LogTrueE_numu->GetXaxis()->SetTitle("log_{10} (True Energy [MeV])");
  LogTrueE_numu->GetYaxis()->SetTitle("entries");
  LogTrueE_numu->GetXaxis()->SetTitleSize(0.05);
  LogTrueE_numu->GetXaxis()->SetLabelSize(0.05);
  LogTrueE_numu->GetYaxis()->SetLabelSize(0.05);
  LogTrueE_numu->GetYaxis()->SetTitleOffset(1.2);
  LogTrueE_numu->SetLineWidth(5);
  LogTrueE_numu->SetLineColor(kBlue+2);
  mytree->Project("LogTrueE_numu","log10(Ev*1000.)","abs(neu)==14","");
  LogTrueE_numu->Draw();
  LogTrueE_nue->Draw("same");
  leg81->AddEntry(LogTrueE_numu, "#nu_{#mu}" ,"l");
  leg81->AddEntry(LogTrueE_nue, "#nu_{e}" ,"l");
  leg81->Draw();

  c81->SaveAs("Plot/GENIE_logtrueEnergy.png");
  c81->SaveAs("Plot/GENIE_logtrueEnergy.pdf");
  c81->SaveAs("Plot/GENIE_logtrueEnergy.C");

  ///////////////////////////////////////////////////////////////////////

  TCanvas *c19 = new TCanvas("c19","",1000,600);
  float Ebins[NBINS] = {0.};
  float numuval[NBINS] = {0.};
  float nueval[NBINS] = {0.};

  for(int k=0; k<NBINS; k++) {
    Ebins[k] = LogTrueE_numu->GetBinCenter(k+1);
    numuval[k] = (LogTrueE_numu->GetBinContent(k+1))*pow(LogTrueE_numu->GetBinCenter(k+1),2.0);;
    nueval[k] = (LogTrueE_nue->GetBinContent(k+1))*pow(LogTrueE_nue->GetBinCenter(k+1),2.0);
  }
  
  TGraph *NuMu = new TGraph(NBINS,Ebins,numuval);
  TGraph *NuE = new TGraph(NBINS,Ebins,nueval);

  NuMu->GetXaxis()->SetTitle("log_{10} (True Energy [MeV])");
  NuMu->GetYaxis()->SetTitle("E^{2} #Phi");
  NuMu->SetLineColor(kRed);
  NuMu->SetLineWidth(3);
  NuE->SetLineColor(kBlue);
  NuE->SetLineWidth(3);
  c19->cd();
  gPad->SetLogy();
  NuMu->Draw("AL");
  NuE->Draw("L");
  
}

