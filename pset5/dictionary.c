/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

#include "dictionary.h"

#define LENGTH 45
#define SIZE 143091

//create a struct to help form and traverse hash function 
typedef struct node
{
    char word[LENGTH+1];
    struct node* next;
} node;

// function defined below
node* chop (node* newNode);

// creation of hashtable full of pointers
node* hashtable[SIZE] = { NULL };

// tracks the size of the dictionary
unsigned int dictSize = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int n = strlen(word);
    
    char noCase[n+1];
    
    //makes case insensitive
    for(int i=0; i<n; i++)
    {
        noCase[i] = tolower(word[i]);
    }
    
    //add a null terminator to use strncmp
    noCase[n] = '\0';
    
    //hashes the strings
    unsigned int hashkey = fnv_hash(noCase);
    
    //indexes into array at the appropriate hash
    node* findWord = hashtable[hashkey];
    //check ti make sure the basket contains anything
    if (findWord==NULL)
        return false;
    
    //traverse down the linked list if word isn't found
    while (findWord!=NULL)
    {
        if (!strncmp(findWord->word, noCase, LENGTH+1))
            return true;
        else
            findWord = findWord->next;
    }
    //if word isn't found
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* inputFile = fopen(dictionary, "r");
    if (inputFile == NULL)
        return false;
    
    node* newNode = malloc(sizeof(node));
    newNode->next = NULL;
    
    while(fgets(newNode->word, 47, inputFile)!=NULL)
    {   
        //fgets returns a string with a newline character at the end
        //this function chops that off
        chop(newNode);
        
        //decides where the node will be indexed into the array
        unsigned int hashkey = fnv_hash(newNode->word);
        
        newNode->next = hashtable[hashkey];
        
        hashtable[hashkey] = newNode;
        
        //keeps track of the dictionary
        dictSize++;
        
        //use calloc instead of malloc because it 
        newNode = malloc(sizeof(node));
        newNode->next = NULL;
    }
    
    free(newNode);
    fclose(inputFile);
    
    return true;
}

node* chop (node* newNode)
{
    for (int i=0, n = strlen(newNode->word); i<n; i++)
    {
        if (newNode->word[i] == '\n')
            newNode->word[i] = '\0';
    }
    
    return newNode;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dictSize;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        node* freeWord = hashtable[i];
        if (freeWord == NULL)
            continue;
            
        while (freeWord != NULL)
        {
            node* temp = freeWord;
            freeWord = freeWord->next;
            free(temp);
        }
    }
    
    return true;
}

/**
 * Fowler/Noll/Vo hash function
 */
unsigned int fnv_hash(const char *key)
{
    const char *p = key;
    unsigned h = 2166136261;
    int n = strlen(key);
    int i;

    for (i = 0; i < n; i++)
    {
        h = (h * 16777619) ^ p[i];
    }

    return h%SIZE;
}