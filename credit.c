#include <stdio.h>
#include <cs50.h>

int main(void)
{
// number is for CC number
// a and i are for taking the sum of numbers which are not multiplied by 2.
// b and j are for taking the sum of numbers which are multiplied by 2.
    long number, a, b;
    int i, j;

    do
    {
        number = get_long_long("Number: ");
    }
    while (number < 0);

    // Taking the sum of the numbers which are not multiplied by 2.
    for (a = number, i = 0; a > 0; a /= 100)
    {
        i += a % 10;
    }

    // Taking the sum of the numbers which needs to be multiplied by 2 according to Luhn's algorithm.
    for (b = number / 10, j = 0; b > 0; b /= 100)
    {
        if (2 * (b % 10) >= 10)
        {
            j += (2 * (b % 10)) / 10;
            j += (2 * (b % 10)) % 10;
        }
        else
        {
            j += 2 * (b % 10);
        }
    }

    // Sum of all the elements of the CC number after being solved as per the Luhn's algorithm.
    int sum = i + j;

    // Checks whether the CC number is valid or not.
    if (sum % 10 == 0)
    {
        if ((number > 340000000000000 && number < 350000000000000) || (number > 370000000000000 && number < 380000000000000))
        {
            printf("AMEX\n");
        }
        else if (number > 5100000000000000 && number < 5600000000000000)
        {
            printf("MASTERCARD\n");
        }
        else if ((number > 4000000000000 && number < 5000000000000) || (number > 4000000000000000 && number < 5000000000000000))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
