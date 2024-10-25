#include <unistd.h>
#include "main.h"

/**
 * print_sign - Entry point
 * Description: Print the sign of a number.
 * @n : number to check
 * Return: 0 if n = zero  / 1 if if n>0 / -1 if n<0
 */

/* prototype */
int display(int n);

int print_sign(int n)
{
	/* check n sign */
	if (n > 0)
	{
		/* if > 0 : show + sign */
		_putchar('+');

		/* then display */
		display(n);

		return (1);
	}

	else if (n < 0)
	{
		/* if < 0 : show - sign */
		_putchar('-');

		/* then display */
		display(n);

		return (-1);
	}

	else
	{
		/* print 0 if 0 */
		_putchar('0');
		return (0);
	}

}


/**
 * display - display the number
 * Description: Print the number after sign check.
 * Return: nothing
* @n : number to print
 */

int display(int n)
{
	/* declare local variable*/
	int i = 9;
	int j;
	int nbis;
	int m;


	/* copy n value to manipulate */
	nbis = n;

	/* define array to stock digit */
	/* we assume this array is huge enough */
	char str[10];

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
	for (int j = i + 1; j < 10; j++)
	{
		_putchar(str[j]);
	}
}
