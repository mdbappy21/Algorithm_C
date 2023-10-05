#include <stdio.h>

typedef struct knapsack {
    float weight;
    float profit;
    float density;
} knapsack;

float max(float a, float b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    float Sack_Capacity;

    printf("Enter how many items: ");
    scanf("%d", &n);
    knapsack p[n];
    float x[n];

    for (int i = 0; i < n; i++) {
        printf("Enter Weight and Profit for item %d: ", i + 1);
        scanf("%f %f", &p[i].weight, &p[i].profit);
        p[i].density = (p[i].profit) / (p[i].weight);
    }

    printf("Enter Sack capacity: ");
    scanf("%f", &Sack_Capacity);

    float dp[n + 1][(int)Sack_Capacity + 1];

    // Initialize the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= (int)Sack_Capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (p[i - 1].weight <= w)
                dp[i][w] = max(p[i - 1].profit + dp[i - 1][(int)(w - p[i - 1].weight)], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Backtrack to find the selected items
    int i = n, w = (int)Sack_Capacity;
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            x[i - 1] = 1.0;
            w -= (int)p[i - 1].weight;
        }
        i--;
    }

    float maxWeight=0,maxProfit=0;
    printf("Selected items:\n");
    for (int j = 0; j < n; j++) {
        if (x[j] == 1.0) {
            printf("Item %d: Weight=%.2f, Profit=%.2f\n", j + 1, p[j].weight, p[j].profit);
            maxWeight+=p[j].weight;
            maxProfit+=p[j].profit;
        }
    }

    printf("Max Weight: %.2f\n", maxWeight);
    printf("Max Profit: %.2f\n", maxProfit);

    return 0;
}