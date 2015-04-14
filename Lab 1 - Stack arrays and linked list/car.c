#include<stdio.h>
#include<string.h>
typedef struct CAR
{
   char name[20];
   int regnum;

}car;


struct parkinglot
{ 
  car list[10];
  int top;

}stack;



void initialize()
{stack.top=-1;
}

void Enter_ParkingLot(car newcar)
{
  if (stack.top==9)
   printf("\noverflow\n");

  else
   {stack.top++;
    stack.list[stack.top].regnum=newcar.regnum;
    strcpy(stack.list[stack.top].name,newcar.name);


   }




}

void  Exit_ParkingLot()
{

   if (stack.top==-1)
     printf("\nunderflow\n");
   else
     {
       printf("\nexiting %d\n",stack.top);
       stack.top--;


     }

}
void display()
{ if (stack.top==-1)
    printf("nothing to display\n");
  int i;
  for (i=0;i<=stack.top;i++)
  {
    printf("%d ",stack.list[i].regnum);

  }

  printf("\n");

}


void Is_Parked(int id)
{
  int i;
  int flag=0;
  for (i=0;i<=stack.top;i++)
  {  
    if (stack.list[i].regnum==id)
      {printf("\ncar found\n");
       printf("regnum:%d\n",stack.list[i].regnum);
       printf("name:%s\n ",stack.list[i].name);
       flag=1;
       break; 


      }

  
  } 

   if (flag==0)
     printf("car not found\n");
}
void  Parking_Snapshot()
{ FILE *f;
  f=fopen("lol.txt","w");
  int i;
 for (i=0;i<=stack.top;i++)
  { fprintf(f,"name:%s\nregnum:%d\n",stack.list[i].name,stack.list[i].regnum);


  }
  
 fclose(f);

}
int main()
{
  initialize();
  car a;
  char name[20];
  int regnum;
  int choice=6;
do
{
  printf("1)enter\n2)exit\n3)search\n4)dispaly\n5)snap\n");
  printf("enter the choice\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:{printf("enter the name\n");
           scanf("%s",name);
           printf("enter the registration number\n");
           scanf("%d",&regnum);
           a.regnum=regnum;
           strcpy(a.name,name);
           Enter_ParkingLot(a);
           break;
     
           }      
   case 2:{

            Exit_ParkingLot();
            break;
           }
    
   case 3:{printf("enter the registration number of the car you wish to search\n");
           scanf("%d",&regnum);
            Is_Parked(regnum);
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
