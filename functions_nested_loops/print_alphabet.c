#include <unistd.h>
#include "main.h"

/**
 * print_alphabet = display alphabet to screen
 * _putchar: Emulate function putchar
 */

void print_alphabet(void)
{
	char *str = "abcdefghijklmnopqrstuvwxyz";

	while (*str)
	{
		_putchar(*str++);
	}
	_putchar('\n');
}
