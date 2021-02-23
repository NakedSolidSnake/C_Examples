#
# Makefile
#

CC=gcc
all: add-server.out add-client.out

%.o: %.c 
	gcc -g3  -Wall -c `pkg-config --cflags dbus-1` $< -o $@

add-server.out: server.o
	$(CC) server.o -o add-server.out `pkg-config --libs dbus-1`

add-client.out: client.o
	$(CC) client.o -o add-client.out `pkg-config --libs dbus-1`

.PHONY: clean
clean:
	rm *.o *.out