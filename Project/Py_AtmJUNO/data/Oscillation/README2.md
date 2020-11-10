This is a document which introduces the files
genie3.0.2_atm_weight.root in the GENIE folder;
nuwro1.9.2_atm_weight.root in the NuWro folder;
they initially come from /junofs/users/junoprotondecay/guowl/AtmWeight/3-Weight/
Author : Wan-Lei Guo
email :  guowl@ihep.ac.cn

//////////////////////////////////////////////////////////////////////////////////////////////////////

1. genie3.0.2_atm_weight.root and nuwro1.9.2_atm_weight.root are based on the genie3.0.2_atm.root and nuwro1.9.2_atm.root, respectively.
   genie3.0.2_atm.root and nuwro1.9.2_atm.root come from /junofs/users/junoprotondecay/chengj/atm-gen/results

   1) genie3.0.2_atm.root is directly produced by GENIE3.0.2 and the command "gevgen_atmo",
      which includes 405934 events (among which there are 6000 \nu_\tau and \bar{\nu}_\tau CC events)

   2) nuwro1.9.2_atm.root is directly produced by NuWro1.9.2,
      which includes 406000 events (among which there are 6000 \nu_\tau and \bar{\nu}_\tau CC events)
   

2. genie3.0.2_atm_weight.root(nuwro1.9.2_atm_weight.root) is based on genie3.0.2_atm.root(nuwro1.9.2_atm.root) and has two additional parameters Cv and weight: 

   1). Cv is the neutrino direction and defined by  cos \theta_z 

   2). weight is the weight value for JUNO 20 kton and 10 years, which is calculated in terms of the produced numbers per bin
       and the corresponding theoretical numbers per bin (considering neutrino fluxes, cross sections, and neutrino Oscillation)

   3). neutrnio fluxes can be found at http://www.icrr.u-tokyo.ac.jp/~mhonda/nflx2014/index.html 
       or /junofs/users/junoprotondecay/guowl/AtmWeight/2-Oscillation/Flux 

   4). Cross section comes from /junofs/users/junoprotondecay/guowl/AtmWeight/2-Oscillation/Xsec/ (see README file there)

   5). neutrino oscillation parameters are taken from the bestfit of PDG2018 and normal hierarchy:
        Theta12 = 0.297;      // sin^2(x)
        Theta23 = 0.425;
        Theta13 = 0.0215; 
        dm2     = 7.37e-5;    // Delta m^2_{21}
        DMatm   = 2.4863e-3;  // Delta m_32^2    
        dcp     = 4.3354;     // in units of radians

   6). some variable definations:
        pPdg                      : initial neutrino PDG code
        tPdg                      : initial target PDG code (note that H1 is "2212", C12 is "1000060120", O16 is "1000080160", ...)
        interType                 : the index of interaction type (1: QEL, 2: RES, 3: COH/DFR, 4: DIS, 5: MEC, -1 : others)
        ctag                      : the index of NC or CC (NC : ctag==1, CC : ctag==2)
        pEn                       : the energy of initial neutrino
        pPx, pPy, pPz             : the momentum of initial neutrino
        m_isoPdg                  : residual nucleus PDG code
        m_isoPx, m_isoPy, m_isoPz : the momentum of residual nucleus
        m_isoMass                 : the mass of residual nucleus
        Npars                     : the number of final particles
        pdg                       : final particle PDG code
        px, py, pz                : the momentum of final particle
        energy                    : the energy of final particle
        mass                      : the mass of final particle         
        Cv                        : neutrino direction cos \theta_z
        weight                    : weight value for JUNO 200 kton year

   8). There are some figures for check in genie3.0.2_atm_weight.root and nuwro1.9.2_atm_weight.root
         KEY: TH2F	WeCCP12;1	Ve    weighted value per bin   400x400 bins
         KEY: TH2F	WeCCM12;1	Vebar weighted value per bin
         KEY: TH2F	WuCCP14;1	Vu    weighted value per bin
         KEY: TH2F	WuCCM14;1	Vubar weighted value per bin
         KEY: TH2F	WvNCP00;1	V     weighted value per bin
         KEY: TH2F	WvNCM00;1	Vbar  weighted value per bin
         KEY: TH1F	WtCCP16;1	Vt    weighted value per bin   400 bins 
         KEY: TH1F	WtCCM16;1	Vtbar weighted value per bin

         KEY: TH1F	Ev_P12;1	Ve  CC energy distribution     40 bins 
         KEY: TH1F	Cv_P12;1	Ve  CC cosz distribution
         KEY: TH1F	Ev_M12;1	Veb CC energy distribution
         KEY: TH1F	Cv_M12;1	Veb CC cosz distribution
         KEY: TH1F	Ev_P14;1	Vu  CC energy distribution
         KEY: TH1F	Cv_P14;1	Vu  CC cosz distribution
         KEY: TH1F	Ev_M14;1	Vub CC energy distribution
         KEY: TH1F	Cv_M14;1	Vub CC cosz distribution
         KEY: TH1F	Ev_P16;1	Vt  CC energy distribution
         KEY: TH1F	Ev_M16;1	Vtb CC energy distribution
         KEY: TH1F	Ev_P00;1	V   NC energy distribution
         KEY: TH1F	Cv_P00;1	V   NC cosz distribution
         KEY: TH1F	Ev_M00;1	Vb  NC energy distribution
         KEY: TH1F	Cv_M00;1	Vb  NC cosz distribution 
/////////////////////////////////////////////////////////////////////////////////////////
