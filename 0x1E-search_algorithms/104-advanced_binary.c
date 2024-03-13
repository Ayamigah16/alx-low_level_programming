#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a
 * sorted array using Advanced Binary search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if
 * not present or array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
size_t low = 0, high = size - 1;
int index = -1;
size_t i;
size_t mid;

if (array == NULL)
{return -1; }

while (low <= high)
{
mid = (low + high) / 2;

printf("Searching in array: ");
for (i = low; i < high; i++)
{printf("%d, ", array[i]); }
printf("%d\n", array[high]);

if (array[mid] == value)
{
index = mid;
high = mid - 1;
}
else if (array[mid] < value)
low = mid + 1;
else
high = mid - 1;
}

{return index; }
}
