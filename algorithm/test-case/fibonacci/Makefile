CC = gcc
CFLAGS = -std=c99 -Wall -g

all: recursive nonrecursive

recursive: fibonacci-recursive.o test.o
	$(CC) $(CFLAGS) -o recursive fibonacci-recursive.o test.o

nonrecursive: fibonacci-nonrecursive.o test.o
	$(CC) $(CFLAGS) -o nonrecursive fibonacci-nonrecursive.o test.o

fibonacci-recursive.o:
	cp ../../include/fibonacci.h .
	cp ../../recursive/fibonacci.c .
	$(CC) $(CFLAGS) -c -o fibonacci-recursive.o fibonacci.c
	rm fibonacci.[ch]

fibonacci-nonrecursive.o:
	cp ../../include/fibonacci.h .
	cp ../../nonrecursive/fibonacci.c .
	$(CC) $(CFLAGS) -c -o fibonacci-nonrecursive.o fibonacci.c
	rm fibonacci.[ch]

test.o: test.c
	cp ../../include/fibonacci.h .
	$(CC) $(CFLAGS) -c test.c
	rm fibonacci.h

clean:
	rm -f recursive fibonacci-recursive.o nonrecursive fibonacci-nonrecursive.o test.o