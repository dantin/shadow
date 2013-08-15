CC = gcc
CFLAGS = -Wall -std=c99 -g

big_integer: doubly_linked_list.o main.o
	$(CC) $(CFLAGS) -o big_integer doubly_linked_list.o main.o

doubly_linked_list.o: init doubly_linked_list.h doubly_linked_list.c
	$(CC) $(CFLAGS) -c doubly_linked_list.c

main.o: init doubly_linked_list.h main.c
	$(CC) $(CFLAGS) -c main.c

init:
	cp ../../data-structure/doubly_linked_list.h .
	cp ../../data-structure/doubly_linked_list.c .

clean:
	rm -f doubly_linked_list.h doubly_linked_list.c main.o doubly_linked_list.o big_integer

test:
	./big_integer < data/input