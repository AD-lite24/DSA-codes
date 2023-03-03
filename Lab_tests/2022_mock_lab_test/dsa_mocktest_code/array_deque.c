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
    ad->processes = calloc(INITIAL_SIZE_ARRAY_DEQUE, sizeof(process*));
    ad->capacity = INITIAL_SIZE_ARRAY_DEQUE;
    ad->next_first = 0;
    ad->next_last = 1;
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

    if (ad->size == 2){ //base case

        ad->processes = realloc(ad->processes, 4*sizeof(process*));
        ad->processes[3] = ad->processes[1];
        ad->processes[1] = NULL;
        ad->capacity = 4;
        ad->next_first = 3;
        ad->next_last = 1;
        printf("changed capacity from 2 to 4\n");
    }
    
    else if (ad->size == ad->capacity){

        int first = get_first_index(ad);
        int last = get_last_index(ad);
        ad->processes = realloc(ad->processes, (ad->capacity)*2*sizeof(process*));
        int curr_capacity = ad->capacity;
        int new_capacity = curr_capacity*2;
        ad->capacity = new_capacity;
        printf("changed capacity from %d to %d\n", ad->size, ad->capacity);

        if (last < first) {
            int num_move = get_size_array_deque(ad) - first;
            for (int i = 0; i < num_move; i++){
                ad->processes[i + ad->capacity/2 + first] = ad->processes[i + first];
                ad->processes[i + first] = NULL;
            }
            for (int i = 0; i < ad->capacity/2; i++){
                ad->next_first = increment_index(ad, ad->next_first);
            }
        }

        else if (first > last){
            int num_move = get_size_array_deque(ad) - last;
            for (int i = 0; i < num_move; i++){
                ad->processes[i + ad->capacity/2 + last] = ad->processes[i + last];
                ad->processes[i + last] = NULL;
            }
            for (int i = 0; i < ad->capacity/2; i++){
                ad->next_last = increment_index(ad, ad->next_last);
            }
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
    ad->size++;

    int first = get_first_index(ad);
    int last = get_last_index(ad);

    if (ad->size == ad->capacity){
        ad->processes = realloc(ad->processes, (ad->capacity)*2*sizeof(process*));
        ad->capacity = (ad->capacity)*2;
        printf("changed capacity from %d to %d\n", ad->size, ad->capacity);

        if (last < first){
            int num_move = get_size_array_deque(ad) - first;
            for (int i = 0; i < num_move; i++){
                ad->processes[i + ad->capacity/2 + first] = ad->processes[i + first];
                ad->processes[i + first] = NULL;
            }
            for (int i = 0; i < ad->capacity/2; i++){
                ad->next_first = increment_index(ad, ad->next_first);
            }
        }

        else if (first > last){
            int num_move = get_size_array_deque(ad) - last;
            for (int i = 0; i < num_move; i++){
                ad->processes[i + ad->capacity/2 + last] = ad->processes[i + last];
                ad->processes[i + last] = NULL;
            }
            for (int i = 0; i < ad->capacity/2; i++){
                ad->next_last = increment_index(ad, ad->next_last);
            }
        }
    }
    ad->processes[ad->next_last] = pro;
    ad->next_last = increment_index(ad, ad->next_last);
    return true;
}

bool remove_first_array_deque(array_deque *ad, process *p) {
    int first = get_first_index(ad);
    int last = get_last_index(ad);
    process* pro = (ad->processes)[first];
    *p = *pro;
    free(pro);
    ad->size--;

    

    if (ad->size < (ad->capacity)/2 && (ad->capacity)/2 >= INITIAL_SIZE_ARRAY_DEQUE){
        
        ad->capacity = ad->capacity/2;

        if (last < first){
            int num_move = ad->capacity*2 - first;
            for (int i = 0; i < num_move; i++){
                ad->processes[first + i - ad->capacity] = ad->processes[first + i];
                ad->processes[first + i] = NULL;
            }
            for (int i = 0; i < ad->capacity; i++){
                ad->next_first = decrement_index(ad, ad->next_first);
            }
        }

        if (last > first){
            int num_move = ad->capacity*2 - last;
            for (int i = 0; i < num_move; i++){
                ad->processes[last + i - ad->capacity] = ad->processes[last + i];
                ad->processes[last + i] = NULL;
            }
            for (int i = 0; i < ad->capacity; i++){
                ad->next_last = decrement_index(ad, ad->next_last);
            }
        }

        ad->processes = realloc(ad->processes, (ad->capacity/2)*sizeof(process*));
        printf("changed capacity from %d to %d", ad->capacity*2, ad->capacity);       
    }

    else{
        ad->next_first = increment_index(ad, ad->next_first);
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

}

void print_array_deque(array_deque *ad) {

    int first = get_first_index(ad);
    int last = get_last_index(ad);

    int size = get_size_array_deque(ad);
    printf("first: %d last: %d\n", first, last);

    for (int i = first; i != ad->next_last; i = increment_index(ad, i)){
        printf("i = %d\n", i);
        process* pro = ad->processes[i];        
        printf("process id: %d\n", pro->pid);
    }

}
