#include <stdlib.h>
#include <stdio.h>

/**
 * op_add - return the sum of a & b
 * @a: first number
 * @b: second number
 * Return: sum
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - return the difference of a & b
 * @a: first number
 * @b: second number
 * Return: difference
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - return the product of a & b
 * @a: first number
 * @b: second number
 * Return: product
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - return the div result of a & b
 * @a: first number
 * @b: second number
 * Return: div result
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	else
	{
	return (a / b);
	}
}

/**
 * op_mod - return the div remainder of a & b
 * @a: first number
 * @b: second number
 * Return: div remainder
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	else
	{
	return (a % b);
	}
}
