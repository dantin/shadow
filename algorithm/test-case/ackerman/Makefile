CC = gcc
CFLAGS = -std=c99 -Wall -g

all: recursive nonrecursive

recursive: ackerman-recursive.o test.o
	$(CC) $(CFLAGS) -o recursive ackerman-recursive.o test.o

nonrecursive: ackerman-nonrecursive.o test.o
	$(CC) $(CFLAGS) -o nonrecursive ackerman-nonrecursive.o test.o

ackerman-recursive.o:
	cp ../../include/ackerman.h .
	cp ../../recursive/ackerman.c .
	$(CC) $(CFLAGS) -c -o ackerman-recursive.o ackerman.c
	rm ackerman.[ch]

ackerman-nonrecursive.o:
	cp ../../include/ackerman.h .
	cp ../../nonrecursive/ackerman.c .
	$(CC) $(CFLAGS) -c -o ackerman-nonrecursive.o ackerman.c
	rm ackerman.[ch]

test.o: test.c
	cp ../../include/ackerman.h .
	$(CC) $(CFLAGS) -c test.c
	rm ackerman.h

clean:
	rm -f recursive ackerman-recursive.o nonrecursive ackerman-nonrecursive.o test.o