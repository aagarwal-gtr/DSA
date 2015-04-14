#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 50

typedef struct Car {
 int regno;
 char owner[20];
} car;

typedef struct ParkingLot {
 car* cars[size];
 int id[size];
 int curr_no;
} plot;

void Enter_ParkingLot(plot p, int regno, char owner[], int sizee) {
 int x=p.curr_no;
 if(x < sizee) {
	p.cars[x+1]->regno = regno;
	strcpy(p.cars[x+1]->owner, owner);
	p.curr_no++;
        p.id[x+1] = x+1;
 }
 else {
 	printf("Error! Stack full!");
 }
}

void Exit_ParkingLot(plot p, int sizee) {
 int x=p.curr_no;
 if(p.curr_no > 0) {
 	free(p.cars[x+1]);
	p.curr_no--;
 }
 else {
 	printf("Error! Stack empty!");
 }
}

car* Is_Parked(plot p, int pid) {
 int x=p.curr_no, i;
 for(i=1; i<=x; i++) {
 	if(p.id[i] == pid)
         return p.cars[pid];
 }
 return NULL;
}

void Parking_Snapshot(char* filename, plot p) {
 FILE * file;
 file = fopen(filename,"w");
 int x=p.curr_no, i;
 for(i=x; i>=1; i--)
  fprintf(file, "Parking id:%d  Regno:%d    Owner_Name:%s\n", p.id[i], p.cars[i]->regno, p.cars[i]->owner); 	
}

int main(int argc, char *argv[]) {
 int sizee = atoi(argv[1]);
 int i; int regno; char owner[20];
 plot p; p.curr_no=0;
 p.cars = (car *)malloc(sizee*sizeof(car));
 int choice; char ans;
 do {
      printf("\nMain Menu");
      printf("\n1.Enter Parking Lot \n2.Exit Parking Lot \n3.Is Parked? \n4.Parking Snapshot \n5.Exit");
      printf("\nEnter Your Choice");
      scanf("%d", &choice);
      switch (choice) {
      case 1:
         printf("\nEnter car regno: "); 	
	 scanf("%d", &regno);
	 printf("\nEnter car owner name: ");
	 scanf(" %s", owner);
         Enter_ParkingLot(p, regno, owner, sizee);
      case 2:
         Exit_ParkingLot(p, sizee);
         break;
      case 3:
         printf("\nEnter parking id: ");
	 int pid;
	 scanf("%d", &pid);
	 car* c; c=Is_Parked(p, pid);
	 if(c!=NULL) {
	  printf("Found at \nParking id: %d \nRegno: %d \nOwner Name: %s", pid, c->regno, c->owner);
	 }
	 else { printf("Error! Given parking id not found!"); }
         break;
      case 4:
	 printf("\nEnter filename: ");
         char fname[20];
	 scanf(" %s", fname);
         Parking_Snapshot(fname, p);
      case 5:
         exit(0);
      }
      printf("\nDo You want To Continue?");
      ans = getche();
   } while (ans == 'Y' || ans == 'y');
 return 0;
}
