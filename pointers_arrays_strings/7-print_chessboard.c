#include "main.h"
#include <stddef.h>

/**
* print_chessboard - prints the chessboard
* @a: 2D array representing the chessboard
*
* Description: Prints the chessboard stored in a 2D array of characters
*/
void print_chessboard(char (*a)[8])
{
int i, j;

for (i = 0; i < 8; i++)
{
	for (j = 0; j < 8; j++)
	{
		_putchar(a[i][j]);
	}
	_putchar('\n');
}
}
