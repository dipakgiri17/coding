#include <stdio.h>

#define size 10

int graph[size][size], visited[size], total = 0;

void BFS(int vertex)
{
    printf("%d\t", vertex);
    visited[vertex] = 1; // this vertex is now also visited

    for (int j = 0; j < total; j++)
    {
        if (!visited[j] && graph[vertex][j] == 1)
        {
            BFS(j);
        }
    }
}

int main()
{

    printf("Enter the total number of vertex: ");
    scanf("%d", &total);

    printf("Enter the adjacency matrix: ");

    for (int i = 0; i < total; i++)
    {
        for (int j = 0; j < total; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < total; i++)
    {
        /**
         * initially all vertices are un-visited.
         */
        visited[i] = 0;
    }

    visited[0] = 1;

    printf("\nBFS Traversal is: ");
    BFS(0);

    return 0;
}