#!/bin/bash
gcc main.c `pkg-config --cflags --libs gtk+-2.0` -o gtktest