#include <stdio.h>

void printArrayInt(int array[], int arraySize)
{
    int i;

    for (i = 0; i < arraySize; i++)
    {
        if (i == 0)
        {
            printf("[%d, ", array[i]);
        }

        else if (i == arraySize - 1)
        {
            printf("%d]", array[i]);
        }

        else
        {
            printf("%d, ", array[i]);
        }
    }
}