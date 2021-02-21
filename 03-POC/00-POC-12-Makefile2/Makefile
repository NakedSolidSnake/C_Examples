################ Makefile ##################
#Definição de variaveis
CC			= gcc
CFLAGS			=-W -Wall -ansi -pedantic
TARGET			= teste
SRC			= $(wildcard *.c)
OBJ			= $(SRC:.o=.c)
BIN_DIR			= /bin

all: $(TARGET)
	@cd sub-make && $(MAKE)

#linka os objetos para gerar o executavel
$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o
	@cd sub-make && $(MAKE) $@
	@echo "compilação pronta"

mrproper: clean
	rm -rf $(TARGET) 
	@cd sub-make && $(MAKE) $@

install: all
	@mv $(TARGET) $(BIN_DIR)
