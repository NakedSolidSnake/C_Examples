target: coredump.out
coredump.out: 
	gcc -g Coredump.c -o coredump.out

target: exec.out 
exec.out: 
	gcc -g3 -ggdb exec.c -o exec.out
	gcc -g message.c -o message.out

clean:
	rm -rf *.out

clean: 
	rm -rf *.out