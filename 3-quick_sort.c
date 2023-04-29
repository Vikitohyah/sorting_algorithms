#include "sort.h"
/**
 * swap - sorts an array of integers in ascending order
 * @array: elements to be sorted
 * @n: left element
 * @m: right element
 * @size: size of array
 */
void swap(int *array, int n, int m, int size)
{
	int aux;

	if (array[n] == array[m])
		return;
	aux = array[n];
	array[n] = array[m];
	array[m] = aux;
	print_array(array, size);
}
/**
 * partition - sorts array partition
 * @array: elements to be sorted
 * @start: left side
 * @end: right side
 * @size: size of an array
 * Return: pivot sorted
 */
int partition(int *array, int start, int end, int size)
{
	int pivot = array[end];
	int split_idx = start;
	int m;

	for (m = start; m < end; m++)
		if (array[m] < pivot)
			swap(array, split_idx++, m, size);
	swap(array, split_idx, end, size);
	return (split_idx);
}
/**
 * recursive - quick_sort core
 * @array: elements to be sorted
 * @start: left side
 * @end: right side
 * @size: size of array
 */
void recursive(int *array, int start, int end, int size)
{
	if (start < end)
	{
		int pivot_pos = partition(array, start, end, size);

		recursive(array, start, pivot_pos - 1, size);
		recursive(array, pivot_pos + 1, end, size);
	}
}
/**
 * quick_sort - it sorts an array of integers in ascending order
 * @array: elements to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	recursive(array, 0, size - 1, size);
}
