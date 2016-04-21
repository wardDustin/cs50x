#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    
    int penny=0;
    int nickle=0;
    int dime=0;
    int quarter=0;
    
    float change;
    do
    {
        printf("Hello, friend. How much change do I owe you, again?: ");
        change = GetFloat();
    }
    while (change<=0);
    
    change = round(change*100);
    
    while (change>=25)
    {
        change=change-25;
        quarter++;
    }
    while (change>=10)
    {
        change=change-10;
        dime++;
    }
            
    while (change>=5)
    {
        change=change-5;
        nickle++;
    }
    
    while (change>=1)
    {
        change=change-1;
        penny++;
    }
    
    int coins = quarter + dime + nickle + penny;
    
    printf("%i\n", coins);
    /* prints out how many of each :)
    printf("%i quarter(s), %i dime(s), %i nickle(s), %i pennie(s)\n", quarter, dime, nickle, penny);*/
}