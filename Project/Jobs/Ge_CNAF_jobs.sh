#!/bin/bash

for((Target=0;Target<4;Target++))
do
    for ((Mode=0;Mode<3;Mode++))
    do
        echo dealing....Par:$Target Mode:$Mode
        sed "s/NLNR TarPar/$Mode $Target/g"  $1.sh > $1$Mode$Target.sh
        chmod 755 $1$Mode$Target.sh
        hep_sub -mem 4000 $1$Mode$Target.sh
    done
    # hep_sub -mem 4000 $1$Mode"%{ProcId}".sh -n 4 
done


#end