#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include "element.h"

Element itoe(int n){
    Element e;
    e.float_value = 0;
    e.int_value = n;
    return e;
}

void bucket_sort(int* A, int* B, int n, int k){

    LIST* C = calloc(k, sizeof(struct linked_list*));
    
    for (int i = 0; i <= k; i++)
        C[i] = createNewList();

    for (int i = 0; i < n; i++){
        int num = A[i];
        NODE new = createNewNode(itoe(num));
        insertNodeIntoList(new, C[num]);
    }

    int j = 0;
    for (int i = 0; i < k; i++){
        LIST list = C[i];
        while(list->count != 0){
            B[j] = removeFirstNode(list);
            j++;
        }
    }

}

int main(){

    int* A = calloc(6, sizeof(int));
    A[0] = 8;
    A[1] = 6;
    A[2] = 5;
    A[3] = 5;
    A[4] = 9;
    A[5] = 13;

    int* B = calloc(6, sizeof(int));
    
    bucket_sort(A, B, 6, 13);

    for (int i = 0; i < 6; i++)
        printf("%d\n", B[i]);
}