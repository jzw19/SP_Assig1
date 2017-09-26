CC=gcc

CFLAGS=-Wall

sorter: Sorter.c mergesort.c
	gcc $(CCFLAGS) Sorter.c -o Sorter

clean:
	rm -f Sorter