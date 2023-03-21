#ifndef HTABLE_H
#define HTABLE_H

typedef struct ht_item
{
    long long int key;
    char name[30];
} ht_item;

typedef struct htable
{
    ht_item **items;
    int size;
    int count;
} htable;

//Create items for the table
ht_item* create_item(long long int key, char* value);

//Create table
htable* create_table(int size);

//Prints the table
void print_table(htable *table);

//Insert into the hashtable
void ht_insert(htable *table, long long int key, char* value);

void free_item(ht_item *item);

void free_table(htable *table);

int hashfunction(long long int key, int size);

#endif