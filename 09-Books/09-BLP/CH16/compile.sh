#!/bin/bash

gcc gtk1.c -o gtk1 `pkg-config --cflags --libs gtk+-3.0`
gcc gtk2.c -o gtk2 `pkg-config --cflags --libs gtk+-3.0`
