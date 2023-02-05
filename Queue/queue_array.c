#include "queue.h"
#include "heap_usage.h"
#include <stdlib.h>
#include <stdio.h>

#define QUEUE_SIZE 1000
struct Queue{
    int front;
    int size;
    int rear;
    Element data[QUEUE_SIZE];
};

Queue *createQueue(){
    Queue* q = myalloc(sizeof(Queue));
    if (q != NULL){
        q->front = -1;
        q->size = 0;
        q->rear = -1;
    }
    return q;
}

bool enqueue(Queue* q, Element element){
    
    if (q->size == QUEUE_SIZE) return false;
    else if (q->front == -1){
        q->front = 0;    
        q->data[0] = element;
        q->rear = 0;
        q->size = 1;
    }
    else if (q->rear == q->size - 1 && q->front != 0){
        q->rear = 0;
        q->data[q->rear] = element;
        q->size += 1;

    }
    else{
        q->rear++;
        q->data[q->rear] = element;
        q->size += 1;
    }
    return true;
}

bool dequeue(Queue* q){
    if (q->size == 0) return false;
    
    if (q->front == QUEUE_SIZE - 1) q->front = 0;
    else q->front++;
    q->size--;
    return true;
}

Element *front(Queue* q){
    if (q != NULL) return &(q->data[q->front]);
    else return NULL;
}

Element* rear(Queue* q){
    if (q != NULL) return &(q->data[q->rear]);
    else return NULL;
}

int size(Queue* q){
    if (q != NULL) return q->size;
    else return -1;
}

bool isEmpty(Queue* q){
    if (q->size == 0) return true;
    else return false;
}

void destroyQueue(Queue* q){
    myfree(q);
}