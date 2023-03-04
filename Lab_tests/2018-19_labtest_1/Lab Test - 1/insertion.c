#include "node.h"
#include<stdio.h>

extern int* Arr[N];
extern int Num_Elements[N];

void InsertionSort_GM(int arr[], int n) 
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && IsLower_GM(key, arr[j]))
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
} 

void InsertionSort_Arr()
{
    for (int i = 0; i < N; i++)
        InsertionSort_Arr(Arr[Num_Elements[i]], Num_Elements[i]);   
}


