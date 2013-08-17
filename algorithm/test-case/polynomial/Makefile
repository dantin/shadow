CC = gcc
CFLAGS = -Wall -std=c99 -g

demo: polynomial.o main.o doubly_linked_list.o
	$(CC) $(CFLAGS) -o demo polynomial.o main.o doubly_linked_list.o

polynomial.o: init polynomial.h polynomial.c
	$(CC) $(CFLAGS) -c polynomial.c

doubly_linked_list.o: init doubly_linked_list.h doubly_linked_list.c
	$(CC) $(CFLAGS) -c doubly_linked_list.c

main.o: init doubly_linked_list.h main.c
	$(CC) $(CFLAGS) -c main.c

init:
	cp ../../data-structure/doubly_linked_list.h .
	cp ../../data-structure/doubly_linked_list.c .

clean:
	rm -f doubly_linked_list.h doubly_linked_list.c main.o doubly_linked_list.o polynomial.o demo

test:
	./demo < data/input