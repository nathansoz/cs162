CC = g++
DEBUG = -g
CFLAGS =  $(DEBUG) -std=c++0x
PROGS = fileFilter
MAKEFLAGS = -k

all: $(PROGS)

fileFilter:
	$(CC) $(CFLAGS) FileFilter.cpp CopyFileFilter.cpp EncryptFileFilter.cpp main.cpp -o fileFilter
clean:
	rm -f *.o fileFilter
