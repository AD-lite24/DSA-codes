#include <stdio.h>
#include <stdlib.h>

void mergeSort(int A[], int st, int en);
void merge(int A[], int s, int mid, int e);
void mergeByInsert(int L1[], int s1, int e1, int L2[], int s2, int e2);

int main(){
    int array[] = { 38, 27, 43, 3, 9, 82, 10};
    mergeSort(array, 0, 6);

    for(int i = 0; i < 7; i++){
        printf("%d\n", array[i]);
    }
}

void mergeSort(int A[], int st, int en)
{
    if (en - st < 1)
        return;
    int mid = (st + en) / 2;   // mid is the floor of (st+en)/2
    mergeSort(A, st, mid);     // sort the first half
    mergeSort(A, mid + 1, en); // sort the second half
    merge(A, st, mid, en);     // merge the two halves
}

void merge(int A[], int s, int mid, int e){
    mergeByInsert(A, s, mid, A, mid+1, e);
}

void mergeByInsert(int L1[], int s1, int e1, int L2[], int s2, int e2){
    
    if (s2 <= e2){
        for (int i = s2; i < e2 + 1; i++){
            
            int key = L2[i];
            int j = i - 1;

            while (j >= 0 && L1[j] >= key){
                L1[j+1] = L1[j];
                j--;
            }
            L1[j+1] = key;

        }
    }
}