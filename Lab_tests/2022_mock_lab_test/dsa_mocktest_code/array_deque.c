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
    array_deque* ad = calloc(1, sizeof(array_deque));
    ad->processes = calloc(INITIAL_SIZE_ARRAY_DEQUE, sizeof(process));
    ad->capacity = INITIAL_SIZE_ARRAY_DEQUE;
    ad->next_first = 0;
    ad->next_last = 0;
    ad->size = 0;

    return ad;
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
    
    process* pro = create_process(p);
    ad->size++;

    int first = get_first_index(ad);
    int last = get_last_index(ad);
    if (ad->size == ad->capacity){

        ad->processes = realloc(ad->processes, (ad->capacity)*2);
        int curr_capacity = ad->capacity;
        int new_capacity = curr_capacity*2;
        ad->capacity = new_capacity;
        printf("changed capacity from %d to %d\n", ad->size, ad->capacity);

        
        
        if (last > first) {
            int num_move = get_size_array_deque(ad) - first;
            for (int i = first; i < num_move; i++){
                ad->processes[i + ad->size] = ad->processes[i];
                setToZero(ad->processes[i]);
                
            }
            ad->next_first+=ad->size;
        }
    }
    
    ad->processes[ad->next_first] = pro;
    ad->next_first = decrement_index(ad, ad->next_first);

    return true;
}

static process *create_process(process p) {
    process *pro = malloc(sizeof(process));
    if (!pro) return NULL;
    *pro = p;
    return pro;
}

bool add_last_array_deque(array_deque *ad, process p) {
    
    process* pro = create_process(p);
    ad->processes[ad->next_last] = pro;
    ad->next_last = (ad, ad->next_last);
    ad->size++;

    if (ad->size == ad->capacity){
        ad->processes = realloc(ad->processes, (ad->capacity)*2);
        ad->capacity = (ad->capacity)*2;
        printf("changed capacity from %d to %d\n", ad->size, ad->capacity);
    }
    return true;
}

bool remove_first_array_deque(array_deque *ad, process *p) {
    process* pro = (ad->processes)[get_first_index(ad)];
    *p = *pro;
    free(pro);
    ad->size--;
    ad->next_first = (ad, get_first_index(ad));

    if (ad->size < (ad->capacity)/2 && (ad->capacity)/2 > INITIAL_SIZE_ARRAY_DEQUE){
        ad->processes = realloc(ad->processes, ad->capacity/2);
        ad->capacity = ad->capacity/2;
    }

    return true;
}

bool remove_last_array_deque(array_deque *ad, process *p) {
    process* pro = (ad->processes)[get_last_index(ad)];
    *p = *pro;
    free(pro);
    ad->size--;
    ad->next_last = (ad, get_last_index(ad));

    if (ad->size < (ad->capacity)/2 && (ad->capacity)/2 > INITIAL_SIZE_ARRAY_DEQUE){
        ad->processes = realloc(ad->processes, ad->capacity/2);
        ad->capacity = ad->capacity/2;
    }

    return true;
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

    int first = get_first_index(ad);
    int last = get_last_index(ad);
    int size = get_size_array_deque(ad);

    for (int i = first; i != last; i = increment_index(ad, i)){
        process* pro = ad->processes[i];
        printf("process id: %d\n", pro->pid);
    }

}
