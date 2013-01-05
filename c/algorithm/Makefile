CC=gcc

.PHONY: clean test all

all: queen hanoi suduku 24-points bulbs permutation combination max-subsequence-sum big-integer quick-sort

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

max-subsequence-sum: max-subsequence-sum.c
	$(CC) -o max-subsequence-sum max-subsequence-sum.c

big-integer: big-integer.c
	$(CC) -o big-integer big-integer.c

quick-sort: quick-sort.c
	$(CC) -o quick-sort quick-sort.c

clean:
	rm -f queen hanoi suduku 24-points bulbs permutation combination max-subsequence-sum big-integer quick-sort a.out *~

test:
	./queen
	./hanoi < data/hanoi
	./suduku < data/suduku
	./24-points < data/24-points
	./bulbs
	./permutation
	./combination
	./max-subsequence-sum
	./big-integer < data/big-integer
	./quick-sort
