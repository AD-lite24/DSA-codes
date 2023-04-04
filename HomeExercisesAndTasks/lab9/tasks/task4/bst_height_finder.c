#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

int get_tree_height(Node* root);

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

    printf("Height of tree is %d", get_tree_height(bst->root));
}

int get_tree_height(Node *root)
{
    if (root == NULL)
        return 0;

    else
    {
        int left = get_tree_height(root->left);
        int right = get_tree_height(root->right);
        return (left > right) ? left + 1 : right + 1;
    }

}
