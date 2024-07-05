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
	int i, j, result;

	result = 0;
	for (i = 0; i < argc; i++)
	{
		result += atoi(argv[i]);
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}
	}

	printf("%d\n", result);
	return (0);
}
