CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = dice
MAKEFLAGS = -k

all: $(PROGS)

dice:
	$(CC) $(CFLAGS) Dice.cpp LoadedDice.cpp SozLibs/Stats.cpp main.cpp -o dice
clean:
	rm -f *.o dice