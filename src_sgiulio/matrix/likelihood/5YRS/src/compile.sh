#!/bin/bash
rm -rf ../5YRSmakematrix ./Data.o
g++ -I $ROOTSYS/include -fPIC -Wall -fpermissive -std=c++11 -c Data.C -o ./Data.o
g++ -O2 -Wall -I$ROOTSYS/include -Iinclude -I$ROOTSYS/lib/LAna//include/ -I$ROOTSYS/lib/SmartHistos//include main.cpp Data.o -o ../5YRSmakematrix -L$ROOTSYS/lib -std=c++11 -lCore -lRIO -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lMatrix -lMathCore
