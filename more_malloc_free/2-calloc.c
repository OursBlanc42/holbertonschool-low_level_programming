#include <stdlib.h>
#include "main.h"
#include <string.h>

/**
 * _calloc - Entry point : concatenates two strings.
 * Description : allocates memory for an array, using malloc.
 * @nmemb: how many elements
 * @size: size of one elements
 * Return:	pointer to the allocated memory
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	/* declaration and initialization */
	void *ptr = NULL; /* void used to be "generic" */
	unsigned int len_total;

	/* check special case */
	if ((nmemb == 0) || (size == 0))
	{
		return (NULL);
	}

	/* len_total calculation  */
	len_total = nmemb * size;

	/* memory allocation */
	ptr = malloc(len_total);

	if (ptr == NULL) /* check if memory allocation succeed */
	{
		return (NULL);
	}

	/* initialization */
	memset(ptr, 0, len_total);

	return (ptr);
}