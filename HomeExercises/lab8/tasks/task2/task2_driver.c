#include <stdlib.h>
#include <stdio.h>
#include "hashtable_h.h"
#include <string.h>
#define TABLE_SIZE 1024

// All four probing techniques used in a single program

// Wrappers for the operations
void insert(htable *table, long long int ID, char *name, int type);
void delete(htable *table, long long int ID, int type);
Student *search(htable *table, long long int ID, int type);

// Helper functions
Student createStudentItem(long long int ID, char *name);

int main()
{

    FILE *fp = fopen("../task1/t1_data.txt", "r"); // Change filepath as needed

    int num;
    fscanf(fp, "%d\n", &num);

    Student students[num];
    

    int idx = 0;
    while (!feof(fp))
    {
        students[idx].name = malloc(30);
        fscanf(fp, "%lld,%[^\n]s", &students[idx].ID, students[idx].name);
        idx++;
    }

    fclose(fp);

    int num_types = 3; // 3 types of open addressing techniques

    for (int i = 0; i < num_types; i++) // For all open addressing techniques, do the same operations for each
    {
        printf("Starting %d type\n", i);
        htable *table = create_table(TABLE_SIZE);
        for (int j = 0; j < num; j++)
            ht_insert(table, students[j], i); // Populating the hashtable initially

        FILE *fq = fopen("t1_queries.txt", "r");
        char *buffer = malloc(40);
        while (fgets(buffer, 40, fq))
        {
            int op = atoi(strtok(buffer, ","));
            printf("%d\n", op);
            switch (op)
            {
            case 1:
            {
                char* ID_string = strtok(NULL, ",");
                long long int ID = atoll(ID_string);
                char *name = malloc(30);
                name = strtok(NULL, ",");
                insert(table, ID, name, i);
                break;
            }

            case 2:
            {
                char* ID_string = strtok(NULL, ",");
                long long int ID = atoll(ID_string);
                delete(table, ID, i);
                break;
            }

            case 3:
            {   
                char* ID_string = strtok(NULL, ",");
                int ID = atoi(ID_string);
                Student* student = search(table, ID, i);
                break;
            }

            default:
                break;
            }
        }

        printf("Finished with %d type\n", i);
        free_table(table);
        fclose(fq);

    }
}

Student createStudentItem(long long int ID, char *name)
{
    Student student;
    student.ID = ID;
    student.name = name;
    return student;
}

void insert(htable *table, long long int ID, char *name, int type)
{
    Student student = createStudentItem(ID, name);
    ht_insert(table, student, type);
}

void delete(htable* table, long long int ID, int type)
{
    ht_delete(table, ID, type);
}

Student* search(htable* table, long long int ID, int type)
{
    return ht_search(table, ID, table->size, type);
}