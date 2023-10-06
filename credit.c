// Objective: Create a program that checks if a given credit card number is valid based on Luhn’s Algorithm
// and then determine whether the credit card is an AMEX, MASTERCARD, or VISA.
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // 1. Prompt for input
    long number = get_long("Number: ");

    // 2. Calculate checksum using Luhn’s Algorithm
    int sum = 0; // stores the sum for Luhn's algorithm
    int digits = 0; //keeps track of the number of digits in the card number
    int start = 0; //holds the first digit(from the left) of the card number
    int second_digit = 0; //holds the second digit (from the left) of the card number

    while (number > 0)
    {
        second_digit = start;
        start = number % 10;

        if (digits % 2 == 1)
        {
            int mult = start * 2;
            sum += mult / 10 + mult % 10;
        }
        else
        {
            sum += start;
        }

        number /= 10;
        digits++;
    }

    // 3. Check for card length and starting digits
    if (sum % 10 == 0)
    {
        if ((digits == 15) && (start == 3) && (second_digit == 4 || second_digit == 7))
        {
            printf("AMEX\n");
            return 0;
        }
        else if ((digits == 16) && (start == 5) && (second_digit > 0 && second_digit < 6))
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if ((digits == 13 || digits == 16) && (start == 4))
        {
            printf("VISA\n");
            return 0;
        }
    }

    // 4. Print INVALID
    printf("INVALID\n");
    return 0;
}
