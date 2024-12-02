#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"


/**
* add_dnodeint - Add a new node at the beginning of a list
* @head: double pointer to a list_t list
* @n: data to be added (int)
* Return: the adress of new elements or NULL if it failed
*/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	/* Initialize a new node*/
	dlistint_t *new_node = malloc(sizeof(*new_node));

	/* Check memory allocation failure */
	if (new_node == NULL)
	{
		return (NULL);
	}

	/* Fill with data from "previous" node, */
	/* and insert element at the begining of the list */
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
