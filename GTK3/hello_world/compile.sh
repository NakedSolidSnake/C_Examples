#!/bin/bash

echo "Compiling..."
gcc -g3 -o gladewin.out main.c -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
echo "Done!"