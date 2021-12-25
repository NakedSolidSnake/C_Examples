# Hexagonal Architecture

## Selecting which way will be used
In Hexagon application we can use two ways to interect with application one is through UDP server and the second is through CLI.
Select a way to use application before compiling.

## Compile
Change directory to src 
```bash
$ mkdir build && cd build && cmake .. && make
```

## Run Application
After build change to bin directory
```bash
$ ./hexagon
```

## Test application 
With running application open a client to connect using netcat
```bash
$ nc -u localhost 1234
```

Send messages using the following tags
_add_
_remove_
_all_
*by_id*
