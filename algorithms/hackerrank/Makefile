name = digit_frequency

run:
	if [  $(name) ]; then rm $(name); fi;
	sleep 2
	gcc $(name).c -o $(name)
	sleep 1
	clear
	./$(name) < input.txt
	