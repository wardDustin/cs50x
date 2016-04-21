#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

//Prototypes for the functions we need
string GetString(void);
void append(int c);
void prepend(int c);

//Node structure definition
typedef struct node
{
    // the value to store in this node
    int n;

    // the link to the next node in the list
    struct node* next;
    
    // the link to the previous node
    struct node* prev;
}
node;

//A simple main method to test our function
int main(void)
{
    printf("Please give me a string: \n");
    char* x = GetString();
    printf("Thanks for the %s!\n", x);
}

//The head of our linked list
node* head = NULL;
node* tail = NULL;

string GetString(void)
{

    // number of chars actually in buffer
    unsigned int n = 0;

    // character read or EOF
    int c;

    // iteratively get chars from standard input
    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        //append the character to our linked list
        prepend(c);
        //update the number of characters
        n++;
    }

    // return NULL if user provided no input
    if (n == 0 && c == EOF)
    {
        return NULL;
    }

    //create a string to hold our result
    char* minimal = malloc((n + 1) * sizeof(char));

    //iterate through the list, adding each character to the string
    node* curr = tail;
    for(int i = 0; i < n; i++)
    {
        minimal[i] = curr->n;
        curr = curr->prev;
    }

    // terminate string
    minimal[n] = '\0';

    // return string
    return minimal;
}

void append(int c)
{
    //create a new node
    node* newNode = malloc(sizeof(node));
    newNode->n = c;
    newNode->next = NULL;
    newNode->prev = NULL;

    //if the list is empty, our node is the only node
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        //iterate through the list until we find the end
        node* curr = head;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        //append the new node to the end of the list
        curr->next = newNode;
        newNode->prev = curr; 
        
        if(curr==NULL)
            tail = curr;
    }
}

void prepend(int c)
{
    node* newNode = malloc(sizeof(node));
    newNode->n = c;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if (tail == NULL)
        tail = newNode;
    else
    {
        node* curr = tail;
        while(curr->prev!=NULL)
        {
            curr=curr->prev;
        }
        curr->prev=newNode;
        newNode->next=curr;
        
        if(curr==NULL)
            head=curr;
    }
}