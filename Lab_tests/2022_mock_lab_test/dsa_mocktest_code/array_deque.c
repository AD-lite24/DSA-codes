#include "array_deque.h"

// Use these functions if you find them helpful or define other static helper functions that might assist you.
// One possible implementation:
// Assume that next_first decrements (or moves left) and rolls back from the other end of the array.
// Assume that next_last increments (or moves right).
// So at any instant, during add_first the element is added to next-first position and next_first is updated accordingly
// Or an element is added at next_last which is then updated accordingly


static unsigned int get_first_index(array_deque *ad);

static unsigned int get_last_index(array_deque *ad);

static unsigned int decrement_index(array_deque *d, size_t index);

static unsigned int increment_index(array_deque *d, size_t index);

static void resize_if_needed(array_deque *d);

static process *create_process(process p);

array_deque *create_empty_process_array_deque() {
    // COMPLETE
}

static unsigned int decrement_index(array_deque *ad, size_t index) {
    index = index - 1;
    if (index == -1) {
        index = ad->capacity - 1;
    }
    return index;
}

static unsigned int increment_index(array_deque *d, size_t index) {
    return (index + 1) % d->capacity;
}

static unsigned int get_first_index(array_deque *ad) {
    return increment_index(ad, ad->next_first);
}

static unsigned int get_last_index(array_deque *ad) {
    return decrement_index(ad, ad->next_last);
}

bool add_first_array_deque(array_deque *ad, process p) {
    // COMPLETE
}

static process *create_process(process p) {
    process *pro = malloc(sizeof(process));
    if (!pro) return NULL;
    *pro = p;
    return pro;
}

bool add_last_array_deque(array_deque *ad, process p) {
    // COMPLETE
}

bool remove_first_array_deque(array_deque *ad, process *p) {
    // COMPLETE
}

bool remove_last_array_deque(array_deque *ad, process *p) {
    // COMPLETE
}

size_t get_size_array_deque(array_deque *ad) {
    return ad->size;
}

static void resize_if_needed(array_deque *ad) {
    if (ad->size < ad->capacity) {
        return;
    }
    // COMPLETE
}

void print_array_deque(array_deque *ad) {
    
}
