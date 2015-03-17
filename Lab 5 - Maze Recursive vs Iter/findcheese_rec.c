#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Maze.h"
#include "MazeOps.h"

void set(char *path_so_far, int posi, int posj)
{   char a[1000];
    sprintf(a,"(%d,%d)", posi, posj);
    strcat(path_so_far,a);
}

Boolean findCheese(Maze m, int n, int posi, int posj, char *path_so_far, int pasti, int pastj) {
    if(posi>=0 && posi<n && posj>=0 && posj<n){

        if(m[posi][posj] == 9) {
            set(path_so_far, posi, posj);
            return true;
        }

        else if(posi>0 && (m[posi-1][posj]==0||m[posi-1][posj]==9) && (posi-1)!=pasti) {
	   if(findCheese(m, n, posi-1, posj, path_so_far, posi, posj)) {
                set(path_so_far, posi, posj);
                return true;
            }
        }

        else if(posj>0 && (m[posi][posj-1]==0||m[posi][posj-1]==9) && (posj-1)!=pastj) {
            if(findCheese(m, n, posi, posj-1, path_so_far, posi, posj)) {
                set(path_so_far, posi, posj);
                return true;
            }
        }

        else if(posi<n-1 && (m[posi+1][posj]==0||m[posi+1][posj]==9) && (posi+1)!=pasti) {
            if(findCheese(m, n, posi+1, posj, path_so_far, posi, posj)) {
                set(path_so_far, posi, posj);
                return true;
            }
        }

        else if(posj<n-1 && (m[posi][posj+1]==0||m[posi][posj+1]==9) && (posj+1)!=pastj) {
            if(findCheese(m, n, posi, posj+1, path_so_far, posi, posj)) {
                set(path_so_far, posi, posj);
                return true;
            }
        }

        else
            return false;
    }
    return false;
}
