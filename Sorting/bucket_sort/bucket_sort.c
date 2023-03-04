#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"


//INCOMPLETE
void intervalSort(float arr[], int n) {
    
    int i, j;

    // Create n empty buckets
    LIST b[n];
    for(i=0; i<n; i++)
        b[i] = createNewList();
    

    // Put array elements in different buckets
    for(i=0; i<n; i++) 
        insertFirst(b[(int)(n*arr[i])], createNewNode(ftoe(arr[i]))); 
    

    // Sort individual buckets
    for(i=0; i<n; i++) 
        sortList(b[i]);     // sortList() function has to be implemented 
    
    // Concatenate all buckets (in sequence) into arr[]
    for(i=0, j=0; i<n; i++) {   
        NODE temp = b[i]->head; 
        while(temp != NULL){
            arr[j++] = temp->data.float_value;
            temp = temp->next;
        }
    } 
}

int main(){
    
}