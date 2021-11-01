#include "search.h"

/**
* *linear_skip - function that searches for a value in a sorted...
* ...skip list of integers.
* @list: a pointer to the head of the skip list to search in
* @value: value to search for
* Return: a pointer on the first node where value is located...
* ...If value is not present in list or if head is NULL, return NULL
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list;
	size_t zero = 0;

	if (list == NULL)
		return (NULL);
	current = list;
	while (current)
	{
		if (current->n == value)
			return (current);
		current = current->next;
	}
	return (NULL);
	printf("Value checked at index [%d] = [%d]\n",
			(int)list->index, list->n);
	}
	printf("Value found between indexes [%d] and [%d]\n",
		   (int)zero, (int)list->index);
	list = current;
	while (list->index < zero)
		list = list->next;
	while (list)
	{
		printf("Value checked at index [%d] = [%d]\n",
			   (int)list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}
}
