#include <stdlib.h>
#include <stdio.h>
#include "quick_sort.h"
#include <sys/time.h>


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
        int p = lo; //some pivot algorithm or just using low in this case
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
        qsort_recurse(Ls, lo, p-1);
        qsort_recurse(Ls, p+1, hi);
    }
}

void qsort_hybrid_v2(int Ls[], int lo, int hi)
{   

    qsort_recurse(Ls, lo, hi);
    i_insertion_sort(Ls, hi - lo + 1);
}

int main(){

    // int arr1[5] = {1, 4, 5, 9, 3};    //testing on small array 
    // int arr2[5] = {1, 4, 5, 9, 3};

    struct timeval t1, t2;
    double time_taken; 

    FILE* fp = fopen("int6.txt", "r");
    int length = 1000000;
    int* arr1 = calloc(length, sizeof(int));

    int i = 0;
    while(!feof(fp)){
        fscanf(fp, "%d", &arr1[i]);
        // printf("%d\t", arr1[i]);
        i++;
    }
    gettimeofday(&t1, NULL);
    qsort_hybrid_v1(arr1, 0, length - 1);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;


    printf("v1 took %f seconds \n", time_taken);
    
    free(arr1);

    int* arr2 = calloc(length, sizeof(int));
    rewind(fp);

    i = 0;
    while(!feof(fp)){
        fscanf(fp, "%d", &arr2[i]);
        i++;
    }

    gettimeofday(&t1, NULL);
    qsort_hybrid_v2(arr2, 0, length - 1);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("v2 took %f seconds \n", time_taken);

}