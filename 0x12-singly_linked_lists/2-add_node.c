#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 *add_node - it adds a new node at the start of a list
 *@head: the original linked list
 *@str: the string to add the node
 *
 *Return: the address of the new list, NULL if its fails
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *temp;
	int length = 0;

	temp = malloc(sizeof(list_t));
	if (temp == NULL)
		return (NULL);

	while (str[length])
		length++;

	temp->len = length;
	temp->str = strdup(str);
	temp->next = *head;
	*head = temp;
	return (temp);
}
