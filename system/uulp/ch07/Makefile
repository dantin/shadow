CC=gcc
CFLAGS=-l curses
LIBS=

EXES=\
	hello\
	bounce\
	sleep\
	ticker_demo\
	sigdemo\
	sigactdemo\
	bounce1d

%: %.o
	${CC} -o $@ $< ${CFLAGS}

%.o: %.c
	${CC} -o $@ -c $< ${CFLAGS}

all: ${EXES}

clean:
	@rm -f ${EXES} *~ *.o