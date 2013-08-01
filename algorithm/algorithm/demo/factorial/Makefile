CC = gcc
CFLAGS = -std=c99 -Wall -g

all: recursive

recursive: factorial-recursive.o recursive-test.o
	$(CC) $(CFLAGS) -o recursive factorial-recursive.o recursive-test.o

factorial-recursive.o:
	cp ../../include/factorial.h .
	cp ../../recursive/factorial.c .
	$(CC) $(CFLAGS) -c -o factorial-recursive.o factorial.c
	rm factorial.[ch]

recursive-test.o: recursive-test.c
	cp ../../include/factorial.h .
	$(CC) $(CFLAGS) -c recursive-test.c
	rm factorial.h

clean:
	rm recursive factorial-recursive.o recursive-test.o