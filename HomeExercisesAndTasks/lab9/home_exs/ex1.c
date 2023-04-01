#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

void printAtCurrLevel(Node* root, int level)
{
    if (root == NULL)
        return;

    if (level == 1)
        printf(" %d ", root->value);
    
    else
    {
        printAtCurrLevel(root->left, level - 1);
        printAtCurrLevel(root->right, level - 1);
    }
    
}

void printLevels(Node* node)
{
    int h = height(node);

    for (int i = 0; i <= h; i++)
        printAtCurrLevel(node, i);
}

void levelOrderTraversal(Node* node)
{
    printLevels(node);
}

int main()
{
    BST *bst = new_bst();
    insert(bst, 6);
    insert(bst, 5);
    insert(bst, 2);
    insert(bst, 5);
    insert(bst, 7);
    insert(bst, 8);

    printf("Traversing level order \n");
    levelOrderTraversal(bst->root);

    return 0;
}