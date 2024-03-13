#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array using Jump search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not present or array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
size_t step = sqrt(size);
size_t prev = 0;
size_t curr = step;
size_t i;

if (array == NULL)
{return -1; }

printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
while (curr < size && array[curr] < value)
{
printf("Value checked array[%lu] = [%d]\n", curr, array[curr]);
prev = curr;
curr += step;
}

printf("Value found between indexes [%lu] and [%lu]\n", prev, curr);
curr = (curr < size) ? curr : size - 1;

for (i = prev; i <= curr; i++)
{
printf("Value checked array[%lu] = [%d]\n", i, array[i]);
if (array[i] == value)
{return i; }
}

{return -1; }
}
