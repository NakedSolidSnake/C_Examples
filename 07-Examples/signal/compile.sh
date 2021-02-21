#!/bin/bash

rm send recv
gcc -g signal_send.c -o send
gcc -g signal_recv.c -o recv
