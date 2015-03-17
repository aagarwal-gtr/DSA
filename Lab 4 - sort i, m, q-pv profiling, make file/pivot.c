#include<stdio.h>

long int medianOf3(int x[], long int l, long int r) {
    long int m = (l + r) / 2;
    if((x[l]-x[m])*(x[m]-x[r]) >=0)
    	return m;
    else if((x[r]-x[l])*(x[l]-x[m]) >=0)
    	return l;
    else
    	return r;
}

int pivot_f(x, first, last) {
	return first;
}

int pivot_m(x, first, last) {
	return medianOf3(x, first, last);
}
