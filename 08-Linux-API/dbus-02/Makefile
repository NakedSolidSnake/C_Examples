target: dbusexample.out

dbusexample.out: 
	gcc  01-dbus.c -o dbusexample.out `pkg-config --libs --cflags dbus-1`

clean:
	rm -rf *.out *.o
