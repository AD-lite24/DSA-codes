#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct node* NODE;
typedef struct linked_list* LIST;

int checkCycleUsingFastPointer(LIST list){
    NODE temp_s = list->head;
    NODE temp_f = list->head;

    while (temp_s != NULL && temp_f != NULL){
        
        temp_s = temp_s->next;
        temp_f = (temp_f->next)->next;

        if (temp_f == temp_s){
            return 1;
        }   
    }
    return 0;
}

int main(){
    
    LIST list = (LIST)malloc(sizeof(struct linked_list));

    list->head = NULL;
    list->size = 0;

    addEleToTheEnd(1, list);
    addEleToTheEnd(2, list);
    addEleToTheEnd(3, list);
    addEleToTheEnd(4, list);

    int val = checkCycleUsingFastPointer(list);

    printf("%d\n", val);

    NODE temp = list->head;
    NODE last = (NODE)malloc(sizeof(struct node));
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = last;
    last->next = list->head->next;
    last->ele = 100;
    list->size++;

    val = checkCycleUsingFastPointer(list);

    printf("%d\n", val);
}