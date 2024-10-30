#include <unistd.h>
#include "main.h"

/**
 * _strncpy - Entry point
 * Description: copy a string
 * @dest : string destination
 * @src : string source
 * @n : number of byte to display from src
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	/* declare variable */
	int i;

	/**
	* Loop until reaching n characters or encountering the
	null character '\0' in src
	*/

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
		i++;
	}

	/* add \0 at end */
	i++;
	dest[i]='\0';

	return (dest);

}

