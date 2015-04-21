#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

int graph[MAX][MAX] = {0};
int visited[MAX] = {0};

int n = 0;
int count = 0;

void DFS(int vertex)
{
	visited[vertex] = count;
	printf("%d ", vertex);
	int i, j;	
	for(j=1; j<=n; j++) {
		if(graph[vertex][j]==1 && visited[j]==0)
			DFS(j);
	}
}

int main()
{
	FILE *fp;
	fp = fopen("testing.txt", "r");
	int i, m, p, q;
	fscanf(fp, "%d", &n);
	fscanf(fp, "%d", &m);	
	for(i=0; i<m; i++) {
		fscanf(fp, "%d %d", &p, &q);
		graph[p][q] = 1;
		graph[q][p] = 1;
	}
	fclose(fp);

	for(i=1; i<=n; i++) {
		if(visited[i]==0) {
			count++;	
			DFS(i);
			printf("\n");
		}
	}
	
	printf("There are %d connected components\n", count);
	return 0;
}
