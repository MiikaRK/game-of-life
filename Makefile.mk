# Makefile #

CC=gcc

gameoflife.exe: main.o init_game.o init_table.o count_neighbours.o calculate_game.o
	$(CC) main.o init_game.o init_table.o count_neighbours.o calculate_game.o -o gameoflife.exe

main.o: main.c gol.h  
	$(CC) -c main.c 

init_game.o: init_game.c gol.h
	$(CC) -c init_game.c  

init_table.o: init_table.c gol.h
	$(CC) -c init_table.c

count_neighbours.o: count_neighbours.c gol.h 
	$(CC) -c count_neighbours.c

calculate_game.o: calculate_game.c gol.h
	$(CC) -c calculate_game.c