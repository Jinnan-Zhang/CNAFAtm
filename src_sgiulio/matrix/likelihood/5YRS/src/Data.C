#define Data_cxx
#include "Data.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <fstream>
#include <string>
#include <TGraph.h>
#include <TSpline.h>
#include "srtutils.cc"
#include <TRandom3.h>

void Data::Initialize(std::string config)
{
  _likfile = GetFileName("LIK_FILE",config.c_str());
  _all_matrix = GetFileName("MAT_ALL_FILE",config.c_str());
  _sgn_matrix = GetFileName("MAT_SGN_FILE",config.c_str());
  _bkg_matrix = GetFileName("MAT_BKG_FILE",config.c_str());
  _E_bins = GetFileName("E_BINS",config.c_str());
  _E_all_file = GetFileName("E_ALL_FILE",config.c_str());
  _E_sgn_file = GetFileName("E_SGN_FILE",config.c_str());
  _E_fidcut_file = GetFileName("E_FIDCUT_FILE",config.c_str());
  _E_allcuts_file = GetFileName("E_ALLCUTS_FILE",config.c_str());
  _E_sgn_allcuts_file = GetFileName("E_SGN_ALLCUTS_FILE",config.c_str());
  _NPE_all_file = GetFileName("NPE_ALL_FILE",config.c_str());
  _NPE_sgn_file = GetFileName("NPE_SGN_FILE",config.c_str());
  _NPE_fidcuts_file = GetFileName("NPE_FIDCUTS_FILE",config.c_str());
  _NPE_allcuts_file = GetFileName("NPE_ALLCUTS_FILE",config.c_str());
  _NPE_sgn_allcuts_file = GetFileName("NPE_SGN_ALLCUTS_FILE",config.c_str());
  _NPE_bins = GetFileName("NPE_BINS",config.c_str());
  _E_all_fromdata = GetFileName("E_ALL_FROM_DATA",config.c_str());
  _E_sgn_fromdata = GetFileName("E_SGN_FROM_DATA",config.c_str());
  _E_fidcuts_fromdata = GetFileName("E_FIDCUTS_FROM_DATA",config.c_str());
  _E_allcuts_fromdata = GetFileName("E_ALLCUTS_FROM_DATA",config.c_str());
  _E_sgn_allcuts_fromdata = GetFileName("E_SGN_ALLCUTS_FROM_DATA",config.c_str());
  _sourceflux = GetFileName("SOURCE_FLUX_FILE",config.c_str());
  family = GetValue("FAMILY",config.c_str());
  if (family == "e") id_family = 11;
  if (family == "mu") id_family = 13;
  osc_flag = GetValue("INCLUDE_OSC",config.c_str());
  cut_tres_str = GetValue("TRES_CUT_VALUE",config.c_str());
  TString str_cut_tres = cut_tres_str;
  cut_tres = atof(str_cut_tres);
}

void Data::GetMAT(Int_t binsE, Float_t lowedgeE, Float_t upedgeE, Int_t binsNPE, Float_t lowedgeNPE, Float_t upedgeNPE, std::string outfold) {

  sprintf(ext_filename, "%s/Matplot_%i_%i.root",outfold.c_str(),binsE,binsNPE);
  TFile *f_out = new TFile(ext_filename, "RECREATE");
  char* filename1 = new char[128];
  sprintf(filename1,"%s/%s_%i_%i.txt",outfold.c_str(),_likfile.c_str(),binsE,binsNPE);
  std::ofstream myLmatrix;
  myLmatrix.open(filename1);
  char* filenameALL = new char[128];
  sprintf(filenameALL,"%s/%s_%i_%i.txt",outfold.c_str(),_all_matrix.c_str(),binsE,binsNPE);
  std::ofstream myALLmatrix;
  myALLmatrix.open(filenameALL);
  char* filenameS = new char[128];
  sprintf(filenameS,"%s/%s_%i_%i.txt",outfold.c_str(),_sgn_matrix.c_str(),binsE,binsNPE);
  std::ofstream mySmatrix;
  mySmatrix.open(filenameS);
  char* filenameB = new char[128];
  sprintf(filenameB,"%s/%s_%i_%i.txt",outfold.c_str(),_bkg_matrix.c_str(),binsE,binsNPE);
  std::ofstream myBmatrix;
  myBmatrix.open(filenameB);
  char* filename2 = new char[128];
  sprintf(filename2,"%s/%s_%i.txt",outfold.c_str(),_E_bins.c_str(),binsE);
  std::ofstream myEbins;
  myEbins.open(filename2);
  char* filename3 = new char[128];
  sprintf(filename3,"%s/%s_%i.txt",outfold.c_str(),_E_all_file.c_str(),binsE);
  std::ofstream myEnorm_all;
  myEnorm_all.open(filename3);
  char* filename4 = new char[128];
  sprintf(filename4,"%s/%s_%i.txt",outfold.c_str(),_E_sgn_file.c_str(),binsE);
  std::ofstream myEnorm_sgn;
  myEnorm_sgn.open(filename4);
  char* filename5 = new char[128];
  sprintf(filename5,"%s/%s_%i.txt",outfold.c_str(),_E_fidcut_file.c_str(),binsE);
  std::ofstream myEnorm_fidcut;
  myEnorm_fidcut.open(filename5);
  char* filename6 = new char[128];
  sprintf(filename6,"%s/%s_%i.txt",outfold.c_str(),_E_allcuts_file.c_str(),binsE);
  std::ofstream myEnorm_allcuts;
  myEnorm_allcuts.open(filename6);
  char* filename7 = new char[128];
  sprintf(filename7,"%s/%s_%i.txt",outfold.c_str(),_E_sgn_allcuts_file.c_str(),binsE);
  std::ofstream myEnorm_sgn_allcuts;
  myEnorm_sgn_allcuts.open(filename7);

  if (fChain == 0) return;
  Long64_t nentries = fChain->GetEntriesFast();
  std::cout << "Looping over " << fChain->GetEntriesFast() << " entries... " << std::endl;
  Long64_t nbytes = 0, nb = 0;

  TH2F *Npe_VS_Ev_LPMT = new TH2F("Npe_VS_Ev_LPMT","Un-normalized likelihood Matrix",binsE,lowedgeE,upedgeE,binsNPE,lowedgeNPE,upedgeNPE);
  TH2F *Npe_VS_Ev_LPMT_sgn = new TH2F("Npe_VS_Ev_LPMT_sgn","Un-normalized likelihood Matrix for signal",binsE,lowedgeE,upedgeE,binsNPE,lowedgeNPE,upedgeNPE);
  TH2F *Npe_VS_Ev_LPMT_bkg = new TH2F("Npe_VS_Ev_LPMT_bkg","Un-normalized likelihood Matrix for background",binsE,lowedgeE,upedgeE,binsNPE,lowedgeNPE,upedgeNPE);
  TH2F *Lmatrix = new TH2F("Lmatrix","Likelihood Matrix",binsE,lowedgeE,upedgeE,binsNPE,lowedgeNPE,upedgeNPE);
  TH1F *Ev = new TH1F("Ev","Inclusive energy spectrum before any cut",binsE,lowedgeE,upedgeE);
  TH1F *Ev_sgn = new TH1F("Ev_sgn","Flavor exclusive energy spectrum",binsE,lowedgeE,upedgeE);
  TH1F *Ev_fidcuts = new TH1F("Ev_fidcuts","Inclusive energy spectrum after fiducial cuts",binsE,lowedgeE,upedgeE);
  TH1F *Ev_allcuts = new TH1F("Ev_allcuts","Inclusive energy spectrum after all cuts",binsE,lowedgeE,upedgeE);
  TH1F *Ev_sgn_allcuts = new TH1F("Ev_sgn_allcuts","Flavor exclusive energy spectrum after all cuts",binsE,lowedgeE,upedgeE);
  TH1F *Ev_bkg_allcuts = new TH1F("Ev_bkg_allcuts","Background energy spectrum after all cuts",binsE,lowedgeE,upedgeE);
  Npe_VS_Ev_LPMT->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_LPMT->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_VS_Ev_LPMT_sgn->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Npe_VS_Ev_LPMT_sgn->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Lmatrix->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Lmatrix->GetYaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Ev->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev->SetLineColor(kMagenta);
  Ev->SetLineWidth(4);
  Ev_sgn->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev_sgn->SetLineColor(kSpring-6);
  Ev_sgn->SetLineWidth(4);
  Ev_fidcuts->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev_fidcuts->SetLineColor(kGray+3);
  Ev_fidcuts->SetLineWidth(4);
  Ev_allcuts->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev_allcuts->SetLineColor(kAzure+7);
  Ev_allcuts->SetLineWidth(4);
  Ev_sgn_allcuts->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev_sgn_allcuts->SetLineColor(kRed);
  Ev_sgn_allcuts->SetLineWidth(4);
  Ev_bkg_allcuts->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev_bkg_allcuts->SetLineColor(kGreen+3);
  Ev_bkg_allcuts->SetLineWidth(4);
  binlowedge.ResizeTo(binsE+1);
  bincenter.ResizeTo(binsE);
  float Cflav_all = 0;
  float Cflav_cut = 0;
  float Cbkg_cut = 0;
  float Call_cut = 0;
  
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
  //for (Long64_t jentry=0; jentry<20000;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    if (jentry%1000==0) std::cout <<"processing event "<<jentry<<std::endl;

    osc_weight = 0.0;
    if(osc_flag == "NO") osc_weight = 1.0;
    if(osc_flag == "YES") osc_weight = P_surv;
    /*
    if(osc_flag == "YES") {
      V_fact = 2.0*sqrt(2.0)*fermi_const*N_e*nuEnergy;
      matt_delta2m31_Nu = sqrt(pow((delta2m31*cos(2.0*theta13))-V_fact,2) + pow(delta2m31*sin(2.0*theta13),2));
      matt_delta2m31_Nubar = sqrt(pow((delta2m31*cos(2.0*theta13))+V_fact,2) + pow(delta2m31*sin(2.0*theta13),2));
      matt_theta13_Nu = 0.5*atan2(tan(2.0*theta13),1.0-(V_fact/(delta2m31*cos(2.0*theta13))));
      matt_theta13_Nubar = 0.5*atan2(tan(2.0*theta13),1.0+(V_fact/(delta2m31*cos(2.0*theta13))));
      phase1_Nu = 1.27*0.5*(delta2m31+V_fact+matt_delta2m31_Nu)*(L_osc_baseline/nuEnergy);
      phase2_Nu = 1.27*0.5*(delta2m31+V_fact-matt_delta2m31_Nu)*(L_osc_baseline/nuEnergy);
      phase3_Nu = 1.27*matt_delta2m31_Nu*(L_osc_baseline/nuEnergy);
      phase1_Nubar = 1.27*0.5*(delta2m31-V_fact+matt_delta2m31_Nubar)*(L_osc_baseline/nuEnergy);
      phase2_Nubar = 1.27*0.5*(delta2m31-V_fact-matt_delta2m31_Nubar)*(L_osc_baseline/nuEnergy);
      phase3_Nubar = 1.27*matt_delta2m31_Nubar*(L_osc_baseline/nuEnergy);
      /////////////////NuMu+NuMubar survival///////////////////////////////
      P_s_NuMu1 = cos(matt_theta13_Nu)*cos(matt_theta13_Nu)*4.0*sin2theta23*cos2theta23*sin(phase1_Nu)*sin(phase1_Nu);
      P_s_NuMu2 = sin(matt_theta13_Nu)*sin(matt_theta13_Nu)*4.0*sin2theta23*cos2theta23*sin(phase2_Nu)*sin(phase2_Nu);
      P_s_NuMu3 = sin2theta23*sin2theta23*(sin(2*matt_theta13_Nu)*sin(2*matt_theta13_Nu))*sin(phase3_Nu)*sin(phase3_Nu);
      P_s_NuMubar1 = cos(matt_theta13_Nubar)*cos(matt_theta13_Nubar)*4.0*sin2theta23*cos2theta23*sin(phase1_Nubar)*sin(phase1_Nubar);
      P_s_NuMubar2 = sin(matt_theta13_Nubar)*sin(matt_theta13_Nubar)*4.0*sin2theta23*cos2theta23*sin(phase2_Nubar)*sin(phase2_Nubar);
      P_s_NuMubar3 = sin2theta23*sin2theta23*(sin(2*matt_theta13_Nubar)*sin(2*matt_theta13_Nubar))*sin(phase3_Nubar)*sin(phase3_Nubar);
      P_s_NuMu = 1.0 - P_s_NuMu1 - P_s_NuMu2 - P_s_NuMu3;
      P_s_NuMubar = 1.0 - P_s_NuMubar1 - P_s_NuMubar2 - P_s_NuMubar3;
      /////////////////NuE+NuEbar survival///////////////////////////////
      P_s_NuE = 1.0 - ((sin(2.0*matt_theta13_Nu)*sin(2.0*matt_theta13_Nu))*sin(phase3_Nu)*sin(phase3_Nu));
      P_s_NuEbar = 1.0 - ((sin(2.0*matt_theta13_Nubar)*sin(2.0*matt_theta13_Nubar))*sin(phase3_Nubar)*sin(phase3_Nubar));
      /////////////////Transition///////////////////////////////
      P_NuEtoNuMu = sin2theta23*(sin(2.0*matt_theta13_Nu)*sin(2.0*matt_theta13_Nu))*sin(phase3_Nu)*sin(phase3_Nu);
      P_NuEbartoNuMubar = sin2theta23*(sin(2.0*matt_theta13_Nubar)*sin(2.0*matt_theta13_Nubar))*sin(phase3_Nubar)*sin(phase3_Nubar);
      if (init_nuID == 12) osc_weight = P_s_NuE;
      if (init_nuID == -12) osc_weight = P_s_NuEbar;
      if (init_nuID == 14) osc_weight = P_s_NuMu;
      if (init_nuID == -14) osc_weight = P_s_NuMubar;
    }
    */

    Ev->Fill(log10(nuEnergy),osc_weight); //inclusive spectrum before cuts
    if ((CCint==1 && abs(init_lepID)==(id_family)) || (NCint==1 && abs(init_lepID)==(id_family+1))) {
      Ev_sgn->Fill(log10(nuEnergy),osc_weight);
      Cflav_all += osc_weight;
    }
    if (newVradius>16000. || trueNPE_LPMT_WP > 60. ) continue;
    Ev_fidcuts->Fill(log10(nuEnergy),osc_weight); //inclusive spectrum after fid cuts
    if ((family == "e" && Tres_RMS>cut_tres) || log10(trueNPE_LPMT_CD) < lowedgeNPE) continue;
    if ((family == "mu" && Tres_RMS<cut_tres) || log10(trueNPE_LPMT_CD) < lowedgeNPE) continue;

    Npe_VS_Ev_LPMT->Fill(log10(nuEnergy),log10(trueNPE_LPMT_CD),osc_weight); //un-normalized likelihood    
    Ev_allcuts->Fill(log10(nuEnergy),osc_weight); //inclusive spectrum after all cuts
    Call_cut += osc_weight;
    if ((CCint==1 && abs(init_lepID)==(id_family)) || (NCint==1 && abs(init_lepID)==(id_family+1))) {
      Npe_VS_Ev_LPMT_sgn->Fill(log10(nuEnergy),log10(trueNPE_LPMT_CD),osc_weight); //un-normalized likelihood for sgn
      Ev_sgn_allcuts->Fill(log10(nuEnergy),osc_weight); //Ev exclusive spectrum for sgn after cut
      Cflav_cut += osc_weight;
    } else {
      Npe_VS_Ev_LPMT_bkg->Fill(log10(nuEnergy),log10(trueNPE_LPMT_CD),osc_weight); //un-normalized likelihood for bkg
      Ev_bkg_allcuts->Fill(log10(nuEnergy),osc_weight); //background
      Cbkg_cut += osc_weight;
    }
  }
  Npe_VS_Ev_LPMT->Write();
  Npe_VS_Ev_LPMT_sgn->Write();
  Npe_VS_Ev_LPMT_bkg->Write();
  std::cout << std::endl << "Signal efficiency is " << 100.*(Cflav_cut/Cflav_all) << "%" << std::endl;
  std::cout << "Residual background is " << 100.*(Cbkg_cut/Call_cut) << "%" << std::endl << std::endl;

  std::cout<<"LIKELIHOOD MATRIX"<<std::endl;  
  mySmatrix << binsE << "\t" << binsNPE << "\t" << lowedgeE << "\t" << upedgeE << "\t" << lowedgeNPE << "\t" << upedgeNPE << "\n";
  myBmatrix << binsE << "\t" << binsNPE << "\t" << lowedgeE << "\t" << upedgeE << "\t" << lowedgeNPE << "\t" << upedgeNPE << "\n";
  myLmatrix << binsE << "\t" << binsNPE << "\t" << lowedgeE << "\t" << upedgeE << "\t" << lowedgeNPE << "\t" << upedgeNPE << "\n";
  myALLmatrix << binsE << "\t" << binsNPE << "\t" << lowedgeE << "\t" << upedgeE << "\t" << lowedgeNPE << "\t" << upedgeNPE << "\n";
  for (int ii=1; ii<=binsE; ii++) {
    for (int jj=1; jj<=binsNPE; jj++) {
      std::cout << float(Npe_VS_Ev_LPMT_sgn->GetBinContent(ii,jj))/float(Ev_sgn->GetBinContent(ii)) << "\t";
      myLmatrix << float(Npe_VS_Ev_LPMT_sgn->GetBinContent(ii,jj))/float(Ev_sgn->GetBinContent(ii)) << "\t";
      Lmatrix->SetBinContent(ii,jj,float(Npe_VS_Ev_LPMT_sgn->GetBinContent(ii,jj))/float(Ev_sgn->GetBinContent(ii)));
      myALLmatrix << float(Npe_VS_Ev_LPMT->GetBinContent(ii,jj)) << "\t";
      mySmatrix << float(Npe_VS_Ev_LPMT_sgn->GetBinContent(ii,jj)) << "\t";
      myBmatrix << float(Npe_VS_Ev_LPMT_bkg->GetBinContent(ii,jj)) << "\t";
    }
    myLmatrix << "\n";
    myALLmatrix << "\n";
    mySmatrix << "\n";
    myBmatrix << "\n";
    binlowedge[ii-1] = Ev_allcuts->GetXaxis()->GetBinLowEdge(ii);
    bincenter[ii-1] = Ev_allcuts->GetXaxis()->GetBinCenter(ii);
    myEbins << Ev_allcuts->GetXaxis()->GetBinCenter(ii) << "\t";
    myEnorm_all << Ev->GetBinContent(ii) << "\t";
    myEnorm_sgn << Ev_sgn->GetBinContent(ii) << "\t";
    myEnorm_fidcut << Ev_fidcuts->GetBinContent(ii) << "\t";
    myEnorm_allcuts << Ev_allcuts->GetBinContent(ii) << "\t";
    myEnorm_sgn_allcuts << Ev_sgn_allcuts->GetBinContent(ii) << "\t";
    std::cout<<std::endl;
  }
  binlowedge[binsE] = Ev_allcuts->GetXaxis()->GetBinLowEdge(binsE+1);
  Lmatrix->Write();
  Ev->Write();
  Ev_sgn->Write();
  Ev_fidcuts->Write();
  Ev_allcuts->Write();
  Ev_sgn_allcuts->Write();
  Ev_bkg_allcuts->Write();
  myLmatrix.close();
  mySmatrix.close();
  myBmatrix.close();
  myEbins.close();
  myEnorm_all.close();
  myEnorm_sgn.close();
  myEnorm_fidcut.close();
  myEnorm_allcuts.close();
  myEnorm_sgn_allcuts.close();
  std::cout << filename1 << " created" << std::endl;
  std::cout << filenameALL << " created" << std::endl;
  std::cout << filenameS << " created" << std::endl;
  std::cout << filenameB << " created" << std::endl;
  std::cout << filename2 << " created" << std::endl;
  std::cout << filename3 << " created" << std::endl;
  std::cout << filename4 << " created" << std::endl;
  std::cout << filename5 << " created" << std::endl;
  std::cout << filename6 << " created" << std::endl;
  std::cout << filename7 << " created" << std::endl;  
  f_out->Close();
}

void Data::GetDATA(Int_t binsE, Float_t lowedgeE, Float_t upedgeE, Int_t binsNPE, Float_t lowedgeNPE, Float_t upedgeNPE, std::string outfold)
{
  sprintf(ext_filename, "%s/Dataplot_%i_%i.root",outfold.c_str(),binsE,binsNPE);
  TFile *f_out = new TFile(ext_filename, "RECREATE");
  char* filenameA1 = new char[128];
  sprintf(filenameA1,"%s/%s_%i.txt",outfold.c_str(),_NPE_all_file.c_str(),binsNPE);
  std::ofstream myNPE_all;
  myNPE_all.open(filenameA1);
  char* filenameA2 = new char[128];
  sprintf(filenameA2,"%s/%s_%i.txt",outfold.c_str(),_NPE_sgn_file.c_str(),binsNPE);
  std::ofstream myNPE_sgn;
  myNPE_sgn.open(filenameA2);
  char* filenameA4 = new char[128];
  sprintf(filenameA4,"%s/%s_%i.txt",outfold.c_str(),_NPE_fidcuts_file.c_str(),binsNPE);
  std::ofstream myNPE_fidcuts;
  myNPE_fidcuts.open(filenameA4);
  char* filename11 = new char[128];
  sprintf(filename11,"%s/%s_%i.txt",outfold.c_str(),_NPE_allcuts_file.c_str(),binsNPE);
  std::ofstream myNPE_allcuts;
  myNPE_allcuts.open(filename11);
  char* filenameS1 = new char[128];
  sprintf(filenameS1,"%s/%s_%i.txt",outfold.c_str(),_NPE_sgn_allcuts_file.c_str(),binsNPE);
  std::ofstream myNPE_sgn_allcuts;
  myNPE_sgn_allcuts.open(filenameS1);
  char* filenameA3 = new char[128];
  sprintf(filenameA3,"%s/%s_%i.txt",outfold.c_str(),_E_all_fromdata.c_str(),binsE);
  std::ofstream mytrueenergy_fromdata_all;
  mytrueenergy_fromdata_all.open(filenameA3);
  char* filenameQ1 = new char[128];
  sprintf(filenameQ1,"%s/%s_%i.txt",outfold.c_str(),_E_sgn_fromdata.c_str(),binsE);
  std::ofstream mytrueenergy_fromdata_sgn;
  mytrueenergy_fromdata_sgn.open(filenameQ1);
  char* filenameF1 = new char[128];
  sprintf(filenameF1,"%s/%s_%i.txt",outfold.c_str(),_E_fidcuts_fromdata.c_str(),binsE);
  std::ofstream mytrueenergy_fromdata_fidcuts;
  mytrueenergy_fromdata_fidcuts.open(filenameF1);
  char* filename33 = new char[128];
  sprintf(filename33,"%s/%s_%i.txt",outfold.c_str(),_E_allcuts_fromdata.c_str(),binsE);
  std::ofstream mytrueenergy_fromdata_allcuts;
  mytrueenergy_fromdata_allcuts.open(filename33);
  char* filenameS3 = new char[128];
  sprintf(filenameS3,"%s/%s_%i.txt",outfold.c_str(),_E_sgn_allcuts_fromdata.c_str(),binsE);
  std::ofstream mytrueenergy_fromdata_sgn_allcuts;
  mytrueenergy_fromdata_sgn_allcuts.open(filenameS3);
  char* filename44 = new char[128];
  sprintf(filename44,"%s/%s_%i.txt",outfold.c_str(),_NPE_bins.c_str(),binsNPE);
  std::ofstream myNPEbins;
  myNPEbins.open(filename44);

  if (fChain == 0) return;
  //Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nentries = 6500;
  std::cout << "Looping over " << fChain->GetEntriesFast() << " entries... " << std::endl;
  Long64_t nbytes = 0, nb = 0;

  TRandom3 extract_osc;
  TH1F *Npe_LPMT = new TH1F("Npe_LPMT","Inclusive NPE spectrum",binsNPE,lowedgeNPE,upedgeNPE);
  TH1F *Npe_LPMT_sgn = new TH1F("Npe_LPMT_sgn","Exclusive flavor NPE spectrum",binsNPE,lowedgeNPE,upedgeNPE);
  TH1F *Npe_LPMT_fidcuts = new TH1F("Npe_LPMT_fidcuts","Inclusive NPE spectrum after fiducial cuts",binsNPE,lowedgeNPE,upedgeNPE);
  TH1F *Npe_LPMT_allcuts = new TH1F("Npe_LPMT_allcuts","Inclusive NPE spectrum after all cuts",binsNPE,lowedgeNPE,upedgeNPE);
  TH1F *Npe_LPMT_sgn_allcuts = new TH1F("Npe_LPMT_sgn_allcuts","Exclusive flavor NPE spectrum after all cuts",binsNPE,lowedgeNPE,upedgeNPE);
  TH1F *Npe_LPMT_bkg_allcuts = new TH1F("Npe_LPMT_bkg_allcuts","Background NPE spectrum after all cuts",binsNPE,lowedgeNPE,upedgeNPE);
  TH1F *Ev = new TH1F("Ev","True energy spectrum",binsE,lowedgeE,upedgeE);
  TH1F *Ev_sgn = new TH1F("Ev_sgn","Flavor exlusive true energy spectrum",binsE,lowedgeE,upedgeE);
  TH1F *Ev_fidcuts = new TH1F("Ev_fidcuts","Inclusive true energy spectrum after fiducial cuts",binsE,lowedgeE,upedgeE);
  TH1F *Ev_allcuts = new TH1F("Ev_allcuts","Inclusive true energy spectrum after all cuts",binsE,lowedgeE,upedgeE);
  TH1F *Ev_sgn_allcuts = new TH1F("Ev_sgn_allcuts","Flavor exclusive true energy spectrum after all cuts",binsE,lowedgeE,upedgeE);
  TH1F *Ev_bkg_allcuts = new TH1F("Ev_bkg_allcuts","Background true energy spectrum after all cuts",binsE,lowedgeE,upedgeE);
  Npe_LPMT->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_LPMT->SetLineColor(kMagenta);
  Npe_LPMT->SetLineWidth(4);
  Npe_LPMT_sgn->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_LPMT_sgn->SetLineColor(kSpring-6);
  Npe_LPMT_sgn->SetLineWidth(4);
  Npe_LPMT_fidcuts->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_LPMT_fidcuts->SetLineColor(kGray+3);
  Npe_LPMT_fidcuts->SetLineWidth(4);
  Npe_LPMT_allcuts->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_LPMT_allcuts->SetLineColor(kAzure+7);
  Npe_LPMT_allcuts->SetLineWidth(4);
  Npe_LPMT_sgn_allcuts->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_LPMT_sgn_allcuts->SetLineColor(kRed);
  Npe_LPMT_sgn_allcuts->SetLineWidth(4);
  Npe_LPMT_bkg_allcuts->GetXaxis()->SetTitle("log_{10}(NPE_{LPMT})");
  Npe_LPMT_bkg_allcuts->SetLineColor(kGreen+3);
  Npe_LPMT_bkg_allcuts->SetLineWidth(4);
  Ev->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev->SetLineColor(kMagenta);
  Ev->SetLineWidth(4);
  Ev_sgn->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev_sgn->SetLineColor(kSpring-6);
  Ev_sgn->SetLineWidth(4);
  Ev_fidcuts->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev_fidcuts->SetLineColor(kGray+3);
  Ev_fidcuts->SetLineWidth(4);
  Ev_allcuts->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev_allcuts->SetLineColor(kAzure+7);
  Ev_allcuts->SetLineWidth(4);
  Ev_sgn_allcuts->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev_sgn_allcuts->SetLineColor(kRed+3);
  Ev_sgn_allcuts->SetLineWidth(4);
  Ev_bkg_allcuts->GetXaxis()->SetTitle("log_{10}(E_{#nu} [MeV])");
  Ev_bkg_allcuts->SetLineColor(kGreen+3);
  Ev_bkg_allcuts->SetLineWidth(4);

  extract_osc.SetSeed(0);
  double sigma13 = (0.024 - 0.019)/6.0;
  double sin2theta13 = 0.024; // NO
  double cos2theta13 = 1.0 - sin2theta13; // NO
  double theta13 = asin(sqrt(sin2theta13));
  double sigma2m31 = 0.001*((2.69 - 2.45)/6.0); //sigma of delta2m31 measurements;
  double delta2m31 = 2.32E-3; // [eV^2]
  double sigma23 = (0.615 - 0.381)/6.0; //sigma of theta23 measurement
  double sin2theta23 = 0.5; //NO
  double cos2theta23 = 1.0 - sin2theta23; //NO
  //double deltaCP = 0.0;
  double fermi_const = 1.167E-5; // [GeV^-2]
  double N_e = 2.5; // electron density
  double V_fact; // V effective potential in matter
  double matt_delta2m31_Nu; // effective mass splitting in matter for neutrinos
  double matt_delta2m31_Nubar; // effective mass splitting in matter for antineutrinos
  double matt_2sin2theta13_Nu; // effective mixing angle in matter for neutrinos
  double matt_2sin2theta13_Nubar; // effective mixing angle in matter for antineutrinos
  double matt_theta13_Nu;
  double matt_theta13_Nubar;
  double phase1_Nu, phase2_Nu, phase3_Nu; //oscillation phases for neutrinos
  double phase1_Nubar, phase2_Nubar, phase3_Nubar; //oscillation phases for antineutrinos
  double P_s_NuMu1, P_s_NuMu2, P_s_NuMu3, P_s_NuMu; // survival probability NuMu
  double P_s_NuMubar1, P_s_NuMubar2, P_s_NuMubar3, P_s_NuMubar; // survival probability NuMubar
  double P_s_NuE, P_s_NuEbar; // survival probability for NuE
  double P_NuEtoNuMu, P_NuEbartoNuMubar;
  /*
  ///////////////OSCILLATIONS/////////////
  delta2m31 = extract_osc.Gaus(2.32E-3, sigma2m31); // [eV^2]
  sin2theta23 = extract_osc.Gaus(0.5, sigma23); //NO
  cos2theta23 = 1.0-sin2theta23; //NO
  sin2theta13 = extract_osc.Gaus(0.024, sigma13);
  cos2theta13 = 1.0 - sin2theta13;
  theta13 = asin(sqrt(sin2theta13));
  N_e = extract_osc.Gaus(2.5, 0.5);
  ////////////////////////////////////////////
  */
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    if (jentry%1000==0) std::cout <<"processing event "<<jentry<<std::endl;

    osc_weight = 0.0;
    if(osc_flag == "NO") osc_weight = 1.0;
    if(osc_flag == "YES") osc_weight = P_surv;
    /*
    if(osc_flag == "YES") {
      V_fact = 2.0*sqrt(2.0)*fermi_const*N_e*(nuEnergy/1000.);
      matt_delta2m31_Nu = sqrt(pow((delta2m31*cos(2.0*theta13))-V_fact,2) + pow(delta2m31*sin(2.0*theta13),2));
      matt_delta2m31_Nubar = sqrt(pow((delta2m31*cos(2.0*theta13))+V_fact,2) + pow(delta2m31*sin(2.0*theta13),2));
      matt_theta13_Nu = 0.5*atan2(tan(2.0*theta13),1.0-(V_fact/(delta2m31*cos(2.0*theta13))));
      matt_theta13_Nubar = 0.5*atan2(tan(2.0*theta13),1.0+(V_fact/(delta2m31*cos(2.0*theta13))));
      phase1_Nu = 1.27*0.5*(delta2m31+V_fact+matt_delta2m31_Nu)*(L_osc_baseline/(nuEnergy/1000.));
      phase2_Nu = 1.27*0.5*(delta2m31+V_fact-matt_delta2m31_Nu)*(L_osc_baseline/(nuEnergy/1000.));
      phase3_Nu = 1.27*matt_delta2m31_Nu*(L_osc_baseline/(nuEnergy/1000.));
      phase1_Nubar = 1.27*0.5*(delta2m31-V_fact+matt_delta2m31_Nubar)*(L_osc_baseline/(nuEnergy/1000.));
      phase2_Nubar = 1.27*0.5*(delta2m31-V_fact-matt_delta2m31_Nubar)*(L_osc_baseline/(nuEnergy/1000.));
      phase3_Nubar = 1.27*matt_delta2m31_Nubar*(L_osc_baseline/(nuEnergy/1000.));
      /////////////////NuMu+NuMubar survival///////////////////////////////
      P_s_NuMu1 = cos(matt_theta13_Nu)*cos(matt_theta13_Nu)*4.0*sin2theta23*cos2theta23*sin(phase1_Nu)*sin(phase1_Nu);
      P_s_NuMu2 = sin(matt_theta13_Nu)*sin(matt_theta13_Nu)*4.0*sin2theta23*cos2theta23*sin(phase2_Nu)*sin(phase2_Nu);
      P_s_NuMu3 = sin2theta23*sin2theta23*(sin(2*matt_theta13_Nu)*sin(2*matt_theta13_Nu))*sin(phase3_Nu)*sin(phase3_Nu);
      P_s_NuMubar1 = cos(matt_theta13_Nubar)*cos(matt_theta13_Nubar)*4.0*sin2theta23*cos2theta23*sin(phase1_Nubar)*sin(phase1_Nubar);
      P_s_NuMubar2 = sin(matt_theta13_Nubar)*sin(matt_theta13_Nubar)*4.0*sin2theta23*cos2theta23*sin(phase2_Nubar)*sin(phase2_Nubar);
      P_s_NuMubar3 = sin2theta23*sin2theta23*(sin(2*matt_theta13_Nubar)*sin(2*matt_theta13_Nubar))*sin(phase3_Nubar)*sin(phase3_Nubar);
      P_s_NuMu = 1.0 - P_s_NuMu1 - P_s_NuMu2 - P_s_NuMu3;
      P_s_NuMubar = 1.0 - P_s_NuMubar1 - P_s_NuMubar2 - P_s_NuMubar3;
      /////////////////NuE+NuEbar survival///////////////////////////////
      P_s_NuE = 1.0 - ((sin(2.0*matt_theta13_Nu)*sin(2.0*matt_theta13_Nu))*sin(phase3_Nu)*sin(phase3_Nu));
      P_s_NuEbar = 1.0 - ((sin(2.0*matt_theta13_Nubar)*sin(2.0*matt_theta13_Nubar))*sin(phase3_Nubar)*sin(phase3_Nubar));
      /////////////////Transition///////////////////////////////
      P_NuEtoNuMu = sin2theta23*(sin(2.0*matt_theta13_Nu)*sin(2.0*matt_theta13_Nu))*sin(phase3_Nu)*sin(phase3_Nu);
      P_NuEbartoNuMubar = sin2theta23*(sin(2.0*matt_theta13_Nubar)*sin(2.0*matt_theta13_Nubar))*sin(phase3_Nubar)*sin(phase3_Nubar);
      if (init_nuID == 12) osc_weight = P_s_NuE;
      if (init_nuID == -12) osc_weight = P_s_NuEbar;
      if (init_nuID == 14) osc_weight = P_s_NuMu;
      if (init_nuID == -14) osc_weight = P_s_NuMubar;
    }
    */
    Npe_LPMT->Fill(log10(trueNPE_LPMT_CD), osc_weight);
    Ev->Fill(log10(nuEnergy),osc_weight);
    if ((CCint==1 && abs(init_lepID)==(id_family)) || (NCint==1 && abs(init_lepID)==(id_family+1))) {
      Ev_sgn->Fill(log10(nuEnergy),osc_weight);
      Npe_LPMT_sgn->Fill(log10(trueNPE_LPMT_CD), osc_weight);
    }
    if (newVradius>16000. || trueNPE_LPMT_WP > 60.) continue;
    Npe_LPMT_fidcuts->Fill(log10(trueNPE_LPMT_CD), osc_weight); //inclusive spectrum after fid cuts
    Ev_fidcuts->Fill(log10(nuEnergy),osc_weight);
    if ((family == "e" && Tres_RMS>cut_tres) || log10(trueNPE_LPMT_CD) < lowedgeNPE) continue;
    if ((family == "mu" && Tres_RMS<cut_tres) || log10(trueNPE_LPMT_CD) < lowedgeNPE) continue;
    Npe_LPMT_allcuts->Fill(log10(trueNPE_LPMT_CD), osc_weight);
    Ev_allcuts->Fill(log10(nuEnergy),osc_weight);
    if ((CCint==1 && abs(init_lepID)==(id_family)) || (NCint==1 && abs(init_lepID)==(id_family+1))) {
      Npe_LPMT_sgn_allcuts->Fill(log10(trueNPE_LPMT_CD), osc_weight);	
      Ev_sgn_allcuts->Fill(log10(nuEnergy),osc_weight);
    } else {
      Npe_LPMT_bkg_allcuts->Fill(log10(trueNPE_LPMT_CD), osc_weight);
      Ev_bkg_allcuts->Fill(log10(nuEnergy),osc_weight);
    }
  }

  Npe_LPMT->Write();
  Npe_LPMT_sgn->Write();
  Npe_LPMT_fidcuts->Write();
  Npe_LPMT_allcuts->Write();
  Npe_LPMT_sgn_allcuts->Write();
  Npe_LPMT_bkg_allcuts->Write();
  Ev->Write();
  Ev_sgn->Write();
  Ev_fidcuts->Write();
  Ev_allcuts->Write();
  Ev_sgn_allcuts->Write();
  Ev_bkg_allcuts->Write();
  std::cout<<"DATA NPE ARRAY"<<std::endl;
  myNPE_all << binsNPE << "\n";
  myNPE_sgn << binsNPE << "\n";
  myNPE_fidcuts << binsNPE << "\n";
  myNPE_allcuts << binsNPE << "\n";
  myNPE_sgn_allcuts << binsNPE << "\n";
  for (int jj=1; jj<=binsNPE; jj++) {
    std::cout << Npe_LPMT_allcuts->GetBinContent(jj) << "\t";
    myNPE_all << Npe_LPMT->GetBinContent(jj) << "\t";
    myNPE_sgn << Npe_LPMT_sgn->GetBinContent(jj) << "\t";
    myNPE_fidcuts << Npe_LPMT_fidcuts->GetBinContent(jj) << "\t";
    myNPE_allcuts << Npe_LPMT_allcuts->GetBinContent(jj) << "\t";
    myNPE_sgn_allcuts << Npe_LPMT_sgn_allcuts->GetBinContent(jj) << "\t";
    myNPEbins << Npe_LPMT->GetBinCenter(jj) << "\t";
  }
  for (int ii=1; ii<=binsE; ii++) {
    mytrueenergy_fromdata_all << Ev->GetBinContent(ii) << "\t";
    mytrueenergy_fromdata_sgn << Ev_sgn->GetBinContent(ii) << "\t";
    mytrueenergy_fromdata_fidcuts << Ev_fidcuts->GetBinContent(ii) << "\t";
    mytrueenergy_fromdata_allcuts << Ev_allcuts->GetBinContent(ii) << "\t";
    mytrueenergy_fromdata_sgn_allcuts << Ev_sgn_allcuts->GetBinContent(ii) << "\t";
  }
  std::cout<<std::endl;
  myNPE_all.close();
  myNPE_sgn.close();
  myNPE_fidcuts.close();
  myNPE_allcuts.close();
  myNPE_sgn_allcuts.close();
  mytrueenergy_fromdata_all.close();
  mytrueenergy_fromdata_sgn.close();
  mytrueenergy_fromdata_fidcuts.close();
  mytrueenergy_fromdata_allcuts.close();
  mytrueenergy_fromdata_sgn_allcuts.close();
  myNPEbins.close();
  
  std::cout << filenameA1 << " created" << std::endl;
  std::cout << filenameA2 << " created" << std::endl;
  std::cout << filenameA4 << " created" << std::endl;
  std::cout << filename11 << " created" << std::endl;
  std::cout << filenameS1 << " created" << std::endl;
  std::cout << filenameA3 << " created" << std::endl;
  std::cout << filenameQ1 << " created" << std::endl;
  std::cout << filenameF1 << " created" << std::endl;
  std::cout << filename33 << " created" << std::endl;
  std::cout << filenameS3 << " created" << std::endl;
  std::cout << filename44 << " created" << std::endl;
  f_out->Close();
}

void Data::GetFlux(Int_t binsE, Float_t lowedgeE, Float_t upedgeE, Int_t binsNPE, Float_t lowedgeNPE, Float_t upedgeNPE, std::string outfold) {
  std::cout << "GET PREDICTED FLUX" <<std::endl;
  int counter = 0;
  int vec_index = 0;
  float HondaLedge;
  float HondaRedge;
  float flux_HondaLedge_interp;
  float flux_HondaRedge_interp;
  sprintf(ext_filename, "%s/Matplot_%i_%i.root",outfold.c_str(),binsE,binsNPE);
  TFile *f_out = new TFile(ext_filename, "UPDATE");
  TVectorD flux_interp;
  TVectorD binintegral;
  flux_interp.ResizeTo(binsE+1);
  binintegral.ResizeTo(binsE);
  binwidth.ResizeTo(binsE);
  char* filenameH = new char[128];
  sprintf(filenameH,"%s/%s_%i_%i.txt",outfold.c_str(),"HondaFlux",binsE,binsNPE);
  std::ofstream Hflux;
  Hflux.open(filenameH);
  char* filename_sourceflux = new char[128];
  sprintf(filename_sourceflux,"%s",_sourceflux.c_str());                                                                                        
  std::ifstream Flux_Honda(filename_sourceflux);
  float value_E;
  float value_NuMu;
  float value_NuMubar;
  float value_NuE;
  float value_NuEbar;
  std::vector <float> Honda_E;
  std::vector <float> Honda_spec;
  Honda_E.clear();
  Honda_spec.clear();
  float binlogstep = (upedgeE-lowedgeE)/float(binsE);
  while (Flux_Honda >> value_E >> value_NuMu >> value_NuMubar >> value_NuE >> value_NuEbar) {
    counter += 1;
    Honda_E.push_back(log10(value_E*1000.));
    if (family == "e") Honda_spec.push_back(value_NuE+value_NuEbar);
    if (family == "mu") Honda_spec.push_back(value_NuMu+value_NuMubar);
  }
  Hwidth.ResizeTo(counter);
  std::cout << "found " << counter << " bins in Honda " << std::endl;
  while(binlowedge[0] >= (Honda_E[vec_index]+0.025)) {
    vec_index +=1;
  }
  HondaLedge = (Honda_E[vec_index]+Honda_E[vec_index+1])/2.;
  flux_interp[0] = (((Honda_spec[vec_index-1]-Honda_spec[vec_index])*(binlowedge[0]-Honda_E[vec_index]))/(Honda_E[vec_index-1]-Honda_E[vec_index]))+Honda_spec[vec_index];
  flux_HondaLedge_interp = (Honda_spec[vec_index]+Honda_spec[vec_index+1])/2.;

  for (int kk=1; kk<=binsE; kk++) {
    binintegral[kk-1] = .0;
    binwidth[kk-1] = (pow(10.,lowedgeE+(kk*binlogstep)) - pow(10.,lowedgeE+((kk-1)*binlogstep)))/1000.; //bin width [GeV]
    while(binlowedge[kk] >= (Honda_E[vec_index]+0.025)) {
      vec_index +=1;
      Hwidth[vec_index] = (pow(10.,Honda_E[vec_index]+0.025) - pow(10.,Honda_E[vec_index-1]+0.025))/1000.; //[GeV]
      binintegral[kk-1] += (Honda_spec[vec_index]*Hwidth[vec_index]);
    }
    flux_interp[kk] = (((Honda_spec[vec_index-1]-Honda_spec[vec_index])*(binlowedge[kk]-Honda_E[vec_index]))/(Honda_E[vec_index-1]-Honda_E[vec_index]))+Honda_spec[vec_index];
    //std::cout << Honda_E[vec_index-1]+0.025 << "\t" << binlowedge[kk] << "\t" << Honda_E[vec_index]+0.025 << std::endl;
    //std::cout << Honda_spec[vec_index-1] << "\t" << flux_interp[kk] << "\t" << Honda_spec[vec_index] << std::endl;
    //HondaRedge = (Honda_E[vec_index-1]+Honda_E[vec_index])/2.;
    HondaRedge = (Honda_E[vec_index-1]+Honda_E[vec_index])/2.;
    flux_HondaRedge_interp = (Honda_spec[vec_index-1]+Honda_spec[vec_index])/2.;
    binintegral[kk-1] -= (Honda_spec[vec_index]*Hwidth[vec_index]);
    binintegral[kk-1] += ((flux_interp[kk-1]+flux_HondaLedge_interp)*(HondaLedge-binlowedge[kk-1]))/2.; //left polygon
    binintegral[kk-1] += ((flux_interp[kk]+flux_HondaRedge_interp)*(HondaRedge-binlowedge[kk]))/2.; //right polygon
    binintegral[kk-1] = (binintegral[kk-1]/binwidth[kk-1]); //energy normalization in GeV^-1
    HondaLedge = (Honda_E[vec_index]+Honda_E[vec_index+1])/2.;
    flux_HondaLedge_interp = (Honda_spec[vec_index]+Honda_spec[vec_index+1])/2.;
    Hflux << binintegral[kk-1]*0.0001 << "\t";
  }
  TGraph *Honda_Flux = new TGraph(bincenter,binintegral);
  Honda_Flux->GetXaxis()->SetTitle("log_{10}(E [MeV])");
  Honda_Flux->GetYaxis()->SetTitle("Flux [m^{-2} s^{-1} sr^{-1} GeV^{-1}]");
  Honda_Flux->SetMarkerStyle(20);
  Honda_Flux->SetMarkerColor(kBlue);
  Honda_Flux->SetMarkerSize(2);
  Honda_Flux->SetLineColor(kBlue);
  Honda_Flux->SetLineWidth(4);
  Honda_Flux->Write("Honda_rebinned_flux");
  std::cout << filenameH << " created" << std::endl;
  std::cout << ext_filename << " created" << std::endl;
  f_out->Close();
}

void Data::GetFluxSpline(Int_t binsE, Float_t lowedgeE, Float_t upedgeE, Int_t binsNPE, Float_t lowedgeNPE, Float_t upedgeNPE, std::string outfold) {
  std::cout << "GET PREDICTED FLUX WITH SPLINE" <<std::endl;
  int counter = 0;
  sprintf(ext_filename, "%s/Matplot_%i_%i.root",outfold.c_str(),binsE,binsNPE);
  TFile *f_out = new TFile(ext_filename, "UPDATE");
  TVectorD orflux_honda;
  TVectorD orenergy_honda;
  TVectorD binintegral;
  binintegral.ResizeTo(binsE);
  binwidth.ResizeTo(binsE);
  char* filenameH = new char[128];
  sprintf(filenameH,"%s/%s_%i_%i.txt",outfold.c_str(),"HondaFlux",binsE,binsNPE);
  std::ofstream Hflux;
  Hflux.open(filenameH);
  char* filename_sourceflux = new char[128];
  sprintf(filename_sourceflux,"%s",_sourceflux.c_str());                                                                                        
  std::ifstream Flux_Honda(filename_sourceflux);
  float value_E;
  float value_NuMu;
  float value_NuMubar;
  float value_NuE;
  float value_NuEbar;
  std::vector <float> Honda_E;
  std::vector <float> Honda_spec;
  Honda_E.clear();
  Honda_spec.clear();
  while (Flux_Honda >> value_E >> value_NuMu >> value_NuMubar >> value_NuE >> value_NuEbar) {
    counter += 1;
    Honda_E.push_back(log10(value_E*1000.));
    if (family == "e") Honda_spec.push_back(value_NuE+value_NuEbar);
    if (family == "mu") Honda_spec.push_back(value_NuMu+value_NuMubar);
  }
  orflux_honda.ResizeTo(counter);
  orenergy_honda.ResizeTo(counter);
  for (int bb=0; bb<counter; bb++) {
    orenergy_honda[bb] = (Honda_E)[bb];
    orflux_honda[bb] = 0.0001*(Honda_spec)[bb];
  }
  Double_t arr_E[counter];
  Double_t arr_flux[counter];
  for (int aa=0; aa<counter; aa++) {
    arr_flux[aa] = 0.0001*(Honda_spec)[aa];
    arr_E[aa] = (Honda_E)[aa];
  }
  TSpline3 *sp_honda = new TSpline3("Cubic Spline", arr_E, arr_flux, counter, "b2e2", 0, 0);
  for (int kk=0; kk<binsE; kk++) {
    binintegral[kk] = sp_honda->Eval(bincenter[kk]);
    Hflux << binintegral[kk] << "\t";
  }
  TGraph *Honda_original = new TGraph(orenergy_honda,orflux_honda);
  Honda_original->SetLineColor(kBlue);
  Honda_original->SetLineStyle(9);
  Honda_original->SetLineWidth(4);
  Honda_original->SetMarkerColor(kBlue);
  Honda_original->SetMarkerSize(2);
  Honda_original->SetMarkerStyle(21);
  Honda_original->Write("Honda_original_flux");
  TGraph *Honda_Flux = new TGraph(bincenter,binintegral);
  Honda_Flux->GetXaxis()->SetTitle("log_{10}(E [MeV])");
  Honda_Flux->GetYaxis()->SetTitle("Flux [m^{-2} s^{-1} sr^{-1} GeV^{-1}]");
  Honda_Flux->SetMarkerStyle(20);
  Honda_Flux->SetMarkerColor(kBlue);
  Honda_Flux->SetMarkerSize(2);
  Honda_Flux->SetLineColor(kBlue);
  Honda_Flux->SetLineWidth(4);
  Honda_Flux->Write("Honda_rebinned_flux");
  std::cout << filenameH << " created" << std::endl;
  std::cout << ext_filename << " created" << std::endl;
  f_out->Close();
}

void Data::Loop() {
  std::cout << "Loop" <<std::endl;
}
