#include "lists.h"

/**
* find_listint_loop - a function that finds the loop in a linked list.
* @head: pointer to the head of list
* Return: The address of the node where the loop starts...
* ...or NULL if there is no loop
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise = head, *hare = head;

	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}
			return (tortoise);
		}
	}
	return (NULL);
}
