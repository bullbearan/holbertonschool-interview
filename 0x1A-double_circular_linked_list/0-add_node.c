#include "list.h"
/**
 * add_node_end - function
 * @list: param
 * @str: param
 * Return: result
 */
List *add_node_end(List **list, char *str)
{
	List *node;
	List *ptr;

	if (!list || !str)
		return (NULL);
	node = malloc(sizeof(list));
	if (node == NULL)
		return (NULL);
	node->str = strdup(str);

	if (*list == NULL)
	{
		node->next = node->prev = node;
		*list = node;
		return (node);
	}
	ptr = (*list)->prev;
	node->next = (*list);
	node->prev = ptr;
	(*list)->prev = node;
	ptr->next = node;
	return (node);
}
/**
 * add_node_begin - function
 * @list: param
 * @str: param
 * Return: result
 */
List *add_node_begin(List **list, char *str)
{
	List *node;
	List *ptr;

	if (!list || !str)
		return (NULL);
	node = malloc(sizeof(list));
	if (node == NULL)
		return (NULL);
	node->str = strdup(str);

	if (*list == NULL)
	{
		node->next = node->prev = node;
		*list = node;
		return (node);
	}
	ptr = (*list)->prev;
	node->next = (*list);
	node->prev = ptr;
	(*list)->prev = ptr->next = node;
	*list = node;
	return (node);
}
