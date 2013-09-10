CC=g++
CCFLAGS=-std=c++11
LIBS=

EXES=\
	main_only\
	add\
	while_count\
	for_count\
	sum\
	occurs\
	item_io\
	add_item

.PHONY: all
all: $(EXES)

%: %.o
	$(CC) -o $@ $< $(CCFLAGS)

%.o: %.cc
	$(CC) -c -o $@ -c $< $(CCFLAGS)

item_io: item_io.o
add_item: add_item.o

.PHONY: clean
clean:
	@rm -f $(EXES) *~ *.o

.PHONY: test
test: all
	./test.sh
