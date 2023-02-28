#include <stdlib.h>
#include <stdio.h>

typedef struct bitsian
{
char name[20];
char rollno[15];
}bitsian;

int main(){
    
    FILE* fp = fopen("text.txt", "r");

    int num_of_students;

    fscanf(fp, "%d\n", &num_of_students);
    // printf("%d\n", num_of_students);
}
