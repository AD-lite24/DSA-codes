#ifndef MERGE_H
#define MERGE_H

typedef struct person{
    int id;
    char *name;
    int age;
    int height;
    int weight;
} Person;

void merge_sort(Person a[], int length);
void merge_sort_recursion(Person a[], int l, int r);
void merge_sorted_arrays(Person a[], int l, int m, int r);

#endif
