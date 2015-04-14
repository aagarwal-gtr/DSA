#include <stdio.h>
#include <string.h>

#define MAX 4

typedef struct node
{
	int id;
	char city[25];
}VERTEX;

typedef struct edge
{
	int adj;
	int distance;
}EDGE;

typedef struct graph
{
	VERTEX v[MAX];
	EDGE e[MAX][MAX];
}GRAPH;

GRAPH g;

int return_subscript(char s[]);

int main()
{
	int i,j;
	char city1[25], city2[25];
	int ans;

	for(i=0; i<MAX; i++) {
		printf("nEnter City?");
		scanf("%s",g.v[i].city);
		g.v[i].id = i;
	}

	printf("nNow enter information about distance if a route exists!");
	do {
		do {
			printf("nEnter city1?");
			scanf("%s",city1);
			printf("nEnter city2?");
			scanf("%s",city2);
			i=return_subscript(city1);
			j=return_subscript(city2);

		}while(i==-1 || j==-1);

		printf("nEnter distance?");
		g.e[i][j].adj=1;
		scanf("%d",&g.e[i][j].distance);
		printf("More entries (1/0)?");
		scanf("%d",&ans);
	}while(ans==1);

	printf("tt");

	for(i=0;i<MAX;i++)
		printf("%dt",g.v[i].id);
	printf("ntt");

	for(i=0;i<MAX;i++)
		printf("%st",g.v[i].city);
	printf("nn");

	for(i=0;i<MAX;i++) {
		printf("%d %st",g.v[i].id,g.v[i].city);
		for(j=0;j<MAX;j++)
			printf("%d/%dt",g.e[i][j].adj,g.e[i][j].distance);
		printf("n");
	}
	
	return 0;
}

int return_subscript(char str[])
{
	int i;
	for(i=0;i<MAX;i++)
		if(strcmp(g.v[i].city,str)==0)
			return i;
	return -1;
}
