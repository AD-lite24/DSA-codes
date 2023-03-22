#include <stdlib.h>
#include <stdio.h>
#include "hashtable_h.h"
#define TABLE_SIZE 1024

//All four probing techniques used in a single program

int main()
{

    FILE *fp = fopen("../task1/t1_data.txt", "r");   //Change filepath if needed

    int num;
    fscanf(fp, "%d\n", &num);

    Student students[num];

    int idx = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%lld,%[^\n]s", &students[idx].ID, students[idx].name);
        idx++;
    }

    
    
}