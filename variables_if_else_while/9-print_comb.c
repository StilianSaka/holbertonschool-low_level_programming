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
        for (int j = i + 1; j <= 9; j++)
        {
            putchar(i + '0');
            putchar(',');
            putchar(' ');
            putchar(j + '0');
            if (i != 8 || j != 9)
            {
                putchar(',');
                putchar(' ');
            }
        }
    }
    putchar('\n');
    return 0;
}
