#include "Bayes.h"
#include "srtutils.cc"


const double DOMEGA = 1.84;
// const double AREAG = 5.77e3;  // Area Detector
const double AREAG = 6.25e4;     // Ag
//const double AREAG = 1.e4;     // Ag
// const double AREAG = 1600.;   // A di selezione



Bayes::Bayes(){
  _noc = 0;
  _noe = 0;
  _maxiter = 0;
  _Ntrue = 0;
}



void Bayes::ReadMAT()
{
  cout << "Bayes::ReadMAT: " << endl;
  ifstream matfile(_matfile.c_str());
  TString space = " ";
  float dummy;
  if(!matfile.good())
    {
      cout<<"** ERROR! ** Unable to open MAT file" << endl;
    } else {

    matfile >> _noc >> _noe;
    cout << "ReadMAT::noc & noe:" << _noc <<" " <<  _noe << endl; 
    
    _nCi.ResizeTo(_noc);
    _nCgi.ResizeTo(_noc);
    _nCsi.ResizeTo(_noc);
    _nCcbi.ResizeTo(_noc);
    _nEj.ResizeTo(_noe);
    _nEgj.ResizeTo(_noe);
    _Mecji.ResizeTo(_noe,_noc);
    _Pecji.ResizeTo(_noe,_noc);
    _Pceij.ResizeTo(_noc,_noe);
    _pCi.ResizeTo(_noc);  
    _pC0i.ResizeTo(_noc);  
    _efficiencyCi.ResizeTo(_noc);
    _Munfij.ResizeTo(_noc,_noe);

    for ( int i = 0; i < _noc; i++ ) 
      {
	matfile >> dummy;
	//	_nCgi[i] = dummy;
	_nCi[i] = dummy;
      }
    for ( int i=0; i<_noc; i++ ) 
      {
	matfile >> _nCsi[i];
      }
    for ( int i=0; i<_noe; i++)
      {
	matfile >> _nEgj[i];
      }
    for ( int i=0; i<_noe; i++)
      {
	matfile >> _nEj[i];
      }
    for(int j=0; j<_noe; j++){
      for(int i=0; i<_noc; i++){  
	matfile >>_Mecji[j][i]; 
      };
    };
    matfile >> dummy;
    for ( int i=0; i<_noc; i++ ) 
      {
	matfile >> _nCcbi[i];
      }
    // values for proton flux
    matfile >> _npb;
    _pflux.ResizeTo(_npb);
    _pen.ResizeTo(_npb);
    _pen_edg.ResizeTo(_npb+1);
    for (int tt=0; tt<_npb; tt++)
      {
	matfile >> _pen[tt];
      }
    for (int tt=0; tt<=_npb; tt++)
      {
	matfile >> _pen_edg[tt];
      }
    // values for iron flux
    matfile >> _nib;
    _iflux.ResizeTo(_nib);
    _ien.ResizeTo(_nib);
    _ien_edg.ResizeTo(_nib+1);
    for (int tt=0; tt<_nib; tt++)
      {
	matfile >> _ien[tt];
      }
    for (int tt=0; tt<=_nib; tt++)
      {
	matfile >> _ien_edg[tt];
      }
  };  // endif matfile good
};    // endif ReadMAT 



void Bayes::ReadTrueFile()
{
  cout << "Bayes::ReadTrueFile: " << endl;
  ifstream truefile(_truefile.c_str());
  TString space = " ";
  float dummy;
  int idummy;
  if(!truefile.good())
    {
      cout<<"** ERROR! ** Unable to open true file" << endl;
    } else 
    {
      // writing counter vector
      truefile >> idummy;
      _nCgi.ResizeTo(idummy);
      truefile >> _noe; 
      
      for ( int i = 0; i < _noc; i++ ) 
	{
	  truefile >> dummy;
	  _nCgi[i] = dummy;
	}
    };  // endif truefile good

  cout << "ReadTrueFile::noc & noe: " << _noc << " " << _noe << endl;

};    // end ReadTrueFile 


void Bayes::ReadMAT1D()
{
  cout << "Bayes::ReadMAT1D: " << endl;
  ifstream matfile(_matfile.c_str());
  TString space = " ";
  float dummy;
  if(!matfile.good())
    {
      cout<<"** ERROR! ** Unable to open MAT file" << endl;
    } else {

    matfile >> _noc >> _noe;
    cout << "ReadMAT1D::noc & noe:" << _noc <<" " <<  _noe << endl; 
    
    _nCi.ResizeTo(_noc);
    _nCgi.ResizeTo(_noc);
    _nCsi.ResizeTo(_noc);
    _nCcbi.ResizeTo(_noc);
    _nEj.ResizeTo(_noe);
    _nEgj.ResizeTo(_noe);
    _Mecji.ResizeTo(_noe,_noc);
    _Pecji.ResizeTo(_noe,_noc);
    _Pceij.ResizeTo(_noc,_noe);
    _pCi.ResizeTo(_noc);  
    _pC0i.ResizeTo(_noc);  
    _efficiencyCi.ResizeTo(_noc);
    _Munfij.ResizeTo(_noc,_noe);

    for ( int i = 0; i < _noc; i++ ) 
      {
	matfile >> dummy;
	//	_nCgi[i] = dummy;
	_nCi[i] = dummy;
      }
    for ( int i=0; i<_noc; i++ ) 
      {
	matfile >> _nCsi[i];
      }
    for ( int i=0; i<_noe; i++)
      {
	matfile >> _nEgj[i];
      }
    for ( int i=0; i<_noe; i++)
      {
	matfile >> _nEj[i];
      }
    for(int j=0; j<_noe; j++){
      for(int i=0; i<_noc; i++){  
	matfile >>_Mecji[j][i]; 
      };
   };
    matfile >> dummy;
    for ( int i=0; i<_noc; i++ ) 
      {
	matfile >> _nCcbi[i];
      }
    // values for proton flux
    matfile >> _npb;
    _pflux.ResizeTo(_npb);
    _pen.ResizeTo(_npb);
    _pen_edg.ResizeTo(_npb+1);
    for (int tt=0; tt<_npb; tt++)
      {
	matfile >> _pen[tt];
      }
    for (int tt=0; tt<=_npb; tt++)
      {
	matfile >> _pen_edg[tt];
      }
  
  };  // endif matfile good
};    // endif ReadMAT1D 






void Bayes::DumpMAT()
{
  TString space = " ";
  cout << "============================================================================================" << endl;
  cout << "Bayes::DumpMAT: " << endl;
  cout << "DumpMAT:noc & noe: " << _noc << " " << _noe << endl;
  cout << "Causes:generated " << endl;
  for(int t=0; t<_noc; t++){
    cout << _nCi[t] << space;
  }
  cout << endl;
  cout << "Causes:selected " << endl;
  for(int t=0; t<_noc; t++){
    cout << _nCsi[t] << space;
  }
  cout << endl;
  cout << "Effects:generated " << endl;
  for(int t=0; t<_noe; t++){
    cout << _nEgj[t] << space;
  }
  cout << endl;
  cout << "Effects:measured " << endl;
  for(int t=0; t<_noe; t++){
    cout << _nEj[t] << space;
  }
  cout << endl;
  cout <<"MAT[" << _noe << "][" << _noc << "]: " << endl;
  for(int j=0; j<_noe; j++){
    for(int i=0; i<_noc; i++){  
      cout << _Mecji[j][i] << space; 
    };
    cout << endl;
  };
  cout << "run duration  = " << _Tperiod << endl;
  cout << "cause center bin values: " << endl;
    for ( int i=0; i<_noc; i++ ) 
      {
	cout << _nCcbi[i] << space;
      }
    cout << endl;
    cout << "number of proton energy bins = " << _npb << endl;
    cout << "values of proton energies:" << endl; 
    for (int tt=0; tt<_npb; tt++)
      {
	cout << _pen[tt] << space;
      }
    cout << endl;
    cout << "values of proton energy edges:" << endl; 
    for (int tt=0; tt<=_npb; tt++)
      {
	cout << _pen_edg[tt] << space;
      }
    // values for iron flux
    cout << endl;
    cout << "number of iron energy bins = " << _nib << endl;
    cout << "values of iron energies:" << endl; 
    for (int tt=0; tt<_nib; tt++)
      {
	cout << _ien[tt] << space;
      }
    cout << endl;
    cout << "values of iron energy edges:" << endl; 
    for (int tt=0; tt<=_nib; tt++)
      {
	cout << _ien_edg[tt] << space;
      }
    cout << endl;
  cout << "============================================================================================" << endl;
};    // end DumpMAT

void Bayes::DumpMAT1D()
{
  TString space = " ";
  cout << "============================================================================================" << endl;
  cout << "Bayes::DumpMAT1D: " << endl;
  cout << "DumpMAT1D:noc & noe: " << _noc << " " << _noe << endl;
  cout << "Causes:generated " << endl;
  for(int t=0; t<_noc; t++){
    cout << _nCi[t] << space;
  }
  cout << endl;
  cout << "Causes:selected " << endl;
  for(int t=0; t<_noc; t++){
    cout << _nCsi[t] << space;
  }
  cout << endl;
  cout << "Effects:generated " << endl;
  for(int t=0; t<_noe; t++){
    cout << _nEgj[t] << space;
  }
  cout << endl;
  cout << "Effects:measured " << endl;
  for(int t=0; t<_noe; t++){
    cout << _nEj[t] << space;
  }
  cout << endl;
  cout <<"MAT[" << _noe << "][" << _noc << "]: " << endl;
  for(int j=0; j<_noe; j++){
    for(int i=0; i<_noc; i++){  
      cout << _Mecji[j][i] << space; 
    };
    cout << endl;
  };
  cout << "run duration  = " << _Tperiod << endl;
  cout << "cause center bin values: " << endl;
    for ( int i=0; i<_noc; i++ ) 
      {
	cout << _nCcbi[i] << space;
      }
    cout << endl;
    cout << "number of proton energy bins = " << _npb << endl;
    cout << "values of proton energies:" << endl; 
    for (int tt=0; tt<_npb; tt++)
      {
	cout << _pen[tt] << space;
      }
    cout << endl;
    cout << "values of proton energy edges:" << endl; 
    for (int tt=0; tt<=_npb; tt++)
      {
	cout << _pen_edg[tt] << space;
      }
   
    cout << endl;
  cout << "============================================================================================" << endl;
};    // end DumpMAT1D




void Bayes::ReadDAT()
{
  cout << "Bayes::ReadDAT: " << endl;
  ifstream datfile(_datfile.c_str());
  TString space = " ";
  if(!datfile.good())
    {
      cout<<"** ERROR! ** Unable to open DAT file" << endl;
    } else 
    {
      datfile >> _noe ;
      for(int j=0; j<_noe; j++){
	datfile >> _nEj[j];
      };
      datfile >> _Tperiod;
    };  // endif matfile good
  cout << "ReadDAT::noc & noe: " << _noc << " " << _noe << endl;
};    // endif ReadDAT 



void Bayes::ReadDAT1D()
{
  cout << "Bayes::ReadDAT1D: " << endl;
  ifstream datfile(_datfile.c_str());
  TString space = " ";
  if(!datfile.good())
    {
      cout<<"** ERROR! ** Unable to open DAT file" << endl;
    } else 
    {
      datfile >> _noe ;
      for(int j=0; j<_noe; j++){
	datfile >> _nEj[j];
      };
      datfile >> _Tperiod;
      cout<<"_Tperiod = "<<_Tperiod<<endl;
    };  // endif matfile good
  cout << "ReadDAT1D::noc & noe: " << _noc << " " << _noe << endl;

  // //2012 correction
  // for(int j=0; j<_noe; j++){
  // if (_year == 2012) {

  //   _nEj[j] = ( (_nEj[j])*(_corr_mult_2012[j]) );
  //   cout<<endl<<"correcting 2012"<<endl;
  // };
  // };

};    // endif ReadDAT1D 



void Bayes::Initialize(string config){
  //
  // obsolete
  //

  cout<<"************************************"<<endl;
  cout<<"*                                  *"<<endl;
  cout<<"* Init::Reading Configuration File *"<<endl;
  cout<<"*                                  *"<<endl;
  cout<<"************************************"<<endl<<endl;
  
  _noc = int (GetValue("N_CAUSES",config.c_str()));
  _noe = int (GetValue("N_EFFECTS",config.c_str()));
  _maxiter = int (GetValue("MAX_ITER",config.c_str()));  
  //file delle cause
  _cfile = GetFileName("CAUSE_FILE",config.c_str());
  
 
  cout<<endl<<" analizing year -> "<<_year<<endl;
  
  //file degli effetti 
  _efile = GetFileName("EFFECT_FILE",config.c_str());
  
  //file della matrice di probabilita' condizionata 
  _matfile = GetFileName("MAT_FILE",config.c_str());

  _nCi.ResizeTo(_noc);
  _nEj.ResizeTo(_noe);
  _Mecji.ResizeTo(_noe,_noc);
  _Pecji.ResizeTo(_noe,_noc);
  _Pceij.ResizeTo(_noc,_noe);
  _pCi.ResizeTo(_noc);  
  _efficiencyCi.ResizeTo(_noc);
  _Munfij.ResizeTo(_noc,_noe);

  
}
void Bayes::Init(string config){

  cout<<"**********************************************************"<<endl;
  cout<<"Bayes::Initialize:reading configuration file & init var  *"<<endl;
  cout<<"**********************************************************"<<endl<<endl;

  _noc = 0;
  _noe = 0;
  _npb = 0;
  _nib = 0;
  _test = 0;
  _ncomp = 2;
  
  int idummy = int (GetValue("N_CAUSES",config.c_str()));    // NOT USED
  idummy = int (GetValue("N_EFFECTS",config.c_str()));       // NOT USED
  _maxiter = int (GetValue("MAX_ITER",config.c_str()));     
  _test = int (GetValue("TEST_FLAG",config.c_str())); 

  //file delle cause
  TString sdummy = GetFileName("CAUSE_FILE",config.c_str()); // NOT USED
    
  //file degli effetti 
  sdummy = GetFileName("EFFECT_FILE",config.c_str());        // NOT USED

 //READING YEAR
  _year = int (GetValue("YEAR",config.c_str()));
  
  //file della matrice di probabilita' condizionata 
  _matfile = GetFileName("MAT_FILE",config.c_str());
  // datafile
  _datfile = GetFileName("DAT_FILE",config.c_str());
  // truefile
  _truefile = GetFileName("TRU_FILE",config.c_str());
  // proton flux
  _proton_flux_file = GetFileName("PRO_FLUX",config.c_str());
  // iron flux
  _iron_flux_file = GetFileName("IRO_FLUX",config.c_str());

  //2012 rate correction
  _corr_mult_2012_file = GetFileName("CORR_2012",config.c_str());

  cout << "==========================================" << endl;
  cout << "= Init::                                 =" << endl;
  cout << "= MAT file set to: " << _matfile << endl;
  cout << "= DAT file set to: " << _datfile << endl;
  cout << "= True file set to: " << _truefile << endl;
  cout << "= Proton flux file set to: " << _proton_flux_file << endl;
  cout << "= Iron flux file set to: " << _iron_flux_file << endl;
  cout << "= Year set to: " << _year << endl;
  cout << "= Correction file set to: " << _corr_mult_2012_file << endl;
  cout << "==========================================" << endl;


  fmat = new TFile("Mat_unfolding.root","RECREATE", "root_file");

 //  if (_year == 2012) {

//       int nbin = 0;

//     ifstream corrfile(_corr_mult_2012_file.c_str());
//     //  TString space = " ";
//   if(!corrfile.good())
//     {
//       cout<<"** ERROR! ** Unable to open CORR file" << endl;
//     } else {
//       corrfile >> nbin;
//       _corr_mult_2012.ResizeTo(nbin);
//       for(int j=0; j<nbin; j++){
// 	corrfile >> _corr_mult_2012[j];
//       };
//          };
//   cout << "read 2012 correction with" << nbin << " bins " << endl;
// };    
}


void Bayes::Read(){

  //
  // obsolete
  //

  ifstream cfile(_cfile.c_str());
  ifstream efile(_efile.c_str());
  ifstream matfile(_matfile.c_str());



  cout<<endl<<"Vettore delle cause"<<endl;
  for(int i=0; i<_noc; i++){
    cfile>>_nCi[i];
  };
  
  
  cout<<endl<<"Vettore degli effetti"<<endl;
  for(int j=0; j<_noe; j++){
    efile>>_nEj[j];
    cout<<"NE["<<j<<"] = "<<_nEj[j]<<endl;
  };
  
  cout<<endl<<"Matrice causa effetto"<<endl;
  for(int j=0; j<_noe; j++){
    for(int i=0; i<_noc; i++){  
      matfile>>_Mecji[j][i]; 
      cout<<_Mecji[j][i]<<" ";
    }
    cout<<endl;
  }
 
  //  cout<<"Det = "<<_Mecji.Determinant()<<endl;
 
}

void Bayes::Normalize(){

  float PMAX = 0.;
  float PMIN = 0.;

  cout<<endl<<"Matrice normalizzata"<<endl;
   for(int j=0; j<_noe; j++){
    for(int i=0; i<_noc; i++){  
      _Pecji[j][i] = _Mecji[j][i]/_nCi[i];
      cout<<_Pecji[j][i]<<" ";
    }
      cout<<endl;
   }

  for(int j=0; j<_noe; j++){
    for(int i=0; i<_noc; i++){  
      if( _Pecji[j][i]>= PMAX){
	PMAX = _Pecji[j][i];
      }
    } 
  }
 
  cout<<"PMAX = "<<PMAX<<endl;
  cout<<endl<<"Matrice normalizzata - Taglio PMAX"<<endl;

  for(int j=0; j<_noe; j++){
    for(int i=0; i<_noc; i++){  
      if( _Pecji[j][i]< PMAX/1e2){
	//	_Pecji[j][i] = 1e-12;
      }
      cout<<_Pecji[j][i]<<" ";

    }
    cout<<endl;
  }
}




void Bayes::Efficiency(){
  cout<<"Bayes::Efficiency"<<endl;
  for(int i=0;i<_noc; i++){
    for(int j =0; j<_noe; j++){
      _efficiencyCi[i] = _efficiencyCi[i] + _Pecji[j][i];
    }
   cout<<"Efficiency["<<i<<"] = "<<_efficiencyCi[i]<<endl;
  }
  // to be removed
  //  _efficiencyCi[9] = 6e-4;
  cout<<"Efficiency[9] = "<<_efficiencyCi[9]<< " redux" << endl;
  //  

}

void Bayes::Unfold(){

  TVectorD denom;
  TVectorD invdenom;
  denom.ResizeTo(_noe);
  invdenom.ResizeTo(_noe);
  TVectorD tmpCi;
  tmpCi.ResizeTo(_noc);
  float testden;
  TVectorD tempC2;
  tempC2.ResizeTo(3);

  cout<<endl;
   
  for(int j = 0; j<_noe; j++){ 
    testden = 0.;
    for(int i = 0; i<_noc; i++){
      denom[j] = denom[j] + _Pecji[j][i] * _pCi[i];
      testden = testden + _Pecji[j][i] * _pCi[i];
    }
    if(denom[j] != 0){
      invdenom[j] = 1./denom[j];
    }else { 
      invdenom[j] = 0.;
    }
    //  cout<<"Den["<<j<<"] = "<<denom[j]<<"  1./den["<<j<<"] ="<<invdenom[j]<<endl;
    //  cout<<"Den["<<j<<"] = "<<denom[j]<<endl;  
    //   cout<<"Testden "<<j<<" = "<<testden<<endl;
  }
   cout<<endl<<"Matrice di Bayes"<<endl;
  
   for(int j =0; j<_noe; j++){ 
     for(int i = 0; i<_noc; i++){ 
       _Pceij[i][j]  = _Pecji[j][i]*_pCi[i]*invdenom[j]; 
       cout << _Pceij[i][j] <<" ";  
     }
     cout<<endl;
   }
   
   _Ntrue = 0;
  
   cout<<endl<<"Matrice di Unfolding"<<endl; 
   for(int i=0;i<_noc; i++){
     tmpCi[i] = 0.;
     for(int j =0; j<_noe; j++){
     
       //tempC2[i] = tempC2[i]*_Pceij[i][j]*

       if(_efficiencyCi[i] != 0.){
	 _Munfij[i][j] = _Pceij[i][j]/_efficiencyCi[i];      	
       }else{
	 _Munfij[i][j] = 0.;	
       }
       // cout<<_Munfij[i][j]<<" ";
       cout<<_Pceij[i][j]<<" ";       

       tmpCi[i] = tmpCi[i] + _Munfij[i][j]*_nEj[j]; 
     }
     
     cout<<endl;
     
   }
   
   for (int i=0; i<_noc; i++){
     _Ntrue = _Ntrue + tmpCi[i];
     _nCi[i] = tmpCi[i];
   }
   
   for (int i=0; i<_noc; i++){
     _pCi[i] = _nCi[i]/_Ntrue;
   }

};    // end Bayes::Unfold

void Bayes::Unfold2(){

  TVectorD denom;
  TVectorD invdenom;
  denom.ResizeTo(_noe);
  invdenom.ResizeTo(_noe);
  TVectorD tmpCi;
  tmpCi.ResizeTo(_noc);
  TVectorD tempC2;
  tempC2.ResizeTo(3);
  TMatrixD Mb1ij;
  Mb1ij.ResizeTo(_noe,_noc);
  MatPlot.ResizeTo(_noe,_noc);

  cout<<endl;
  // zero's
  for(int t=0; t<_noe; t++)
    {
      denom[t] = 0.;
      for(int tt=0; tt<_noc; tt++)
	{
	  tmpCi[tt] = 0.;
	  Mb1ij[t][tt] = 0.;
	  MatPlot[t][tt] = 0.;
	};
    };
   
  for(int j = 0; j<_noe; j++){ 
    for(int i = 0; i<_noc; i++){
      denom[j] = denom[j] + _Pecji[j][i] * _pCi[i];
    }
    if(denom[j] != 0){
      invdenom[j] = 1./denom[j];
    }else { 
      invdenom[j] = 0.;
    }
  };
  cout<<endl<<"pC(i) * pec(j,i)"<<endl;
  
   for(int j =0; j<_noe; j++){ 
     for(int i = 0; i<_noc; i++){ 
       Mb1ij[j][i]  = _Pecji[j][i]*_pCi[i]; 
       cout << Mb1ij[j][i] <<" ";  
     }
     cout<<endl;
   }
   
   _Ntrue = 0;
  

   cout<<endl<<endl<<"pC(i) * pec(j,i)*invdenom"<<endl;
   
   for(int j =0; j<_noe; j++){ 
     for(int i = 0; i<_noc; i++){ 
       cout<<(Mb1ij[j][i]*invdenom[j])<<" "; 
       //   MatPlot[j][i] = Mb1ij[j][i]; 
     }
     cout<<endl;
   }
    

   cout<<endl<<"Matrice di Unfolding"<<endl; 
   for(int i=0;i<_noc; i++){
     for(int j =0; j<_noe; j++){
       if(_efficiencyCi[i] != 0.){
	 Mb1ij[j][i] = Mb1ij[j][i]* invdenom[j]/_efficiencyCi[i];	
       } else if (_efficiencyCi[i] == 0.){
	 Mb1ij[j][i] = 0.;
       }
       //     cout<<Mb1ij[j][i]* invdenom[j]/_efficiencyCi[i]<<" ";       
         MatPlot[j][i] = Mb1ij[j][i];  
       cout<<Mb1ij[j][i]<<" ";             
 //       tmpCi[i] = tmpCi[i] + _Munfij[i][j]*_nEj[j]; 
  // ORIGINAL///////////////////////////////////////////////////////////////////////
  // tmpCi[i] = tmpCi[i] + _nEj[j] * (Mb1ij[j][i] * invdenom[j]) / _efficiencyCi[i];
  // ///////////////////////////////////////////////////////////////////////////////
       tmpCi[i] = tmpCi[i] + _nEj[j] * Mb1ij[j][i]; 
     }
     
     cout<<endl;
     
   }
   
   cout<<endl<<endl;
   
   
   for (int i=0; i<_noc; i++){
     //   _Ntrue = _Ntrue + tmpCi[i];
     _nCi[i] = tmpCi[i];
     
     cout<<"NC["<<i<<"] = "<<_nCi[i]<<endl;
   }
   
   cout<<endl<<"NTRUE = "<<_Ntrue<<endl<<endl;

   //  this->SmoothingPRD();    

    for (int i=0; i<_noc; i++){
      //   _pCi[i] = _nCi[i]/_Ntrue;
      //    cout<<"PC["<<i<<"] = "<<_pCi[i]<<endl;

    }
   
};   // end Bayes::Unfold2


void Bayes::Flux()
{

  cout << "Bayes::Flux:   calculating flux " << endl;
  double DeltaE;
  if(_Tperiod == 0){ cout << "run duration = 0 !! " << endl; _Tperiod = 1.;};
  if(DOMEGA == 0)    cout << "solid angle = 0 !! " << endl;
  if(AREAG == 0)     cout << "areag = 0 !! " << endl;
  //center bin
  for (int t=0; t<_npb; t++)
    {
      DeltaE =( ((pow(10,_pen_edg[t+1]))) - ((pow(10,_pen_edg[t]))) );
      if(DeltaE == 0) { cout << "DeltaE = 0 for bin = " << t << endl; DeltaE = 1.;}; 
      _pflux[t] = _nCi[t] * (1./_Tperiod) * (1./DOMEGA) * (1./AREAG) * (1./DeltaE);
    }
  for (int tt=0; tt<_nib; tt++)
    {
      DeltaE =( ((pow(10,_ien_edg[tt+1]))) - ((pow(10,_ien_edg[tt]))) );
      if(DeltaE == 0) { cout << "DeltaE = 0 for bin = " << (tt) << endl; DeltaE = 1.;}; 
      _iflux[tt] = _nCi[_npb+tt] * (1./_Tperiod) * (1./DOMEGA) * (1./AREAG) * (1./DeltaE);
    }

}; // end Bayes::Flux()

void Bayes::Flux1D()
{

  cout << "Bayes::Flux1D:   calculating flux " << endl;
  double DeltaE;
  if(_Tperiod == 0){ cout << "run duration = 0 !! " << endl; _Tperiod = 1.;};
  if(DOMEGA == 0)    cout << "solid angle = 0 !! " << endl;
  if(AREAG == 0)     cout << "areag = 0 !! " << endl;
  //center bin
  for (int t=0; t<_npb; t++)
    {
      DeltaE =( ((pow(10,_pen_edg[t+1]))) - ((pow(10,_pen_edg[t]))) );
      if(DeltaE == 0) { cout << "DeltaE = 0 for bin = " << t << endl; DeltaE = 1.;}; 
      _pflux[t] = _nCi[t] * (1./_Tperiod) * (1./DOMEGA) * (1./AREAG) * (1./DeltaE);
    }
 

}; // end Bayes::Flux1D()


void Bayes::WriteFlux()
{
  cout << "Bayes::WriteFlux: " << endl;
  cout << "Proton file = " << _proton_flux_file << endl;
  TString space = " ";
  ofstream setfile(_proton_flux_file.c_str());
  setfile << _npb << endl;
  for(int t=0; t<_npb; t++)
    {
      setfile << pow(10,_pen[t]) << space << _pflux[t] << space
      << pow(10,_pen_edg[t]) << space << pow(10,_pen_edg[t+1]) << endl;
    };
  cout << "Iron file = " << _iron_flux_file << endl;
  ofstream setfile2(_iron_flux_file.c_str());
  setfile2 << _nib << endl;
  for(int t=0; t<_nib; t++)
    {
      setfile2 << pow(10,_ien[t]) << space << _iflux[t] << space 
               << pow(10,_ien_edg[t]) << space << pow(10,_ien_edg[t+1]) << endl;
    };
};  // end Bayes::WriteFlux()

void Bayes::WriteFlux1D()
{
  cout << "Bayes::WriteFlux1D: " << endl;
  cout << "Proton file = " << _proton_flux_file << endl;
  TString space = " ";
  ofstream setfile(_proton_flux_file.c_str());
  setfile << _npb << endl;
  for(int t=0; t<_npb; t++)
    {
      setfile << pow(10,_pen[t]) << space << _pflux[t] << space
      << pow(10,_pen_edg[t]) << space << pow(10,_pen_edg[t+1]) << endl;

      cout<<"Emin = "<<_pen_edg[t]<<"  Emax = "<<_pen_edg[t+1]<<endl;
    };
 
};  // end Bayes::WriteFlux1D()


void Bayes::Loop()
{

  float ntrue_temp=0.;
  cout<<"Bayes::Loop()"<<endl;
  TVectorD index;
  index.ResizeTo(_noc);

  static const int nybins = _noe;
  static const int nxbins = _noc;
  ostringstream oss1;  

  for(int i=0; i<_noc; i++){index[i] = i;}
  for(int k = 0; k<_maxiter; k++)
    {

      //      this->Unfold();
      this->Unfold2();
              if(k != _maxiter-1){
      //      if(k != _maxiter){  //smoothing forzato
		this->SmoothingPRD();	  
	  //this->Smoothing();
	  //this->SmoothingGiulio();
	    }
      // cout<<endl;
      
      for (int i=0; i<_noc; i++){
	//	  cout<<"PC-NO-SMOOTH["<<i<<"] = "<<_pCi[i]<<"      ";
	_Ntrue += _nCi[i];

	//	ntrue_temp += _nCi[i];
	//  cout<<"PC-SMOOTH["<<i<<"] = "<<_pCi[i]<<endl;
      }
      for (int i=0; i<_noc; i++){
      _pCi[i] = _nCi[i]/_Ntrue;
      }
      cout<<endl<<"NTRUE SMOOTH= "<<ntrue_temp<<endl;
      
      TGraph *g = new TGraph(index,_nCi);
      ncplot.push_back(g); 
      
      oss1 << (k+1);
      TString sind = oss1.str();
      TString mm = "hmat"+sind;
      cout <<"Hist. NAME "<< mm<<endl;
      int mat_bin = 0;
      h_mat = new TH2F(mm,mm,nxbins,0,(nxbins-1),nybins,0,(nybins-1));
      for(int i=0;i<_noc; i++){
	for(int j =0; j<_noe; j++){
      	  mat_bin = h_mat->GetBin((j+1),(i+1));
	  h_mat->SetBinContent(mat_bin,MatPlot[j][i]);
	}
      }
      HMAT.push_back(h_mat);
    }     
   
  //  this->Flux();
  // this->WriteFlux();

  for(int k = 0; k<_maxiter; k++){
    HMAT[k] -> Draw("colz");
    }
  fmat->Write();
  this->Flux1D();
  this->WriteFlux1D();
  TGraph *mygp = new TGraph(index,_pC0i);
  ncplot.push_back(mygp);
  if(_test == 1){
    this->ReadTrueFile();
    TGraph *myg = new TGraph(index,_nCgi);
    ncplot.push_back(myg);
    cout<<endl<<"Unfolding Results"<<endl
	<<"---------------------------"<<endl;
    cout<<"NTRUE = "<<_Ntrue<<endl<<endl;
    cout << "   PRIOR                 UNFOLDED                  TRUE " << endl;
    for(int i=0; i<_noc; i++)
      {
	cout << "Nprio["    << i << "]= " << _pC0i[i]
	     << "    Nunf[" << i << "]= " << _nCi[i] 
	     << "    Ng["   << i << "]= " << _nCgi[i] << endl;
      }
  } else if (_test == 0){
    cout<<endl<<"Unfolding Results"<<endl
	<<"---------------------------"<<endl;
    cout<<"NTRUE = "<<_Ntrue<<endl<<endl;
    cout << "   PRIOR                 UNFOLDED " << endl;
    for(int i=0; i<_noc; i++)
      {
	cout << "Nprio["    << i << "]= " << _pC0i[i]
	     << "    Nunf[" << i << "]= " << _nCi[i]  << endl; 
      };
  };
  TCanvas *c2 = new TCanvas("c2","Unfolding",0,0,800,600);
  TLegend *leg = new TLegend(0.15,0.15,0.25,0.25);
  for(int k = 0; k<_maxiter; k++)
    {
      ncplot[k]->SetMarkerStyle(20);
      ncplot[k]->SetMarkerSize(1.2);
      if(k==0){
	ncplot[k]->Draw("AP");
      }else{
	ncplot[k]->SetMarkerColor(k+1);
	ncplot[k]->Draw("P");
      }
      ostringstream oss;
      oss << (k+1);
      TString sind = oss.str();
      leg->AddEntry(ncplot[k],sind,"p");
    }
  int size = ncplot.size();
  int lt = size-2;
  cout << "ncplot size = " << size << " lt = " << lt << endl;
  ncplot[lt]->SetMarkerStyle(28);
  ncplot[lt]->SetMarkerSize(1.8);
  ncplot[lt]->SetMarkerColor(40);
  ncplot[lt]->Draw("P");

  if(_test == 1){
    size = ncplot.size();
    lt = size-1;
    cout << "ncplot size = " << size << " lt = " << lt << endl;
    ncplot[lt]->SetMarkerStyle(29);
    ncplot[lt]->SetMarkerSize(1.5);
    ncplot[lt]->SetMarkerColor(50);
    ncplot[lt]->Draw("P");
  };
  leg->Draw();
  c2->SaveAs("plot/unfolding.root");
}


void Bayes::SetPrior(string priorname){
  cout<<"Bayes::SetPrior()"<<endl;
  TVectorD index;
  TCanvas *c1 = new TCanvas("c1","Prior",0,0,800,600);
  index.ResizeTo(_noc);
  float norm =0.; 
  float norm2 =0.;
  float norm0 =0.;
  float norm20 =0.;
 // cout<<endl<<"Prior"<<endl;
  if(priorname == "uniform"){
    for(int i=0;i<_noc;i++){
      _pCi[i] = 1./float(_noc);
      _pC0i[i] = 1./float(_noc);
    }
  } else if(priorname == "uniformMod"){
    for(int i=0;i<_noc;i++){
      _pCi[i] = 1./float(_noc);
      _pC0i[i] = 1./float(_noc);
      if(i == 0 || i == 6 || i == 7 || i == 12){
	_pCi[i] = 0.;
	_pC0i[i] = 0.;
      }
      norm += _pCi[i];
      norm0 += _pC0i[i];
    }
    for(int i=0;i<_noc;i++){
      _pCi[i] = _pCi[i]/norm;
      _pC0i[i] = _pC0i[i]/norm0;
    }

  }else if (priorname == "ProtonUnif"){
    for(int i=0;i<_noc;i++){
      if(i<10){
      _pCi[i] = 1./float(_noc-8);
      _pC0i[i] = 1./float(_noc-8);
      } else {
	_pCi[i] = 1.e-3;
	_pC0i[i] = 1.e-3;
      }
      norm += _pCi[i];
      norm0 += _pC0i[i];
    }

 for(int i=0;i<_noc;i++){
      _pCi[i] = _pCi[i]/norm;
      _pC0i[i] = _pC0i[i]/norm0;
    }

  }else if (priorname == "IronUnif"){
    
    for(int i=0;i<_noc;i++){
      if(i>=10){
	_pCi[i] = 1./float(_noc-10);
	_pC0i[i] = 1./float(_noc-10);
      } else {
	_pCi[i] = 0.;
	_pC0i[i] = 0.;
      }
    }

  } else if(priorname == "PowerLaw"){
    float alpha = 1.;
    float xm = 1;

    for(int i=0;i<_noc;i++){
      _pCi[i] = pow(xm,alpha)/pow(i+1,alpha+1);
      norm += _pCi[i];
      _pC0i[i] = pow(xm,alpha)/pow(i+1,alpha+1);
      norm0 += _pC0i[i];
    }
    for(int i=0;i<_noc;i++){
      _pCi[i] = _pCi[i]/norm;
      _pC0i[i] = _pC0i[i]/norm0;
    }

  } else if(priorname == "myPowLaw"){
    // Prior = pow(cause bin index "i",alpha)
    //
    float alpha = 2.61;
    for(int i=0;i<_noc;i++){
      _pCi[i] = pow(i+1,-alpha);
      norm += _pCi[i];
      _pC0i[i] = pow(i+1,-alpha);
      norm0 += _pC0i[i];
    }
    for(int i=0;i<_noc;i++){
      _pCi[i] = _pCi[i]/norm;
      _pC0i[i] = _pC0i[i]/norm0;
    }

  //
  } else if(priorname == "myPowLaw2"){
    //Prior = pow(energy bin value,alpha)

    float alpha = 2.61;
    float base = 3;
    float base_prior = 1.;
    for(int i=0;i<_noc;i++){
      base_prior = pow(base,_nCcbi[i]);
      _pCi[i] = pow(base_prior,-alpha);
      norm += _pCi[i];
      _pC0i[i] = pow(base_prior,-alpha);
      norm0 += _pC0i[i];
    }
    for(int i=0;i<_noc;i++){
      _pCi[i] = _pCi[i]/norm;
      _pC0i[i] = _pC0i[i]/norm0;
    }

  //
  } else if(priorname == "myPowLaw3"){
    //Prior = pow(energy bin value,alpha_primary)
    //        alpha_proton = 2.3
    //        alpha_iron   = 2.0

    float alpha_proton = 2.0;
    float alpha_iron = 2.3;
    float base = 10.;
    float base_prior = 1.;
    //proton
    for(int i=0;i<_npb;i++){
      base_prior = pow(base,_nCcbi[i]);
      _pCi[i] = pow(base_prior,-alpha_proton);
      norm += _pCi[i];
      _pC0i[i] = pow(base_prior,-alpha_proton);
      norm0 += _pC0i[i];
    }
    //iron
    for(int i=0;i<_nib;i++){
      base_prior = pow(base,_nCcbi[_npb+i]);
      _pCi[_npb+i] = pow(base_prior,-alpha_iron);
      norm += _pCi[_npb+i];
      _pC0i[_npb+i] = pow(base_prior,-alpha_iron);
      norm0 += _pC0i[_npb+i];
    }
    for(int i=0;i<_noc;i++){
      _pCi[i] = _pCi[i]/norm;
      _pC0i[i] = _pC0i[i]/norm0;
    }

  } else if(priorname == "myPowLaw4"){
    //Prior = pow(energy bin value,alpha_primary)
    //        alpha_proton = 2.0
    //        alpha_iron   = 2.3

    float alpha_proton = 1.7; //26-08-2013
    float alpha_iron = 1.7; //26-08-2013
    float base = 10.;
    float base_prior = 1.;
    float LoverH = 1.;
    //proton
    for(int i=0;i<_npb;i++){
      base_prior = pow(base,_nCcbi[i]);
      _pCi[i] = pow(base_prior,-alpha_proton);
      norm += _pCi[i];
      _pC0i[i] = pow(base_prior,-alpha_proton);
      norm0 += _pC0i[i];
    }
    //iron
    for(int i=0;i<_nib;i++){
      base_prior = pow(base,_nCcbi[_npb+i]);
      _pCi[_npb+i] = pow(base_prior,-alpha_iron)/LoverH;
      norm += _pCi[_npb+i];
      _pC0i[_npb+i] = pow(base_prior,-alpha_iron)/LoverH;
      norm0 += _pC0i[_npb+i];
    }
    for(int i=0;i<_noc;i++){
      _pCi[i] = _pCi[i]/norm;
      _pC0i[i] = _pC0i[i]/norm0;
    }
  } // endif (priorname == .....)

  //
  for(int i=0;i<_noc;i++){
    index[i] = i;
    norm2 += _pCi[i];
    norm20 += _pC0i[i];
    cout<<"Prior["<<i<<"] = "<<_pCi[i]<<endl;
  }
  cout<<"NORM = "<<norm<<endl;
  cout<<"NORM2 = "<<norm2<<endl;
  cout<<"NORM0 = "<<norm0<<endl;
  cout<<"NORM20 = "<<norm20<<endl;
  TGraph * prior = new TGraph(index,_pCi);
  prior->SetMarkerStyle(20);  
  prior->Draw("AP");
 
  c1->SaveAs("plot/prior.root");
}



void Bayes::Smoothing(){

  TVectorD pCTemp;
 
  pCTemp.ResizeTo(_noc);
  cout<<"*********************"<<endl;
  cout<<"*     SMOOTHING     *"<<endl;
  cout<<"*********************"<<endl;

 for(int i=0;i<_noc;i++){
    cout << "PC Pre-Smoothing "<<i<<"  "<<_pCi[i]<<endl;

    if(i==0){
      pCTemp[i] = 0.5*(_pCi[i]+2*_pCi[i+1]-_pCi[i+2]);	
      
    } else if (i==_noc-1){
      
      pCTemp[i] = 0.5*(_pCi[i]+2*_pCi[i-1]-_pCi[i-2]);	      
   
    } else {
      
      pCTemp[i] = _pCi[i]/2 + _pCi[i-1]/4+ _pCi[i+1]/4;	
   
    }
  
  }

  // sostituzione punti

  cout<<endl;
  for(int i=0;i<_noc;i++){
    if(pCTemp[i] < 0){
      _pCi[i] = _pCi[i];
    }else{
      _pCi[i] = pCTemp[i];
    }
    cout << "PC Smooth "<<i<<" "<<_pCi[i]<<endl;

  }
  
  }

void Bayes::OldSmoothing(){

  TVectorD pCTemp;
  pCTemp.ResizeTo(_noc);

  cout<<"SMOOTHING"<<endl;

  pCTemp[0] = (_pCi[0] +2*_pCi[1] - _pCi[2])/2; 

  for(int k = 1; k<_noc-1; k++){

    pCTemp[k] = (2*_pCi[k] + _pCi[k-1] + _pCi[k+1])/4;

  };

 pCTemp[_noc-1] =  (_pCi[_noc-1] + _pCi[_noc-2] + _pCi[_noc-3])/2;


  for(int j=0; j<_noc; j++){

    _pCi[j] = pCTemp[j];
    cout << "PC Smooth "<<j<<" "<<_pCi[j]<<endl;

  };
}

void Bayes::SmoothingPRD(){
  
  TVectorD nCTemp;
  nCTemp.ResizeTo(_noc);
  
  cout<<"PRIMA DI SMOOTHING"<<endl;

 for(int j=0; j<_noc; j++){
    
    cout << "NC NO_SMOOTH "<<j<<" "<<_nCi[j]<<endl;

  };

  nCTemp[0] = (_nCi[0] +2*_nCi[1] - _nCi[2])/2; 
 // nCTemp[0] = _nCi[0];
 // nCTemp[1] = _nCi[1];

 nCTemp[1] = (_nCi[1] +2*_nCi[2] - _nCi[3])/2; 
 
 for(int k = 1; k<_noc-1; k++){
   
   nCTemp[k] = (2*_nCi[k] + _nCi[k-1] + _nCi[k+1])/4;
   
 };
  
 //nCTemp[_noc-2] =  (_nCi[_noc-2] + _nCi[_noc-3] + _nCi[_noc-4])/2;
 // nCTemp[_noc-1] = _nCi[_noc-1];
 nCTemp[_noc-1] =  (_nCi[_noc-1] + _nCi[_noc-2] + _nCi[_noc-3])/2;
  for(int j=0; j<_noc; j++){
    
    _nCi[j] = nCTemp[j];
    cout << "NC SMOOTH "<<j<<" "<<_nCi[j]<<endl; 
  };
};

void Bayes::SmoothingGiulio(){
  
  TVectorD nCTemp;
  nCTemp.ResizeTo(_noc);
  //int q;
  cout<<endl;

  cout<<"*********************"<<endl;
  cout<<"* SMOOTHING GIULIO  *"<<endl;
  cout<<"*********************"<<endl;

  //  cout<<endl<<"loop n. "<<k<<endl;

   for(int j=0; j<_noc; j++){
    
    cout << "NC NO_SMOOTH "<<j<<" "<<_nCi[j]<<endl;

   }
  

   /* //SMOOTHING MEDIA

      cout<<endl<<"smoothing con media"<<endl<<endl;

      for(int k = 1; k<_noc-1; k++){
    q = 0;
  for(int p = 0; p<15; p++)  {

    q = q + _nCi[p];
  }
  nCTemp[k] = (q - _nCi[k])/15;
 }
  
 nCTemp[0] = (_nCi[0]/2 + _nCi[1]/3 + _nCi[2]/6);
 nCTemp[_noc-1] = (_nCi[_noc-1]/2 + _nCi[_noc-2]/3 + _nCi[_noc-3]/6);

  for(int j=0; j<_noc; j++){

    cout << "NC SMOOTH "<<j<<" "<<_nCi[j]<<endl;
    _nCi[j] = nCTemp[j];
    
    } */

              //SMOOTHING CENTRATO PESATO

		cout<<endl<<"smoothing centrato (pesato)"<<endl<<endl;

   int _centro = 6;   //centro dello smoothing (unico parametro da modificare)

nCTemp[_centro] = _nCi[_centro];
 
for(int q = 1; q<_centro; q++){
   
   nCTemp[_centro-q] = (3*_nCi[_centro-q] + _nCi[_centro-q-1] + 2*_nCi[_centro-q+1])/6;
   _nCi[_centro-q] = nCTemp[_centro-q];
   }

 for(int i = 1; i<(15-_centro); i++) {

   nCTemp[_centro+i] = (3*_nCi[_centro+i] + 2*_nCi[_centro+i-1] + _nCi[_centro+i+1])/6;
   _nCi[_centro+i] = nCTemp[_centro+i];
 }
  
 nCTemp[0] = (_nCi[0]/2 + _nCi[1]/3 + _nCi[2]/6);
 nCTemp[_noc-1] = (_nCi[_noc-1]/2 + _nCi[_noc-2]/3 + _nCi[_noc-3]/6);

 _nCi[0] = nCTemp[0];
 _nCi[_noc-1] = nCTemp[_noc-1]; 

 
   /*            //SMOOTHING CENTRATO NON PESATO

   cout<<endl<<"smoothing centrato (non pesato)"<<endl<<endl;;

   int _centro = 5;   //centro dello smoothing (unico parametro da modificare)

nCTemp[_centro] = _nCi[_centro];
 
for(int q = 1; q<_centro; q++){
   
   nCTemp[_centro-q] = (2*_nCi[_centro-q] + _nCi[_centro-q-1] + _nCi[_centro-q+1])/4;
   _nCi[_centro-q] = nCTemp[_centro-q];
   }

 for(int i = 1; i<(15-_centro); i++) {

   nCTemp[_centro+i] = (2*_nCi[_centro+i] + _nCi[_centro+i-1] + _nCi[_centro+i+1])/4;
   _nCi[_centro+i] = nCTemp[_centro+i];
 }
  
 nCTemp[0] = (_nCi[0]/2 + _nCi[1]/3 + _nCi[2]/6);
 nCTemp[_noc-1] = (_nCi[_noc-1]/2 + _nCi[_noc-2]/3 + _nCi[_noc-3]/6);

 _nCi[0] = nCTemp[0];
 _nCi[_noc-1] = nCTemp[_noc-1]; 
*/

/*
 double q = .0;

 for(int p = 1; p<15; p++)  {

    q = q + _nCi[p];
    cout<<"q"<<p<<" = "<<q<<endl;
     cout<<"_nCi = "<<_nCi[p]<<endl;
  }
  nCTemp[_centro] = (q - _nCi[_centro])/13;

  _nCi[_centro] = nCTemp[_centro]; */

   /*

 // SMOOTHING CENTRATO GAUSSIANO

 cout<<endl<<"smoothing centrato gaussiano"<<endl<<endl;

   nCTemp[5] = _nCi[5];
 
   nCTemp[4] = (_nCi[1]+3*_nCi[2]+6*_nCi[3]+7*_nCi[4]+6*_nCi[5]+3*_nCi[6]+_nCi[7])/27;
   //   _nCi[4] = nCTemp[4];

   nCTemp[3] = (_nCi[0]+3*_nCi[1]+6*_nCi[2]+7*_nCi[3]+6*_nCi[4]+3*_nCi[5]+_nCi[6])/27;
   //   _nCi[3] = nCTemp[3];

   nCTemp[2] = (_nCi[0]+2*_nCi[1]+3*_nCi[2]+2*_nCi[3]+_nCi[4])/9;
   //   _nCi[2] = nCTemp[2];

   nCTemp[1] = (_nCi[0]+2*_nCi[1]+_nCi[3])/4;
   //  _nCi[1] = nCTemp[1];
 
   int i = 1;

   while(_noc-5-i>3) {

   nCTemp[5+i] = (_nCi[5+i-3]+3*_nCi[5+i-2]+6*_nCi[5+i-1]+7*_nCi[5+i]+6*_nCi[5+i+1]+3*_nCi[5+i+2]+_nCi[5+i+3])/27;
   //   _nCi[5+i] = nCTemp[5+i];
   i = i+1;
 }

 nCTemp[_noc-3] = (_nCi[_noc-5]+2*_nCi[_noc-4]+3*_nCi[_noc-3]+2*_nCi[_noc-2]+_nCi[_noc-1])/9;
 nCTemp[_noc-2] = (_nCi[_noc-3]+2*_nCi[_noc-2]+_nCi[_noc-1])/4;
  
 nCTemp[0] = (_nCi[0]/2 + _nCi[1]/3 + _nCi[2]/6);
 nCTemp[_noc-1] = (_nCi[_noc-1]/2 + _nCi[_noc-2]/3 + _nCi[_noc-3]/6);

 _nCi[0] = nCTemp[0];
 _nCi[_noc-1] = nCTemp[_noc-1];

*/
   /* // SMOOTHING CON CENTRO VARIABILE
      // la function va dichiarata come SmoothingGiulio(int k)

      cout<<endl<<"smoothing con centro variabile"<<endl<<endl;

   int p = 2*k; 

nCTemp[5+p] = _nCi[5+p]; 

for(int q = 1; q<5+p; q++){
   
   nCTemp[5+p-q] = (3*_nCi[5+p-q] + _nCi[5+p-q-1] + 2*_nCi[5+p-q+1])/6;
   _nCi[5+p-q] = nCTemp[5+p-q];
   }

 for(int i = 1; i<9-p; i++) {

   nCTemp[5+p+i] = (3*_nCi[5+p+i] + 2*_nCi[5+p+i-1] + _nCi[5+p+i+1])/6;
   _nCi[5+p+i] = nCTemp[5+p+i];
 }
  
 nCTemp[0] = (_nCi[0]/2 + _nCi[1]/3 + _nCi[2]/6);
 nCTemp[_noc-1] = (_nCi[_noc-1]/2 + _nCi[_noc-2]/3 + _nCi[_noc-3]/6); */


 // float index[_noc];
 for(int j=0; j<_noc; j++){ 
cout << "NC SMOOTH "<<j<<" "<<_nCi[j]<<endl;
//_nCi[j] = nCTemp[j];
// index[j] = j;
 }

 // TGraph *Smooth = new TGraph(_noc, index, _nCi);
 //Smooth -> Draw("AP");
 // Smooth -> SaveAs("smooth.pdf");

}
