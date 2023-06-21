#include "sort.h"
/**
 * merge - Entry point
 * @array: value
 * @l: value
 * @r: value
 * @size: value
 **/
void merge(int *array, int *l, int *r, size_t size)
{
	int i = 0, j = 0, k = 0;
	int size_l = size / 2, size_r = size - size_l;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, size_l);
	printf("[right]: ");
	print_array(r, size_r);

	while (i < size_l && j < size_r)
	{
		if (l[i] < r[j])
			array[k++] = l[i++];
		else
			array[k++] = r[j++];
	}

	while (i < size_l)
		array[k++] = l[i++];

	while (j < size_r)
		array[k++] = r[j++];

	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - Entry point
 * @array: value
 * @size: value
 **/
void merge_sort(int *array, size_t size)
{
	size_t mid = size / 2, i, j;
	int l[100000];
	int r[100000];

	if (!array)
		return;

	if (size < 2)
		return;

	for (i = 0; i < mid; i++)
		l[i] = array[i];

	for (j = mid; j < size; j++)
		r[j - mid] = array[j];

	merge_sort(l, mid);
	merge_sort(r, size - mid);
	merge(array, l, r, size);
}
