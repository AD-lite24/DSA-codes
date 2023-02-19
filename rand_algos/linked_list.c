#include <stdlib.h>
#include "linked_list.h"

LIST createNewList(){
    LIST list = malloc(sizeof(struct linked_list));
    list->head = NULL;
    list->count = 0;
    return list;
}

NODE createNewNode(Element value) {
NODE myNode;
myNode = (NODE) malloc(sizeof(struct node)); 
myNode->data=value;
myNode->next=NULL;
return myNode;
}

void insertNodeIntoList(NODE node, LIST list){
    node->next = list->head;
    list->head = node;
}

void removeFirstNode(LIST list){
    NODE first = list->head;
    NODE newFirst = first->next;
    list->head = newFirst;
    free(first);
}