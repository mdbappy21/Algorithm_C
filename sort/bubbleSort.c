// best case n, avg case = worst case =n^2
#include <stdbool.h>
#include <stdio.h>

void print(int arr[], int n);
void bubbleSort(int arr[], int n);
void swap(int* xp, int* yp);

int main()
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

    bubbleSort(arr, n);//call function to sort the array

    printf("After sorted the array : ");
    print(arr, n);//call function to print the array

    return 0;
}

// Function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d \t", arr[i]);
    printf("\n");
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
       int  temp = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                temp = 1;
            }
        }
        // If no two elements were temp by inner loop, then break
        if (temp == 0)
            break;
    }
}

//swap two variable.
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}