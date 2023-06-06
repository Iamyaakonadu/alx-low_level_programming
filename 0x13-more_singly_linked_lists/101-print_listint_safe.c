#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);
/**
*looped_listint_len - it counts the number of unique nodes
*in a looped listint_t linked list.
*@head: a pointer to the head of the listint_t to check
*
*Return:if the list is not looped - 0
*otherwise the number of unique nodes in the list.
*/

size_t looped_listint_len(const listint_t *head)
{
	const listint_t *ant, *cat;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	ant = head->next;
	cat = (head->next)->next;

	while (cat)
	{
		if (ant == cat)
		{
			ant = head;
			while (ant != cat)
			{
				nodes++;
				ant = cat->next;
				cat = cat->next;
			}

			ant = ant->next;
			while (ant != cat)
			{
				nodes++;
				ant = ant->next;
			}

			return (nodes);
		}
		ant = ant->next;
		cat = (cat->next)->next;
	}
	return (0);
}

/**
*print_listint_safe - it prints a listint_t list safely
*@head: a pointer to the head of the listint_t list
*
*Return: the number of nodes in the list
*/
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	nodes = looped_listint_len(head);

	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (nodes);
}
