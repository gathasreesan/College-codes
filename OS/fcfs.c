#include <stdio.h>
int main()
{
  int n, i;
printf(Enter the number of processes");
scanf("%d",&n);
int at[100], bt[100],ct[100], wt[100], tat[100];
printf("Enter arrival time and burst time");
for(i=0; i<n ;i++)
{
scanf("%d %d",&at[i],&bt[i]);
}
ct[0]=at[0]+bt[0];
for(i=0;i<n;i++)
{
ct[i]=ct[i-1]+bt[i];
}
for(i=0;i<n;i++)
{
tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];
}
for(i = 0; i < n; i++)
        printf("P%d WT=%d TAT=%d\n", i, wt[i], tat[i]);

    return 0;
}





