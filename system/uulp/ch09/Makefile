CC=gcc
CFLAGS=
LIBS=

EXES=\
	smsh

smsh: smsh.o splitline.o execute.o
	$(CC) -o smsh smsh.o splitline.o execute.o $(CFLAGS)

smsh.o: smsh.c smsh.h
	$(CC) -c -o smsh.o smsh.c $(CFLAGS)

splitline.o: splitline.c
	$(CC) -c -o splitline.o splitline.c $(CFLAGS)

execute.o: execute.c
	$(CC) -c -o execute.o execute.c $(CFLAGS)

all: ${EXES}

clean:
	@rm -f ${EXES} *.o *~