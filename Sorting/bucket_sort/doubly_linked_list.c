#include <stdlib.h>
#include "linked_list.h"
#include "element.h"

Element ftoe(float val){
    Element ele;
    ele.float_value = val;
    return ele;
}

void sortList(LIST list){ //INCOMPLETE

    int n = list->count;
    NODE curr = list->head;
    for (int i = 1; i < n; i++){
        curr = curr->next;
        int j = i - 1;
        NODE temp = curr->prev;
        while (j >= 0 && temp->data.float_value > curr->data.float_value){
            temp = temp->prev;
            j--;
        }
        temp->next = curr;
    }
}
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
    myNode->prev = NULL;
    return myNode;
}

void insertNodeIntoList(NODE node, LIST list){

    if (list->head == NULL){
        list->head = node;
        list->head->prev = malloc(sizeof(struct node)); //dummy pointer before head
        list->head->prev->next = list->head;
        list->head->prev->prev = NULL;
    }
    else{
        NODE dummy = list->head->prev;
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
        list->head->prev = dummy;
    }
    list->count++;
}

void removeFirstNode(LIST list){
    NODE dummy = list->head->prev;
    NODE first = list->head;
    NODE newFirst = first->next;
    list->head = newFirst;
    newFirst->prev = dummy;
    list->count--;
    free(first);
}