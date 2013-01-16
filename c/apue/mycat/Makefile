C=gcc
PROGS=mycat

.PHONY: clean test all

all: ${PROGS}

mycat: mycat.c ourhdr.h error.c
	$(CC) -o mycat mycat.c ourhdr.h error.c

clean:
	rm -f ${PROGS} *~

test:
	./mycat < Makefile
