#!/bin/bash
# for((Target=1;Target<5101;Target+=100))
for((Target=1;Target<5001;Target+=100))
do
    echo dealing...Files begin from:$Target 
    sed "s/START/$Target/g"  $1.sh > $1_$Target_100.sh
    sed "s/NPETE/$1$Target/g" $1.sub > $1_$Target_100.sub
    chmod 774 $1_$Target_100.sh
    condor_submit -name sn-01.cr.cnaf.infn.it -spool $1_$Target_100.sub
    # bsub -q juno -o ${PWD}/logs/NEPTE_$Target.log -hl -M 4000000 ${PWD}/$1_$Target_100.sh
    echo ${PWD}/$1_$Target_100.sh
done
#end