#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
*get_nodeint_at_index - it returns the node at a certain index in a linked list
*@head: the 1st in the linked list
*@index: the index of the node to return
*
*Return: the pointer to the node looking for or NULL
*/

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp = head;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}
	return (temp ? temp : NULL);
}
