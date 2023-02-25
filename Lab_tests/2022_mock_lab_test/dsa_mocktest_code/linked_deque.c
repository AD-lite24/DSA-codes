#include "linked_deque.h"
// REFER Corresponding header for documentation of functions. 
linked_deque *create_linked_process_deque() {
   // COMPLETE
}

bool add_first_linked_deque(linked_deque *ld, process p) {
    return add_first_to_linked_list(ld->list, p);
}

bool add_last_linked_deque(linked_deque *ld, process p) {
    // COMPLETE
}

bool remove_first_linked_deque(linked_deque *ld, process *p) {
    // COMPLETE
}

bool remove_last_linked_deque(linked_deque *ld, process *p) {
    // COMPLETE
}

size_t get_size_linked_deque(linked_deque *ld) {
    // COMPLETE
}

bool is_empty_linked_deque(linked_deque *ld) {
    // COMPLETE
}

void print_linked_deque(linked_deque *ld) {
    print_linked_list(ld->list);
}

void destroy_linked_deque(linked_deque *ld) {
    destroy_linked_list(ld->list);
    free(ld);
}
