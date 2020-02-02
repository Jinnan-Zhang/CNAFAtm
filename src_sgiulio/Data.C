#define Data_cxx
#include "Data.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include "srtutils.cc"

Float_t Data::great_circle_distance(Float_t theta1, Float_t phi1, Float_t theta2, Float_t phi2)
{
  Float_t delta_theta = std::abs(theta1-theta2);
  Float_t delta_phi = std::abs(phi1-phi2);
  Float_t x = ( (pow(sin(delta_theta/2.) , 2)) + (sin(theta1)*sin(theta2) * (pow(sin(delta_phi/2.) , 2))) );
  return 2.*asin(sqrt(x));
}

void Data::Loop()
{
  static const int NPMTS = 10;
  //static const int NMU = 11;
  std::vector < std::pair <float,float> > pairCID;
  std::vector < std::pair <float,float> > hit_pairTID;
  std::vector < std::pair <float,float> > hit_pairCID;
  std::vector<float> weights_WP_PMT;
  int pmtID = 0;
  int counter = 0;
  int allcounter = 0;;
  Float_t mean_theta_WP;
  Float_t mean_phi_WP;
  Float_t mean_theta_CD;
  Float_t mean_phi_CD;
  float X_hit = 0.;
  float Y_hit = 0.;
  float Z_hit = 0.;
  float X_mean = 0.;
  float Y_mean = 0.;
  float Z_mean = 0.;
  //TVectorF _Nbin;
  //TVectorF _Ebin;
  TFile *f_out = new TFile("Plot/Mu_ana.root", "RECREATE");
  /*
  TH2D *WP_PMT_MAP_h = new TH2D("WP_PMT_MAP_h","",360,0.,360.,180,0.,180.);
  TH2D *CD_PMT_MAP_h = new TH2D("CD_PMT_MAP_h","",360,0.,360.,180,0.,180.);
  WP_PMT_MAP_h->SetMarkerStyle(20);
  WP_PMT_MAP_h->SetMarkerColor(kBlue);
  CD_PMT_MAP_h->SetMarkerColor(kRed);
  */
  TH1F *Ang_dist_WP_CD_h = new TH1F("Ang_dist_WP_CD_h","",180,0.,180.);
  TH2F *Npmt_VS_logEmu_WP_h = new TH2F("Npmt_VS_Emu_WP_h","",100,-1.0,6.1,1000,0., 1000.0);

  std::cout << "Looping over " << fChain->GetEntries() << " entries... " << std::endl;
  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    //Long64_t jentry = 396;
    Long64_t ientry = LoadTree(jentry);
    //if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    //if(jentry%10==0) cout <<"processing event "<<jentry<<endl;
    //std::cout <<"processing event "<<jentry<<std::endl;
    //if(jentry!=250) continue;

    if (trueNPE_LPMT_WP == 0 || trueNPE_LPMT_CD < 1.E5) continue;

    weights_WP_PMT.clear();
    /*
    for (int aa=0; unsigned(aa) < hit_pairTID.size(); aa++) {
      hit_pairTID[aa].first.clear();
      hit_pairTID[aa].second.clear();
    }
    for (int bb=0; unsigned(bb) < pairCID.size(); bb++) {
      pairCID[bb].first.clear();
      pairCID[bb].second.clear();
      }*/
    hit_pairTID.clear();
    pairCID.clear();
    hit_pairCID.clear();

    for (int kk=0; unsigned(kk) < LPMT_WP_PMTID->size(); kk++) {
      hit_pairTID.push_back( std::make_pair((*LPMT_WP_PMTID)[kk], (*hit_time_LPMT_WP)[kk]) );
      hit_pairCID.push_back( std::make_pair((*LPMT_WP_PMTID)[kk], (*LPMT_WP_Charge)[kk]) );
    }
    std::sort(hit_pairTID.begin(), hit_pairTID.end());
    std::sort(hit_pairCID.begin(), hit_pairCID.end());
    pmtID = (hit_pairTID[0].first);

    int qq = 0;
    while (unsigned(qq) < (hit_pairTID.size())) {
      while ((hit_pairTID[qq].first) == pmtID) {
	if ((hit_pairTID[qq].second) > 200.) {
	qq += 1;
	} else {
	  counter += (hit_pairCID[qq].second);
	  qq += 1;
	}
      }
      pairCID.push_back( std::make_pair(counter, pmtID) );
      counter = 0;
      pmtID = (hit_pairTID[qq].first);
    }
    counter = 0;
    std::sort(pairCID.begin(), pairCID.end());
    std::reverse(pairCID.begin(), pairCID.end());

    Npmt_VS_logEmu_WP_h->Fill(log10(lepEnergy),pairCID.size());
    //if (pairCID.size() > 60) continue;

    /*
    for (int jj=0; jj<(pairCID.size()); jj++) {
      std::cout<<"PMTID: "<<pairCID[jj].second<<"\t"<<"Charge: "<<pairCID[jj].first<<std::endl;
      }
    */
    ///////////////////////////////////WP//////////////////////////////////////
    /*
    for (int kk=0; kk<NPMTS; kk++) {
      allcounter += pairCID[kk].first;
    }
    */
    for (int kk=0; kk<NPMTS; kk++) {
      pmtID = pairCID[kk].second;
      for (int jj=0; unsigned(jj)<(hit_time_LPMT_WP->size()); jj++) {
	if ((*hit_time_LPMT_WP)[jj] > 1200.) continue;
	if ((*LPMT_WP_PMTID)[jj] == pmtID) {
	  X_hit += 20050.0*sin((*theta_hitLPMT_WP)[jj]*(M_PI/180.))*cos((*phi_hitLPMT_WP)[jj]*(M_PI/180.));
	  Y_hit += 20050.0*sin((*theta_hitLPMT_WP)[jj]*(M_PI/180.))*sin((*phi_hitLPMT_WP)[jj]*(M_PI/180.));
	  Z_hit += 20050.0*cos((*theta_hitLPMT_WP)[jj]*(M_PI/180.));
	  counter += (*LPMT_WP_Charge)[jj];
	}
      }
      allcounter += counter;
      //weights_WP_PMT.push_back((pairCID[kk].first)/float(allcounter));
      //std::cout<<(weights_WP_PMT)[kk]<<std::endl;
      X_mean += X_hit*counter;
      Y_mean += Y_hit*counter;
      Z_mean += Z_hit*counter;
      X_hit = 0.;
      Y_hit = 0.;
      Z_hit = 0.;
      counter = 0;
      //WP_PMT_MAP_h->Fill(phi_pos_WP_PMT[kk],theta_pos_WP_PMT[kk],weights_WP_PMT[kk]);
    }
    X_mean = (X_mean/float(allcounter));
    Y_mean = (Y_mean/float(allcounter));
    Z_mean = (Z_mean/float(allcounter));
    allcounter = 0;
    mean_theta_WP = acos(Z_mean/sqrt((X_mean*X_mean)+(Y_mean*Y_mean)+(Z_mean*Z_mean)));
    if (atan2(Y_mean,X_mean) >= 0.) {
      mean_phi_WP = atan2(Y_mean,X_mean);
    } else {
      mean_phi_WP = atan2(Y_mean,X_mean)+(2*M_PI);
    }
    X_mean = 0.;
    Y_mean = 0.;
    Z_mean = 0.;
    counter = 0;
    //mean_theta_WP = (TMath::Mean(theta_pos_WP_PMT.begin(),theta_pos_WP_PMT.end()))*(M_PI/180.);
    //mean_phi_WP = (TMath::Mean(phi_pos_WP_PMT.begin(),phi_pos_WP_PMT.end()))*(M_PI/180.);

    //////////////////////////////////CD/////////////////////////////////////////////

    for (int ii=0; unsigned(ii)<(hit_time_LPMT_CD->size()); ii++) {
      if ((*hit_time_LPMT_CD)[ii] < 50.) {
	X_hit = 20050.0*sin((*theta_hitLPMT_CD)[ii]*(M_PI/180.))*cos((*phi_hitLPMT_CD)[ii]*(M_PI/180.));
	Y_hit = 20050.0*sin((*theta_hitLPMT_CD)[ii]*(M_PI/180.))*sin((*phi_hitLPMT_CD)[ii]*(M_PI/180.));
	Z_hit = 20050.0*cos((*theta_hitLPMT_CD)[ii]*(M_PI/180.));
	counter += (*LPMT_CD_Charge)[ii];
	//CD_PMT_MAP_h->Fill((*phi_hitLPMT_CD)[ii],(*theta_hitLPMT_CD)[ii]);
      }
      X_mean += X_hit*counter;
      Y_mean += Y_hit*counter;
      Z_mean += Z_hit*counter;
      allcounter += counter;
      counter = 0;
    }
    X_mean = X_mean/float(allcounter);
    Y_mean = Y_mean/float(allcounter);
    Z_mean = Z_mean/float(allcounter);
    mean_theta_CD = acos(Z_mean/sqrt((X_mean*X_mean)+(Y_mean*Y_mean)+(Z_mean*Z_mean)));
    if (atan2(Y_mean,X_mean) >= 0.) {
      mean_phi_CD = atan2(Y_mean,X_mean);
    } else {
      mean_phi_CD = atan2(Y_mean,X_mean)+(2*M_PI);
    }
    counter = 0;
    allcounter = 0;
    X_hit = 0.;
    Y_hit = 0.;
    Z_hit = 0.;
    X_mean = 0.;
    Y_mean = 0.;
    Z_mean = 0.;

    Ang_dist_WP_CD_h->Fill((great_circle_distance(mean_theta_WP,mean_phi_WP,mean_theta_CD,mean_phi_CD))*(180./M_PI));
    
    std::cout<<"ID: "<<evtID<<"\t"<<"E: "<<lepEnergy<<"\t"<<"Z: "<<zenith_vert<<"\t"<<"D: "<<dist_0<<"\t"<<"WP_phi: "<<mean_phi_WP*(180./M_PI)<<"\t"<<"WP_theta: "<<mean_theta_WP*(180./M_PI)<<"\t"<<"CD phi: "<<mean_phi_CD*(180./M_PI)<<"\t"<<"CD_theta: "<<mean_theta_CD*(180./M_PI)<<"\t"<<"DIST: "<<(great_circle_distance(mean_theta_WP,mean_phi_WP,mean_theta_CD,mean_phi_CD))*(180./M_PI)<<"\t"<<pairCID.size()<<"\t"<<trueNPE_LPMT_WP<<std::endl;

    //WP_PMT_MAP_h->Reset();
    //CD_PMT_MAP_h->Reset();
    //WP_PMT_MAP_h->Write();
    //CD_PMT_MAP_h->Write();

    } //end of loop on events

    Ang_dist_WP_CD_h->Write();
    Npmt_VS_logEmu_WP_h->Write();
    f_out->Close();

}
