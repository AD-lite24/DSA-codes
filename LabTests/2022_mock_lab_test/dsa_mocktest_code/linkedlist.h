#ifndef DSA_LINKEDLIST_H
#define DSA_LINKEDLIST_H

#include <stdlib.h>
#include "process.h"
#include <stdbool.h>


typedef struct linked_list_node {
    struct linked_list_node *next;
    struct linked_list_node *previous;
    process *process;
} node;

typedef struct process_linked_list {
    size_t size;
    node *head;
} process_linked_list;

// Creates and returns a pointer to an empty linked list
process_linked_list *create_empty_process_linked_list();

// Adds to the first position in the list and returns true if the addition was successful.
// Time Complexity: Theta(1)
bool add_first_to_linked_list(process_linked_list *list, process p);

// Adds to the last position in the list and returns true if the addition was successful.
// Time Complexity: Theta(1)
bool add_last_to_linked_list(process_linked_list *list, process p);

// Adds to the specified position in the list if index <= size
// and returns true if the addition was successful.
// Time Complexity: O(index)
bool add_at_index_linked_list(process_linked_list *list, size_t index, process p);

// Removes from the first position of the linked list and returns true if successful
// Stores the removed process in the memory pointed to by p
// Time Complexity: Theta(1)
bool remove_first_linked_list(process_linked_list *list, process *p);

// Removes from the last position of the linked list and returns true if successful
// Stores the removed process in the memory pointed to by p.
// Time Complexity: Theta(1)
bool remove_last_linked_list(process_linked_list *list, process *p);

// NOT used in this assignment, implement it later.
bool contains_linked_list(process p);

// Destroys the linked list and frees the memory occupied by it and the processes within
void destroy_linked_list(process_linked_list *list);

// Returns the size of the list
// Time Complexity: Theta(1)
size_t get_size_linked_list(process_linked_list *list);

// Prints the list to stdout
void print_linked_list(process_linked_list *list);


#endif //DSA_LINKEDLIST_H
