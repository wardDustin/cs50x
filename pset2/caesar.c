#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int alphaPos (char letter, int key);

int main(int argc, string argv[])
{
    if (argc!=2)
    {
        printf("You must type two- and only two- command arguments, please!!\n");
        return 1;
    }
    
    int key = atoi(argv[argc-1]); // sets the last command line argument to an integer (which will always be the second because of the above if statement)

    string plaintext = GetString(); // gets plaintext
    
    for (int i = 0, n = strlen(plaintext); i<n; i++)
    {
        int final = alphaPos (plaintext[i], key); // calls the function and sends the i'th letter of plaintext and the key to the cipher
        
        printf("%c", (char) final); // prints each final number as a character
    
    }
    printf("\n");
}

int alphaPos (char letter, int key)
{
    int alphaposition = 0; // determines where in the alphabet original plaintext letter is
    int cipherposition = 0; // determines where the user wants to move the plaintext letter to
    if (isalpha(letter)) 
        {
            if (isupper(letter))
            {
                alphaposition = (int) letter % 'A';
                cipherposition = (alphaposition + key) % 26;
                return cipherposition + 'A';
            }
            else
            {
                alphaposition = (int) letter % 'a';
                cipherposition = (alphaposition + key) % 26;
                return cipherposition + 'a';
            }
        }
        else
        {
            return letter;
        }
}