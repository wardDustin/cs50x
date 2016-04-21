#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    int n = 0;
    if (strlen(argv[0])>strlen(argv[1]))
    {
        n = strlen(argv[0]);
    }
    else
    {
        n = strlen(argv[1]);
    }
    for (int i = 0; i<n; i++)
    {
        if (strlen(argv[0])>strlen(argv[1]))
        {
            printf("%c", argv[0][i]);
            printf("%c", argv[1][i%(strlen(argv[1]))]);
        }
        else
        {
            printf("%c", argv[0][i%(strlen(argv[0]))]);
            printf("%c", argv[1][i]);
        }
    }
    printf("\n");
}

