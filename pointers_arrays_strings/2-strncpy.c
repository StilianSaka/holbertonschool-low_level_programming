#include "main.h"

/**
* _strncpy - Copies a string.
* @dest: The destination string buffer.
* @src: The source string.
* @n: The maximum number of bytes to copy from src.
*
* Return: A pointer to the destination string @dest.
*/
char *_strncpy(char *dest,  char *src, int n)
{
char *copy = dest;

while (*src && n > 0)
	{
	*dest++ = *src++;
	n--;
	}
	while (n > 0)
{
	*dest++ = '\0';
	n--;
}
return (copy);
}
