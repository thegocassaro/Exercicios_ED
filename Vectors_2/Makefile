all:
	gcc -Wall -g -o main *.c

clean:
	rm -f main

val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main < entrada_8 > saida