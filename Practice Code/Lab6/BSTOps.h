BST createEmptyBST();
node insertInBST(node tree, book newb);
BST insertBST(BST bt, book b); 
node createNode(book b);
void bstPrint(BST bt);
void treePrint(node p);
book findMax(node p, book b);
book findMaxPrice(BST bt);
book findMinPrice(BST bt);
int getHeight(BST bt);
book findLatestBook(BST bt);
book findOldestBook(BST bt);
BST reOrderBST(BST bt);
