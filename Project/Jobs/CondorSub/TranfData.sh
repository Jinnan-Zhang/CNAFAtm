#!/bin/bash
for((Data=5489276;Data<5489324;Data+=1))
do
    echo retrieve: job: $Data
    condor_transfer_data -name sn-01.cr.cnaf.infn.it $Data.0
done
# (3001 2401 4101 301 1801 4701 4401 4201 3901 1401 4001 3101 901 2901)