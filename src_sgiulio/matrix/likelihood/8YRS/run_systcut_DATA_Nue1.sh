#!/bin/bash
for n in {0..10}; do
    let "N_init = 70"
    let "mycut = $(expr n+N_init)"
    echo "MODE DATA
FAMILY e
TRES_CUT_VALUE $mycut
INCLUDE_OSC YES
BINS_ENERGY 7
BINS_NPE 7
LOWTHR_E 2.0
LOWTHR_NPE 5.0
UPTHR_E 4.05
UPTHR_NPE 7.2
FOLDER output_Nue_osc/systcut
LIK_FILE likmatrix_normNue-$mycut
MAT_ALL_FILE allmatrix_Nue-$mycut
MAT_SGN_FILE sgnmatrix_Nue-$mycut
MAT_BKG_FILE bkgmatrix_Nue-$mycut
E_ALL_FILE trueenergy_all-$mycut
E_SGN_FILE trueenergy_Nue-$mycut
E_FIDCUT_FILE trueenergy_fidcut-$mycut
E_ALLCUTS_FILE trueenergy_allcuts-$mycut
E_SGN_ALLCUTS_FILE trueenergy_Nue_allcuts-$mycut
E_BINS energybins_Nue
NPE_ALL_FILE NPEarray_all-$mycut
NPE_SGN_FILE NPEarray_Nue-$mycut
NPE_FIDCUTS_FILE NPEarray_fidcuts-$mycut
NPE_ALLCUTS_FILE NPEarray_allcuts-$mycut
NPE_SGN_ALLCUTS_FILE NPEarray_Nue_allcuts-$mycut
NPE_BINS NPEbins_Nue
E_ALL_FROM_DATA trueenergy_fromDATA_all-$mycut
E_SGN_FROM_DATA trueenergy_fromDATA_Nue-$mycut
E_FIDCUTS_FROM_DATA trueenergy_fromDATA_fidcuts-$mycut
E_ALLCUTS_FROM_DATA trueenergy_fromDATA_allcuts-$mycut
E_SGN_ALLCUTS_FROM_DATA trueenergy_fromDATA_Nue_allcuts-$mycut
SOURCE_FLUX_FILE /storage/DATA-02/juno/Users/sgiulio/Atmo/HondaFlux/juno-ally-20-12-solmin_OSC.d
MC_FILE /storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker/trees/MC_500K_1m_TOT.root
DATA_FILE /storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/treemaker/trees/DATA_10K_1m_TOT.root
" > output_Nue_osc/systcut/run/config_Nue_osc-$mycut
    echo "running data with $mycut ns cut..."
    ./makematrix output_Nue_osc/systcut/run/config_Nue_osc-$mycut
done

cp output_Nue_osc/*.txt output_Nue_osc/systcut/.
