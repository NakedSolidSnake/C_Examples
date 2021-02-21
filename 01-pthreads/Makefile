#CC		:= gcc
CC		:= arm-linux-gnueabihf-gcc
DEBUG   :=  -g3 -O0
STD99 	:= -std=c99
STD11 	:= -std=c11

target: creating_thread.out
creating_thread.out: 
	$(CC) ${DEBUG} ${STD99} 01-creating_thread.c -o creating_thread.out -lpthread

target: create_ex1.out
create_ex1.out:
	$(CC) ${DEBUG} ${STD99} 02-EX1_creating_thread.c -o create_ex1.out -lpthread

target: thread_return.out
thread_return.out:
	$(CC) ${DEBUG} ${STD99} 03-EX2_Thread_Return.c -o thread_return.out -lpthread -lm

target: mutex.out
mutex.out:
	$(CC) ${DEBUG} ${STD99} 04-mutex.c -o mutex.out -lpthread

target: condition.out
condition.out:
	$(CC) ${DEBUG} ${STD11} -D_GNU_SOURCE  05-cond.c -o condition.out -lpthread 

target: generic.out
generic.out:
	$(CC) ${DEBUG} ${STD11} -D_GNU_SOURCE 06-generic.c -o generic.out -lpthread 

target: thread_debug.out
thread_debug.out:
	$(CC) ${DEBUG} ${STD99} 07-thread_debug.c -o thread_debug.out -lpthread

clean:
	rm -rf *.out