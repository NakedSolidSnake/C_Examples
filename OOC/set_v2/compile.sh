#!/bin/bash

gcc -c -I./ set.c -o set.o  
gcc -c -I./ main.c -o main.o  

gcc set.o main.o -o set.out