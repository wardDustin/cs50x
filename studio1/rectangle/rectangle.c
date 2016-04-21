#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("I will draw you a rectangle of hearts!\nHow wide should it be: ");
    int width = GetInt();
    printf("How tall should it be: ");
    int height = GetInt();
    int w = 0;
    
    for (int counter = 0; counter < height; counter++)
    {
       while (w < width)
       {
            printf("<3");
            w++;
       }
       w=0;
       printf("\n");
    }
}