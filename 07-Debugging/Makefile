target: coredump.out
coredump.out: 
	gcc -g 01-Coredump.c -o coredump.out

target: exec.out 
exec.out: 
	gcc -g3 -ggdb 02-exec.c -o exec.out
	gcc -g 02-message.c -o message.out

clean:
	rm -rf *.out

clean: 
	rm -rf *.out