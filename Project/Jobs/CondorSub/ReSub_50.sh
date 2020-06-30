#!/bin/bash
# NOreSub=( 2901 3101 4001 1401 3901 4201 4401 1801 301 4101 )
NOreSub=(3001 2401 4101 301 1801 4701 4401 4201 3901 1401 4001 3101 901 2901 3801)
for((Target=1;Target<5101;Target+=100))
do
    COUNT_re=0
    for re in ${NOreSub[@]}
    do
        if [ $re -eq $Target ]
        then
            COUNT_re=`expr $COUNT_re + 1`
            break
        fi
    done
    if [ $COUNT_re -eq 0 ]
    then
        echo dealing...Files begin from:$Target 
        sed "s/START/$Target/g"  $1.sh > $1_$Target.sh
        sed "s/NPETE/$1_$Target/g" $1.sub > $1_$Target.sub
        chmod 774 $1_$Target.sh
        condor_submit -name sn-01.cr.cnaf.infn.it -spool $1_$Target.sub
        Target1=`expr $Target + 50 `
        echo dealing...Files begin from:$Target1
        sed "s/START/$Target1/g"  $1.sh > $1_$Target1.sh
        sed "s/NPETE/$1_$Target1/g" $1.sub > $1_$Target1.sub
        chmod 774 $1_$Target1.sh
        condor_submit -name sn-01.cr.cnaf.infn.it -spool $1_$Target1.sub
        # echo ${PWD}/$1_$Target.sh
    fi
done
#end
