CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = fileSort
MAKEFLAGS = -k

all: $(PROGS)

fileSort:
	$(CC) $(CFLAGS) fileSort.cpp -o fileSort
clean:
	rm -rf *.o fileSort
