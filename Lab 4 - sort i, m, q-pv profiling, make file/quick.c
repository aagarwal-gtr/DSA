#include<stdio.h>

void quickSort(int x[],long int first,long int last){
    long int pivot,j,i; int temp;

     if(first<last){
	pivot = pivot_f(x, first, last);
	//pivot = pivot_m(x, first, last);
        i=first;
        j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                  temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }
         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quickF(x,first,j-1);
         quickF(x,j+1,last);
    }
}
