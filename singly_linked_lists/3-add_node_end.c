#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * _strlen - Calculate the length of a string
 * @str: string to check
 * Return: length of a string
 */
int _strlen(char *str)
{
	/* declare and initialize variable */
	int len = 0;

	/* loop through chain until null charactere ('\0') */
	while (str[len] != '\0')
	{
		/* increment n for each character founded */
		len++;
	}

	return (len);

}

/**
 * add_node_end - Add a new node at the end of a list
 *@head: double pointer to a list_t list
 *@str: str to be added
 *Return: the adress of new elements or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	/* Declare and initialize variable */
	char *dup_str = strdup(str);

	/* create new node and check if malloc succeeded */
	list_t *new_node = malloc(sizeof(*new_node));

	if (new_node == NULL)
		return (NULL);

	/* Give data to the node */
	/* next can be "NULL" cause will be the last node */
	new_node->str = dup_str;
	new_node->len = strlen(dup_str);
	new_node->next = NULL;

	/* If the head node is NULL, it's an empty list and we */
	/* make the new node as head */
	if (*head == NULL)
		*head = new_node;
	/* Otherwise, find last node and add the new one */
	else
	{
		while ((*head)->next != NULL)
		{
			(*head) = (*head)->next;
		}

		(*head)->next = new_node;
	}

	return (new_node);
}
