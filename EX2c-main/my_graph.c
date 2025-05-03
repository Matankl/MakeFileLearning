#include <stdio.h>
#include "my_mat.h"

int main() {

    // Declare a 10x10 matrixes
    int matrix[MatSize][MatSize];
    int dist[MatSize][MatSize];

    // Declare input
    char input; 
    int Mi, Mj;


    //main loop: scan for input and call the appropriate function
    do
    {
        if (scanf(" %c", &input) == EOF) {
            break; // Exit the loop on EOF
        }

        // if A call buildMatrix (function 1)
        if (input == 'A')
        {
        buildMatrix(matrix);
        MakeDist(matrix, dist);
        }
        
        // if B call hasPath (function 2)
        if (input == 'B')
        {
            scanf("%d %d", &Mi, &Mj);
            hasPath(dist, Mi, Mj);
        }

        // if C call shortestPathLength (function 3)
        if (input == 'C')
        {
            scanf("%d %d", &Mi, &Mj);
            shortestPathLength(dist, Mi, Mj);
        }


    } while (input != 'D');         //might want to chack EOF
    

    return 0;

}

/* ---------------------------- possible future bugs ----------------------------








*/