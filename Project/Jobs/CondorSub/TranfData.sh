#!/bin/bash
for((Data=5489276;Data<5489324;Data+=1))
do
    echo retrieve: job: $Data
    condor_transfer_data -name sn-01.cr.cnaf.infn.it $Data.0
done