PROJ=hello
CC=emcc
CFLAGS= -O3 --emrun -s WASM=1

$(PROJ).html: $(PROJ).c 
	$(CC) $(CFLAGS) -o $(PROJ).html $(PROJ).c

clean:
	rm -rf $(PROJ).html $(PROJ).wasm $(PROJ).js

run:
	echo "access service on localhost:8000/hello.html"
	python -m SimpleHTTPServer 8000  