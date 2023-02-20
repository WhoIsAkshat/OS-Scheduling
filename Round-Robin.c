#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
void waitingTimeHelper(int process[], int n, int burstTime[], int waitTime[], int quantum)
{
    int remBurstTime[n];
    for (int i = 0; i < n; i++)
    {
        remBurstTime[i] = burstTime[i];
    }
    int t = 0;
    while (true)
    {
        bool done = true;
        for (int i = 0; i < n; i++)
        {
            if (remBurstTime[i] > 0)
            {
                done = false;
                if (remBurstTime[i] > quantum)
                {
                    t += quantum;
                    remBurstTime[i] -= quantum;
                }
                else
                {
                    t += remBurstTime[i];
                    waitTime[i] = t - burstTime[i];
                    remBurstTime[i] = 0;
                }
            }
        }
        if (done)
            break;
    }
}
void turnAroundTimeHelper(int process[], int n, int burstTime[], int waitTime[],
                          int turnAroundTime[])
{
    for (int i = 0; i < n; i++)
    {
        turnAroundTime[i] = burstTime[i] + waitTime[i];
    }
}
void avgTime(int process[], int n, int burstTime[], int quantum)
{
    int waitTime[n], turnAroundTime[n], totalWaitTime = 0, totalTurnAroundTime = 0;
    waitingTimeHelper(process, n, burstTime, waitTime, quantum);
    turnAroundTimeHelper(process, n, burstTime, waitTime, turnAroundTime);
    printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        totalWaitTime += waitTime[i];
        totalTurnAroundTime += turnAroundTime[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], waitTime[i],
               turnAroundTime[i]);
    }
    printf("Average Waiting Time: %f\n", (float)totalWaitTime / n);
    printf("Average Turnaround Time: %f\n", (float)totalTurnAroundTime / n);
}
int main()
{
    int n = 6;
    int process[6] = {1, 2, 3, 4, 5, 6};
    int burstTime[6] = {3, 4, 2, 5, 3, 6};
    int quantum = 2;
    avgTime(process, n, burstTime, quantum);
    return 0;
}
