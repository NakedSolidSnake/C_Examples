#!/bin/bash

gcc -g -I. -c window.c
gcc -g -I. -c main.c
gcc -g -o window.out main.o window.o -lSDL2