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
	char *dup_str = NULL;	/* Declare and initialize variables */
	list_t *temp_buffer = NULL;	/* Initialize a new node*/
	list_t *new_node = malloc(sizeof(*new_node));

	/* Check for special cases: invalid input or memory allocation failure */
	if ((str == NULL) || (new_node == NULL))
	{
		free(new_node);
		return (NULL);
	}

	/* Duplicate str to manipulate it & check if duplication succeed */
	dup_str = strdup(str);
	if (dup_str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	/* Assign data Next = "NULL" cause will be the last node */
	new_node->str = dup_str;
	new_node->len = _strlen(dup_str);
	new_node->next = NULL;

	/* If the list is empty, set new_node as the head */
	if (*head == NULL)
		*head = new_node;

	/* Otherwise, loop through the list and find the last node */
	else
	{
		temp_buffer = *head;
		while (temp_buffer->next != NULL)
			temp_buffer = temp_buffer->next;

		/* Attach the new node at the end of the list */
		temp_buffer->next = new_node;
	}

	return (new_node);
}
