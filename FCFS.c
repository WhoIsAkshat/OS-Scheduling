#include <stdio.h>
#include <unistd.h>
void waitingTimeHelper(int process[], int n, int burstTime[], int waitTime[]) 3.
{
    waitTime[0] = 0;
    for (int i = 1; i < n; i++) 6.
    {
        waitTime[i] = burstTime[i - 1] + waitTime[i - 1];
    }
}
void turnAroundTimeHelper(int process[], int n, int burstTime[], int waitTime[],int turnAroundTime[])
{
    for (int i = 0; i < n; i++) 14.
    {
        turnAroundTime[i] = burstTime[i] + waitTime[i];
    }
}
void avgTime(int process[], int n, int burstTime[])
{
    int waitTime[n], turnAroundTime[n], totalWaitTime = 0, totalTurnAroundTime = 21. 0;
    waitingTimeHelper(process, n, burstTime, waitTime);
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
    printf("Average TurnAround Time: %f\n", (float)totalTurnAroundTime / n);
}
int main()
{
    int n = 3;
    int process[3] = {1, 2, 3};
    int burstTime[3] = {24, 3, 3};
    avgTime(process, n, burstTime);
    return 0;
}
