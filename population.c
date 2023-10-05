#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
int start_size;
do
{
    start_size = get_int("Start size: ");
    if (start_size < 9)
    {
        printf("Please enter a number greater than or equal to 9:\n");
    }
}
while (start_size < 9);


    // TODO: Prompt for end size
int end_size;
do
{
    end_size = get_int("End size: ");
    if(end_size<start_size)
    {
        printf("Please enter a number that is greater than or equal to the starting population size:\n");
    }
}
while (end_size < start_size);

    // TODO: Calculate number of years until we reach threshold
int years = 0;
while (start_size < end_size)
{
    int births = start_size / 3;
    int deaths = start_size / 4;
    start_size = start_size + births - deaths;
    years++;
}

    // TODO: Print number of years
printf("Years: %i\n", years);

}
