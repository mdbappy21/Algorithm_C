//best case = avg case = n log(n), worst case = n^2
#include <stdio.h>
#include <stdlib.h>

void print(int arr[],int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);

// Driver code
void main()
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
    quickSort(arr, 0, n - 1);

    printf("After Sorted the array : ");
    print(arr,n);
}

void print(int arr[],int n){
    for (int i = 0; i < n; i++)
        printf("%d\t",arr[i]);
    printf("\n");
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {

        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Partition the array using the last element as the pivot
int partition(int arr[], int low, int high)
{
    // Choosing the pivot
    int pivot = arr[high];

    // Index of smaller element and indicates the right position of pivot found so far
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than the pivot
        if (arr[j] < pivot) {

            // Increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}