#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
    //printf("Hi friend. What is your name?: "); check50 doesn't want a printf... boo... but this gets the input either way
    string name = GetString();
    
    // prints the zero index in name as a capital letter
    printf("%c", toupper(name[0]));
    
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        //this is checking for the space which precedes the initials of the middle or last names
        if (name[i]==' ')
        {
            //prints the character after the space, as a capital letter
            printf("%c", toupper(name[i+1]));
        }
    }
    printf("\n");
}