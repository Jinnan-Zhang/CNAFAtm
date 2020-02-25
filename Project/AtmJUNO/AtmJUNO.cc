#include <TFile.h>
#include <TTree.h>
#include <TF1.h>
#include "AtmJUNO.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    TFile *ff0=TFile::Open("../data/tme.root","RECREATE");
    TF1 *f1=new TF1("f1","sin(x)",-10,10);
    f1->Write();
    ff0->Close();
    for(int i=0;i<100;i++)
    {printf("?\n");}
    return 0;
}