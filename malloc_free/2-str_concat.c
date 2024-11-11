#include <stdlib.h>
#include "main.h"

/**
 * _strlen - calculate the length of a string
 * Description : calculate the length of a string (without '\0')
 * @str: source str
 * Return: unsigned int "count" = length of a string
 */

unsigned int _strlen(char *str)
{
	/* declare an initialize */
	unsigned int count = 0;

	if (str == NULL)
	{
		count = 0;
		return (count);
	}
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

/**
 * str_concat - Entry point : concatenates two strings.
 * Description : concatenates two strings.
 * @s1: source str 1
 * @s2 : source str 2
 * Return: NULL (if malloc failed) or pointer to concatenated string
 */

char *str_concat(char *s1, char *s2)
{
	/* declaration and initialization */
	unsigned int i;
	unsigned int len_s1;
	unsigned int len_s2;
	unsigned int len_total;
	char *arr;

	/* find string length */
	len_s1 = _strlen(s1);
	len_s2 = _strlen(s2);

	/* len_total calculation + 1 to count the FINAL '\0' */
	len_total = len_s1 + len_s2 + 1;

	/* memory allocation */
	arr = malloc(len_total);

	/* check if memory allocation succeed */
	if (arr == NULL)
	{
		return (NULL);
	}
	else
	{	/* concatenate strings */
		/* first string */
		for (i = 0; i < len_s1; i++)
		{
			arr[i] = s1[i];
		}
		/* second string (<= to count the FINAL \0 )*/
		for (i = 0; i <= len_s2; i++)
		{
			arr[len_s1 + i] = s2[i];
		}
	}

	return (arr);
}

