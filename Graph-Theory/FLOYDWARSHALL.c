#include <stdio.h>

#define INF 9999
#define nV 4

void PrintGraph(int graph[][nV])
{
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            if (graph[i][j] == INF)
            {
                printf("%4s ", "INF"); // prints total 4 charecters including "INF"
            }
            else
            {
                printf("%4d ", graph[i][j]); // prints total 4 digits including the value.
            }
        }
        printf("\n");
    }
}

void FloyeWarshall(int graph[][nV])
{

    int dist[nV][nV], i, j, k;

    for (i = 0; i < nV; i++)
    {
        for (j = 0; j < nV; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < nV; k++)
    {
        for (i = 0; i < nV; i++)
        {
            for (j = 0; j < nV; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\n");
    PrintGraph(dist);
}

int main()
{
    int graph[nV][nV];

    printf("Enter the Adjacency matrix: \n");
    // Example of an adjacency metrix: 0 9999 -2 9999 4 0 3 9999 9999 9999 0 2 9999 -1 9999 0
    for (int i = 0; i < nV; i++)
    {

        for (int j = 0; j < nV; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\n");
    PrintGraph(graph);

    FloyeWarshall(graph);
    return 0;
}
