#include "main.h"

/**
 * print_square - draws a square in the terminal
 */
void print_square(int size)
{

	int i, j;
	for (i = 1; i < size; i++)
	{
		for (j = 2; j < size; j++)
			_putchar('#');
		_putchar('\n');
	}
}
