#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "trie.h"
#include "trieop.h"

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
	trie_node_t *pCrawl;
	pTrie->count++;
	pCrawl = pTrie->root;
	for(level=0; level<length; level++) {
		
		index = chartoind(key[level]);
		
		if(!pCrawl->children[index]) {
			pCrawl->children[index] = getNode();
		} 

		pCrawl = pCrawl->children[index];
	}
	// mark last node as leaf
    	pCrawl->value = pTrie->count;
}
