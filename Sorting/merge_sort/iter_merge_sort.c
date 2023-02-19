#include <stdio.h>
#include <stdlib.h>

void i_mergeSort(int array[], int n);
void merge(int array[], int l, int r);

int main(){

}

void i_mergeSort(int array[], int n){
    merge(array, 0, n - 1);
}

void merge(int array[], int l, int r){
    int m = r + (l-r)/2;
    
}