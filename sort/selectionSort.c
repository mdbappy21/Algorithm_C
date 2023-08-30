// C program for implementation of selection sort
#include <stdio.h>

void print(int arr[], int size);
void selectionSort(int arr[], int n);
void swap(int *xp, int *yp);

// Driver program to test above functions
int main()
{
    int n;
    printf("Enter how many element : ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter the element : ");
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("Before sorted the array : ");
    print(arr,n);

    // Function call to sort
    selectionSort(arr, n);

    printf("After Sorted the array : ");
    print(arr,n);

    return 0;
}

//print the array
void print(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d \t", arr[i]);
    printf("\n");
}

//sort the array
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

//swap two variable
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}