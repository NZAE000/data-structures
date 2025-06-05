#!bin/bash


g++ -std=c++20 -c src/*.cpp && g++ -std=c++20 *.o -o exec && rm *.o

