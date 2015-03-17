all: htops

htops: query.o htops.o
	gcc query.o htops.o -o htops

query.o: query.c
	gcc query.c

htops.o: htops.c
	gcc htops.c
