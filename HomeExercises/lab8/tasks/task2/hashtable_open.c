#include <stdio.h>
#include <stdlib.h>
#include "hashtable_h.h"
#include <string.h>

//******* Utility functions ******//

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

int probe(htable *table, int index, int size, int type, long long int k)
{
    switch (type)
    {
    case 0:
        return linearProbing(table, index, size, 0, k); // insertion flag set to 0 to indicate searching operation

    case 1:
        return quadraticProbing(table, index, size, 0, k);

    case 2:
        return doubleHashing(table, index, size, 0, k);

    default:
        return -1;
    }
}

//****** Hashtable functions ******//

void free_item(ht_item *item)
{
    // Frees an item.
    free(item->student.name);
    free(item);
}

void free_table(htable *table)
{
    // Frees the table.
    for (int i = 0; i < table->size; i++)
    {
        ht_item *item = table->items[i];
        // printf("Free function id: %lld\n", item->student.ID);
        // printf("Free function name: %s\n", item->student.name);
        if (item != NULL)
            free_item(item);
    }
    
    free(table->items);
    free(table);
}

ht_item *create_item()
{
    ht_item *item = malloc(sizeof(ht_item));
    item->stat = EMPTY;
    item->student.ID = -1;
    item->student.name = malloc(40);
    return item;
}

htable *create_table(int size)
{
    htable *table = malloc(sizeof(htable));
    table->size = size;
    table->items = (ht_item **)calloc(table->size, sizeof(ht_item *));

    for (int i = 0; i < table->size; i++)
        table->items[i] = create_item();

    return table;
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
        return key % prime;
    }

    case 3:
        return mulHash(key, size);

    case 4:
    {
        int prime = findPrime(size * 0.9);
        return key % prime;
    }

    case 5:
        return (key * findPrime(size)) % size;

    default:
        return 0;
        break;
    }
}

int ht_insert(htable *table, Student student, int type)
{
    int index = hashfunction(student.ID, table->size, 3); // Using multiplicative hashfunction
    ht_item *curr_item = table->items[index];

    if (curr_item->stat == EMPTY || curr_item->stat == DELETED) // Good to go
    {
        table->items[index]->student.ID = student.ID;
        // printf("direct student name: %s\n", student.name);
        strcpy(table->items[index]->student.name, student.name);
        // printf("copied student name: %s\n", table->items[index]->student.name);
        table->count++;
        table->items[index]->stat = FILLED;
        return 1;
    }

    else
    {
        int i = 0;
        switch (type)
        {
        case 0:
        {
            index = linearProbing(table, index, table->size, 1, student.ID);
            break;
        }

        case 1:
        {
            index = quadraticProbing(table, index, table->size, 1, student.ID);
            break;
        }

        case 2:
        {
            index = doubleHashing(table, index, table->size, 1, student.ID); // K is the key ie. ID
            break;
        }

        default:
            break;
        }

        if (index < 0)
            return 0;

        else
        {
            table->items[index]->student.ID = student.ID;
            strcpy(table->items[index]->student.name, student.name);
            table->items[index]->stat = FILLED;

            return 1;
        }
    }
}

int ht_delete(htable *table, long long int ID, int type)
{
    int index = hashfunction(ID, table->size, 3); // 3 is type number for multiplicative hash function
    ht_item *curr_item = table->items[index];

    if (type == 1)
    {
        printf("hash done with index %d\n", index);
    }
    if (curr_item->stat == EMPTY)
    {
        printf("Value does not exist\n");
        return 0;
    }

    else if (curr_item->student.ID != ID)
    {
        index = probe(table, index, table->size, type, ID);
        if (index < 0)
        {
            printf("Value does not exist\n");
            return 0;
        }
        else
        {
            curr_item = table->items[index];
            curr_item->stat = DELETED;
            return 1;
        }
    }

    curr_item->stat = DELETED;
    return 1;
}

Student *ht_search(htable *table, long long int ID, int m, int type)
{
    int index = hashfunction(ID, m, 3); // 3 is type number for multiplicative hash function
    ht_item *curr_item = table->items[index];

    if (curr_item->stat == EMPTY)
    {
        printf("Not Found\n");
        return NULL;
    }

    else if (curr_item->student.ID == ID)
    {
        printf("Student with id: %lld found with name: %s\n", ID, curr_item->student.name);
        return &(curr_item->student);
    }

    else
    {
        index = probe(table, index, m, type, ID);
        if (index < 0)
        {
            printf("Not found\n");
            return NULL;
        }
        else
            return &(table->items[index]->student);
    }
}

//****** Probing techniques ******//

// Searching and insertion in the same function separate them out for simplicity
int linearProbing(htable *table, int index, int size, int insertion, long long int k)
{
    int i = 0;
    while (i != size)
    {
        i++;
        index = (index + i) % size;
        ht_item *item = table->items[index];
        if (insertion)
        {
            if (item->stat != FILLED)
                return index;
        }

        //** Searching part **//
        else
        {
            if (item->stat != EMPTY)
            {
                if (item->student.ID == k)
                    return index;
                else
                    continue;
            }
            else
                return -1;
        }

        //** END of searching **//
    }
    printf("Table full\n");
    return -1;
}

int quadraticProbing(htable *table, int index, int size, int insertion, long long int k)
{
    int c1 = 1;
    int c2 = 1;

    int i = 0;
    while (i != size)
    {
        i++;
        index = (index + c1 * i + c2 * i * i) % size;
        ht_item *item = table->items[index];

        if (insertion)
        {
            if (item->stat != FILLED)
                return index;
        }
        else
        {
            if (item->stat == FILLED)
            {
                if (item->student.ID == k)
                    return index;
                else
                    continue;
            }
        }
        
    }
    printf("Table full\n");
    return -1;
}

int doubleHashing(htable *table, int index, int size, int insertion, long long int k) // here index is h1 ie. multiplicative hash index
{
    int i = 0;
    int h2 = 1 + (k % 1023);
    while (i != size)
    {
        i++;
        index = (index + i * h2) % size;
        ht_item *item = table->items[index];

        if (insertion)
        {
            if (item->stat != FILLED)
                return index;
        }
        else
        {
            if (item->stat == FILLED)
            {
                if (item->student.ID == k)
                    return index;
                else
                    continue;
            }
        }
    }
    printf("Table full\n");
    return -1;
}
