#include<stdio.h>
#define MAX 1000000

void mergeSort(int arr[], long int low, long int mid, long int high) {
    long int i,m,k,l; int temp[MAX];
    l=low;
    i=low;
    m=mid+1;
    while((l<=mid)&&(m<=high)) {
         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else {
             temp[i]=arr[m];
             m++;
         }
         i++;
    }
    if(l>mid) {
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else {
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }  
    for(k=low;k<=high;k++) {
    	arr[k]=temp[k];
    }
}
void partition(int arr[], long int low, long int high) {
    long int mid;
    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}
