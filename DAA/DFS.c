#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], n;

void dfs(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

int main() {
    int i, j, start, connected = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);

    for (i = 0; i < n; i++) {
        if (visited[i] == 0)
            connected = 0;
    }

    if (connected)
        printf("\nGraph is Connected");
    else
        printf("\nGraph is Not Connected");

    return 0;
}
