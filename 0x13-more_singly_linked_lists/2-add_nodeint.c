#include "lists.h"
#include <stdlib.h>

/**
*add_nodeint - it adds a new node at the start of a linked list
*@head: pointer to the first node in thlist
*@n: data to insert the new node
*
*Return: the address of the new element, or NULL if it failed
*/

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *recent;

	recent = malloc(sizeof(listint_t));
	if (!recent)
		return (NULL);

	recent->n = n;
	recent->next = *head;
	*head = recent;

	return (recent);
}
