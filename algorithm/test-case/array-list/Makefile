CC = gcc
CFLAGS = -Wall -std=c99 -g

demo: array_list.o test.o
	$(CC) $(CFLAGS) -o demo array_list.o test.o

array_list.o: init array_list.h array_list.c
	$(CC) $(CFLAGS) -c array_list.c

test.o: init array_list.h test.c
	$(CC) $(CFLAGS) -c test.c

init:
	cp ../../data-structure/array_list.h .
	cp ../../data-structure/array_list.c .

clean:
	rm array_list.h array_list.c test.o array_list.o demo

test: demo
	./demo

memcheck: demo
	valgrind --tool=memcheck ./demo