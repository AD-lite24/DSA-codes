#include <stdlib.h>
#include <stdio.h>

typedef struct data{
    int index;
    char word[50];
}Data;

void readFileUsingFscanf(FILE* fp, Data* msgs){
    int i = 0;
    while(!feof(fp)){
        fscanf(fp, "%d", &(msgs[i].index));
        fscanf(fp, ",%s\n", msgs[i].word);
        i++;
    }
}

Data* counting_sort(Data* msgs, Data* output, int n){

    int* C = calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++)
        C[msgs[i].index]++;
    
    int run_sum = 0;
    
    for (int i = 0; i < n; i++){
        run_sum += C[i];
        C[i] = run_sum;
    }

    for (int i = n - 1; i >= 0; i--){
        Data data = msgs[i];
        output[C[data.index] - 1] = data;
        C[data.index]--;
    }

}

int main(){

    FILE* fp = fopen("2001.csv", "r");

    int n = 112;
    
    Data* msgs = calloc(112, sizeof(Data)); //112 words in the file
    readFileUsingFscanf(fp, msgs);
    
    Data* output = calloc(n, sizeof(Data));

    counting_sort(msgs, output, n);

    for (int i = 0; i < n; i++)
        printf("%s ", output[i].word);


}