#include "binary_trees.h"

/**
 * binary_tree_node - Binary tree node
 *
 * @parent: Integer stored in the node
 * @value: number to be inserted in the node
 * Return: A pointer
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
