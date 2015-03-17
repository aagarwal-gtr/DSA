#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Maze.h"
#include "MazeOps.h"

int getsize(char *temp) {
	int count=0, len=strlen(temp), i;
	for(i=0; i<len; i++) {
		if(temp[i]==',')
		count++;
    	}
   	return count;
}

int createMaze(Maze *pm, char *mazefilename) {
	FILE *fp;
	fp = fopen(mazefilename,"r");
	char temp[1000];
        Maze a;
        int size = 0, i, j;
        fscanf(fp,"%s",temp);
        size = getsize(temp);
        fclose(fp);
        a = (Maze)malloc(size*sizeof(int *));
        for(i=0; i<size; i++) {
		a[i] = (int *)malloc(size*sizeof(int));
        }
	fp = fopen(mazefilename,"r");
	for(i=0; i<size; i++) {
        	for(j=0; j<size; j++)
            	fscanf(fp, "%d,", &a[i][j]);
	}
	*pm=a;
	//fclose(fp);
	return size;
}
