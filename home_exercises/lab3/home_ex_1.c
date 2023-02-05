#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include <string.h>

#define STACK_SIZE 1000
struct Stack
{
int top;
int data[STACK_SIZE];
};

int checkIfCharIsOp(char ch);
int performArithmetic(int num1, char op, int num2);

int main(){

    char input[100];
    scanf("%[^\n]s", input);
    char* inputChars = malloc(100);

    char* token = strtok(input, " ");
   
    int num_of_elemnts = 0;
    for(int i = 0; token != NULL; i++) {
            inputChars[i] = *token;
            token = strtok(NULL, " ");   
            num_of_elemnts = i; 
        }
    
    inputChars = realloc(inputChars, num_of_elemnts + 1);

    Stack* s = newStack();

    for (int i = 0; i < num_of_elemnts + 1; i++){

        char current = inputChars[i];

        if (!checkIfCharIsOp(current)){
            push(s, (int)current - 48);
        }

        else{
            int num2 = s->data[s->top];
            pop(s);
            int num1 = s->data[s->top];
            pop(s);
            int out = performArithmetic(num1, current, num2);
            push(s, out);
        }
    }

    printf("Output is %d", s->data[s->top]);
    
}

int performArithmetic(int num1, char op, int num2){
    switch (op)
    {
    
    case '+':
        return num1 + num2;
        break;
    
    case '-':
        return num1 - num2;
        break;
    
    case '/':
        return num1/num2;
    
    case '*':
        return num1*num2;

    default:
        return 0;
        break;
    }
}

int checkIfCharIsOp(char ch){
    switch (ch)
    {
    
    case '+':
        return 1;
        break;
    
    case '-':
        return 1;
        break;
    
    case '/':
        return 1;
    
    case '*':
        return 1;

    default:
        return 0;
        break;
    }
}