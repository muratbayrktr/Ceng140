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

clean :
	rm -rf gcd simp-seq
	
all :
	rm -rf gcd simp-seq
	sleep 1.5
	$(CC) $(CFLAGS) $(LDFLAGS) gcd.c -o gcd
	$(CC) $(CFLAGS) $(LDFLAGS) simp-seq.c -o simp-seq
	sleep 2
	clear
