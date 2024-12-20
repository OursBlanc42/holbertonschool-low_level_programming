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
 *
 * Description (Algorithm):
 * 1. Allocate memory for a new node.
 * 2. Duplicates the constant string `str` using strdup to manipulate it
 *	strdup allocate memory. So if fail the memory should be free and returns
 *	NULL to indicate an error.
 *  Next is initialized to NULL because it will be the last node.
 * 3. Traverse the list to find the last node.
 * 4. Append the new node at the end of the list.
 *
 *@head: double pointer to a list_t list
 *@str: str to be added
 *Return: the adress of new elements or NULL if it failed
 */

list_t *add_node_end(list_t **head, const char *str)
{
	/* Initialize buffer node and new node*/
	list_t *temp_buffer = NULL;
	list_t *new_node = malloc(sizeof(*new_node));

	/* Check for special cases: invalid input or memory allocation failure */
	if ((str == NULL) || (new_node == NULL))
	{
		free(new_node);
		return (NULL);
	}

	/* Initialize new_node with duplicated string and apply new data */
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->len = _strlen(new_node->str);
	new_node->next = NULL;

	/* If the list is empty, set new_node as the head */
	if (*head == NULL)
		*head = new_node;

	/* Otherwise, loop through the list and find the last node */
	else
	{
		temp_buffer = *head;
		while (temp_buffer->next != NULL)
		{
			temp_buffer = temp_buffer->next;
		}

		/* Attach the new node at the end of the list */
		temp_buffer->next = new_node;
	}

	return (new_node);
}
