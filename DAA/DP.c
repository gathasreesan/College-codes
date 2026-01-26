#include <stdio.h>
#include <math.h>
int knapsack()
{
int n,w,i,j;
printf("Enter number of objects");
scanf("%d",&n);
printf("Enter maximum weight");
scanf("%d",&w);
int dp[n+1][w];
int wt[n],p[n];
printf("Enter weights ");
for(i=0;i<n;i++)
{
scanf("%d",&wt[i]);
}
printf("Enter profits");
for(i=0;i<n;i++)
{
scanf("%d",&p[i]);
}
for(i=0;i<n;i++)
{
for(j=0;j<w;j++)
{
if(i==0||j==0)
{
dp[i][j]=0;
}
else if (wt[i-1]<=w)
{
dp[i][j] = (int)fmax(p[i-1] + dp[i-1][j-wt[i-1]],dp[i-1][j]);
}
else
{
dp[i][j]=dp[i-1][w];
}
}
}
printf("DP TABLLE\n");
for(i=0;i<n;i++)
{
for(j=0;j<w;j++)
{
printf("%d",dp[i][j]);
}
printf("\n");
}
return dp[n][w];
}
int main()
{
int result = knapsack();
    printf("Maximum Profit = %d", result);
}
