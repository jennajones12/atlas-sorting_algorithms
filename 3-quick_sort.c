#include "sort.h"

/**
* swap - Swaps two elements in an array
* @a: First element
* @b: Second element
*/
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
* lomuto_partition - Partitions the array using the Lomuto scheme
* @array: The array to be partitioned
* @low: The starting index of the partition
* @high: The ending index of the partition
* @size: The size of the array (for printing)
* Return: The index of the pivot element after partition
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j;

for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
i++;
if (i != j)
{
swap(&array[i], &array[j]);
print_array(array, size);
}
}
}
if (array[i + 1] != array[high])
{
swap(&array[i + 1], &array[high]);
print_array(array, size);
}
return (i + 1);
}

/**
* quick_sort_recursion - Recursive function to implement Quick sort
* @array: The array to be sorted
* @low: The starting index of the partition
* @high: The ending index of the partition
* @size: The size of the array (for printing)
*/
void quick_sort_recursion(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pi = lomuto_partition(array, low, high, size);

quick_sort_recursion(array, low, pi - 1, size);
quick_sort_recursion(array, pi + 1, high, size);
}
}

/**
* quick_sort - Sorts an array of integers in ascending order
*              using the Quick sort algorithm
* @array: The array to be sorted
* @size: The size of the array
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_recursion(array, 0, size - 1, size);
}
