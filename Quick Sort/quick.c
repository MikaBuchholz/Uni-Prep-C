#include <stdio.h>
#include "printArray.h"
#include <stdlib.h>

void fillArray(int lowerBound, int upperBound, int array[], int range)
{
    int i;

    for (i = 0; i < range; i++)
    {
        int randomNumber = (rand() % (upperBound - lowerBound + 1)) + lowerBound;
        array[i] = randomNumber;
    }
}

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

int partition(int array[], int low, int high)
{
    int index, pivot, j;

    index = low - 1;
    pivot = array[high];

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            index += 1;
            swap(&array[index], &array[j]);
        }
    }

    swap(&array[index + 1], &array[high]);
    return index + 1;
}

void quickSort(int array[], int low, int high)
{
    int part;
    if (low < high)
    {
        part = partition(array, low, high);

        quickSort(array, low, part - 1);
        quickSort(array, part + 1, high);
    }
}

int main()
{
    int lower = 20, upper = 30000, range = 200;
    int array[range];

    fillArray(lower, upper, array, range);
    int arrayLength = sizeof(array) / sizeof(int);

    /*printArrayInt(array, arrayLength);*/
    quickSort(array, 0, arrayLength - 1);
    printArrayInt(array, arrayLength);

    return 0;
}