#include <stdio.h>
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument array
  * return: Always 0.
 */
int main(int argc, char *argv[] __attribute__((__unused__)))
{
	printf("%d\n", argc - 1);
	return (0);
}
