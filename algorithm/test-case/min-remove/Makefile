CC = gcc
CFLAGS = -Wall -std=c99 -g

min_remove: singly_linked_list.o main.o
	$(CC) $(CFLAGS) -o min_remove singly_linked_list.o main.o

singly_linked_list.o: init singly_linked_list.h singly_linked_list.c
	$(CC) $(CFLAGS) -c singly_linked_list.c

main.o: init singly_linked_list.h main.c
	$(CC) $(CFLAGS) -c main.c

init:
	cp ../../data-structure/singly_linked_list.h .
	cp ../../data-structure/singly_linked_list.c .

clean:
	rm -f singly_linked_list.h singly_linked_list.c main.o singly_linked_list.o min_remove

test:
	./min_remove < data/input