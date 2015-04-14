#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct trie_node trie_node_t;

struct trie_node {
	int value;
	trie_node_t *children[26];
};

typedef struct trie trie_t;

struct trie {
	trie_node_t *root;
	int count;
};

int chartoind(char c)
{
	return ((int)c - (int)'a');
}

trie_node_t *getNode()
{
	trie_node_t *pNode = NULL;
	pNode = (trie_node_t *)malloc(sizeof(trie_node_t)); 
	if(pNode) {
		int i;
		pNode->value = 0;
		for(i=0; i<26; i++) {
			pNode->children[i] = NULL;
		}
	}
	return pNode;
}

void initialize(trie_t *pTrie)
{
	pTrie->root = getNode();
	pTrie->count = 0;
}

void insert(trie_t *pTrie, char key[])
{
	int level;
	int length = strlen(key);
	int index;
	trie_node_t *ptr;
	pTrie->count++;
	ptr = pTrie->root;
	for(level=0; level<length; level++) {
		
		index = chartoind(key[level]);
		
		if(!ptr->children[index]) {
			ptr->children[index] = getNode();
		} 

		ptr = ptr->children[index];
	}
	// mark last node as leaf
    	ptr->value = pTrie->count;
}

int search(trie_t *pTrie, char key[], FILE *fp)
{
	int level;
	int length = strlen(key);
	int index;
	trie_node_t *ptr;

	ptr = pTrie->root;
 
	for(level=0; level<length; level++) {

		index = chartoind(key[level]);
 
		if(!ptr->children[index]) {
			return 0;
		} 
		ptr = ptr->children[index];
		fprintf(fp, "%s %d\n", key, index);
	}	
}

int main()
{
	FILE *fpr;
	FILE *fpw;

	fpr = fopen("some.txt", "r");
	fpw = fopen("someother.txt", "w");

	char c;
	while(!feof(fpr)) {
		fscanf(fpr, "%c", &c);
		if(c>='A' && c<='Z')
			fprintf(fpw, "%c", c-'A'+'a');
		else if((c>='a' && c<='z') || (c==' '))
			fprintf(fpw, "%c", c);
	}

	fclose(fpr);	
	fclose(fpw);

	FILE *fp;
	fp = fopen("someother.txt", "r");

	trie_t trie;
	initialize(&trie);

	char key[100];
	while(!feof(fp)) {
		fscanf(fp, "%s", key);
		insert(&trie, key);	
	}

	fclose(fp);

	FILE *fp1;
	
	fp1 = fopen("index.txt", "w");
	search(&trie, "the", fp1);
	search(&trie, "dasdsda", fp1);

	fclose(fp);

	return 0;
}
