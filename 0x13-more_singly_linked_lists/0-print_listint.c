#include "lists.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
*print_listint - Prints all elements of a linked list
*@h: linked list of the type listint_t to print
*
*Return: the number of nodes.
*/

size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h != NULL)
	{
		printf(" % d\n", h->n);
		h = h->next;
		num++;
	}
	return (num);
}
