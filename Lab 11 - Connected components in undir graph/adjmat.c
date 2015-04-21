#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

int graph[MAX][MAX] = {0};
int visited[MAX] = {0};

void DFS(int vertex, int n)
{
	visited[vertex]++;
	printf("%d ", vertex);
	int j;	
	for(j=1; j<=n; j++) {
		if(graph[vertex][j] && !visited[j])
			DFS(j, n);
	}
}

void printmat(int n)
{
	int i, j;
	printf("   ");
	for(i=1; i<=n; i++)
		printf("%2d ", i);
	printf("\n");
	for(i=1; i<=n; i++) {
		printf("%2d ", i);
		for(j=1; j<=n; j++)
			printf("%2d ", graph[i][j]);
		printf("\n");
	}
}

int main()
{
	FILE *fp;
	//fp = fopen("test.txt", "r");
	fp = fopen("inputGraph.txt", "r");
	int i, m, n, p, q, count = 0;
	fscanf(fp, "%d", &n);
	fscanf(fp, "%d", &m);	
	for(i=0; i<m; i++) {
		fscanf(fp, "%d %d", &p, &q);
		graph[p][q] = 1;
		graph[q][p] = 1;
	}
	fclose(fp);

	printf("The matrix follows:\n"); printmat(n);
	printf("Connected components:\n");
	
	for(i=1; i<=n; i++) {
		if(!visited[i]) {
			count++;	
			DFS(i, n);
			printf("\n");
		}
	}
	
	printf("There are %d connected components\n", count);
	return 0;
}
