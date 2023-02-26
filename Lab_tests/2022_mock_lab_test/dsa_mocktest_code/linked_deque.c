#include "linked_deque.h"
#include <stdio.h>
// REFER Corresponding header for documentation of functions. 
linked_deque *create_linked_process_deque() {
   linked_deque* ld = malloc(sizeof(linked_deque));
   ld->list = create_empty_process_linked_list();
   ld->list->head = NULL;
   ld->list->size = 0;
   return ld;
}

bool add_first_linked_deque(linked_deque *ld, process p) {
    return add_first_to_linked_list(ld->list, p);
}


bool add_last_linked_deque(linked_deque *ld, process p) {
    return add_last_to_linked_list(ld->list, p);
}

bool remove_first_linked_deque(linked_deque *ld, process *p) {
    return remove_first_linked_list(ld->list, p);
}

bool remove_last_linked_deque(linked_deque *ld, process *p) {
    return remove_last_linked_list(ld->list, p);
}

size_t get_size_linked_deque(linked_deque *ld) {
    return get_size_linked_list(ld->list);
}

bool is_empty_linked_deque(linked_deque *ld) {
    if (ld->list->size == 0) return true;
    return false;
}

void print_linked_deque(linked_deque *ld) {
    print_linked_list(ld->list);
}

void destroy_linked_deque(linked_deque *ld) {
    destroy_linked_list(ld->list);
    free(ld);
}
