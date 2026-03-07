#include <stdio.h>
#define MAX 20
int queue[MAX];
int front = 0, rear = -1;
void enqueue(int x)
{
queue[++rear] = x;
}
int dequeue()
{
return queue[front++];
}
int isEmpty()
{
return front > rear;
}
int main()
{
int V, E;
int adj[MAX][MAX];
int indegree[MAX] = {0};
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
indegree[v]++;
}
for (int i = 0; i < V; i++)
{
if (indegree[i] == 0)
enqueue(i);
}
int count = 0;
printf("\nTopological Order:\n");
while (!isEmpty())
{
int u = dequeue();
printf("%d\n", u);
count++;
for (int v = 0; v < V; v++)
{
if (adj[u][v])
{
indegree[v]--;
if (indegree[v] == 0)
enqueue(v);
}
}
}
if (count < V)
printf("\nCycle detected! Graph is NOT a DAG.\n");
else
printf("\nGraph is a DAG.\n");
return 0;
}
