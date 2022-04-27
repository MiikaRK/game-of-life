# Makefile #

CC=gcc

gameoflife.exe: main.o init_game.o init_table.o count_neighbours.o calculate_game.o
	$(CC) main.o init_game.o init_table.o count_neighbours.o calculate_game.o -o gameoflife.exe -lncursesw -Wall -pedantic 

main.o: main.c gol.h  
	$(CC) -c main.c -Wall -ansi -pedantic -lncursesw

init_game.o: init_game.c gol.h
	$(CC) -c init_game.c -Wall -ansi -pedantic -lncursesw

init_table.o: init_table.c gol.h
	$(CC) -c init_table.c -Wall -ansi -pedantic -lncursesw

count_neighbours.o: count_neighbours.c gol.h 
	$(CC) -c count_neighbours.c -Wall -ansi -pedantic -lncursesw

calculate_game.o: calculate_game.c gol.h
	$(CC) -c calculate_game.c -Wall -ansi -pedantic -lncursesw

clean: 
	del main.o init_game.o init_table.o count_neighbours.o calculate_game.o