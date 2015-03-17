#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct NODE {
	int data;
	struct NODE *next;
}node;

int size = 0;

node* readData(char filename[]) {
	node *temp = malloc(sizeof(node));
	node *head = malloc(sizeof(node));
	FILE *fp; int ch;
	fp = fopen(filename, "r");
	fscanf(fp,"%d",&ch);
	temp->data = ch;
	temp->next = malloc(sizeof(node));
	head = temp;
	temp = temp->next; size++;
	while(ch = fgetc(fp) != EOF) {
		fscanf(fp, "%d", &ch);
		temp->data = ch;
		temp->next = malloc(sizeof(node));
		temp = temp->next;
		size++;
	}
	temp->next = NULL;
	fclose(fp);
	return head;
}

void printList(node *temp, FILE *fp) {
	while(temp->next != NULL) {
		fprintf(fp, "%d\n", temp->data);
		temp = temp->next;
	}
}

void sortM(node *head) {

}

void sortQ(node *head) {

}

int main(int argc, char *argv[]) {
	node *head = malloc(sizeof(node));
	char filename[25], fname[25];
	strcpy(filename, argv[1]); FILE *fp;
	int choice; char ans;
	do {
	 printf("\nMain Menu");
	 printf("\n1.Read Data from filename entered \n2.Print \n3.M-sort \n4.Q-sort \n5.Exit");
	 printf("\nEnter Your Choice: ");
	 scanf("%d", &choice);
	 switch (choice) {
		 case 1:
		      head = readData(filename);
		      break;
		 case 2:
		  	  printf("\nEnter filename or stdout to print to screen: ");
		  	  scanf("%s", fname);
			  if(!strcmp(fname, "stdout")) { fp = stdout; printList(head, fp);}
			  else {fp = fopen(fname, "w"); printList(head, fp); fclose(fp);}
		      break;
		 case 3:
		      //head = sortM(head);
		      //printf("\nThe merge sorted list follows: "); 
		 	  //fp = stdout;
		      //printList(head, fp);
		      break;
		 case 4:
		      //sortQ(head);
		      //printf("\nThe quick sorted list follows: ");
		      //fp = stdout;
		      //printList(head, fp);
		      break;
		 case 5:
		      exit(0);
		 default:
		      printf("\nWrong input!");
	 }
	 printf("\nDo You want To Continue? ");
	 scanf(" %c", &ans);
	} while(ans == 'Y' || ans == 'y');
	return 0;
}