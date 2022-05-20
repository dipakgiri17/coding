#include <stdio.h>

#define INFINITY 9999
#define MAX 10

void Dijkstra(int Graph[MAX][MAX], int n, int start)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (Graph[i][j] == 0)
            {
                cost[i][j] = INFINITY;
            }
            else
            {
                cost[i][j] = Graph[i][j];
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n - 1)
    {
        mindistance = INFINITY;
        for (i = 0; i < n; i++)
        {
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;

        for (i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
        count++;
    }

    for (i = 0; i < n; i++)
        if (i != start)
        {
            printf("\nDistance from source to %d: %d", i, distance[i]);
        }
}

int main()
{

    int Graph[MAX][MAX], i, j, n, u;

    n = 7;

    printf("Enter the adjacency matrix: \n");
    // for example: 0 3 6 0 0 0 0 3 0 2 4 0 0 0 6 2 0 1 4 2 0 0 4 1 0 2 0 4 0 0 4 2 0 2 1 0 0 2 0 2 0 1 0 0 0 4 1 1 0

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            scanf("%d", &Graph[i][j]);
        }
    }

    u = 0;

    Dijkstra(Graph, n, u);

    return 0;
}