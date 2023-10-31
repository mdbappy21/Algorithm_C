#include <stdio.h>
#define size 6

int arr[size][size], visited[size];
void dfs(int k) {
    printf("%c->", k + 65);
    visited[k] = 1;
    for (int j = 0; j < size; j++) {
        if (!visited[j] && arr[k][j] == 1) {
            dfs(j);
        }
    }
}

int main() {
    printf("Enter the adjacency matrix : \n");
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            scanf("%d", &arr[i][j]);
        }

    for (int i = 0; i <= 5; i++) {
        visited[i] = 0;
    }
    dfs(0);

}