#include <stdlib.h>
#include <stdio.h>
#include "bst.h"
#define NUM_ENTRIES 10         //Set number of entries according to csv  

BST* constructBST(Person* array);
Node* LCA(Node* root, int id1, int id2);
int isChild(Node* node);

int main()
{
    FILE* fp = fopen("dat10.csv", "r");
    Person* array = calloc(NUM_ENTRIES, sizeof(Person));


    for(int i = 0; !feof(fp); i++)
        fscanf(fp, "%d,%[^,],%d,%d,%d\n", &(array[i].id), array[i].name, &(array[i].age), &(array[i].height), &(array[i].weight));

    BST* bst = constructBST(array);
    Node* ancestor = LCA(bst->root, 8, 9);      //LCA between ID1 and ID2

}

BST* constructBST(Person *array)
{
    BST* bst = new_bst();
    for (int i = 0; i < NUM_ENTRIES; i++)
        insert(bst, array[i]);
    return bst;
}

Node* LCA(Node* root, int id1, int id2)
{
    if (!root)
        return NULL;

    else if (root->person.id == id1 || root->person.id == id2)
        return root;

    Node* left = LCA(root->left, id1, id2);
    Node* right = LCA(root->right, id1, id2);

    if (!left)
        return right;
    else if (!right)
        return left;
    else
        return root;    
    
}

