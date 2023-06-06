#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
*find_listint_loop - it finds the loop in a liinked list
*@head: the linked list to look for
*
*Return: The address of the node where the loop starts, or NULL if no loop
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	if (!head)
		return (NULL);

	while (slow && fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{

			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (fast);
		}
	}
	return (NULL);
}
