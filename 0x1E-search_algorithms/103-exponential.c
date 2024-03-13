#include <stdio.h>
#include "search_algos.h"

/**
 * bin_search - Searches for a value in a sorted
 * array using Binary search
 * @array: Pointer to the first element of the array
 * @low: Lower bound index of the subarray
 * @high: Upper bound index of the subarray
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not present
 */
int bin_search(int *array, size_t low, size_t high, int value)
{
size_t mid;
size_t i;

while (low <= high)
{
printf("Searching in array: ");
for (i = low; i < high; i++)
{printf("%d, ", array[i]); }
printf("%d\n", array[high]);

mid = (low + high) / 2;

if (array[mid] == value)
{return mid; }
else if (array[mid] < value)
{low = mid + 1; }
else
{high = mid - 1; }
}

{return -1; }
}


/**
 * exponential_search - Searches for a value in
 * assorted array using Exponential search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1
 * if not present or array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
size_t bound = 1;
size_t low, high;

if (array == NULL)
{return -1; }

while (bound < size && array[bound] < value)
{
printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
bound *= 2;
}

low = bound / 2;
high = (bound < size) ? bound : size - 1;

printf("Value found between indexes [%lu] and [%lu]\n", low, high);

{return bin_search(array, low, high, value); }
}
