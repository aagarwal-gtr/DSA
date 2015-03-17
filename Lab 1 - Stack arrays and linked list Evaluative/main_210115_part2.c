//todo: pid not same when random car exiting

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
}s1, s2;

void init() {
  s1.top = -1;
  s2.top = -1;
}

void Enter_ParkingLot(car c) {
  if(s1.top == size-1)
      printf("\nError! s1 Overflow");
  else {
      s1.top++;
      s1.list[s1.top].regno = c.regno;
      strcpy(s1.list[s1.top].owner, c.owner);
  }
}

void Exit_ParkingLot(int pid) {
  pid--; int i, count = 0;
  if(s1.top == -1)
      printf("\nError! s1 Underflow");
  else {
      for(i=s1.top; i>pid; i--) {
        s2.top++;
        s2.list[s2.top].regno = s1.list[i].regno;
        strcpy(s2.list[s2.top].owner, s1.list[i].owner);
        count++;
      }
      s1.top -= count;
      printf("\nExiting: Id: %d RegNo: %d Owner: %s", s1.top+1, s1.list[s1.top].regno, s1.list[s1.top].owner);
      s1.top--;
      for(i=s2.top; i>=0; i--) {
        s1.top++;
        s1.list[s1.top].regno = s2.list[i].regno;
        strcpy(s1.list[s1.top].owner, s2.list[i].owner);
      }
  }
}

void display() {
  if(s1.top == -1)
      printf("\nNothing to display! ");
  int i;
  for(i=0; i<=s1.top; i++)
    printf("Id: %d RegNo: %d Owner: %s\n", i+1, s1.list[i].regno, s1.list[i].owner);
  printf("\n");
}

void Is_Parked(int pid) {
  int i; pid--;
  int flag=0;
  if(pid <= s1.top && pid>=0) {
      printf("\nCar Found at \nRegNo: %d\nOwner: %s", s1.list[pid].regno, s1.list[pid].owner);
      flag=1;
  }
  if(flag==0)
      printf("\nError! Car with given id not found");
}

void Parking_Snapshot(char fname[]) {
  FILE * file;
  file = fopen(fname, "w");
  int i;
  for(i=0; i<=s1.top; i++)
      fprintf(file, "Parking id:%d  Regno:%d    Owner:%s\n", i+1, s1.list[i].regno, s1.list[i].owner); 
}

int main(int argc, char *argv[]) {
  init();
  size = atoi(argv[1]);
  car c;
  int choice, x; char fname[20];
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
          printf("\nEnter car regno: ");  
          scanf("%d", &x);
          Exit_ParkingLot(x);
          break;
     case 3:
          printf("\nEnter parking id: ");
          scanf("%d", &x);
          Is_Parked(x);
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
  } while(1);
  return 0;
}