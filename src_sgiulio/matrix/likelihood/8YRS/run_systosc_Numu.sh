#!/bin/bash
for n in {1..1000}; do
    echo "MODE DATA
FAMILY mu
TRES_CUT_VALUE 95
INCLUDE_OSC YES
BINS_ENERGY 7
BINS_NPE 8
LOWTHR_E 2.7
LOWTHR_NPE 5.7
UPTHR_E 4.05
UPTHR_NPE 7.2
FOLDER output_Numu_osc/systoscillation
LIK_FILE likmatrix_normNumu-$n
MAT_ALL_FILE allmatrix_Numu-$n
MAT_SGN_FILE sgnmatrix_Numu-$n
MAT_BKG_FILE bkgmatrix_Numu-$n
E_ALL_FILE trueenergy_all-$n
E_SGN_FILE trueenergy_Numu-$n
E_FIDCUT_FILE trueenergy_fidcut-$n
E_ALLCUTS_FILE trueenergy_allcuts-$n
E_SGN_ALLCUTS_FILE trueenergy_Numu_allcuts-$n
E_BINS energybins_Numu
NPE_ALL_FILE NPEarray_all-$n
NPE_SGN_FILE NPEarray_Numu-$n
NPE_FIDCUTS_FILE NPEarray_fidcuts-$n
NPE_ALLCUTS_FILE NPEarray_allcuts-$n
NPE_SGN_ALLCUTS_FILE NPEarray_Numu_allcuts-$n
NPE_BINS NPEbins_Numu
E_ALL_FROM_DATA trueenergy_fromDATA_all-$n
E_SGN_FROM_DATA trueenergy_fromDATA_Numu-$n
E_FIDCUTS_FROM_DATA trueenergy_fromDATA_fidcuts-$n
E_ALLCUTS_FROM_DATA trueenergy_fromDATA_allcuts-$n
E_SGN_ALLCUTS_FROM_DATA trueenergy_fromDATA_Numu_allcuts-$n
SOURCE_FLUX_FILE /storage/DATA-02/juno/Users/sgiulio/Atmo/HondaFlux/juno-ally-20-12-solmin_OSC.d
MC_FILE /storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker/trees/MC_500K_1m_TOT.root
DATA_FILE /storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker/trees/DATA_10K_1m_TOT.root
" > output_Numu_osc/systoscillation/run/config_Numu_osc-$n
    echo "running data $n..."
    ./makematrixOSC output_Numu_osc/systoscillation/run/config_Numu_osc-$n
done

cp output_Numu_osc/*.txt output_Numu_osc/systoscillation/.
