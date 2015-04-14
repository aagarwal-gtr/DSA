#include<stdio.h>
#include<stdlib.h>

//initialize
void init(int **arr) {
int i, j;
for(i = 0; i < 5; i++) {
for(j = 0; j < 5; j++) {
arr[i][j] = 0;
}
}
}

//undirected
void insert(int **arr, int v1, int v2, int weight) {
arr[v1][v2] = weight;
arr[v2][v1] = weight;
}

void printMatrix(int **arr) {
int i, j;
for(i = 0; i < 5; i++) {
for(j = 0; j < 5; j++) {
printf("%d ", arr[i][j]);
}
printf("\n");
}
}

//bfs
void bfs(int **arr, int start) {
int i;
int visited[5] = {0}, queue[5] = {0};
visited[start] = 1;
int front, rear, root;
    front = 0;
rear = 0;
    queue[rear++] = start;
    printf("%d   ",start);
    while (front != rear)
    {
        root = queue[front];
        for (i = 0; i < 5; i++)
            if (arr[root][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
                printf("%d   ",i);
            }
        front++;
    }
}

//dfs
void dfs(int **arr, int visited[], int start) {
    int j;
    printf("%d   ", start);
    visited[start] = 1;
    for(j = 0; j < 5; j++) {
        if(!visited[j] && arr[start][j]!=0) {
            dfs(arr,visited,j);
        }
    }
}

int main() {
int **adj = (int **)malloc(5*sizeof(int*));
int i;
for(i = 0; i < 5; i++) {
adj[i] = (int *)malloc(5*sizeof(int));
}
init(adj);
insert(adj,1,0,4);
insert(adj,2,0,6);
insert(adj,2,3,3);
insert(adj,1,4,9);
insert(adj,3,4,9);
printMatrix(adj);
printf("\n");
bfs(adj,1);
printf("\n");
int visited[5] = {0};
dfs(adj,visited,4);
return 0;
}
