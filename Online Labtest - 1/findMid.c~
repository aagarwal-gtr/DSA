#include "data.h"
#include <stdlib.h>

// write a function called swap here to swap two rows to aid in analysis
void swap(PointList *plist1, PointList *plist2)
{
	PointList *temp;
	temp = plist1;
	plist1 = plist2;
	plist2 = temp;
}

int part(PointList plist, int start, int end, int col)
{
	int x = plist[end][col];
	int i = start-1, j;
	for(j=start; j<=end-1; j++) {
		if(plist[j][col]<=x) {
			i++;
			swap(plist[i], plist[j]);
		}
	}
	swap(plist[i+1], plist[end]);
	return i+1;
}

int randpart(PointList plist, int start, int end, int col)
{	
	int pivot = plist[(start+mid)/2][col];
	swap(plist[pivot], plist[end]);
	return part(plist, start, end, col);
}

extern int findMid(PointList plist, int start, int end, int col)
{
	if(start==end) return start;
	int q = randpart(plist, start, end, col);
	int k = q-start+1;
	if(plist[][col]==plist[k][col])
		return q;
	else if(i<k)
		return findMid(plist, start, end-1, col);
	else
		return findMid(plist, , col);
}
