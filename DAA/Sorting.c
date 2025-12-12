#include <stdio.h>
#include <stdlib.h>

void linear(int arr[], int n, int key)
{
    int found = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            printf("Element found at index %d\n", i);
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
swap(&A[i],&A[j])
}
void quicksort(int arr[],int low,int high)
{
if(low<high)
{
int pi=partition(A,low,high);
quickSort(A,low,pi-1);
quickSort(A,pi+1,high);
}
}
int main()
{
int arr[100],arr1[100],n,key,b;
printf("Enter the size of array");
scanf("%d",&n);
printf("Enter the elements of the array");
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("Enter the element to search using linear search");
scanf("%d",&key);
linear(arr,n,key);
arr1=arr;
// sort before binary search
//bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }

    b = binary(arr1, n, key);

    if(b != -1)
        printf("Binary Search: Element found at index %d\n", b);
    else
        printf("Binary Search: Element not found\n");

quickSort(arr1,0,n);
return 0;
}




