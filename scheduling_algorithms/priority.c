// C program for implementation of Priority scheduling algorithm

#include <stdio.h>

struct process
{
  int id;
  int burstTime;
  int priority;
};

void priority_scheduling(struct process processes[], size_t n)
{
  // 1. Sorting based on priority in ascending order
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (processes[j].priority > processes[j + 1].priority)
      {
        struct process temp = processes[j];
        processes[j] = processes[j + 1];
        processes[j + 1] = temp;
      }
    }
  }

  // 2. Calculate waiting time for each process
  // Waiting time = Burst time of prev process + Waiting time of prev process
  int waitingTime[n];
  waitingTime[0] = 0;
  for (int i = 1; i < n; i++)
  {
    waitingTime[i] = processes[i - 1].burstTime + waitingTime[i - 1];
  }

  // 3. Calculating turn-around time for each process
  int turnAroundTime[n];
  for (int i = 0; i < n; i++)
  {
    turnAroundTime[i] = processes[i].burstTime + waitingTime[i];
  }

  // 4. Calculating avg w_time and ta_time
  float avgWaitingTime = 0, avgTurnAroundTime = 0;
  for (int i = 0; i < n; i++)
  {
    avgWaitingTime += waitingTime[i];
    avgTurnAroundTime += turnAroundTime[i];
  }

  avgWaitingTime /= n;
  avgTurnAroundTime /= n;

  // 5. Print details
  printf("\nProcess ID\tPriority\tBurst Time\tWaiting Time\tTurn Around Time\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].priority, processes[i].burstTime, waitingTime[i], turnAroundTime[i]);
  }
  printf("Average Waiting time : %.2f", avgWaitingTime);
  printf("\nAverage Turn-around time : %.2f", avgTurnAroundTime);
}

int main()
{
  size_t n;
  printf("Enter the number of processes : ");
  scanf("%d", &n);
  struct process processes[n];
  printf("\nEnter the process details - \n");
  for (int i = 0; i < n; i++)
  {
    printf("\nPROCESS %d\n", i + 1);
    processes[i].id = i + 1;
    printf("Burst time : ");
    scanf("%d", &processes[i].burstTime);
    printf("Priority : ");
    scanf("%d", &processes[i].priority);
  }

  priority_scheduling(processes, n);
  return 0;
}