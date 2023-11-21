#include "sort.h"

/**
*selection_sort - sorting an array using the selection sort algorethim
*
*@array: pointer to ineger array
*@size: the size of the array
*/

void selection_sort(int *array, size_t size)
{
size_t x, y, z;
int temp;

for (x = 0; x < size - 1; x++)
{
z = x;
for (y = x + 1; y < size; y++)
{
if (array[y] < array[z])
z = y;
}
if (z != x)
{
temp = array[x];
array[x] = array[z];
array[z] = temp;
print_array(array, size);
}
}
}
