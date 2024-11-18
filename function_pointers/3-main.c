#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

/**
 * main - Entry point
 * Description: calculate operation
 * @argc: number of arguments
 * @argv: array who contains each arguments
 * Return: 0 if success or 98 if argc != 4
 */

int main(int argc, char *argv[])
{
	/* variable declaration */
	int num1;
	int num2;
	int result;

	/* hide argc and argv to avoid compilator error*/
	(void)argc;
	(void)argv;


	/* if the number of arguments is wrong, print Error, */
	/* followed by a new line, and exit with the status 98  */

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	else
	{   /* convert string to number with atoi */
		num1 = atoi(argv[1]);
		num2 = atoi(argv[3]);
		/* call get_op_func */
		result = get_op_func(argv[2])(num1, num2);
		printf("%d\n", result);
	}

	return (0);
}
