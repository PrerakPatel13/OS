#include <stdio.h>

int main()
{
    int n, i, tq, time = 0;
    float awt = 0, atat = 0;
    int at[10], bt[10], wt[10], tat[10], copy[10], rt[10], ct[10], flag[10] = {0};

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the arrival time of the processes:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d = ", i);
        scanf("%d", &at[i]);
    }

    printf("Enter the burst time of the processes:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d = ", i);
        scanf("%d", &bt[i]);
        copy[i] = bt[i];
        rt[i] = bt[i];
    }

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    printf("\nGantt Chart:\n");
    printf("|");

    while (1)
    {
        int done = 1;

        for (i = 0; i < n; i++)
        {
            if (rt[i] > 0)
            {
                done = 0;

                if (rt[i] > tq)
                {
                    time += tq;
                    rt[i] -= tq;
                    printf(" P%d |", i);
                }
                else
                {
                    time += rt[i];
                    printf(" P%d |", i);
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = ct[i] - bt[i] - at[i];
                    rt[i] = 0;
                }
            }
        }

        if (done == 1)
            break;
    }

    printf("\n");
    printf("0");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", ct[i]);
    }
    printf("\n\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (i = 0; i < n; i++)
    {
        awt += wt[i];
        atat += tat[i];
        printf("\nP%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d", i, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    awt /= n;
    atat /= n;

    printf("\n\nAverage Waiting Time = %f\n", awt);
    printf("Average Turnaround Time = %f\n", atat);

    return 0;
}
