#include <stdio.h>

typedef struct knapsack {
    float weight;
    float profit;
    float density;
}knapsack;

int main() {
    int n;
    float Sack_Capacity;

    float Max_weight = 0, Max_profit = 0;

    printf("Enter how many items: ");
    scanf("%d", &n);
    knapsack p[n];
    float x[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Weight and Profit for item %d: ", i + 1);
        scanf("%f", &p[i].weight);
        scanf("%f", &p[i].profit);
        p[i].density = (p[i].profit) / (p[i].weight);
    }

    // Sorting items based on density in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].density < p[j].density) {
                knapsack temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("Enter Sack capacity: ");
    scanf("%f", &Sack_Capacity);

    int i = 0;
    while (Sack_Capacity > 0 && i < n) { // Changed the condition from Sack_Capacity != 0 to Sack_Capacity > 0
        if (p[i].weight <= Sack_Capacity) {
            x[i] = 1;
            Sack_Capacity -= p[i].weight;
        } else {
            x[i] = Sack_Capacity / p[i].weight;
            Sack_Capacity = 0; // Set Sack_Capacity to 0 when we cannot fit more items
        }
        i++;
    }

    for (int j = 0; j < n; j++) {
        Max_weight += x[j] * p[j].weight;
        Max_profit += x[j] * p[j].profit;
    }
    printf("Max Weight: %.2f\n", Max_weight);
    printf("Max Profit: %.2f\n", Max_profit);

    if (Sack_Capacity > 0)
        printf("Sack Capcity remain : %.2f\n", Sack_Capacity);
    else
        printf("Sack is full\n");

    return 0;
}