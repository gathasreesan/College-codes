#include <stdio.h>
int maxv(int a,int b){
if(a>b){
return a;
}
else{
return b;
}
}
int main(){
int n,m,i,j;
printf("ENTER THE NO OF ITEMS :");
scanf("%d",&n);
printf("ENTER THE CAPACITY OF THE KNAPSACK:");
scanf("%d",&m);
int dp[n+1][m+1];
int w[n],p[n],k[n];
printf("ENTER THE WEIGHT OF THE ITEMS:");
for(i=0;i<n;i++){
scanf("%d",&w[i]);
}
printf("ENTER THE PROFIT OF THE ITEMS:");
for(i=0;i<n;i++){
scanf("%d",&p[i]);
}
for(i=0;i<=n;i++){
for(j=0;j<=m;j++){
if(i==0||j==0){
dp[i][j]=0;
}
else if(w[i-1]<=j){
dp[i][j]=maxv(p[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
}
else{
dp[i][j]=dp[i-1][j];
}
}
}
printf("TABLE:\n");
for(i=0;i<=n;i++){
for(j=0;j<=m;j++){
printf("%d ",dp[i][j]);
}
printf("\n");
}
printf("MAX PROFIT:%d\n",dp[n][m]);
for(i=0;i<n;i++){
k[i]=0;
}
printf("SELECTED ITEMS:\n");
i=n;
j=m;
while(i>0&&j>0){
if(dp[i][j]!=dp[i-1][j]){
k[i-1]=1;
j=j-w[i-1];
}
i--;
}
for(i=0;i<n;i++){
printf("%d ",k[i]);
}
return 0;
}
