#include <stdio.h>

#define size 10

int graph[size][size], visited[size], total = 0;

void BFS(int vertex)
{
    printf("%d\t", vertex);
    visited[vertex] = 1;

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

    printf("\nEnter the total number of vertex: ");
    scanf("%d", &total);

    printf("\nEnter the adjacency matrix: \n");
    // for example: 0 1 1 1 0 1 1 0 0 1 1 1 0 0 1 1 0 0 0 0 0 0 1 0 0

    for (int i = 0; i < total; i++)
    {
        for (int j = 0; j < total; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < total; i++)
    {
        visited[i] = 0;
    }

    visited[0] = 1;

    printf("\nBFS Traversal is: ");
    BFS(0);

    return 0;
}