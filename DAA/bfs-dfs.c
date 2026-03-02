#include<stdio.h> 
int a[10][10],visited[10],n; 
void dfs(int v) 
{ 
int i; 
visited[v]=1; 
printf("%d ",v+1); 
for(i=0;i<n;i++) 
if(a[v][i]==1 && visited[i]==0) 
dfs(i); 
} 
void bfs(int v) 
{ 
int queue[10],front=0,rear=0,i,u; 
for(i=0;i<n;i++) 
visited[i]=0; 
visited[v]=1; 
queue[rear++]=v; 
printf("%d ",v+1); 
while(front<rear) 
{ 
u=queue[front++]; 
for(i=0;i<n;i++) 
{ 
if(a[u][i]==1 && visited[i]==0) 
{ 
visited[i]=1; 
queue[rear++]=i; 
printf("%d ",i+1); 
} 
} 
} 
} 
int main() 
{ 
int i,j,e,u,v,start; 
printf("Enter number of vertices: "); 
scanf("%d",&n); 
printf("Enter number of edges: "); 
scanf("%d",&e); 
for(i=0;i<n;i++) 
{ 
visited[i]=0; 
for(j=0;j<n;j++) 
a[i][j]=0; 
} 
printf("Enter edges (u v):\n"); 
for(i=0;i<e;i++) 
{ 
scanf("%d%d",&u,&v); 
u--;v--; 
a[u][v]=1; 
a[v][u]=1; 
} 
printf("Enter starting vertex: "); 
scanf("%d",&start); 
start--; 
printf("DFS: "); 
dfs(start); 
printf("\n"); 
printf("BFS: "); 
bfs(start); 
printf("\n"); 
return 0; 
} 
