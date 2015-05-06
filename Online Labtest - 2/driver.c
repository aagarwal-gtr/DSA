#include <stdio.h>
#include <malloc.h>
#include <assert.h>

struct vertex
{
	int v;
	int visited;
	struct vertex * adj;
};

typedef struct vertex *Graph;

void insertedge(Graph g, int a, int b)
{
	Graph t;
	Graph tempA = (Graph) malloc (sizeof(struct vertex));
	assert(tempA != NULL);
	tempA -> v = a;
	tempA -> visited = 0;
	tempA -> adj = NULL;
	
	if(a != b)
	{
		Graph tempB = (Graph) malloc (sizeof(struct vertex));
		assert(tempB != NULL);
		tempB -> v = b;
		tempB -> visited = 0;
		tempB -> adj = NULL;

		t = &g[a];
		while(t -> adj != NULL)
			t = t -> adj;
		t -> adj = tempB;       //adding vertex b in adjcant list of vertex a
	}

	t = &g[b];
	while(t -> adj != NULL)
		t = t -> adj;
	t -> adj = tempA;		//adding vertex a in adjcant list of vertex b
}

int isNeighbourOf(Graph G, int u, int v)
{
// Write your code here
	Graph p;
	int resa = 0, resb = 0;
	p = &G[u];	
	while(p != NULL) {
		if(p -> v == v)
			resa = 1;
		p = p -> adj;
	}
	p = &G[v];	
	while(p != NULL) {
		if(p -> v == u)
			resb = 1;
		p = p -> adj;
	}
	if(resa == 1 && resb == 1)
		return 1;
	else
		return 0;
}

int checkK3(Graph G, int * result)

{
// Write your code here
	int res[3] = {0}, i, j;
	Graph p, q;
	for(i = 0; i < 3; i++) {
		p = &G[result[i]];
		for(j = 0; j < 3; j++) {
			if(i != j) {
				q = &G[result[j]];
				if(isNeighbourOf(G, p -> v, q -> v))
					res[i]++;
			}
		}
	}
	if((res[0] == 2) && (res[1] == 2) && (res[2] == 2))
		return 1;
	else
		return 0;
}

int checkK4(Graph G, int * result)

{
// Write your code here
	int res[4] = {0}, i, j;
	Graph p, q;
	for(i = 0; i < 4; i++) {
		p = &G[result[i]];
		for(j = 0; j < 4; j++) {
			if(i != j) {
				q = &G[result[j]];
				if(isNeighbourOf(G, p -> v, q -> v))
					res[i]++;
			}
		}
	}
	if((res[0] == 3) && (res[1] == 3) && (res[2] == 3) && (res[3] == 3))
		return 1;
	else
		return 0;
}

void DFS(Graph G, int start, int *result)
{
// Write your code here
	Graph p;
	p = &G[start];
	G[start].visited = 1;	
	while(p != NULL) {
		start = p -> v;
		if(G[start].visited != 1) {		
			result[start] = start;
			DFS(G, start, result);
		}
		p = p-> adj;
	}
}

int main(int *argc, char *argv[])
{
	int v, e, a, b, i;
	int counts[4]={0};
 	FILE *fout;

	FILE *f = fopen("input.txt", "r");
	assert(f != NULL);
	
	fscanf(f,"%d", &v);
	//printf("vertex = %d", v);
	fscanf(f,"%d", &e);
	//printf("\nedges = %d", e);
	
	
	//allocate memory for v vertices
	Graph g = (Graph) malloc (sizeof(struct vertex) * v);
	assert(g != NULL);
	
	//initialize adjacency list
	for(i = 0; i < v; i++)
	{
		g[i].v = i;
		g[i].visited = 0;
		g[i].adj = NULL;
	}
	
	for(i = 0; i < e; i++)
	{
		fscanf(f,"%d %d ", &a, &b);
		printf("\n%d %d", a, b);
		insertedge(g, a, b);
	}

	//allocate memory for list of vertices in connected component i.e. result
	int *result = (int*) malloc (sizeof(int) * 4);
	assert(result != NULL);

	for(i = 0; i < 4; i++) //initializing result array
		result[i] = -1;

	printf("DFT ->\n");
	for(i = 0; i < v; i++)
	{
		if(g[i].visited != 1)
		{
			int j,c=0;
			g[i].visited = 1;
			printf("\n%d ", g[i].v);
			DFS(g, g[i].v, result);
			for(j=0; j<=3; j++)
				if(result[j] != -1) c++;
			switch(c)
			{
				case 4:
					if (checkK4(g, result) == 1)
						counts[3]++;
					break;
				case 3:
					if(checkK3(g, result) == 1)
						counts[2]++;
					break;
				case 2:
					if (isNeighbourOf(g, result[0], result[1]) == 1)
						counts[1]++;
					break;
				case 1:
					counts[0] ++;
					break;
				default:
					break;

			}
			
		}
	}

	
	fout = fopen("output.txt", "w");
	for(i = 0; i < 4; i++)
		fprintf(fout, "\n%d", counts[i]);

		fprintf(fout, "\n");
	fclose(f);
	fclose(fout);
	return 0;
}
