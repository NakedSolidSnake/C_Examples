target: car.out
car.out: main.o car.o	
	gcc main.o car.o -o car.out

main.o: main.c
	gcc -c -I./ main.c -o main.o

car.o: car.c 
	gcc -c -I./ car.c -o car.o

clean:
	rm -rf *.out *.o