#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct NODE {
	int data;
	struct NODE *next;
}node;

void printList(node *temp, FILE *fp) {
	while(temp) {
		fprintf(fp, "%d\n", temp->data);
		temp = temp->next;
	}
}

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

void partition(node *head,node **head1,node **head2)
{
    node *temp=head;
    int pivot=head->data;
    while (temp!=NULL)
    {
       if ((temp->data)<pivot)
        insert(head1,temp->data);
       if ((temp->data)>pivot)
        insert(head2,temp->data);
       temp=temp->next;
    }
}

void quicksort(node **head)
{
   if (*head==NULL)
    return;
   if ((*head)->next==NULL)
    return;
   node *head1=NULL;
   node *head2=NULL;
   partition(*head,&head1,&head2);
   if (head1!=NULL)
       quicksort(&head1);
   if (head2!=NULL)
       quicksort(&head2);
   if (head1==NULL)
        (*head)->next=head2;
   else
   {
       node *temp=head1;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=*head;
        (*head)->next=head2;
        (*head)=head1;
   }
}

int main(int argc, char *argv[]) {
	node *head=NULL;
	char filename[25], fname[25]; int ch;
	strcpy(filename, argv[1]); FILE *fp;
	int choice; char ans;
	do {
	 printf("\nMain Menu");
	 printf("\n1.Read Data from filename entered \n2.Print \n3.Q-sort \n4.Exit");
	 printf("\nEnter Your Choice: ");
	 scanf("%d", &choice);
	 switch (choice) {
		 case 1:
		      fp = fopen(filename, "r");
		      do
  		      {
   			fscanf(fp,"%d",&ch);
   			insert(&head,ch);
 		      }while (!feof(fp));
		      break;
		 case 2:
		      printf("\nEnter filename or stdout to print to screen: ");
		      scanf("%s", fname);
		      if(!strcmp(fname, "stdout")) { fp = stdout; printList(head, fp); }
		      else { fp = fopen(fname, "w"); printList(head, fp); fclose(fp); }
		      break;
		 case 3:
		      quicksort(&head);
		      printf("\nThe quick sorted list follows: \n");
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
