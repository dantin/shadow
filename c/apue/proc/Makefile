CC=gcc
PROGS=shell1 shell2
LIB_DIR=../lib.freebsd
.PHONY: clean test all

all: ${PROGS}

shell1: shell1.c ourhdr.h $(LIB_DIR)/error.c
	$(CC) -o shell1 shell1.c $(LIB_DIR)/ourhdr.h $(LIB_DIR)/error.c

shell2: shell2.c ourhdr.h $(LIB_DIR)/error.c
	$(CC) -o shell2 shell2.c $(LIB_DIR)/ourhdr.h $(LIB_DIR)/error.c

clean:
	rm -f ${PROGS} *~

test:
	./shell1 < ../data/shell-input
	./shell2 < ../data/shell-input
