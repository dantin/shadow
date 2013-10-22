CC=gcc
CFLAGS=
LIBS=

EXES=\
	listargs\
	stdinredir_cto\
	stdinredir_ocdc\
	stdinredir_dup2\
	whotofile\
	pipedemo\
	pipedemo2\
	pipe

%: %.o
	${CC} -o $@ $< ${CFLAGS}

%.o: %.c
	${CC} -o $@ -c $< ${CFLAGS}

all: ${EXES}

clean:
	@rm -f ${EXES} *.o *~ userlist
