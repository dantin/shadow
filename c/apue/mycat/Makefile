C=gcc
PROGS=mycat getcputc

.PHONY: clean test all

all: ${PROGS}

mycat: mycat.c ourhdr.h error.c
	$(CC) -o mycat mycat.c ourhdr.h error.c

getcputc: getcputc.c ourhdr.h error.c
	$(CC) -o getcputc getcputc.c ourhdr.h error.c

clean:
	rm -f ${PROGS} *~

test:
	./mycat < Makefile
	./getcputc < Makefile
