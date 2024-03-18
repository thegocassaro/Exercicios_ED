all:
	gcc -Wall -o main *.c

clean:
	rm -f main

val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main