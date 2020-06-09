void makecombinedmatrix() {
  gStyle->SetOptStat(0);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetPadRightMargin(0.12);
  //gStyle->SetTitleH(0.1);
  //gStyle->SetTitleW(1.05);

  static const int binsE_nuE = 12;
  static const int binsNPE_nuE = 10;
  //static const int binsE_nuMu = 10;
  static const int binsE_nuMu = 12;
  static const int binsNPE_nuMu = 8;
  static const float lowE_nuE = 2.0;
  static const float lowNPE_nuE = 5.0;
  static const float upE_nuE = 4.2;
  static const float upNPE_nuE = 7.2;
  //static const float lowE_nuMu = 2.48;
  static const float lowE_nuMu = 2.0;
  static const float lowNPE_nuMu = 5.7;
  static const float upE_nuMu = 4.2;
  static const float upNPE_nuMu = 7.2;

  TTree *mytree;
  //TFile *_file1 = TFile::Open("/home/sgiulio/Giulio/University/JUNO/juno-unfolding/treemaker/trees/MC_100K_1m_SHORT.root");
  //TFile *_file1 = TFile::Open("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker/trees/MC_100K_1m_SHORT.root");
  TFile *_file1 = TFile::Open("/home/settanta/Documents/JUNO/Work/Atmo/analysis/unfolding/treemaker/trees/MC_100K_1m_SHORT.root");
  _file1->GetObject("Data",mytree);


  //////////////////////////////CC+NC/////////////////////////////////////////////////////////////////////

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

  TCanvas *cg = new TCanvas("cg","",1000,800);
  cg->Divide(2,2);
  
  TH2F *NPE_VS_Ev_less75_nueALL = new TH2F("NPE_VS_Ev_less75_nueALL","",binsE_nuE,lowE_nuE,upE_nuE,binsNPE_nuE,lowNPE_nuE,upNPE_nuE);
  mytree->Project("NPE_VS_Ev_less75_nueALL","log10(trueNPE_LPMT_CD):log10(nuEnergy)","((CCint==1 && abs(init_lepID)==11) || (NCint==1 && abs(init_lepID)==12)) && Tres_RMS<75. && newVradius<16000. && trueNPE_LPMT_CD>1.E5 && FC==1","");
  NPE_VS_Ev_less75_nueALL->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  NPE_VS_Ev_less75_nueALL->GetYaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_less75_nueALL->GetYaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_less75_nueALL->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  NPE_VS_Ev_less75_nueALL->GetXaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_less75_nueALL->GetXaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_less75_nueALL->GetZaxis()->SetLabelSize(0.05); 
  NPE_VS_Ev_less75_nueALL->SetTitle("#nu_{e} #sigma(t_{RES}) < 75 ns");
  gStyle->SetPalette(kBird);
  cg->cd(1);
  NPE_VS_Ev_less75_nueALL->Draw("colz");
  /*
  for (int ii=1; ii<=binsE_nuE; ii++) {
    for (int jj=1; jj<=binsNPE_nuE; jj++) {
      std::cout << NPE_VS_Ev_less75_nueCC->GetBinContent(ii,jj) << "\t";
      sgnmatrix_e << NPE_VS_Ev_less75_nueCC->GetBinContent(ii,jj) << "\t";
    }
    std::cout<<std::endl;
    sgnmatrix_e << "\n";
  }
  sgnmatrix_e.close();
  std::cout << filename1 << " created" << std::endl;
  */

  TH2F *NPE_VS_Ev_over95_nueALL = new TH2F("NPE_VS_Ev_over95_nueALL","",binsE_nuMu,lowE_nuMu,upE_nuMu,binsNPE_nuMu,lowNPE_nuMu,upNPE_nuMu);
  mytree->Project("NPE_VS_Ev_over95_nueALL","log10(trueNPE_LPMT_CD):log10(nuEnergy)","((CCint==1 && abs(init_lepID)==11) || (NCint==1 && abs(init_lepID)==12)) && Tres_RMS>95. && newVradius<16000. && trueNPE_LPMT_CD>5.E5 && FC==1","");
  NPE_VS_Ev_over95_nueALL->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  NPE_VS_Ev_over95_nueALL->GetYaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_over95_nueALL->GetYaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_over95_nueALL->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  NPE_VS_Ev_over95_nueALL->GetXaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_over95_nueALL->GetXaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_over95_nueALL->GetZaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_over95_nueALL->SetTitle("#nu_{e} #sigma(t_{RES}) > 95 ns");
  gStyle->SetPalette(kBird);
  cg->cd(2);
  NPE_VS_Ev_over95_nueALL->Draw("colz");


  TH2F *NPE_VS_Ev_less75_numuALL = new TH2F("NPE_VS_Ev_less75_numuALL","",binsE_nuE,lowE_nuE,upE_nuE,binsNPE_nuE,lowNPE_nuE,upNPE_nuE);
  mytree->Project("NPE_VS_Ev_less75_numuALL","log10(trueNPE_LPMT_CD):log10(nuEnergy)","((CCint==1 && abs(init_lepID)==13) || (NCint==1 && abs(init_lepID)==14)) && Tres_RMS<75. && newVradius<16000. && trueNPE_LPMT_CD>1.E5 && FC==1","");
  NPE_VS_Ev_less75_numuALL->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  NPE_VS_Ev_less75_numuALL->GetYaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_less75_numuALL->GetYaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_less75_numuALL->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  NPE_VS_Ev_less75_numuALL->GetXaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_less75_numuALL->GetXaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_less75_numuALL->GetZaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_less75_numuALL->SetTitle("#nu_{#mu} #sigma(t_{RES}) < 75 ns");
  gStyle->SetPalette(kBird);
  cg->cd(3);
  NPE_VS_Ev_less75_numuALL->Draw("colz");

  
  TH2F *NPE_VS_Ev_over95_numuALL = new TH2F("NPE_VS_Ev_over95_numuALL","",binsE_nuMu,lowE_nuMu,upE_nuMu,binsNPE_nuMu,lowNPE_nuMu,upNPE_nuMu);
  mytree->Project("NPE_VS_Ev_over95_numuALL","log10(trueNPE_LPMT_CD):log10(nuEnergy)","((CCint==1 && abs(init_lepID)==13) || (NCint==1 && abs(init_lepID)==14)) && Tres_RMS>95. && newVradius<16000. && trueNPE_LPMT_CD>5.E5 && FC==1","");
  NPE_VS_Ev_over95_numuALL->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  NPE_VS_Ev_over95_numuALL->GetYaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_over95_numuALL->GetYaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_over95_numuALL->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  NPE_VS_Ev_over95_numuALL->GetXaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_over95_numuALL->GetXaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_over95_numuALL->GetZaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_over95_numuALL->SetTitle("#nu_{#mu} #sigma(t_{RES}) > 95 ns");
  gStyle->SetPalette(kBird);
  cg->cd(4);
  NPE_VS_Ev_over95_numuALL->Draw("colz");


  //Arrays
  Float_t E_bins[binsE_nuE+binsE_nuMu+1];
  Float_t NPE_bins[binsNPE_nuE+binsNPE_nuMu+1];

  for(int ii=0; ii<binsE_nuE+binsE_nuMu+1; ii++) {
    E_bins[ii] = float(ii);
  }
  for(int jj=0; jj<=binsNPE_nuE+binsNPE_nuMu+1; jj++) {
    NPE_bins[jj] = float(jj);
  }

  TCanvas *call = new TCanvas("call","",1000,800);
  TPaveText *pt1 = new TPaveText(5.0,-3.2,7.0,-1.2);
  TPaveText *pt2 = new TPaveText(17.0,-3.2,19.0,-1.2);
  TText *t1 = new TText(-1.5,5.0,"< 75 ns");
  t1->SetTextSize(0.05);
  t1->SetTextAngle(90);
  TText *t2 = new TText(-1.5,12.0,"> 95 ns");
  t2->SetTextSize(0.05);
  t2->SetTextAngle(90);
  
  TH2F *NPE_VS_Ev_ALL = new TH2F("NPE_VS_Ev_ALL","",binsE_nuE+binsE_nuMu,E_bins,binsNPE_nuE+binsNPE_nuMu,NPE_bins);
  NPE_VS_Ev_ALL->GetXaxis()->SetTitle("i");
  NPE_VS_Ev_ALL->GetYaxis()->SetTitle("j");
  for(int ii=1; ii<=binsE_nuE; ii++) {
    for(int jj=1; jj<=binsNPE_nuE; jj++) {
      NPE_VS_Ev_ALL->SetBinContent(ii,jj,NPE_VS_Ev_less75_nueALL->GetBinContent(ii,jj));
      NPE_VS_Ev_ALL->SetBinContent(ii,jj+binsNPE_nuE,NPE_VS_Ev_over95_nueALL->GetBinContent(ii,jj));
      NPE_VS_Ev_ALL->SetBinContent(ii+binsE_nuE,jj,NPE_VS_Ev_less75_numuALL->GetBinContent(ii,jj));
      NPE_VS_Ev_ALL->SetBinContent(ii+binsE_nuE,jj+binsNPE_nuE,NPE_VS_Ev_over95_numuALL->GetBinContent(ii,jj));
    }
  }

  gPad->SetLogz();
  pt1->AddText("#nu_{e}");
  pt2->AddText("#nu_{#mu}");
  call->cd();
  NPE_VS_Ev_ALL->Draw("colz");
  pt1->Draw();
  pt2->Draw();
  t1->Draw();
  t2->Draw();

  call->SaveAs("Plot/NPE_VS_Ev_MAT_FLAV.png");
  call->SaveAs("Plot/NPE_VS_Ev_MAT_FLAV.pdf");
  call->SaveAs("Plot/NPE_VS_Ev_MAT_FLAV.C");


  ////////////////////////////CC+NC////////////////////////////////////////////////////////
  
  TCanvas *ck = new TCanvas("ck","",1500,900);
  ck->Divide(3,2);
  
  TH2F *NPE_VS_Ev_less75_nueCC = new TH2F("NPE_VS_Ev_less75_nueCC","",binsE_nuE,lowE_nuE,upE_nuE,binsNPE_nuE,lowNPE_nuE,upNPE_nuE);
  mytree->Project("NPE_VS_Ev_less75_nueCC","log10(trueNPE_LPMT_CD):log10(nuEnergy)","CCint==1 && abs(init_lepID)==11 && Tres_RMS<75. && newVradius<16000. && trueNPE_LPMT_CD>1.E5 && FC==1","");
  NPE_VS_Ev_less75_nueCC->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  NPE_VS_Ev_less75_nueCC->GetYaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_less75_nueCC->GetYaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_less75_nueCC->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  NPE_VS_Ev_less75_nueCC->GetXaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_less75_nueCC->GetXaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_less75_nueCC->GetZaxis()->SetLabelSize(0.035); 
  NPE_VS_Ev_less75_nueCC->SetTitle("#nu_{e}^{CC} #sigma(t_{RES}) < 75 ns");
  gStyle->SetPalette(kBird);
  ck->cd(4);
  NPE_VS_Ev_less75_nueCC->Draw("colz");

  TH2F *NPE_VS_Ev_over95_nueCC = new TH2F("NPE_VS_Ev_over95_nueCC","",binsE_nuMu,lowE_nuMu,upE_nuMu,binsNPE_nuMu,lowNPE_nuMu,upNPE_nuMu);
  mytree->Project("NPE_VS_Ev_over95_nueCC","log10(trueNPE_LPMT_CD):log10(nuEnergy)","CCint==1 && abs(init_lepID)==11 && Tres_RMS>95. && newVradius<16000. && trueNPE_LPMT_CD>5.E5 && FC==1","");
  NPE_VS_Ev_over95_nueCC->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  NPE_VS_Ev_over95_nueCC->GetYaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_over95_nueCC->GetYaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_over95_nueCC->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  NPE_VS_Ev_over95_nueCC->GetXaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_over95_nueCC->GetXaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_over95_nueCC->GetZaxis()->SetLabelSize(0.035);
  NPE_VS_Ev_over95_nueCC->SetTitle("#nu_{e}^{CC} #sigma(t_{RES}) > 95 ns");
  gStyle->SetPalette(kBird);
  ck->cd(1);
  NPE_VS_Ev_over95_nueCC->Draw("colz");

  TH2F *NPE_VS_Ev_less75_numuCC = new TH2F("NPE_VS_Ev_less75_numuCC","",binsE_nuE,lowE_nuE,upE_nuE,binsNPE_nuE,lowNPE_nuE,upNPE_nuE);
  mytree->Project("NPE_VS_Ev_less75_numuCC","log10(trueNPE_LPMT_CD):log10(nuEnergy)","CCint==1 && abs(init_lepID)==13 && Tres_RMS<75. && newVradius<16000. && trueNPE_LPMT_CD>1.E5 && FC==1","");
  NPE_VS_Ev_less75_numuCC->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  NPE_VS_Ev_less75_numuCC->GetYaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_less75_numuCC->GetYaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_less75_numuCC->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  NPE_VS_Ev_less75_numuCC->GetXaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_less75_numuCC->GetXaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_less75_numuCC->GetZaxis()->SetLabelSize(0.035);
  NPE_VS_Ev_less75_numuCC->SetTitle("#nu_{#mu}^{CC} #sigma(t_{RES}) < 75 ns");
  gStyle->SetPalette(kBird);
  ck->cd(5);
  NPE_VS_Ev_less75_numuCC->Draw("colz");

  TH2F *NPE_VS_Ev_over95_numuCC = new TH2F("NPE_VS_Ev_over95_numuCC","",binsE_nuMu,lowE_nuMu,upE_nuMu,binsNPE_nuMu,lowNPE_nuMu,upNPE_nuMu);
  mytree->Project("NPE_VS_Ev_over95_numuCC","log10(trueNPE_LPMT_CD):log10(nuEnergy)","CCint==1 && abs(init_lepID)==13 && Tres_RMS>95. && newVradius<16000. && trueNPE_LPMT_CD>5.E5 && FC==1","");
  NPE_VS_Ev_over95_numuCC->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  NPE_VS_Ev_over95_numuCC->GetYaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_over95_numuCC->GetYaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_over95_numuCC->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  NPE_VS_Ev_over95_numuCC->GetXaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_over95_numuCC->GetXaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_over95_numuCC->GetZaxis()->SetLabelSize(0.035);
  NPE_VS_Ev_over95_numuCC->SetTitle("#nu_{#mu}^{CC} #sigma(t_{RES}) > 95 ns");
  gStyle->SetPalette(kBird);
  ck->cd(2);
  NPE_VS_Ev_over95_numuCC->Draw("colz");

  TH2F *NPE_VS_Ev_less75_nuNC = new TH2F("NPE_VS_Ev_less75_nuNC","",binsE_nuE,lowE_nuE,upE_nuE,binsNPE_nuE,lowNPE_nuE,upNPE_nuE);
  mytree->Project("NPE_VS_Ev_less75_nuNC","log10(trueNPE_LPMT_CD):log10(nuEnergy)","NCint==1 && Tres_RMS<75. && newVradius<16000. && trueNPE_LPMT_CD>1.E5 && FC==1","");
  NPE_VS_Ev_less75_nuNC->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  NPE_VS_Ev_less75_nuNC->GetYaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_less75_nuNC->GetYaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_less75_nuNC->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  NPE_VS_Ev_less75_nuNC->GetXaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_less75_nuNC->GetXaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_less75_nuNC->GetZaxis()->SetLabelSize(0.035);
  NPE_VS_Ev_less75_nuNC->SetTitle("#nu^{NC} #sigma(t_{RES}) < 75 ns");
  gStyle->SetPalette(kBird);
  ck->cd(6);
  NPE_VS_Ev_less75_nuNC->Draw("colz");

  TH2F *NPE_VS_Ev_over95_nuNC = new TH2F("NPE_VS_Ev_over95_nuNC","",binsE_nuMu,lowE_nuMu,upE_nuMu,binsNPE_nuMu,lowNPE_nuMu,upNPE_nuMu);
  mytree->Project("NPE_VS_Ev_over95_nuNC","log10(trueNPE_LPMT_CD):log10(nuEnergy)","NCint==1 && Tres_RMS>95. && newVradius<16000. && trueNPE_LPMT_CD>5.E5 && FC==1","");
  NPE_VS_Ev_over95_nuNC->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  NPE_VS_Ev_over95_nuNC->GetYaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_over95_nuNC->GetYaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_over95_nuNC->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  NPE_VS_Ev_over95_nuNC->GetXaxis()->SetTitleSize(0.06);
  NPE_VS_Ev_over95_nuNC->GetXaxis()->SetLabelSize(0.05);
  NPE_VS_Ev_over95_nuNC->GetZaxis()->SetLabelSize(0.035);
  NPE_VS_Ev_over95_nuNC->SetTitle("#nu^{NC} #sigma(t_{RES}) > 95 ns");
  gStyle->SetPalette(kBird);
  ck->cd(3);
  NPE_VS_Ev_over95_nuNC->Draw("colz");

  //Arrays

  Float_t E_bins_large[binsE_nuE+binsE_nuMu+binsE_nuE+1];

  for(int ii=0; ii<binsE_nuE+binsE_nuMu+binsE_nuE+1; ii++) {
    E_bins_large[ii] = float(ii);
  }

  TCanvas *call_cc = new TCanvas("call_cc","",1500,900);
  TPaveText *pt11 = new TPaveText(5.0,-3.2,7.0,-1.2);
  TPaveText *pt12 = new TPaveText(17.0,-3.2,19.0,-1.2);
  TPaveText *pt13 = new TPaveText(29.0,-3.2,31.0,-1.2);
  TText *t11 = new TText(-1.5,5.0,"< 75 ns");
  t11->SetTextSize(0.05);
  t11->SetTextAngle(90);
  TText *t12 = new TText(-1.5,12.0,"> 95 ns");
  t12->SetTextSize(0.05);
  t12->SetTextAngle(90);
  
  TH2F *NPE_VS_Ev_INT = new TH2F("NPE_VS_Ev_INT","CC+NC",binsE_nuE+binsE_nuMu+binsE_nuE,E_bins_large,binsNPE_nuE+binsNPE_nuMu,NPE_bins);
  NPE_VS_Ev_INT->GetXaxis()->SetTitle("i");
  NPE_VS_Ev_INT->GetYaxis()->SetTitle("j");
  for(int ii=1; ii<=binsE_nuE; ii++) {
    for(int jj=1; jj<=binsNPE_nuE; jj++) {
      NPE_VS_Ev_INT->SetBinContent(ii,jj,NPE_VS_Ev_less75_nueCC->GetBinContent(ii,jj));
      NPE_VS_Ev_INT->SetBinContent(ii,jj+binsNPE_nuE,NPE_VS_Ev_over95_nueCC->GetBinContent(ii,jj));
      NPE_VS_Ev_INT->SetBinContent(ii+binsE_nuE,jj,NPE_VS_Ev_less75_numuCC->GetBinContent(ii,jj));
      NPE_VS_Ev_INT->SetBinContent(ii+binsE_nuE,jj+binsNPE_nuE,NPE_VS_Ev_over95_numuCC->GetBinContent(ii,jj));
      NPE_VS_Ev_INT->SetBinContent(ii+binsE_nuE+binsE_nuE,jj,NPE_VS_Ev_less75_nuNC->GetBinContent(ii,jj));
      NPE_VS_Ev_INT->SetBinContent(ii+binsE_nuE+binsE_nuE,jj+binsNPE_nuE,NPE_VS_Ev_over95_nuNC->GetBinContent(ii,jj));
    }
  }

  gPad->SetLogz();
  pt11->AddText("#nu_{e}^{CC}");
  pt12->AddText("#nu_{#mu}^{CC}");
  pt13->AddText("#nu^{NC}");
  call_cc->cd();
  NPE_VS_Ev_INT->Draw("colz");
  pt11->Draw();
  pt12->Draw();
  pt13->Draw();
  t11->Draw();
  t12->Draw();

  call_cc->SaveAs("Plot/NPE_VS_Ev_MAT_CC+NC.png");
  call_cc->SaveAs("Plot/NPE_VS_Ev_MAT_CC+NC.pdf");
  call_cc->SaveAs("Plot/NPE_VS_Ev_MAT_CC+NC.C");


}
