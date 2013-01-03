CC=gcc

.PHONY: clean test all

all: queen hanoi suduku 24-points bulbs permutation combination

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

permutation: permutation.c
	$(CC) -o permutation permutation.c

combination: combination.c
	$(CC) -o combination combination.c

clean:
	rm -f queen hanoi suduku 24-points bulbs permutation combination a.out *~

test:
	./queen
	./hanoi < data/hanoi
	./suduku < data/suduku
	./24-points < data/24-points
	./bulbs
	./permutation
	./combination
