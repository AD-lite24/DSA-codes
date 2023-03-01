#include <stdlib.h>
#include "quick_sort.h"

// Ls[lo..hi] is the input array; Ls[pInd] is the pivot

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
