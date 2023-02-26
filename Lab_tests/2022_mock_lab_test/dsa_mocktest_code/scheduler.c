#include "scheduler.h"
#include "array_deque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_deque.h"

// The TIME QUANTUM used by this Round Robin Simulator
#define TIME_QUANTUM 3

static void print_stats(process p);

static process **read_processes_from_file(char *filename, int *num_processes_ptr);

/**
 * DO NOT MODIFY THIS FUNCTION
 * Reads the processes from the file in the format Process_Name Process_id Arrival_time CPU_burst
 * subsequently stores the number of processes in the location pointed by num_processes_ptr
 * @return an array of process pointers read from the file
 */
static process **read_processes_from_file(char *filename, int *num_processes_ptr) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    // Read the number of processes from the first line
    int num_processes;
    fscanf(file, "%d", &num_processes);
    *num_processes_ptr = num_processes;

    // Allocate memory for the process pointers
    process **processes = malloc(num_processes * sizeof(process *));
    if (processes == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for processes\n");
        exit(EXIT_FAILURE);
    }

    // Read each process from the file
    for (int i = 0; i < num_processes; i++) {
        process *p = malloc(sizeof(process));
        if (p == NULL) {
            fprintf(stderr, "Error: Failed to allocate memory for process\n");
            exit(EXIT_FAILURE);
        }

        // Read the process data from the file
        char name[32];
        unsigned int pid, arrival, cpu_burst;
        fscanf(file, "%s %u %u %u", name, &pid, &arrival, &cpu_burst);
        p->name = strdup(name);
        p->pid = pid;
        p->arrival = arrival;
        p->cpu_burst = cpu_burst;

        // Initialize the other process fields to 0
        p->turnaround = 0;
        p->wait = 0;
        p->remaining_time = cpu_burst;

        processes[i] = p;
    }

    fclose(file);
    return processes;
}

bool checkIfComplete(int num_of_completions, int num_of_processes, int curr_time){
    if (num_of_completions == num_of_processes) 
        return true;
    return false;
}

void checkArrivalTimes(process** processes, int num_of_processes, linked_deque* ld, int curr_time){
    for (int i = 0; i < num_of_processes; i++){
        process* p = processes[i];
        if (curr_time = p->arrival){
            add_last_linked_deque(ld, *p);
        }
    }
}

process* getProcessFromID(process** processes, int processID, int num_of_processes){
    for (int i = 0; i < num_of_processes; i++){
        if (processes[i]->pid = processID){
            return processes[i];
        }
    }
    return NULL;
}

void visualize_round_robin(char *path) {
    int num_processes;
    process **processes = read_processes_from_file(path, &num_processes);
    
    printf("Number of processes: %d\n", num_processes);
    printf("%-10s%-15s%-15s%-15s%-15s\n", "Process", "Arrival Time", "Burst Time", "Waiting Time", "Turnaround Time");

    linked_deque *ld = create_linked_process_deque();

    // COMPLETE using the ld for storing processes as described

    int t = 0;
    int timeJump = TIME_QUANTUM;
    bool flag = false;
    bool executing = false;
    int pTime = 0;
    
    process* curr_process; 
    int process_id = 0;
    int num_of_completions = 0;

    while(1){

        curr_process = get_front_linked_deque(ld); //updating current process variables
        process_id = curr_process->pid;

        checkArrivalTimes(processes, num_processes, ld, t); //add processes as they arrive

        if (executing){
            //check single process completion and update burst times
            if (curr_process->cpu_burst == 0){
                executing = false;
                // process_index++;
            }
            else{
                curr_process->cpu_burst--;
            }
        }

        if (pTime == timeJump || !executing){
            //move to the next process and deque
            pTime = 0;
            remove_first_linked_deque(ld, curr_process);
            // process_id = get_front_linked_deque(ld)->pid;
            executing = true;
        }

        bool flag = checkIfComplete(num_of_completions, num_processes, t); //check if all processes are done
        if (flag) break;
        t++;

    }


    // Free the allocated memory
    for (int i = 0; i < num_processes; i++) {
        free(processes[i]->name);
        free(processes[i]);
    }
    free(processes);
}



// Prints the stats for the process p to stdout
static void print_stats(process p) {
    printf("%-10s%-15d%-15d%-15d%-15d\n",
           p.name,
           p.arrival,
           p.cpu_burst,
           p.wait,
           p.turnaround);
}