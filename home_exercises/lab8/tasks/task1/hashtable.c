#include <stdlib.h>
#include <stdio.h>
#include "hashtable_h.h"
#include <string.h>

ht_item *create_item(long long int key, char *value)
{

    ht_item *item = malloc(sizeof(ht_item));
    item->name = malloc(30);
    item->key = key;
    strcpy(item->name, value);

    return item;
}

int isPrime(int X)
{
    for (int i = 2; i * i <= X; i++)
        if (X % i == 0) // Factor found
            return 0;
    return 1;
}

int findPrime(int x)
{
    for (int j = x - 1;; j--)
        if (isPrime(j))
            return j;
}

int mulHash(long long int key, int size)
{
    double A = 0.6180339887;
    double frac = key * A - (int)(key * A);
    return (int)(size * frac);
}

int hashfunction(long long int key, int size, int type)
{

    switch (type)
    {

    case 0:
        return key % size;

    case 1:
    {
        int power2 = 1;
        while (power2 * 2 < size)
            power2 *= 2;
        return key % power2; // ID % power_of_2_just_less_than_size
    }

    case 2:
    {
        int prime = findPrime(size);
        return key%prime;
    }

    case 3:
        return mulHash(key, size);

    case 4:
    {
        int prime = findPrime(size*0.9);
        return key%prime;
    }

    case 5:
        return (key*findPrime(size))%size;
        
    default:
        return 0;
        break;
    }
}

void print_table(htable *table)
{
    for (int i = 0; i < table->size; i++)
    {
        if (table->items[i])
        {
            printf("Index:%d, Key:%lld, Value:%s\n", i, table->items[i]->key, table->items[i]->name);
        }
    }
}

htable *create_table(int size)
{

    htable *table = malloc(sizeof(htable));
    table->size = size;
    table->items = (ht_item **)calloc(table->size, sizeof(ht_item *));

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
        ht_item *item = table->items[i];

        if (item != NULL)
            free_item(item);
    }

    free(table->items);
    free(table);
}

int ht_insert(htable *table, long long int key, char *value, int type)
{

    ht_item *item = create_item(key, value);

    int index = hashfunction(key, table->size, type);

    ht_item *curr_item = table->items[index];

    // No collision resolution applied here

    if (curr_item == NULL)
    {
        // Key does not exist.
        if (table->count == table->size)
        {
            // HashTable is full.
            printf("Insert Error: Hash Table is full\n");
            free_item(item);
            return 0;
        }

        // Insert directly.
        table->items[index] = item;
        table->count++;
        return 1;
    }

    else
    {
        // Same key so update value
        if (curr_item->key == key)
        {
            strcpy(table->items[index]->name, value);
            return 1;
        }
        //collision condition, return false
        else return 0;
    }
}

