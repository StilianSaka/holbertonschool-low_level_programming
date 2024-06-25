#include "main.h"

/**
 * swap_int -  swaps the values of two integers
 * @a: pointer to the first intiger
 * @b: pointer to the second intiger
 */
void swap_int(int *a, int *b)

{
	int temp = *a;
	*a = *b;
	*b = temp;
}
