CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = life
MAKEFLAGS = -k

all: $(PROGS)

life:
	$(CC) $(CFLAGS) Dice.cpp LoadedDice.cpp SozLibs/Stats.cpp main.cpp -o dice
clean:
	rm -f *.o dice