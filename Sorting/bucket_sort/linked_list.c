#include <stdlib.h>
#include "linked_list.h"

LIST createNewList()
{
    LIST list = malloc(sizeof(struct linked_list));
    list->head = NULL;
    list->count = 0;
    return list;
}

NODE createNewNode(Element value)
{
    NODE myNode;
    myNode = (NODE)malloc(sizeof(struct node));
    myNode->data = value;
    myNode->next = NULL;
    return myNode;
}

void insertNodeIntoList(NODE node, LIST list)
{
    if (list->head == NULL){
        list->head = node;
        list->count++;
        return;
    }

    NODE temp = list->head;
    while(temp->next != NULL)
        temp = temp->next;
    
    temp->next = node;
    list->count++;
}

int removeFirstNode(LIST list)
{
    if (list->count == 1){
        NODE temp = list->head;
        list->head = NULL;
        list->count--;
        return temp->data.int_value;
    }

    NODE temp = list->head;
    list->head = temp->next;
    list->count--;
    return temp->data.int_value;

}