#include <unistd.h>
#include "main.h"

/**
 * print_last_digit - Entry point
 * Description: Display last digit of N number
 * @n : number to check
 * Return: last digit
 */

int print_last_digit(int n)
{
	/* with modulo extract last digit */
	n = n%10
	/* display */
	_putchar(n);

	return (n);
}
