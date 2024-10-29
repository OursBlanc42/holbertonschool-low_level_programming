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
	int end = 0;

	/* loop through chain until null charactere ('\0') */
	while (s[end] != '\0')
	{
		/* increment end for each character founded */
		end++;
	}

	/* perform swap */
	/* loop through chain in reverse */
	for (end = end - 1 ; end >= 0 ; end--)
	{
		/* through through middle of the chain*/
		if (end != end / 2)
		{
		/* swap with temp buffer */
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;

		/* increment start */
		start++;
		}
	}

}

