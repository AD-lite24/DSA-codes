#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

void removeHalfNodes(Node* root);
int hasSingleChild(Node* left, Node* right);

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

    removeHalfNodes(bst->root);
}
void removeHalfNodes(Node* root)
{

    Node* curr = root; 

    if (curr->left == NULL && curr->right == NULL)
        return;
    
    while(hasSingleChild(curr->left, curr->right))
    {
        // If left has only one right child
        if (curr->left->left == NULL && curr->left->right != NULL)
        {
            curr->left = curr->left->right;
            free(curr->left);
        }

        // If left has only one left child
        else if (curr->left->left != NULL && curr->left->right == NULL)
        {
            curr->left = curr->left->left;
            free(curr->left);
        }

        // If right has only one right child
        else if (curr->right->left == NULL && curr->right->right != NULL)
        {
            curr->right = curr->right->right;
            free(curr->right);
        }

        // If right has only one left child
        else if (curr->right->left != NULL && curr->right->right == NULL)
        {
            curr->right = curr->right->left;
            free(curr->right);
        }
    }    

    removeHalfNodes(curr->left);
    removeHalfNodes(curr->right);
}

int hasSingleChild(Node* left_node, Node* right_node)
{
    // If left has only one right child
    if (left_node->left == NULL && left_node->right != NULL)
        return 1;

    // If left has only one left child
    else if (left_node->left != NULL && left_node->right == NULL)
        return 1;

    // If right has only one right child
    else if (right_node->left == NULL && right_node->right != NULL)
        return 1;

    // If right has only one left child
    else if (right_node->left != NULL && right_node->right == NULL)
        return 1;
    
    return 0;
}
