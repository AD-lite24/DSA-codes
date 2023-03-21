#include <stdlib.h>
#include <stdio.h>

//INCOMPLETE

typedef struct student{
    long long int ID;
    char name[30];
} Student;

typedef struct ht_item{
    long long int key;
    char name[30];
} ht_item;

typedef struct htable {
    ht_item** items;
    int size;
    int count;
} htable;


int main(){

    FILE* fp = fopen("t1_data.txt", "r");

    int num;
    fscanf(fp, "%d\n", &num);

    Student students[num];
    
    int idx = 0;
    while(!feof(fp)){
        fscanf(fp, "%lld,%[^\n]s", &students[idx].ID, students[idx].name);
    }


}

