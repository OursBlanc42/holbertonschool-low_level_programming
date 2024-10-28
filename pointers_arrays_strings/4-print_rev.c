#include <unistd.h>
#include "main.h"

/**
 * _puts - Entry point
 * Description: prints a string in reverse followed by a new line, to stdout.
 * @str : string to print
 * Return: nothing
 */

void print_rev(char *str)
{

	/* declare and initialize variable */
	int n = 0;

	/* loop through chain until null charactere ('\0') */
	while (str[n] != '\0')
	{
		/* increment n for each character founded */
		n++;
	}

	/* loop through chain in reverse */
	for (; n >= 0 ; n--)
	{
		_putchar(str[n]);
	}

	_putchar('\n');

}

