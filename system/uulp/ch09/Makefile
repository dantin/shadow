CC=gcc
CFLAGS=
LIBS=

EXES=\
	smsh\
	showenv\
	getenv\
	changeenv

changeenv: changeenv.c
	$(CC) -o changeenv changeenv.c $(CFLAGS)

getenv: getenv.c
	$(CC) -o getenv getenv.c $(CFLAGS)

showenv: showenv.c
	$(CC) -o showenv showenv.c $(CFLAGS)

smsh: smsh.o splitline.o execute.o process.o controlflow.o builtin.o varlib.o
	$(CC) -o smsh smsh.o splitline.o execute.o process.o controlflow.o builtin.o varlib.o $(CFLAGS)

varlib.o: varlib.c
	$(CC) -c -o varlib.o varlib.c $(CFLAGS)

builtin.o: builtin.c
	$(CC) -c -o builtin.o builtin.c $(CFLAGS)

smsh.o: smsh.c smsh.h
	$(CC) -c -o smsh.o smsh.c $(CFLAGS)

splitline.o: splitline.c
	$(CC) -c -o splitline.o splitline.c $(CFLAGS)

execute.o: execute.c
	$(CC) -c -o execute.o execute.c $(CFLAGS)

process.o: process.c
	$(CC) -c -o process.o process.c $(CFLAGS)

controlflow.o: controlflow.c smsh.h
	$(CC) -c -o controlflow.o controlflow.c $(CFLAGS)

all: ${EXES}

clean:
	@rm -f ${EXES} *.o *~