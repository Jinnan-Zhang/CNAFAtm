#include "Bayes.h"
#include <iostream>
#include "srtutils.cc"

int main(int argc, char* argv[]){
  
  std::string config = argv[1];	

  Bayes * b = new Bayes();
  b->Init(config);            // read config file:new
  b->ReadMAT();               // read 1D causes effects and mat:new
  b->ReadDATA();
  //b->SetPrior("PowerLaw");  // prior  (see Bayes.cc)
  b->SetPrior("external");    // prior  (see Bayes.cc)
  //b->SetPrior("uniform");   // prior  (see Bayes.cc)
  b->Unfold();
  b->RawFlux();

  //b->Rescale();
  //b->Smoothing();
  b->Loop();                  //loop on N iterations

return 1;
}
