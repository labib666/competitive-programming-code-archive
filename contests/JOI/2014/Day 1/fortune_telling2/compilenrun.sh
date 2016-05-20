#!/bin/sh
NAME=fortune_telling2
/usr/bin/g++ -std=c++11 -O2 -DEVAL -static -o $NAME $NAME.cpp
./$NAME
