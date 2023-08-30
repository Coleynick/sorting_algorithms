#include "sort.h"
/**
* selection_sort - Sorts an arry of %d using d func
* @array: Pointer to the arry to be sorted
* @size: Num of elemnts in the arry
*/

void selection_sort(int *array, size_t size)
{
	size_t a, j, min_idx;
	int tmp;

	for (a = 0; a < size - 1; a++)
	{
		min_idx = a;
		for (j = a + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != a)
		{
			tmp = array[a];
			array[a] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
	}
}
