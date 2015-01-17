CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = life
MAKEFLAGS = -k

all: $(PROGS)

life:
	$(CC) $(CFLAGS) Board.cpp Cell.cpp main.cpp -o life
clean:
	rm -f *.o life