#include "main.h"
#include <stdlib.h>

/**
 * binary_to_uint - function that converst a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 * Return: the converted number or 0 if there is one or more chars in the
 * string b that is not 0 or 1, b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int s = 0, w = 1;
	int j, l = 0;

	if (b == NULL)
		return (0);
	for (j = 0; b[j] != '\0'; j++)
		l++;
	for (j = (l - 1); j >= 0; j--)
	{
		if (b[j] != '0' && b[j] != '1')
			return (0);
		if (b[j] == '1')
			s = s + w;
		w = w * 2;
	}
	return (s);
}
