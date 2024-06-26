#include "main.h"
#include <unistd.h>

/**
* puts2 - Prints every other character of a string, starting with the first.
* @str: The string to be processed.
*/
void puts2(char *str)
{
int i;
char c;

if (str == NULL)
	return;

for (i = 0; str[i] != '\0'; i++)
{
	if (i % 2 == 0)
	{
		c = str[i];
		write(1, &c, 1);
	}
}
c = '\n';
write(1, &c, 1);
}
