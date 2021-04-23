#!/bin/bash
echo "Compiling client"
gcc -Wall -o client  client.c -L/usr/lib -lssl -lcrypto
echo "Compiling server"
gcc -Wall -o server server.c -L/usr/lib -lssl -lcrypto
echo "Done"