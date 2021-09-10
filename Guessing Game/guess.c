#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void saveToFile(int points)
{
    FILE *fp;
    char array[255];

    fp = fopen("test.txt", "w");

    if (fp == NULL)
    {
        exit(-1);
    }

    fprintf(fp, "%d", points);

    fclose(fp);
}

int readFromFile()
{
    FILE *fp;
    char *str = "string";

    char array[255];

    fp = fopen("test.txt", "r");

    if (fp == NULL)
    {
        exit(-1);
    }

    fscanf(fp, "%s", array);

    fclose(fp);

    return atoi(array);
}

int generateRandomNumber(int lowerBound, int upperBound)
{
    int randomNumber = (rand() % (upperBound - lowerBound + 1)) + lowerBound;
    return randomNumber;
}

int main()
{
    srand(time(NULL));

    char *filename = "points.txt";

    int guesses = 5, points = readFromFile(), lowerBound = 1, upperBound = 20;
    int randomNumber = generateRandomNumber(lowerBound, upperBound);
    int inputNumber;

    printf("Guess a number between (%d and %d) | You have %d tries left\n", lowerBound, upperBound, guesses);

    while (guesses > 0)
    {
        printf("Random: %d\n", randomNumber);
        scanf("%d", &inputNumber);

        if (inputNumber < randomNumber)
        {
            guesses -= 1;
            points -= 1;
            printf("Guess higher| -1 point | Lives: %d\n", guesses);
        }

        if (inputNumber > randomNumber)
        {
            guesses -= 1;
            points -= 1;
            printf("Guess lower| -1 point | Lives: %d\n", guesses);
        }

        if (inputNumber == randomNumber)
        {
            points += 10;
            printf("Nice guess, +10 points bekommen | Your points: %d\n", points);
            randomNumber = generateRandomNumber(lowerBound, upperBound);
            guesses = 5;
        }

        printf("Points: %d\n", points);
        saveToFile(points);
    }

    return 0;
}
