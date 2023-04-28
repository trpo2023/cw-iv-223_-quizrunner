Flags = -Wall -Werror

.PHONY: all

all: main

main: extract.o main.o
	gcc $(Flags) -o main main.o extract.o

extract.o: extract.c 
	gcc $(Flags) -c extract.c 

main.o: main.c 
	gcc $(Flags) -c main.c

.PHONY: run

run:
	./main