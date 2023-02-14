#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "merge_sort.h"

// typedef struct person{
//     int id;
//     char *name;
//     int age;
//     int height;
//     int weight;
// } Person;

Person* readCsv(FILE* fp, int length);
void sortArr(Person arr[], int length);
void writeToCSV(Person arr[], int length, int idx);

int main(){

    FILE* fp = fopen("dat7578440.csv", "r");

    printf("starting\n");
    int sizeEntries = 8;
    
    while(sizeEntries--){
        if (sizeEntries == 0){
            Person* pArr = (Person*)malloc(578441*sizeof(struct person));
            pArr = readCsv(fp, 578441);
            writeToCSV(pArr, 578441, 8 - sizeEntries);
        }
        else{
            printf("int the loop at idx %d\n", 8-sizeEntries);
            Person* pArr = (Person*)malloc(1000000*sizeof(struct person));
            printf("allocaton done\n");
            
            pArr = readCsv(fp, 1000000);
            printf("func1 done \n");
            sortArr(pArr, 1000000);
            printf("func2 done \n");
            writeToCSV(pArr, 1000000, 8 - sizeEntries);
            printf("funk3 done \n");
        }
    }

}

Person* readCsv(FILE* fp, int length){
    Person* pArr = (Person*)malloc(1000000*sizeof(struct person));
    printf("arr allocation\n");
    char buffer[1024];
    for (int i = 0; i < length; i++){
        Person p;
        p.name = (char*)malloc(30);
        fgets(buffer, 1024, fp);
        char* value = strtok(buffer, ",");
        p.id = atoi(value);
        value = strtok(NULL, ",");
        strcpy(p.name, value);
        value = strtok(NULL, ",");
        p.age = atoi(value);
        value = strtok(NULL, ",");
        p.height = atoi(value);
        value = strtok(NULL, ",");
        p.weight = atoi(value);
        pArr[i] = p;
    }

    return pArr;
}

void writeToCSV(Person arr[], int length, int idx){
    char append = (idx + '0');
    char name[10] = "filex.csv";
    name[4] = append;
    // printf("test\n");

    FILE* fp = fopen(name, "w+");
    // printf("hello\n");
    for (int i = 0; i < length; i++){
    
        fprintf(fp, "%d, %s, %d, %d, %d\n", arr[i].id, arr[i].name, arr[i].age, arr[i].height, arr[i].weight);
    }
    fclose(fp);
}

void sortArr(Person arr[], int length){
    printf("inside interface\n");
    merge_sort(arr, length);
}