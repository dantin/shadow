CC=gcc
CFLAGS=
LIBS=

EXES=\
	who\
	cp

%: %.o
	${CC} -o $@ $< ${LIBS}

%.o: %.c
	${CC} -o $@ -c $<

all: ${EXES}

clean:
	@rm -f ${EXES} *~