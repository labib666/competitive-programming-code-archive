#!/bin/bash

NAME=birthday

/usr/bin/g++ -DEVAL -static -O2 -o $NAME grader.c $NAME.cpp
