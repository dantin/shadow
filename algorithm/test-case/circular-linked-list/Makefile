CC = gcc
CFLAGS = -Wall -std=c99 -g

list_test: circular_linked_list.o test.o
	$(CC) $(CFLAGS) -o list_test circular_linked_list.o test.o

circular_linked_list.o: init circular_linked_list.h circular_linked_list.c
	$(CC) $(CFLAGS) -c circular_linked_list.c

test.o: init circular_linked_list.h test.c
	$(CC) $(CFLAGS) -c test.c

init:
	cp ../../data-structure/circular_linked_list.h .
	cp ../../data-structure/circular_linked_list.c .

clean:
	rm circular_linked_list.h circular_linked_list.c test.o circular_linked_list.o list_test