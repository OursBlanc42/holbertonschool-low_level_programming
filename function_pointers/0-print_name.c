#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - prints a name
 * @name: name of the person
 * @f: callback
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
