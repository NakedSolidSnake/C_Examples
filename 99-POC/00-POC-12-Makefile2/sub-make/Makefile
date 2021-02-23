CC = gcc
CFLAGS = -W -Wall -ansi -pedantic
EXEC=teste2
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(EXEC)
	@echo "Compilando sub-makefile"

$(EXEC): $(OBJ)
	@$(CC) -o $@ $^

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
