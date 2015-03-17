#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Maze.h"
#include "MazeOps.h"

int main(int argc, char *argv[]) {	
	char finame[20], foname[20];
	strcpy(finame, argv[1]);
	strcpy(foname, "output.txt");
	int startx = atoi(argv[1]), starty = atoi(argv[2]);
	Maze a;
	char path_so_far[1000];
	strcpy(path_so_far, "");
	printf("%s %s %d %d", finame, foname, startx, starty);
	int i, j, size = createMaze(&a, finame);
	findCheese(a, size, startx, starty, path_so_far, -10, -10);       
	FILE *fp;
	fp = fopen(foname, "w");
	fprintf(fp, "%s\n", path_so_far);
	fclose(fp);
	free(a);
	return 0;
}
