#include <stdio.h>
#include <stdlib.h>

int graph[10][10], visited[10], total, arr[30];
int k = 0, count = 0;

void DFS(int vertex)
{
    int c = 0;

    count++;

    printf("%d\t", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < total; i++)
    {

        if (!visited[i] && graph[vertex][i] == 1)
        {
            arr[++k] = i;
            c = 1;
        }

        if (count == total)
        {
            exit(0);
        }
    }

    if (c == 1)
    {
        DFS(arr[k]);
    }
    else
    {
        k--;
        DFS(arr[k]);
    }
}

int main()
{

    printf("Enter the total number of vertices in graph: ");
    scanf("%d", &total);

    printf("Enter the Adjacency matrix: \n");

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

    printf("\nDFS Traversal is: ");
    DFS(0);

    return 0;
}