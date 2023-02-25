#ifndef DSA_ARRAY_DEQUE_H
#define DSA_ARRAY_DEQUE_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "process.h"

#define INITIAL_SIZE_ARRAY_DEQUE 2

// Use the next_first and next_last pointers to track the circular buffer additions and deletions
// Feel free to modify the struct if you want to use a different technique to track the two ends of the array deque.
typedef struct process_array_deque {
    process **processes;
    size_t next_first;
    size_t next_last;
    size_t size;
    size_t capacity;
} array_deque;

// creates an empty process array deque with INITIAL_SIZE_ARRAY_DEQUE size of the internal processes array
// and returns a pointer to it
array_deque *create_empty_process_array_deque();

/**
 * adds to the front of the array deque in constant time "on average"
 * @return true if the addition was successful, false otherwise
 * Time Complextiy: O(1) on average
 */
bool add_first_array_deque(array_deque *ad, process p);

/**
 * adds to the back of the array deque in constant time "on average"
 * @return true if the addition was successful, false otherwise
 * Time Complextiy: O(1) on average
 */
bool add_last_array_deque(array_deque *ad, process p);


/**
 * removes the front of the array deque in constant time "on average"
 * @return true if the addition was successful, false otherwise
 * Time Complextiy: O(1) on average
 */
bool remove_first_array_deque(array_deque *ad, process *p);

/**
 * removes the back of the array deque in constant time "on average"
 * @return true if the addition was successful, false otherwise
 * Time Complextiy: O(1) on average
 */
bool remove_last_array_deque(array_deque *ad, process *p);

/**
 * @return the size of the array deque
 * Time Complextiy: Theta(1)
 */
size_t get_size_array_deque(array_deque *ad);

void print_array_deque(array_deque* ad);

#endif //DSA_ARRAY_DEQUE_H
