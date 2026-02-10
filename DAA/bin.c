#include <stdio.h>
#include <time.h>
int n, m, C;
int weight[10];
int bin[10];
long long bruteCalls = 0;
long long backtrackCalls = 0;
/* ---------- BRUTE FORCE (NO PRUNING) ---------- */
int bruteForce(int item)
{
    bruteCalls++;
    if (item == n)
        return 1;
    for (int i = 0; i < m; i++)
    {
        bin[i] += weight[item];
        if (bin[i] <= C)
        {
            if (bruteForce(item + 1))
                return 1;
        }
        bin[i] -= weight[item];
    }
    return 0;
}
/* ---------- BACKTRACKING (WITH PRUNING) ---------- */
int backtracking(int item)
{
    backtrackCalls++;
    if (item == n)
        return 1;
    for (int i = 0; i < m; i++)
    {
        if (bin[i] + weight[item] <= C)
        {
            bin[i] += weight[item];
            if (backtracking(item + 1))
                return 1;
            bin[i] -= weight[item];
        }
    }
    return 0;
}
int main()
{
    clock_t start, end;
    double time_taken;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter item weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    printf("Enter number of bins: ");
    scanf("%d", &m);
    printf("Enter bin capacity: ");
    scanf("%d", &C);
    /* ---------- BRUTE FORCE ---------- */
    for (int i = 0; i < m; i++)
        bin[i] = 0;
    start = clock();
    bruteForce(0);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n--- BRUTE FORCE ---\n");
    printf("Recursive Calls = %lld\n", bruteCalls);
    printf("CPU Time        = %f seconds\n", time_taken);
    /* ---------- BACKTRACKING ---------- */
    for (int i = 0; i < m; i++)
        bin[i] = 0;
    start = clock();
    backtracking(0);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n--- BACKTRACKING (With Pruning) ---\n");
    printf("Recursive Calls = %lld\n", backtrackCalls);
    printf("CPU Time        = %f seconds\n", time_taken);
    return 0;
}
