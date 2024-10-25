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
	/* declare variable */
	int last_digit;

	/* with modulo extract last digit */
	last_digit = n % 10;

	return (last_digit);
}
