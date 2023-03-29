#include <stdio.h>

#define MAX_PROCESS 10

struct process {
    int pid;
    int burst_time;
    int remaining_time;
};

int main() {
    int num_processes, time_quantum, total_time = 0;
    struct process p[MAX_PROCESS];

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    for (int i = 0; i < num_processes; i++) {
        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
        p[i].pid = i+1;
        total_time += p[i].burst_time;
    }

    printf("Enter the time slice: ");
    scanf("%d", &time_quantum);

    int current_time = 0;
    do {
        for (int i = 0; i < num_processes; i++) {
            if (p[i].remaining_time > 0) {
                int time_executed = p[i].remaining_time > time_quantum ? time_quantum : p[i].remaining_time;
                current_time += time_executed;
                p[i].remaining_time -= time_executed;
                printf("Process %d executed for %d seconds. Remaining time: %d\n", p[i].pid, time_executed, p[i].remaining_time);
            }
        }
    } while (current_time < total_time);

    return 0;
}

