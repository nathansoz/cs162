CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = main
MAKEFLAGS = -k

all: $(PROGS)

main: 
	$(CC) $(CFLAGS) SozLibs/Dice.cpp GameChars/Character.cpp GameChars/Barbarian.cpp GameChars/ReptilePeople.cpp GameChars/Goblin.cpp GameChars/BlueMen.cpp GameChars/Shadow.cpp main.cpp -o main
clean:
	rm -f *.o main
