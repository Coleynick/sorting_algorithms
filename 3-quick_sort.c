#include "sort.h"

/**
* quick_sort - Sorts an array of %d in ascension
* @array: D array to be sorted
* @size: The size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_helpa(array, 0, size - 1, size);
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
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quick_sort_helpa(array, low, pivot - 1, size);
		quick_sort_helpa(array, pivot + 1, high, size);
	}
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
	int pivot, a, j;

	pivot = array[high];
	a = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			a++;
			swap(&array[a], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[a + 1], &array[high]);
	print_array(array, size);
	return (a + 1);
}

/**
* swap - Swaps 2 %d
* @v: First %d
* @x: Second %d
*/
void swap(int *v, int *x)
{
	int temp = *v;
	*v = *x;
	*x = temp;
}
