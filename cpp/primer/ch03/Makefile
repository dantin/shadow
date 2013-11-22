CXX=g++
CPPFLAGS=-std=c++11 -Wall
LIBS=

EXES=\
	add_using\
	string_io\
	string_io2\
	word_echo

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
