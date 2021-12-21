rm -rf build
mkdir build
gcc -Wall -Wextra -o src/main src/main.c $(pkg-config gtk+-3.0 --cflags --libs) -export-dynamic
cp -r glade build
cp src/main build
cd build
./main