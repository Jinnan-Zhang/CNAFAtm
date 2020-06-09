#!/bin/bash
for n in {1..1000}; do
    echo "FAMILY mu
E_BINS_FILE energybins_Numu_7.txt
E_NORM_FILE HondaFlux_7_8.txt
MAT_FILE_SGN allmatrix_Numu_7_8.txt
MAT_FILE_BKG bkgmatrix_Numu_7_8.txt
NPE_BINS_FILE NPEbins_Numu_8.txt
NPE_FILE NPEarray_allcuts-${n}_8.txt
TRUE_E_FILE trueenergy_allcuts_7.txt
TRUE_E_FLUX HondaFlux_7_8.txt
PRIOR_FILE HondaFlux_7_8.txt
UNFOLDED_SPECTRUM Unf_spectrum-${n}
MC-DATA-RATIO 76.923077
N_ITER 1
INPUT_FOLDER /storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/matrix/likelihood/5YRS/output_Numu_osc/systoscillation
OUTPUT_FOLDER outputs_systosc_Numu
HONDA_FLUX_FILE /storage/DATA-02/juno/Users/sgiulio/Atmo/HondaFlux/juno-ally-20-12-solmin_OSC.d
SK_FLUX_FILE /storage/DATA-02/juno/Users/sgiulio/Atmo/analysis/unfolding/bayes/ext_fluxes/SK_flux_Numu.txt
" > outputs_systosc_Numu/run/config_Numu-$n
    echo "running ${n} spectrum..."
    ../Bayes.exe outputs_systosc_Numu/run/config_Numu-$n
done
