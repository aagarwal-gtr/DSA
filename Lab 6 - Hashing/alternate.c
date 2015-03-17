#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct NODE
{
    int cust_id;
    char item_code[20];
    int item_cost;


    struct NODE *next;
}node;

void initialise(node **start)
{
    *start=NULL;
}

node *createnode(int id,char *code,int cost)   //chage parameter
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->cust_id=id;
    strcpy(newnode->item_code,code);
    newnode->item_cost=cost;
    newnode->next=NULL;

    return newnode;
}

void insert(node **start,int id,char *code,int cost) //change parameter
{node *newnode=createnode(id,code,cost); //change them
    if (*start==NULL)
    {
        *start=newnode;
    }
    else
    {
        newnode->next=*start;
        *start=newnode;
    }
}
void display(node *start)
{
    while (start)
    {
        printf("%d %s %d->",start->cust_id,start->item_code,start->item_cost);//also print others
        start=start->next;

    }
    printf("\n");
}


void display1(node *start, FILE *fp)
{
    while (start)
    {
        fprintf(fp, "%4d %s %3d\n",start->cust_id,start->item_code,start->item_cost);//also print others
        start=start->next;

    }

}


int hash1(char *key, int size)
{
    int value=0;
    int len=strlen(key);
    int i;
    for (i=0;i<len;i++)
        value+=key[i];
    return value%size;
}
int hash2(int key, int size)
{
    int sum=0;
    while (key!=0)
    {
        sum+=(key%10);
        key/=10;
    }
    return (sum)%size;
}

void init_hash_id(node *hash_id[],int size)
{
     int i;
    for (i=0;i<size;i++)
    {
        initialise(&hash_id[i]);
    }

}
/*
void insert_hash_id(node *hash_id[],int size,int id,char *code,int cost)
{
    int key=hash2(id,size);
    insert(&hash_id[key],id,code,cost);

}
*/
void display_hash_id(node *hash_id[],int size, FILE *fp)
{
    int i;
    for (i=0;i<size;i++)
    {

        display1(hash_id[i], fp);

    }


}

typedef struct
{

    node *hash_id[5];


}hash_item;

void init_hash_item(hash_item h[],int size)
{
    int i;
    for (i=0;i<size;i++)
    {
        init_hash_id(h[i].hash_id,5);
    }
}

void insert_hash_item(hash_item h[],int size,int id,char *code,int cost)
{
    int key=hash1(code,size);


    int key1=hash2(id,5);
    insert(&h[key].hash_id[key1],id,code,cost);

}




int findEntry(hash_item h[], int size, int cust_id, char *item_code)
{
    int key1=hash1(item_code,size);
    int key2=hash2(cust_id,5);
    //printf("%d %d\n",hash1(item_code,10),hash2(cust_id,5));

    int cost=-1;
    node *temp=h[key1].hash_id[key2];
    while (temp!=NULL)
    {
        if (temp->cust_id==cust_id &&(strcmp(temp->item_code,item_code)==0))
        {
            cost=temp->item_cost;
            break;
        }
        temp=temp->next;
    }
    //display(h[key1].hash_id[key2]);

   return cost;

}


int item_purchased(hash_item h[],int size,int id)
{
    int sum=0;
    int key=hash2(id,5);
    int i;
    node *temp;
    for(i=0;i<size;i++)
    {
        temp=h[i].hash_id[key];
        while (temp)
        {
            if (temp->cust_id==id)
            {
                sum+=temp->item_cost;
            }
            temp=temp->next;
        }
    }

    return sum;
}

void output(hash_item h[],int size)
{
   int i;
   FILE *fp; fp=fopen("output1.txt", "w");
   for (i=0;i<size;i++)
   {
       display_hash_id(h[i].hash_id,5, fp);
   }
}

int main()
{

    hash_item h[10];
    init_hash_item(h,10);

    FILE *fp;
    int id;
    int cost;
    char code[9];
    fp=fopen("inputHashing.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d %s %d ",&id,code,&cost);
        insert_hash_item(h,10,id,code,cost);

    }
    int pos=findEntry(h,10,5672,"DMOJEVIK");
    printf("%d\n",pos);
    int value=item_purchased(h,10,5664);
    printf("%d\n",value);
    
   printf("\n\n\n");
  output(h,10);

    return 0;
}
