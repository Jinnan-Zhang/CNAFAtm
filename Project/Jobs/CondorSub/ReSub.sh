#!/bin/bash
NOreSub=(2901 3101 4001 1401 3901 4201 4401 1801 301 4101 )
for((Target=1;Target<510;Target+=100))
do
    if [[ "${NOreSub[@]}" =~ $Target ]]
    then
        echo dealing...Files begin from:$Target 
        # sed "s/START/$Target/g"  $1.sh > $1$Target.sh
        # sed "s/NPETE/$1$Target/g" $1.sub > $1$Target.sub
        # chmod 774 $1$Target.sh
        # condor_submit -name sn-01.cr.cnaf.infn.it -spool $1$Target.sub
        # echo ${PWD}/$1$Target.sh
    fi
done
#end
