CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = generate search sort binarySearch
MAKEFLAGS = -k

all: $(PROGS)

generate:
	$(CC) $(CFLAGS) generate.cpp -o generate

search:
	$(CC) $(CFLAGS) search.cpp -o search

sort:
	$(CC) $(CFLAGS) sort.cpp -o sort

binarySearch:
	$(CC) $(CFLAGS) binarySearch.cpp -o binarySearch

clean:
	rm -f *.o generate search sort binarySearch
