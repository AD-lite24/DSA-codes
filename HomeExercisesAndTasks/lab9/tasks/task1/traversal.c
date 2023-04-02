#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

void traverse_in_order(Node* node)
{
    if (node == NULL)
        return;
    
    traverse_in_order(node->left);
    printf("%d ", node->value);
    traverse_in_order(node->right);
}

void traverse_pre_order(Node* node)
{
    if (node == NULL)
        return;

    printf(" %d ", node->value);
    traverse_pre_order(node->left);
    traverse_pre_order(node->right);
}

void traverse_post_order(Node* node)
{
    if (node == NULL)
        return;

    traverse_post_order(node->left);
    traverse_post_order(node->right);
    printf(" %d ", node->value);
}

// Driver program to test the above functions (feel free to play around with this)
int main()
{
    BST *bst = new_bst();
    insert(bst, 2);
    insert(bst, 1);
    insert(bst, 3);
    insert(bst, 4);
    insert(bst, 5);
    insert(bst, 6);
    insert(bst, 7);
    insert(bst, 8);

    printf("Traversing in order \n");
    traverse_in_order(bst->root);
    printf("\n");

    printf("Traversing pre order \n");
    traverse_pre_order(bst->root);
    printf("\n");

    printf("Traversing post order \n");
    traverse_post_order(bst->root);
    printf("\n");

    return 0;
}