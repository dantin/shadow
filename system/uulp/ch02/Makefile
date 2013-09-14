CC=gcc
CFLAGS=
LIBS=

EXES=\
	who

%: %.o
	${CC} -o $@ $< ${LIBS}

%.o: %.c
	${CC} -o $@ -c $<

all: ${EXES}

clean:
	@rm -f ${EXES} *~