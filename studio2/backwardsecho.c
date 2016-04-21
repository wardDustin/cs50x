#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (int argc, string argv[])
{
    for (int i = 0, n = argc; i<n; i++)
    {
        for (int j = 0, k=strlen(argv[i]); k>=j; k--)
        {
            printf("%c", argv[i][k]);
        }
        printf(" ");
    }
    printf("\n");
}