//complxity best case = avg case = worst case = n^2.
#include <stdio.h>

void print(int arr[], int size);
void selectionSort(int arr[], int n);
void swap(int *temp1, int *temp2);

// Driver program to test above functions
void main() {
    int n;//array size
    printf("Enter how many element : ");
    scanf("%d", &n);//input array size
    int arr[n];//array declare

    printf("Enter the element : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);//input array

    printf("Before sorted the array : ");
    print(arr, n);

    selectionSort(arr, n); // Function call to sort
    printf("After Sorted the array : ");
    print(arr, n);
}

//print the array
void print(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d \t", arr[i]);
    printf("\n");
}

//sort the array
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[i]) //find minimum value and swap with large value.
                swap(&arr[j], &arr[i]);
    }
}

//swap two variable
void swap(int *temp1, int *temp2) {
    int temp = *temp1;
    *temp1 = *temp2;
    *temp2 = temp;
}