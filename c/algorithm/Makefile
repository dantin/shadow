CC=gcc

.PHONY: clean test all

all: queen hanoi suduku 24-points bulbs

queen: queen.c
	$(CC) -o queen queen.c

hanoi: hanoi.c
	$(CC) -o hanoi hanoi.c

suduku: suduku.c
	$(CC) -o suduku suduku.c

24-points: 24-points.c
	$(CC) -o 24-points 24-points.c

bulbs: bulbs.c
	$(CC) -o bulbs bulbs.c

clean:
	rm -f queen hanoi suduku 24-points bulbs a.out *~

test:
	./queen
	./hanoi < data/hanoi
	./suduku < data/suduku
	./24-points < data/24-points
	./bulbs
