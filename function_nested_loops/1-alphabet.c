#include <stdio.h>

/**
 * main - Entry point
 * Description: Display the alphabet on screen
 * Return: Alphabet
 */

int main(void)
{
	char *str = "abcdefghijklmnopqrstuvwxyz";

	while (*str)
	{
		putchar(*str++);
	}
	putchar('\n');
	return (0);
}
