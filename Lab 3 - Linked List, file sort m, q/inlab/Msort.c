#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct NODE {
	int data;
	struct NODE *next;
}node;

int size = 0;

void insert(node **head,int data)
{   node *newnode=(node *)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    if (*head==NULL)
    {
        *head=newnode;
    }
    else
    {   node *temp=*head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
      temp->next=newnode;
    }
}

void printList(node *temp, FILE *fp) {
	while(temp) {
		fprintf(fp, "%d\n", temp->data);
		temp = temp->next;
	}
}

void split(node *start,node **start1,node **start2)
{
    int i;
    for (i=0;i<size/2;i++)
    {   insert(start1,start->data);
        start=start->next;
    }
    for (;i<size;i++)
    {
        insert(start2,start->data);
        start=start->next;
    }
}

node *merge(node *start1,node *start2)
{   
    node *start=NULL;
    while (start1!=NULL  && start2!=NULL)
    {  if ((start1->data)<(start2->data))
        {insert(&start,start1->data);
        start1=start1->next;
        }

        else
        {insert(&start,start2->data);
        start2=start2->next;

        }
    }
    while(start1!=NULL)
    {insert(&start,start1->data);
        start1=start1->next;

    }
    while (start2!=NULL)
    {
       insert(&start,start2->data);
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
    *start=merge(start1,start2);
}

int main(int argc, char *argv[]) {
	node *head=NULL;
	char filename[25], fname[25]; int ch;
	strcpy(filename, argv[1]); FILE *fp;
	int choice; char ans;
	do {
	 printf("\nMain Menu");
	 printf("\n1.Read Data from filename entered \n2.Print \n3.M-sort \n4.Exit");
	 printf("\nEnter Your Choice: ");
	 scanf("%d", &choice);
	 switch (choice) {
		 case 1:
		      fp = fopen(filename, "r");
		      do
  		      {
   			fscanf(fp,"%d",&ch);
   			insert(&head,ch); size++;
 		      }while (!feof(fp));
		      break;
		 case 2:
		      printf("\nEnter filename or stdout to print to screen: ");
		      scanf("%s", fname);
		      if(!strcmp(fname, "stdout")) { fp = stdout; printList(head, fp); }
		      else { fp = fopen(fname, "w"); printList(head, fp); fclose(fp); }
		      break;
		 case 3:
		      sort(&head);
		      printf("\nThe merge sorted list follows: \n");
		      fp = stdout;
		      printList(head, fp);
		      break;
		 case 4:
		      exit(0);
		 default:
		      printf("\nWrong input!");
	 }
	 printf("\nDo You want To Continue? ");
	 scanf(" %c", &ans);
	} while(ans == 'Y' || ans == 'y');
	return 0;
}
