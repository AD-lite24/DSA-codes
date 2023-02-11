#include <stdio.h>
#include <stdlib.h>

void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);


int main(){
    int array[] = { 38, 27, 43, 3, 9, 82, 10};
    merge_sort(array, 7);

    for(int i = 0; i < 7; i++){
        printf("Printing\n");
        printf("%d\n", array[i]);
    }
}

void merge_sort(int a[], int length){
  // call the merge sort recursion function, the left index of 0 and the
  // right index of length - 1 are provided as we are initially looking 
  // at sorting "the entire array"
  printf("%d\n", length-1);
  merge_sort_recursion(a, 0, length - 1);
}

void merge_sort_recursion(int a[], int l, int r){
    
    if (l < r){
        int mid = l + (r-l)/2;
        merge_sort_recursion(a, l, mid);
        merge_sort_recursion(a, mid+1, r);
        merge_sorted_arrays(a, l, mid, r);
    }
}

void merge_sorted_arrays(int a[], int l, int mid, int r){

    int l_len = mid - l + 1;
    int r_len = r - mid;
    
    //create temporary arrays

    int temp_left[l_len];
    int temp_right[r_len];

    int i, j, k; //index pointers 

    // copy the left portion into the temp_left array
    for (int i = 0; i < l_len; i++)
        temp_left[i] = a[l + i];
  
    // copy the right portion into the temp_right array
    for (int i = 0; i < r_len; i++)
        temp_right[i] = a[mid + 1 + i];

    for (i = 0, j = 0, k = l; k <= r; k++){
        
        if ((i < l_len) &&
        (j >= r_len || temp_left[i] <= temp_right[j])){
            a[k] = temp_left[i];
            i++;
        }

        else {
            a[k] = temp_right[j];
            j++;
        }

    }
}
