#!/bin/bash
echo "Server compiling"
gcc -Wall -o server server.c -L/usr/lib -lssl -lcrypto
# if [ "$?" -eq 0 ]; then
#     echo "Done."
# else
#     echo "Error"
#     return
# if

echo "Done."
echo ""

echo "Client compiling..."
gcc -Wall -o client  client.c -L/usr/lib -lssl -lcrypto
echo "Done"

