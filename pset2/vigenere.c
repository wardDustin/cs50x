#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int AlphaToAscii (char letter, int key);

int MakeKey (char c);

int main(int argc, string argv[])
{
    if (argc!=2)
    {
        printf("You must type two- and only two- command arguments, please!!\n");
        return 1;
    }
    
    for (int a = 0, m = strlen(argv[1]); a<m; a++)
    {
        if (!isalpha(argv[1][a]))
        {
            printf("Keyword must only contain letters A-Z and a-z\n");
            return 1;
        }
    }

    string plaintext = GetString(); // gets plaintext
    
    int key = 0;
    int final = 0;
    
    for (int i = 0, j=0, n = strlen(plaintext); i<n; i++) // 'i' iterates for the length of the whole plaintext, while j keeps count of which letter in plaintext and the key
    {
        
        key = MakeKey(argv[1][j]); // builds the key
        
        if (isalpha(plaintext[i])) 
        {
            final = AlphaToAscii(plaintext[i], key); // finds alphaposition and converts to ascii position
            j++;
        }
        else
        {
            final = plaintext[i]; // keeps the key from iterating and just prints the original non-alpha character
        }
        
        j%=strlen(argv[1]); // modules j by the length of the key
        
        printf("%c", (char) final); // prints each final number as a character
    
    }
    printf("\n");
}

int AlphaToAscii (char letter, int key)
{
    int alphaposition = 0;
    int newposition = 0;
    int final = 0;
    if (isupper(letter)) // Because of ascii codes differentiate between a capital and lowercase letter (obvious reasons), must have different codes for each
    {
        alphaposition = letter % 'A'; // finds where the position of the ascii coded letter is in the alphabet
        newposition = (alphaposition + key) % 26; // adds the predetermined key to move to a new letter in the alphabet
        return final = newposition + 'A'; // finally put the newposition back into ascii code for the computer to interpret
    }
    else
    {
        alphaposition = letter % 'a'; // finds where the position of the ascii coded letter is in the alphabet
        newposition = (alphaposition + key) % 26; // adds the predetermined key to move to a new letter in the alphabet
        return final = newposition + 'a'; // finally put the newposition back into ascii code for the computer to interpret
    }
}

int MakeKey (char c)
{
    return tolower(c) % 'a'; // since both lower and upper case letters are the same in their position within the alphabet, this converts either to lower and generates the key
}