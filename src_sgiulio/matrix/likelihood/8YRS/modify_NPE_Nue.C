void modify_NPE_Nue(){
  std::ifstream npearray("/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/matrix/likelihood/output_Nue_osc_NEW/NPEarray_allcuts_7.txt");
  char* out_file = new char[256];
  //std::ofstream NPE_out;
  float norm, var;
  vector <float> NPE_arr;
  TRandom3 gausmear;
  npearray >> norm;
  while(npearray >> var) {
    NPE_arr.push_back(var);
  }
  for (int k=1; k<=1000; k++) {
    std::ofstream NPE_out;
    sprintf(out_file,"/storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/matrix/likelihood/output_Nue_osc/mod/NPEarray_allcuts_7-%i.txt",k);
    NPE_out.open(out_file);
    std::cout << "creating file " << out_file << "..." <<std::endl;
    NPE_out << norm << "\n";
    for(int jj=0; jj<(NPE_arr.size()); jj++) {
      NPE_out << gausmear.Poisson((NPE_arr)[jj]) << "\t";
    }
    NPE_out.close(); 
  }
}
