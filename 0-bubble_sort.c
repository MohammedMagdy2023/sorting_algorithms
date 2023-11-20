#include "sort.h"

/**
*bubble_sort - sorting array using bubble sort
*
*@array: the array to sort
*@size: the size of the array
*/

void bubble_sort(int *array, size_t size)
{
int i;
size_t x = 0, y;

if (!size || !array)
return;

while (x < size)
{
for (y = 0; y < size - 1; y++)
{
if (array[y] > array[y + 1])
{
i = array[y];
array[y] = array[y + 1];
array[y + 1] = i;
print_array(array, size);
}
}
x++;
}
}
