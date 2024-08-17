#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer to swap
 * @b: Second integer to swap
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble sort algorithm.
 * @array: The array of integers to sort
 * @size: The number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int swapped;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                print_array(array, size);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}
