typedef struct NODE {
	int cust_id;
	char item_code[8];
	int item_cost;
	struct NODE *next;
}node;

typedef struct item {
	node *Hash_id[5];
}Hash_item;

