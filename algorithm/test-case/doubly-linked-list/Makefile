CC = gcc
CFLAGS = -Wall -std=c99 -g

list_test: doubly_linked_list.o test.o
	$(CC) $(CFLAGS) -o list_test doubly_linked_list.o test.o

doubly_linked_list.o: init doubly_linked_list.h doubly_linked_list.c
	$(CC) $(CFLAGS) -c doubly_linked_list.c

test.o: init doubly_linked_list.h test.c
	$(CC) $(CFLAGS) -c test.c

init:
	cp ../../data-structure/doubly_linked_list.h .
	cp ../../data-structure/doubly_linked_list.c .

clean:
	rm doubly_linked_list.h doubly_linked_list.c test.o doubly_linked_list.o list_test