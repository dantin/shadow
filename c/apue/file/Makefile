CC=gcc
PROGS=ls1 hello

.PHONY: clean test all

all: ${PROGS}

ls1: ls1.c ourhdr.h error.c
	$(CC) -o ls1 ls1.c ourhdr.h error.c

hello: hello.c ourhdr.h
	$(CC) -o hello hello.c

clean:
	rm -f ${PROGS} *~

test:
	./ls1 .
	./hello
