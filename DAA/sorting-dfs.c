#include <stdio.h>
#define MAX 20
int stack[MAX];
int top = -1;
int count = 0;
void dfs(int v, int visited[], int adj[MAX][MAX], int V)
{
visited[v] = 1;
for (int i = 0; i < V; i++)
{
if (adj[v][i] && !visited[i])
{
dfs(i, visited, adj, V);
}
}
stack[++top] = v;
count++;
}
int main()
{
int V, E;
int adj[MAX][MAX];
int visited[MAX] = {0};
printf("Enter number of vertices:\n");
scanf("%d", &V);
printf("Enter number of edges:\n");
scanf("%d", &E);
for (int i = 0; i < V; i++)
{
for (int j = 0; j < V; j++)
{
adj[i][j] = 0;
}
}
printf("Enter edges (u then v on new lines):\n");
for (int i = 0; i < E; i++)
{
int u, v;
scanf("%d", &u);
scanf("%d", &v);
adj[u][v] = 1;
}
for (int i = 0; i < V; i++)
{
if (!visited[i])
dfs(i, visited, adj, V);
}
printf("\nTopological Order:\n");
while (top != -1)
{
printf("%d\n", stack[top--]);
}
if (count < V)
printf("\nCycle detected! Graph is NOT a DAG.\n");
else
printf("\nGraph is a DAG.\n");
return 0;
}
