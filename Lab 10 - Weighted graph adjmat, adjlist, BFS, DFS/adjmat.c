#include <stdio.h>
#include <malloc.h>
#define inf 999

typedef struct NODE
{

  int item;
  struct NODE *next;

}node;


node *create(int item)
{
  node *newnode=(node *)malloc(sizeof(node));
  newnode->item=item;
  newnode->next=NULL;
  return newnode;
}

void display(node *temp)
{
  while (temp)
  {
    printf("%d ",temp->item);temp=temp->next;
  }
}

typedef struct
{
 node *front;
 node *rear;
 int size;
}Queue;

void initialise(Queue *q)
{
 (*q).front=NULL;
 (*q).rear=NULL;
 (*q).size=0;
}

void enqueue(Queue *q,int item)
{
 (*q).size++;
 node *newnode=create(item);
 if ((*q).front==NULL)
 {
  (*q).front=newnode;
  (*q).rear=newnode;return;
 }
 
  ((*q).rear)->next=newnode;
  (*q).rear=newnode;
}

int dequeue(Queue *q)
{
  if ((*q).front==NULL)
  {
   printf("empty\n");
   return -1;
  }
  int temp=((*q).front)->item;
  (*q).front=((*q).front)->next;
  (*q).size--;
  return temp;
}

int isempty(Queue q)
{
  if (q.front==NULL)
    return 1;
  return 0;
}
int shortpath(int weight[][6],int s,int t)
{
  int distance[6],perm[6];
  int current,i,k,dc;
  int smalldist,newdist;
  for (i=0;i<6;i++)
  {
   perm[i]=0;
   distance[i]=9999;
  }
  perm[s]=1;
  distance[s]=0;
  current=s;
  while (current!=t){
    smalldist=999;
    dc=distance[current];
    for (i=0;i<6;i++)
      if (perm[i]==0)
      {
        newdist=dc+weight[current][i];
        if (newdist<distance[i])
         {
            distance[i]=newdist;
         }
        if (distance[i]<smalldist)
         {
         smalldist=distance[i];
         k=i;
         }
      }
  current=k;
  perm[current]=1;}
  return distance[t];
}


int prev;
int total=0;
void dfs (int vis[],int a[][6],int pos)   //give prev as 0 initially
{

 printf("visiting %d\n",pos);
  vis[pos]=1;
  int i;
  for (i=0;i<6;i++)
  {
    if (!vis[i] && a[pos][i]!=10)
    {dfs(vis,a,i);
     total+=a[pos][i];
    
    }
  
  
  }
  if (a[pos][i]!=10)
  total+=a[pos][prev];   //does n't matter in a undirected graaph
  prev=pos;
}




int main(int argc,char *argv[])
{

/*weight matrix with 10 as infinity later change it to a suitable value
int a[6][6]={
{10,2,3,4,10,10},
{2,10,10,10,1,2},
{3,10,10,10,10,10},
{4,10,10,10,10,10},
{10,1,10,10,10,10},
{10,2,10,10,10,10}
};



*/


//take input from file

int a[6][6];

//also change the fixed size from 6
int i,j;
int start=0;   //take it asa input from here
int visited[6]={0};

sscanf(argv[2],"%d",&start);


FILE *fp;
fp=fopen(argv[1],"r");


for (i=0;i<6;i++)
{
 for (j=0;j<6;j++)
  {
   fscanf(fp,"%d,",&a[i][j]);
  
  } 

}


Queue q;
initialise(&q);
enqueue(&q,start);
visited[start]=1;


int visiting=-1;
int len=0;
int distance[6]={0};

/*
while (!isempty(q))
{
  visiting=dequeue(&q);
  printf("visiting %d\n",visiting);
  for (i=0;i<6;i++)
  {
     if (a[visiting][i] && !visited[i])
     {
       enqueue(&q,i);
       distance[i]=a[visiting][i]+distance[visiting];
       visited[i]=1;
     }
  }
  len++;
}
*/
//bfs done at this point

//show this to inst

printf("The jetties you can travel with 100 rupees aare\n");

for (i=0;i<6;i++)
{
  int temp=shortpath(a,start,i);
  if (temp<=10 && i!=start)  
         //change this to 100
     printf("fare to jetty %d is %d \n",i,temp);
}

/*

int vis[6]={0};
int dis[6]={0};s
for (i=0;i<6;i++)
{
  int temp=shortpath(a,start,i);
     dis[i]=temp;    //change this to 100
     //printf("fare to jety %d is %d \n",i,temp);
}


*/



/*
int vis[6]={0};
prev=start;
dfs(vis,a,start);
printf("total=%d\n",total);

*/
return 0;
}