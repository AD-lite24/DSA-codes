#include <stdio.h>
#include <stdlib.h>
#include "hashtable_h.h"

int main(){

    int size = 10;
    htable* table = create_table(size);

    ht_insert(table, 123456789, "test1");
    ht_insert(table, 696969696, "test2");
    ht_insert(table, 666669990, "test_f");

    print_table(table);
}