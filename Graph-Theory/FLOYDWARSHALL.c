#include <stdio.h>

#define INF 9999
#define nV 4

void PrintGraph(int Graph[][nV])
{
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            if (Graph[i][j] == INF)
            {
                printf("%4s ", "INF"); // prints total 4 charecters including "INF"
            }
            else
            {
                printf("%4d ", Graph[i][j]); // prints total 4 digits including the value.
            }
        }
        printf("\n");
    }
}

void FloyeWarshall(int Graph[][nV])
{

    int D[nV][nV], i, j, k;

    for (i = 0; i < nV; i++)
    {
        for (j = 0; j < nV; j++)
        {
            D[i][j] = Graph[i][j];
        }
    }

    for (i = 0; i < nV; i++)
    {
        for (j = 0; j < nV; j++)
        {
            for (k = 0; k < nV; k++)
            {

                if (D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    printf("-----------------------------\n");
    PrintGraph(D);
}

int main()
{

    int Graph[nV][nV] = {
        {0, INF, -2, INF},
        {4, 0, 3, INF},
        {INF, INF, 0, 2},
        {INF, -1, INF, 0},
    };

    printf("-----------------------------\n");
    PrintGraph(Graph);
    FloyeWarshall(Graph);
    return 0;
}
