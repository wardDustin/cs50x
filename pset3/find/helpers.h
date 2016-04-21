/**
 * helpers.h
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n);

//does the actual searching then returns an int to match up in bool search
bool binarySearch(int key, int array[], int min, int max);

/**
 * Sorts array of n values.
 */
void sort(int values[], int n);