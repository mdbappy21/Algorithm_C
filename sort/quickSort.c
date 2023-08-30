//best case = avg case = n log(n), worst case = n^2
#include <stdio.h>

void print(int arr[],int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);

void main()
{
    int n;//array size
    printf("Enter how many element : ");
    scanf("%d",&n);//input array size
    int arr[n];//declare array

    printf("Enter the element : ");
    for (int i = 0; i < n; i++) {//input array
        scanf("%d",&arr[i]);
    }
    printf("Before sorted the array : ");
    print(arr,n);

    quickSort(arr, 0, n - 1); // Function call to sort

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
        int pivot = partition(arr, low, high); //calculate pivot's write position.

        quickSort(arr, low, pivot - 1); //pivot's smallest element sort
        quickSort(arr, pivot + 1, high); //pivot's biggest element sort
    }
}

// Partition the array using the last element as the pivot
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];  // Choosing the pivot to last element.
    int i = (low - 1);     //blank space create where we store smallest value.

    for (int j = low; j < high ; j++) {
        if (arr[j] < pivot) {   // If current element is smaller than the pivot
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[high]);
    return i;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}