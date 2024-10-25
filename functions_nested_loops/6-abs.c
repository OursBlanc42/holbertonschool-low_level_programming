#include <unistd.h>
#include "main.h"

/**
 * _abs - Entry point
 * Description: Display absolute value of a number
 * @n : number to check
 * Return: absolute value
 */

 /* prototype */
int display(int n);

int _abs(int n)
{
	/* check n sign */
	if (n < 0)
	{
		/* if negative convert to aboslute */
		n = n * -1;
	}

	/* once is converted :display */
	display(n);

	return (0);

}


/**
 * display - display number to screen
 * Description: Display absolute value of a number on screen
 * @n : number to check
 * Return: absolute value
 */

int display(int n)
{
	/* declare local variable*/
	/* define array to stock digit */
	/* we assume this array is huge enough */
	int i = 9;
	int j;
	int nbis;
	int m;
	char str[10];

	/* copy n value to manipulate */
	nbis = n;

	/* loop through each digit */
	while (nbis > 0 && i >= 0)
	{
		/* extract last digit */
		m = nbis % 10;
		/* convert digit to string */
		m = m + '0';
		/* write m in buffer */
		str[i] = m;
		/* decremential */
		nbis = nbis / 10;
		i--;
	}

	/* Show digit in right order */
	for (j = i + 1; j < 10; j++)
	{
		_putchar(str[j]);
	}
	return (0);
}
