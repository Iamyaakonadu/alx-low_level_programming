#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
*listint_len - Returns the number of elements in a linked lists.
*@h: linked list of type listint_t to traverse
*
*Return: the number of nodes.
*/

size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}
	return (num);
}
