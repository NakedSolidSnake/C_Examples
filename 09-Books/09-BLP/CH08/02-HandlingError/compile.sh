#!/bin/bash

gcc -I/usr/include/mysql main.c -L/usr/lib/mysql -lmysqlclient -o connect
