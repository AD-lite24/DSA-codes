#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

void removeHalfNodes(Node* root);
int hasSingleChild(Node* left, Node* right);
void traverse_in_order(Node *node);


int main()
{
    BST *bst = new_bst();
    insert(bst, 5);
    insert(bst, 4);
    insert(bst, 1);
    insert(bst, 3);
    insert(bst, 2);
    insert(bst, 9);
    insert(bst, 8);
    insert(bst, 6);
    insert(bst, 10);

    removeHalfNodes(bst->root);
    traverse_in_order(bst->root);
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
            Node* temp = curr->left->right;
            free(curr->left);
            curr->left = temp;
        }

        // If left has only one left child
        else if (curr->left->left != NULL && curr->left->right == NULL)
        {
            Node* temp = curr->left->left;
            free(curr->left);
            curr->left = temp;
        }


        // If right has only one right child
        else if (curr->right->left == NULL && curr->right->right != NULL)
        {
            // curr->right = curr->right->right;
            Node* temp = curr->right->right;
            free(curr->right);
            curr->right = temp;
        }

        // If right has only one left child
        else if (curr->right->left != NULL && curr->right->right == NULL)
        {
            Node* temp = curr->right->left;
            free(curr->right);
            curr->right = temp;
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

void traverse_in_order(Node *node)
{
    if (node == NULL)
        return;

    traverse_in_order(node->left);
    printf("%d ", node->value);
    traverse_in_order(node->right);
}
