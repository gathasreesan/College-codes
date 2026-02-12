#include <stdio.h>
#include <time.h>

int n, m, C;
int weight[10];
int bin[10];

int bruteCalls = 0;
int backtrackCalls = 0;

/* ---------- BRUTE FORCE (NO PRUNING) ---------- */
int bruteForce(int item)
{
    bruteCalls++;

    if (item == n)
        return 1;

    for (int i = 0; i < m; i++)
    {
        bin[i] += weight[item];

        if (bruteForce(item + 1))
            return 1;

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
        // PRUNING: capacity constraint
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

int countBinsUsed()
{
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        if (bin[i] > 0)
            count++;
    }
    return count;
}

int main()
{
    clock_t start, end;
    double bruteTime, backtrackTime;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter item weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter number of bins: ");
    scanf("%d", &m);

    printf("Enter bin capacity: ");
    scanf("%d", &C);

    printf("\n===== INPUT DETAILS =====\n");
    printf("Number of Items (n) = %d\n", n);
    printf("Number of Bins (m)  = %d\n", m);
    printf("Bin Capacity (C)    = %d\n", C);

    /* ---------- BRUTE FORCE RUN ---------- */
    for (int i = 0; i < m; i++)
        bin[i] = 0;

    bruteCalls = 0;

    start = clock();
    bruteForce(0);
    end = clock();

    bruteTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    int bruteBins = countBinsUsed();

    /* ---------- BACKTRACKING RUN ---------- */
    for (int i = 0; i < m; i++)
        bin[i] = 0;

    backtrackCalls = 0;

    start = clock();
    backtracking(0);
    end = clock();

    backtrackTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    int backtrackBins = countBinsUsed();

    /* ---------- OUTPUT ---------- */
    printf("\n\n========== RESULTS ==========\n");

    printf("\n--- Brute Force (No Pruning) ---\n");
    printf("Recursive Calls = %d\n", bruteCalls);
    printf("Bins Used       = %d\n", bruteBins);
    printf("Time Taken      = %f seconds\n", bruteTime);

    printf("\n--- Backtracking (With Pruning) ---\n");
    printf("Recursive Calls = %d\n", backtrackCalls);
    printf("Bins Used       = %d\n", backtrackBins);
    printf("Time Taken      = %f seconds\n", backtrackTime);

    printf("\n=================================\n");

    return 0;
}
