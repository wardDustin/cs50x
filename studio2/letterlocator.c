#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int alphaPos (char letter);

int main(void)
{
    char letter;
    
    do
    {
        printf("Give me a letter, please: ");
        letter = GetChar();
    }
    while (isalpha(letter) == false);
    
    int position = alphaPos (letter);
    
    printf("%c is at position %i\n", letter, position);
}

int alphaPos (char letter)
{
    if (isalpha(letter))
        {
            if (isupper(letter))
            {
                return (int) letter % 'A';
            }
            else
            {
                return (int) letter % 'a';
            }
        }
        return 0;
}