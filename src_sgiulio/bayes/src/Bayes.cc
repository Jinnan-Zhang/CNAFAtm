#include "Bayes.h"
#include "srtutils.cc"

Bayes::Bayes(){
  _noEnu = 0;
  _noNPE = 0;
}

void Bayes::Init(std::string config){

  std::cout<<"**********************************************************"<<std::endl;
  std::cout<<"Bayes::Initialize:reading configuration file & init var  *"<<std::endl;
  std::cout<<"**********************************************************"<<std::endl<<std::endl;

  //energy normalization
  _Enormfile = GetFileName("E_NORM_FILE",config.c_str());
  //matrix file for signal
  _matfile_sgn = GetFileName("MAT_FILE_SGN",config.c_str());
  //matrix file for background
  _matfile_bkg = GetFileName("MAT_FILE_BKG",config.c_str());
  //datafile
  _NPE_file = GetFileName("NPE_FILE",config.c_str());
  //databins
  _NPE_bins = GetFileName("NPE_BINS_FILE",config.c_str());
  //binsfile
  _E_bins = GetFileName("E_BINS_FILE",config.c_str());
  //true energy file from fake data
  _trueE_file = GetFileName("TRUE_E_FILE",config.c_str());
  //true energy flux from Honda
  _trueE_flux = GetFileName("TRUE_E_FLUX",config.c_str());
  //contamination file
  _contE_file = GetFileName("CONT_E_FILE",config.c_str());
  //external prior file
  _prior_file = GetFileName("PRIOR_FILE",config.c_str());
  //output spectrum
  _unf_spectrum = GetFileName("UNFOLDED_SPECTRUM",config.c_str());
  // input folder
  _input_folder = GetFileName("INPUT_FOLDER",config.c_str());
  // output folder
  _output_folder = GetFileName("OUTPUT_FOLDER",config.c_str());
  // external Honda flux file
  _Honda_str = GetFileName("HONDA_FLUX_FILE",config.c_str());
  // external SK file
  _SK_file = GetFileName("SK_FLUX_FILE",config.c_str());
  // number of iterations  
  num_iter = GetValue("N_ITER",config.c_str());
  MC_D_R = GetValue("MC-DATA-RATIO",config.c_str());
  family = GetValue("FAMILY",config.c_str());
  TString _niter = num_iter;
  Niter = atoi(_niter);

  std::cout << "==========================================" << std::endl;
  std::cout << "= Init::                                 =" << std::endl;
  std::cout << "= MATRIX file set to: " << _matfile_sgn << std::endl;
  std::cout << "= DATA file set to: " << _NPE_file << std::endl;
  std::cout << "= BINS file set to: " << _E_bins << std::endl;
  std::cout << "= Input folder set to: " << _input_folder << std::endl;
  std::cout << "= Output folder set to: " << _output_folder << std::endl;
  std::cout << "==========================================" << std::endl;
}

void Bayes::ReadMAT()
{
  std::cout << "Bayes::ReadMATRIX: " << std::endl;
  char* Aname = new char[256];
  char* inputmat = new char[256];
  sprintf(inputmat, "%s/%s",_input_folder.c_str(),_matfile_sgn.c_str());
  std::cout<<"Input Likelihood matrix is: "<<inputmat<<std::endl;
  std::ifstream matfile(inputmat);
  char* inputnorm = new char[256];
  sprintf(inputnorm, "%s/%s",_input_folder.c_str(),_Enormfile.c_str());
  std::cout<<"Input Normalization file is: "<<inputnorm<<std::endl;
  std::ifstream normfile(inputnorm);
  if(!matfile.good()){
    std::cout<<"** ERROR! ** Unable to open MATRIX file" << std::endl;
    return;
  }
  matfile >> _noEnu >> _noNPE >> lowedge_E >> upedge_E >> lowedge_NPE >> upedge_NPE;
  std::cout << "ReadMAT::noEnu & noNPE:" << _noEnu <<" " <<  _noNPE << std::endl;
  sprintf(ext_filename, "%s/plot_%i_%i.root",_output_folder.c_str(),_noEnu,_noNPE);
  TFile *f_out = new TFile(ext_filename, "RECREATE");
  sprintf(Aname,"%s/Lmatrix_%i_%i.txt",_output_folder.c_str(),_noEnu,_noNPE);
  std::ofstream likematrix;
  likematrix.open(Aname);
  TH2F *lik_matrix = new TH2F("lik_matrix","Likelihood matrix",_noEnu,lowedge_E-3,upedge_E-3,_noNPE,lowedge_NPE,upedge_NPE);
  TH2F *sgn_matrix = new TH2F("sgn_matrix","",_noNPE,lowedge_NPE,upedge_NPE,_noEnu,lowedge_E,upedge_E);
  TH2F *bkg_matrix = new TH2F("bkg_matrix","",_noNPE,lowedge_NPE,upedge_NPE,_noEnu,lowedge_E,upedge_E);
  lik_matrix->GetYaxis()->SetTitle("log_{10}(NPE)");
  lik_matrix->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
  sgn_matrix->GetXaxis()->SetTitle("log_{10}(NPE)");
  sgn_matrix->GetYaxis()->SetTitle("log_{10}(E_{#nu}) [GeV]");
  bkg_matrix->GetXaxis()->SetTitle("log_{10}(NPE)");
  bkg_matrix->GetYaxis()->SetTitle("log_{10}(E_{#nu}) [GeV]");
  _En.ResizeTo(_noEnu);
  _Aji.ResizeTo(_noNPE,_noEnu);
  _MUNFij.ResizeTo(_noEnu,_noNPE);
  _pCi.ResizeTo(_noEnu);
  _efficiency.ResizeTo(_noEnu);
  
  for(int i=0; i<_noEnu; i++){  
    normfile >> _En[i];
    //_En[i] = _En[i]*10.;
    _efficiency[i] = 0.;
    for(int j=0; j<_noNPE; j++){
      matfile >> _Aji[j][i]; 
      likematrix << float(_Aji[j][i])/float(_En[i]) << "\t";
      lik_matrix->SetBinContent(i+1,j+1,float(_Aji[j][i])/float(_En[i]));
      std::cout << float(_Aji[j][i])/float(_En[i]) << "\t";
    }
    std::cout << "\n";
    likematrix << "\n";
  }
  std::cout << std::endl;
  likematrix.close();
  lik_matrix->Write();

  std::cout<<"Bayes::Efficiency"<<std::endl;
  for(int i=0; i<_noEnu; i++){
    for(int j=0; j<_noNPE; j++){
      _efficiency[i] = _efficiency[i] + (float(_Aji[j][i])/float(_En[i]));
    }
    std::cout << _efficiency[i] << "\t";
  }
  f_out->Close();
  std::cout<<std::endl;
}

void Bayes::SetPrior(std::string priorname){
  std::cout<<"Bayes::SetPrior()"<<std::endl;
  sprintf(ext_filename, "%s/plot_%i_%i.root",_output_folder.c_str(),_noEnu,_noNPE);
  TFile *f_out = new TFile(ext_filename, "UPDATE");
  char* Pname = new char[256];
  sprintf(Pname,"%s/Prior_%s_%i.txt",_output_folder.c_str(),priorname.c_str(),_noEnu);
  std::ofstream priorarray;
  priorarray.open(Pname);
  float norm = 0.;
  _pCi.ResizeTo(_noEnu);

  if(priorname == "uniform"){
    for(int i=0;i<_noEnu;i++){
      _pCi[i] = 1./float(_noEnu);
    }

  } else if(priorname == "PowerLaw"){
    float powindex = 2.7;
    for(int i=0;i<_noEnu;i++){
      _pCi[i] = pow(i+1,-powindex);
      norm += _pCi[i];
    }
  } else if(priorname == "external"){
    char* inputprior = new char[256];
    sprintf(inputprior, "%s/%s",_input_folder.c_str(),_prior_file.c_str());
    std::cout<<"External prior is: "<<inputprior<<std::endl;
    std::ifstream priorfile(inputprior);
    for(int i=0;i<_noEnu;i++){
      priorfile >> _pCi[i];
      norm += _pCi[i];
    }
  }
  
  for(int i=0;i<_noEnu;i++){
    _pCi[i] = _pCi[i]/norm;
  }

  for(int i=0;i<_noEnu;i++){
    std::cout << _pCi[i] << "\t";
    priorarray << _pCi[i] << "\t";
  }
  std::cout << std::endl;
  priorarray.close();
  f_out->Close();
}

void Bayes::ReadDATA()
{
  sprintf(ext_filename, "%s/plot_%i_%i.root",_output_folder.c_str(),_noEnu,_noNPE);
  TFile *f_out = new TFile(ext_filename, "UPDATE");
  std::cout << "Bayes::ReadDATA: " << std::endl;
  char* inputdata = new char[256];
  sprintf(inputdata, "%s/%s",_input_folder.c_str(),_NPE_file.c_str());
  std::cout<<"Input data file is: "<<inputdata<<std::endl;
  std::ifstream NPE_file(inputdata);
  char* inputdatabins = new char[256];
  sprintf(inputdatabins, "%s/%s",_input_folder.c_str(),_NPE_bins.c_str());
  std::cout<<"Input data bins file is: "<<inputdatabins<<std::endl;
  std::ifstream NPE_bins(inputdatabins);
  char* Dname = new char[256];
  sprintf(Dname,"%s/Data_%i.txt",_output_folder.c_str(),_noNPE);
  std::ofstream dataarray;
  dataarray.open(Dname); 
  if(!NPE_file.good()) {
    std::cout<<"** ERROR! ** Unable to open DATA file" << std::endl;
  } else {
    NPE_file >> _noNPE;
    std::cout << "ReadDATA:: noNPE:" << _noNPE << std::endl;
    _NPEbins.ResizeTo(_noNPE);
    _nNPEj.ResizeTo(_noNPE);
    for(int j=0; j<_noNPE; j++){
      NPE_file >> _nNPEj[j];
      NPE_bins >> _NPEbins[j];
      std::cout << _nNPEj[j] << "\t";
      dataarray << _nNPEj[j] << "\t";
    }
  }
  std::cout << std::endl;
  dataarray.close();
  TGraph *NPE_input = new TGraph(_NPEbins,_nNPEj);
  NPE_input->Write("NPE_input_spectrum");
  f_out->Close();
}


void Bayes::Unfold()
{
  sprintf(ext_filename, "%s/plot_%i_%i.root",_output_folder.c_str(),_noEnu,_noNPE);
  TFile *f_out = new TFile(ext_filename, "UPDATE");
  std::cout << "UNFOLDING" << std::endl;
  TH2F *unf_matrix = new TH2F("unf_matrix","Unfolding matrix",_noEnu,lowedge_E-3.0,upedge_E-3.0,_noNPE,lowedge_NPE,upedge_NPE);
  unf_matrix->GetYaxis()->SetTitle("log_{10}(NPE)");
  unf_matrix->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
  char* Uname = new char[256];
  sprintf(Uname,"%s/Umatrix_%i_%i.txt",_output_folder.c_str(),_noNPE,_noEnu);
  std::ofstream unfoldmatrix;
  unfoldmatrix.open(Uname, std::ofstream::out);
  denom.ResizeTo(_noNPE);
  invdenom.ResizeTo(_noNPE);

  for(int j=0; j<_noNPE; j++){
    for(int i=0; i<_noEnu; i++){
      denom[j] = denom[j] + (_Aji[j][i]*_pCi[i]);
    }
  }
  std::cout << std::endl;
  for(int j=0; j<_noNPE; j++){
    if(denom[j] != 0){
      invdenom[j] = 1./denom[j];
    }else { 
      invdenom[j] = 0.;
    }
  }
  for(int j=0; j<_noNPE; j++){
    for(int i=0; i<_noEnu; i++){
      _MUNFij[i][j] = (_Aji[j][i]*_pCi[i]*invdenom[j]);
      std::cout << _MUNFij[i][j] << "\t";
      unfoldmatrix << _MUNFij[i][j] << "\t";
      unf_matrix->SetBinContent(i+1,j+1,_MUNFij[i][j]);
    }
    unfoldmatrix << "\n";
    std::cout << std::endl;
  }
  unfoldmatrix.close();
  unf_matrix->Write();
  f_out->Close();
}

void Bayes::RawFlux()
{
  std::ifstream Honda_unosc_flux("/storage/DATA-02/juno/Users/sgiulio/Atmo/HondaFlux/juno-ally-01-01-solmin_raw.d");
  char* Honda_F = new char[256];
  sprintf(Honda_F, "%s", _Honda_str.c_str());
  std::ifstream Honda_file(Honda_F);
  char* SK_F = new char[256];
  sprintf(SK_F, "%s", _SK_file.c_str());
  std::ifstream SK_flux_file(SK_F);
  sprintf(ext_filename, "%s/plot_%i_%i.root",_output_folder.c_str(),_noEnu,_noNPE);
  TFile *f_out = new TFile(ext_filename, "UPDATE");
  std::cout << "UNFOLDED SPECTRUM" << std::endl;
  neffects = 0;
  /*
  char* UDout = new char[256];
  sprintf(UDout,"%s/%s_%i_%i.txt",_output_folder.c_str(),_unf_spectrum.c_str(),_noEnu,_noNPE);
  std::ofstream udataarray;
  udataarray.open(UDout);
  */
  TCanvas *cUD = new TCanvas("cUD","Unfolded Spectrum",0,0,800,700);
  //TCanvas *cUDdiff = new TCanvas("cUDdiff","Unfolded Spectrum reco-true difference",0,0,800,700);
  float Integral_Ndata = .0;
  float Integral_NHonda = .0;
  TH1F *flux_h = new TH1F("flux_h","",_noEnu,lowedge_E,upedge_E);
  TString MCR = MC_D_R;
  MC_DATA_ratio = atof(MCR);
  _nUNFi.ResizeTo(_noEnu);
  _nUNFi_eff.ResizeTo(_noEnu);
  _Ebins.ResizeTo(_noEnu);
  _trueE.ResizeTo(_noEnu);
  _trueFlux.ResizeTo(_noEnu);
  plot_trueFlux.ResizeTo(_noEnu);
  plot_nUNFi_eff.ResizeTo(_noEnu);
  plot_Ebins.ResizeTo(_noEnu);
  err_nUNFi.ResizeTo(_noEnu);
  _trueE_recoE_ratio.ResizeTo(_noEnu);
  _trueE_recoE_ratio_err.ResizeTo(_noEnu);
  plot_err_nUNFi.ResizeTo(_noEnu);
  err_trueE.ResizeTo(_noEnu);
  err_ratio.ResizeTo(_noEnu);
  errx.ResizeTo(_noEnu);
  errx0.ResizeTo(_noEnu);
  char* inputEbins = new char[256];
  sprintf(inputEbins, "%s/%s",_input_folder.c_str(),_E_bins.c_str());
  std::cout<<"Input energy bins file is: "<<inputEbins<<std::endl;
  std::ifstream E_bins(inputEbins);
  char* inputE = new char[256];
  sprintf(inputE, "%s/%s",_input_folder.c_str(),_trueE_file.c_str());
  std::cout<<"Input energy file is: "<<inputE<<std::endl;
  std::ifstream trueE_file(inputE);
  char* inputF = new char[256];
  sprintf(inputF, "%s/%s",_input_folder.c_str(),_trueE_flux.c_str());
  std::cout<<"Input flux file is: "<<inputF<<std::endl;
  std::ifstream trueE_flux(inputF);
  std::cout << "RECO:  ";
  for(int i=0; i<_noEnu; i++){
    for(int j=0; j<_noNPE; j++){
      _nUNFi[i] = _nUNFi[i] + (_MUNFij[i][j]*_nNPEj[j]);
      neffects += _nUNFi[i];
    }
    E_bins >> _Ebins[i];
    trueE_file >> _trueE[i];
    trueE_flux >> _trueFlux[i];
    _efficiency[i] = (float(_trueE[i]/MC_DATA_ratio)/float(_En[i]));
    _nUNFi_eff[i] = _nUNFi[i]/_efficiency[i];
    std::cout << _nUNFi_eff[i] << "\t";
    Integral_Ndata += _trueE[i];
    Integral_NHonda += _En[i];
    //_trueE_recoE_ratio[i] = float(_nUNFi_eff[i])/float(_trueFlux[i]);
    err_trueE[i] = sqrt(float(_trueFlux[i]));
    if(_nUNFi_eff[i]>1.E-2) {
      err_nUNFi[i] = 0.2*(_nUNFi_eff[i]);
    } else {
      err_nUNFi[i] = 0.25*(_nUNFi_eff[i]);
    }
    /*
    if(_nUNFi_eff[i]>1.E-2) {
      err_nUNFi[i] = sqrt((pow(0.1*(_nUNFi_eff[i]),2))+(1./_nUNFi_eff[i]));
    } else {
      err_nUNFi[i] = sqrt((pow(0.2*(_nUNFi_eff[i]),2))+(1./_nUNFi_eff[i]));
      }*/
    //err_ratio[i] = sqrt((pow(err_nUNFi[i]/_trueFlux[i],2.))+(pow((err_trueE[i]*_nUNFi_eff[i])/(float(_trueFlux[i])*float(_trueFlux[i])),2.)));
    errx0[i] = 0.;
    errx[i] = (upedge_E-lowedge_E)/float(_noEnu);
    //TUTTO IN GeV
    plot_Ebins[i] = _Ebins[i]-3.;
    plot_nUNFi_eff[i] = (_nUNFi_eff[i]*(pow(10.,2*plot_Ebins[i])));
    plot_err_nUNFi[i] = (err_nUNFi[i]*(pow(10.,2*plot_Ebins[i])));
    plot_trueFlux[i] = (_trueFlux[i]*(pow(10.,2*plot_Ebins[i])));
  }
  std::cout << std::endl;
  std::cout << "TRUE:  ";
  for(int i=0; i<_noEnu; i++){
    std::cout<<_trueFlux[i]<<"\t";
    flux_h->SetBinContent(i+1,_nUNFi_eff[i]);
  }
  std::cout << std::endl;
  std::cout << "DATA " << Integral_Ndata << " HONDA " << Integral_NHonda << std::endl;
  TGraphErrors *flux = new TGraphErrors(plot_Ebins,plot_nUNFi_eff,errx0,plot_err_nUNFi);
  //TGraph *flux = new TGraph(_Ebins,_nUNFi_eff);
  TGraph *flux_MC = new TGraph(plot_Ebins,plot_trueFlux);
  int dummy;
  int counter = 0;
  double value_E;
  double value_NuMu;
  double value_NuMubar;
  double value_NuE;
  double value_NuEbar;
  std::vector <double> Honda_E;
  std::vector <double> Honda_spec;
  while (Honda_file >> value_E >> value_NuMu >> value_NuMubar >> value_NuE >> value_NuEbar) {
    counter += 1;
    Honda_E.push_back(value_E);
    if (family == "e") Honda_spec.push_back(value_NuE+value_NuEbar);
    if (family == "mu") Honda_spec.push_back(value_NuMu+value_NuMubar);
  }
  E_Honda.ResizeTo(counter);
  Flux_Honda.ResizeTo(counter);
  for (int kk=0; kk<counter; kk++) {
    E_Honda[kk] = log10((Honda_E)[kk]);
    Flux_Honda[kk] = 0.0001*((Honda_spec)[kk]*((Honda_E)[kk]*(Honda_E)[kk]));
  }
  counter = 0;
  Honda_spec.clear();
  while (Honda_unosc_flux >> value_E >> value_NuMu >> value_NuMubar >> value_NuE >> value_NuEbar) {
    counter += 1;
    Honda_E.push_back(value_E);
    if (family == "e") Honda_spec.push_back(value_NuE+value_NuEbar);
    if (family == "mu") Honda_spec.push_back(value_NuMu+value_NuMubar);
  }
  Flux_Honda_unosc.ResizeTo(counter);
  for (int kk=0;kk<counter;kk++) {                                                                                                      
    Flux_Honda_unosc[kk] = 0.0001*((Honda_spec)[kk]*((Honda_E)[kk]*(Honda_E)[kk]));
  }                                                                                                                                       
  counter = 0;
  TGraph *flux_H = new TGraph(E_Honda,Flux_Honda);
  TGraph *flux_H_unosc = new TGraph(E_Honda,Flux_Honda_unosc);
  double SK_binE, SK_binflux, SK_err;
  std::vector<double> vec_E_SK;
  std::vector<double> vec_Flux_SK;
  std::vector<double> vec_err_SK;
  while (SK_flux_file >> dummy >> SK_binE >> SK_binflux >> SK_err) {
    std::cout<<dummy<<"\t"<<SK_binE<<"\t"<<SK_binflux<<"\t"<<SK_err<<std::endl;
    counter += 1;
    vec_E_SK.push_back(SK_binE);
    vec_Flux_SK.push_back(SK_binflux);
    vec_err_SK.push_back(SK_err);
  }
  E_SK.ResizeTo(counter);
  Flux_SK.ResizeTo(counter);
  errX_SK.ResizeTo(counter);
  err_SK.ResizeTo(counter);
  for (int xx=0; xx<counter; xx++) {
    E_SK[xx] = (vec_E_SK)[xx];
    Flux_SK[xx] = (vec_Flux_SK)[xx];
    errX_SK[xx] = 0.;
    err_SK[xx] = 0.01*((vec_err_SK)[xx]*(vec_Flux_SK)[xx]);
  }
  TGraphErrors *flux_SK = new TGraphErrors(E_SK, Flux_SK, errX_SK, err_SK);
  //TGraph *flux_MC = new TGraph(_Ebins,_trueFlux);
  /*
  if(_noEnu==10) {
    flux->RemovePoint(_noEnu-1);
    flux_MC->RemovePoint(_noEnu-1);
    flux_h->SetBinContent(_noEnu,0);
    fluxratio->RemovePoint(_noEnu-1);
    }*/
  TLegend * legUD = new TLegend(0.15,0.15,0.47,0.3);
  cUD->cd();
  //flux_h->SetFillColor(2);
  //flux_h->SetFillStyle(3005);
  flux_h->SetLineColor(2);
  flux_h->SetLineWidth(4);
  flux_H->SetMarkerColor(kBlue+2);
  flux_H->SetLineColor(kBlue+2);
  flux_H->SetLineWidth(4);
  flux_H->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
  flux_H->GetYaxis()->SetTitle("E^{2} #Phi [GeV cm^{-2} s^{-1} sr^{-1}]");
  flux_H->GetYaxis()->SetRangeUser(0.000001,0.1);
  flux_H->GetXaxis()->SetRangeUser(-1.0,2.0);
  flux_H->Write("Honda_Flux_osc");
  flux_H_unosc->SetMarkerColor(kBlue+2);
  flux_H_unosc->SetLineColor(kBlue+2);
  flux_H_unosc->SetLineWidth(4);
  flux_H_unosc->SetLineStyle(9);
  flux_H_unosc->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
  flux_H_unosc->GetYaxis()->SetTitle("E^{2} #Phi [GeV cm^{-2} s^{-1} sr^{-1}]");
  flux_H_unosc->GetYaxis()->SetRangeUser(0.000001,0.1);
  flux_H_unosc->GetXaxis()->SetRangeUser(-1.0,2.0);
  flux_H_unosc->Write("Honda_Flux_noosc");
  flux_MC->SetMarkerStyle(20);
  flux_MC->SetMarkerColor(kBlue+2);
  flux_MC->SetMarkerSize(1.5);
  flux_MC->SetLineColor(kBlue+2);
  flux_MC->SetLineWidth(4);
  //flux_MC->GetYaxis()->SetRangeUser(0.000001,0.1);
  flux_MC->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
  flux_MC->GetYaxis()->SetTitle("E^{2} #Phi [GeV cm^{-2} s^{-1} sr^{-1}]");
  flux_MC->Write("True_MC_flux");
  flux->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
  flux->GetYaxis()->SetTitle("E^{2} #Phi [GeV cm^{-2} s^{-1} sr^{-1}]");
  flux->SetMarkerStyle(20);
  flux->SetMarkerColor(2);
  flux->SetMarkerSize(1.5);
  flux->SetFillColor(2);
  //flux->SetFillStyle(3005);
  flux->SetLineColor(2);  
  flux->SetLineWidth(4);
  flux->Write("Unfolded_flux");
  flux_SK->SetMarkerStyle(28);
  flux_SK->SetMarkerSize(1.5);
  flux_SK->Write("SK_Flux");
  gPad->SetLogy();
  //flux->Draw("A3");
  flux_H_unosc->Draw("AL");
  flux_H->Draw("CL");
  //flux_MC->Draw("ACL");
  flux_SK->Draw("PE");
  flux->Draw("PE");
  //flux_h->Draw("same");
  //legUD->AddEntry(flux_MC,"Injected spectrum","l");
  legUD->AddEntry(flux_H_unosc,"Honda Flux w/o osc.","l");
  legUD->AddEntry(flux_H,"Honda Flux w/ osc.","l");
  legUD->AddEntry(flux_SK,"SK","p");
  legUD->AddEntry(flux,"Unfolded spectrum","p");
  //legUD->AddEntry(flux_h,"Unfolded spectrum","l");
  legUD->Draw();
  //char* UDname = new char[256];
  //sprintf(UDname,"%s/UD.root",_output_folderc_str());
  //cUD->SaveAs(UDname);
  cUD->Write();
  //cUDdiff->cd();
  //fluxdiff->SetMarkerStyle(21);
  //fluxdiff->GetXaxis()->SetTitle("log_{10}(E_{#nu})");
  //fluxdiff->Draw("AP");
  //char* UDdiffname = new char[256];
  //sprintf(UDdiffname,"%s/UDdiff.root",_output_folder.c_str());
  //cUDdiff->SaveAs(UDdiffname);
  f_out->Close();
}

void Bayes::Smoothing()
{
  std::cout<<"*********************"<<std::endl;
  std::cout<<"*     SMOOTHING     *"<<std::endl;
  std::cout<<"*********************"<<std::endl;
  _nCtemp.ResizeTo(_noEnu);

  std::cout<<"NC NO_SMOOTH "<<"\t";
  for(int j=0; j<_noEnu; j++){
    std::cout <<_nUNFi[j]<<"\t";
  }
  std::cout<<std::endl;

  for(int i=1; i<_noEnu-1; i++){
    _nCtemp[i] = 0.25*((2.*_nUNFi[i]) + _nUNFi[i-1] + _nUNFi[i+1]);
  }
  _nCtemp[0] = 0.5*(_nUNFi[0] + (2.*_nUNFi[1]) - _nUNFi[2]);
  //_nCtemp[_noEnu-1] = 0.5*(_nUNFi[_noEnu-1] + 2.*_nUNFi[_noEnu-2] + _nUNFi[_noEnu-3]);
  _nCtemp[_noEnu-1] = (_nUNFi[_noEnu-1]/2. + _nUNFi[_noEnu-2]/3. + _nUNFi[_noEnu-3]/6.);
  //_nCtemp[_noEnu-1] = 0.5*(_nUNFi[_noEnu-1] + (2.*_nUNFi[_noEnu-2]) - _nUNFi[_noEnu-3]);

  std::cout<<"NC AF_SMOOTH "<<"\t";
  for(int i=0; i<_noEnu; i++){
    _nUNFi[i] = _nCtemp[i];
    std::cout<<_nUNFi[i]<<"\t";
  }
  std::cout<<std::endl;
}

void Bayes::Rescale()
{
  TCanvas *cUD_R = new TCanvas("cUD_R","Unfolded Specrum",0,0,800,700);
  char* inputcont = new char[256];
  sprintf(inputcont, "%s/%s",_input_folder.c_str(),_contE_file.c_str());
  std::cout<<"Input contamination file is: "<<inputcont<<std::endl;
  std::ifstream contE_file(inputcont);
  _ncont.ResizeTo(_noEnu);
  for(int i=0; i<_noEnu; i++){
    contE_file >> _ncont[i];
    _nUNFi[i] -= _nUNFi[i]*_ncont[i];
  }
  TGraph *flux_R = new TGraph(_Ebins,_nUNFi);
  TGraph *flux_MC = new TGraph(_Ebins,plot_trueFlux);
  TLegend * legUD_R = new TLegend(0.65,0.9,0.9,0.75);
  cUD_R->cd();
  flux_MC->SetMarkerStyle(21);
  flux_MC->SetMarkerColor(4);
  flux_MC->SetMarkerSize(1.5);
  flux_R->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
  flux_R->GetYaxis()->SetTitle("E^{2} #Phi [GeV cm^{-2} s^{-1} sr^{-1}]");
  flux_R->SetMarkerStyle(20);
  flux_R->SetMarkerColor(2);
  flux_R->SetMarkerSize(1.5);
  //flux_R->Draw("AP");
  //flux_MC->Draw("P");
  legUD_R->AddEntry(flux_MC,"MC true spectrum","p");
  legUD_R->AddEntry(flux_R,"unfolding","p");
  //legUD_R->Draw();
  char* UD_R_name = new char[256];
  sprintf(UD_R_name,"%s/UD_R.root",_output_folder.c_str());
  //cUD_R->SaveAs(UD_R_name);
}

void Bayes::Loop()
{
  std::cout<<"*********************"<<std::endl;
  std::cout<<"*     ITERATIONS    *"<<std::endl;
  std::cout<<"*********************"<<std::endl;
  std::cout<<"LOOPING ON "<<Niter<<" iterations"<<std::endl<<std::endl;
  sprintf(ext_filename, "%s/plot_%i_%i.root",_output_folder.c_str(),_noEnu,_noNPE);
  TFile *f_out = new TFile(ext_filename, "UPDATE");
  //std::vector<TGraphErrors*> mygraph;
  char* graphname = new char[128];
  char* rationame = new char[128];
  TGraphErrors* mygraph[10] = { NULL };
  TGraph* myratio[10] = { NULL };
  char* UDout = new char[256];
  sprintf(UDout,"%s/%s_%i_%i.txt",_output_folder.c_str(),_unf_spectrum.c_str(),_noEnu,_noNPE);
  std::ofstream udataarray;
  udataarray.open(UDout);
  char* Unamen = new char[256];
  sprintf(Unamen,"%s/Umatrix_%i_iter_%i_%i.txt",_output_folder.c_str(),Niter,_noNPE,_noEnu);
  std::ofstream unfoldmatrixn;
  unfoldmatrixn.open(Unamen, std::ofstream::out);
  char* ratiofile = new char[256];
  sprintf(ratiofile,"%s/Reco_MC_spectrum_ratio_%i_iter_%i_%i.txt",_output_folder.c_str(),Niter,_noEnu,_noNPE);
  std::ofstream reco_MC_ratio;
  reco_MC_ratio.open(ratiofile);
  char* UMnamecanv = new char[256];
  sprintf(UMnamecanv,"Unfolded Spectrum after %i iterations",Niter);
  char* UMdescrhist = new char[256];
  sprintf(UMdescrhist,"Unfolding matrix after %i iterations",Niter);
  TH2F *unf_matrix_n = new TH2F("unf_matrix_n",UMdescrhist,_noEnu,lowedge_E-3.0,upedge_E-3.0,_noNPE,lowedge_NPE,upedge_NPE);
  _pCn.ResizeTo(_noEnu);

  for (int yy=0; yy<Niter; yy++) {

    std::cout<<std::endl<<yy+1<<" ITERATION"<<std::endl;

    //new prior
    for(int i=0; i<_noEnu; i++){
      _pCn[i] = (_nUNFi[i]/neffects);
    }
    neffects = 0.;

    this->Smoothing();

    //new unfolding matrix

    for(int j=0; j<_noNPE; j++){
      denom[j] = 0.;
      for(int i=0; i<_noEnu; i++){
	denom[j] = denom[j] + (_Aji[j][i]*_pCn[i]);
      }
    }
    std::cout << std::endl;
    for(int j=0; j<_noNPE; j++){
      if(denom[j] != 0){
	invdenom[j] = 1./denom[j];
      } else {
	invdenom[j] = 0.;
      }
    }
    for(int j=0; j<_noNPE; j++){
      for(int i=0; i<_noEnu; i++){
	_MUNFij[i][j] = (_Aji[j][i]*_pCn[i]*invdenom[j]);
	std::cout << _MUNFij[i][j] << "\t";
	unfoldmatrixn << _MUNFij[i][j] << "\t";
	unf_matrix_n->SetBinContent(i,j,_MUNFij[i][j]);
      }
      unfoldmatrixn << "\n";
      std::cout << std::endl;
    }
    unfoldmatrixn.close();
    unf_matrix_n->Write();

    std::cout << "NEW FLUX " << "\t";
    //new flux
    for(int i=0; i<_noEnu; i++){
      _nUNFi[i] = 0.;
      for(int j=0; j<_noNPE; j++){
	_nUNFi[i] = _nUNFi[i] + (_MUNFij[i][j]*_nNPEj[j]);
	neffects += _nUNFi[i];
      }
      std::cout << _nUNFi[i] << "\t";
    }
    std::cout << std::endl << "NEW NORM FLUX " << "\t";
    
    for(int i=0; i<_noEnu; i++){
      _nUNFi_eff[i] = _nUNFi[i]/_efficiency[i];
      if(_nUNFi_eff[i]>0.01) {
	err_nUNFi[i] = 0.1*(_nUNFi_eff[i]);
      } else {
	err_nUNFi[i] = 0.2*(_nUNFi_eff[i]);
      }
      std::cout << _nUNFi_eff[i] << "\t";
      plot_Ebins[i] = _Ebins[i]-3.;
      plot_nUNFi_eff[i] = (_nUNFi_eff[i]*(pow(10.,2*plot_Ebins[i])));
      plot_err_nUNFi[i] = (err_nUNFi[i]*(pow(10.,2*plot_Ebins[i])));
      _trueE_recoE_ratio[i] = float(_nUNFi_eff[i])/float(_trueFlux[i]);
      _trueE_recoE_ratio_err[i] = (float(err_nUNFi[i])/float(_nUNFi_eff[i]))*float(_trueE_recoE_ratio[i]);
      reco_MC_ratio << _trueE_recoE_ratio[i] << "\t";
    }

    mygraph[yy] = new TGraphErrors(plot_Ebins,plot_nUNFi_eff,errx0,plot_err_nUNFi);
    mygraph[yy]->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
    mygraph[yy]->GetYaxis()->SetTitle("E^{2} #Phi [GeV cm^{-2} s^{-1} sr^{-1}]");
    mygraph[yy]->SetMarkerStyle(20);
    mygraph[yy]->SetMarkerColor(6-yy);
    mygraph[yy]->SetMarkerSize(2.0-(0.2*yy));
    mygraph[yy]->SetLineWidth(2.5);
    mygraph[yy]->SetLineColor(6-yy);
    mygraph[yy]->SetFillColor(6-yy);
    mygraph[yy]->SetLineColor(6-yy);
    mygraph[yy]->SetLineWidth(4);
    sprintf(graphname,"Unfolded_flux_%i_iter", yy+1);
    mygraph[yy]->Write(graphname);
    myratio[yy] = new TGraphErrors(plot_Ebins,_trueE_recoE_ratio,errx0,_trueE_recoE_ratio_err);
    myratio[yy]->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
    myratio[yy]->GetYaxis()->SetTitle("Data/MC");
    myratio[yy]->SetMarkerStyle(20);
    myratio[yy]->SetMarkerColor(kGreen+3);
    myratio[yy]->SetMarkerSize(1.5);
    myratio[yy]->SetLineColor(kGreen+3);
    myratio[yy]->SetLineWidth(4);
    sprintf(rationame,"Reco_True_ratio_%i_iter", yy+1);
    myratio[yy]->Write(rationame);
    
  } //end of loop on iterations
  
  std::cout<<std::endl<<std::endl;
  
  for(int i=0; i<_noEnu; i++){
    udataarray << _nUNFi_eff[i] << "\t";
  }
  /*
    _nUNFi_eff[i] = _nUNFi[i]/_efficiency[i];
    if(_nUNFi_eff[i]>0.01) {
      err_nUNFi[i] = 0.1*(_nUNFi_eff[i]);
    } else {
      err_nUNFi[i] = 0.2*(_nUNFi_eff[i]);
    }

  //TUTTO IN GeV
  plot_Ebins[i] = _Ebins[i]-3.;
  plot_nUNFi_eff[i] = (_nUNFi_eff[i]*(pow(10.,2*plot_Ebins[i])));
  plot_err_nUNFi[i] = (err_nUNFi[i]*(pow(10.,2*plot_Ebins[i])));
  }*/
  //TCanvas *cUDxn = new TCanvas("cUDxn",UMnamecanv,0,0,800,700);
  /*
  TGraphErrors *flux_iter = new TGraphErrors(plot_Ebins,plot_nUNFi_eff,errx0,plot_err_nUNFi);
  TGraphErrors *flux_SK = new TGraphErrors(E_SK, Flux_SK, errX_SK, err_SK);
  TGraph *flux_H = new TGraph(E_Honda,Flux_Honda);
  TGraph *flux_H_unosc = new TGraph(E_Honda,Flux_Honda_unosc);
  TLegend * legUD = new TLegend(0.15,0.15,0.47,0.3);
  //cUDxn->cd();
  flux_H->SetMarkerColor(kBlue+2);
  flux_H->SetLineColor(kBlue+2);
  flux_H->SetLineWidth(4);
  flux_H->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
  flux_H->GetYaxis()->SetTitle("E^{2} #Phi [GeV cm^{-2} s^{-1} sr^{-1}]");
  flux_H->GetYaxis()->SetRangeUser(0.000001,0.1);
  flux_H->GetXaxis()->SetRangeUser(-1.0,2.0);
  flux_H_unosc->SetMarkerColor(kBlue+2);
  flux_H_unosc->SetLineColor(kBlue+2);
  flux_H_unosc->SetLineWidth(4);
  flux_H_unosc->SetLineStyle(9);
  flux_H_unosc->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
  flux_H_unosc->GetYaxis()->SetTitle("E^{2} #Phi [GeV cm^{-2} s^{-1} sr^{-1}]");
  flux_H_unosc->GetYaxis()->SetRangeUser(0.000001,0.1);
  flux_H_unosc->GetXaxis()->SetRangeUser(-1.0,2.0);
  flux_iter->GetXaxis()->SetTitle("log_{10}(E_{#nu} [GeV])");
  flux_iter->GetYaxis()->SetTitle("E^{2} #Phi [GeV cm^{-2} s^{-1} sr^{-1}]");
  flux_iter->SetMarkerStyle(34);
  flux_iter->SetMarkerColor(8);
  flux_iter->SetMarkerSize(1.5);
  flux_iter->SetLineWidth(2.5);
  flux_iter->SetLineColor(8);
  flux_SK->SetMarkerStyle(28);
  flux_SK->SetMarkerSize(1.5);
  gPad->SetLogy();
  flux_H_unosc->Draw("AL");
  flux_H->Draw("CL");
  flux_SK->Draw("PE");
  flux_iter->Draw("PE");
  legUD->AddEntry(flux_H_unosc,"Honda Flux w/o osc.","l");
  legUD->AddEntry(flux_H,"Honda Flux w/ osc","l");
  legUD->AddEntry(flux_SK,"SK","p");
  legUD->AddEntry(flux_iter,"Unfolded spectrum","p");
  legUD->Draw();
  cUDxn->Write();
  */
  udataarray.close();
  f_out->Close();

  std::cout<<std::endl;
  std::cout << "file " << ext_filename << " created" << std::endl;
}
