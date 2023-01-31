#include "lists.h"
/**
 * check_cycle - check if there's a cycle
 * @list: head
 * Return: either one or zero
 */
int check_cycle(listint_t *list)
{
	listint_t *cur = list, *tmp = list;

	while (cur && cur->next)
	{
		tmp = tmp->next;
		cur = cur->next->next;
		if (cur == tmp)
			return (1);
	}
	return (0);
}
