#ifndef BST_H
#define BST_H

typedef struct person
{
    int id;
    char name[20];
    int age;
    int height;
    int weight;
} Person;

typedef struct node
{
    Person person;
    struct node *left;
    struct node *right;
} Node;

typedef struct bst
{
    Node *root;
} BST;

BST* new_bst();

Node *new_node(Person person);

void insert(BST *bst, Person person);

int search(BST *bst, int height);

Person find_min(BST *bst);

Person find_max(BST *bst);

Node *predecessor(Node *node);

void del(BST* bst, Node* node);

Node *successor(Node *node);


#endif