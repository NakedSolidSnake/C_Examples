emcc -O3 -s WASM=1 -o hello.html hello.c
echo "access service on localhost:8000/hello.html"
python -m SimpleHTTPServer 8000  
# emcc hello.c -o hello.html
# emcc hello.c -s WASM=1 -o hello.html