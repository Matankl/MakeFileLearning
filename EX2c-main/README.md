# C Algorithms and Data Structures Project

## Overview

This project implements two classic algorithms: the Floyd-Warshall algorithm for finding the shortest paths in a graph, and the 0/1 Knapsack problem for optimizing item selection based on weight and value. The project includes the following components:

- **Graph Operations**: Implementation of the Floyd-Warshall algorithm to compute the shortest paths between all pairs of nodes in a graph.
- **Knapsack Problem**: Implementation of the 0/1 Knapsack problem to determine the maximum value of items that can be carried in a knapsack with a given weight limit.

## Components

### Files

- **`my_graph.c`**: Contains the main program for handling graph operations, including matrix input and shortest path queries.
- **`my_Knapsack.c`**: Contains the main program for solving the 0/1 Knapsack problem, including item input and selection.
- **`my_mat.c`**: Implements functions for both the graph operations and knapsack problem, including matrix creation, path checking, and dynamic programming table filling.
- **`my_mat.h`**: Header file declaring the functions and constants used across the project.
- **`Makefile`**: Automates the compilation of the project files.

### Functions

#### Graph Functions

- **`buildMatrix(int matrix[MatSize][MatSize])`**: Creates a 10x10 matrix based on user input.
- **`hasPath(int dist[MatSize][MatSize], int Mi, int Mj)`**: Prints `True` if there is a path from node `i` to node `j`, otherwise prints `False`.
- **`shortestPathLength(int dist[MatSize][MatSize], int Mi, int Mj)`**: Prints the length of the shortest path from node `i` to node `j`, or `-1` if no path exists.
- **`MakeDist(int matrix[MatSize][MatSize], int dist[MatSize][MatSize])`**: Creates a distance matrix using the Floyd-Warshall algorithm.

#### Knapsack Functions

- **`knapsack(int price[ItemsSize], int weight[ItemsSize], int dp[ItemsSize + 1][MaxWeight + 1])`**: Fills the dynamic programming (dp) table with the maximum values of items that can be placed in the knapsack.
- **`printSelectedItems(int dp[ItemsSize + 1][MaxWeight + 1], int weight[ItemsSize])`**: Prints the items selected to achieve the maximum value in the knapsack.
- **`max(int a, int b)`**: Utility function to return the maximum of two integers.

## Getting Started

### Prerequisites

- GCC (GNU Compiler Collection) or any compatible C compiler.
- A Linux/Unix environment is recommended, but the project is also compatible with Windows.

### Compilation

Use the provided `Makefile` to compile the project. Run the following command in the terminal:

```sh
make
```

This will compile the `my_graph.c`, `my_Knapsack.c`, and `my_mat.c` files and generate the corresponding executables.

### Running the Project

#### Graph Operations

To run the graph operations program:

```sh
./my_graph
```

The program will prompt for the following inputs:

1. **`A`**: Build the adjacency matrix for the graph.
2. **`B`**: Check if there is a path between two nodes.
3. **`C`**: Find the shortest path length between two nodes.
4. **`D`**: Exit the program.

#### Knapsack Problem

To run the knapsack problem program:

```sh
./my_Knapsack
```

The program will prompt for the following inputs:

1. Enter the items' names, prices, and weights.
2. The program will compute and display the maximum profit and the selected items.

### Example Usage

#### Graph Example

```sh
./my_graph
A
1 0 4 0 0 0 0 0 8 0
0 1 0 8 0 0 0 0 11 0
...
B
2 3
True
C
2 3
5
D
```

#### Knapsack Example

```sh
./my_Knapsack
a 60 10
b 100 20
c 120 30
...
Maximum profit: 220
Selected items: b c
```

## License

This project is open-source and available under the MIT License. Feel free to use, modify, and distribute as per the terms of the license.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request. For major changes, it is recommended to open an issue first to discuss what you would like to change.

