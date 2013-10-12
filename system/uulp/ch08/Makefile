CC=gcc
CFLAGS=
LIBS=

EXES=\
	exec\
	psh\
	forkdemo\
	forkdemo2

%: %.o
	${CC} -o $@ $< ${CFLAGS}

%.o: %.c
	${CC} -o $@ -c $< ${CFLAGS}

all: ${EXES}

clean:
	@rm -f ${EXES} *~ *.o