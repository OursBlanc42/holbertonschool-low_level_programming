#include <unistd.h>
#include "main.h"

/**
 * print_sign - Entry point
 * Description: Print the sign of a number.
 * @n : number to check to check
 * Return: 0 if n = zero  / 1 if if n>0 / -1 if n<0
 */

int print_sign(int n)
{
	/* check the sign of n */

	if (n > 0)
	{
	_putchar('+');
	_putchar(n);
	return (1);
	}

	else if (n < 0)
	{
	_putchar('-');
	_putchar(n);
	return (-1);
	}

	else
	{
	_putchar(n);
	return (0);
	}

}
