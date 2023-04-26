#include "sort.h"
/**
 * swap - Entry point
 * @a: value
 * @b: value
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * heapify - Entry point
 * @array: value
 * @n: value
 * @i: value
 * @size: value
 */
void heapify(int *array, int n, int i, size_t size)
{
	int biggest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && array[l] > array[biggest])
		biggest = l;

	if (r < n && array[r] > array[biggest])
		biggest = r;

	if (biggest != i)
	{
		swap(&array[i], &array[biggest]);
		print_array(array, size);
		heapify(array, n, biggest, size);
	}

}
/**
 * heap_sort - Build max heap
 * @array: value
 * @size: value
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL)
		return;

	for (i = size / 2 ; i > 0; i--)
		heapify(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
