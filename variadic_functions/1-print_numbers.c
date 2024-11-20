#include <stdarg.h>
#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_numbers - prints numbers, followed by a new line.
 * @separator: string to be printed between numbers
 * @n: number of int passed to the functions
 * Return: prints numbers with separator or NULL if separator is null
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	/* Variable declaration and initialisation */
	unsigned int i;

	va_list args; /* Arguments list declaration */

	va_start(args, n); /* Initialize list with fixed arguments */

	/* check special case */
	if (separator == NULL)
	{	/* if separator = NULL replace by nothing to dont print it */
		separator = "";
	}

	if (n <= 0)
	{	/* if n <= 0 just print the separator (or nothing as checked before) */
		printf("%s", separator);
		return;
	}

	/* loop each arguments start with "n" */
	/* (n-1) to stop before the last and not print the last separator */
	for (i = 0; i < (n - 1); i++)
	{	/* catch each args as a int */
		printf("%d%s", va_arg(args, int), separator);
	}

	/* increment the last time to cath the last int */
	i++;

	/* print without separator */
	printf("%d", va_arg(args, int));

	/* add new line */
	printf("\n");

	va_end(args); /* Ends the use of the list */

}
