#include "sort.h"

/**
* bubble_sort - Sorts an array of %d in ascension
* @array: The array to be bubble_sorted
* @size: D size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t a, j;
	int tmp;
	int swp;

	if (array == NULL || size < 2)
		return;
	for (a = 0; a < size - 1; a++)
	{
		swp = 0;

		for (j = 0; j < size - a - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swp = 1;
				print_array(array, size);
			}
		}
		if (swp == 0)
			break;
	}
}
