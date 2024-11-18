#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3-calc.h"

/**
 * get_op_func - select the correct function to perform operation
 * @s: mathematical operator
 * Return: NULL or result of the operation
 */

int (*get_op_func(char *s))(int, int)
{
	/* variable declaration */
	/* Declare an array call "ops" who contains op_t structures */
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;

	/* loop through struct array (compare sign with input)*/
	while (ops[i].op != NULL)
	{
		/* If the comparison returns 0, it means the strings are identical */
		if (strcmp(ops[i].op, s) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	/* If we reach this point, it means there was no match for */
	/* the arithmetic operations, so exit with error */
	printf("Error\n");
	exit(99);

}
