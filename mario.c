#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for valid input about how tall and short they want pyramid to be
    // Height must be between 1 and 8 (inclusive)
    int height;
    do
    {
        height = get_int("Height: ");
        if (height < 1 || height > 8)
        {
            printf("Please enter a valid integer between 1 and 8 (inclusive): \n");
        }
    }
    while (height < 1 || height > 8);

    // Build and print the pyramid
    // Pyramid has 2 parts(left and right) with a gap of 2 spaces in between
    // Each row of it has spaces followed by hash symbol(#), gap, and #, like so:
    // .....#..#
    // ....##..##
    // ...###..### and so on

    // Loop through each row of the pyramid
    for (int i = 1; i <= height; i++)

    {
        // Print spaces for the left side before hashes
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        // Print left hashes
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        // Print the gap
        printf("  ");
        // Print right hashes
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        // Move to the next line for the next level
        printf("\n");
    }
}