#include <stdio.h>

int main()
{
    int i, j, n;
    int temp;
    int at[100], bt[100], ct[100], wt[100], tat[100], pr[100];
    int pid[100];
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        printf("\nProcess P%d\n", i+1);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Priority (Lower number = Higher priority): ");
        scanf("%d", &pr[i]);
    }

    // Sort by Arrival Time first, then by Priority
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(at[i] > at[j] || 
              (at[i] == at[j] && pr[i] > pr[j]))
            {
                // Swap AT
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap BT
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap Priority
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                // Swap PID
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Completion Time calculation
    ct[0] = at[0] + bt[0];

    for(i = 1; i < n; i++)
    {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    // WT and TAT calculation
    for(i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        awt += wt[i];
        atat += tat[i];
    }

    // Output
    printf("\nProcess\tAT\tBT\tPR\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pr[i],
               ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", awt/n);
    printf("\nAverage Turnaround Time = %.2f\n", atat/n);

    return 0;
}
