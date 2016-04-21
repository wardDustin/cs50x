#include <stdio.h>
#include <cs50.h>
#include "mult.h"

//TODO: Write a recursive function that computes exponents.
//This function will rely upon your multiplication function, so you should do that first!
int expt(int, int);

int main() {
    //Test multiplication:
    printf("2 * 2 = %i\n", mult(2, 2));
    printf("3 * 9 = %i\n", mult(3, 9));
    printf("-3 * 9 = %i\n", mult(-3, 9));
    printf("3 * -9 = %i\n", mult(3, -9));
    printf("-3 * -9 = %i\n", mult(-3, -9));

    //Test exponentiation:
    printf("2^8 = %i\n", expt(2, 8)); //should be 256
    printf("2^3 = %i\n", expt(2, 3)); //should be 8
    printf("(-2)^3 = %i\n", expt(-2, 3)); //should be -8
}

int expt(int x, int y)
{
    if (y==1)
        return x;
    else
        return mult(x, expt(x,y-1));
}