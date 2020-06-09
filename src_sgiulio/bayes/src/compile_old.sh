#!/bin/bash
rm -rf ../Bayes.exe ../lib/Bayes.o
g++ -I$ROOTSYS/include -fPIC -Wall -fpermissive -c Bayes.cc -o ../lib/Bayes.o
g++ -Wall -I$ROOTSYS/include -L$ROOTSYS/lib main.cpp -lCore -lHist -lRIO -lTree -lGpad ../lib/Bayes.o -o ../Bayes.exe
