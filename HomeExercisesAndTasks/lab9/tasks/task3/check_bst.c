#include <stdlib.h>
#include <stdio.h>
#include "bst.h"
#include "stack.h"

int getMin(Node *root);
int getMax(Node *root);

int checkBstRecursive(Node *node)
{
    if (node == NULL)
        return 1;           //base case

    if (node->left != NULL)
        if (getMax(node->left) > node->value)
            return 0;

    if (node->right != NULL)
        if (getMin(node->right) < node->value)
            return 0;
    
    if (!checkBstRecursive(node->left) || !checkBstRecursive(node->right))    //check left and right subtrees
        return 0;

    return 1;
}

int checkBstIterative(Node* node)
{
    if (node == NULL)
        return 1;           //edge case
    
    Stack* stack = newStack();
    Node* root = node;
    Node* prev = NULL;
    while (!isEmpty(stack) || (root != NULL))
    {   
            while(root != NULL)     // traverse left subtree
            {
                push(stack, root);
                root = root->left;
            }

        root = top(stack);
        pop(stack);

        if (prev != NULL && root->value <= prev->value)
            return 0;

        prev = root;
        root = root->right;
    }
    return 1;
}


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

    printf("check bst recursive: %d\n", checkBstRecursive(bst->root));
    printf("check bst iterative: %d", checkBstIterative(bst->root));
}

int getMax(Node *root)
{
    if (root == NULL)
        return INT8_MIN;

    int curr_res = root->value;
    int left_res = getMax(root->left);
    int right_res = getMax(root->right);
    int res;

    if (left_res > curr_res)
        res = left_res;

    else if (right_res > curr_res)
        res = right_res;

    else
        res = curr_res;

    return res;
}

int getMin(Node *root)
{
    if (root == NULL)
        return INT8_MAX;

    int curr_res = root->value;
    int left_res = getMin(root->left);
    int right_res = getMin(root->right);
    int res;

    if (left_res < curr_res)
        res = left_res;

    else if (right_res < curr_res)
        res = right_res;

    else
        res = curr_res;

    return res;
}