#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DISPLAY_SIZE 10
#define LARGE_SIZE 20000

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int randomPartition(int arr[], int low, int high)
{
    int random = low + rand() % (high - low + 1);
    swap(&arr[random], &arr[high]);
    return partition(arr, low, high);
}

void randomizedQuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = randomPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi-1);
        randomizedQuickSort(arr, pi+1, high);
    }
}

int main()
{
    int arr[DISPLAY_SIZE], arr2[DISPLAY_SIZE];

    printf("Enter %d numbers:\n", DISPLAY_SIZE);
    for(int i=0;i<DISPLAY_SIZE;i++)
    {
        scanf("%d",&arr[i]);
        arr2[i] = arr[i];
    }

    printf("\nInput Array:\n");
    printArray(arr,DISPLAY_SIZE);

    quickSort(arr,0,DISPLAY_SIZE-1);

    printf("\nSorted using Normal QuickSort:\n");
    printArray(arr,DISPLAY_SIZE);

    randomizedQuickSort(arr2,0,DISPLAY_SIZE-1);

    printf("\nSorted using Randomized QuickSort:\n");
    printArray(arr2,DISPLAY_SIZE);

    // Large arrays for timing
    int big1[LARGE_SIZE], big2[LARGE_SIZE];

    for(int i=0;i<LARGE_SIZE;i++)
    {
        big1[i] = i;        // worst case for normal QuickSort
        big2[i] = i;
    }

    clock_t start,end;
    double time_taken;

    start = clock();
    quickSort(big1,0,LARGE_SIZE-1);
    end = clock();
    time_taken = (double)(end-start)/CLOCKS_PER_SEC;

    printf("\nTime taken by Normal QuickSort (large input): %f seconds\n", time_taken);

    start = clock();
    randomizedQuickSort(big2,0,LARGE_SIZE-1);
    end = clock();
    time_taken = (double)(end-start)/CLOCKS_PER_SEC;

    printf("Time taken by Randomized QuickSort (large input): %f seconds\n", time_taken);

    return 0;
}