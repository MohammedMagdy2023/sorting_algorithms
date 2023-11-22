#include "sort.h"

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
	int x, y, pivot = array[high];

	for (x = y = low; y < high; y++)
		if (array[y] < pivot)
			swaper(array, size, &array[y], &array[x++]);
	swaper(array, size, &array[x], &array[high]);

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
 * swaper - swap two arrays
 *
 * @array: the int array to sort
 * @size: the size of the array
 * @x: the first int to swap
 * @y: the second int to swap
*/

void swaper(int *array, size_t size, int *x, int *y)
{
	if (*x != *y)
	{
		int *temp;
		*temp = *y;
		*y = *x;
		*x = *temp;
		print_array((const int *)array, size);
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
	if (array == NULL || size == NULL)
		return;
	quicksorter(array, size, 0, size - 1);
}

