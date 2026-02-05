#include <stdio.h>
#define INF 999

int parent[10];

/* --------- Kruskal Helpers --------- */
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void uni(int i, int j)
{
    parent[j] = i;
}

/* --------- Main --------- */
int main()
{
    int n, i, j, choice;
    int cost[10][10];
    char again;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Prim's Algorithm\n");
        printf("2. Kruskal's Algorithm\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        /* -------- PRIM -------- */
        if (choice == 1)
        {
            int visited[10] = {0};
            int edges = 0, mincost = 0;
            int u = 0, v = 0, min;

            visited[0] = 1;

            printf("\nEdges in MST (Prim):\n");

            while (edges < n - 1)
            {
                min = INF;

                for (i = 0; i < n; i++)
                {
                    if (visited[i])
                    {
                        for (j = 0; j < n; j++)
                        {
                            if (!visited[j] && cost[i][j] < min)
                            {
                                min = cost[i][j];
                                u = i;
                                v = j;
                            }
                        }
                    }
                }

                printf("(%d - %d) cost = %d\n", u, v, min);
                mincost += min;
                visited[v] = 1;
                edges++;
            }

            printf("Minimum cost = %d\n", mincost);
        }

        /* -------- KRUSKAL -------- */
        else if (choice == 2)
        {
            int edges = 0, mincost = 0;
            int temp[10][10];

            /* Copy matrix (important!) */
            for (i = 0; i < n; i++)
            {
                parent[i] = i;
                for (j = 0; j < n; j++)
                    temp[i][j] = cost[i][j];
            }

            printf("\nEdges in MST (Kruskal):\n");

            while (edges < n - 1)
            {
                int min = INF, a = -1, b = -1;

                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        if (temp[i][j] < min)
                        {
                            min = temp[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }

                int u = find(a);
                int v = find(b);

                if (u != v)
                {
                    printf("(%d - %d) cost = %d\n", a, b, min);
                    mincost += min;
                    uni(u, v);
                    edges++;
                }

                temp[a][b] = temp[b][a] = INF;
            }

            printf("Minimum cost = %d\n", mincost);
        }
        else
        {
            printf("Invalid choice!\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    return 0;
}
