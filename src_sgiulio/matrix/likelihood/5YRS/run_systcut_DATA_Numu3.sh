#!/bin/bash
for n in {8..10}; do
    let "N_init = 90"
    let "mycut = $(expr n+N_init)"
    echo "MODE MC
FAMILY mu
TRES_CUT_VALUE $mycut
INCLUDE_OSC YES
BINS_ENERGY 7
BINS_NPE 8
LOWTHR_E 2.7
LOWTHR_NPE 5.7
UPTHR_E 4.05
UPTHR_NPE 7.2
FOLDER output_Numu_osc/systcut
LIK_FILE likmatrix_normNumu-$mycut
MAT_ALL_FILE allmatrix_Numu-$mycut
MAT_SGN_FILE sgnmatrix_Numu-$mycut
MAT_BKG_FILE bkgmatrix_Numu-$mycut
E_ALL_FILE trueenergy_all-$mycut
E_SGN_FILE trueenergy_Numu-$mycut
E_FIDCUT_FILE trueenergy_fidcut-$mycut
E_ALLCUTS_FILE trueenergy_allcuts-$mycut
E_SGN_ALLCUTS_FILE trueenergy_Numu_allcuts-$mycut
E_BINS energybins_Numu
NPE_ALL_FILE NPEarray_all-$mycut
NPE_SGN_FILE NPEarray_Numu-$mycut
NPE_FIDCUTS_FILE NPEarray_fidcuts-$mycut
NPE_ALLCUTS_FILE NPEarray_allcuts-$mycut
NPE_SGN_ALLCUTS_FILE NPEarray_Numu_allcuts-$mycut
NPE_BINS NPEbins_Numu
E_ALL_FROM_DATA trueenergy_fromDATA_all-$mycut
E_SGN_FROM_DATA trueenergy_fromDATA_Numu-$mycut
E_FIDCUTS_FROM_DATA trueenergy_fromDATA_fidcuts-$mycut
E_ALLCUTS_FROM_DATA trueenergy_fromDATA_allcuts-$mycut
E_SGN_ALLCUTS_FROM_DATA trueenergy_fromDATA_Numu_allcuts-$mycut
SOURCE_FLUX_FILE /storage/DATA-02/juno/Users/sgiulio/Atmo/HondaFlux/juno-ally-20-12-solmin_OSC.d
MC_FILE /storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker/trees/MC_500K_1m_TOT.root
DATA_FILE /storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker/trees/DATA_10K_1m_TOT.root
" > output_Numu_osc/systcut/run/config_Numu_osc-$mycut
    echo "running data with $mycut ns cut..."
    ./makematrix output_Numu_osc/systcut/run/config_Numu_osc-$mycut
done

cp output_Numu_osc/*.txt output_Numu_osc/systcut/.
