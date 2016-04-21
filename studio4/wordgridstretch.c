#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, char** argv)
{
    if (argc!=4)
    {
        printf("I need three command line arguments (not including the program name) please!\n");
        return 1;
    }
    
    if (strlen(argv[1]) != strlen(argv[2]) || strlen(argv[1]) != strlen(argv[3]))
    {
        printf("This program only accepts strings of the same length!\n");
        return 2;
    }
    
    printf("Your word grid currently looks like: \n");
    for (int i=1, j = argc-1; i<j+1; i++)
    {
        for (int m = 0, n=strlen(*(argv+1)); m<n; m++)
        {
            printf("%c", argv[i][m]);
        }
        printf("\n");
    }
    
    printf("Now I will stretch it vertically! How many should I stretch it by: ");
    int x = GetInt();
    
    while (x<=0)
    {
        printf("I need a positive integer, please! ");
        x=GetInt();
    }
    
    printf("After stretching by %i, you now have this: \n", x);
    
    for (int f=1; f<=argc-1; f++)
    {
        for (int g = 0; g<x; g++)
        {
            for (int e = 0, q=strlen(argv[1]); e<q; e++)
            {
                for (int i = 0; i<x; i++)
                {
                    printf("%c", argv[f][e]);
                }
            }
            printf("\n");
        }
    }
}

