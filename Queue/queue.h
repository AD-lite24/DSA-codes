#ifndef QUEUE_H
#define QUEUE_H
#include "element.h"
#include <stdbool.h>

typedef struct Queue Queue;
Queue *createQueue();
// createQueue() returns a pointer to a new Queue instance.
bool enqueue(Queue *queue, Element element);
// enqueue() returns true if the element was successfully added to the
// queue, false otherwise.
bool dequeue(Queue *queue);
// dequeue() returns true if the element was successfully removed from
// the queue, false otherwise.
Element *front(Queue *queue);
// front() returns a pointer to the element at the front of the queue,
// or NULL if the queue is empty.
int size(Queue *queue);
// size() returns the number of elements in the queue.
bool isEmpty(Queue *queue);
// isEmpty() returns true if the queue is empty, false otherwise.
void destroyQueue(Queue *queue);
// destroyQueue() frees all memory associated with the queue.

Element* rear(Queue* queue);
#endif