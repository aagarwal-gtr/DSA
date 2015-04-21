#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct node
{
    struct node *next;
    int vertex;
}node;

node *G[MAX];    //heads of linked list
int visited[MAX] = {0};

int n = 0;
int count = 0;

void insert(int vi, int vj)
{
    node *p, *q;
    //acquire memory for the new node
    q = (node*)malloc(sizeof(node));
    q->vertex = vj;
    q->next = NULL;

    //insert the node in the linked list number vi
    if(G[vi] == NULL)
        G[vi] = q;
    else {
        //go to end of the linked list
        p = G[vi];
        
		while(p->next != NULL)
            p = p->next;
        
		p->next = q;
    }

}

void read_graph()
{

	FILE *fp;
	fp = fopen("inputGraph.txt", "r");

    int i, p, q, m;

    fscanf(fp, "%d", &n);

    //initialise G[] with a null
    for(i=1; i<=n; i++) {
        G[i] = NULL;
	}
    
	//read edges and insert them in G[]
	fscanf(fp, "%d", &m);

    for(i=0; i<m; i++) {
    	fscanf(fp, "%d %d", &p, &q);
    	insert(p, q);
    }
	
	fclose(fp);
}

void DFS(int i)
{
    node *p;
    
	p = G[i];
    visited[i] = count;
	printf("%d ", i);

	while(p != NULL) {
        i = p->vertex;
        if(!visited[i])
            DFS(i);
        p = p->next;
    }
}

int main()
{
    int i;

    read_graph();

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

