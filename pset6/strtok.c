#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){

char word[] = "Blah.html";
char* word2;
// char* word3;

printf("%s\n", word);

word2 = strtok(word, ".");
word2 = strtok(NULL, "\0");

printf("%s\n", word2);
    
}