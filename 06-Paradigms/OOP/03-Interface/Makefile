all: app.out

app.out: main.o gpio.o led.o button.o
	gcc -g main.o gpio.o led.o button.o -o app.out

main.o: main.c led.o button.o
	gcc -g -c -I./ main.c -o main.o button.o

button.o: button.c gpio.o
	gcc -g -c -I./ button.c -o button.o gpio.o

led.o: led.c gpio.o
	gcc -g -c -I./ led.c -o led.o gpio.o

gpio.o: gpio.c
	gcc -g -c -I./ gpio.c -o gpio.o

clean:
	rm -rf *.o *.out