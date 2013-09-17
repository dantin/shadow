CC=gcc
CFLAGS=
LIBS=

EXES=\
	who\
	cp\
	buffer_who

%: %.o
	${CC} -o $@ $< ${CFLAGS}

%.o: %.c
	${CC} -o $@ -c $< ${CFLAGS}

buffer_who: buffer_who.o utmplib.o
	$(CC) -o $@ buffer_who.o utmplib.o

all: ${EXES}

clean:
	@rm -f ${EXES} *~ *.o