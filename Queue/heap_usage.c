#include "heap_usage.h"

#define ADDITIONAL_MEMORY sizeof(int)
size_t heapMemoryAllocated = 0;
void *myalloc(size_t size)
{
    void *ptr = malloc(size + ADDITIONAL_MEMORY);
    if(ptr == NULL)
        return NULL;
    heapMemoryAllocated += size;
    *((int *)ptr) = size;
    return ptr + ADDITIONAL_MEMORY;
}
 
void myfree(void *ptr)
{
    int size = *((int *)(ptr - ADDITIONAL_MEMORY));
    heapMemoryAllocated -= size;
    free(ptr - ADDITIONAL_MEMORY);
}
 