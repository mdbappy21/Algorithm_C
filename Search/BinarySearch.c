#include <stdio.h>
void binarySearch(int arr[], int left, int right, int search) {
    while (left <= right) {
        int mid = (left + right ) / 2;
        // Check if x is present at mid
        if (arr[mid] == search) {
            printf("The Value %d found at position %d\n", arr[mid], mid+1);
            return;
        }
        // If x greater, ignore left half
        if (arr[mid] < search)
            left = mid + 1;

            // If x is smaller, ignore right half
        else
            right = mid - 1;
    }
    printf("The value %d does not found\n",search);
}

void main() {
    int n;
    printf("How many element do you want to inseart : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter a Sorted array : ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int search ;
    printf("Enter a value that you want to find : ");
    scanf("%d",&search);

    binarySearch(arr, 0, n - 1, search);
}