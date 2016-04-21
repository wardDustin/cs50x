#include <stdio.h>
#include <cs50.h>
#include <string.h>

bool validate(int, char**, int);

void printGrid (int, char**, int);

int main(int argc, string argv[])
{
    int dimension = argc -1;
    
    if(!validate(argc, argv, dimension))
        return 1;
    
    printGrid(argc, argv, dimension);
    
}

bool validate(int argc, char** argv, int dimension)
{
    for (int a = 1, b = argc; a<b; a++)
    {
        if (strlen(argv[a])!=dimension)
        {
            printf("Length of the words need to be the same as the number of words (not including the program name)\n");
            return false;
        }
    }
    return true;
}

void printGrid(int argc, char** argv, int dimension)
{
    for (int i=0; i<dimension; i++)
    {
        for (int m = 1, n=argc; m<n; m++)
        {
            printf("%c", argv[m][i]);
        }
        printf("\n");
    }
}