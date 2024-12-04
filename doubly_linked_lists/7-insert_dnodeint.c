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
* @h: double pointer to the head of the double linked chain
* @idx: index of the list where the new node should be added. Index start 0
* @n: data to be added (int)
* Return: the address of the new node, or NULL if it failed
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	/* Declare and initialize variables */
	unsigned int list_len = 0;
	unsigned int current_index = 0;
	dlistint_t *new_node = NULL;
	dlistint_t *temp_buffer = NULL;

	/* Calculate len of the list */
	list_len = dlistint_len(*h);

	/* Check special case */
	/* If list is empty, the only right index is zero */
	if ((h == NULL) && (idx != 0))
	{
		return (NULL);
	}

	/* idx should be in the appropriate range */
	if (idx <= (list_len))
	{
		/* If == 0 : add node at the begining of the list */
		if (idx == 0)
			add_dnodeint(h, n);

		/* If idx == (list_len) : add node at the end of the list */
		if (idx == list_len)
			add_dnodeint_end(h, n);

	/* Otherwise traverse list to find the node before the insertion point */
		temp_buffer = *h;
		while (temp_buffer != NULL)
		{
			if (current_index == (idx - 1))
			{
				/* Initialize a new node*/
				new_node = malloc(sizeof(*new_node));

				/* Check memory allocation failure */
				if (new_node == NULL)
				{
					return (NULL);
				}

				/* Set the pref of new node to current_node */
				new_node->prev = (temp_buffer);
				/* Set the next of new node */
				new_node->next = (temp_buffer)->next;
				/* update the link with next node to new_node */
				(temp_buffer)->next = new_node;

				return (*h);
			}

			temp_buffer = temp_buffer->next;
		}

	}

	return (NULL);

}
