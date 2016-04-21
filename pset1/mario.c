#include <stdio.h>
#include <cs50.h>

void GoPyramidGo (int height);

int main(void)
{
    printf("Mario, let's make your pyramid out of hashtags!\n");

    int height;

    do
    {
        printf("Please keep it between 1 and 23. How tall do you want it: ");
        height = GetInt();
    }
    while (height < 0 || height > 23);
    
    GoPyramidGo(height);
    
}

void GoPyramidGo(int height)
{
    int tall = height;
    
    for (int counter = 0; counter < tall; counter++)
    {
                
        for (int x = 1; x < height; x++)
        {
            printf(" ");
        }
        
        height--;
        
        for (int y = tall; y>=height; y--)
        {
            printf("#");
        }
        
        printf("\n");
    }
}
        
        