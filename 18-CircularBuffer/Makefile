CC := gcc

CSOURCES = $(wildcard *.c)
#INCLUDE_DIR = $(CSOURCES)

CFLAGS = -I$(INCLUDE_DIR)

all: app

app: $(CSOURCES:.c=.o)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $< $(CFLAGS)  $@

clean:
	rm -rf *.o app	

