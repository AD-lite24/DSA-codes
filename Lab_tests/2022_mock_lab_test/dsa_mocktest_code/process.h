#ifndef DSA_PROCESS_H
#define DSA_PROCESS_H
typedef struct process {
    char *name;
    unsigned int pid;
    unsigned int arrival;
    unsigned int cpu_burst;
    unsigned int turnaround;
    unsigned int wait;
    unsigned int remaining_time;
} process;
#endif //DSA_PROCESS_H
