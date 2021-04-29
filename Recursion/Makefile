# compiler
CC=gcc
# compiler flags
CFLAGS=-Wall -ansi -pedantic-errors
# link/load flags ex: "-lm" for math.h
LDFLAGS=

gcd :
	$(CC) $(CFLAGS) $(LDFLAGS) gcd.c -o gcd

simp-seq :
	$(CC) $(CFLAGS) $(LDFLAGS) simp-seq.c -o simp-seq

tower_of_hanoi:
	$(CC) $(CFLAGS) $(LDFLAGS) tower_of_hanoi.c -o tower_of_hanoi

recaman:
	$(CC) $(CFLAGS) $(LDFLAGS) recaman.c -o recaman

power:
	$(CC) $(CFLAGS) $(LDFLAGS) power.c -o power

clean :
	rm -rf gcd simp-seq recaman tower_of_hanoi power
	
all :
	rm -rf gcd simp-seq tower_of_hanoi
	sleep 1.5
	$(CC) $(CFLAGS) $(LDFLAGS) gcd.c -o gcd
	$(CC) $(CFLAGS) $(LDFLAGS) simp-seq.c -o simp-seq
	$(CC) $(CFLAGS) $(LDFLAGS) tower_of_hanoi.c -o tower_of_hanoi
	sleep 2
	clear
