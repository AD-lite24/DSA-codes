#ifndef DSA_LINKED_DEQUE_H
#define DSA_LINKED_DEQUE_H

#include "linkedlist.h"

// The Linked-Deque API backed internally by a linked_list
typedef struct process_linked_deque {
    process_linked_list *list;
} linked_deque;

/**
 * Creates and returns an empty process deque
 * Also creates the internal linked list. 
 */
linked_deque *create_linked_process_deque();

/**
 * Adds to the first position of the linked deque in constant time.
 * @return true if the addition was successful
 */
bool add_first_linked_deque(linked_deque *ld, process p);

/**
 * Adds to the last position of the linked deque in constant time.
 * @return true if the addition was successful
 */
bool add_last_linked_deque(linked_deque *ld, process p);

/**
 * Removes from the first position of the linked deque in constant time and stores it in the memory pointed to by p
 * @return true if the removal was successful
 */
bool remove_first_linked_deque(linked_deque *ld, process *p);
/**
 * Removes from the last position of the linked deque in constant time and stores it in the memory pointed to by p
 * @return true if the removal was successful
 */
bool remove_last_linked_deque(linked_deque *ld, process *p);

/**
 * Returns the size of the linked deque
 */
size_t get_size_linked_deque(linked_deque *ld);

/**
 * Returns true if the linked deque is empty; false otherwise
 */
bool is_empty_linked_deque(linked_deque *ld);

void print_linked_deque(linked_deque *ld);

void destroy_linked_deque(linked_deque *ld);

#endif //DSA_LINKED_DEQUE_H
