CC=gcc
CFLAGS=
LIBS=

EXES=\
	write\
	listchars\
	echostate\
	setecho\
	showtty

%: %.o
	${CC} -o $@ $< ${CFLAGS}

%.o: %.c
	${CC} -o $@ -c $< ${CFLAGS}

all: ${EXES}

clean:
	@rm -f ${EXES} *~ *.o