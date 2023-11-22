#include "sort.h"

/**
 * swap - swap two arrays givin numbers
 *
 * @array: the int array to sort
 * @size: the size of the array
 * @x: the first int to swap
 * @y: the second int to swap
*/

void swap(int *array, size_t size, int *x, int *y)
{
	if (*x != *y)
	{
		*x = *x + *y;
		*y = *x - *y;
		*x = *x - *y;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partitioner - partitioning the array
 *
 * @array: the int array to sort
 * @size: the size of the array
 * @low:  the low point of the array
 * @high: the high point of the array
 *
 * Return: size_t
*/

size_t lomuto_partitioner(int *array, size_t size, size_t low, size_t high)
{
	int x, pivot = array[high];
	size_t y;
	
	for (x = y = low; y < high; y++)
		if (array[y] < pivot)
			swap(array, size, &array[y], &array[x++]);
	swap(array, size, &array[x], &array[high]);

	return (x);
}

/**
 * quicksorter - quick sort by using the lomuto partitioning scheme
 *
 * @array: the int array to sort
 * @size: the size of the array
 * @low:  the low point of the array
 * @high: the high point of the array
*/

void quicksorter(int *array, size_t size, size_t low, size_t high)
{
	if (low < high)
	{
		size_t pivot = lomuto_partitioner(array, size, low, high);

		quicksorter(array, size, low, pivot - 1);
		quicksorter(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort - sorting function using quick sort
 *
 * @array: the array for sorting
 * @size: the size of the array
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || !size)
		return;
	quicksorter(array, size, 0, size - 1);
}

