#include "main.h"

/**
* get_bit - gets the value of a bit at a given index
* @n: the number to extract the bit from
* @index: the index of the bit to extract (starting from 0)
* Return: value of the bit at index, or -1 if an error occurred
*/
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	return (-1);

	return ((n >> index) & 1);
}
