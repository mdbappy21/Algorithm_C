//complxity best case = age case= worst case = n log(n)
#include <stdio.h>
#include <stdlib.h>

void print(int arr[], int n);

void divide(int arr[], int L, int R);

void conqure(int arr[], int L, int mid, int R);

void main() {
    //taking array size.
    int n;
    printf("Enter how many element : ");
    scanf("%d", &n);
    int arr[n];

    //taking array element as user input.
    printf("Enter the Element : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    //printing unsorted array.
    printf("Before sorted the array : ");
    print(arr, n);

    //call method for sort.
    divide(arr, 0, n - 1);

    //printing sorted array.
    printf("After sorted the array : ");
    print(arr, n);
}


void print(int arr[], int n) {
    //printing array using for loop.
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}


void divide(int arr[], int L, int R) {
    //declear mid variable .
    int mid = 0;

    // condition true when Left is smaller than Right.
    if (L < R) {
        //calulate mid value .
        mid = (L + R) / 2;

        //use recurtion for divide array's Left part in single element.
        divide(arr, L, mid);
        //again use recurtion for divide array's right part in single element.
        divide(arr, mid + 1, R);

        //conqure the single element for build the array.

        conqure(arr, L, mid, R);
    }
}


void conqure(int arr[], int L, int mid, int R) {
    int i, j, k=L;
    //create two variable that indicate new array size.
    int n1 = mid - L + 1;
    int n2 = R - mid;

    //declared two array.
    int arrL[n1], arrR[n2];
    //copy data to the array.
    for (i = 0; i < n1; i++)
        arrL[i] = arr[L + i];

    for (j = 0; j < n2; j++)
        arrR[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    //sort the short array.
    while (i < n1 && j < n2) {
        if (arrL[i] <= arrR[j]) {
            arr[k] = arrL[i];
            i++;
        } else {
            arr[k] = arrR[j];
            j++;
        }
        k++;
    }

    //copy remaining element of arrL
    while (i < n1) {
        arr[k] = arrL[i];
        i++;
        k++;
    }

    //copy remaining element of arrR.
    while (j < n2) {
        arr[k] = arrR[j];
        j++;
        k++;
    }
}