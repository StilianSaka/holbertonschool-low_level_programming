#include "main.h"

/**
* rev_string - Reverses a string.
* @s: Pointer to the string to be reversed.
*/
void rev_string(char *s)
{
int length = 0;
char *start, *end, temp;

while (*(s + length) != '\0')
	length++;

start = s;
end = s + length - 1;

while (start < end)
{
	temp = *start;
	*start = *end;
	*end = temp;
	start++;
	end--;
}
}
