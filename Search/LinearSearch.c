#include <stdio.h>

void linearSearch(int arr[], int n, int search) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("The Value %d found at position %d\n", search, i + 1);
            return;
        }
    }
    printf("The Value %d does not found\n", search);
}

void main() {
    int n;
    printf("How many element do you want to inseart : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array element : ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int search;
    printf("Enter a value that you want to find : ");
    scanf("%d", &search);

    linearSearch(arr, n, search);
}
