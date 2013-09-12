CC=gcc
CFLAGS=
LIBS=

EXES=\
	more

%: %.o
	${CC} -o $@ $< ${LIBS}

%.o: %.c
	${CC} -o $@ -c $<

all: ${EXES}

clean:
	@rm -f ${EXES} *~