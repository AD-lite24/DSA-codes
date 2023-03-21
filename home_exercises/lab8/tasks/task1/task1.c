#include <stdlib.h>
#include <stdio.h>
#include "hashtable_h.h"

// INCOMPLETE

typedef struct student
{
    long long int ID;
    char name[30];
} Student;

int main()
{

    FILE *fp = fopen("t1_data.txt", "r");

    int num;
    fscanf(fp, "%d\n", &num);

    Student students[num];

    int idx = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%lld,%[^\n]s", &students[idx].ID, students[idx].name);
        idx++;
    }

    int num_types = 6; // types of hashfunctions

    for (int i = 0; i < num_types; i++){

        int collisions = 0;
        htable *table = create_table(2*num);
        for (int j = 0; j < num; j++){
            int check = ht_insert(table, students[j].ID, students[j].name, i);
            if (check) collisions++;
        }

        printf("No. of collisions for type %d is %d\n", i, collisions);
        free_table(table);
    }

}
