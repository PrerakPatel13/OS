#include <stdio.h>
#include <stdlib.h>

int rear = -1, front = -1, queue[100], max = 20;

void enque(int val)
{
    if (rear == max - 1)
    {
        printf("Queue is full ");
        exit;
    }
    else if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = val;
}

int deque()
{
    int val = queue[front];
    if (front == -1)
    {
        printf("Queue underflow ");
        exit;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
    return val;
}
int main()
{
    int x[10], i, j, tq, processId, highest = 0, count = 0, time = 0, ctr = 0, n, ganLen = 1, index = 0;
    int gp[100] = {1};
    int gid[100] = {-1};
    double wat = 0, tt = 0, end;
    int tat[100], wt[100], ct[100],bt[100],at[100],pid[100];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the arrival time and burst time of the processes:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d = ", i+1);
        scanf("%d", &at[i]);
        pid[i]=i+1;
        scanf("%d", &bt[i]);
        x[i] = bt[i];
    }
    printf("Enter the time quantum: ");
    scanf("%d", &tq);
    enque(at[0]);
    gp[0] = at[0];
    while (count != n)
    {
        processId = queue[front];

        for (i = 0; i < n; i++)
        {
            if (at[i] == processId)
            {
                index = i;
            }
        }

        gid[ctr] = pid[index];

        if (bt[index] <= tq)
        {
            time = time + bt[index];
            bt[index] = 0;
            count++;
            for (i = 0; i < n; i++)
            {
                if (at[i] > index && at[i] <= time && bt[i] != 0 && at[i] > highest)
                {
                    enque(at[i]);
                    highest = at[i];
                }
            }
            int p = deque();
            ganLen--;
            ct[index] = time;

            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - x[index];

            wat = wat + wt[index];
            tt = tt + tat[index];
        }
        else
        {
            bt[index] = bt[index] - tq;
            time = time + tq;
            for (i = 0; i < n; i++)
            {
                if (at[i] > index && at[i] <= time && bt[i] != 0 && at[i] > highest)
                {
                    enque(at[i]);
                    highest = at[i];
                }
            }
            int p = deque();
            enque(p);
        }
        gp[ctr+1] = time;
        ctr++;
    }


    printf("\nGantt Chart\n\n");
    for (int i = 0; i < ctr; i++)
    {
        printf("     P%d\t", gid[i]);
    }
    printf("\n");
    for (int i = 0; i < ctr+1; i++)
    {
        printf("%d\t ", gp[i]);
    }
    printf("\n\n");

    printf("Process\tArrivalTime\tBurstTime\tCompletionTime\tTurnAroundTime\tWaitingTime\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], x[i], ct[i], tat[i], wt[i]);
    }

    printf("\n\nAverage waiting time = %lf\n", wat / n);
    printf("Average Turnaround time = %lf\n\n", tt / n);
}