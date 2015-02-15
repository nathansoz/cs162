CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = test
MAKEFLAGS = -k

all: $(PROGS)

test:
	$(CC) $(CFLAGS) SozLibs/Stats.cpp Dice.cpp Character.cpp Barbarian.cpp ReptilePeople.cpp Goblin.cpp BlueMen.cpp Shadow.cpp TestDriver.cpp -o test
clean:
	rm -f *.o test