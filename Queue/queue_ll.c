#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "queue.h"
#include "element.h"
#include "linked_list.h"

struct Queue{
    LIST queue_ll;
};

Queue* createQueue(){
    Queue* q = malloc(sizeof(Queue));
    if (q != NULL)
        q->queue_ll = NULL;
    return q;
}

bool enqueue(Queue *queue, Element element){
    NODE node = createNewNode(element);
    if (queue->queue_ll == NULL){
        queue->queue_ll = createNewList();
        queue->queue_ll->head = node;
        queue->queue_ll->tail = node;
        queue->queue_ll->count = 1;
    }
    else{
        insertNodeIntoList(node, queue->queue_ll);
    }
    return true;
}

bool dequeue(Queue *queue){
    // NODE head = queue->queue_ll->head;
    // NODE tail = queue->queue_ll->tail;
    // printf ("%d", head->data);

    if (queue->queue_ll->head == NULL){
        printf("activated");
        return false;
    }
    else if (queue->queue_ll->head == queue->queue_ll->tail){
        queue->queue_ll->head = NULL;
        queue->queue_ll->tail = NULL;
        printf("No element left\n");
        return true;
    }
    else{
        removeFirstNode(queue->queue_ll);
        return true;
    }
}

Element *front(Queue *queue){
    NODE front = queue->queue_ll->head;
    if (front == NULL) return NULL;
    return &(front->data);
}

int size(Queue *queue){
    return queue->queue_ll->count;
}

bool isEmpty(Queue *queue){
    if (queue->queue_ll == NULL || queue->queue_ll->count == 0) return true;
    return false;
}

void destroyQueue(Queue *queue){
    free(queue);
}

Element* rear(Queue* queue){
    NODE rear = queue->queue_ll->tail;
    if (rear == NULL) return NULL;
    return &(rear->data);
}
