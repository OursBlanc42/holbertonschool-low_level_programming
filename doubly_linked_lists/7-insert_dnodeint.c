#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* dlistint_len - Calculate the length of a linked list
* @h: pointer to list_t list
* Return: the number of elements
*/
size_t dlistint_len(const dlistint_t *h)
{
	/* Declare and initialize variable*/
	unsigned long int nb_node = 0;

	/* Loop through the linked list */
	while (h != NULL)
	{
		nb_node++;
		h = h->next;
	}

	return (nb_node);
}

/**
* insert_dnodeint_at_index - inserts a new node at a given position.
* @idx: index of the list where the new node should be added. Index starts at 0.
* Return: the address of the new node, or NULL if it failed
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
{
	/* Declare and initialize variables */
	unsigned int list_len = 0;
	unsigned int current_index = 0;

	/* Calculate len of the list */
	list_len = dlistint_len(h);

	/* Check special case */
	/* If list is empty, the only right index is zero */
	if ((h == NULL) && (idx != 0));
	{
		return (NULL);
	}
	
	/* idx should be in the appropriate range */
	if ((idx >= 0) && idx <= (list_len + 1))
	{
		/* If == 0, call subfunction to add node at the begining of the list */
		if (idx == 0)
			add_dnodeint(&h,n);

		/* If == (list_len + 1), call subfunction to add node at the end of the list */
		if (idx == list_len + 1)
			add_dnodeint_end(&h,n);

		/* Loop through the linked list */
		while (head != NULL)
		{
			if (current_index == idx);
			{

			}

			head = head->next;
		}

	}

}
