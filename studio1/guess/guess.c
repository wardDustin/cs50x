#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int answer = 9;
    printf("I'm thinking of a number 1 - 10. Can you guess what it is?\n");
    int counter = 1;
    int x;
    do
    {
        printf("Guess #%i: ", counter);
        x = GetInt();
    }
    while(x<1 || x>10);
    
    while (x!=answer)
    {
        printf("Wrong!\n");
        counter++;
        printf("Guess #%i: ", counter);
        x = GetInt();
    }
    if (x==answer)
    {
        printf("Correct! You must be psychic!\n");
        return 0;
    }
}




/* do
    {
        printf("Guess #%i: ", counter);
        int x = GetInt();
        counter++;
        if (x!=answer)
        {
            printf("Wrong!\n");
        }
        else
        {
            printf("Correct! You must be psychic!\n");
            return 0;
        }
    }
    while (counter<6);
    printf("Sorry, you ran out of guesses!\n");
    return 0;*/