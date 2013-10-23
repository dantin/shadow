CC=gcc
CFLAGS=
LIBS=

EXES=\
	tinybc\
	popendemo\
	popen_ex3

%: %.o
	${CC} -o $@ $< ${CFLAGS}

%.o: %.c
	${CC} -o $@ -c $< ${CFLAGS}

all: ${EXES}

clean:
	@rm -f ${EXES} *.o *~ userlist
