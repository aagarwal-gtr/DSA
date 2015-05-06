all: driver.o populateHash.o printVicinity.o partitionInto4.o findMid.o
	gcc -o test -pg driver.o populateHash.o printVicinity.o partitionInto4.o findMid.o

findMid.o: findMid.c
	gcc -c -pg findMid.c

partitionInto4.o: partitionInto4.c
	gcc -c -pg partitionInto4.c

printVicinity.o: printVicinity.c
	gcc -c -pg printVicinity.c

populateHash.o: populateHash.c
	gcc -c -pg populateHash.c

driver.o: driver.c
	gcc -c -pg driver.c

clean:
	rm *.o
