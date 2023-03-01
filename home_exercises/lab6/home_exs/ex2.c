//Question Let S be an (unsorted) array of n distinct real numbers 
//and let k ≤ n be a positive integer 
//(k may not be a constant, ie., it can be in terms of n as well). 
//Write an algorithm, running in O(n) time, that determines the k 
//numbers in S that are closest to the median of S.


//INCOMPLETE 

#include <stdlib.h>
#include <stdio.h>

int swap(int arr[], int i1, int i2){
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}

int part(int Ls[], int lo, int hi, int pInd)
{
    swap(Ls, pInd, lo);
    int pivPos, lt, rt, pv;
    lt = lo + 1;
    rt = hi;
    pv = Ls[lo];
    while (lt < rt)
    {
        for (; lt <= hi && Ls[lt] <= pv; lt++);
        // Ls[j]<=pv for j in lo..lt-1
        for (; Ls[rt] > pv; rt--);
        // Ls[j]>pv for j in rt+1..hi
        if (lt < rt)
            {
                swap(Ls, lt, rt);
                lt++;
                rt--;
            }
    }
    if (Ls[lt] < pv && lt <= hi)
        pivPos = lt;
    else
        pivPos = lt - 1;
    swap(Ls, lo, pivPos);
// Postcond.: (Ls[j]<=pv for j in lo..pivPos-1) and (Ls[j]>pv for j in pivPos+1..hi)
    return pivPos;
}

int qselect(int L[], int n, int k)
{
    int pivot = 0;
    int lo = 0;
    int hi = n - 1;
    int pInd = part(L, lo, hi, pivot);
    if (k <= pInd)
        return qselect(L, pInd, k);
    else if (k > pInd + 1)
        return qselect(L + pInd + 1, n - pInd - 1, k - pInd - 1);
    else
        return L[pInd];
}

int* getNearestEles(int arr[], int k, float median){

    int* nears = calloc(k, sizeof(int));
    if (ceilf())
    for (int i = 0; i < k; i++){

        
    }
}

int main(){

    int num = 10;
    float arr[10] = {5.0f, 6.0f, 19.9f, 4.45f, 13.34f, 9.0f, 10.0f, 56.0f, 34.0f, 2};
    int k = 3;
    float median;
    

    if (num%2 == 0){
        int i1 = num/2;
        int i2 = num/2 + 1;
        
        int num1 = qselect(arr, num, i1); //quickselect takes O(n) on average
        int num2 = qselect(arr, num, i2);
        median = (num1 + num2)/2.0f;
    }

    else{
        int i = (num + 1)/2;
        int num1 = qselect(arr, num, i);
        median = num1;
    }

    // printf("%f\n", median);



    
}