#include <stdlib.h>
#include <stdio.h>
#include "quick_sort.h"


int part(int Ls[], int lo, int hi, int pInd);

void i_insertion_sort(int array[], int length){
    
    for (int i = 1; i < length; i++){
        int key = array[i];
        int j = i-1;

        while(j >= 0 && array[j] > key){
            array[j+1] = array[j];
            j--;
        }

        array[j+1] = key;       
    }
}

void qsort_hybrid_v1(int Ls[], int lo, int hi)
{
    if (hi - lo < 10)
    {
        i_insertion_sort(Ls, hi - lo + 1);
        return; 
    }
    else if (lo < hi)
    {
        int p = lo; //some pivot algorithm or low in this case
        p = part(Ls, lo, hi, p);
        qsort_hybrid_v1(Ls, lo, p - 1);
        qsort_hybrid_v1(Ls, p + 1, hi);
    } 
}

void qsort_recurse(int Ls[], int lo, int hi){
    if (hi - lo < 10)
        return;
        
    else if (lo < hi){
        int p = lo;
        p = part(Ls, lo, hi, p);
    }
}

void qsort_hybrid_v2(int Ls[], int lo, int hi)
{   
    qsort_recurse(Ls, lo, hi);
    i_insertion_sort(Ls, hi - lo + 1);
}

int main(){
    int arr1[5] = {1, 4, 5, 9, 3};
    int arr2[5] = {1, 4, 5, 9, 3};

    qsort_hybrid_v1(arr1, 0, 4);
    printf("v1: \n");
    for (int i = 0; i < 5; i++){
        printf("%d\n", arr1[i]);
    }

    qsort_hybrid_v2(arr2, 0, 4);
    printf("v2: \n");
    for (int i = 0; i < 5; i++){
        printf("%d\n", arr2[i]);
    }
}