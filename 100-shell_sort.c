#include "sort.h"
/**
 * shell_sort -Sort an array using shell_sort algorithm
 * @array: array
 * @size: size of the array
 * Return: NULL
 **/
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, n, m;
	int temp;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (n = gap; n < size; n++)
		{
			temp = array[n];
			m = n;
			while (m >= gap && array[m - gap] > temp)
			{
				array[m] = array[m - gap];
				m -= gap;
			}
			array[m] = temp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
