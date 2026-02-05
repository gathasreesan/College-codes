#include <stdio.h>

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
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter item weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter number of bins: ");
    scanf("%d", &m);

    printf("Enter bin capacity: ");
    scanf("%d", &C);

    /* ---------- BRUTE FORCE RUN ---------- */
    for (int i = 0; i < m; i++)
        bin[i] = 0;

    bruteForce(0);
    int bruteBins = countBinsUsed();

    /* ---------- BACKTRACKING RUN ---------- */
    for (int i = 0; i < m; i++)
        bin[i] = 0;

    backtracking(0);
    int backtrackBins = countBinsUsed();

    /* ---------- OUTPUT ---------- */
    printf("\n--- RESULTS ---\n");
    printf("Brute Force:\n");
    printf("  Recursive Calls = %d\n", bruteCalls);
    printf("  Bins Used       = %d\n", bruteBins);

    printf("\nBacktracking (with Pruning):\n");
    printf("  Recursive Calls = %d\n", backtrackCalls);
    printf("  Bins Used       = %d\n", backtrackBins);

    return 0;
}
