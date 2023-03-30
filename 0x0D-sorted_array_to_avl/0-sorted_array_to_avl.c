#include "binary_trees.h"
/**
 * convert - Entry point
 *
 * @array: The array to be printed
 * @start: Size of the array
 * @last: Size of the array
 * @parent: Size of the array
 * Return: 0 on success, error code on failure
 */
avl_t *convert(int *array, int start, int last, avl_t *parent)
{
	avl_t *root;
	int mid;

	if (start > last)
		return (NULL);
	mid = (start + last) / 2;
	root = malloc(sizeof(avl_t));
	if (root == NULL)
		return (NULL);
	root->parent = parent;
	root->n = array[mid];
	root->left = convert(array, start, mid - 1, root);
	root->right = convert(array, mid + 1, last, root);
	return (root);
}
/**
 * sorted_array_to_avl - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Size of the array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL)
		return (NULL);
	return (convert(array, 0, size - 1, NULL));
}
