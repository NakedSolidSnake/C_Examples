target: student.out
student.out: main.o
	gcc main.o -o student.out

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -rf *.out *.o