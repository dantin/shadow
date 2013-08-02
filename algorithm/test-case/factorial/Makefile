CC = gcc
CFLAGS = -std=c99 -Wall -g

all: recursive nonrecursive

recursive: factorial-recursive.o test.o
	$(CC) $(CFLAGS) -o recursive factorial-recursive.o test.o

nonrecursive: factorial-nonrecursive.o test.o
	$(CC) $(CFLAGS) -o nonrecursive factorial-nonrecursive.o test.o

factorial-recursive.o:
	cp ../../include/factorial.h .
	cp ../../recursive/factorial.c .
	$(CC) $(CFLAGS) -c -o factorial-recursive.o factorial.c
	rm factorial.[ch]

factorial-nonrecursive.o:
	cp ../../include/factorial.h .
	cp ../../nonrecursive/factorial.c .
	$(CC) $(CFLAGS) -c -o factorial-nonrecursive.o factorial.c
	rm factorial.[ch]

test.o: test.c
	cp ../../include/factorial.h .
	$(CC) $(CFLAGS) -c test.c
	rm factorial.h

clean:
	rm -f recursive factorial-recursive.o nonrecursive factorial-nonrecursive.o test.o