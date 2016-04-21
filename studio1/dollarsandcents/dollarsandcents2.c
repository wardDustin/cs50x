#include <stdio.h>
#include <cs50.h>
#include <math.h>

float roundMoney (float amount);

int main(void)
{
    printf("Gimme a crazy dollar amount, yo!: ");
    float amount = GetFloat();
    roundMoney(amount);
    printf("Oh, I actually think you mean \"$%.2f\"\n", amount);
}

float roundMoney (float amount)
{
    amount=amount*100;
    amount = round(amount);
    amount = amount/100;
    return amount;
}