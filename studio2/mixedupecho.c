#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    int length = 0;
    for (int i=0; i<argc; i++) // checking for which argument is the longest
    {
        if (strlen(argv[i])>length) // this will always be true at first (as length =0) and false until the length of any argument [i] is bigger. Runs for the number of arguments (argc)
        {
            length = strlen(argv[i]); // sets integer length to longest argument
        }
    }
    
    for (int i = 0; i<length; i++) // loops for the amount of times of the longest arguments
    {
        for (int j = 0; j<argc; j++) //second loop runs for the length of argument count
        {
            printf("%c", argv[j][i%strlen(argv[j])]); // this works because you are printing the first character in each string represented by [j] here and it runs the number of arguments (argc)
                                                      // i is moduled the string length of argv (a string) [j] (a certain one in the array) to make sure it loops after it ends
        }
    }
    printf("\n");
}