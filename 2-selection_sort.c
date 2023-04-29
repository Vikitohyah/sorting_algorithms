#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: element to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int n, m;

	if (size < 2)
		return;

	for (n = 0; n < size; n++)
	{
		unsigned int x = n;
		int aux = array[n];

		for (m = n + 1; m < size; m++)
		{
			if (array[m] < aux)
				aux = array[m], x = m;
		}
		if (x != n)
		{
			array[x] = array[n];
			array[n] = aux;
			print_array(array, size);
		}
	}
}
