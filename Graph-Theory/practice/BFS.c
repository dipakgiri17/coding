/**
 * Step by step implementation of Breath First Search.
 */

#include <stdio.h>

/* step 1: declear the constants and variables */

#define size 10
int graph[size][size], visited[size], total = 0;
void BFS(int vertex);

int main()
{

    /* step 2: take input of the number of vertices */

    printf("\nEnter the total number of vertex: ");
    scanf("%d", &total);

    /* step 3: take the adjacency matrix */

    printf("\nEnter adjacency matrix: ");
    for (int i = 0; i < total; i++)
        for (int j = 0; j < total; j++)
            scanf("%d", &graph[i][j]);

    printf("\nYour Entered adjacency matrix: \n");
    for (int i = 0; i < total; i++)
    {
        for (int j = 0; j < total; j++)
        {

            printf("%3d", graph[i][j]);
        }
        printf("\n");
    }

    printf("BFS Traversal is: ");

    /* step 4: call function BFS(0) */
    BFS(0);

    return 0;
}

/* step 5: Define BFS */

void BFS(int vertex)
{

    /* step 6: print the current visiting vertex */
    printf("%d ", vertex);

    /* step 7: set the vertex as visited */
    visited[vertex] = 1;

    /* step 8: for all vertex */
    for (int j = 0; j < total; j++)
    {

        /* step 9: if a vertex is not visited and has edge with current veretex, visit the vertex */
        if (!visited[j] && graph[vertex][j] == 1)
        {

            /* step 10: visit the vertex */
            BFS(j);
        }
    }
}