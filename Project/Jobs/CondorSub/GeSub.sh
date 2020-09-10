#!/bin/bash
# for((Target=1;Target<5101;Target+=100))
for((Target=1;Target<5001;Target+=100))
do
    echo dealing...Files begin from:$Target 
    sed "s/START/$Target/g"  $1.sh > $1$Target.sh
    sed "s/NPETE/$1$Target/g" $1.sub > $1$Target.sub
    chmod 774 $1$Target.sh
    condor_submit -name sn-01.cr.cnaf.infn.it -spool $1$Target.sub
    # bsub -q juno -o ${PWD}/logs/NEPTE_$Target.log -hl -M 4000000 ${PWD}/$1$Target.sh
    echo ${PWD}/$1$Target.sh
done
#end
# sed "s/100 START/65 5001/g"  NPETE.sh > NPETE5001.sh
# sed "s/NPETE/NPETE5001/g" NPETE.sub > NPETE5001.sub