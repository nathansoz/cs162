CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = lab1-1 lab1-2
MAKEFLAGS = -k

all: $(PROGS)

lab1-1:
	$(CC) $(CFLAGS) lab1-1.cpp -o lab1-1
lab1-2:
	$(CC) $(CFLAGS) f.cpp g.cpp lab1-2.cpp -o lab1-2
clean:
	rm -rf *.o lab1-1 lab1-2
