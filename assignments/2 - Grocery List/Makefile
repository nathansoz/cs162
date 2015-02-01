CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x -lncurses -lmenu -lform
PROGS = glist
MAKEFLAGS = -k

all: $(PROGS)

glist:
	$(CC) $(CFLAGS) Item.cpp List.cpp main.cpp -o glist
clean:
	rm -f *.o glist
