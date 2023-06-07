#include "lists.h"
#include <stdio.h>

/**
*listint_len - Returns the number of elements in a linked lists.
*@h: linked list of type listint_t to traverse
*
*Return: the number of nodes.
*/

size_t listint_len(const listint_t *h)
{
	size_t letter = 0;

	while (h)
	{
		letter++;
		h = h->next;
	}
	return (letter);
}
