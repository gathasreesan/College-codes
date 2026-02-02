#include <stdio.h>
int main()
{
int n, i,tq;
int at[100],bt[100],tat[100],ct[100],wt[100],rt[100];
printf("Enter the number of processes");
scanf("%d",&n);
printf("Enter time quantum");
scanf("%d",&tq);
for(i=0;i<n;i++)
{
printf("Enter arrival time of P%d",i);
scanf("%d",&at[i]);
printf("Enter burst time of P%d",i);
scanf("%d",&bt[i]);
}
for(i=0;i<n;i++)
{
rt[i]=bt[i]; //copying burst time
}
int time = 0, completed = 0;
while(completed < n)
{
for(int i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    completed++;
                }
            }
        }
    }
 float avgWT = 0, avgTAT = 0;

    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgWT/n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT/n);

    return 0;
}

