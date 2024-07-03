#include "main.h"
#include <stdio.h>

/**
* print_diagsums - prints the sum of the two diagonals of a square matrix
* @a: pointer to the first element of the matrix
* @size: size of the matrix (number of rows or columns)
*
* Calculates the sum of the main diagonal (top-left to bottom-right)
* and the secondary diagonal (top-right to bottom-left) of the matrix
* and prints them in the format specified.
*/
void print_diagsums(int *a, int size)
{
int i;
int sum1 = 0, sum2 = 0;

for (i = 0; i < size; i++)
{
	sum1 += *(a + i * size + i);
	sum2 += *(a + i * size + (size - 1 - i));
}

printf("%d, %d\n", sum1, sum2);
}
