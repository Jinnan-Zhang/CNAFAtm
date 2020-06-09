#ifndef srtutils_cc
#define srtutils_cc
#include <iostream>
#include <fstream>
// old #include <iostream.h>  
// old #include <fstream.h>   
#include <TString.h>
#include <math.h>



inline void Bprint(Int_t id, const char *title)
{
  // Print test program number and its title
   const Int_t kMAX = 65;
   char header[80];
   sprintf(header,"Test %2d : %s",id,title);
   Int_t nch = strlen(header);
   for (Int_t i=nch;i<kMAX;i++) header[i] = '.';
   header[kMAX] = 0;
   header[kMAX-1] = ' ';
   printf("%s",header);
}


inline bool isoneof(char any[], char all[]){
  bool match(false);
  int i=0,j=0;
  int count=0;
  while(1){
    if(all[i]==0) break;
    if(all[i]==any[j]) count++;
    else count=0;
    if(count-1==j && any[j+1]==0 && (all[i+1]=='+'|| all[i+1] ==0)) match=true;
    i++;
    j++;
    if(all[i-1]=='+') j=0;
    if(any[j]==0) j=0;
  }
  return match;
}

inline float approx(float eff, int nOfDecimals){
  float approximated;
  approximated=(float)((int)(pow(10,nOfDecimals)*eff)/pow(10,nOfDecimals));
  return approximated;
}

inline std::string GetValue(TString variable,const char* filename){
//   if(filename!=0)
//     std::cout << "ThreebodyApp::GetValue: reading value from file "<< filename << std::endl;
  std::ifstream setfile(filename);
  std::string val;
  if(!setfile.good()){
    std::cout << "ERROR in ThreebodyApp::GetValue "
	 << "unable to open the file " << filename << std::endl;
  }
  else {
    TString var;
    bool anyfound(false);
    while(1){
      setfile>>var>>val;
      if (!setfile.good()) break;
      if(var==variable){
	anyfound=true;
	std::cout << " Search for " << variable << " found " << var 
             << " = " << val << std::endl;
	break;
      }
    }
    if(!anyfound) std::cout<<"warning!!: I didn't find "<<variable<<"...setting it to 0"<<std::endl;
  }
  setfile.close();
  return val;
} 

inline std::string GetFileName(TString variable,const char* filename){
  std::ifstream setfile(filename);
  std::string val("");
  if(!setfile.good()){
    std::cout << "ERROR in ThreebodyApp::GetValue "
	 << "unable to open the file " << filename << std::endl;
  }
  else {
    TString var;
    bool anyfound(false);
    while(1){
      setfile>>var>>val;
      if (!setfile.good()) break;
      //      std::cout << " reading file name: good file! " << std::endl;
      //      std::cout << " var = " << var << " val = " << val << " variable = " << variable << std::endl;
      if(var==variable){
	      std::cout << " match found: variable = " << var << " matched to " 
	           << variable << ", value = " << val << std::endl;
	anyfound=true;
	break;
      }
    }
    if(!anyfound) std::cout<<"warning!!: I didn't find "<<variable<<"...setting it to 0"<<std::endl;
  }
  setfile.close();
  return val;
} 

#endif
