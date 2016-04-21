#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Give me a phrase and I shall repeat it!: ");
    string repeat = GetString();
    
    int times;
    
    do
    {
        printf("And how many times shall I repeat \"%s\"? (between 1 and 100 times): ", repeat);
        times = GetInt();
    }
    while (times<1 || times>100);
    
    int counter=0;
    
    while (counter<times)
    {
    printf("%s\n", repeat);
    counter++;
    }
}