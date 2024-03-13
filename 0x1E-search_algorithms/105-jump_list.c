#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list
 * of integers using Jump search
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in the list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is
 * located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
listint_t *prev = NULL, *next = NULL;
size_t step = sqrt(size), prev_idx = 0, next_idx = step;

if (list == NULL)
{return NULL; }

while (next_idx < size && next_idx < list->index)
{
next = list;
while (next->index < next_idx)
{
prev = next;
next = next->next;
}

printf("Value checked at index [%lu] = [%d]\n", next->index, next->n);
if (next->n >= value || next->index == size - 1)
{break; }

prev_idx = next_idx;
next_idx += step;
}

printf("Value found between indexes [%lu] and [%lu]\n",
prev_idx, next_idx);
while (prev->index < next_idx && prev->index < size)
{
printf("Value checked at index [%lu] = [%d]\n",
prev->index, prev->n);
if (prev->n == value)
{return prev; }
prev = prev->next;
}

{return NULL; }
}