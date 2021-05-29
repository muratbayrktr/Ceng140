name = circular_rotation

main:
	gcc -Wall -pedantic-errors $(name).c -o $(name)

clean:
	rm $(name)

run:
	if [-a $(name)]; then rm $(name); fi;
	sleep 0.5
	gcc $(name).c -o $(name)
	sleep 0.5
	clear
	./$(name) < $(name)_input.txt
	