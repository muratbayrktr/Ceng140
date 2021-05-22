# compiler
CC=gcc
# compiler flags
CFLAGS=-Wall -ansi -pedantic-errors
# link/load flags ex: "-lm" for math.h
LDFLAGS=

main :
	$(CC) -c $(CFLAGS) $(LDFLAGS) lab2.c 
	sleep 0.5
	$(CC) $(CFLAGS) $(LDFLAGS) run.c -o main lab2.o

clean :
	rm -rf main lab2.o
	
all :
	make clean
	sleep 1
	make main
	sleep 1
	clear
	./main