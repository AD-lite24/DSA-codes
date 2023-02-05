#include "queue.h"
#include <stdio.h>
Element itoe (int i);
int main()
{
    Queue *q = createQueue();
    if(isEmpty(q))
        printf("Queue is empty\n");
    
    enqueue(q, itoe(1));
    int value = front(q)->int_value;
    printf("front of queue is %d\n", value);

    enqueue(q, itoe(2));
    value = rear(q)->int_value;
    printf("rear of queue is %d\n", value);

    value = front(q)->int_value;
    printf("front of queue is %d\n", value);
    
    dequeue(q);

    value = front(q)->int_value;
    printf("front of queue is %d\n", value);
    printf("Pop returned %s\n", dequeue(q)?"true":"false");

    printf("Trying to pop an empty stack\n");
    printf("Pop returned %s\n", dequeue(q)?"true":"false");

    destroyQueue(q);
    return 0;
}
Element itoe (int i)
{
    Element e;
    e.int_value = i;
    e.float_value = 0;
    return e;
}