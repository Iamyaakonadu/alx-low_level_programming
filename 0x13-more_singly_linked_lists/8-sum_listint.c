#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
*sum_listint - it calcultes the sum of all data in a listint_t list
*@head: 1st node in the linked list
*
*Return: the rseulting sum
*/

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp = head;

	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}
	return (sum);
}
