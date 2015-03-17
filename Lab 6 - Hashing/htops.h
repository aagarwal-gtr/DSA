#include "hashtable.h"

Hash_item* populateHashtable(char *filename); //done
void insertHashtable(Hash_item ht, int htsize, int cust_id, char *item_code, int cost_item); //done
int findEntry(Hash_item ht[], int htsize, int cust_id, char *item_code); //done
int purchasedby(Hash_item ht[], int htsize, int cust_id); //done
int hash1(char *key, int size); //done
int hash2(int key, int size); //done
int prime(int n); //done
void display(node *start, FILE *fp); //extra
void display_Hash_id(node *Hash_id[], int size, FILE *fp); //extra
void printHT(Hash_item ht[], int htsize, FILE *fp); //extra
node *createnode(int id, char *code, int cost); //extra
void insert(node **start, int id, char *code, int cost); //extra
void initialise(node **start); //extra
void init_Hash_item(Hash_item ht[], int size); //extra
void init_Hash_id(node *Hash_id[], int size); //extra

