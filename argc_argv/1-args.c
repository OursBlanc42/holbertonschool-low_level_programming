#include <stdio.h>

/**
 * main - Entry point
 * Description: print the number of arguments passed into it
 * @argc: number of arguments
 * @argv: array who contains each arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	/* hide argc and argv to avoid compilator error*/
	(void)argc;
	(void)argv;
	printf("%d\n", argc);
	return (0);
}
