#!/bin/bash

cd LED
gcc -g -fPIC -Wall -Werror -Wextra -pedantic *.c -shared -o led.so -ldl
cd - 
cd Button
gcc -g -fPIC -Wall -Werror -Wextra -pedantic *.c -shared -o button.so -ldl
cd - 
gcc -g3 -O0 -o plugin main.c -ldl