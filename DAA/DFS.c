#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[MAX];
int visited[MAX];
int n;

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (Undirected Graph)
void addEdge(int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// DFS Traversal
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adjList[v];
    while(temp != NULL) {
        int adjVertex = temp->vertex;
        if(!visited[adjVertex])
            dfs(adjVertex);
        temp = temp->next;
    }
}

int main() {
    int edges, src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        adjList[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(int i = 0; i < edges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);

    // Check connectivity
    int connected = 1;
    for(int i = 0; i < n; i++) {
        if(!visited[i])
            connected = 0;
    }

    if(connected)
        printf("\nGraph is Connected");
    else
        printf("\nGraph is Not Connected");

    return 0;
}
