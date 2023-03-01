#include <stdlib.h>
#include <stdio.h>

// L[] is the input array of length n
// kth smallest element is returned

int select(int L[], int n, int k)
{
    if (k == 0)
        return L[0];
    if (n <= 5){
        for (int i = 1; i < n; i++)
            for (int j = i-1; j >= 0; j--)
                if (L[j] > L[j+1])
                    swap(L, j, j+1);
                else
                    break;
        return L[k-1];
    }
    // partition L into subsets of five elements each
    //     (there will be n/5 subsets total).
    int numGroups;
    if (n % 5 == 0)
        numGroups = n/5;
    else
        numGroups = n/5 + 1;
    int medians[numGroups];
    for (int i = 0; i < numGroups; i++)
    {
        medians[i] = select(L + i*5, min(5, n - i*5), min(5, n - i*5)/2);
    }
    int M = select(medians, numGroups, (numGroups+1)/2);
    // Partition array into two halves, L1, {M} and L2, such that
    // L1 contains elements <= M, {M} contains one instance of M and L2 contains all elements > M
    int mInd;
    for (int i = 0; i < n; i++)
    {
        if (L[i] == M)
        {
        mInd = i;
        break; 
        }
    }
    int pInd = part(L, 0, n-1, mInd);
    if (k <= pInd)
        return select(L, pInd, k);
    else if (k > pInd + 1)
        return select(L + pInd + 1, n - pInd - 1, k - pInd - 1);

    else
        return L[pInd];
}