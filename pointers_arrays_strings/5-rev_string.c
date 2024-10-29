#include <unistd.h>
#include "main.h"

/**
 * rev_string - Entry point
 * Description: reverse a string
 * @s : string to reverse
 * Return: reverse string
 */

void rev_string(char *s)
{
	/* declare and initialize variable */
	int start = 0;
	char temp = '\0';
	int end = _strlen(s); /* retrieve chain length */

	/* perform swap */
	/* loop through chain in reverse */
	for (end = end - 1 ; end >= 0 ; end--)
	{
		/* swap with temp buffer */
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;

		/* increment start */
		start++;
	}

}

