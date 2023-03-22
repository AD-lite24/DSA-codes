#ifndef HTABLE_H
#define HTABLE_H

enum status {FILLED, EMPTY, DELETED};

typedef struct student
{
    long long int ID;
    char name[30];
} Student;

typedef struct ht_item
{
    Student student;
    enum status stat;
} ht_item;

typedef struct htable
{
    ht_item **items;
    int size;
    int count;
} htable;

//Create empty items for the table to initialize
ht_item* create_item();

//Create table
htable* create_table(int size);

//Prints the table
void print_table(htable *table);

//Insert into the hashtable and return 
int ht_insert(htable *table, Student student, int type);

void free_item(ht_item *item);

void free_table(htable *table);

int hashfunction(long long int key, int size, int type);

Student* ht_search(ht_item *table, long long int ID, int m, int type);

#endif