#include "main.h"

/**
* _is_prime_helper - recursively checks if n is a prime number
* @n: the number to check
* @divisor: the current divisor to check
*
* Return: 1 if n is prime, 0 otherwise
*/
int _is_prime_helper(int n, int divisor)
{
if (n % divisor == 0)
	return (0);
if (divisor * divisor > n)
	return (1);
return (_is_prime_helper(n, divisor + 1));
}

/**
* is_prime_number - returns 1 if the input integer a prime number, otherwise 0
* @n: the number to check
*
* Return: 1 if n is prime, 0 otherwise
*/
int is_prime_number(int n)
{
if (n <= 1)
	return (0);
return (_is_prime_helper(n, 2));
}
