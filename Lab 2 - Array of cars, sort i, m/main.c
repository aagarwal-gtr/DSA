#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ParkingLot.h"

int size=50;
int num=0;

Plot p;

void Enter_ParkingLot(Car c) {
    num++;
    p.list[num] = c;
}

void sortCarsI() {
	
    Car temp; int i, j, temp1;
	
    for(i=2; i<=num; i++) {
	temp = p.list[i];
        temp1 = p.pid[i];
	j = i-1;
	while(temp.regno<p.list[j].regno && j>=1) {
		p.list[j+1] = p.list[j];
                p.pid[j+1] = p.pid[j];
		j--;
	}
	p.list[j+1] = temp;
        p.pid[j+1] = temp1;
    }
}

void merge(int min, int mid, int max) {
	
    Car temp[50];
    int i, j, k, m, temp1[50]; 
    j = min;
    m = mid+1;
    
    for(i=min; j<=mid && m<=max; i++) {
    	if(p.list[j].regno <= p.list[m].regno) {
    		temp[i] = p.list[j];
		temp1[i] = p.pid[j];
                j++;
        }
        else {
                temp[i] = p.list[m];
		temp1[i] = p.pid[m];
                m++;
        }
    }
    
    if(j>mid) {
    	for(k=m; k<=max; k++) {
    		temp[i] = p.list[k];
		temp1[i] = p.pid[k];
                i++;
        }
    }
    
    else {
    	for(k=j; k<=mid; k++) {
    		temp[i] = p.list[k];
		temp1[i] = p.pid[k];
                i++;
        }
    }
    
    for(k=min; k<=max; k++) {
    	p.list[k] = temp[k];
	p.pid[k] = temp1[k];
    }
}

void sortCarsM(int min, int max) {
    
    int mid;
    
    if(min<max) {
    	mid = (min+max)/2;
        sortCarsM(min, mid);
        sortCarsM(mid+1, max);
        merge(min, mid, max);
    }
}

void printArr() {

   printf("\nParked cars are: ");
   
   int i;
   for(i=1; i<=num; i++)
        printf("\nOwner: %15s  RegNo: %10d  Pid: %10d", p.list[i].owner, p.list[i].regno, p.pid[i]);
}

void printCurrentlyParked(int ch) {
	
   printf("\nParked cars in ascending order of Registration Number are: ");
	
   switch (ch) {
   case 1:
        sortCarsI();
	break;
   default:
	sortCarsM(1, num);
   }

   int i;
   for(i=1; i<=num; i++)
	printf("\nOwner: %15s  RegNo: %10d  Pid: %10d", p.list[i].owner, p.list[i].regno, p.pid[i]);
}

int main(int argc, char *argv[]) {
  size = atoi(argv[1]);
  Car c;
  int choice; char ans;
  do {
     printf("\nMain Menu");
     printf("\n1.Enter Parking Lot \n2.Print \n3.Print using I-sort \n4.Print using M-sort \n5.Exit");
     printf("\nEnter Your Choice: ");
     scanf("%d", &choice);
     switch (choice) {
     case 1:
          if(num < size) {
	      printf("\nEnter car regno: ");  
	      scanf("%d", &c.regno);
              printf("\nEnter car owner name: ");
	      scanf(" %s", c.owner);
              p.pid[num+1] = num+1;
              Enter_ParkingLot(c);
	  }
	  else {
	      printf("Error! Overflow");
	  }
          break;
     case 2:
	  printArr();
          break;
     case 3:
          printCurrentlyParked(1);
          break;
     case 4:
          printCurrentlyParked(2);
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
