CC = gcc
CFLAGS = -Wall -std=c99 -g

demo: circular_linked_list.o main.o
	$(CC) $(CFLAGS) -o demo circular_linked_list.o main.o

circular_linked_list.o: init circular_linked_list.h circular_linked_list.c
	$(CC) $(CFLAGS) -c circular_linked_list.c

main.o: init circular_linked_list.h main.c
	$(CC) $(CFLAGS) -c main.c

init:
	cp ../../data-structure/circular_linked_list.h .
	cp ../../data-structure/circular_linked_list.c .

clean:
	rm circular_linked_list.h circular_linked_list.c main.o circular_linked_list.o demo

test: demo
	./demo < data/input

memcheck: demo
	valgrind --tool=memcheck ./demo < data/input