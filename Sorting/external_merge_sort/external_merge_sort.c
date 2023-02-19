#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "merge_sort.h"
#include <math.h>

Person* readCsv(FILE* fp, int length);
void sortArr(Person arr[], int length);
void writeToCSV(Person arr[], int length, int idx);
void externalMerge(int numf);
void mergeFiles(FILE *in1, FILE *in2, FILE *out);

int main(){

    FILE* fp = fopen("dat7578440.csv", "r");

    printf("starting\n");
    int sizeEntries = 8;
    
    while(sizeEntries--){
        if (sizeEntries == 0){
            Person* pArr = readCsv(fp, 578440);
            sortArr(pArr, 578440);
            writeToCSV(pArr, 578440, 8 - sizeEntries);
        }
        else{
            Person* pArr = readCsv(fp, 1000000);
            sortArr(pArr, 1000000);
            writeToCSV(pArr, 1000000, 8 - sizeEntries);
        }
    }
    fclose(fp);
    externalMerge(8);
}

Person* readCsv(FILE* fp, int length){
    Person* pArr = (Person*)malloc(length*sizeof(struct person));

    char buffer[1024];
   
    for (int i = 0; i < length; i++){

        Person p;
        p.name = (char*)malloc(30);

        fgets(buffer, 1024, fp); //used fgets here and fscanf later on for variety`
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


    FILE* fp = fopen(name, "w+");

    int i;
    for (i = 0; i < length; i++){
    
        fprintf(fp, "%d,%s,%d,%d,%d\n", arr[i].id, arr[i].name, arr[i].age, arr[i].height, arr[i].weight);
    }

    fclose(fp);

}

void sortArr(Person arr[], int length){

    merge_sort(arr, length);
}

void externalMerge(int numf){

    FILE* in[numf]; //array of all the file pointers
    //NOTE: Storing array of file names would be better 

    for (int i = 1; i <= numf; i++){
        char file_name[20] = "filex.csv";
        file_name[4] = i + '0';
        FILE* fp = fopen(file_name, "r+");
        in[i-1] = fp;
    }

    //final output in file1.csv

    int numMergedChunks = numf;
    printf("num of chunks: %d\n", numMergedChunks);


    while (numMergedChunks != 1){

        int i;
        for (i = 0; i < 8; i += (int)pow(2, 8/numMergedChunks)) {  //algorithm can be simpler
            FILE *in1 = in[i];
            FILE *in2 = in[i + (int)pow(2, 4/numMergedChunks)];
            FILE *out = tmpfile();

            printf("in1: %d, in2: %d\n", i, i + (int)pow(2, 4/numMergedChunks));
            mergeFiles(in1, in2, out);

            fclose(in[i]);
            char filename[20] = "filex.csv";
            filename[4] = i + 1 + '0';
            FILE* fp = fopen(filename, "w+");
            rewind(out);
            char c = fgetc(out);
            while (c != EOF)
            {
                fputc(c, fp); //TO DO: copying files; major inefficiency, make new file instead of copying
                c = fgetc(out);
            }
            rewind(fp);
            in[i] = fp;
            in[i + (int)pow(2, 4/numMergedChunks)] = NULL;
            fclose(out);
        }


        if (numMergedChunks % 2 != 0) {
            // Special case for odd number of chunks
            in[numMergedChunks - 1] = in[numMergedChunks - 2];
            in[numMergedChunks - 2] = NULL;
        }
        printf("before: %d\n", numMergedChunks);
        numMergedChunks = (numMergedChunks + 1) / 2;
        printf("after: %d\n", numMergedChunks);
    }


}

void mergeFiles(FILE *in1, FILE *in2, FILE *out) {

    Person p1, p2;
    p1.name = malloc(30);
    p2.name = malloc(30);
    rewind(in1);
    rewind(in2);

    fscanf(in1, "%d,%[^,],%d,%d,%d", &p1.id, p1.name, &p1.age, &p1.height, &p1.weight);
    fscanf(in2, "%d,%[^,],%d,%d,%d", &p2.id, p2.name, &p2.age, &p2.height, &p2.weight);

    while (!feof(in1) && !feof(in2)) {

        if (p1.height < p2.height) {
            fprintf(out, "%d,%s,%d,%d,%d\n", p1.id, p1.name, p1.age, p1.height, p1.weight);
            fscanf(in1, "%d,%[^,],%d,%d,%d", &p1.id, p1.name, &p1.age, &p1.height, &p1.weight);
        } 
        else {
            fprintf(out, "%d,%s,%d,%d,%d\n", p2.id, p2.name, p2.age, p2.height, p2.weight);
            fscanf(in2, "%d,%[^,],%d,%d,%d", &p2.id, p2.name, &p2.age, &p2.height, &p2.weight);
        }
    }

    while (!feof(in1)) {
        fprintf(out, "%d,%s,%d,%d,%d\n", p1.id, p1.name, p1.age, p1.height, p1.weight);
        fscanf(in1, "%d,%[^,],%d,%d,%d", &p1.id, p1.name, &p1.age, &p1.height, &p1.weight);
    }

    while (!feof(in2)) {
        fprintf(out, "%d,%s,%d,%d,%d\n", p2.id, p2.name, p2.age, p2.height, p2.weight);
        fscanf(in2, "%d,%[^,],%d,%d,%d", &p2.id, p2.name, &p2.age, &p2.height, &p2.weight);
    }

    rewind(in1);
    rewind(in2);
}