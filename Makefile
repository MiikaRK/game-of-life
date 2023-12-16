CC=gcc
CFLAGS=-Wall -ansi -pedantic -lncursesw

gameoflife.exe: main.o init_game.o init_table.o count_neighbours.o calculate_game.o
	$(CC) main.o init_game.o init_table.o count_neighbours.o calculate_game.o -o gameoflife.exe $(CFLAGS)

main.o: main.c gol.h  
	$(CC) -c main.c $(CFLAGS)

init_game.o: init_game.c gol.h
	$(CC) -c init_game.c $(CFLAGS)

init_table.o: init_table.c gol.h
	$(CC) -c init_table.c $(CFLAGS)

count_neighbours.o: count_neighbours.c gol.h 
	$(CC) -c count_neighbours.c $(CFLAGS)

calculate_game.o: calculate_game.c gol.h
	$(CC) -c calculate_game.c $(CFLAGS)

clean: 
	rm -f main.o init_game.o init_table.o count_neighbours.o calculate_game.o gameoflife.exe
