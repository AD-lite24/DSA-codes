#include "linked_deque.h"
#include "process.h"

#define SIZE 5

int main() {
    linked_deque *list = create_linked_process_deque();
    process p1 = {"p1", 1, 0, 8, 0, 0, 8};
    process p2 = {"p2", 2, 1, 4, 0, 0, 4};
    process p3 = {"p3", 3, 4, 9, 0, 0, 9};
    process p4 = {"p4", 4, 2, 5, 0, 0, 5};
    process p5 = {"p5", 5, 3, 2, 0, 0, 2};

    add_first_linked_deque(list, p1);
    add_last_linked_deque(list, p2);
    add_last_linked_deque(list, p3);
    add_last_linked_deque(list, p4);
    add_last_linked_deque(list, p5);
    print_linked_deque(list);
    process curr;
    remove_first_linked_deque(list, &curr);
    print_linked_deque(list);


    // you can add more tests here

}