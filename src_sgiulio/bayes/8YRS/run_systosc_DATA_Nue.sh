#!/bin/bash
for n in {1..1000}; do
    echo "FAMILY e
E_BINS_FILE energybins_Nue_7.txt
E_NORM_FILE HondaFlux_7_7.txt
MAT_FILE_SGN allmatrix_Nue_7_7.txt
MAT_FILE_BKG bkgmatrix_Nue_7_7.txt
NPE_BINS_FILE NPEbins_Nue_7.txt
NPE_FILE NPEarray_allcuts-${n}_7.txt
TRUE_E_FILE trueenergy_allcuts_7.txt
TRUE_E_FLUX HondaFlux_7_7.txt
PRIOR_FILE HondaFlux_7_7.txt
UNFOLDED_SPECTRUM Unf_spectrum-${n}
MC-DATA-RATIO 50.
N_ITER 1
INPUT_FOLDER /storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/matrix/likelihood/output_Nue_osc/systoscillation
OUTPUT_FOLDER outputs_systosc_Nue
HONDA_FLUX_FILE /storage/DATA-02/juno/Users/sgiulio/Atmo/HondaFlux/juno-ally-20-12-solmin_OSC.d
SK_FLUX_FILE /storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/bayes/ext_fluxes/SK_flux_Nue.txt
" > outputs_systosc_Nue/run/config_Nue-$n
    echo "running ${n} spectrum..."
    ./Bayes.exe outputs_systosc_Nue/run/config_Nue-$n
done
