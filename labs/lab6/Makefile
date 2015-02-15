CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = sort search binarySearch
MAKEFLAGS = -k

all: $(PROGS)

sort:
	$(CC) $(CFLAGS) sort.cpp -o sort
search:
	$(CC) $(CFLAGS) search.cpp -o search
binarySearch:
	$(CC) $(CFLAGS) binarySearch.cpp -o binarySearch
clean:
	rm -f *.o search sort binarySearch
