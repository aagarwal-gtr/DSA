#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 6

/*
int graph[][MAX] = {
 {0, 12, 10, 0, 9, 0},
 {12, 0, 0, 11, 0, 0},
 {10, 0, 0, 15, 0, 0},
 {0, 11, 15, 0, 0, 0},
 {9, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0}
}; */

int graph[][MAX] = {
 {0, 1, 0, 1, 1, 0},
 {1, 0, 0, 1, 0, 0},
 {0, 0, 0, 0, 0, 1},
 {1, 1, 0, 0, 0, 0},
 {1, 0, 0, 0, 0, 0},
 {0, 1, 0, 0, 0, 0}
};

int visited[MAX]={0};

void bfs(int source, int amt)
{    
	int queue[MAX];
	int i, front, rear, root;
	front = rear = 0;
	visited[source] = 1;
	queue[rear++] = source;
	printf("%d   ",source);
	//for(i=0; i<MAX; i++)
	//		if(graph[source][i])
	//			visited[i] = graph[source][i];
	while(front != rear) {
		root = queue[front];
		for(i=0; i<MAX; i++) { 
			//visited[i] += graph[root][i];
			if(graph[root][i] && visited[i]==0) {
				visited[i] = graph[root][i];
				queue[rear++] = i;
				printf("%d   ",i);
			}

		}
		front++;
	}
	printf("\n");
	for(i=0; i<MAX; i++) printf("%d ", visited[i]);
	printf("\n");
}


int total = 0;

void dfs(int source) {
       
    int i;
    printf("%d   ", source);
    visited[source] = 1;
    
    for(i=0; i<MAX; i++) {    
        if(!visited[i] && graph[source][i]) {
            total += graph[source][i];
            dfs(i);
        }
    }
}

int main()
{
	//bfs(3, 13);

	dfs(0); printf("\n%d\n", total);
    
	return 0;
}
