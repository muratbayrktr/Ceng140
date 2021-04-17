# compiler
CC=gcc
# compiler flags
CFLAGS=-Wall -ansi -pedantic-errors
# link/load flags ex: "-lm" for math.h
LDFLAGS=

main :
	$(CC) $(CFLAGS) $(LDFLAGS) main.c -o main

clean :
	rm -rf main
	
all :
	rm -rf main
	sleep 1.5
	$(CC) $(CFLAGS) $(LDFLAGS) main.c -o main
	sleep 2
	clear
	./main