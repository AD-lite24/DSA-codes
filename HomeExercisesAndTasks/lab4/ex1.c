#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
} Person;

void sortAccordingToName(Person arr[], int lenght);

int main(){
    Person arr[5];
    Person p1 = {.id = 1, .name = "Soka", .age = 15, .height = 150, .weight = 45};
    arr[0] = p1;
    Person p2 = {.id = 2, .name = "Ang", .age = 1126, .height = 137, .weight = 35};
    arr[1] = p2;
    Person p3 = {.id = 3, .name = "Zuko", .age = 16, .height = 160, .weight = 50};
    arr[2] = p3;
    Person p4 = {.id = 4, .name = "Katara", .age = 14, .height = 145, .weight = 38};
    arr[3] = p4;
    Person p5 = {.id = 5, .name = "Toph", .age = 12, .height = 113, .weight = 30};
    arr[4] = p5;

    for (int i = 0; i < 5; i++){
        printf("%s\n", arr[i].name);
    }
    //Sort in lexicographic order according to names using insertions sort
    sortAccordingToName(arr, 5);

    for (int i = 0; i < 5; i++){
        printf("%s\n", arr[i].name);
    }
}

void sortAccordingToName(Person arr[], int length){
    for (int i = 1; i < length; i++){
        int j = i - 1;

        Person key = arr[i];
        
        while (j >= 0 && strcmp(arr[j].name, key.name) > 0){
            arr[j+1] = arr[j];
            j--;
        }
        printf("Key was: %s\n", key.name);
        arr[j+1] = key;
    }
}

