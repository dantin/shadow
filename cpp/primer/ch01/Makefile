CC=g++
CCFLAGS=-std=c++0x
LIBS=

SRC_DIR=.
EXE_DIR=.

EXES=\
	$(EXE_DIR)/main_only\
	$(EXE_DIR)/add\
	$(EXE_DIR)/while_count\
	$(EXE_DIR)/for_count\
	$(EXE_DIR)/sum\
	$(EXE_DIR)/occurs

$(EXE_DIR)/%: %.o
	$(CC) -o $@ $< $(LIBS)

%.o: $(SRC_DIR)/%.cc
	$(CC) $(CCFLAGS) -o $@ -c $<

all: $(EXES)

clean:
	@rm -f $(EXES) *~

test: all
	./test.sh
