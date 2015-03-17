#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size=50;

typedef struct Car {
   char owner[20];
   int regno;
}car;

struct ParkingLot {
  car list[50];
  int top;
}stack;

void init() {
  stack.top = -1;
}

void Enter_ParkingLot(car c) {
  if(stack.top == size-1)
      printf("\nError! Stack Overflow");
  else {
      stack.top++;
      stack.list[stack.top].regno = c.regno;
      strcpy(stack.list[stack.top].owner, c.owner);
  }
}

void Exit_ParkingLot() {
  if(stack.top == -1)
      printf("\nError! Stack Underflow");
  else {
      printf("\nExiting: %d", stack.top);
      stack.top--;
  }
}

void display() {
  if(stack.top == -1)
      printf("\nNothing to display! ");
  int i;
  for(i=0; i<=stack.top; i++)
    printf("Id: %d RegNo: %d Owner: %s\n", i+1, stack.list[i].regno, stack.list[i].owner);
  printf("\n");
}

void Is_Parked(int pid) {
  int i; pid--;
  int flag=0;
  if(pid <= stack.top && pid>=0) {
      printf("\nCar Found at \nRegNo: %d\nOwner: %s", stack.list[pid].regno, stack.list[pid].owner);
      flag=1;
  }
  if(flag==0)
      printf("\nError! Car with given id not found");
}

void Parking_Snapshot(char fname[]) {
  FILE * file;
  file = fopen(fname,"w");
  int i;
  for(i=0; i<=stack.top; i++)
      fprintf(file, "Parking id:%d  Regno:%d    Owner:%s\n", i+1, stack.list[i].regno, stack.list[i].owner); 
}

int main(int argc, char *argv[]) {
  init();
  size = atoi(argv[1]);
  car c;
  int choice, pid; char ans, fname[20];
  do {
     printf("\nMain Menu");
     printf("\n1.Enter Parking Lot \n2.Exit Parking Lot \n3.Is Parked? \n4.Display \n5.Parking Snapshot \n6.Exit");
     printf("\nEnter Your Choice: ");
     scanf("%d", &choice);
     switch (choice) {
     case 1:
          printf("\nEnter car regno: ");  
          scanf("%d", &c.regno);
          printf("\nEnter car owner name: ");
          scanf(" %s", c.owner);
          Enter_ParkingLot(c);
          break;
     case 2:
          Exit_ParkingLot();
          break;
     case 3:
          printf("\nEnter parking id: ");
          scanf("%d", &pid);
          Is_Parked(pid);
          break;
     case 4:
          display();
          break;
     case 5:
          printf("\nEnter filename: ");
          scanf(" %s", fname);
          Parking_Snapshot(fname);
          break;
     case 6:
          exit(0);
     default:
          printf("\nWrong input!");
     }
     printf("\nDo You want To Continue? ");
     scanf(" %c", &ans);
  } while(ans == 'Y' || ans == 'y');
  return 0;
}