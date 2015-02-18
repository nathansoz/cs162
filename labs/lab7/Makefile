CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = generate search
MAKEFLAGS = -k

all: $(PROGS)

generate:
	$(CC) $(CFLAGS) generate.cpp -o generate

search:
	$(CC) $(CFLAGS) search.cpp -o search

clean:
	rm -f *.o generate search
