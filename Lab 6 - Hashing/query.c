#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "htops.h"
//#include "hashtable.h"

int main(int argc, char *argv[]) {
	char finame[20], foname[20], item_code[8];
	int cust_id;
	//strcpy(finame, argv[1]);
	strcpy(finame, "inputHashing.txt");
	//strcpy(foname, argv[2]);
	strcpy(foname, "output.txt");
	//cust_id = atoi(argv[3]);	
	cust_id = 5672;
	//strcpy(item_code, argv[4]);
	strcpy(item_code, "DMOJEVIK");	
	
	Hash_item ht[10];
	ht = populateHashtable(finame);
	FILE *fp; fp = fopen(foname, "w")
	printHT(Hash_item ht, 10, fp);
	fp.close();
	
	/*
	int pos = findEntry(ht, 10, cust_id, item_code);
    	printf("%d\n", pos);
    	int value = purchasedby(ht, 10, 5664);
    	printf("%d\n",value);
  	*/
	return 0;
}
