CC=gcc
CFLAGS=
LIBS=

EXES=\
	listargs\
	stdinredir_cto

%: %.o
	${CC} -o $@ $< ${CFLAGS}

%.o: %.c
	${CC} -o $@ -c $< ${CFLAGS}

all: ${EXES}

clean:
	@rm -f ${EXES} *.o *~