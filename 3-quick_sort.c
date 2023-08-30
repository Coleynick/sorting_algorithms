#include "sort.h"

/**
* swap - Swaps 2 %d
* @v: First %d
* @x: Second %d
*/
void swap(int *v, int *x)
{
	int tmp = *v;
	*v = *x;
	*x = tmp;
}

/**
* lomuto_partition - Implements the func schme.
* @array: Array to be partitioned.
* @low: Starting indx of d partition.
* @high: Ending indx of the partition.
* @size: Array size.
* Return: Indx of the pivot's finl postion.
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivt = array[high];
	int a = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivt)
		{
			a++;
			if (a != j)
			{
				swap(&array[a], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (a + 1 != high)
	{
		swap(&array[a + 1], &array[high]);
		print_array(array, size);
	}
	return (a + 1);
}

/**
* quick_sort_helpa - Help the quick_sort algorithm.
* @array: Array to be sortd.
* @low: Starting indx of the partition.
* @high: Ending indx of the partition.
* @size: Size of the arry.
*/
void quick_sort_helpa(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quick_sort_helpa(array, low, pi - 1, size);
		quick_sort_helpa(array, pi + 1, high, size);
	}
}

/**
* quick_sort - Sorts an array of integers using the func
* @array: Array to be sorted
* @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	quick_sort_helpa(array, 0, size - 1, size);
}
