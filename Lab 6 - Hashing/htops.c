#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htops.h"
#include "hashtable.h"

void initialise(node **start) {
	*start=NULL;
}

void init_Hash_id(node *Hash_id[], int size) {
	int i;
	for(i=0; i<size; i++)
        	initialise(&Hash_id[i]);
}

void init_Hash_item(Hash_item ht[], int size) {
	int i;
	for(i=0; i<size; i++)
		init_Hash_id(ht[i].Hash_id, 5);
}

int prime(int n) {
	return 7; //todo next prime function
}

int hash1(char *key, int size) {
	int i, sum = 0;
	for(i=0; i<=strlen(key); i++)
		sum += key[i];
	sum %= prime(size);
	sum %= size;
	return sum;
}

int hash2(int key, int size) {
	int sum = 0;
	while(key) {
		sum += key%10;
		key /= 10;	
	}
	sum %= size;
	return sum;
}

node *createnode(int id, char *code, int cost) { //chage parameter
	node *newnode = (node *)malloc(sizeof(node));
	newnode->cust_id = id;
    	strcpy(newnode->item_code, code);
    	newnode->item_cost = cost;
    	newnode->next = NULL;
	return newnode;
}

void insert(node **start, int id, char *code, int cost) { //change parameter
	node *newnode = createnode(id, code, cost); //change them
	if(*start == NULL) {
		*start = newnode;
	}
	else {
		newnode->next = *start;
        	*start = newnode;
    	}
}

void insertHashtable(Hash_item ht, int htsize, int cust_id, char *item_code, int cost_item) {
	int key1 = hash1(item_code, htsize);
	int key2 = hash2(cust_id, 5);
	insert(&ht[key1].Hash_id[key2], cust_id, item_code, cost_item);
}

void display(node *start, FILE *fp) {
    	while(start) {
        	fprintf(fp, "%4d %s %3d\n", start->cust_id, start->item_code, start->item_cost);//also print others
        	start = start->next;
    	}
}

void display_Hash_id(node *Hash_id[], int size, FILE *fp) {
    	int i;
    	for(i=0; i<size; i++)
    		display(Hash_id[i], fp);
}

void printHT(Hash_item ht[], int htsize, FILE *fp) {
	int i;
	if(fp!=NULL) {	
		for(i=0; i<size; i++) {
       			display_Hash_id(ht[i].Hash_id, 5, fp);
		}
	}
}

int findEntry(Hash_item ht[], int htsize, int cust_id, char *item_code) {
	int key1 = hash1(item_code, htsize), key2 = hash2(cust_id,5);
	int cost = -1;
    	node *temp = ht[key1].Hash_id[key2];
	while(temp != NULL) {
        	if(temp->cust_id==cust_id && !(strcmp(temp->item_code, item_code))) {
	        	cost = temp->item_cost;
            		break;
	        }
        	temp = temp->next;
   	}
	return cost;
}

int purchasedby(Hash_item ht[], int htsize, int cust_id) {
	int sum = 0, key = hash2(cust_id,5), i;
    	node *temp;
    	for(i=0; i<htsize; i++) {
		temp = ht[i].Hash_id[key];
        	while(temp) {
	        	if(temp->cust_id == cust_id)
                    		sum += temp->item_cost;
            		temp=temp->next;
        	}
    	}
	return sum;
}

Hash_item* populateHashtable(char *filename) {
	FILE *fp;
	Hash_item ht[10];
	init_Hash_item(ht, 10);
	fp = fopen(filename, "r");
	int new_id, new_cost; char new_code[8];
	while(!feof(fp)) {
		fscanf(fp,"%d %s %d ", &new_id, new_code, &new_cost);
 		insertHashtable(ht, 20, new_id, new_code, new_cost);
	 }
	fp.close();
	return ht;
}

