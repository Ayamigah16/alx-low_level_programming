#include <stdio.h>
#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array
 * using binary search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not
 * present or array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
size_t left = 0, right = size - 1, mid;

if (array == NULL)
{return -1; }

while (left <= right)
{
printf("Searching in array: ");
for (mid = left; mid < right; mid++)
{printf("%d, ", array[mid]); }
printf("%d\n", array[mid]);

mid = (left + right) / 2;

if (array[mid] == value)
{return mid; }

if (array[mid] < value)
left = mid + 1;
else
right = mid - 1;
}

{return -1; }
}
