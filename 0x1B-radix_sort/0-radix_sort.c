#include "sort.h"
/**
* max - max
* @array: para
* @size: para
* Return: 0
*/
int max(int *array, int size)
{
	int i, max;

	for (max = array[0], i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}
/**
* sort - sort
* @array: para
* @size: para
* @num: para
* Return - 0
*/
void sort(int *array, int size, int num)
{
	int *tmp, i, count[10] = {0};

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / num) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		tmp[count[(array[i] / num) % 10] - 1] = array[i];
		count[(array[i] / num) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	free(tmp);
}
/**
* radix_sort - sort
* @array: para
* @size: para
* Return - void
*/
void radix_sort(int *array, size_t size)
{
	int num, m;

	if (size < 2)
		return;
	m = max(array, size);
	for (num = 1; m / num > 0; num *= 10)
	{
		sort(array, size, num);
		print_array(array, size);
	}
}
