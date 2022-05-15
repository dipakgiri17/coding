/**
 * @file BFS.c(works)
 * @brief BFS, it takes adjecency matrix as input and gives the path as output 
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

int graph[10][10], visited[10], total;

void bfs(int vertex)
{
    int j;
    printf("%d", vertex);
    visited[vertex] = 1;

    for (j = 0; j < total; j++)
    {
        if (!visited[j] && graph[vertex][j] == 1)
        {
            bfs(j);
        }
    }
}

void main()
{

    printf("Enter the number of total vertex: ");
    scanf("%d", &total);

    printf("Enter the adj matix: ");

    for (int i = 0; i <= total; i++)
    {
        for (int j = 0; j <= total; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    for (int i = 0; i < total; i++)
    {
        visited[i] = 0;
    }

    bfs(0);
}
