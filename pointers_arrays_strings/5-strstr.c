#include "main.h"
#include <stddef.h>

/**
* _strstr - locates a substring
* @haystack: the string to search in
* @needle: the substring to search for
*
* Return: a pointer to the beginning of the located substring,
* or NULL if the substring is not found
*/
char *_strstr(char *haystack, char *needle)
{
while (*haystack)
{
	char *begin = haystack;
	char *pattern = needle;

	while (*haystack && *pattern && *haystack == *pattern)
	{
		haystack++;
		pattern++;
	}

	if (!*pattern)
		return (begin);

	haystack = begin + 1;
}

return (NULL);
}
