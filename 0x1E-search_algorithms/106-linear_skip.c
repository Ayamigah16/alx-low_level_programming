#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted
 * skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located,
 * or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *prev = NULL, *next = NULL;

if (list == NULL)
{return NULL; }

prev = list;
next = list->express;

while (next)
{
printf("Value checked at index [%lu] = [%d]\n",
next->index, next->n);
if (next->n >= value || next->express == NULL)
{
printf("Value found between indexes [%lu] and [%lu]\n",
prev->index, next->index);
while (prev->index <= next->index)
{
printf("Value checked at index [%lu] = [%d]\n",
prev->index, prev->n);
if (prev->n == value)
{return prev; }
prev = prev->next;
}
{return NULL; }
}
prev = next;
next = next->express;
}

printf("Value found between indexes [%lu] and [%lu]\n",
prev->index, prev->index + 1);
while (prev->index < prev->index + 1)
{
printf("Value checked at index [%lu] = [%d]\n",
prev->index, prev->n);
if (prev->n == value)
{return prev; }
prev = prev->next;
}

return NULL;
}
