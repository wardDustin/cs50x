#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int answer = 9;
    printf("I am thinking of a number 1 - 10, can you guess what it is (You have five guesses)?\n");
    
    for (int counter = 1; counter<6; counter++)
    {
        printf("Guess #%i: ", counter);
        int x = GetInt();
        if (x==answer)
        {
            printf("Correct! You must be psychic!!\n");
            return 0;
        }
        else
        {
             printf("Wrong!\n");
        }
    }
    printf("Sorry, you ran out of guesses.\n");
    return 0;
}