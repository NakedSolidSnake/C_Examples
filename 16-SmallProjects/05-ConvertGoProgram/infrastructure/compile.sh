#!/bin/bash

gcc -g3 -O0 -c -I./ queue.c -o queue.o
gcc -g3 -O0 -c -I./ parse.c -o parse.o
gcc -g3 -O0 -c -I./ service.c -o service.o
gcc -g3 -O0 -c -I./ controller.c -o controller.o
gcc -g3 -O0 -c -I./ file.c -o file.o
gcc -g3 -O0 -c -I./ main.c -o main.o
gcc -g3 -O0 -c -I./ -I/usr/include/mysql Repository.c -o Repository.o
gcc -g3 -O0 -c -I./ handle_partials.c -o handle_partials.o
gcc main.o queue.o controller.o parse.o service.o file.o Repository.o handle_partials.o -o server.out -lpthread -lmysqlclient
