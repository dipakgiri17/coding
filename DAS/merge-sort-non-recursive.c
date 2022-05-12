#include <stdio.h>

int main()
{

    int arr[] = {33, 352, 3, 35, 865, 345, 45, 32, 323};

    printf("Array before sorting: ");

    printArray(arr, 9);

    merge(arr, 9);

    printf("Array after sorting: ");

    printArray(arr, 9);

    return 0;
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}

void merge(int x[], int n)
{
    int i, j, k, l1, l2, size = 1, u1, u2, aux[100];

    while (size < n)
    {
        l1 = 0;
        k = 0;

        while (l1 + size < n)
        {
            l2 = l1 + size;
            u1 = l2 - 1;
            if (l2 + size - 1 < n)
                u2 = l2 + size - 1;
            else
                u2 = l2 + size - 1;

            for (i = 1, j = l2; i <= u1 && j <= u2; k++)
            {
                if (x[i] < x[j])
                {
                    aux[k] = x[i++];
                }
                else
                {
                    aux[k] = x[j++];
                }
            }

            for (; i < i <= u1; k++)
            {
                aux[k] = x[i++];
                for (; j <= u2; k++)
                {
                    aux[k] = x[j++];
                    l1 = u2 + 1;
                }

                for (i = 0; i < n; i++)
                {
                    x[i] = aux[i];
                    size = size * 2;
                }
            }
        }
    }
}