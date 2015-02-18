CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = generate
MAKEFLAGS = -k

all: $(PROGS)

generate:
	$(CC) $(CFLAGS) generate.cpp -o generate

clean:
	rm -f *.o generate
