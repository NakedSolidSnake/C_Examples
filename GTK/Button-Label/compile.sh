#!/bin/bash
gcc main.c `pkg-config --cflags --libs gtk+-3.0` -o gtktest