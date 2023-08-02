#include "binary_trees.h"

/**
 * tree_is_balanced - tsena
 * @node: tsn
 * @min: tnse
 * @max: tnuf
 * @height: tnsea
 * Return: tnsea
 */
int tree_is_balanced(const binary_tree_t *node, int min, int max, int *height)
{
	int hl, hr;

	hr = 0;
	hl = 0;

	if (!node)
		return (1);
	if (node->n <= min || node->n >= max)
		return (0);
	if (!tree_is_balanced(node->left, min, node->n, &hl) ||
		!tree_is_balanced(node->right, node->n, max, &hr))
		return (0);
	if (hl > hr)
		*height = hl + 1;
	else
		*height = hr + 1;
	return (abs(hl - hr) < 2);
}

/**
 * binary_tree_is_avl - tnf
 * @tree: tsne
 * Return: tfnuw
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (!tree)
		return (0);
	return (tree_is_balanced(tree, INT_MIN, INT_MAX, &height));
}
