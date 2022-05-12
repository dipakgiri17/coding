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
}