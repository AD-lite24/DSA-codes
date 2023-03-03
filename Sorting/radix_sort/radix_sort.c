#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void counting_sort_2(int* A, int n, int place, int* B){
    
    int max = ((int)(A[0]/pow(10, place)))%10;

    for (int i = 1; i < n; i++){
        if (((int)(A[i]/pow(10, place)))%10 > max)
            max = A[i];
    }
    int* C = calloc(max, sizeof(int));

    for (int i = 0; i < n; i++){
        C[((int)(A[i]/pow(10, place)))%10]++;
    }

    int run_sum = 0;
    for (int i = 0; i < max; ++i){
        run_sum+= C[i];
        C[i] = run_sum;
    }

    for (int i = n-1; i >=0; i--){
        int num = ((int)(A[i]/pow(10, place)))%10;
        B[C[num] - 1] = A[i];
        C[num]--;
    }
}

void radix_sort(int* A, int n, int dig, int* B){

    for (int i = 0; i < dig; i++){
        counting_sort_2(A, n, i, B);
    }
}

int main(){
    int* A = calloc(5, sizeof(int));
    int* B = calloc(5, sizeof(int));

    A[0] = 564;
    A[1] = 345;
    A[2] = 674;
    A[3] = 990;
    A[4] = 500;

    radix_sort(A, 5, 3, B);

    for (int i = 0; i < 5; i++)
        printf("%d\n", B[i]);

}
