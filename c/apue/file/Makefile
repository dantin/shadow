CC=gcc
PROGS=ls1

.PHONY: clean test all

all: ${PROGS}

ls1: ls1.c ourhdr.h error.c
	$(CC) -o ls1 ls1.c ourhdr.h error.c

clean:
	rm -f ${PROGS} "*~"

test:
	./ls1 .
