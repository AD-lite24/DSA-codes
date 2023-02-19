#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "element.h"

//Linked list files not yet configured

typedef struct node* NODE;
typedef struct linked_list* LIST;

Element itoe (int i)
{
    Element e;
    e.int_value = i;
    e.float_value = 0;
    return e;
}

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

    
    insertNodeAtEnd(createNewNode(itoe(1)), list);
    insertNodeAtEnd(createNewNode(itoe(2)), list);
    insertNodeAtEnd(createNewNode(itoe(3)), list);
    insertNodeAtEnd(createNewNode(itoe(4)), list);


    int val = checkCycleUsingFastPointer(list);

    printf("%d\n", val);

    NODE temp = list->head;
    NODE last = (NODE)malloc(sizeof(struct node));
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = last;
    last->next = list->head->next;
    last->data = itoe(100);


    val = checkCycleUsingFastPointer(list);

    printf("%d\n", val);
}