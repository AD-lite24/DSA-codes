#include "array_deque.h"

int main(void) {
    array_deque *ad = create_empty_process_array_deque();
    process p1 = {"p1", 1, 0, 8, 0, 0, 8};
    process p2 = {"p2", 2, 1, 4, 0, 0, 4};
    process p3 = {"p3", 3, 4, 9, 0, 0, 9};
    process p4 = {"p4", 4, 2, 5, 0, 0, 5};
    process p5 = {"p5", 5, 3, 2, 0, 0, 2};
    add_first_array_deque(ad, p1);
    add_first_array_deque(ad, p2);
    add_first_array_deque(ad, p3);
    add_first_array_deque(ad, p4);
    add_first_array_deque(ad, p5);
    add_last_array_deque(ad, p1);
    print_array_deque(ad);
    process curr;
    remove_first_array_deque(ad, &curr);
    remove_first_array_deque(ad, &curr);
    print_array_deque(ad);
}