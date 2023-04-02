#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"

#define STACK_SIZE 100
struct Stack
{
    int top;
    Node* data[STACK_SIZE];
};

Stack *newStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    for (int i = 0; i < STACK_SIZE; i++)
        s->data[i] = malloc(sizeof(Node));
    if(s != NULL)
        s->top = -1;
    return s;
}
bool push(Stack *s, Node* e)
{
    if(s->top == STACK_SIZE - 1)
        return false;
    s->data[++(s->top)] = e;
    return true;
}
bool pop(Stack *s){
    if (s->top == - 1)
        return false;
    
    s->top--;
    return true;
}

Node *top(Stack *s){
    
    if (s->top == -1){
        return NULL;
    }

    return s->data[s->top];
}

bool isEmpty(Stack *s){
    if (s->top == -1)
        return true;
    return false;
}

void freeStack(Stack *s){
    free(s);
}