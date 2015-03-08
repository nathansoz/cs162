CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x -Wno-conversion-null
PROGS = test
MAKEFLAGS = -k

all: $(PROGS)

test:
	$(CC) $(CFLAGS) SozLibs/Dice.cpp TestDriver.cpp -o TestDriver

clean:
	rm -f *.o TestDriver
