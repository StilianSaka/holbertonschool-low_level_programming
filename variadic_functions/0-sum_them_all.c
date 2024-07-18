#include <stdarg.h>

/**
 * sum_them_all - sums all arguments passed
 *
 * @n: number of arguments
 *
 * Return: sum of arguments
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list numbers;
	unsigned int i;
	int sum;

	va_start(numbers, n);

	sum = 0;
	for (i = 0; i < n; i++)
		sum = sum + va_arg(numbers, int);

	va_end(numbers);

	return (sum);

}
