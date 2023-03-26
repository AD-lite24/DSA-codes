#include"node.h"
#include<stdio.h>
#include<stdlib.h>

extern int* A[N];
extern int Num_Elements[N];
void ConvertListstoArray(Locality *start)
{
    Locality* temp = start;
    for(int i = 0; i < N; i++){
        Num_Elements[i] = temp->count;

        for (int j = 0; j < temp->count; j++){
            Member* mem = temp->first;
            A[i][j] = mem->id;
        }
        temp = temp->next;
    } 
}



