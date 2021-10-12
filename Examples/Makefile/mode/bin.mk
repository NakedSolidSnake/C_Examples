PROJECT_NAME = soma_x86

CC 			:= gcc
CFLAGS		:= -W -Wall -ansi -pedantic

COMPILE = $(CC) $(OBJECTS) -o $@ $(LDFLAGS)