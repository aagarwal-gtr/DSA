#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Maze.h"
#include "MazeOps.h"

typedef struct sele{
	int x, y;
}ele;

struct stack{
	ele data[100];
	int top;
}s;

s.top=-1;
int sizz=0;

void push(int datax, int datay) {
	s.data[sizz].x=datax; s.data[sizz].y=datay;
	sizz++;
	s.top=sizz;
}

void pop() {
	s.top--;
}

void set(char *path_so_far, int posi, int posj)
{   char a[1000];
    sprintf(a,"(%d,%d)", posi, posj);
    strcat(path_so_far,a);
}

Boolean findCheese(Maze m, int n, int posi, int posj, char *path_so_far, int pasti, int pastj) {
    if(posi>=0 && posi<n && posj>=0 && posj<n){
	push(0, 0);
        if(m[posi][posj] == 9) {
            
            set(path_so_far, posi, posj);
            return true;
        }

        else if(posi>0 && (m[posi-1][posj]==0||m[posi-1][posj]==9) && (posi-1)!=pasti) {
	   push(posi, posj);              
		set(path_so_far, posi, posj);
                return true;
           
        }

        else if(posj>0 && (m[posi][posj-1]==0||m[posi][posj-1]==9) && (posj-1)!=pastj) {
            push(posi, posj);
                set(path_so_far, posi, posj);
                return true;
            
        }

        else if(posi<n-1 && (m[posi+1][posj]==0||m[posi+1][posj]==9) && (posi+1)!=pasti) {
            push(posi, posj);
                set(path_so_far, posi, posj);
                return true;
            
        }

        else if(posj<n-1 && (m[posi][posj+1]==0||m[posi][posj+1]==9) && (posj+1)!=pastj) {
            push(posi, posj);
                set(path_so_far, posi, posj);
                return true;
            
        }

        else
            return false;
    }
    return false;	
}
