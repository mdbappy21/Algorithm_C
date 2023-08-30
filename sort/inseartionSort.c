//complxity best case =n ,avg case = worst case = n^2
#include <stdio.h>

void print(int arr[], int n);
void insertionSort(int arr[], int n);

void main()
{
    int n;//array size
    printf("Enter how many element  : ");
    scanf("%d",&n);//input array size
    int arr[n] ;//array declear
    printf("Enter the Element : ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);//input array

    printf("Before sorted tha array : ");
    print(arr, n);//call function to print the array

    insertionSort(arr, n);//call function to sort the array

    printf("After sorted the array : ");
    print(arr, n);//call function to print the array
}

//print the array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d \t", arr[i]);
    printf("\n");
}

//sort the array
void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        while (i >= 0 && arr[i] > arr[i+1]) {
            arr[i] = arr[i+1];
            arr[i + 1] = arr[i];
        }
}