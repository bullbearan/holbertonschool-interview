#include "binary_trees.h"
/**
 *  binary_tree_size - Binary tree node
 *
 * @tree: Integer stored in the node
 * Return: value
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	unsigned int count = 0;

	if (tree == NULL)
		return (0);

	count += 1;
	count += binary_tree_size(tree->left);
	count += binary_tree_size(tree->right);
	return (count);
}
/**
 *  binary_tree_perfect - Binary tree node
 *
 * @tree: Integer stored in the node
 * Return: value
 */
size_t binary_tree_perfect(const binary_tree_t *tree)
{
	unsigned int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_size(tree->left);
	right_height = binary_tree_size(tree->right);

	if (left_height == right_height)
		return (1);

	return (0);
}
/**
 *  heap_check - Binary tree node
 *
 * @ibn: Integer stored in the node
 * @parn: Integer stored in the node
 * Return: value
 */
void heap_check(heap_t **ibn, heap_t **parn)
{
	heap_t *left_node, *right_node, *child = *ibn, *parent = *parn;

	right_node = (*ibn)->right, left_node = (*ibn)->left;
	if (child->n > parent->n)
	{
		if (child->left)
			child->left->parent = parent;
		if (child->right)
			child->right->parent = parent;
		if (parent->left == child)
		{
			if (parent->right)
				parent->right->parent = child;
			child->right = parent->right;
			child->left = parent;
		}
		else
		{
			parent->left->parent = child;
			child->left = parent->left;
			child->right = parent;
		}
		if (parent->parent)
		{
			if (parent->parent->left == parent)
				parent->parent->left = child;
			else
				parent->parent->right = child;
		}
		else
		{
			*parn = child;
		}
		child->parent = parent->parent;
		parent->parent = child;
		parent->left = left_node;
		parent->right = right_node;
	}
}
/**
 *  heap_insert - Binary tree node
 *
 * @root: Integer stored in the node
 * @value: Integer stored in the node
 * Return: value
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if ((*root) == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	if (binary_tree_perfect(*root) || (!binary_tree_perfect((*root)->left)))
	{
		if ((*root)->left != NULL)
		{
			new_node = heap_insert(&((*root))->left, value);
			heap_check(&((*root)->left), root);
			return (new_node);
		}
		else
		{
			new_node = binary_tree_node(*root, value);
			(*root)->left = new_node;
			heap_check(&((*root)->left), root);
			return (new_node);
		}
	}
	else
	{
		if ((*root)->right != NULL)
		{
			new_node = heap_insert(&((*root)->right), value);
			heap_check(&((*root)->right), root);
			return (new_node);
		}
		else
		{
			new_node = binary_tree_node(*root, value);
			(*root)->right = new_node;
			heap_check(&((*root)->right), root);
			return (new_node);
		}
	}
	return (NULL);
}
