#!/bin/bash
#rm -rf ../Bayes.exe ../lib/Bayes.o
#g++ -I$ROOTSYS/include -fPIC -Wall -fpermissive -std=c++11 -c Bayes.cc -o ../lib/Bayes.o
#g++ -Wall -I$ROOTSYS/include -L$ROOTSYS/lib main.cpp -std=c++11 -lCore -lHist -lRIO -lTree -lGpad ../lib/Bayes.o -o ../Bayes.exe

rm -rf ../Bayes.exe ../lib/Bayes.o
g++ -I $ROOTSYS/include -fPIC -Wall -fpermissive -std=c++11 -c Bayes.cc -o ../lib/Bayes.o
g++ -O2 -Wall -I$ROOTSYS/include -Iinclude -I$ROOTSYS/lib/LAna//include/ -I$ROOTSYS/lib/SmartHistos//include main.cpp ../lib/Bayes.o -o ../Bayes.exe -L$ROOTSYS/lib -std=c++11 -lCore -lRIO -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lMatrix
