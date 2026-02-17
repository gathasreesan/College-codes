#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void linear(int arr[], int n, int key)
{
    int found = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            printf("Linear Search :Element found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if(!found)
        printf("Element not found\n");
}
int binary(int arr[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1; // only return -1 AFTER loop ends
}
void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}
int partition(int A[],int low,int high)
{
int pivot=A[high];
int i=low-1;
for(int j=low;j<high;j++)
{
if(A[j]<pivot)
{
i++;
swap(&A[i],&A[j]);
}
}
return i+1;
}
void quicksort(int A[],int low,int high)
{
if(low<high)
{
int pi=partition(A,low,high);
quicksort(A,low,pi-1);
quicksort(A,pi+1,high);
}
}
int main()
{
int n,key,b;
printf("\n");
printf("Enter the size of array");
scanf("%d",&n);
int arr[n],arr1[n];
 srand(time(NULL)); // seeds rand() so numbers change every run
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;   // random number between 0 and 999
    }
    // Print them:
    printf("Random numbers: ");
    for (int i = 0; i < n; i++) {
        printf("%d \t", arr[i]);
    }
printf("\nEnter the element to search ");
scanf("%d",&key);
for (int i = 0; i < n; i++)
{
 arr1[i] = arr[i];
} 
clock_t start, end;
double time_taken;
//Linear Search Time
printf("\n");
printf("-----Performance Analysis-----\n");
printf("Array Size: %d\n", n);
printf("\n");
printf(" ----Linear Search:----\n"  );
start = clock();
linear(arr,n,key);
end=clock();
time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Time taken by Linear Search: %f seconds\n", time_taken);
//Bubble Sort Time
printf("\n");
printf(" ----Bubble Sort:----\n"  );
start=clock();
//bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }

end=clock();
time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Time taken by Bubble Sort: %f seconds\n", time_taken);
//Binary Search Time
printf("\n");
printf(" ----Binary Search:----\n"  );
start = clock();
 b = binary(arr1, n, key);
    if(b != -1)
        printf("Binary Search: Element found at index %d\n", b);
    else
        printf("Binary Search: Element not found\n");
end=clock();
time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Time taken by Binary Search: %f seconds\n", time_taken);
//Quick Sort Time
printf("\n");
printf(" ----Quick Sort:----\n"  );
start = clock();
quicksort(arr, 0, n - 1);
end=clock();
time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Time taken by Quick Sort: %f seconds\n", time_taken);   
return 0;
}
