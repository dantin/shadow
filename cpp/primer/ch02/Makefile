CXX=g++
CPPFLAGS=-std=c++11 -Wall
LIBS=

EXES=\
	convs\
	unsigned\
	escape\
	literals\
	inits\
	ref-ex\
	scope_levels

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
