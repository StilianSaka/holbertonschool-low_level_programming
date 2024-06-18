#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/* more headers goes there */
/* betty style doc for function main goes there */
/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(void)
{
char c;
for (c = 0; c < 10; c++)
{
putchar(c + '0');
}
putchar('\n');
return (0);
}
