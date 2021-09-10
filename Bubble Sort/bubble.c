#include <stdio.h>

void printArray(int arr[5], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d", arr[i]);

    printf("\n");
    }
}

void swapElements(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main()
{
    int i;
    int j;

    int array[5] = {5, 4, 3, 2, 1};
    
    int arraySize = sizeof(array) / sizeof(int);

    for (i = 0; i < arraySize; i++) 
    {
        for (j = 0; j < arraySize - i; j++) {
            if (array[j] > array[j + 1]) {
                swapElements(&array[j], &array[j + 1]);
            }
        }
    }

    printArray(array, arraySize);
    return 0;
}


