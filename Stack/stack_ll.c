#include <stdlib.h>
#include "stack.h"
#include "linked_list.h"


//The head is the top of the stack
struct Stack{
    LIST stack_ll;
};

Stack *newStack(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if(s != NULL)
        s->stack_ll = NULL;
    return s;
}

bool push(Stack *stack, Element element){
    NODE node = createNewNode(element);
    if (stack->stack_ll == NULL){
        stack->stack_ll = createNewList();
        stack->stack_ll->head = node;
        stack->stack_ll->count = 1;     
        
    }

    else{
        insertNodeIntoList(node, stack->stack_ll);
        
    }
    return true;
}

Element *top(Stack *stack){
    if (stack->stack_ll->head == NULL) return NULL;
    return &(stack->stack_ll->head->data);
}

bool pop(Stack *stack){
    if (stack->stack_ll->head == NULL){
        return false;
    }

    NODE temp = stack->stack_ll->head->next;
    removeFirstNode(stack->stack_ll);
    stack->stack_ll->head = temp;
    stack->stack_ll->count--;
    return true;
}

bool isEmpty(Stack *stack){
    if (stack->stack_ll == NULL) return true;
    return false;
}

void freeStack(Stack *stack){
    free(stack);
}
