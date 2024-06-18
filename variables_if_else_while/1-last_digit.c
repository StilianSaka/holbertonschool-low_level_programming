#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/* more headers goes there */
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	
    last_digit = %1;
    
    if(last_digit > 5)
    {
        printf( "Last digit of %d is %d is less than %d and not 0\n",n,last_digit);
    }
     if(last_digit == 5)
    {
        printf( "Last digit of %d is %d and is 0\n",n, l);
    }
    if(last_digit < 6 && last_digit != 0)
    {
        printf( "Last digit of %d is %d and is less than 6 and not 0\n",n, l);
    }

	return (0);
}