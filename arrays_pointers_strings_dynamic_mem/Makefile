name = recursive_infix_eval
# compiler
CC=gcc
# compiler flags
CFLAGS=-Wall -ansi -pedantic-errors 
# link/load flags ex: "-lm" for math.h
LDFLAGS=

main:
	$(CC) $(CFLAGS) $(LDFLAGS) $(name).c -o $(name)

clean:
	 rm $(name)
	 
run:
	if [-a $(name)]; then rm $(name); fi;
	sleep 0.5
	$(CC) $(CFLAGS) $(LDFLAGS) $(name).c -o $(name)
	sleep 0.5
	clear
	./$(name) < $(name)_input.txt
	