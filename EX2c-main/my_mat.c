#include <stdio.h>
#include "my_mat.h"



void buildMatrix(int matrix[MatSize][MatSize]) {
    for (int i = 0; i < MatSize; i++) {
        for (int j = 0; j < MatSize; j++) {
            // Get input from the user
            scanf("%d", &matrix[i][j]);
        }
    }
}

void hasPath(int dist[MatSize][MatSize], int Mi, int Mj){
    if (dist[Mi][Mj] == 0)
        printf("False\n");
    else
        printf("True\n");
}


//print the shortest path length from Mi to Mj
void shortestPathLength(int dist[MatSize][MatSize], int Mi, int Mj){
    if (dist[Mi][Mj] == 0)
        printf("-1\n");                                                    // this may be a future problem if they want me to print an intiger
    else
        printf("%d\n", dist[Mi][Mj]);
}




/*----------additional functions for my_graph----------*/

//make a shortest path matrix using Floyd Warshall algorithm
void MakeDist(int matrix[MatSize][MatSize], int dist[MatSize][MatSize]){
    // copy the matrix to dist
    for (int i = 0; i < MatSize; i++){
        for (int j = 0; j < MatSize; j++){
            dist[i][j] = matrix[i][j];
        }
    }
    //Floyd Warshall algorithm for shortest path to all nodes from all nodes
    for (int k = 0; k < MatSize; k++){
        for (int i = 0; i < MatSize; i++){
            for (int j = 0; j < MatSize; j++){
                if (dist[i][j] == 0 && (i!=j) &&(dist[i][k] != 0 && dist[k][j] != 0))
                    dist[i][j] = dist[i][k] + dist[k][j];
                else if (((dist[k][j] != 0) && (dist[i][k] != 0) && (dist[i][j] > (dist[i][k] + dist[k][j]))))
                    dist[i][j] = dist[i][k] + dist[k][j];
                
                
                // if (dist[i][k] + dist[k][j] < dist[i][j])
                //     dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}



int max(int a, int b) {
    return (a > b) ? a : b;
}

/*---------- functions for my_Knapsack----------*/

void knapsack(int price[ItemsSize], int weight[ItemsSize], int dp[ItemsSize + 1][MaxWeight + 1]) {
    for (int i = 0; i <= ItemsSize; i++) {
        for (int w = 0; w <= MaxWeight; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weight[i - 1] <= w) {
                dp[i][w] = max(price[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
}

void printSelectedItems(int dp[ItemsSize + 1][MaxWeight + 1], int weight[ItemsSize]) {
    int i = ItemsSize, w = MaxWeight;
    //init int
    int selected[ItemsSize];
    printf("Selected items:");
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected[i - 1] = 1;
            w -= weight[i - 1];
            i--;
        } else {
            selected[i - 1] = 0;
            i--;
        }
    }
    for (int i = 0; i < ItemsSize; i++) {
        if (selected[i] == 1) {
            printf(" %c", i + 'a');
        }
    }
   // printf("\n");
}










