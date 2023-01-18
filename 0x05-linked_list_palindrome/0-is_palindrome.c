#include "lists.h"
/**
 * is_palindrome - check the code for
 * @head: head
 * Return: Always 0.
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head;
	listint_t *fast = *head;
	listint_t *tmp = *head;
	listint_t *prev = NULL;
	listint_t *ptr = *head;

	if (*head == NULL)
		return (1);

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	while (slow != NULL)
	{
		tmp = slow->next;
		slow->next = prev;
		prev = slow;
		slow = tmp;
	}
	while (prev != NULL)
	{
		if (ptr->n != prev->n)
			return (0);
		ptr = ptr->next;
		prev = prev->next;
	}
	return (1);
}
