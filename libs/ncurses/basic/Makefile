CC=gcc
LIBS=-lncurses

SRC_DIR=.
EXE_DIR=../demo/exe

EXES=\
	${EXE_DIR}/hello_world\
	${EXE_DIR}/init_func_example\
	${EXE_DIR}/printw_example\
	${EXE_DIR}/scanw_example\
	${EXE_DIR}/simple_attr\
	${EXE_DIR}/with_chgat\
	${EXE_DIR}/win_border\
	${EXE_DIR}/other_border\
	${EXE_DIR}/simple_color

${EXE_DIR}/%: %.o
	${CC} -o $@ $< ${LIBS}

%.o: ${SRC_DIR}/%.c
	${CC} -o $@ -c $<

all: ${EXES}

clean:
	@rm -f ${EXES} *~