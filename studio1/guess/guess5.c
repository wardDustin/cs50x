#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int answer = 9;
    printf("I'm thinking of a number 1 - 10. Can you guess what it is (You have five guesses)?\n");
    int counter = 1;
    do
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
    return 0;
}