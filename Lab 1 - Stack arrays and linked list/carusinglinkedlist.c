#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct CAR
{
   char name[20];
   int regnum;

}car;

typedef struct NODE
{ 
  car c;
 struct NODE *next; 


}node;



struct parkinglot
{  
   node *start;
   int id;
   



}stack;




node *create(car newcar)
{
   node *newnode=(node *)malloc(sizeof(node));
   
   newnode->next=NULL;
     strcpy(newnode->c.name,newcar.name);
     newnode->c.regnum=newcar.regnum; 

   return newnode;

}


void insert(car newcar)
{ node *newnode=create(newcar);
   if (stack.start==NULL)
   {
      stack.start=newnode;
   }
  else
  {
   
      newnode->next=stack.start;
      stack.start=newnode;

  }

  stack.id++;

}


void pop()
{
   if (stack.start==NULL)
      printf("underflow\n");
   else
    {
      printf("deleting %d\n",stack.start->c.regnum);
      node *temp=stack.start;
      stack.start=stack.start->next;
      free(temp);
    stack.id--;

    }

  

}

 void display()
{node *temp=stack.start;
 while (temp)
  {
    printf("%d->",temp->c.regnum);
    temp=temp->next; 

   }
    printf("\n");
 
}

void isparked(int id)
{
   node *temp=stack.start;
   int flag=0;
 while (temp)
 {
   if (temp->c.regnum==id)
   {
     flag=1;

     printf("element found\n");
     printf("name:%s",temp->c.name);
    break;

   }
   temp=temp->next;

  }
  if (flag==0)
    printf("element not found\n");

}





void initialise()
{  
    stack.start==NULL;
    stack.id=0;

}

void  Parking_Snapshot()
{ FILE *f;
  f=fopen("lolypop.txt","w");
  int i;
  node *temp=stack.start;
 while (temp)
  { fprintf(f,"name:%s\nregnum:%d\n",temp->c.name,temp->c.regnum);


  }
  
 fclose(f);

}




int main()
{
  initialise();
  car a;
  char name[20];
  int regnum;
  int choice=6;
do
{
  printf("1)enter\n2)exit\n3)search\n4)dispaly\n5)snap\n");
  printf("enter the chopice\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:{printf("enter the name\n");
           scanf("%s",name);
           printf("enter the registration number\n");
           scanf("%d",&regnum);
           a.regnum=regnum;
           strcpy(a.name,name);
           insert(a);
           break;
     
           }      
   case 2:{

            pop();
            break;
           }
    
   case 3:{printf("enter the registration  number of the car you wish to search\n");
         scanf("%d",&regnum);
         isparked(regnum);
      break;



     }
  case 4:{
          display();  
          break; 

         }
  
  case 5:{Parking_Snapshot();
           break;   
      }
  
  default:{printf("incorrect choice\n");
           choice=6;
          }


  }




}while(choice!=6);





}


