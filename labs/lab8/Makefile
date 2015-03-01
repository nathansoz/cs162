CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = game
MAKEFLAGS = -k

all: $(PROGS)

game:
	$(CC) $(CFLAGS) Maze.cpp gameLoop.cpp -o game

clean:
	rm -f *.o game
