CC=gcc
CFLAGS=-l curses -lrt
LIBS=

EXES=\
	hello\
	bounce\
	sleep\
	ticker_demo\
	sigdemo\
	sigactdemo\
	bounce1d\
	bounce2d\
	bounce_async\
	bounce_io

%: %.o
	${CC} -o $@ $< ${CFLAGS}

%.o: %.c
	${CC} -o $@ -c $< ${CFLAGS}

all: ${EXES}

clean:
	@rm -f ${EXES} *~ *.o