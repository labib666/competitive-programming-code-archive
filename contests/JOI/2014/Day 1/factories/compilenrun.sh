#!/bin/sh
/usr/bin/g++ -std=c++11 -DEVAL -static -O2 -o factories grader.cpp factories.cpp
./factories
