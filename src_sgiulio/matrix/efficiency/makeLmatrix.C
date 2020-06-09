void makeLmatrix() {
  gStyle->SetOptStat(0);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetPadRightMargin(0.12);
  gStyle->SetTitleH(0.1);
  gStyle->SetTitleW(1.05);

  static const int binsE_nuE = 12;
  static const int binsNPE_nuE = 10;
  static const int binsE_nuMu = 10;
  static const int binsNPE_nuMu = 8;
  static const float lowE_nuE = 2.0;
  static const float lowNPE_nuE = 5.0;
  static const float upE_nuE = 4.2;
  static const float upNPE_nuE = 7.2;
  static const float lowE_nuMu = 2.48;
  static const float lowNPE_nuMu = 5.7;
  static const float upE_nuMu = 4.2;
  static const float upNPE_nuMu = 7.2;

  TCanvas *cc = new TCanvas("cc","",1000,800);
  cc->Divide(2,2);

  TTree *mytree;
  //TFile *_file1 = TFile::Open("/home/sgiulio/Giulio/University/JUNO/juno-unfolding/treemaker/trees/MC_100K_1m_COMPLETE.root");
  TFile *_file1 = TFile::Open("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker/trees/MC_100K_1m_COMPLETE.root");
  _file1->GetObject("Data",mytree);
  //////////////////////////EFF-ELECTRONS-LPMT///////////////////////////////////////////
  TH2F *Npe_VS_Ev_less75_nueCC_CUT = new TH2F("Npe_VS_Ev_less75_nueCC_CUT","",binsE_nuE,lowE_nuE,upE_nuE,binsNPE_nuE,lowNPE_nuE,upNPE_nuE);
  mytree->Project("Npe_VS_Ev_less75_nueCC_CUT","log10(trueNPE_LPMT_CD):log10(nuEnergy)","Tres_RMS<75 && CCint==1 && abs(init_lepID)==11 && newVradius<16000 && trueNPE_LPMT_CD>1.E5 && FC==1","");
  TH2F *Npe_VS_Ev_less75_nueCC_FULL = new TH2F("Npe_VS_Ev_less75_nueCC_FULL","",binsE_nuE,lowE_nuE,upE_nuE,binsNPE_nuE,lowNPE_nuE,upNPE_nuE);
  mytree->Project("Npe_VS_Ev_less75_nueCC_FULL","log10(trueNPE_LPMT_CD):log10(nuEnergy)","CCint==1 && abs(init_lepID)==11 && newVradius<16000 && trueNPE_LPMT_CD>1.E5 && FC==1","");
  TH2F *Npe_VS_Ev_less75_nueCC_EFF = (TH2F*)Npe_VS_Ev_less75_nueCC_CUT->Clone("Npe_VS_Ev_less75_nueCC_EFF");
  Npe_VS_Ev_less75_nueCC_EFF->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_VS_Ev_less75_nueCC_EFF->GetYaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_less75_nueCC_EFF->GetYaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_less75_nueCC_EFF->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_less75_nueCC_EFF->GetXaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_less75_nueCC_EFF->GetXaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_less75_nueCC_EFF->GetZaxis()->SetLabelSize(0.05); 
  Npe_VS_Ev_less75_nueCC_EFF->Divide(Npe_VS_Ev_less75_nueCC_FULL);
  Npe_VS_Ev_less75_nueCC_EFF->SetTitle("#nu_{e}^{CC} efficiency");
  gStyle->SetPalette(kLightTemperature);
  cc->cd(1);
  Npe_VS_Ev_less75_nueCC_EFF->Draw("colz");

  //////////////////////////CONT-ELECTRONS-LPMT///////////////////////////////////////////
  TH2F *Npe_VS_Ev_less75_nueCC_CUT_BKG = new TH2F("Npe_VS_Ev_less75_nueCC_CUT_BKG","",binsE_nuE,lowE_nuE,upE_nuE,binsNPE_nuE,lowNPE_nuE,upNPE_nuE);
  mytree->Project("Npe_VS_Ev_less75_nueCC_CUT_BKG","log10(trueNPE_LPMT_CD):log10(nuEnergy)","Tres_RMS<75 && abs(init_lepID)!=11 && newVradius<16000 && trueNPE_LPMT_CD>1.E5 && FC==1","");
  TH2F *Npe_VS_Ev_less75_nueCC_CUT_ALL = new TH2F("Npe_VS_Ev_less75_nueCC_CUT_ALL","",binsE_nuE,lowE_nuE,upE_nuE,binsNPE_nuE,lowNPE_nuE,upNPE_nuE);
  mytree->Project("Npe_VS_Ev_less75_nueCC_CUT_ALL","log10(trueNPE_LPMT_CD):log10(nuEnergy)","Tres_RMS<75 && newVradius<16000 && trueNPE_LPMT_CD>1.E5 && FC==1","");
  TH2F *Npe_VS_Ev_less75_nueCC_CONT = (TH2F*)Npe_VS_Ev_less75_nueCC_CUT_BKG->Clone("Npe_VS_Ev_less75_nueCC_CONT");
  Npe_VS_Ev_less75_nueCC_CONT->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_VS_Ev_less75_nueCC_CONT->GetYaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_less75_nueCC_CONT->GetYaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_less75_nueCC_CONT->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_less75_nueCC_CONT->GetXaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_less75_nueCC_CONT->GetXaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_less75_nueCC_CONT->GetZaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_less75_nueCC_CONT->Divide(Npe_VS_Ev_less75_nueCC_CUT_ALL);
  Npe_VS_Ev_less75_nueCC_CONT->SetTitle("#nu_{e}^{CC} contamination");
  gStyle->SetPalette(kLightTemperature);
  cc->cd(3);
  Npe_VS_Ev_less75_nueCC_CONT->Draw("colz");
  
  //////////////////////////EFF-MUONS-LPMT///////////////////////////////////////////
  TH2F *Npe_VS_Ev_over95_numuCC_CUT = new TH2F("Npe_VS_Ev_over95_numuCC_CUT","",binsE_nuMu,lowE_nuMu,upE_nuMu,binsNPE_nuMu,lowNPE_nuMu,upNPE_nuMu);
  mytree->Project("Npe_VS_Ev_over95_numuCC_CUT","log10(trueNPE_LPMT_CD):log10(nuEnergy)","Tres_RMS>95 && CCint==1 && abs(init_lepID)==13 && newVradius<16000 && trueNPE_LPMT_CD>5.E5 && FC==1","");
  TH2F *Npe_VS_Ev_over95_numuCC_FULL = new TH2F("Npe_VS_Ev_over95_numuCC_FULL","",binsE_nuMu,lowE_nuMu,upE_nuMu,binsNPE_nuMu,lowNPE_nuMu,upNPE_nuMu);
  mytree->Project("Npe_VS_Ev_over95_numuCC_FULL","log10(trueNPE_LPMT_CD):log10(nuEnergy)","CCint==1 && abs(init_lepID)==13 && newVradius<16000 && trueNPE_LPMT_CD>5.E5 && FC==1","");
  TH2F *Npe_VS_Ev_over95_numuCC_EFF = (TH2F*)Npe_VS_Ev_over95_numuCC_CUT->Clone("Npe_VS_Ev_over95_numuCC_EFF");
  Npe_VS_Ev_over95_numuCC_EFF->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_VS_Ev_over95_numuCC_EFF->GetYaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_over95_numuCC_EFF->GetYaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_over95_numuCC_EFF->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_over95_numuCC_EFF->GetXaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_over95_numuCC_EFF->GetXaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_over95_numuCC_EFF->GetZaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_over95_numuCC_EFF->Divide(Npe_VS_Ev_over95_numuCC_FULL);
  Npe_VS_Ev_over95_numuCC_EFF->SetTitle("#nu_{#mu}^{CC} FC efficiency");
  gStyle->SetPalette(kLightTemperature);
  cc->cd(2);
  Npe_VS_Ev_over95_numuCC_EFF->Draw("colz");

  //////////////////////////CONT-MUONS-LPMT///////////////////////////////////////////
  TH2F *Npe_VS_Ev_over95_numuCC_CUT_BKG = new TH2F("Npe_VS_Ev_over95_numuCC_CUT_BKG","",binsE_nuMu,lowE_nuMu,upE_nuMu,binsNPE_nuMu,lowNPE_nuMu,upNPE_nuMu);
  mytree->Project("Npe_VS_Ev_over95_numuCC_CUT_BKG","log10(trueNPE_LPMT_CD):log10(nuEnergy)","Tres_RMS>95 && abs(init_lepID)!=13 && newVradius<16000 && trueNPE_LPMT_CD>5.E5 && FC==1","");
  TH2F *Npe_VS_Ev_over95_numuCC_CUT_ALL = new TH2F("Npe_VS_Ev_over95_numuCC_CUT_ALL","",binsE_nuMu,lowE_nuMu,upE_nuMu,binsNPE_nuMu,lowNPE_nuMu,upNPE_nuMu);
  mytree->Project("Npe_VS_Ev_over95_numuCC_CUT_ALL","log10(trueNPE_LPMT_CD):log10(nuEnergy)","Tres_RMS>95 && newVradius<16000 && trueNPE_LPMT_CD>5.E5 && FC==1","");
  TH2F *Npe_VS_Ev_over95_numuCC_CONT = (TH2F*)Npe_VS_Ev_over95_numuCC_CUT_BKG->Clone("Npe_VS_Ev_over95_numuCC_CONT");
  Npe_VS_Ev_over95_numuCC_CONT->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_VS_Ev_over95_numuCC_CONT->GetYaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_over95_numuCC_CONT->GetYaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_over95_numuCC_CONT->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV] FC)");
  Npe_VS_Ev_over95_numuCC_CONT->GetXaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_over95_numuCC_CONT->GetXaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_over95_numuCC_CONT->GetZaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_over95_numuCC_CONT->Divide(Npe_VS_Ev_over95_numuCC_CUT_ALL);
  Npe_VS_Ev_over95_numuCC_CONT->SetTitle("#nu_{#mu}^{CC} FC contamination");
  gStyle->SetPalette(kLightTemperature);
  cc->cd(4);
  Npe_VS_Ev_over95_numuCC_CONT->Draw("colz");

  cc->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_16volcut_1m_e-mu_EFF-CONT.png");
  cc->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_16volcut_1m_e-mu_EFF-CONT.pdf");
  cc->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_16volcut_1m_e-mu_EFF-CONT.C");

  //////////////////////////////ABSOLUTE CONTENT/////////////////////////////////////////////////////////////////////

  char* filename1= new char[128];
  sprintf(filename1,"output/sgnmatrix_Nue_%i_%i.txt",binsE_nuE,binsNPE_nuE);
  std::ofstream sgnmatrix_e;
  sgnmatrix_e.open(filename1);
  char* filename2= new char[128];
  sprintf(filename2,"output/sgnmatrix_Numu_%i_%i.txt",binsE_nuMu,binsNPE_nuMu);
  std::ofstream sgnmatrix_mu;
  sgnmatrix_mu.open(filename2);
  char* filename3= new char[128];
  sprintf(filename3,"output/bkgmatrix_Nue_%i_%i.txt",binsE_nuE,binsNPE_nuE);
  std::ofstream bkgmatrix_e;
  bkgmatrix_e.open(filename3);
  char* filename4= new char[128];
  sprintf(filename4,"output/bkgmatrix_Numu_%i_%i.txt",binsE_nuMu,binsNPE_nuMu);
  std::ofstream bkgmatrix_mu;
  bkgmatrix_mu.open(filename4);

  TCanvas *c97 = new TCanvas("c97","",1000,800);
  c97->Divide(2,2);

  //////////////////////////SIGNAL-ELECTRONS-LPMT///////////////////////////////////////////
  TH2F *Npe_VS_Ev_less75_nueCC_SGN = new TH2F("Npe_VS_Ev_less75_nueCC_SGN","",binsE_nuE,lowE_nuE,upE_nuE,binsNPE_nuE,lowNPE_nuE,upNPE_nuE);
  mytree->Project("Npe_VS_Ev_less75_nueCC_SGN","log10(trueNPE_LPMT_CD):log10(nuEnergy)","Tres_RMS<75 && CCint==1 && abs(init_lepID)==11 && newVradius<16000 && trueNPE_LPMT_CD>1.E5 && FC==1","");
  Npe_VS_Ev_less75_nueCC_SGN->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_VS_Ev_less75_nueCC_SGN->GetYaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_less75_nueCC_SGN->GetYaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_less75_nueCC_SGN->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_less75_nueCC_SGN->GetXaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_less75_nueCC_SGN->GetXaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_less75_nueCC_SGN->GetZaxis()->SetLabelSize(0.05); 
  Npe_VS_Ev_less75_nueCC_SGN->SetTitle("#nu_{e}^{CC} signal");
  gStyle->SetPalette(kBird);
  c97->cd(1);
  Npe_VS_Ev_less75_nueCC_SGN->Draw("colz");
  for (int ii=1; ii<=binsE_nuE; ii++) {
    for (int jj=1; jj<=binsNPE_nuE; jj++) {
      std::cout << Npe_VS_Ev_less75_nueCC_SGN->GetBinContent(ii,jj) << "\t";
      sgnmatrix_e << Npe_VS_Ev_less75_nueCC_SGN->GetBinContent(ii,jj) << "\t";
    }
    std::cout<<std::endl;
    sgnmatrix_e << "\n";
  }
  sgnmatrix_e.close();
  std::cout << filename1 << " created" << std::endl;

  //////////////////////////BACKGROUND-ELECTRONS-LPMT///////////////////////////////////////////
  TH2F *Npe_VS_Ev_less75_nueCC_BKG = new TH2F("Npe_VS_Ev_less75_nueCC_BKG","",binsE_nuE,lowE_nuE,upE_nuE,binsNPE_nuE,lowNPE_nuE,upNPE_nuE);
  mytree->Project("Npe_VS_Ev_less75_nueCC_BKG","log10(trueNPE_LPMT_CD):log10(nuEnergy)","Tres_RMS<75 && abs(init_lepID)!=11 && newVradius<16000 && trueNPE_LPMT_CD>1.E5 && FC==1","");
  Npe_VS_Ev_less75_nueCC_BKG->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_VS_Ev_less75_nueCC_BKG->GetYaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_less75_nueCC_BKG->GetYaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_less75_nueCC_BKG->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_less75_nueCC_BKG->GetXaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_less75_nueCC_BKG->GetXaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_less75_nueCC_BKG->GetZaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_less75_nueCC_BKG->SetTitle("#nu_{e}^{CC} background");
  gStyle->SetPalette(kBird);
  c97->cd(3);
  Npe_VS_Ev_less75_nueCC_BKG->Draw("colz");
  for (int ii=1; ii<=binsE_nuE; ii++) {
    for (int jj=1; jj<=binsNPE_nuE; jj++) {
      std::cout << Npe_VS_Ev_less75_nueCC_BKG->GetBinContent(ii,jj) << "\t";
      bkgmatrix_e << Npe_VS_Ev_less75_nueCC_BKG->GetBinContent(ii,jj) << "\t";
    }
    std::cout<<std::endl;
    bkgmatrix_e << "\n";
  }
  bkgmatrix_e.close();
  std::cout << filename3 << " created" << std::endl;  

  //////////////////////////SIGNAL-MUONS-LPMT///////////////////////////////////////////
  TH2F *Npe_VS_Ev_over95_numuCC_SGN = new TH2F("Npe_VS_Ev_over95_numuCC_SGN","",binsE_nuMu,lowE_nuMu,upE_nuMu,binsNPE_nuMu,lowNPE_nuMu,upNPE_nuMu);
  mytree->Project("Npe_VS_Ev_over95_numuCC_SGN","log10(trueNPE_LPMT_CD):log10(nuEnergy)","Tres_RMS>95 && CCint==1 && abs(init_lepID)==13 && newVradius<16000 && trueNPE_LPMT_CD>5.E5 && FC==1","");
  Npe_VS_Ev_over95_numuCC_SGN->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_VS_Ev_over95_numuCC_SGN->GetYaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_over95_numuCC_SGN->GetYaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_over95_numuCC_SGN->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_over95_numuCC_SGN->GetXaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_over95_numuCC_SGN->GetXaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_over95_numuCC_SGN->GetZaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_over95_numuCC_SGN->SetTitle("#nu_{#mu}^{CC} FC signal");
  gStyle->SetPalette(kBird);
  c97->cd(2);
  Npe_VS_Ev_over95_numuCC_SGN->Draw("colz");
  for (int ii=1; ii<=binsE_nuMu; ii++) {
    for (int jj=1; jj<=binsNPE_nuMu; jj++) {
      std::cout << Npe_VS_Ev_over95_numuCC_SGN->GetBinContent(ii,jj) << "\t";
      sgnmatrix_mu << Npe_VS_Ev_over95_numuCC_SGN->GetBinContent(ii,jj) << "\t";
    }
    std::cout<<std::endl;
    sgnmatrix_mu << "\n";
  }
  sgnmatrix_mu.close();
  std::cout << filename2 << " created" << std::endl;

  //////////////////////////BACKGROUND-MUONS-LPMT///////////////////////////////////////////
  TH2F *Npe_VS_Ev_over95_numuCC_BKG = new TH2F("Npe_VS_Ev_over95_numuCC_BKG","",binsE_nuMu,lowE_nuMu,upE_nuMu,binsNPE_nuMu,lowNPE_nuMu,upNPE_nuMu);
  mytree->Project("Npe_VS_Ev_over95_numuCC_BKG","log10(trueNPE_LPMT_CD):log10(nuEnergy)","Tres_RMS>95 && abs(init_lepID)!=13 && newVradius<16000 && trueNPE_LPMT_CD>5.E5 && FC==1","");
  Npe_VS_Ev_over95_numuCC_BKG->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_VS_Ev_over95_numuCC_BKG->GetYaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_over95_numuCC_BKG->GetYaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_over95_numuCC_BKG->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV] FC)");
  Npe_VS_Ev_over95_numuCC_BKG->GetXaxis()->SetTitleSize(0.06);
  Npe_VS_Ev_over95_numuCC_BKG->GetXaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_over95_numuCC_BKG->GetZaxis()->SetLabelSize(0.05);
  Npe_VS_Ev_over95_numuCC_BKG->SetTitle("#nu_{#mu}^{CC} FC background");
  gStyle->SetPalette(kBird);
  c97->cd(4);
  Npe_VS_Ev_over95_numuCC_BKG->Draw("colz");
  for (int ii=1; ii<=binsE_nuMu; ii++) {
    for (int jj=1; jj<=binsNPE_nuMu; jj++) {
      std::cout << Npe_VS_Ev_over95_numuCC_BKG->GetBinContent(ii,jj) << "\t";
      bkgmatrix_mu << Npe_VS_Ev_over95_numuCC_BKG->GetBinContent(ii,jj) << "\t";
    }
    std::cout<<std::endl;
    bkgmatrix_mu << "\n";
  }
  bkgmatrix_mu.close();
  std::cout << filename4 << " created" << std::endl;

  c97->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_16volcut_1m_e-mu_SGN-BKG.png");
  c97->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_16volcut_1m_e-mu_SGN-BKG.pdf");
  c97->SaveAs("Plot/logNPE_VS_logEv_0-20GeV_16volcut_1m_e-mu_SGN-BKG.C");


  //////////////////////////////////////////////////////////1-D//////////////////////////////////////////////////

  char* filenameC1= new char[128];
  sprintf(filenameC1,"output/contarray_Nue_%i.txt",binsE_nuE);
  std::ofstream contarray_e;
  contarray_e.open(filenameC1);
  char* filenameC2= new char[128];
  sprintf(filenameC2,"output/contarray_Numu_%i.txt",binsE_nuMu);
  std::ofstream contarray_mu;
  contarray_mu.open(filenameC2);

  //////////////////////////EFF-ELECTRONS-LPMT///////////////////////////////////////////
  TCanvas *c98 = new TCanvas("c98","",1500,1000);
  c98->Divide(2,2);
  
  TH1F *Ev_less75_nueCC_CUT = new TH1F("Ev_less75_nueCC_CUT","",binsE_nuE,lowE_nuE,upE_nuE);
  mytree->Project("Ev_less75_nueCC_CUT","log10(nuEnergy)","Tres_RMS<75 && CCint==1 && abs(init_lepID)==11 && newVradius<16000 && trueNPE_LPMT_CD>1.E5 && FC==1","");
  TH1F *Ev_less75_nueCC_FULL = new TH1F("Ev_less75_nueCC_FULL","",binsE_nuE,lowE_nuE,upE_nuE);
  mytree->Project("Ev_less75_nueCC_FULL","log10(nuEnergy)","CCint==1 && abs(init_lepID)==11 && newVradius<16000 && trueNPE_LPMT_CD>1.E5 && FC==1","");
  TH1F *Ev_less75_nueCC_EFF = (TH1F*)Ev_less75_nueCC_CUT->Clone("Ev_less75_nueCC_EFF");
  Ev_less75_nueCC_EFF->GetYaxis()->SetTitle("efficiency");
  Ev_less75_nueCC_EFF->GetYaxis()->SetTitleSize(0.06);
  Ev_less75_nueCC_EFF->GetYaxis()->SetLabelSize(0.05);
  Ev_less75_nueCC_EFF->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev_less75_nueCC_EFF->GetXaxis()->SetTitleSize(0.06);
  Ev_less75_nueCC_EFF->GetXaxis()->SetLabelSize(0.05);
  Ev_less75_nueCC_EFF->GetZaxis()->SetLabelSize(0.05); 
  Ev_less75_nueCC_EFF->Divide(Ev_less75_nueCC_FULL);
  Ev_less75_nueCC_EFF->SetTitle("#nu_{e}^{CC} efficiency");
  Ev_less75_nueCC_EFF->SetLineWidth(3);
  c98->cd(1);
  Ev_less75_nueCC_EFF->Draw("colz");

  //////////////////////////CONT-ELECTRONS-LPMT///////////////////////////////////////////
  TH1F *Ev_less75_nueCC_CUT_BKG = new TH1F("Ev_less75_nueCC_CUT_BKG","",binsE_nuE,lowE_nuE,upE_nuE);
  mytree->Project("Ev_less75_nueCC_CUT_BKG","log10(nuEnergy)","Tres_RMS<75 && abs(init_lepID)!=11 && newVradius<16000 && trueNPE_LPMT_CD>1.E5 && FC==1","");
  TH1F *Ev_less75_nueCC_CUT_ALL = new TH1F("Ev_less75_nueCC_CUT_ALL","",binsE_nuE,lowE_nuE,upE_nuE);
  mytree->Project("Ev_less75_nueCC_CUT_ALL","log10(nuEnergy)","Tres_RMS<75 && newVradius<16000 && trueNPE_LPMT_CD>1.E5 && FC==1","");
  TH1F *Ev_less75_nueCC_CONT = (TH1F*)Ev_less75_nueCC_CUT_BKG->Clone("Ev_less75_nueCC_CONT");
  Ev_less75_nueCC_CONT->GetYaxis()->SetTitle("contamination");
  Ev_less75_nueCC_CONT->GetYaxis()->SetTitleSize(0.06);
  Ev_less75_nueCC_CONT->GetYaxis()->SetLabelSize(0.05);
  Ev_less75_nueCC_CONT->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev_less75_nueCC_CONT->GetXaxis()->SetTitleSize(0.06);
  Ev_less75_nueCC_CONT->GetXaxis()->SetLabelSize(0.05);
  Ev_less75_nueCC_CONT->GetZaxis()->SetLabelSize(0.05);
  Ev_less75_nueCC_CONT->Divide(Ev_less75_nueCC_CUT_ALL);
  Ev_less75_nueCC_CONT->SetTitle("#nu_{e}^{CC} contamination");
  Ev_less75_nueCC_CONT->SetLineWidth(3);
  c98->cd(3);
  Ev_less75_nueCC_CONT->Draw("colz");

  for (int ii=1; ii<=binsE_nuE; ii++) {
    std::cout << Ev_less75_nueCC_CONT->GetBinContent(ii) << "\t";
    contarray_e << Ev_less75_nueCC_CONT->GetBinContent(ii) << "\t";
  }
  contarray_e.close();
  std::cout << std::endl << filenameC1 << " created" << std::endl;
  
  //////////////////////////EFF-MUONS-LPMT///////////////////////////////////////////
  TH1F *Ev_over95_numuCC_CUT = new TH1F("Ev_over95_numuCC_CUT","",binsE_nuMu,lowE_nuMu,upE_nuMu);
  mytree->Project("Ev_over95_numuCC_CUT","log10(nuEnergy)","Tres_RMS>95 && CCint==1 && abs(init_lepID)==13 && newVradius<16000 && trueNPE_LPMT_CD>5.E5 && FC==1","");
  TH1F *Ev_over95_numuCC_FULL = new TH1F("Ev_over95_numuCC_FULL","",binsE_nuMu,lowE_nuMu,upE_nuMu);
  mytree->Project("Ev_over95_numuCC_FULL","log10(nuEnergy)","CCint==1 && abs(init_lepID)==13 && newVradius<16000 && trueNPE_LPMT_CD>5.E5 && FC==1","");
  TH1F *Ev_over95_numuCC_EFF = (TH1F*)Ev_over95_numuCC_CUT->Clone("Ev_over95_numuCC_EFF");
  Ev_over95_numuCC_EFF->GetYaxis()->SetTitle("efficiency");
  Ev_over95_numuCC_EFF->GetYaxis()->SetTitleSize(0.06);
  Ev_over95_numuCC_EFF->GetYaxis()->SetLabelSize(0.05);
  Ev_over95_numuCC_EFF->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev_over95_numuCC_EFF->GetXaxis()->SetTitleSize(0.06);
  Ev_over95_numuCC_EFF->GetXaxis()->SetLabelSize(0.05);
  Ev_over95_numuCC_EFF->GetZaxis()->SetLabelSize(0.05);
  Ev_over95_numuCC_EFF->Divide(Ev_over95_numuCC_FULL);
  Ev_over95_numuCC_EFF->SetTitle("#nu_{#mu}^{CC} FC efficiency");
  Ev_over95_numuCC_EFF->SetLineWidth(3);
  c98->cd(2);
  Ev_over95_numuCC_EFF->Draw("colz");

  //////////////////////////CONT-MUONS-LPMT///////////////////////////////////////////
  TH1F *Ev_over95_numuCC_CUT_BKG = new TH1F("Ev_over95_numuCC_CUT_BKG","",binsE_nuMu,lowE_nuMu,upE_nuMu);
  mytree->Project("Ev_over95_numuCC_CUT_BKG","log10(nuEnergy)","Tres_RMS>95 && abs(init_lepID)!=13 && newVradius<16000 && trueNPE_LPMT_CD>5.E5 && FC==1","");
  TH1F *Ev_over95_numuCC_CUT_ALL = new TH1F("Ev_over95_numuCC_CUT_ALL","",binsE_nuMu,lowE_nuMu,upE_nuMu);
  mytree->Project("Ev_over95_numuCC_CUT_ALL","log10(nuEnergy)","Tres_RMS>95 && newVradius<16000 && trueNPE_LPMT_CD>5.E5 && FC==1","");
  TH1F *Ev_over95_numuCC_CONT = (TH1F*)Ev_over95_numuCC_CUT_BKG->Clone("Ev_over95_numuCC_CONT");
  Ev_over95_numuCC_CONT->GetYaxis()->SetTitle("contamination");
  Ev_over95_numuCC_CONT->GetYaxis()->SetTitleSize(0.06);
  Ev_over95_numuCC_CONT->GetYaxis()->SetLabelSize(0.05);
  Ev_over95_numuCC_CONT->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev_over95_numuCC_CONT->GetXaxis()->SetTitleSize(0.06);
  Ev_over95_numuCC_CONT->GetXaxis()->SetLabelSize(0.05);
  Ev_over95_numuCC_CONT->GetZaxis()->SetLabelSize(0.05);
  Ev_over95_numuCC_CONT->Divide(Ev_over95_numuCC_CUT_ALL);
  Ev_over95_numuCC_CONT->SetTitle("#nu_{#mu}^{CC} FC contamination");
  Ev_over95_numuCC_CONT->SetLineWidth(3);
  c98->cd(4);
  Ev_over95_numuCC_CONT->Draw("colz");

  for (int ii=1; ii<=binsE_nuMu; ii++) {
    std::cout << Ev_over95_numuCC_CONT->GetBinContent(ii) << "\t";
    contarray_mu << Ev_over95_numuCC_CONT->GetBinContent(ii) << "\t";
  }
  contarray_mu.close();
  std::cout << std::endl << filenameC2 << " created" << std::endl;

  c98->SaveAs("Plot/logEv_0-20GeV_16volcut_1m_e-mu_EFF-CONT.png");
  c98->SaveAs("Plot/logEv_0-20GeV_16volcut_1m_e-mu_EFF-CONT.pdf");
  c98->SaveAs("Plot/logEv_0-20GeV_16volcut_1m_e-mu_EFF-CONT.C");

  //////////////////////////////ABSOLUTE CONTENT/////////////////////////////////////////////////////////////////////

  char* filename11= new char[128];
  sprintf(filename11,"output/sgnarray_Nue_%i.txt",binsE_nuE);
  std::ofstream sgnarray_e;
  sgnarray_e.open(filename11);
  char* filename12= new char[128];
  sprintf(filename12,"output/sgnarray_Numu_%i.txt",binsE_nuMu);
  std::ofstream sgnarray_mu;
  sgnarray_mu.open(filename12);
  char* filename13= new char[128];
  sprintf(filename13,"output/bkgarray_Nue_%i.txt",binsE_nuE);
  std::ofstream bkgarray_e;
  bkgarray_e.open(filename13);
  char* filename14= new char[128];
  sprintf(filename14,"output/bkgarray_Numu_%i.txt",binsE_nuMu);
  std::ofstream bkgarray_mu;
  bkgarray_mu.open(filename14);

  //////////////////////////SIGNAL-ELECTRONS-LPMT///////////////////////////////////////////
  TCanvas *c95 = new TCanvas("c95","",1500,1000);
  c95->Divide(2,2);
  
  TH1F *Ev_less75_nueCC_SGN = new TH1F("Ev_less75_nueCC_SGN","",binsE_nuE,lowE_nuE,upE_nuE);
  mytree->Project("Ev_less75_nueCC_SGN","log10(nuEnergy)","Tres_RMS<75 && CCint==1 && abs(init_lepID)==11 && newVradius<16000 && trueNPE_LPMT_CD>1.E5 && FC==1","");
  Ev_less75_nueCC_SGN->GetYaxis()->SetTitle("entries");
  Ev_less75_nueCC_SGN->GetYaxis()->SetTitleSize(0.06);
  Ev_less75_nueCC_SGN->GetYaxis()->SetLabelSize(0.05);
  Ev_less75_nueCC_SGN->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev_less75_nueCC_SGN->GetXaxis()->SetTitleSize(0.06);
  Ev_less75_nueCC_SGN->GetXaxis()->SetLabelSize(0.05);
  Ev_less75_nueCC_SGN->GetZaxis()->SetLabelSize(0.05); 
  Ev_less75_nueCC_SGN->SetTitle("#nu_{e}^{CC} signal");
  Ev_less75_nueCC_SGN->SetLineWidth(3);
  c95->cd(1);
  Ev_less75_nueCC_SGN->Draw("colz");
  for (int ii=1; ii<=binsE_nuE; ii++) {
      std::cout << Ev_less75_nueCC_SGN->GetBinContent(ii) << "\t";
      sgnarray_e << Ev_less75_nueCC_SGN->GetBinContent(ii) << "\t";
  }
    std::cout<<std::endl;
    sgnarray_e.close();
    std::cout << filename11 << " created" << std::endl;

  //////////////////////////BACKGROUND-ELECTRONS-LPMT///////////////////////////////////////////
  TH1F *Ev_less75_nueCC_BKG = new TH1F("Ev_less75_nueCC_BKG","",binsE_nuE,lowE_nuE,upE_nuE);
  mytree->Project("Ev_less75_nueCC_BKG","log10(nuEnergy)","Tres_RMS<75 && abs(init_lepID)!=11 && newVradius<16000 && trueNPE_LPMT_CD>1.E5 && FC==1","");
  Ev_less75_nueCC_BKG->GetYaxis()->SetTitle("entries");
  Ev_less75_nueCC_BKG->GetYaxis()->SetTitleSize(0.06);
  Ev_less75_nueCC_BKG->GetYaxis()->SetLabelSize(0.05);
  Ev_less75_nueCC_BKG->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev_less75_nueCC_BKG->GetXaxis()->SetTitleSize(0.06);
  Ev_less75_nueCC_BKG->GetXaxis()->SetLabelSize(0.05);
  Ev_less75_nueCC_BKG->GetZaxis()->SetLabelSize(0.05);
  Ev_less75_nueCC_BKG->SetTitle("#nu_{e}^{CC} background");
  Ev_less75_nueCC_BKG->SetLineWidth(3);
  c95->cd(3);
  Ev_less75_nueCC_BKG->Draw("colz");
  for (int ii=1; ii<=binsE_nuE; ii++) {
    std::cout << Ev_less75_nueCC_BKG->GetBinContent(ii) << "\t";
    bkgarray_e << Ev_less75_nueCC_BKG->GetBinContent(ii) << "\t";
  }
  std::cout<<std::endl;
  bkgarray_e.close();
  std::cout << filename13 << " created" << std::endl;
  
  //////////////////////////SIGNAL-MUONS-LPMT///////////////////////////////////////////
  TH1F *Ev_over95_numuCC_SGN = new TH1F("Ev_over95_numuCC_SGN","",binsE_nuMu,lowE_nuMu,upE_nuMu);
  mytree->Project("Ev_over95_numuCC_SGN","log10(nuEnergy)","Tres_RMS>95 && CCint==1 && abs(init_lepID)==13 && newVradius<16000 && trueNPE_LPMT_CD>5.E5 && FC==1","");
  Ev_over95_numuCC_SGN->GetYaxis()->SetTitle("entries");
  Ev_over95_numuCC_SGN->GetYaxis()->SetTitleSize(0.06);
  Ev_over95_numuCC_SGN->GetYaxis()->SetLabelSize(0.05);
  Ev_over95_numuCC_SGN->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev_over95_numuCC_SGN->GetXaxis()->SetTitleSize(0.06);
  Ev_over95_numuCC_SGN->GetXaxis()->SetLabelSize(0.05);
  Ev_over95_numuCC_SGN->GetZaxis()->SetLabelSize(0.05);
  Ev_over95_numuCC_SGN->SetTitle("#nu_{#mu}^{CC} FC signal");
  Ev_over95_numuCC_SGN->SetLineWidth(3);
  c95->cd(2);
  Ev_over95_numuCC_SGN->Draw("colz");
  for (int ii=1; ii<=binsE_nuMu; ii++) {
    std::cout << Ev_over95_numuCC_SGN->GetBinContent(ii) << "\t";
    sgnarray_mu << Ev_over95_numuCC_SGN->GetBinContent(ii) << "\t";
  }
  std::cout<<std::endl;
  sgnarray_mu.close();
  std::cout << filename12 << " created" << std::endl;

  //////////////////////////BACKGROUND-MUONS-LPMT///////////////////////////////////////////
  TH1F *Ev_over95_numuCC_BKG = new TH1F("Ev_over95_numuCC_BKG","",binsE_nuMu,lowE_nuMu,upE_nuMu);
  mytree->Project("Ev_over95_numuCC_BKG","log10(nuEnergy)","Tres_RMS>95 && abs(init_lepID)!=13 && newVradius<16000 && trueNPE_LPMT_CD>5.E5 && FC==1","");
  Ev_over95_numuCC_BKG->GetYaxis()->SetTitle("entries");
  Ev_over95_numuCC_BKG->GetYaxis()->SetTitleSize(0.06);
  Ev_over95_numuCC_BKG->GetYaxis()->SetLabelSize(0.05);
  Ev_over95_numuCC_BKG->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev_over95_numuCC_BKG->GetXaxis()->SetTitleSize(0.06);
  Ev_over95_numuCC_BKG->GetXaxis()->SetLabelSize(0.05);
  Ev_over95_numuCC_BKG->GetZaxis()->SetLabelSize(0.05);
  Ev_over95_numuCC_BKG->SetTitle("#nu_{#mu}^{CC} FC background");
  Ev_over95_numuCC_BKG->SetLineWidth(3);
  c95->cd(4);
  Ev_over95_numuCC_BKG->Draw("colz");
  for (int ii=1; ii<=binsE_nuMu; ii++) {
    std::cout << Ev_over95_numuCC_BKG->GetBinContent(ii) << "\t";
    bkgarray_mu << Ev_over95_numuCC_BKG->GetBinContent(ii) << "\t";
  }
  std::cout<<std::endl;
  bkgarray_mu.close();
  std::cout << filename14 << " created" << std::endl;

  c95->SaveAs("Plot/logEv_0-20GeV_16volcut_1m_e-mu_SGN-BKG.png");
  c95->SaveAs("Plot/logEv_0-20GeV_16volcut_1m_e-mu_SGN-BKG.pdf");
  c95->SaveAs("Plot/logEv_0-20GeV_16volcut_1m_e-mu_SGN-BKG.C");


}
