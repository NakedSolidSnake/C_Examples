target: exec.out 
exec.out: 
	gcc -g 01-exec.c -o exec.out
	gcc -g 01-message.c -o message.out

target: helloworld.out
helloworld.out: 
	gcc -g 02-helloworld.c -o helloworld.out

target pipe.out: clean
	gcc -g 03-pipelaunch.c -o pipelaunch.out
	gcc -g 03-piperead.c   -o piperead.out
	gcc -g 03-pipewrite.c  -o pipewrite.out

target strtod.out:
	gcc -g 04-strtod.c -o strtod.out

target timespec.out:
	gcc -g 05-timespec.c -o timespec.out

target strstr.out:
	gcc -g 06-strstr.c -o strstr.out

clean:
	rm -rf *.out