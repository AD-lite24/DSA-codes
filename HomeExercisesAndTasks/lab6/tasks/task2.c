//You are given an array of 0s and 1s in random order. Segregate 0s on the left side and 1s
//on the right side of the array [Basically you have to sort the array]. Traverse the array only once.

#include <stdlib.h>
#include <stdio.h>

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sort(int arr[], int len){
    int i = 0;
    int j = len - 1;
    int pv = 1;

    while (i < j){
        for (; i <= j && arr[i] != pv; i++);
        for (; arr[j] == pv; j--);

        if (i < j){
            swap(arr, i, j);
            i++;
            j--;
        }
    }
    
}

int main(){
    int arr[10] = {0, 1, 0, 0, 1, 1, 0, 0, 1, 1};
    int len = 10;

    sort(arr, len);

    for (int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
}
