#include <stdio.h>

int main()
{
    int n, graph[10][10], visited[10]={0};
    int cost = 0, city = 0;

    printf("Enter number of cities: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    visited[city] = 1;
    printf("Tour: %d ", city);

    for(int i=1;i<n;i++)
    {
        int min = 999, nextCity;

        for(int j=0;j<n;j++)
        {
            if(!visited[j] && graph[city][j] < min && graph[city][j] != 0)
            {
                min = graph[city][j];
                nextCity = j;
            }
        }

        visited[nextCity] = 1;
        printf("-> %d ", nextCity);
        cost += min;
        city = nextCity;
    }

    cost += graph[city][0];

    printf("-> 0");
    printf("\nTotal cost = %d\n", cost);

    return 0;
}