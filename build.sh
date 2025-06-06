#! bin/bash


TDA=$1


g++ -std=c++20 -c ${TDA}/src/*.cpp && g++ -std=c++20 *.o -o exec && rm *.o
