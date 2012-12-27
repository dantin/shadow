CC=gcc

.PHONY: clean test all

all: nQueen hanoi suduku

nQueen: nQueen.c
	$(CC) -o nQueen nQueen.c

hanoi: hanoi.c
	$(CC) -o hanoi hanoi.c

suduku: suduku.c
	$(CC) -o suduku suduku.c

clean:
	rm -f nQueen hanoi suduku a.out *~

test:
	./nQueen
	./hanoi < data/hanoi
	./suduku < data/suduku
