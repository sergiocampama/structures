#!/bin/bash

gcc -c -g src/hash.c -Iheaders -o bin/hash.o
gcc -c -g src/list.c -Iheaders -o bin/list.o
gcc -c -g src/main.c -Iheaders -o bin/main.o

gcc bin/hash.o bin/list.o bin/main.o -o bin/main