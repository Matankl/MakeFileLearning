#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"

int main() {
    // Declare lists of items price and weight
    char items[ItemsSize];
    int price[ItemsSize];
    int weight[ItemsSize];

    // get input from the user for the items and their price and weight
    // for (int i = 0; i < ItemsSize; i++) {
    //     scanf("%c", &items[i]);
    //     scanf("%d", &price[i]);
    //     scanf("%d", &weight[i]);
        
    // }
    for (int i = 0; i < ItemsSize; i++) {
    scanf(" %c %d %d", &items[i], &price[i], &weight[i]);
}
     
    // Declare a 2D array to store the maximum value of items that can be put in the knapsack
    int dp[ItemsSize + 1][MaxWeight + 1];

    // Print the chosen items and the maximum value that can be put in the knapsack
    knapsack(price, weight, dp);
    printf("Maximum profit: %d\n", dp[ItemsSize][MaxWeight]);
    printSelectedItems(dp, weight);

    



    return 0;
}
