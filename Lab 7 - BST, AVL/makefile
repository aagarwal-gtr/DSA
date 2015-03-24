all: bst

bst: driver.o bstops.o
	gcc driver.o bstops.o -o bst

driver.o: driver.c
	gcc -W -Wall -O2 -c driver.c

bstops.o: bstops.c
	gcc -W -Wall -O2 -c bstops.c
