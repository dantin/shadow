CC = gcc
CFLAGS = -Wall -std=c99 -g

list_test: linked_list.o test.o
	$(CC) $(CFLAGS) -o list_test linked_list.o test.o

linked_list.o: init linked_list.h linked_list.c
	$(CC) $(CFLAGS) -c linked_list.c

test.o: init linked_list.h test.c
	$(CC) $(CFLAGS) -c test.c

init:
	cp ../../data-structure/linked_list.h .
	cp ../../data-structure/linked_list.c .

