CC = gcc
CFLAGS = -Wall -std=c99 -g

list_test: singly_linked_list.o test.o
	$(CC) $(CFLAGS) -o list_test singly_linked_list.o test.o

singly_linked_list.o: init singly_linked_list.h singly_linked_list.c
	$(CC) $(CFLAGS) -c singly_linked_list.c

test.o: init singly_linked_list.h test.c
	$(CC) $(CFLAGS) -c test.c

init:
	cp ../../data-structure/singly_linked_list.h .
	cp ../../data-structure/singly_linked_list.c .

clean:
	rm singly_linked_list.h singly_linked_list.c test.o singly_linked_list.o list_test