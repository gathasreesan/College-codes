#include <stdio.h>
int main()
{
int i,n,temp=0,awat=0,atat=0;
int at[100],bt[100],ct[100],wt[100],tat[100];
printf("Enter the number of processes");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter arrival time of P%d : ");
scanf("%d",&at[i]);
printf("Enter burst time of P%d:");
scanf("%d",&bt[i]);
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(at[i]>at[j] || (at[i]==at[j] && bt[i]>bt[j]))
{
temp=at[i];
at[i]=at[j];
at[j]=temp;
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
}
}
}
ct[0]=at[0]+bt[0];
wt[0]=0;
for(i=0;i<n;i++)
{
ct[i]=ct[i-1]+bt[i];
wt[i]=ct[i]-at[i]-bt[i];
}
for(i=0;i<n;i++)
{
wt[i]=ct[i-1]-at[i];
tat[i]=wt[i]-bt[i];
}
for(i=0;i<n;i++)
{
awat=awat+wt[i];
atat=atat+tat[i]
  }
   printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n", i, at[i], bt[i], wt[i], tat[i]);
    }
printf("Average waiting time= %d", awat/n);
printf("Average turn around time = %d", atat/n);
}




