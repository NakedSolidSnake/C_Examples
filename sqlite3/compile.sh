#!/bin/bash
gcc -g sqlite_connect.c -o sqlite_connect.out -l sqlite3
gcc -g sqlite_create_table.c -o sqlite_create_table.out -l sqlite3
gcc -g sqlite_insert.c -o sqlite_insert.out -l sqlite3
gcc -g sqlite_select.c -o sqlite_select.out -l sqlite3
gcc -g sqlite_update.c -o sqlite_update.out -l sqlite3
gcc -g sqlite_delete.c -o sqlite_delete.out -l sqlite3
