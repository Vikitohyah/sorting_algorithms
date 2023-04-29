#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _merge_sort - initiate merge sort
 * @array: array to be sorted
 * @temp: temporary array for holding sorted elements
 * @size: size of the array
 */
void _merge_sort(int *array, int *temp, size_t size)
{
	size_t half = size / 2, l = 0, m = 0, n;

	if (size < 2)
		return;

	_merge_sort(array, temp, half);
	_merge_sort(array + half, temp + half, size - half);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, half);
	printf("[right]: ");
	print_array(array + half, size - half);
	for (n = 0; n < size; n++)
		if (m >= size - half || (l < half && array[l] < (array + half)[m]))
		{
			temp[n] = array[l];
			l++;
		}
		else
		{
			temp[n] = (array + half)[m];
			m++;
		}
	for (n = 0; n < size; n++)
		array[n] = temp[n];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - initiate merge sort
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(*temp) * size);
	if (!temp)
		return;

	_merge_sort(array, temp, size);
	free(temp);
}
