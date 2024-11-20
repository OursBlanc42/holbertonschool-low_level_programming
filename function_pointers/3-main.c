#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

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

	(void)argc;	/* hide argc and argv to avoid compilator error*/
	(void)argv;	/* hide argc and argv to avoid compilator error*/

	if (argc != 4)
	{	/* if the number of arguments is wrong, print Error, */
		printf("Error\n");
		exit(98);
	}

	if (get_op_func(argv[2]) == NULL)
	{	/* Check if the function pointer returned by get_op_func is NULL */
		printf("Error\n");
		exit(99);
	}
	else
	{	/* Convert input arguments to integers using atoi */
		num1 = atoi(argv[1]);
		num2 = atoi(argv[3]);

		/* Call get_op_func to retrieve the appropriate function pointer */
		/* Immediately invoke the returned function with num1 and num2 */
		result = get_op_func(argv[2])(num1, num2);
		printf("%d\n", result);	/* Print the result of the operation */
	}

	return (0);
}
