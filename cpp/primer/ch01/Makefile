CXX=g++
CPPFLAGS=-std=c++11
LIBS=

EXES=\
	main_only\
	add\
	while_count\
	for_count\
	sum\
	occurs\
	item_io\
	add_item\
	avg_price

.PHONY: all
all: $(EXES)

%: %.o
	$(CXX) -o $@ $< $(CPPFLAGS)

%.o: %.cc
	$(CXX) -c -o $@ -c $< $(CPPFLAGS)

.PHONY: clean
clean:
	@rm -f $(EXES) *~

.PHONY: test
test: all
	./test.sh
