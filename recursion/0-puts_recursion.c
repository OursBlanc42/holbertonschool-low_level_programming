#include "main.h"

/**
 * _puts_recursion - Entry point
 * Description: display a string
 * @s: string to print
 * Return: /
 */

void _puts_recursion(char *s)
{
	if (*s != '\0')
	{
		_putchar(*s);
		s++;
		_puts_recursion(s);
	}
	else
	{
		_putchar('\n');
	}

}
