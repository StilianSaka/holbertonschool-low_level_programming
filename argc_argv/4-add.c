#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument array
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int i, result;

	result = 0;
	for (i = 0; i < argc; i++)
	{
		result += atoi(argv[i]);
	}

	printf("%d\n", result);
	return (0);
}
