#!/bin/bash

gcc main.c -o main.o -g -c&
gcc cparser.c -o cparser.o -g -c&
gcc main.o cparser.o -g -o cparser

