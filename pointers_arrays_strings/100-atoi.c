#include <unistd.h>
#include "main.h"

/**
 * _atoi - Entry point
 * Description: convert string to an integer
 * @s : entry string
 * Return: integer
 */

int _atoi(char *s)
{
	/* declare and define variable */
	unsigned int value = 0;
	int count = 0;
	int minus = 0;
	int first_digit = 0;
	int last_digit = 0;
	int i = 0;
	int j = 0;
	int power = 1;
	int result =0;

	/* loop through source chain until null charactere ('\0') */
	while (s[count] != '\0')
	{
		/* count the occurence of minus to detect if its negative*/
		if(s[count] == '-')
		{
			minus++;
		}
		/* check there is a digit*/
		if (s[count] >= '0' && s[count] <= '9')
		{
			/* setup variable */
			first_digit = count;
			last_digit = count;
			break;
		}
		/* increment count for each loop */
		count++;
	}

	/* as soon as the first digit is found, loop to the last digit found */
	while (s[count] >= '0' && s[count] <= '9')
	{
		last_digit++;
		count++;
	}

	/* from last to first digit 
	recalculate each power of 10 at each rank to recompose the number*/
	for (i = last_digit - 1 ; i >= first_digit ; i--)
	{
		j = (s[i] - '0') * power;
		value = value + j;

		/* avoid problem with INT MAX or INT MIN */
		if (power != 1000000000)
		{
		power *= 10;
		}
	}

	/* determinate if its negative */
	if (minus % 2 == 1)
	{
		result = value * -1;
	}
	else
	{
		result = value;
	}



	return (result);

}

