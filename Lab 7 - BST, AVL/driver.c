#include "bst.h"
#include "bstops.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    node *root;
    node *tmp;
    
    root = NULL;
    
    insert(&root, 9);
    insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 2);

    printf("Pre Order Display\n");
    print_preorder(root);

    printf("In Order Display\n");
    print_inorder(root);

    printf("Post Order Display\n");
    print_postorder(root);

    tmp = search(&root, 4);
    if(tmp) {
        printf("Searched node = %d\n", tmp->data);
    }
    else {
        printf("Data Not found in tree.\n");
    }

    deltree(root);

    //todo: Perform comparative evaluation balanced and unbalanced BST
    //todo: Use given inorder succesor for inorder printing, init inorder successors
    return 0;
}
