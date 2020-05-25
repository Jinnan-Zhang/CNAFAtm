#!/bin/bash

for((Target=1;Target<100;Target+=50))
do
    echo dealing...Files begin from:$Target 
    sed "s/START/$Target/g"  $1.sh > $1$Target.sh
    chmod 774 $1$Target.sh
    bsub -q juno -o ${PWD}/logs/Sel_$Target.log -hl -M 4000000 ${PWD}/$1$Target.sh
done
# bsub -q juno -o myo3.log ${PWD}/CNAF_Atm.sh

#end