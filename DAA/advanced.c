#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int n;
     clock_t start,end;
    double time_taken;
printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n],arr2[n];

    srand(time(0)); // seed for random numbers

    // Fill array with random numbers
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // numbers between 0–99
    }

    // Print array
    printf("Array elements are:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        arr2[i] = arr[i]; // copy to another array for fair comparison
    }
    printf("\n");
    \
  
start = clock();
    quickSort(arr,0,n-1);

    printf("\nSorted using Normal QuickSort:\n");
    printArray(arr,n);
end = clock();
    time_taken = (double)(end-start)/CLOCKS_PER_SEC;
 printf("\nTime taken by Normal QuickSort: %f seconds\n", time_taken);

 start = clock();
    randomizedQuickSort(arr2,0,n-1);

    printf("\nSorted using Randomized QuickSort:\n");
    printArray(arr2,n);
end = clock();
    time_taken = (double)(end-start)/CLOCKS_PER_SEC;
printf("Time taken by Randomized QuickSort: %f seconds\n", time_taken);

    return 0;
    
}