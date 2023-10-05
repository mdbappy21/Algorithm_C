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
    int i, temp, j;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j+1]=arr[j+1]+arr[j];    //swip arr[j+1] and arr[j]
            arr[j] = arr[j+1]-arr[j];
            arr[j+1] = arr[j+1]-arr[j];
            j --;
        }
    }
}