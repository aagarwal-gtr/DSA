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
