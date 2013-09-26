CC=gcc
CFLAGS=
LIBS=

EXES=\
	rotate\
	play_again\
	sigdemo

%: %.o
	${CC} -o $@ $< ${CFLAGS}

%.o: %.c
	${CC} -o $@ -c $< ${CFLAGS}

all: ${EXES}

clean:
	@rm -f ${EXES} *~ *.o