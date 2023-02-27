#include "linkedlist.h"
#include <stdio.h>

static node *create_node_for_list(process p);
// Check header files for documentation/ function description
process_linked_list *create_empty_process_linked_list() {
    process_linked_list* p = malloc(sizeof(process_linked_list));
    p->head = NULL;
    p->size = 0;

    return p;
}

bool add_first_to_linked_list(process_linked_list *list, process p) {
    return add_at_index_linked_list(list, 0, p);
}

bool add_last_to_linked_list(process_linked_list *list, process p) {
    return add_at_index_linked_list(list, list->size, p);
}

bool add_at_index_linked_list(process_linked_list *list, size_t index, process p) {
   if (index == 0){ //add at beginning
        node* temp = list->head;
        node* new = create_node_for_list(p);
        list->head = new;
        new->previous = NULL;
        new->next = temp;
        list->size++;
        return true;
   }

   else if (index > list->size) return false; //not possible to add

   else if (index == list->size){
        node* new = create_node_for_list(p);
        node* temp = list->head;

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = new;
        new->previous = temp;
        list->size++;
        return true;
   }

   else {
        
        node* new = create_node_for_list(p);
        node* temp = list->head;
        for (int i = 0; i < index; i++){
            temp = temp->next;
        } 
        node* prev = temp->previous;
        prev->next = new;
        new->previous = prev;
        new->next = temp;
        temp->previous = new;
        list->size++;
        return true;
   }

}

bool remove_first_linked_list(process_linked_list *list, process *p) {
    if (list->size == 0) {
        return false;
    }

    else if (list->size == 1){
        node* temp = list->head;
        p = temp->process;
        free(temp);
        list->size--;
        return true;
    }
    else{
        node* temp = list->head;
        p = temp->process;
        list->head = temp->next;
        list->head->previous = NULL;
        free(temp);
        list->size--;
        return true;
    }
}

bool remove_last_linked_list(process_linked_list *list, process *p) {
    if (list->size == 0) {
        return false;
    }

    else if (list->size == 1){
        node* temp = list->head;
        p = temp->process;
        free(temp);
        list->size--;
        return true;
    }

    else{
        node* temp = list->head;
        while (temp->next != NULL){
            temp = temp->next;
        }

        node* prev = temp->previous;
        prev->next = NULL;
        p = temp->process;
        free(temp);
        list->size--;
        return true;
    }
}

size_t get_size_linked_list(process_linked_list *list) {
    return list->size;
}

void print_linked_list(process_linked_list *list) {
    node *tracker = list->head;
    for (int i = 0; i < list->size; ++i) {
        printf("%d => ", tracker->process->pid);
        tracker = tracker->next;
    }
    printf("%s", "\n");
}

static node *create_node_for_list(process p) {
    process *to_add_process = malloc(sizeof(process));
    if (!to_add_process) {
        return NULL;
    }
    *to_add_process = p;
    node *new_node = malloc(sizeof(node));
    if (!new_node) {
        return NULL;
    }
    new_node->process = to_add_process;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
}


void destroy_linked_list(process_linked_list *list) {
    node *current = list->head->next;
    for (int i = 0; i < list->size; ++i) {
        node *next = current->next;
        free(current->process);
        current = next;
    }
    free(list->head);
    free(list);
}
