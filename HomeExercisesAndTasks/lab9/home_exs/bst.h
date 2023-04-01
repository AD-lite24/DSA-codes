#ifndef BST_H
#define BST_H

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} Node;

typedef struct bst
{
    Node *root;
} BST;

BST* new_bst();

Node *new_node(int value);

void insert(BST *bst, int value);

int search(BST *bst, int key);

int height(Node* node);

int find_min(BST *bst);

int find_max(BST *bst);

Node *predecessor(Node *node);

Node *successor(Node *node);

void delete(BST *bst, Node *node);

#endif