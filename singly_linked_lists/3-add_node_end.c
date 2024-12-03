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
    /*
     * Prepare the new node:
     * - Duplicate the input string to avoid modifying the original
     * - Allocate memory for the new node
     * - Check if memory allocation succeeded
     */
	char *dup_str = strdup(str);
	list_t *temp_buffer = NULL;
	list_t *new_node = malloc(sizeof(*new_node));

	if (new_node == NULL)
		return (NULL);

	/* Assign data to the new node */
	/* next can be "NULL" cause will be the last node */
	new_node->str = dup_str;
	new_node->len = strlen(dup_str);
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
