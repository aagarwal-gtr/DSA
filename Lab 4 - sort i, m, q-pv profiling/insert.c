#include<stdio.h>

void Isort(int a[],long int n) {
	long int i, j; int temp;
	for (i = 1 ; i <= n - 1; i++) {
	    j = i;
	    while ( j > 0 && a[j] < a[j-1]) {
		    temp   = a[j];
			a[j]   = a[j-1];
	    	a[j-1] = temp;
		    j--;
		}
	}
}
