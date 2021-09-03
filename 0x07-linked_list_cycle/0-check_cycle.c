#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
* check_cycle - checks if a singly linked list has a cycle
* @list: linked list
* Return: 0 is no cycle, 1 is a cycle
*/

int check_cycle(listint_t *list)
{
listint_t *slow = list, *fast = list;

	if (!list)
		return (0);

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			return (1);
	}

return (0);

}
