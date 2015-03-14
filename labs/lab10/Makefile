CC = g++
CFLAGS =  -std=c++0x -O3 -lboost_chrono -lboost_system
PROGS = main
MAKEFLAGS = -k

all: $(PROGS)

main:
	$(CC) $(CFLAGS) main.cpp -o main

clean:
	rm -f *.o main
