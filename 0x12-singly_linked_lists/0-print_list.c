#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
*print_list- prints all elements of a linked list
*@h: the pointer to the list_t to print
*
*Return: number of nodes printed
*/

size_t print_list(const list_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		if (h->str == NULL)
			printf("[%d} %s\n", h->len, h->str);

		nodes++;
		h = h->next;
	}

	return (nodes);
}
