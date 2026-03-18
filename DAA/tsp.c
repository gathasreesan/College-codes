#include <stdio.h>
#include <limits.h>
#include <time.h>

#define MAX 10

int graph[MAX][MAX];
int n;

//////////////////// EXACT TSP ////////////////////

int visited[MAX], minCost;

void tsp(int curr, int count, int cost)
{
    if(count == n && graph[curr][0])
    {
        if(cost + graph[curr][0] < minCost)
            minCost = cost + graph[curr][0];
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i] && graph[curr][i])
        {
            visited[i]=1;
            tsp(i,count+1,cost+graph[curr][i]);
            visited[i]=0;
        }
    }
}

int solveExactTSP()
{
    for(int i=0;i<n;i++) visited[i]=0;
    minCost = INT_MAX;
    visited[0]=1;
    tsp(0,1,0);
    return minCost;
}

//////////////////// NEAREST NEIGHBOUR ////////////////////

int nearestNeighbour()
{
    int visitedNN[MAX]={0};
    int cost=0, curr=0;

    visitedNN[0]=1;

    for(int i=0;i<n-1;i++)
    {
        int min=999, next=-1;

        for(int j=0;j<n;j++)
        {
            if(!visitedNN[j] && graph[curr][j] && graph[curr][j]<min)
            {
                min=graph[curr][j];
                next=j;
            }
        }

        visitedNN[next]=1;
        cost+=min;
        curr=next;
    }

    cost+=graph[curr][0];
    return cost;
}

//////////////////// MST (PRIM) ////////////////////

int parent[MAX];

int minKey(int key[], int mstSet[])
{
    int min=999, index;

    for(int i=0;i<n;i++)
    {
        if(!mstSet[i] && key[i]<min)
        {
            min=key[i];
            index=i;
        }
    }
    return index;
}

void primMST()
{
    int key[MAX], mstSet[MAX]={0};

    for(int i=0;i<n;i++)
        key[i]=999;

    key[0]=0;
    parent[0]=-1;

    for(int i=0;i<n-1;i++)
    {
        int u=minKey(key,mstSet);
        mstSet[u]=1;

        for(int v=0;v<n;v++)
        {
            if(graph[u][v] && !mstSet[v] && graph[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
}

//////////////////// PREORDER ////////////////////

int visitedMST[MAX];

void preorder(int u, int *cost)
{
    visitedMST[u]=1;

    for(int i=0;i<n;i++)
    {
        if(parent[i]==u && !visitedMST[i])
        {
            *cost += graph[u][i];
            preorder(i,cost);
        }
    }
}

int mstApprox()
{
    primMST();

    for(int i=0;i<n;i++) visitedMST[i]=0;

    int cost=0;
    preorder(0,&cost);

    cost += graph[0][0]; // return to start
    return cost;
}

//////////////////// MAIN ////////////////////

int main()
{
    printf("Enter number of cities: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    clock_t start,end;
    double timeExact, timeNN, timeMST;

    start = clock();
    int exact = solveExactTSP();
    end = clock();
    timeExact = (double)(end-start)/CLOCKS_PER_SEC;

    start = clock();
    int nn = nearestNeighbour();
    end = clock();
    timeNN = (double)(end-start)/CLOCKS_PER_SEC;

    start = clock();
    int mst = mstApprox();
    end = clock();
    timeMST = (double)(end-start)/CLOCKS_PER_SEC;

    printf("\n--- RESULTS ---\n");
    printf("Exact TSP Cost = %d\n", exact);
    printf("Nearest Neighbour Cost = %d\n", nn);
    printf("MST Approx Cost = %d\n", mst);

    printf("\n--- EXECUTION TIME ---\n");
    printf("Exact = %lf\n", timeExact);
    printf("Nearest = %lf\n", timeNN);
    printf("MST = %lf\n", timeMST);

    printf("\n--- APPROXIMATION RATIO ---\n");
    printf("NN Ratio = %lf\n", (double)nn/exact);
    printf("MST Ratio = %lf\n", (double)mst/exact);

    return 0;
}