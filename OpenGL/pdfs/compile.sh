#!/bin/bash

gcc -g 01-main.c -o 01-main.out -lglut -lGLU -lGL
gcc -g 02-main.c -o 02-main.out -lglut -lGLU -lGL
gcc -g 03-main.c -o 03-main.out -lGLEW -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lm