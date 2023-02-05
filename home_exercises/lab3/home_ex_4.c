#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include <string.h>

int main(){
    FILE* fp;
    fp = fopen("fcfs_input.txt", "r");

    if(fp == NULL){
        printf("Error opening file!");
        exit(1); 
    }
    
    char* num_line = malloc(10);
    fgets(num_line, 8, fp);
    int num = (int)*num_line - 48;

    Process arrProc[num];
    Process process;
    Queue* q = createQueue(); 
    for(int i = 0; fgets(num_line, 8, fp); i++){
        
        char* token = malloc(50);
        token = strtok(num_line, " ");
        
        process.pid = atoi(token);
        token = strtok(NULL, " ");
        
        process.arrival_time = atoi(token);
        token = strtok(NULL, " ");
        
        process.burst_time = atoi(token);
        arrProc[i] = process;

        
    }

    int t = 0;
    bool flag = true;
    bool executing = false;
    int numOfProc = 0;
    while(flag){

        if (numOfProc == num){
            printf("All processes finished executing");
            break;
        }

        Process p;
        for (int i = 0; i < num; i++){
            p = arrProc[i];
            if (p.arrival_time == t) enqueue(q, p);
        }

        if(executing){
            if (front(q)->burst_time == 1){
                printf("Process %d has finished executing at time %d\n", front(q)->pid, t);
                dequeue(q);
                executing = false;
                numOfProc++;
            }
            else{
                front(q)->burst_time--;
            }    
        }

        if (!isEmpty(q) && !executing){
            executing = true;
            printf("Process %d started at time %d\n", front(q)->pid, t);
        }
        
        t++;
    }

}