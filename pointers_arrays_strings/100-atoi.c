#include "main.h"

/**
* _atoi - Converts a string to an integer.
* @s: Pointer to the string to be converted.
*
* Return: The converted integer.
*/
int _atoi(char *s)
{
int sign = 1;
unsigned int num = 0;
int found_num = 0;

while (*s)
{
	if (*s == '-')
		sign *= -1;
	else if (*s >= '0' && *s <= '9')
	{
		num = num * 10 + (*s - '0');
		found_num = 1;
	}
	else if (found_num)
		break;
	s++;
}

return (sign * num);
}
