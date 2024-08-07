#include "main.h"

/**
* flip_bits - counts the number of bits you would need to flip to get from
* one number to another.
* @n: first number
* @m: second number
* Return: number of bits to flip
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int bit_diff = n ^ m;
	unsigned int count = 0;

	while (bit_diff != 0)
	{
		count += bit_diff & 1;
		bit_diff >>= 1;
	}

	return (count);
}
