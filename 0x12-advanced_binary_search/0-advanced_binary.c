#include "search_algos.h"

/**
 * @advb - Entry point
 * @array: value
 * @left: value
 * @right: value
 * @value: value
 *
 * Return: Always EXIT_SUCCESS
 */
int advb(int *array, int left, int right, int value)
{
	int mid, i;

	if (left > right)
		return (-1);

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	if (left == right && array[right] == value)
		return (right);

	if (left == right && array[right] != value)
		return (-1);

	mid = left + (right - left) / 2;

	if ((mid == left || value != array[mid - 1]) && array[mid] == value)
		return (mid);

	if (array[mid] >= value)
		return (advb(array, left, mid, value));

	return (advb(array, mid + 1, right, value));
}
/**
 * advanced_binary - Entry point
 * @array: value
 * @size: value
 * @value: value
 *
 * Return: Always EXIT_SUCCESS
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);
	return (advb(array, 0, size - 1, value));
}
