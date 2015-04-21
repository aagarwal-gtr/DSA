#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct node
{
    struct node *next;
    int vertex;
}node;

node *G[MAX];
int visited[MAX] = {0};

void insert(int vi, int vj)
{
    node *p, *q;
    
    q = (node*)malloc(sizeof(node));
    q->vertex = vj;
    q->next = NULL;

    if(G[vi] == NULL)
        G[vi] = q;
    else {
    	p = G[vi];   
		while(p->next != NULL) {
            p = p->next;
            if(p->vertex == vj)
            	return;
        }
		p->next = q;
    }
}

int read_graph()
{

	FILE *fp;
	//fp = fopen("test.txt", "r");
	fp = fopen("inputGraph.txt", "r");
    int i, p, q, m, n;
    fscanf(fp, "%d", &n);

    for(i=1; i<=n; i++) {
        G[i] = NULL;
	}

	fscanf(fp, "%d", &m);

    for(i=0; i<m; i++) {
    	fscanf(fp, "%d %d", &p, &q);
    	insert(p, q);
    	insert(q, p);
    }
	
	fclose(fp);
	return n;
}

void DFS(int i)
{
    node *p;
    
	p = G[i];
    visited[i]++;
	printf("%d ", i);

	while(p != NULL) {
        i = p->vertex;
        if(!visited[i])
            DFS(i);
        p = p->next;
    }
}

void printlist(int n)
{
	node *p;
    int i;
    for(i=1; i<=n; i++) {
    	p = G[i];
    	printf("%d -> ", i);
    	while(p != NULL) {
			printf("%d -> ", p->vertex);
            p = p->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int i, n, count =  0;

    n = read_graph();
	
	printf("The list follows:\n"); printlist(n);	
	printf("Connected components:\n");
	
	for(i=1; i<=n; i++) {
		if(!visited[i]) {
			count++;	
			DFS(i);
			printf("\n");
		}
	}
	
	printf("There are %d connected components\n", count);

	return 0;
}
