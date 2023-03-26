#include <stdlib.h>
#include <stdio.h>

typedef struct bitsian
{
char name[40];
char rollno[15];
} bitsian;

int main(){
    
    FILE* fp = fopen("bitsian.csv", "r");
    printf("%p\n", fp);

    int num_of_students;

    fscanf(fp, "%d", &num_of_students);

    bitsian arr[num_of_students];

    for (int i = 0; i < num_of_students; i++){
        fscanf(fp, "%[^,],%[^\n]\n", arr[i].rollno, arr[i].name);
    }

    //INCOMPLETE

}
