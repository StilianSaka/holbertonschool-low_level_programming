#include "main.h"

/**
* _strcmp - Compares two strings s1 and s2.
* Returns an integer less than, equal to, or greater than zero
* if s1 is found, respectively, to be less than, to match, or be
* greater than s2.
* @s1: A pointer to the first string to be compared.
* @s2: A pointer to the second string to be compared.
* Return: An integer less than, equal to, or greater than zero if s1 is found,
* respectively, to be less than, to match, or be greater than s2.
*/
int _strcmp(char *s1, char *s2)

{
while (*s1 && (*s1 == *s2))
{
	s1++;
	s2++;
}
return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
