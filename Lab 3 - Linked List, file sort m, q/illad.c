#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct NODE
{
    int item;
    struct NODE *next;
}node;



void insert(node **start,int item)
{   node *newnode=(node *)malloc(sizeof(node));
    newnode->item=item;
    newnode->next=NULL;
    if (*start==NULL)
    {
        *start=newnode;
    }
    else
    {   node *temp=*start;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
      temp->next=newnode;



    }


}

void print(node *start)
{
    while (start)
    {  printf("%d ",start->item);
        start=start->next;
    }
    printf("\n");

}


int nodecount(node *start)
{
    int count=0;
    while (start!=NULL)
    {   count++;
        start=start->next;
    }
    return count;
}

void split(node *start,node **start1,node **start2)
{
    int count=nodecount(start);

    int i;
    for (i=0;i<count/2;i++)
    {   insert(start1,start->item);
        start=start->next;
    }
    for (;i<count;i++)
    {
        insert(start2,start->item);
        start=start->next;
    }





}

node *merge(node *start1,node *start2)
{node *start=NULL;
    while (start1!=NULL  && start2!=NULL)
    {  if ((start1->item)<(start2->item))
        {insert(&start,start1->item);
        start1=start1->next;
        }

        else
        {insert(&start,start2->item);
        start2=start2->next;

        }
    }
    while(start1!=NULL)
    {insert(&start,start1->item);
        start1=start1->next;

    }
    while (start2!=NULL)
    {
       insert(&start,start2->item);
        start2=start2->next;
    }


    return start;
}

void sort(node **start)
{
    if ((*start)==NULL)
        return;
    if ((*start)->next==NULL)
        return;
    node *start1=NULL;
    node *start2=NULL;
    split(*start,&start1,&start2);
    sort(&start1);
    sort(&start2);
    *start=merge(start1,start2);                 //test if this works




}

node *partition(node *start,node **start1,node **start2)
{
    node *temp=start;

    int pivot=start->item;
    while (temp!=NULL)
    {
       if ((temp->item)<pivot)
        insert(start1,temp->item);
       if ((temp->item)>pivot)
        insert(start2,temp->item);
       temp=temp->next;



    }



}
void quicksort(node **start)
{
   if (*start==NULL)
    return;
   if ((*start)->next==NULL)
    return;
   node *start1=NULL;
   node *start2=NULL;
   partition(*start,&start1,&start2);
   if (start1!=NULL)
       quicksort(&start1);
   if (start2!=NULL)
       quicksort(&start2);
   if (start1==NULL)
        (*start)->next=start2;
   else
   {
       node *temp=start1;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=*start;
        (*start)->next=start2;
        (*start)=start1;


   }

}



int main()
{   FILE *fp=fopen("lol.txt","r");
    int a;

    node *start=NULL;


   do
   {
       fscanf(fp,"%d",&a);
       insert(&start,a);
   }while (!feof(fp));


    /*insert(&start,3);
    insert(&start,1);
    insert(&start,4);
    insert(&start,3);
    insert(&start,2);
    */
    //sort(&start);
    fclose(fp);
    quicksort(&start);    //redundancy removed
    print(start);
    return 0;
}
