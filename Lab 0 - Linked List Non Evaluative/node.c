#include <stdlib.h>
#include <stdio.h>

typedef struct NODE {
 int data;
 struct NODE *next;
}node;
/*
void push(node *x, int data) {
 while(x->next!=NULL) {
  x = x->next;
 }
 x->next = (node *)malloc(sizeof(node));
 x = x->next;
 x->data = data;
 x->next = NULL;
}
*/
// 2 4 6
void push(node *x, int data) {
 node *new = (node *)malloc(sizeof(node));
 new->data = data;
 node *var = x;
 if(new->data < var->data) {
  new->next = var;
  x = new;
 }
 node *temp = var->next;
 while(temp!=NULL || temp->data < new->data) {
  var = var->next;
  temp = temp->next;
 }
 new->next = var->next;
 var->next = new;
}

void print(node *x) {
 if(x==NULL) {
  return;
 }
 printf("%d ",x->data);
 print(x->next);
}

node* reverse(node *x)
{
    node *temp,*temp1,*var;
    temp=x;
    var=NULL;
    while(temp!=NULL)
    {
         temp1 = var;
         var = temp;
         temp=temp->next;
         var->next = temp1;
    }
    x = var;
    return x;
}
/*
void sort(node *x) {
 
}
*/
int main() {
 node *head;
 head = (node *)malloc(sizeof(node));
 head->next = NULL;
 head->data = 10;
 push(head, 25);
 push(head, 20);
 push(head, 15);
 print(head); printf("\n");
 print(reverse(head)); printf("\n");
 return 0;
}
