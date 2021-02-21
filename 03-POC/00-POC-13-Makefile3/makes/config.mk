#workspace
WORKSPACE		:= $(shell $(pwd)../)

#Toolchain

CC				:= gcc
AR				:= ar
MD				:= mkdir
RM				:= rm -rf

#Compiler Flags
CFLAGS			:= -g -O0

#Libraries
LDFLAGS			:= -lm -lpthread -lrt


#include
INCLUDE			:=  \
					-Iinclude
