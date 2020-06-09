#include "Data.h"
#include <iostream>

int main(int argc, char* argv[]){

  std::cout<<"CIAO"<<std::endl;

  if(argv[1] != NULL) {
    std::cout<<"output file: "<<argv[1]<<std::endl;
  } else {
    std::cout<<"INSERT OUTPUT FILE"<<std::endl;
    return 0;
  }


  Data *a = new Data();

  a->Loop(argv[1]);

  return 1;
}
