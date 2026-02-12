#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 9999

int n;

struct Node {
    int vertex;
    int distance;
};

struct Node heap[MAX];
int size = 0;

void swap(struct Node *a, struct Node *b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index) {
    while (index > 0 && heap[index].distance < heap[(index-1)/2].distance) {
        swap(&heap[index], &heap[(index-1)/2]);
        index = (index-1)/2;
    }
}

void heapifyDown(int index) {
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if (left < size && heap[left].distance < heap[smallest].distance)
        smallest = left;

    if (right < size && heap[right].distance < heap[smallest].distance)
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(int vertex, int distance) {
    heap[size].vertex = vertex;
    heap[size].distance = distance;
    size++;
    heapifyUp(size - 1);
}

struct Node extractMin() {
    struct Node root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

void dijkstra(int graph[MAX][MAX], int src) {
    int dist[MAX], visited[MAX], parent[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;
    insert(src, 0);

    while (size > 0) {
        struct Node node = extractMin();
        int u = node.vertex;

        if (visited[u])
            continue;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v]) {
                int newDist = dist[u] + graph[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    parent[v] = u;
                    insert(v, newDist);
                }
            }
        }
    }

    printf("\nVertex\tDistance\tPath");
    for (int i = 0; i < n; i++) {
        printf("\n%d\t%d\t\t%d", i, dist[i], src);
        printPath(parent, i);
    }
}

int main() {
    int graph[MAX][MAX], src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}
