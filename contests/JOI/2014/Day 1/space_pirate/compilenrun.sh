#!/bin/sh
NAME=space_pirate
/usr/bin/g++ -std=c++11 -O2 -DEVAL -static -o $NAME $NAME.cpp
./$NAME
