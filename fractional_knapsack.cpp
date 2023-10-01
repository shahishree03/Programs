#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Function to compare items based on their value-to-weight ratio (descending order)
int compare(const void *a, const void *b) {
    double ratio1 = (double)(((struct Item *)a)->value) / (((struct Item *)a)->weight);
    double ratio2 = (double)(((struct Item *)b)->value) / (((struct Item *)b)->weight);
    return (ratio2 > ratio1) - (ratio2 < ratio1);
}

// Function to solve Fractional Knapsack problem
double fractionalKnapsack(struct Item items[], int numItems, int capacity) {
    // Sort items based on their value-to-weight ratio in descending order
    qsort(items, numItems, sizeof(struct Item), compare);

    double totalValue = 0.0; // Total value of selected items
    int currentWeight = 0;   // Current weight in the knapsack

    // Iterate through the sorted items and select them partially or fully
    for (int i = 0; i < numItems; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // If the entire item can be added, add it
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Otherwise, add a fraction of the item
            double fraction = (double)(capacity - currentWeight) / items[i].weight;
            totalValue += items[i].value * fraction;
            break; // No more items can be added
        }
    }

    return totalValue;
}

int main() {
    int numItems;
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    struct Item items[10];

    for (int i = 0; i < numItems; i++) {
        printf("Enter the weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    int capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    double maxValue = fractionalKnapsack(items, numItems, capacity);

    printf("The maximum value that can be obtained is: %.2lf\n", maxValue);

    return 0;
}
