#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertion_sort(int array[], int length);

int main() {

    int array[] = {5, 3, 10, 6, 8, 9};
    insertion_sort(array, 6);

    for(int i = 0; i < 6; i++){
        printf("Printing\n");
        printf("%d\n", array[i]);
    }

}

void insertion_sort(int array[], int length){
    

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