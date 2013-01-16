C=gcc
PROGS=mycat getcputc
LIB_DIR=../lib.freebsd

.PHONY: clean test all

all: ${PROGS}

mycat: mycat.c $(LIB_DIR)/ourhdr.h $(LIB_DIR)/error.c
	$(CC) -o mycat mycat.c $(LIB_DIR)/ourhdr.h $(LIB_DIR)/error.c

getcputc: getcputc.c $(LIB_DIR)/ourhdr.h $(LIB_DIR)/error.c
	$(CC) -o getcputc getcputc.c $(LIB_DIR)/ourhdr.h $(LIB_DIR)/error.c

clean:
	rm -f ${PROGS} *~

test:
	./mycat < Makefile
	./getcputc < Makefile
