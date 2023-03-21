#include <stdlib.h>
#include <stdio.h>
#include "hashtable_h.h"
#include <string.h>

ht_item *create_item(long long int key, char* value){

    ht_item* item = malloc(sizeof(ht_item));
    item->key = key;
    strcpy(item->name, value);

    return item;
}

int hashfunction(long long int key, int size){
    return key%size;
}

void print_table(htable* table){
    for (int i = 0; i < table->size; i++)
    {
        if (table->items[i])
        {
            printf("Index:%d, Key:%lld, Value:%s\n", i, table->items[i]->key, table->items[i]->name);
        }
    }
}

htable *create_table(int size){

    htable* table = malloc(sizeof(htable));
    table->size = size;
    table->items = (ht_item**)calloc(table->size, sizeof(ht_item *));

    for (int i = 0; i < table->size; i++)
        table->items[i] = NULL;

    return table;
}

void free_item(ht_item *item)
{
    // Frees an item.
    free(item->name);
    free(item);
}

void free_table(htable *table)
{
    // Frees the table.
    for (int i = 0; i < table->size; i++)
    {
        ht_item* item = table->items[i];

        if (item != NULL)
            free_item(item);
    }

    free(table->items);
    free(table);

}

void ht_insert(htable *table, long long int key, char *value){

    ht_item* item = create_item(key, value);

    int index = hashfunction(key, table->size);

    ht_item* curr_item = table->items[index];

    //No collision resolution applied here 

    if (curr_item == NULL)
    {
        // Key does not exist.
        if (table->count == table->size)
        {
            // HashTable is full.
            printf("Insert Error: Hash Table is full\n");
            free_item(item);
            return;
        }

        // Insert directly.
        table->items[index] = item;
        table->count++;
    }

    else{

        if (curr_item->key == key)
        {
            strcpy(table->items[index]->name, value);
            return;
        }
    }
}
