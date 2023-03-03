#include <stdlib.h>
#include <stdio.h>

void counting_sort(int* A, int* B, int k, int n){
    int* C = calloc(k, sizeof(int));

    for (int i = 0; i < n; i++)
        C[A[i]]++;
    
    int run_sum = 0;
    for (int i = 0; i < k; i++){
        run_sum += C[i];
        C[i] = run_sum;
    }

    for (int i = n-1; i >= 0; i--){  //to ensure stability
        int num = A[i];
        B[C[num] - 1] = num;
        C[num]--;
    }

    free(C);
}

int main(){

    int* A = malloc(5*sizeof(int));
    A[0] = 10;
    A[1] = 4;
    A[2] = 6;
    A[3] = 6;
    A[4] = 13;

    int* B = malloc(5*sizeof(int));

    counting_sort(A, B, 14, 5);

    for (int i = 0; i < 5; i++)
        printf("%d\n", B[i]);
}