#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("How many minutes did you spend in the shower today?: ");
    int x = GetInt();
    x = x*12;
    printf("Dude, you're using: %i bottles\n", x);
}