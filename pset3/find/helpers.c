#include <cs50.h>
#include "helpers.h"

bool search(int value, int values[], int n);
bool binarySearch(int key, int array[], int min, int max);
void sort(int values[], int n);


bool search(int value, int values[], int n)
{
    int m = 0;
    if (binarySearch(value, values, m, n))
        return true;
    else
        return false;
}

bool binarySearch(int key, int array[], int min, int max)
{
    int midpoint;
    
    if (min>max)
        return false;
    else
        midpoint = min + ((max - min)/2);
        
        if (array[midpoint] < key)
            return binarySearch(key, array, midpoint+1, max);
        else if (array[midpoint] > key)
            return binarySearch(key, array, min, midpoint-1);
        else
            return true;
}

void sort(int values[], int n)
{
    int swaps = 0;
    do
    {
        swaps = 0;
        for (int j = 0; j < n; j++)
        {
            if (values[j]>values[j+1])
            {
                int temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
                swaps++;
            }
        }
    }
    while (swaps!=0);
}