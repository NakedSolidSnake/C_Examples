#!/bin/bash

echo "compiling producer"
gcc producer.c -o producer.out -lipc

echo "compiling consumer"
gcc consumer.c -o consumer.out -lipc