#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
*add_nodeint_end - it adds a node at the endof a linked list
*@head: pointer to the 1st element in the list
*@n:data to insert in the new element
*
*Return: pointer to the new node, or NULL if it fails
*/

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *house;
	listint_t *temp = *head;

	house = malloc(sizeof(listint_t));
	if (!house)
		return (NULL);

	house->n = n;
	house->next = NULL;
	if (*head == NULL)
	{
		*head = house;
		return (house);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = house;

	return (house);
}
