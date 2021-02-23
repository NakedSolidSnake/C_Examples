#!/bin/bash

gcc -c -I./ queue.c -o queue.o
gcc -c -I./ main.c -o main.o
gcc main.o queue.o -o server.out -lpthread
