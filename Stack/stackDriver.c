#include "stack.h"
#include <stdio.h>
Element itoe (int i);
int main()
{
    Stack *s = newStack();
    if(isEmpty(s))
        printf("Stack is empty\n");
    
    push(s, itoe(1));
    int value = top(s)->int_value;
    printf("Top of stack is %d\n", value);

    push(s, itoe(2));
    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);

    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);
    
    pop(s);

    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);
    printf("Pop returned %s\n", pop(s)?"true":"false");

    printf("Trying to pop an empty stack\n");
    printf("Pop returned %s\n", pop(s)?"true":"false");

    freeStack(s);
    return 0;
}
Element itoe (int i)
{
    Element e;
    e.int_value = i;
    e.float_value = 0;
    return e;
}