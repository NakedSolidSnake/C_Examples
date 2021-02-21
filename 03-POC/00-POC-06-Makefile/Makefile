
all:

app: operations.o log.o main.o
	gcc -o app operations.o log.o main.o

operations.o: libs/math/operations.c
	gcc -c -Ilibs/math libs/math/operations.c

log.o: libs/print/log.c
	gcc -c -Ilibs/print libs/print/log.c

main.o: src/main.c
	gcc -c -Ilibs/math -Ilibs/print src/main.c

clean:
	rm -rf libs/math/*.o
	rm -rf libs/print/*.o
	rm app
