#include <stdlib.h>
#include <string.h>

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter
 * @str: The string to duplicate
 *
 * Return: A pointer to the duplicated string, or NULL if str is NULL
 *         or if insufficient memory was available
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int length;

	if (str == NULL)
	return (NULL);

	length = strlen(str);
	dup = malloc((length + 1) * sizeof(char));
	if (dup == NULL)
	return (NULL);

	strcpy(dup, str);

	return (dup);
	}
