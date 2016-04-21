#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Welcome to the Dustin's Donuts!\nToday's Manager Special is:\n");
    printf("Fruity Pebble Crunch: A long john style donut with vanilla topping sprinkled with fruity pebbles\n");
    printf("How many donuts would you like (you can order fractional donuts)?: ");
    float donut = GetFloat();
    while (donut<0 || donut==0)
    {
       if (donut<0)
       {
            printf("So, you're going to make it for us? Maybe try a positive number please: ");
            donut = GetFloat();
       }
       else //if (donut==0)
       {
        printf("Then why are you even here? Please order a positive amount!: ");
        donut = GetFloat();
       }
    }
    printf("How much would you like to pay per donut (suggested price is $3.50 each)?: ");
    float price = GetFloat();
    float final = donut*price*1.05;
    printf("Ok, let me get that for you....\nAfter tax, your total is: $%f\n", final);
    printf("Thank you for snacking with us! Come on back around here soon!\n");
}
