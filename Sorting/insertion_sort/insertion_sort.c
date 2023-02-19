#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void i_insertion_sort(int array[], int length);
void r_insertion_sort(int array[], int length);

void insert(int array[], int ele);

int main() {

    int array[] = {5, 3, 10, 6, 8, 9};
    r_insertion_sort(array, 6);

    printf("Printing recursive\n");
    for(int i = 0; i < 6; i++){
        printf("%d\n", array[i]);
    }

    int array1[] = {5, 3, 10, 6, 8, 9};
    i_insertion_sort(array1, 6);

    printf("Printing iterative\n");
    for(int i = 0; i < 6; i++){
        printf("%d\n", array1[i]);
    }

}

void r_insertion_sort(int array[], int length){

    if (length == 1) return;

    r_insertion_sort(array, length - 1);
    int last = array[length - 1];
    int j = length - 2;

    while(j >=0 && array[j] > last){
        array[j+1] = array[j];
        j--;
    }

    array[j+1] = last;   
}


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