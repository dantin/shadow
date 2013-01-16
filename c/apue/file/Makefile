CC=gcc
PROGS=ls1 hello testerror uidgid
LIB_DIR=../lib.freebsd
.PHONY: clean test all

all: ${PROGS}

ls1: ls1.c $(LIB_DIR)/ourhdr.h $(LIB_DIR)/error.c
	$(CC) -o ls1 ls1.c $(LIB_DIR)/ourhdr.h $(LIB_DIR)/error.c

hello: hello.c $(LIB_DIR)/ourhdr.h
	$(CC) -o hello hello.c

testerror: testerror.c $(LIB_DIR)/ourhdr.h $(LIB_DIR)/error.c
	$(CC) -o testerror testerror.c $(LIB_DIR)/ourhdr.h $(LIB_DIR)/error.c

uidgid: uidgid.c $(LIB_DIR)/ourhdr.h
	$(CC) -o uidgid uidgid.c

clean:
	rm -f ${PROGS} *~

test:
	./ls1 .
	./hello
	./testerror
	./uidgid
