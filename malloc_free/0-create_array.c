#include <stdlib.h>

/**
 * create_array - Creates an array of chars
 * @size: The size of the array
 * @c: The char to initialize the array with
 *
 * Return: A pointer to the array, or NULL if it fails or if size is 0
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)

	return (NULL);

		array = malloc(size * sizeof(char));

	if (array == NULL)

	return (NULL);

	for (i = 0; i < size; i++)
	{
		array[i] = c;
		}
	return (array);
	}
