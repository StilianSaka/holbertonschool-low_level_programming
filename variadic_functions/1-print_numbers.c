#include <stdarg.h>
#include "variadic_functions.h"
#include <stdio.h>

/**
 * sum_them_all - sums all arguments passed
 *
 * @n: number of arguments
 *
 * Return: sum of arguments
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list numbers;
	unsigned int i;
	(void) separator;

	va_start(numbers, n);

	for (i = 0; i < n; i++)
	{
		if (i == n - 1)
			printf("%d", va_arg(numbers, int));
		else
			printf("%d%s", va_arg(numbers, int), separator);

	}

	printf("\n");

	va_end(numbers);

}
