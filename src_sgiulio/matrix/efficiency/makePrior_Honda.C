void makePrior_Honda(){

  static const int binsE_nuE = 12;

  TTree *mytree;
  TFile *_file1 = TFile::Open("/storage/DATA-02/juno/Prod/GENIE-2_12_10/atmo_nuall_LS_0-20GeV_1M.1.gst.root");
  _file1->GetObject("gst",mytree);

  TH1F *Honda_spectrum_nuE = new TH1F("Honda_spectrum_nuE","",binsE_nuE,2.0,4.2);
  mytree->Project("Honda_spectrum_nuE","log10(Ev*1000.)","abs(neu)==12");
  TH1F *Honda_spectrum_nueCC = new TH1F("Honda_spectrum_nueCC","",binsE_nuE,2.0,4.2);
  mytree->Project("Honda_spectrum_nueCC","log10(Ev*1000.)","cc==1 && abs(fspl)==11");
  Honda_spectrum_nueCC->Draw();
  char* filename11= new char[128];
  sprintf(filename11,"output/HondaPrior_nueCC_%i.txt",binsE_nuE);
  std::ofstream hondaprior_nueCC;
  hondaprior_nueCC.open(filename11);
  Int_t norm_nuE = Honda_spectrum_nuE->GetEntries();
  char* filename1= new char[128];
  sprintf(filename1,"output/HondaPrior_nuE_%i.txt",binsE_nuE);
  std::ofstream hondaprior_nuE;
  hondaprior_nuE.open(filename1);

  for(int i=1; i<=binsE_nuE; i++) {
    hondaprior_nuE << (float(Honda_spectrum_nuE->GetBinContent(i)))/float(norm_nuE) << "\t";
    hondaprior_nueCC << (float(Honda_spectrum_nueCC->GetBinContent(i))) << "\t";
  }
  hondaprior_nuE.close();
  hondaprior_nueCC.close();
  std::cout << filename1 << " created" << std::endl;
  std::cout << filename11 << " created" << std::endl;
}
