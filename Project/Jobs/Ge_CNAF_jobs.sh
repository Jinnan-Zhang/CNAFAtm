#!/bin/bash

for((Target=0;Target<4;Target++))
do
    echo dealing...Files begin from:$Target 
    sed "s/START/$Target/g"  $1.sh > $1$Target.sh
    chmod 774 $1$Target.sh
    

    # hep_sub -mem 4000 $1$"%{ProcId}".sh -n 4 
done


#end