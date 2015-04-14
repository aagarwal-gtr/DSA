#include <stdio.h>
#include <stdlib.h>

void print(int a[], long int n, FILE *f) {
	long int i;
	for(i=0; i<n; i++) {
		fprintf(f, "%d \n", a[i]);
	}
}

int* file_read(char fnam[], long int size) {
	FILE *fp;
	fp = fopen(fnam,"r");
	int *start = malloc(sizeof(int)*size);	
	int a, i=0;
	do
	{       fscanf(fp,"%d",&a);
		start[i++]=a;
	} while (!feof(fp) && i<size);
	fclose(fp);
	return start;
}

void file_write(char fname[], int arr[], long int size) {
	FILE *fp;
	if(!strcmp(fname, "stdout")) { 
		fp = stdout; 
		print(arr, 10, fp);
	}
	else {
		fp = fopen(fname, "w"); 	
		if(fp!=NULL)		
			print(arr, size, fp); 
		else 
			printf("Error writing file");
		fclose(fp);
	}
}

int main(int argc, char *argv[]) {
	long int size = atol(argv[1]);	
	int *a = malloc(size*sizeof(int));	
	a = file_read("input.txt", size);
	Isort(a, size);	
	//partition(a, 0 size-1);
	//quickSort(a, 0, size);
	file_write("output.txt", a, size);
	free(a);
	return 0;
}
