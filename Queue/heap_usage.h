#ifndef HEAP_USAGE_H
#define HEAP_USAGE_H
#include <stdlib.h>
extern size_t heapMemoryAllocated;
void *myalloc(size_t size);
void myfree(void *ptr);
#endif