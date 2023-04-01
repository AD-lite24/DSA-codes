#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int *counting_sort2(int *a, int *b, int k, int n)
{
    int c[k];
    for (int i = 0; i < k; i++)
    {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++)
        c[a[i]]++;
    for (int i = 1; i < k; i++)
    {
        c[i] = c[i] + c[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    return b;
}
int main()
{
    FILE *fptr = fopen("heights.txt", "r");
    if (fptr == NULL)
    {
        printf("Cannot Open File!");
        return 1;
    }
    while (!feof(fptr))
    {
        int n;
        fscanf(fptr, "%d", &n);
        int *curr = (int *)malloc(n * sizeof(int));
        int *exp = (int *)malloc(n * sizeof(int));
        fscanf(fptr, ",[%d", &curr[0]);
        for (int i = 1; i < n; i++)
            fscanf(fptr, ", %d", &curr[i]);
        fscanf(fptr, "]\n");
        // printArr(curr, n);
        counting_sort2(curr, exp, 350, n);
        // printArr(exp, n);
        int count = 0;
        for (int i = 0; i < n; i++)
            count += (curr[i] != exp[i] ? 1 : 0);
        printf("count = %d\n", count);
    }
}